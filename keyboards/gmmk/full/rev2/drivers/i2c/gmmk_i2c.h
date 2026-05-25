#pragma once

#include <stdint.h>
#include "sn32_i2c.h"

#define GMMK_I2C0_BASE      0x40018000UL
#define GMMK_I2C0           ((sn32_i2c_t *)GMMK_I2C0_BASE)
#define GMMK_SYS1_AHBCLKEN  (*(volatile uint32_t *)0x4005E000UL)
#define GMMK_I2C0_CLKEN     (1 << 21)

#ifndef SLED1734X_USE_BITBANG_I2C

void i2c_init(void);
void i2c_write_reg(uint8_t devaddr, uint8_t regaddr, uint8_t val);

#endif
