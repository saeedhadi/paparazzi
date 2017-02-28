/*
 * Copyright (C) 2014 Felix Ruess <felix.ruess@gmail.com>
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
 */

/**
 * @file subsystems/ahrs/ahrs_float_mlkf_wrapper.c
 *
 * Paparazzi specific wrapper to run MLKF filter.
 */

#include "modules/ahrs/ahrs_float_foc_wrapper.h"
#include "modules/ahrs/comp_nav_filter.h"
#include "subsystems/ahrs.h"
#include "subsystems/abi.h"
#include "state.h"

#ifndef AHRS_FOC_OUTPUT_ENABLED
#define AHRS_FOC_OUTPUT_ENABLED TRUE
#endif
PRINT_CONFIG_VAR(AHRS_FOC_OUTPUT_ENABLED)

/** if TRUE with push the estimation results to the state interface */
static bool ahrs_foc_output_enabled;
static uint8_t ahrs_foc_id = AHRS_COMP_ID_FOC;

#if PERIODIC_TELEMETRY
#include "subsystems/datalink/telemetry.h"
#include "mcu_periph/sys_time.h"
static void send_euler(struct transport_tx *trans, struct link_device *dev)
{
  struct FloatEulers euler;
  euler.phi = (float)comp_nav_filter_Y.roll_est;
  euler.theta = (float)comp_nav_filter_Y.pitch_est;
  euler.psi = (float)comp_nav_filter_Y.yaw_est;
  pprz_msg_send_AHRS_EULER(trans, dev, AC_ID,
                           &euler.phi,
                           &euler.theta,
                           &euler.psi,
                           &ahrs_foc_id);
}
#endif


/** ABI binding for IMU data.
 * Used for gyro, accel ABI messages.
 */
#ifndef AHRS_FOC_IMU_ID
#define AHRS_FOC_IMU_ID ABI_BROADCAST
#endif
PRINT_CONFIG_VAR(AHRS_FOC_IMU_ID)

static abi_event gyro_ev;
static abi_event accel_ev;


static void gyro_cb(uint8_t __attribute__((unused)) sender_id,
                    uint32_t stamp, struct Int32Rates *gyro)
{
  (void)stamp;
  // update inputs with float gyro data
  // assuming the IMU is aligned with the body
  struct FloatRates gyro_f;
  RATES_FLOAT_OF_BFP(gyro_f, *gyro);
  comp_nav_filter_U.roll_gyro = gyro_f.p; // in [rad/s]
  comp_nav_filter_U.pitch_gyro = gyro_f.q; // in [rad/s]
  comp_nav_filter_U.yaw_gyro = gyro_f.r; // in [rad/s]
}

static void accel_cb(uint8_t sender_id __attribute__((unused)),
                     uint32_t stamp __attribute__((unused)),
                     struct Int32Vect3 *accel)
{
  (void)stamp;
  // update inputs with float accel data
  struct FloatVect3 accel_f;
  ACCELS_FLOAT_OF_BFP(accel_f, *accel);
  comp_nav_filter_U.roll_accel = accel_f.x; // [m/s^2]
  comp_nav_filter_U.pitch_accel = accel_f.y; // [m/s^2]
  comp_nav_filter_U.yaw_accel = accel_f.z; // [m/s^2]
}


static bool ahrs_foc_enable_output(bool enable)
{
  ahrs_foc_output_enabled = enable;
  return ahrs_foc_output_enabled;
}

void ahrs_foc_register(void)
{
  ahrs_foc_output_enabled = AHRS_FOC_OUTPUT_ENABLED;
  //ahrs_foc_init();
  ahrs_register_impl(ahrs_foc_enable_output);

  // initialize filter
  comp_nav_filter_initialize();

  // subscribe to messages
  /*
   * Subscribe to scaled IMU measurements and attach callbacks
   */
  AbiBindMsgIMU_GYRO_INT32(AHRS_FOC_IMU_ID, &gyro_ev, gyro_cb);
  AbiBindMsgIMU_ACCEL_INT32(AHRS_FOC_IMU_ID, &accel_ev, accel_cb);

#if PERIODIC_TELEMETRY
  register_periodic_telemetry(DefaultPeriodic, PPRZ_MSG_ID_AHRS_EULER, send_euler);
#endif
}

/**
 * Periodic function
 */
void ahrs_foc_periodic(void)
{
  // update inputs -> done in callbacks

  // run step
  comp_nav_filter_step();

  // update outputs
}

