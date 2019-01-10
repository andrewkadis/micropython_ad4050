/*******************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*******************************************************************************/
/**
 * @file:       sport_loopback_dma.c
 * 
 * @brief       This file contains a loop back example which demonstrates how
 *              to use the SPORT device driver APIs.
 */

#include <common.h>
#include <drivers/general/adi_drivers_general.h>
#include <drivers/sport/adi_sport.h>
#include <drivers/pwr/adi_pwr.h>

#include "sport_loopback_dma.h"

extern int32_t adi_initpinmux(void);

ADI_ALIGNED_PRAGMA(4)
static ADI_SPORT_HANDLE hDevRx ADI_ALIGNED_ATTRIBUTE(4);                                /* Handle for Rx channel */

ADI_ALIGNED_PRAGMA(4)
static ADI_SPORT_HANDLE hDevTx ADI_ALIGNED_ATTRIBUTE(4);                                /* Handle for Tx channel */

ADI_ALIGNED_PRAGMA(4)
static unsigned char sport_driverTx[ADI_SPORT_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);    /* Memory required by the device for TX operation */

ADI_ALIGNED_PRAGMA(4)
static unsigned char sport_driverRx[ADI_SPORT_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);    /* Memory required by the device for RX operation */

ADI_ALIGNED_PRAGMA(4)
static uint8_t nBufferTx[BUFFER_SIZE] ADI_ALIGNED_ATTRIBUTE(4) =
{
#include "sport_data_buf.dat"
};

ADI_ALIGNED_PRAGMA(4)
static uint8_t nBufferRx[BUFFER_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Prototypes for function used in this example */
static uint32_t checkTransmittedData(const uint8_t refBuff[], const uint8_t chkBuff[], const size_t numData);

static void checkGetBufferResult(const ADI_SPORT_RESULT eSportResult, const uint32_t hwEvt);

/**
 * @brief       main function (application entry point)
 */
int main(void)
{
    ADI_PWR_RESULT ePwrResult = ADI_PWR_SUCCESS;
    uint32_t error_count = 0u;
    ADI_SPORT_RESULT eSportResult = ADI_SPORT_SUCCESS;  /* Variable for storing the return code from UART device */
    bool bBufferComplete = false;                       /* Bool variable for peek function */
    void *pProcessedBuffer = NULL;                      /* Variable to get the buffer address */
    bool useDma = true;                                 /* SPORT communication in DMA mode, not interrupt */
    uint32_t hwEvt = ADI_SPORT_HW_NO_ERR;               /* used to read SPORT HW error status*/

    adi_initpinmux();
    common_Init();

    ePwrResult = adi_pwr_Init();
    DEBUG_RESULT("Failed to initialize power service",ePwrResult,ADI_PWR_SUCCESS);

    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1);
    DEBUG_RESULT("Failed to assign HCLK",ePwrResult,ADI_PWR_SUCCESS);

    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1);
    DEBUG_RESULT("Failed to assign PCLK",ePwrResult,ADI_PWR_SUCCESS);

    ePwrResult = adi_pwr_EnableClock(ADI_CLOCK_GATE_PCLK, true);
    DEBUG_RESULT("Failed to enable power clock",ePwrResult,ADI_PWR_SUCCESS);

    eSportResult = adi_sport_Open(SPORT_DEVICE_ID,
                                  ADI_HALF_SPORT_A,
                                  ADI_SPORT_DIR_RX,
                                  sport_driverRx,
                                  (uint32_t)(ADI_SPORT_MEMORY_SIZE),
                                  &hDevRx);
    DEBUG_RESULT("Failed to open SPORT0 A in Rx mode",eSportResult,ADI_SPORT_SUCCESS);

    eSportResult = adi_sport_Open(SPORT_DEVICE_ID,
                                  ADI_HALF_SPORT_B,
                                  ADI_SPORT_DIR_TX,
                                  sport_driverTx,
                                  (uint32_t)(ADI_SPORT_MEMORY_SIZE),
                                  &hDevTx);
    DEBUG_RESULT("Failed to open SPORT0 B in Tx mode",eSportResult,ADI_SPORT_SUCCESS);

    /* SPORT-A and SPORT-B are configured through the configuration parameters
     * in adi_sport_config.h ; there's no need to call adi_sport_ConfigData,
     * adi_sport_ConfigClock and adi_sport_ConfigFrameSync for SPORT drivers
     * in this example. */

    memset(nBufferRx,0,sizeof(nBufferRx));      /* initialize Rx buffer with 0s */
    eSportResult = adi_sport_SubmitBuffer(hDevRx,&nBufferRx[0],BUFFER_SIZE,useDma);
    DEBUG_RESULT("Failed to submit buffer for Rx channel",eSportResult,ADI_SPORT_SUCCESS);

    eSportResult = adi_sport_SubmitBuffer(hDevTx,&nBufferTx[0],BUFFER_SIZE,useDma);
    DEBUG_RESULT("Failed to submit buffer for Tx channel",eSportResult,ADI_SPORT_SUCCESS);

    /* wait for Tx buffer availability */
    do
    {
        eSportResult = adi_sport_IsBufferAvailable(hDevTx,&bBufferComplete);
        DEBUG_RESULT("Failed to check transmit buffer availability",eSportResult,ADI_SPORT_SUCCESS);
    }
    while (true != bBufferComplete);
		/* Get the address of the buffer processed by the transmit channel.
    * Upon successful return "pProcessedBuffer" should contain the
    * address of "nBufferTx" and content of nSize should be size of
    * "nBufferTx"
    */
    eSportResult = adi_sport_GetBuffer(hDevTx,&pProcessedBuffer,&hwEvt);
    checkGetBufferResult(eSportResult,hwEvt);
    DEBUG_RESULT("Processed buffer is not the buffer submitted to transmit channel",(unsigned int)pProcessedBuffer,(unsigned int)&nBufferTx[0]);

    /* wait for Rx buffer availability */
    do
    {
        eSportResult = adi_sport_IsBufferAvailable(hDevRx,&bBufferComplete);
        DEBUG_RESULT("Failed to check receive buffer availability",eSportResult,ADI_SPORT_SUCCESS);
    }
    while (true != bBufferComplete);

    /* Get the address of the buffer processed by the receive channel.
    * Upon successful return "pProcessedBuffer" should contain the
    * address of "nBufferRx" and content of nSize should be size of
    * "nBufferRx"
    */
    eSportResult = adi_sport_GetBuffer(hDevRx,&pProcessedBuffer,&hwEvt);
    checkGetBufferResult(eSportResult,hwEvt);
    DEBUG_RESULT("Processed buffer is not the buffer submitted to receive channel",(unsigned int)pProcessedBuffer,(unsigned int)&nBufferRx[0]);

    eSportResult = adi_sport_Close(hDevTx);
    DEBUG_RESULT("Failed to close SPORT0 A",eSportResult,ADI_SPORT_SUCCESS);

    eSportResult = adi_sport_Close(hDevRx);
    DEBUG_RESULT("Failed to close SPORT0 B",eSportResult,ADI_SPORT_SUCCESS);

    error_count = checkTransmittedData(&nBufferTx[0],&nBufferRx[0],BUFFER_SIZE);
    if (0u == error_count)
    {
        common_Pass();
    } else {
        common_Fail("Failed to run SPORT loopback DMA example");
    }
    return 0;
}

static uint32_t checkTransmittedData(const uint8_t refBuff[], const uint8_t chkBuff[], const size_t numData)
{
    uint32_t i;
    uint32_t error_count = 0u;

    for (i = 0u; i < numData; i++)
    {
        if (refBuff[i] != chkBuff[i])
        {
            error_count++;
        }
    }
    return error_count;
}

static void checkGetBufferResult(const ADI_SPORT_RESULT eSportResult, const uint32_t hwEvt)
{
    switch (eSportResult)
    {
    case ADI_SPORT_SUCCESS:
        break;

    case ADI_SPORT_HW_ERROR:
        if (ADI_SPORT_HW_NO_ERR != hwEvt)
        {
            char msg[64];

            sprintf(msg,"Sport HW event detected: 0x%X", (unsigned int)hwEvt);
            common_Perf(msg);
        }
        break;

    default:
        DEBUG_RESULT("Failed to get the processed buffer",eSportResult,ADI_SPORT_SUCCESS);
    }
}
