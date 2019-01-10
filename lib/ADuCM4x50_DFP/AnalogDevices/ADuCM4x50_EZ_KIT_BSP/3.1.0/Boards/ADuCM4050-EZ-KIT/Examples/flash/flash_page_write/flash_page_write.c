/*********************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      flash_page_write.c
 * @brief     Example to demonstrate flash driver
 * @date:     $Date: 2015-11-08 13:00:01 -0500 (Sun, 08 Nov 2015) $
 *
 * @details
 *            This is the primary source file for the flash example demonstrating
 *            writing and reading from the flash.
 *
 */

/*=============  I N C L U D E S   =============*/

/* Managed drivers and/or services include */
#include <drivers/flash/adi_flash.h>
#include <drivers/general/adi_drivers_general.h>
#include <common.h>
/* Flash example include */
#include "flash_page_write.h"

/*=============  D A T A  =============*/


/* Memory Required for flash driver */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Memory[ADI_FEE_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);



/* Buffer */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Buffer[BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* define "FEE_ENABLE_CALLBACK" for callback mode */
#define FEE_ENABLE_CALLBACK

#ifdef FEE_ENABLE_CALLBACK
/* Callback flag */
static volatile int numCallbacks = 0;
#endif

/*=============  L O C A L    F U N C T I O N S  =============*/

void InitBuffer(void);
ADI_FEE_RESULT VerifyBuffer(void);

/*=============  C O D E  =============*/

/* IF (Callback mode enabled) */
#ifdef FEE_ENABLE_CALLBACK

/* Callback from flash controller */
static void FlashCallback(void *pCBParam, uint32_t Event, void *pArg)
{
    switch (Event) {
		case ADI_FEE_CALLBACK_EVENT_BUFFER_PROCESSED:
			numCallbacks++;
			break;

		case ADI_FEE_CALLBACK_EVENT_DEVICE_ERROR:
			DEBUG_RESULT("Internal Flash HW error detected.",(unsigned int) pArg, 0);
			break;

		case ADI_FEE_ERR_DMA_BUS_FAULT:
			DEBUG_RESULT("Flash DMA bus fault detected.",(unsigned int) Event, 0);
			break;

		case ADI_FEE_ERR_DMA_INVALID_DESCR:
			DEBUG_RESULT("Flash DMA invalid descriptor detected.",(unsigned int) Event, 0);
			break;

		case ADI_FEE_ERR_DMA_UNKNOWN_ERROR:
			DEBUG_RESULT("Unknown flash DMA error detected.",(unsigned int) Event, 0);
			break;

		default:
			DEBUG_MESSAGE("Unknown event.\n");
			break;
    }
}

#endif

/*********************************************************************
*
*   Function:   main
*
*********************************************************************/
int main (void)
{

	/* Flash Handle */
	ADI_FEE_HANDLE hDevice;

	/* transaction struct */
	ADI_FEE_TRANSACTION transfer;

    uint32_t hwError = 0u;

    uint32_t nStartPage, nEndPage;

    /* Flash controller  Return code */
    ADI_FEE_RESULT eResult = ADI_FEE_SUCCESS;

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

    /* Init the buffers */
    InitBuffer();

    /* Open Flash Controller Device */
    eResult = adi_fee_Open(FEE_DEV_NUM, Memory, sizeof(Memory), &hDevice);
    DEBUG_RESULT("Failed to open flash driver.", eResult, ADI_FEE_SUCCESS);

    /* Get the start page */
    eResult = adi_fee_GetPageNumber(hDevice, PAGE_ADDR, &nStartPage);
    DEBUG_RESULT("Failed to get start page number.", eResult, ADI_FEE_SUCCESS);

    /* Get the start page */
    eResult = adi_fee_GetPageNumber(hDevice, (PAGE_ADDR + BUFF_SIZE - 1), &nEndPage);
    DEBUG_RESULT("Failed to get end page number.", eResult, ADI_FEE_SUCCESS);

    /* Clear the Pages */
    eResult = adi_fee_PageErase (hDevice, nStartPage, nEndPage, &hwError);
    DEBUG_RESULT("Failed to erase flash page(s).", eResult, ADI_FEE_SUCCESS);

#ifdef FEE_ENABLE_CALLBACK
    eResult = adi_fee_RegisterCallback(hDevice, FlashCallback, NULL);
    DEBUG_RESULT("Failed to register callback handler.", eResult,ADI_FEE_SUCCESS);
#endif

    /* configure write buffer */
    transfer.pWriteAddr = (uint32_t*)PAGE_ADDR;
    transfer.pWriteData = (uint32_t*)Buffer;
    transfer.nSize      = sizeof(Buffer);
    transfer.bUseDma    = true;

    /* Submit a buffer for writing */
    eResult =  adi_fee_SubmitBuffer (hDevice, &transfer);
    DEBUG_RESULT("Failed to submit the buffer.", eResult, ADI_FEE_SUCCESS);

#ifndef FEE_ENABLE_CALLBACK
    /* Get the buffer back */
    eResult = adi_fee_GetBuffer(hDevice, &hwError);
    DEBUG_RESULT("Failed to get the buffer.", eResult, ADI_FEE_SUCCESS);
#else
    while (numCallbacks == 0u) {;}
#endif

    /* Verify the transfer */
    eResult = VerifyBuffer();
    DEBUG_RESULT("Unmatched readback data.", eResult, ADI_FEE_SUCCESS);

   /* Close the flash controller */
    eResult = adi_fee_Close(hDevice);
    DEBUG_RESULT("Failed to close the flash driver.", eResult,ADI_FEE_SUCCESS);

    common_Pass();
}

void InitBuffer(void)
{
    for (int x = 0; x < BUFF_SIZE; x++) {
      Buffer[x] = rand()%256;
    }
}

ADI_FEE_RESULT VerifyBuffer (void)
{
	uint8_t* pDataInFlash = (uint8_t*)PAGE_ADDR;
	for (int x = 0; x < BUFF_SIZE; x++) {
		if (Buffer[x] != *pDataInFlash++){
			    return ADI_FEE_ERR_BUFFER_ERR;
			 }
    }
    return ADI_FEE_SUCCESS;
}

/*****/
