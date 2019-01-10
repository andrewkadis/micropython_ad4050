/*
 **
 ** Source file generated on September 11, 2014 at 11:21:20.	
 **
 ** Copyright (C) 2016 Analog Devices Inc., All Rights Reserved.
 **
 ** This file is generated automatically based upon the options selected in 
 ** the Pin Multiplexing configuration editor. Changes to the Pin Multiplexing
 ** configuration should be made by changing the appropriate options rather
 ** than editing this file.
 **
 ** Selected Peripherals
 ** --------------------
 ** I2C0 (SCL0, SDA0)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P0_04, P0_05
 */

#include <adi_processor.h>

#define I2C0_SCL0_PORTP0_MUX  ((uint16_t) ((uint16_t) 1<<8))
#define I2C0_SDA0_PORTP0_MUX  ((uint16_t) ((uint16_t) 1<<10))



int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* Port Control MUX registers */
    *((volatile uint32_t *)REG_GPIO0_CFG) = I2C0_SCL0_PORTP0_MUX | I2C0_SDA0_PORTP0_MUX;


    return 0;
}

