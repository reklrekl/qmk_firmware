/*
 * Copyright 2023 Dimitris Mantzouranis <d3xter93@gmail.com>
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

#include <stdint.h>

/* Command Registers Declarations */
#define SLED1734X_REG_COMMAND 0xFD
#define SLED1734X_COMMAND_FRAME_1 0x00
#define SLED1734X_COMMAND_FRAME_2 0x01
#define SLED1734X_COMMAND_FUNCTION 0x0B
#define SLED1734X_COMMAND_CURRENT_TUNE 0x0C
#define SLED1734X_COMMAND_VAF_TUNE 0x0D

/* Function Registers Declarations */
#define SLED1734X_FUNCTION_REG_CONFIGURATION 0x00     // Configuration register
#define SLED1734X_FUNCTION_REG_PICTUREDISPLAY 0x01    // Picture Display register
#define SLED1734X_FUNCTION_REG_DISPLAYOPTION 0x05     // Display Option register
#define SLED1734X_FUNCTION_REG_AUDIOSYNC 0x06         // Audio Sync register
#define SLED1734X_FUNCTION_REG_BREATHCONTROL1 0x08    // Breath Control 1 register
#define SLED1734X_FUNCTION_REG_BREATHCONTROL2 0x09    // Breath Control 2 register
#define SLED1734X_FUNCTION_REG_SOFTWARE_SHUTDOWN 0x0A // Shutdown register
#define SLED1734X_FUNCTION_REG_AUDIOGAIN_CONTROL 0x0B // AGC Control register
#define SLED1734X_FUNCTION_REG_STAGGERED_DELAY 0x0D   // Staggered Delay register
#define SLED1734X_FUNCTION_REG_SLEW_RATE_CONTROL 0x0E // Slew Rate Control register
#define SLED1734X_FUNCTION_REG_CURRENT_CONTROL 0x0F   // Current Control register
#define SLED1734X_FUNCTION_REG_OPEN_SHORT_1 0x10      // Open Short Test 1 register
#define SLED1734X_FUNCTION_REG_OPEN_SHORT_2 0x11      // Open Short Test 2 register
#define SLED1734X_FUNCTION_REG_VAF_1 0x14             // VAF 1 register
#define SLED1734X_FUNCTION_REG_VAF_2 0x15             // VAF 2 register
#define SLED1734X_FUNCTION_REG_THERMAL_DETECTION 0x17 // Thermal Detection register
#define SLED1734X_FUNCTION_REG_TP4VAF_1 0x18          // TP4Vaf Register 1
#define SLED1734X_FUNCTION_REG_TP4VAF_2 0x19          // TP4Vaf Register 2
#define SLED1734X_FUNCTION_REG_TP4VAF_3 0x1A          // TP4Vaf Register 3
#define SLED1734X_FUNCTION_REG_ID 0x1B                // Chip ID Register

/* Function Registers Defaults */
// Sync Mode. 00 - High Impedance, 01 Master, 10 Slave
#ifndef SLED1734X_SYNC_MODE
#    define SLED1734X_SYNC_MODE 0x00
#endif
// Matrix Type. 00 - Type-1, 01 Type-2, 10 Type-3, 11 Type-4
#ifndef SLED1734X_MATRIX_TYPE
#    define SLED1734X_MATRIX_TYPE 0x10
#endif
// Blink Frame and Enable. Default to Disabled
#ifndef SLED1734X_BLINK_FRAME
#    define SLED1734X_BLINK_FRAME 0x00
#endif
// Audio Sync Enable. Default to Disabled
#ifndef SLED1734X_AUDIOSYNC_ENABLE
#    define SLED1734X_AUDIOSYNC_ENABLE 0x00
#endif
// Fade Out and Fade In Time setting. Default to 0
#ifndef SLED1734X_FADE_TIME
#    define SLED1734X_FADE_TIME 0x00
#endif
// Breathe and Continuous Breathe Enable. Default to Disabled
#ifndef SLED1734X_BREATHE_ENABLE
#    define SLED1734X_BREATHE_ENABLE 0x00
#endif
// Audio Gain Control. Mode, Gain and Enable setting. Default to Disabled
#ifndef SLED1734X_AUDIOGAIN_MODE
#    define SLED1734X_AUDIOGAIN_MODE 0x00
#endif
// Staggered Delay Timing setting. Default to 0
#ifndef SLED1734X_STAGGERED_DELAY_TIMING
#    define SLED1734X_STAGGERED_DELAY_TIMING 0x00
#endif
// Slew Rate Control Enable. Default to Enabled
#ifndef SLED1734X_SLEW_RATE_CONTROL_ENABLE
#    define SLED1734X_SLEW_RATE_CONTROL_ENABLE 0x01
#endif
// Current Control Enable. Default to Disabled
#ifndef SLED1734X_CURRENT_CONTROL_ENABLE
#    define SLED1734X_CURRENT_CONTROL_ENABLE 0xB0
#endif
// Open Short Detection Mode. Default to Disabled
#ifndef SLED1734X_OPEN_SHORT_1_MODE
#    define SLED1734X_OPEN_SHORT_1_MODE 0x00
#endif
// Open Short Detection Interrupt. Default to Disabled
#ifndef SLED1734X_OPEN_SHORT_2_MODE
#    define SLED1734X_OPEN_SHORT_2_MODE 0x00
#endif
// VAF fine tune setting. Default to 0x44
#ifndef SLED1734X_VAF_1_TUNE
#    define SLED1734X_VAF_1_TUNE 0x44
#endif
// VAF control setting. Default to 0x04
#ifndef SLED1734X_VAF_2_TUNE
#    define SLED1734X_VAF_2_TUNE 0x04
#endif

/* SW Shutdown Declarations */
// 0 - SW Shutdown Mode, 1 Normal Mode
#define SLED1734X_SOFTWARE_SHUTDOWN_SSD_SHUTDOWN 0x00
#define SLED1734X_SOFTWARE_SHUTDOWN_SSD_NORMAL 0x01

/* I2C Address Declarations */
#define SLED1734X_I2C_ADDRESS_GND 0x74
#define SLED1734X_I2C_ADDRESS_SCL 0x75
#define SLED1734X_I2C_ADDRESS_SDA 0x76
#define SLED1734X_I2C_ADDRESS_VDDIO 0x77


#define SLED1734X_LED_COUNT RGB_MATRIX_LED_COUNT

extern const uint8_t g_led_pos[SLED1734X_LED_COUNT];
extern const uint8_t state_frame1[2][16];
extern const uint8_t state_frame2[2][16];
