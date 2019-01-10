/*
 **
 ** Source file generated on September 9, 2016 at 13:30:37.	
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
 ** UART0 (Tx, Rx)
 ** UART1 (Tx, Rx)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P0_10, P0_11, P1_15, P2_0
 */

#include <adi_processor.h>


#define UART1_TX_PORTP1_MUX  ((uint32_t) ((uint32_t) 0x2 << 30))
#define UART1_RX_PORTP2_MUX  ((uint32_t) ((uint32_t) 0x2 << 0))


int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* Port Control MUX registers */
    *((volatile uint32_t *)REG_GPIO1_CFG) = UART1_TX_PORTP1_MUX; 
    *((volatile uint32_t *)REG_GPIO2_CFG) = UART1_RX_PORTP2_MUX;
										  


    return 0;
}

