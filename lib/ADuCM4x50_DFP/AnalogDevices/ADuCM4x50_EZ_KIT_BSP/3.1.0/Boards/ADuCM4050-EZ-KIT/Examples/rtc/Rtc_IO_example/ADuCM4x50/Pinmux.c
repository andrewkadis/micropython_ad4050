/*
 **
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
 ** RTC (RTC_OPC1)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P2_11
 */

#include <adi_processor.h>

#define RTC_OPC1_PORTP2_MUX  ((uint32_t) ((uint32_t) 3<<22))



int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* Port Control MUX registers */
    *((volatile uint32_t *)REG_GPIO2_CFG) = RTC_OPC1_PORTP2_MUX;


    return 0;
}

