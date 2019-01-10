/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      rng_example.c
 * @brief     Example to demonstrate RNG driver to generate random numbers
 *
 * @details
 *            This is the primary source file for the RNG example to generate
 *            random numbers.
 *
 */

/*=============  I N C L U D E S   =============*/

/* RNG example include */
#include "rng_example.h"
/* Managed drivers and/or services include */
#include <drivers/rng/adi_rng.h>
#include <drivers/pwr/adi_pwr.h>
#include <common.h>
/*=============  D A T A  =============*/

/* RNG Device Handle */
static ADI_RNG_HANDLE     hDevice;
/* Memory to handle CRC Device */
static uint8_t            RngDevMem[ADI_RNG_MEMORY_SIZE];
/* Data buffers for Random numbers */
static uint32_t           RNBuff[NUM_RANDOM_NUMS] = {0};

static volatile uint32_t  nNumRNGen = 0u;

static volatile bool failure_detected = false;

/* IF (Callback mode enabled) */
#if (RNG_ENABLE_CALLBACK == 1u)
static volatile bool stuck_status_detected = false;
#endif

/*=============  L O C A L    F U N C T I O N S  =============*/

/*=============  C O D E  =============*/

/* IF (Callback mode enabled) */
#if (RNG_ENABLE_CALLBACK == 1u)

/*
 *  Callback from RNG Driver
 *
 * Parameters
 *  - [in]  pCBParam    Callback parameter supplied by application
 *  - [in]  Event       Callback event
 *  - [in]  pArg        Callback argument
 *
 * Returns  None
 *
 */
static void rngCallback(void *pCBParam, uint32_t Event, void *pArg)
{
    ADI_RNG_RESULT eResult;
    if (Event == ADI_RNG_EVENT_READY)
    {
      uint32_t nRandomNum;
      eResult = adi_rng_GetRngData(hDevice, &nRandomNum);
      if (ADI_RNG_SUCCESS != eResult) {
        /* A failure has been detected. Since we cannot print this from the ISR
         * we set a variable to indicate the problem.
         */
        failure_detected =true;
        return;
      }
      /* Make sure that we do not overflow the array allocated */
      if (nNumRNGen < NUM_RANDOM_NUMS) {
        RNBuff[nNumRNGen++] = nRandomNum;
      }
    }
    else if (Event == ADI_RNG_EVENT_STUCK)
    {
        stuck_status_detected = true;
    }
    else
    {
        /* Unknown event */
        failure_detected =true;
    }
}

#endif /* RNG_ENABLE_CALLBACK */



/*********************************************************************
*
*   Function:   main
*
*********************************************************************/
int main (void)
{
    /* RNG Return code */
    ADI_RNG_RESULT	eResult = ADI_RNG_SUCCESS;

    /* test system initialization */
    common_Init();

    if(adi_pwr_Init()!= ADI_PWR_SUCCESS)
    {
        DEBUG_MESSAGE("\n Failed to intialize the power service \n");
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service\n");
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service\n");
    }

    eResult = adi_rng_Open(RNG_DEV_NUM,RngDevMem,sizeof(RngDevMem),&hDevice);
    DEBUG_RESULT("Failed to open RNG device",eResult,ADI_RNG_SUCCESS);

    /* This API is only required if the parameters need to be changed at runtime
     * By default the API #adi_rng_Open sets them to the values defined in the
     * RNG configuration file
     */
    eResult = adi_rng_SetSampleLen(hDevice,RNG_DEV_LEN_PRESCALER,RNG_DEV_LEN_RELOAD);
    DEBUG_RESULT("Failed to set sample length",eResult,ADI_RNG_SUCCESS);

#if (RNG_ENABLE_CALLBACK == 1u)
    eResult = adi_rng_RegisterCallback(hDevice, rngCallback,hDevice);
    DEBUG_RESULT("Failed to register callback",eResult,ADI_RNG_SUCCESS);
#endif

    eResult = adi_rng_Enable(hDevice, true);
    DEBUG_RESULT("Failed to enable device",eResult,ADI_RNG_SUCCESS);
    while (nNumRNGen < NUM_RANDOM_NUMS)
    {
#if (RNG_ENABLE_CALLBACK != 1u)
        bool bRNGRdy;
        eResult = adi_rng_GetRdyStatus(hDevice, &bRNGRdy);
        DEBUG_RESULT("Failed to get ready status",eResult,ADI_RNG_SUCCESS);
        if (bRNGRdy) {
            uint32_t nRandomNum;
            eResult = adi_rng_GetRngData(hDevice, &nRandomNum);
            DEBUG_RESULT("Failed to enable device",eResult,ADI_RNG_SUCCESS);

            RNBuff[nNumRNGen++] = nRandomNum;
        }
#endif
    }

    /* Disable the RNG driver */
    eResult = adi_rng_Enable(hDevice, false);
    DEBUG_RESULT("Failed to disable device",eResult,ADI_RNG_SUCCESS);

    eResult = adi_rng_Close(hDevice);
    DEBUG_RESULT("Failed to close the device",eResult,ADI_RNG_SUCCESS);

    /* Print the results. Since the numbers are random we cannot compare
     * them with anything
     */
    for (int x=0; x < NUM_RANDOM_NUMS; x++) {
      DEBUG_MESSAGE("Random number %d : 0x%08X",x,(uint16_t)RNBuff[x]);
    }

    /* Most errors exit the example directly but if there was a problem in
     * the callback we only catch it here
     */
    if ( failure_detected == true)
    {
      DEBUG_MESSAGE("Error detected. Example failed");
    }
    else {
      DEBUG_MESSAGE("All done!. Random number generator example completed successfully");
    }

}

/*****/
