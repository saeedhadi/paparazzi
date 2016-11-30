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
 * @file modules/ins/ins_skeleton.h
 *
 * Paparazzi specific wrapper to run simple module based INS.
 */


#ifndef INS_LPE_H
#define INS_LPE_H

#include "std.h"
#include "math/pprz_geodetic_int.h"
#include "math/pprz_algebra_int.h"
#include "math/pprz_orientation_conversion.h"

enum {X_x = 0, X_y, X_z, X_vx, X_vy, X_vz, X_bx, X_by, X_bz, n_x};
enum {U_ax = 0, U_ay, U_az, n_u};

extern void ins_lpe_init(void);
extern void ins_lpe_periodic(void);

#endif /* INS_LPE_H */
