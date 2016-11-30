/*
 * Copyright (C) 2016 Felix Ruess <felix.ruess@gmail.com>
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
 * along with Paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/**
 * @file modules/ins/ins_skeleton.c
 *
 * Paparazzi specific wrapper to run simple module based INS.
 */

#include "modules/ins/ins_lpe.h"
#include "subsystems/abi.h"
#include "mcu_periph/sys_time.h"
#include "message_pragmas.h"

#include "state.h"

#ifndef USE_INS_NAV_INIT
#define USE_INS_NAV_INIT TRUE
PRINT_CONFIG_MSG("USE_INS_NAV_INIT defaulting to TRUE")
#endif

/*
 * ABI bindings
 */
/** baro */
#ifndef INS_LPE_BARO_ID
#if USE_BARO_BOARD
#define INS_LPE_BARO_ID BARO_BOARD_SENDER_ID
#else
#define INS_MODULE_BARO_ID ABI_BROADCAST
#endif
#endif
PRINT_CONFIG_VAR(INS_LPE_BARO_ID)

/** IMU (accel, body_to_imu) */
#ifndef INS_LPE_IMU_ID
#define INS_LPE_IMU_ID ABI_BROADCAST
#endif
PRINT_CONFIG_VAR(INS_LPE_IMU_ID)

/** ABI binding for gps data.
 * Used for GPS ABI messages.
 */
#ifndef INS_LPE_GPS_ID
#define INS_LPE_GPS_ID GPS_MULTI_ID
#endif
PRINT_CONFIG_VAR(INS_LPE_GPS_ID)


float A[n_x][n_x]; // process matrix
float B[n_x][n_u]; // input matrix
float R[n_u][n_u]; // measurement noise covariance
float Q[n_x][n_x]; // process noise covariance
float P[n_x][n_x]; // estimate error covariance
float x[n_x]; // state vector
float u[n_u]; // input vector

void ins_lpe_init(void)
{



}


void ins_lpe_periodic(void)
{

}
