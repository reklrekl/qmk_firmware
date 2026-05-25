#include "gmmk_i2c.h"
#include "gpio.h"

#ifndef SLED1734X_USE_BITBANG_I2C

void i2c_init(void) {
    GMMK_SYS1_AHBCLKEN |= GMMK_I2C0_CLKEN;
    (void)GMMK_SYS1_AHBCLKEN;

    // drive strength all gpio A 20ma
    SN_GPIO0->MODE |= 0xFFFF0000;

    GMMK_I2C0->SCLHT  = 59;
    GMMK_I2C0->SCLLT  = 59;
    GMMK_I2C0->CTRL_b.I2CEN = 1;
}

void i2c_write_reg(uint8_t devaddr, uint8_t regaddr, uint8_t val) {
    GMMK_I2C0->CTRL_b.STA = 1;
    while (!(GMMK_I2C0->STAT & mskI2C_START_DONE));
    GMMK_I2C0->STAT_b.I2CIF = 1;

    GMMK_I2C0->TXDATA = devaddr;
    while (!(GMMK_I2C0->STAT & mskI2C_ACK_DONE));
    GMMK_I2C0->STAT_b.I2CIF = 1;

    GMMK_I2C0->TXDATA = regaddr;
    while (!(GMMK_I2C0->STAT & mskI2C_ACK_DONE));
    GMMK_I2C0->STAT_b.I2CIF = 1;

    GMMK_I2C0->TXDATA = val;
    while (!(GMMK_I2C0->STAT & mskI2C_ACK_DONE));
    GMMK_I2C0->STAT_b.I2CIF = 1;

    GMMK_I2C0->CTRL_b.STO = 1;
    while (!(GMMK_I2C0->STAT & mskI2C_STOP_DONE));
    GMMK_I2C0->STAT_b.I2CIF = 1;
}

#endif
