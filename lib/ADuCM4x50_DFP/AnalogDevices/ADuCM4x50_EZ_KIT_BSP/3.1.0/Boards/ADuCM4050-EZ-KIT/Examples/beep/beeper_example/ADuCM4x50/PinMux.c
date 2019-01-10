/*
 **
 ** Source file generated on November 4, 2016 at 16:03:26.	
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
 ** BEEPER0 (TONE_N, TONE_P)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P0_08, P0_09
 */

#include <sys/platform.h>
#include <stdint.h>

#define BEEPER0_TONE_N_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<16))
#define BEEPER0_TONE_P_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<18))

int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* PORTx_MUX registers */
    *pREG_GPIO0_CFG = BEEPER0_TONE_N_PORTP0_MUX | BEEPER0_TONE_P_PORTP0_MUX;

    return 0;
}

