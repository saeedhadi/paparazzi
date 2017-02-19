/*
 * Copyright (C) 2009  Gautier Hattenberger
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

/** \file demo_module.h
 *
 * demo module with blinking LEDs
 */

#ifndef DRIVERS_TEST_H
#define DRIVERS_TEST_H

#include "std.h"
#include "mcu_periph/adc.h"

// Definitions of pins

extern bool ams_status;
extern bool pwr_ready;
extern bool pwr_stdby;
extern bool rtds;

void fsae_electric_init(void);
void fsae_electric_periodic(void);
/** Reset sweep number */
extern void fsae_electric_UpdateDac1(uint16_t val);
extern void fsae_electric_UpdateDac2(uint16_t val);
extern uint16_t dac_1;
extern uint16_t dac_2;

#endif /* DRIVERS_TEST */
