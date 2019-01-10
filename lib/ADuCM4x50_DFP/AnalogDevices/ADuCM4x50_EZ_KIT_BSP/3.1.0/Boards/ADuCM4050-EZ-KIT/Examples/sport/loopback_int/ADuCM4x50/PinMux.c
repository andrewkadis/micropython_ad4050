/*
 **
 ** Source file generated on November 1, 2016 at 15:57:26.	
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
 ** SPORT0_A (SPT0A_D0, SPT0A_D0, SPT0A_CLK, SPT0A_CLK, SPT0A_FS, SPT0A_FS, SPT0A_CNV, SPT0A_CNV)
 ** SPORT0_B (SPT0B_D0, SPT0B_CLK, SPT0B_FS, SPT0B_CNV)
 **
 ** GPIO (unavailable)
 ** ------------------
 ** P0_00, P0_01, P0_02, P0_03, P0_12, P1_15, P2_00, P2_02, P3_00, P3_01, P3_02, P3_03
 */

#include <adi_processor.h>

#define SPORT0_A_SPT0A_D0_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<24))
#define SPORT0_A_SPT0A_D0_PORTP3_MUX  ((uint16_t) ((uint16_t) 2<<4))
#define SPORT0_A_SPT0A_CLK_PORTP1_MUX  ((uint32_t) ((uint32_t) 1<<30))
#define SPORT0_A_SPT0A_CLK_PORTP3_MUX  ((uint16_t) ((uint16_t) 2<<0))
#define SPORT0_A_SPT0A_FS_PORTP2_MUX  ((uint16_t) ((uint16_t) 1<<0))
#define SPORT0_A_SPT0A_FS_PORTP3_MUX  ((uint16_t) ((uint16_t) 2<<2))
#define SPORT0_A_SPT0A_CNV_PORTP2_MUX  ((uint16_t) ((uint16_t) 1<<4))
#define SPORT0_A_SPT0A_CNV_PORTP3_MUX  ((uint16_t) ((uint16_t) 2<<6))
#define SPORT0_B_SPT0B_D0_PORTP0_MUX  ((uint16_t) ((uint16_t) 2<<4))
#define SPORT0_B_SPT0B_CLK_PORTP0_MUX  ((uint16_t) ((uint16_t) 2<<0))
#define SPORT0_B_SPT0B_FS_PORTP0_MUX  ((uint16_t) ((uint16_t) 2<<2))
#define SPORT0_B_SPT0B_CNV_PORTP0_MUX  ((uint16_t) ((uint16_t) 2<<6))

int32_t adi_initpinmux(void);

/*
 * Initialize the Port Control MUX Registers
 */
int32_t adi_initpinmux(void) {
    /* PORTx_MUX registers */
    *pREG_GPIO0_CFG = SPORT0_A_SPT0A_D0_PORTP0_MUX | SPORT0_B_SPT0B_D0_PORTP0_MUX
     | SPORT0_B_SPT0B_CLK_PORTP0_MUX | SPORT0_B_SPT0B_FS_PORTP0_MUX | SPORT0_B_SPT0B_CNV_PORTP0_MUX;
    *pREG_GPIO1_CFG = SPORT0_A_SPT0A_CLK_PORTP1_MUX;
    *pREG_GPIO2_CFG = SPORT0_A_SPT0A_FS_PORTP2_MUX | SPORT0_A_SPT0A_CNV_PORTP2_MUX;
    *pREG_GPIO3_CFG = SPORT0_A_SPT0A_D0_PORTP3_MUX | SPORT0_A_SPT0A_CLK_PORTP3_MUX
     | SPORT0_A_SPT0A_FS_PORTP3_MUX | SPORT0_A_SPT0A_CNV_PORTP3_MUX;

    return 0;
}

