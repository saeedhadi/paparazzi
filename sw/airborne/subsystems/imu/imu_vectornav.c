/*
 * Copyright (C) 2016 Michal Podhradsky, michal.podhradsky@aggiemail.usu.edu
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

/**
 * @file subsystems/imu/imu_vectornav.c
 *
 * Vectornav VN-200 IMU subsystems, to be used with other AHRS/INS algorithms.
 */

#include "subsystems/imu/imu_vectornav.h"
#include "subsystems/gps.h"

struct ImuVectornav imu_vn;
struct GpsState gps_vn;

/* no scaling */
void imu_scale_gyro(struct Imu *_imu __attribute__((unused))) {}
void imu_scale_accel(struct Imu *_imu __attribute__((unused))) {}
void imu_scale_mag(struct Imu *_imu __attribute__((unused))) {}


/**
 * Convert yaw, pitch, and roll data from VectorNav
 * to correct attitude
 * yaw(0), pitch(1), roll(2) -> phi, theta, psi
 * [deg] -> rad
 */
static inline void ins_vectornav_yaw_pitch_roll_to_attitude(struct FloatEulers *vn_attitude)
{
  static struct FloatEulers att_rad;
  att_rad.phi = RadOfDeg(vn_attitude->psi);
  att_rad.theta = RadOfDeg(vn_attitude->theta);
  att_rad.psi = RadOfDeg(vn_attitude->phi);

  vn_attitude->phi = att_rad.phi;
  vn_attitude->theta = att_rad.theta;
  vn_attitude->psi = att_rad.psi;
}

/**
 * Init IMU struct and set up ABI messages
 */
void imu_vectornav_init(void)
{
  // Initialize variables
  imu_vn.vn_status = VNNotTracking;
  imu_vn.vn_freq = 0;

  // Initialize packet
  imu_vn.vn_packet.status = VNMsgSync;
  imu_vn.vn_packet.msg_idx = 0;
  imu_vn.vn_packet.msg_available = false;
  imu_vn.vn_packet.chksm_error = 0;
  imu_vn.vn_packet.hdr_error = 0;
  imu_vn.vn_packet.overrun_error = 0;
  imu_vn.vn_packet.noise_error = 0;
  imu_vn.vn_packet.framing_error = 0;

  // initialize data structs
  memset(&(imu_vn.vn_data), 0, sizeof(struct VNData));
  memset(&(gps_vn), 0, sizeof(struct GpsState));
}



/**
 * Event function to read and parse data from the serial port
 */
void imu_vectornav_event(void)
{
  // receive data
  vn200_event(&(imu_vn.vn_packet));

  // read message
  if (imu_vn.vn_packet.msg_available) {
    vn200_read_message(&(imu_vn.vn_packet),&(imu_vn.vn_data));
    imu_vn.vn_packet.msg_available = false;
    imu_vectornav_propagate();
  }
}


/**
 * Periodic function checks for the frequency of packets,
 * triggers warning in case the IMU stops sending data
 * and performs initial configuration if needed
 */
void imu_vectornav_periodic(void)
{
  static uint16_t last_cnt = 0;
  static uint16_t sec_cnt = 0;

  sec_cnt = imu_vn.vn_packet.counter -  last_cnt;
  imu_vn.vn_freq = sec_cnt; // update frequency counter

  // we want at least 75% of periodic frequency to be able to control the airfcraft
  if (imu_vn.vn_freq < (PERIODIC_FREQUENCY*0.75)) {
    imu_vn.vn_status = VNNotTracking;
  }

  if (imu_vn.vn_status == VNUninitialized) {
    // performs initialization here (TBD)
  }
}


/**
 * Send ABI messages
 */
void imu_vectornav_propagate(void)
{
  uint64_t tmp = imu_vn.vn_data.nanostamp / 1000;
  uint32_t now_ts = (uint32_t) tmp;

  float now_ts_f = imu_vn.vn_data.timestamp;

  // Rates and accel
  RATES_BFP_OF_REAL(imu.gyro, imu_vn.vn_data.gyro);
  ACCELS_BFP_OF_REAL(imu.accel, imu_vn.vn_data.accel);

  // Send accel and gyro data separate for other AHRS algorithms
  AbiSendMsgIMU_GYRO_INT32(IMU_VECTORNAV_ID, now_ts, &imu.gyro);
  AbiSendMsgIMU_ACCEL_INT32(IMU_VECTORNAV_ID, now_ts, &imu.accel);


  // Gps / position info
  gps_vn.num_sv = imu_vn.vn_data.num_sv;

  struct LlaCoor_f lla_pos_f;
  lla_pos_f.lat = RadOfDeg((float)imu_vn.vn_data.pos_lla[0]); // lat - convert to radians
  lla_pos_f.lon = RadOfDeg((float)imu_vn.vn_data.pos_lla[1]); // lon - convert to radians
  lla_pos_f.alt = (float)imu_vn.vn_data.pos_lla[2]; // alt [m]

  LLA_BFP_OF_REAL(gps_vn.lla_pos, lla_pos_f);
  SetBit(gps_vn.valid_fields, GPS_VALID_POS_LLA_BIT);

  if (imu_vn.vn_status > VNNotTracking) {
    // we have GPS lock
    gps_vn.fix = GPS_FIX_3D;
  }
  else {
    // no lock
    gps_vn.fix = GPS_FIX_NONE;
  }

  // Send the message
  AbiSendMsgGPS(GPS_VECTORNAV_ID, now_ts, &gps_vn);


  // Attitude
  // comes as yaw-pitch-roll
  struct Int32Eulers att_i;
  ins_vectornav_yaw_pitch_roll_to_attitude(&imu_vn.vn_data.attitude);
  EULERS_BFP_OF_REAL(att_i, imu_vn.vn_data.attitude);
  AbiSendMsgIMU_EULERS_INT32(IMU_VECTORNAV_ID, now_ts, &att_i);


  // Lin accel
  AbiSendMsgLIN_ACCEL(IMU_VECTORNAV_ID, now_ts_f, &imu_vn.vn_data.lin_accel);

  // Velocity
  struct Int32Vect3 vel_i;
  SPEEDS_BFP_OF_REAL(vel_i, imu_vn.vn_data.vel_body);
  AbiSendMsgIMU_VELOCITY_INT32(IMU_VECTORNAV_ID, now_ts, &vel_i);
}

