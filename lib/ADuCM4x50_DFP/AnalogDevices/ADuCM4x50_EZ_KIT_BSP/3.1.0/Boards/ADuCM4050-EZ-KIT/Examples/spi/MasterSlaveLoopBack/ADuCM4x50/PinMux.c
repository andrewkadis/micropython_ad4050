/*
 **
 ** Source file generated on November 14, 2014 at 23:26:46.	
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
 ** SPI0 (SCLK, MOSI, MISO, CS_0)
 ** SPI1 (SCLK, MISO, MOSI, CS_0)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P0_00, P0_01, P0_02, P0_03, P1_06, P1_07, P1_08, P1_09
 */

#include <stdint.h>
#include <adi_processor.h>

#define SPI0_SCLK_PORTP0_MUX  ((uint16_t) ((uint16_t) 1<<0))
#define SPI0_MOSI_PORTP0_MUX  ((uint16_t) ((uint16_t) 1<<2))
#define SPI0_MISO_PORTP0_MUX  ((uint16_t) ((uint16_t) 1<<4))
#define SPI0_CS_0_PORTP0_MUX  ((uint16_t) ((uint16_t) 1<<6))
#define SPI1_SCLK_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<12))
#define SPI1_MISO_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<14))
#define SPI1_MOSI_PORTP1_MUX  ((uint32_t) ((uint32_t) 1<<16))
#define SPI1_CS_0_PORTP1_MUX  ((uint32_t) ((uint32_t) 1<<18))



int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* Port Control MUX registers */
    *((volatile uint32_t *)REG_GPIO0_CFG) = SPI0_SCLK_PORTP0_MUX | SPI0_MOSI_PORTP0_MUX
     | SPI0_MISO_PORTP0_MUX | SPI0_CS_0_PORTP0_MUX;
    *((volatile uint32_t *)REG_GPIO1_CFG) = SPI1_SCLK_PORTP1_MUX | SPI1_MISO_PORTP1_MUX
     | SPI1_MOSI_PORTP1_MUX | SPI1_CS_0_PORTP1_MUX;

    return 0;
}

