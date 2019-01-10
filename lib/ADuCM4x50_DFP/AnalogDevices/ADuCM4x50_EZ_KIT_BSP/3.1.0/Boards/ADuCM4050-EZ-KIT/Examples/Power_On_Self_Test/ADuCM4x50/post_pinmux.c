/*
 *  (C) Copyright 2016 - Analog Devices, Inc. All Rights Reserved.
 *
 * This software is proprietary and confidential.  By using this software
 * you agree to the terms of the associated Analog Devices License Agreement.
 *
 * Project Name:        Power_On_Self_Test
 *
 * Hardware:                ADuCM4x50 EZKIT
 *
 * Description:     This file provides pinmuxing for the POST tests
 */

#include <adi_processor.h>

#define SPI2_RDY_PORTP0_MUX  ((uint16_t) ((uint16_t) 3<<6))
#define SPI2_SCLK_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<4))
#define SPI2_MISO_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<6))
#define SPI2_MOSI_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<8))
#define SPI2_CS_0_PORTP1_MUX  ((uint16_t) ((uint16_t) 1<<10))
#define SPI2_CS_2_PORTP2_MUX_LF  ((uint32_t) ((uint32_t) 2<<20))
#define SPI2_CS_2_PORTP2_MUX_WL  ((uint32_t) ((uint32_t) 1<<30))
#define I2C0_SCL0_PORTP0_MUX  ((uint16_t) ((uint16_t) 1<<8))
#define I2C0_SDA0_PORTP0_MUX  ((uint16_t) ((uint16_t) 1<<10))
#define BEEPER_TONE_N_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<16))
#define BEEPER_TONE_P_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<18))
#define UART0_TX_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<20))
#define UART0_RX_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<22))
#define SYS_WAKEUP_SYS_WAKE0_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<30))
#define SWD0_SWD0_CLK_PORTP0_MUX  ((uint16_t) ((uint16_t) 0<<12))
#define SWD0_SWD0_DATA_PORTP0_MUX  ((uint16_t) ((uint16_t) 0<<14))



int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* Port Control MUX registers */
    *((volatile uint32_t *)REG_GPIO0_CFG) = I2C0_SCL0_PORTP0_MUX | I2C0_SDA0_PORTP0_MUX
     | BEEPER_TONE_N_PORTP0_MUX | BEEPER_TONE_P_PORTP0_MUX | UART0_TX_PORTP0_MUX
     | UART0_RX_PORTP0_MUX | SYS_WAKEUP_SYS_WAKE0_PORTP0_MUX | SWD0_SWD0_CLK_PORTP0_MUX
     | SWD0_SWD0_DATA_PORTP0_MUX | SPI2_RDY_PORTP0_MUX;
    *((volatile uint32_t *)REG_GPIO1_CFG) = SPI2_SCLK_PORTP1_MUX | SPI2_MISO_PORTP1_MUX
     | SPI2_MOSI_PORTP1_MUX | SPI2_CS_0_PORTP1_MUX ;
    *((volatile uint32_t *)REG_GPIO2_CFG) = SPI2_CS_2_PORTP2_MUX_LF | SPI2_CS_2_PORTP2_MUX_WL ;


    return 0;
}

