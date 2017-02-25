/*
 * Copyright (C) 2016 Michal Podhradsky <michal.podhradsky@aggiemail.usu.edu>
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
 * FOC wrapoper
 */
#include "modules/foc/foc_wrapper.h"
#include "modules/foc/comp_nav_filter.h"

#include "subsystems/abi.h"

// State interface for rotation compensation
#include "state.h"

/** ABI binding for IMU data.
 * Used for gyro, accel ABI messages.
 */
#ifndef FOC_IMU_ID
#define FOC_IMU_ID ABI_BROADCAST
#endif
PRINT_CONFIG_VAR(FOC_IMU_ID)

static abi_event gyro_ev;
static abi_event accel_ev;



static void gyro_cb(uint8_t __attribute__((unused)) sender_id,
                    uint32_t stamp, struct Int32Rates *gyro)
{
  // update inputs with float gyro data
}

static void accel_cb(uint8_t sender_id __attribute__((unused)),
                     uint32_t stamp __attribute__((unused)),
                     struct Int32Vect3 *accel)
{
  // update inputs with float accel data
}

/**
 * Initialization function
 */
void foc_init(void)
{
	// initialize filter
	comp_nav_filter_initialize();

	// subscribe to messages
  /*
   * Subscribe to scaled IMU measurements and attach callbacks
   */
  AbiBindMsgIMU_GYRO_INT32(FOC_IMU_ID, &gyro_ev, gyro_cb);
  AbiBindMsgIMU_ACCEL_INT32(FOC_IMU_ID, &accel_ev, accel_cb);
}



/**
 * Periodic function
 */
void foc_periodic(void)
{
	// update inputs

	// run step
	comp_nav_filter_step();

	// update outputs
}
