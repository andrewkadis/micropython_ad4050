/*
 **
 ** Source file generated on September 9, 2016 at 17:06:52. 
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
 ** RGB_TMR0 (RGB_TMR0_1, RGB_TMR0_2, RGB_TMR0_3)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P1_06, P1_07, P1_08
 */

#include <sys/platform.h>
#include <stdint.h>

#define RGB_TMR0_RGB_TMR0_1_PORTP1_MUX  ((uint16_t) ((uint16_t) 3<<12))
#define RGB_TMR0_RGB_TMR0_2_PORTP1_MUX  ((uint16_t) ((uint16_t) 3<<14))
#define RGB_TMR0_RGB_TMR0_3_PORTP1_MUX  ((uint32_t) ((uint32_t) 3<<16))

int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* PORTx_MUX registers */
    *pREG_GPIO1_CFG = RGB_TMR0_RGB_TMR0_1_PORTP1_MUX | RGB_TMR0_RGB_TMR0_2_PORTP1_MUX
     | RGB_TMR0_RGB_TMR0_3_PORTP1_MUX;

    return 0;
}

