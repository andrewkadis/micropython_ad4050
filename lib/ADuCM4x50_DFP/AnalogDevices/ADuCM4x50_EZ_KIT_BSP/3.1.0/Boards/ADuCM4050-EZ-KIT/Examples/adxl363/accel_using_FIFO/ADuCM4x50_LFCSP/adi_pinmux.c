/*
 **
 ** Source file generated on November 25, 2016 at 17:38:45.	
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
 ** SPI2 (CLK, MOSI, MISO, CS_2, RDY)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P0_03, P1_02, P1_03, P1_04, P2_10
 */

#include <stdint.h>
#include <adi_processor.h>

#define SPI2_CLK_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<4))
#define SPI2_MOSI_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<6))
#define SPI2_MISO_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<8))
#define SPI2_CS_2_PORTP2_MUX  ((uint32_t) ((uint32_t) 2<<20))
#define SPI2_RDY_PORTP0_MUX  ((uint16_t) ((uint16_t) 3<<6))

int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* PORTx_MUX registers */
    *pREG_GPIO0_CFG = SPI2_RDY_PORTP0_MUX;
    *pREG_GPIO1_CFG = SPI2_CLK_PORTP1_MUX | SPI2_MOSI_PORTP1_MUX
     | SPI2_MISO_PORTP1_MUX;
    *pREG_GPIO2_CFG = SPI2_CS_2_PORTP2_MUX;

    return 0;
}

