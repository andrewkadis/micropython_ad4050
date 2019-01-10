/*
 **
 ** Source file generated on October 11, 2016 at 09:52:44.	
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
 ** ADC0_IN (ADC0_VIN0, ADC0_VIN1, ADC0_VIN2, ADC0_VIN3, ADC0_VIN4, ADC0_VIN5, ADC0_VIN6)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P2_03, P2_04, P2_05, P2_06, P2_07, P2_08, P2_09
 */

#include <sys/platform.h>
#include <stdint.h>

#define ADC0_IN_ADC0_VIN0_PORTP2_MUX  ((uint16_t) ((uint16_t) 1<<6))
#define ADC0_IN_ADC0_VIN1_PORTP2_MUX  ((uint16_t) ((uint16_t) 1<<8))
#define ADC0_IN_ADC0_VIN2_PORTP2_MUX  ((uint16_t) ((uint16_t) 1<<10))
#define ADC0_IN_ADC0_VIN3_PORTP2_MUX  ((uint16_t) ((uint16_t) 1<<12))
#define ADC0_IN_ADC0_VIN4_PORTP2_MUX  ((uint16_t) ((uint16_t) 1<<14))
#define ADC0_IN_ADC0_VIN5_PORTP2_MUX  ((uint32_t) ((uint32_t) 1<<16))
#define ADC0_IN_ADC0_VIN6_PORTP2_MUX  ((uint32_t) ((uint32_t) 1<<18))

int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* PORTx_MUX registers */
    *pREG_GPIO2_CFG = ADC0_IN_ADC0_VIN0_PORTP2_MUX | ADC0_IN_ADC0_VIN1_PORTP2_MUX
     | ADC0_IN_ADC0_VIN2_PORTP2_MUX | ADC0_IN_ADC0_VIN3_PORTP2_MUX | ADC0_IN_ADC0_VIN4_PORTP2_MUX
     | ADC0_IN_ADC0_VIN5_PORTP2_MUX | ADC0_IN_ADC0_VIN6_PORTP2_MUX;

    return 0;
}

