/*********************************************************************************

Copyright(c) 2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/

#include <drivers/pwr/adi_pwr.h>
#include <drivers/wdt/adi_wdt.h>
#include <drivers/flash/adi_flash.h>
#include <drivers/general/adi_drivers_general.h>
#include "common.h"

/* Memory Required for flash driver */
ADI_ALIGNED_PRAGMA(4)
static uint8_t FlashDriverMemory[ADI_FEE_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

// Bring PLL clock out to P2.11 for debugging purposes
#define CLKOUT_DEBUG

// Pin Mux defines
#define SYS_CLK_IN_PORTP1_MUX  ((uint32_t) ((uint32_t) 2<<20));
#define SYS_CLK_OUT_PORTP2_MUX  ((uint32_t) ((uint32_t) 2<<22))

/* FEE Device number */
#define FEE_DEV_NUM              (0u)


int main()
{  

    /* test system initialization */
    common_Init();

    
    /* power init */
    if(adi_pwr_Init()!= ADI_PWR_SUCCESS) {
        DEBUG_MESSAGE("Failed to intialize the power service.\n");
    }
    
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1)) {
        DEBUG_MESSAGE("Failed to set HCLK.\n");
    }

    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1)) {
        DEBUG_MESSAGE("Failed to set PCLK.\n");
    }

    /* Use HFOSC as input for the PLL */
    if( ADI_PWR_SUCCESS != adi_pwr_SetPLLClockMux(ADI_CLOCK_MUX_SPLL_HFOSC)) {
        DEBUG_MESSAGE("Failed to set PLL Clock Mux.\n");
    }
    
    /* Change the loading capability of the HPBUCK. Necessary if system clock is greater than 26 MHz */
    if( ADI_PWR_SUCCESS != adi_pwr_SetHPBuckLoadMode(ADI_PWR_HPBUCK_LD_MODE_HIGH)) {
         DEBUG_MESSAGE("Failed to set HP Buck Load Mode.\n");     
    }
    
    /* 
     * Configure PLL frequency to 52 MHz 
     *    MUL2 = 1
     *    N    = 26
     *    DIV2 = 1
     *    M    = 13
     *
     * Freq = HFOSC * (MUL2*N) / (DIV2*M) = 26 * (1 * 26) / (1*13) = 52
     *
     */
    if( ADI_PWR_SUCCESS != adi_pwr_SetPll(13, 26, false, false)) {
        DEBUG_MESSAGE("Failed to set set the PLL.\n");     
    }

    /* Flash Handle */
    ADI_FEE_HANDLE hDevice;

    /* Open Flash Controller Device */
    if( ADI_FEE_SUCCESS != adi_fee_Open(FEE_DEV_NUM, FlashDriverMemory, sizeof(FlashDriverMemory), &hDevice)) {
        DEBUG_MESSAGE("Failed to open flash driver.");
    }
    
    /* We need at least one wait state else the flash will not function correctly when running at 52 MHz */
    if( ADI_FEE_SUCCESS !=  adi_fee_ConfigureWaitStates(hDevice, 1)) {
        DEBUG_MESSAGE("Failed to configure the flash wait states.\n");          
    }
    
    /* Enable the PLL */
    if( ADI_PWR_SUCCESS !=  adi_pwr_EnableClockSource(ADI_CLOCK_SOURCE_SPLL, true)) {
        DEBUG_MESSAGE("Failed to set enable the clock source.\n");          
    }
    
    /* Set PLL as Root clock */
    if( ADI_PWR_SUCCESS !=  adi_pwr_SetRootClockMux(ADI_CLOCK_MUX_ROOT_SPLL)) {
        DEBUG_MESSAGE("Failed to set the PLL as the root clock.\n");          
    }
    
    /* Now operating at 52 MHz */
 
    common_Pass();
    
    return 0;
}
