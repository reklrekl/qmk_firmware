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

#include "rgb_matrix.h"
#include "sled1734x_unbuffered.h"
#include "gpio.h"
#include "wait.h"

// Uncomment to use bit-bang I2C instead of the hardware I2C peripheral driver
// #define SLED1734X_USE_BITBANG_I2C

#ifndef SLED1734X_USE_BITBANG_I2C
#    include "drivers/i2c/gmmk_i2c.h"
#else

#define I2C_SCL A4
#define I2C_SDA A5
#define I2C_SDB B0

#define I2C_SCL_IN gpio_read_pin(I2C_SCL)
#define I2C_SDA_IN gpio_read_pin(I2C_SDA)

#define I2C_SCL_HI  do { gpio_set_pin_output(I2C_SCL); gpio_write_pin_high(I2C_SCL); } while (0)
#define I2C_SCL_LO  do { gpio_set_pin_output(I2C_SCL); gpio_write_pin_low(I2C_SCL); } while (0)
#define I2C_SCL_HIZ do { gpio_set_pin_input_high(I2C_SCL); } while (0)

#define I2C_SDA_HI  do { gpio_set_pin_output(I2C_SDA); gpio_write_pin_high(I2C_SDA); } while (0)
#define I2C_SDA_LO  do { gpio_set_pin_output(I2C_SDA); gpio_write_pin_low(I2C_SDA); } while (0)
#define I2C_SDA_HIZ do { gpio_set_pin_input_high(I2C_SDA); } while (0)


/*
 * according to the spec, high SCL peroid 0.7us, low SCL peroid 1.3us
 *
 * i2c_delay 1 loop about 7 cycles. Under 48MHz, the actual delay is around 0.9us and 1.5us respectively.
 *
 * according to the idle thread replacement it's 9 cycles.
 */
#define I2C_DELAY           i2c_delay(12)

static __inline void i2c_delay(uint32_t loop)
{
    // #pragma GCC unroll 0
    for (uint32_t i = 0; i < loop; i++) {
        __NOP();
    }
}

void i2c_init(void)
{
    // drive strength all gpio A 20ma
    SN_GPIO0->MODE |= 0xFFFF0000;

    I2C_SCL_HI;
    I2C_SDA_HIZ;
}

static void i2c_start_phase(void)
{
    /* START */
    I2C_SDA_LO;
    I2C_DELAY;
    I2C_SCL_LO;
    I2C_DELAY;      //(not needed in testing)
}



static void i2c_stop_phase(void)
{
    I2C_SDA_LO;
    I2C_DELAY;      //(not needed in testing)

    /* STOP */
    I2C_SCL_HI;
    I2C_DELAY;      //(not needed in testing)
    I2C_SDA_HIZ;

    I2C_DELAY;      //(not needed in testing)
    I2C_DELAY;      //(not needed in testing)
}


bool i2c_writeb(uint8_t data){       // Send a byte over I2C
    for(uint8_t i = 0; i < 8; i++)          // 8 bits, so 8 loops
    {
        if((0x80 >> i) & data) I2C_SDA_HI;               // Check if i bit to be sent is a 1 or 0  // It's a 1, so send a logic HIGH
        else I2C_SDA_LO;                       // It's a 0, so just pretend we need send a 0 for completion
        //Generate Clock for data bits
        I2C_SCL_HI;
        I2C_DELAY; //needed
        I2C_SCL_LO;
        I2C_DELAY;      //(not needed in testing)
    }
    // Tick Signal that we sent the logic
    I2C_SDA_HIZ;
    I2C_SCL_HI;
    I2C_DELAY; //needed
    bool ack = !I2C_SDA_IN;
    I2C_SCL_LO;
    I2C_DELAY;      //(not needed in testing)
    return ack;
}

static void i2c_write_reg(uint8_t devid, uint8_t reg, uint8_t data)
{
    i2c_start_phase();
    i2c_writeb(devid);
    i2c_writeb(reg);
    i2c_writeb(data);
    i2c_stop_phase();
}

#endif



#define SLED1734X_LED_CHIP0_COUNT 42

static uint8_t last_frame[2] = {0xFF, 0xFF};



static void reg_write(uint8_t addr, uint8_t reg, uint8_t val) {
    i2c_write_reg(addr, reg, val);
}

void sled1734x_init_driver(uint8_t addr) {
    uint8_t chip_id = (addr == SLED1734X_I2C_ADDRESS_2) ? 1 : 0;

    // select function frame and sw shutdown
    reg_write(addr, SLED1734X_REG_COMMAND, SLED1734X_COMMAND_FUNCTION);
    reg_write(addr, SLED1734X_FUNCTION_REG_SOFTWARE_SHUTDOWN, SLED1734X_SOFTWARE_SHUTDOWN_SSD_SHUTDOWN);
    // sync mode
    reg_write(addr, SLED1734X_FUNCTION_REG_CONFIGURATION,   SLED1734X_SYNC_MODE);
    // matrix type
    reg_write(addr, SLED1734X_FUNCTION_REG_PICTUREDISPLAY,  SLED1734X_MATRIX_TYPE);
    // blink frame
    reg_write(addr, SLED1734X_FUNCTION_REG_DISPLAYOPTION,   SLED1734X_BLINK_FRAME);
    // audio sync off
    reg_write(addr, SLED1734X_FUNCTION_REG_AUDIOSYNC,       SLED1734X_AUDIOSYNC_ENABLE);
    // breathe control
    reg_write(addr, SLED1734X_FUNCTION_REG_BREATHCONTROL1,  SLED1734X_FADE_TIME);
    reg_write(addr, SLED1734X_FUNCTION_REG_BREATHCONTROL2,  SLED1734X_BREATHE_ENABLE);
    // audio gain off
    reg_write(addr, SLED1734X_FUNCTION_REG_AUDIOGAIN_CONTROL, SLED1734X_AUDIOGAIN_MODE);
    // staggered delay off
    reg_write(addr, SLED1734X_FUNCTION_REG_STAGGERED_DELAY, SLED1734X_STAGGERED_DELAY_TIMING);
    // slew rate control enable
    reg_write(addr, SLED1734X_FUNCTION_REG_SLEW_RATE_CONTROL, SLED1734X_SLEW_RATE_CONTROL_ENABLE);
    // VAF fine tuning
    reg_write(addr, SLED1734X_FUNCTION_REG_VAF_1,           SLED1734X_VAF_1_TUNE );
    reg_write(addr, SLED1734X_FUNCTION_REG_VAF_2,           SLED1734X_VAF_2_TUNE );
    // current control
    reg_write(addr, SLED1734X_FUNCTION_REG_CURRENT_CONTROL, SLED1734X_CURRENT_CONTROL_ENABLE);

    // select page frame 1
    reg_write(addr, SLED1734X_REG_COMMAND, SLED1734X_COMMAND_FRAME_1);

    // enable only physically present LEDs in control register
    for (int i = 0; i <= 0x0F; i++) {
        reg_write(addr, i, state_frame1[chip_id][i]);
    }
    // blink control registers (not needed)
    for (int i = 0x10; i <= 0x1F; i++) {
        reg_write(addr, i, 0x00);
    }
    // set PWM on all LEDs to 0
    for (int i = 0x20; i <= 0x9F; i++) {
        reg_write(addr, i, 0x00);
    }

    // select page frame 2
    reg_write(addr, SLED1734X_REG_COMMAND, SLED1734X_COMMAND_FRAME_2);

    // enable only physically present LEDs in frame 2 control register
    for (int i = 0; i <= 0x0F; i++) {
        reg_write(addr, i, state_frame2[chip_id][i]);
    }
    // blink control registers (not needed)
    for (int i = 0x10; i <= 0x1F; i++) {
        reg_write(addr, i, 0x00);
    }
    // set PWM on all LEDs to 0
    for (int i = 0x20; i <= 0x9F; i++) {
        reg_write(addr, i, 0x00);
    }

    reg_write(addr, SLED1734X_REG_COMMAND, SLED1734X_COMMAND_FUNCTION);
    reg_write(addr, SLED1734X_FUNCTION_REG_SOFTWARE_SHUTDOWN, 0x01); // Normal mode
}

void sled1734x_init_drivers(void) {
    i2c_init();

    // Enable SLED1734X chips via SDB pin
    gpio_set_pin_output(SLED1734X_SDB_PIN);
    gpio_write_pin_high(SLED1734X_SDB_PIN);
    wait_us(180);

    sled1734x_init_driver(SLED1734X_I2C_ADDRESS_1);
    sled1734x_init_driver(SLED1734X_I2C_ADDRESS_2);

    last_frame[0] = 0xFF;
    last_frame[1] = 0xFF;
}

static void set_pwm(uint8_t dev, uint8_t chip_id, uint8_t addr, uint8_t val) {
    uint8_t frame = (addr >= 0x80) ? SLED1734X_COMMAND_FRAME_2 : SLED1734X_COMMAND_FRAME_1;
    if (last_frame[chip_id] != frame) {
        reg_write(dev, SLED1734X_REG_COMMAND, frame);
        last_frame[chip_id] = frame;
    }
    addr &= 0x7F;
    reg_write(dev, addr + 0x20, val);
}

void sled1734x_set_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < 0 || index >= SLED1734X_LED_COUNT) return;

    uint8_t addr = g_led_pos[index];
    uint8_t chip_id = index >= SLED1734X_LED_CHIP0_COUNT;
    uint8_t dev  = (chip_id) ? SLED1734X_I2C_ADDRESS_2 : SLED1734X_I2C_ADDRESS_1;

    set_pwm(dev, chip_id, addr,         r);
    set_pwm(dev, chip_id, addr + 0x10,  g);
    set_pwm(dev, chip_id, addr + 0x20,  b);
}

void sled1734x_set_color_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < SLED1734X_LED_COUNT; i++) {
        sled1734x_set_color(i, r, g, b);
    }
}

void sled1734x_flush(void) { };


const rgb_matrix_driver_t rgb_matrix_driver = {
    .init           = sled1734x_init_drivers,
    .flush          = sled1734x_flush,
    .set_color      = sled1734x_set_color,
    .set_color_all  = sled1734x_set_color_all,
};
