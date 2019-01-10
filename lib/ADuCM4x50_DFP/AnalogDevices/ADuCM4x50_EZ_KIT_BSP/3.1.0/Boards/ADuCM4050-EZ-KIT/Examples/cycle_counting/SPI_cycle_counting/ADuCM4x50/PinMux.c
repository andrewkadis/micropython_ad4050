/*
 **
 ** Source file generated on September 14, 2014 at 22:01:39.	
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
 ** SPI2 (SCLK, MISO, MOSI)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P1_02, P1_03, P1_04
 */

#include <adi_processor.h>

#define SPI2_CLK_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<4))
#define SPI2_MOSI_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<6))
#define SPI2_MISO_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<8))

int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* PORTx_MUX registers */
    *pREG_GPIO1_CFG = SPI2_CLK_PORTP1_MUX | SPI2_MOSI_PORTP1_MUX | SPI2_MISO_PORTP1_MUX;

    return 0;
}

