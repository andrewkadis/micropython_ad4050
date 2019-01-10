/*********************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file        dma_driven_crc_without_callback.c
 *
 * @brief       Example to demonstrate dma-driven CRC operations for computing
 *              the CRC of given block of data without a callback function.
 *
 * @details     This is the primary source file for the CRC example that shows
 *              how to use dma-driven CRC operations for computing the CRC of
 *              given block of data with no callback function registered in the
 *              interrupt handler attached to the DMA channel used to drive the
 *              CRC hardware engine.
 */

/*=============  I N C L U D E S   =============*/

#include <drivers/crc/adi_crc.h>
#include <drivers/pwr/adi_pwr.h>

#include "dma_driven_crc_without_callback.h"
#include "common.h"

/*=============  D A T A  =============*/

static ADI_CRC_HANDLE   hCrcDev;                        /*!< CRC Device Handle */
static uint8_t          CrcDevMem[ADI_CRC_MEMORY_SIZE]; /*!< Memory to handle CRC Device */
static const uint32_t         crc_data_buf[CRC_BUF_NUM_DATA]= /*!< Data to be sent to the CRC hardware engine */
{
#include "crc_data_buf.dat"
};

/*=============  L O C A L    F U N C T I O N S  =============*/

/*=============  C O D E  =============*/

int main (void)
{
    uint8_t * StartAddr = (uint8_t*) crc_data_buf;
    const bool bLsbFirst = true;                                                /* used to set CRC LSB/MSB first calculation */
    const uint32_t crc_polynomial = (bLsbFirst ? CRC32_POLYNOMIAL_LE : CRC32_POLYNOMIAL_BE);
    const uint32_t NumBytes = sizeof(crc_data_buf) / sizeof(uint8_t);           /* number of bytes in the data buffer to be processed by the CRC engine */
    const uint32_t NumBits = 0;                                                 /* no partial byte */

    common_Init();

    if (ADI_PWR_SUCCESS != adi_pwr_Init())
    {
        common_Fail("adi_pwr_Init failed");
    }
    else if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
        common_Fail("adi_pwr_SetClockDivider ADI_CLOCK_HCLK failed");
    }
    else if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        common_Fail("adi_pwr_SetClockDivider ADI_CLOCK_PCLK failed");
    }
    /* open a CRC device instance */
    else if (ADI_CRC_SUCCESS != adi_crc_Open (CRC_DEV_NUM, &CrcDevMem[0], ADI_CRC_MEMORY_SIZE, &hCrcDev))
    {
        common_Fail("adi_crc_Open failed");
    }
    else if (ADI_CRC_SUCCESS != adi_crc_SetLSBFirst(hCrcDev, bLsbFirst))
    {
        common_Fail("adi_crc_SetLSBFirst failed");
    }
    else if (ADI_CRC_SUCCESS != adi_crc_SetPolynomialVal (hCrcDev, crc_polynomial))
    {
        common_Fail("adi_crc_SetPolynomialVal failed");
    }
    /* set the Seed value */
    else if (ADI_CRC_SUCCESS != adi_crc_SetCrcSeedVal (hCrcDev, CRC32_SEED_VALUE))
    {
        common_Fail("adi_crc_SetCrcSeedVal failed");
    }else{
        /* kick off the dma-driven CRC operation */
        if (ADI_CRC_SUCCESS != adi_crc_Compute (hCrcDev, StartAddr, NumBytes, NumBits))
        {
            common_Fail("adi_crc_Compute failed");
        }else{
            const uint32_t expectedCRCValue = (bLsbFirst ? CRC32_EXPECTED_VAL_LE : CRC32_EXPECTED_VAL_BE );  /* expected CRC value depending on LSB setting */
            uint32_t computedCRCValue;
            bool inProgress = true;

            do
            {
                if (ADI_CRC_SUCCESS != adi_crc_IsCrcInProgress(hCrcDev, &inProgress))   /* Gets the current CRC peripheral status */
                {
                  common_Fail("adi_crc_IsCrcInProgress failed");                  
                }
            } while (true == inProgress);

            /* get the final result */
            if (ADI_CRC_SUCCESS != adi_crc_GetFinalCrcVal(hCrcDev, &computedCRCValue))
            {
                common_Fail("adi_crc_GetFinalCrcVal failed");
            }
            /* close the CRC device instance */
            else if (ADI_CRC_SUCCESS != adi_crc_Close (hCrcDev))
            {
                common_Fail("adi_crc_Close failed");
            }
            else if (expectedCRCValue != computedCRCValue)
            {
                common_Fail("unexpected CRC result");
            }else{
                common_Pass();
            }
        }
    }
    return 0;
}

/*****/
