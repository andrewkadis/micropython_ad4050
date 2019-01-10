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
 * Description:     This examples tests the SPI flash on the ADuCM4x50 EZKIT.
 */


/*=============  I N C L U D E S   =============*/

/* Flash exmaple include */
#include "flash_page_write.h"

/* Managed drivers and/or services include */
#include <drivers/flash/adi_flash.h>
#include "post_common.h"
#include <drivers/general/adi_drivers_general.h>

/*=============  D A T A  =============*/

/* Memory Required for flash driver */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Memory[ADI_FEE_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Buffer */
ADI_ALIGNED_PRAGMA(4)
uint8_t Buffer[BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

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
			FAIL("Internal Flash HW error detected.");
			break;

		case ADI_FEE_ERR_DMA_BUS_FAULT:
			FAIL("Flash DMA bus fault detected.");
			break;

		case ADI_FEE_ERR_DMA_INVALID_DESCR:
			FAIL("Flash DMA invalid descriptor detected.");
			break;

		case ADI_FEE_ERR_DMA_UNKNOWN_ERROR:
			FAIL("Unknown flash DMA error detected.");
			break;

		default:
			FAIL("Unknown event.\n");
			break;
    }
}

#endif

/*********************************************************************
*
*   Function:   TEST_SPI_FLASH
*
*********************************************************************/
int TEST_SPI_FLASH(void)
{
    /* Flash Handle */
    ADI_FEE_HANDLE hDevice;

    /* transaction struct */
    ADI_FEE_TRANSACTION transfer;

    uint32_t hwError = 0u;

    uint32_t nStartPage, nEndPage;

    /* Init the buffers */
    InitBuffer();

    /* Open Flash Controller Device */
    if (adi_fee_Open(FEE_DEV_NUM, Memory, sizeof(Memory), &hDevice) != ADI_FEE_SUCCESS) {
         FAIL("Failed to open flash driver.");
    }

    /* Get the start page */
    if (adi_fee_GetPageNumber(hDevice, PAGE_ADDR, &nStartPage) != ADI_FEE_SUCCESS) {
        FAIL("Failed to get start page number.");
         adi_fee_Close(hDevice);
    }

    /* Get the start page */
    if (adi_fee_GetPageNumber(hDevice, (PAGE_ADDR + BUFF_SIZE - 1), &nEndPage) != ADI_FEE_SUCCESS) {
        FAIL("Failed to get end page number.");
         adi_fee_Close(hDevice);
    }

    /* Clear the Pages */
    if (adi_fee_PageErase (hDevice, nStartPage, nEndPage, &hwError) != ADI_FEE_SUCCESS) {
        FAIL("Failed to erase flash page(s).");
         adi_fee_Close(hDevice);
    }

#ifdef FEE_ENABLE_CALLBACK
    if (adi_fee_RegisterCallback(hDevice, FlashCallback, NULL) != ADI_FEE_SUCCESS) {
        INFO("Failed to register callback handler.");
         adi_fee_Close(hDevice);
    }
#endif

    /* configure write buffer */
    transfer.pWriteAddr = (uint32_t*)PAGE_ADDR;
    transfer.pWriteData = (uint32_t*)Buffer;
    transfer.nSize      = sizeof(Buffer);
    transfer.bUseDma    = true;

    /* Submit a buffer for writing */
    if (adi_fee_SubmitBuffer (hDevice, &transfer) != ADI_FEE_SUCCESS) {
        FAIL("Failed to submit the buffer.");
         adi_fee_Close(hDevice);
    }

#ifndef FEE_ENABLE_CALLBACK
    /* Get the buffer back */
    if (adi_fee_GetBuffer(hDevice, &hwError) != ADI_FEE_SUCCESS) {
        FAIL("Failed to get the buffer.");
         adi_fee_Close(hDevice);
    }
#else
    while (numCallbacks == 0u) {;}
#endif

    /* Verify the transfer */
    if (VerifyBuffer() != ADI_FEE_SUCCESS) {
        FAIL("Unmatched readback data.");
         adi_fee_Close(hDevice);
    }

   /* Close the flash controller */
    if (adi_fee_Close(hDevice) != ADI_FEE_SUCCESS) {
        FAIL("Failed to close the flash driver.");
    }

    PASS();
    return (SUCCESS);
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
