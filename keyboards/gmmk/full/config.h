/*
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define SERIAL_NUMBER "GMMK Full"

#define LAYER_STATE_8BIT
#define MATRIX_COLS 16
#define MATRIX_ROWS 7

//Saving RAM Space
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
//default is 4
//#define USB_DEFAULT_BUFFER_CAPACITY 2

#define EEPROM_SIZE FEE_DENSITY_BYTES
