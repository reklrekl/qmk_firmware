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

// uncomment to use Bit-Bang driver instead of HW I2C
//#define SLED1734X_USE_BITBANG_I2C

// Old config values differing from default for refernce
//#define SLED1734X_STAGGERED_DELAY_TIMING 0x0F             // Enable max. delay for STD2 and STD1 (Why?)
// larger current crash KB
#define SLED1734X_STAGGERED_DELAY_TIMING 0x27               // max delay, helps with KB crashing at higher currents
//#define SLED1734X_CURRENT_CONTROL_ENABLE 0x9E               // 23 mA, QMK Driver default is 0xB0 (32mA)
#define SLED1734X_CURRENT_CONTROL_ENABLE 0xA0               // 24 mA, QMK Driver default is 0xB0 (32mA)
//#define SLED1734X_VAF_2_TUNE 0x80                         // Force Vaf disabled, Vaf3 = VDD (Why?)


// already shift I2C addresses for custom unbuffered driver
#define SLED1734X_I2C_ADDRESS_1 (SLED1734X_I2C_ADDRESS_GND << 1)
#define SLED1734X_I2C_ADDRESS_2 (SLED1734X_I2C_ADDRESS_VDDIO << 1)

#define SLED1734X_SDB_PIN B0

