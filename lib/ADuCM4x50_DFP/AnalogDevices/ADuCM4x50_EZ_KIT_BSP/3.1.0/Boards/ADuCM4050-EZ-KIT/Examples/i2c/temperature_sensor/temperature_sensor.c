/*********************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      manual_test.c
 * @brief     Manual test to demonstrate I2C Driver
 *
 * @details
 *            This is the primary source file for the I2C example demonstrating
 *            a master to slave transfer.
 *
 */

/*=============  I N C L U D E S   =============*/

#include <stdio.h>  /* for DEBUG_MESSAGE */

/* Managed drivers and/or services include */
#include <drivers/i2c/adi_i2c.h>

#include "drivers/pwr/adi_pwr.h"
#include "common.h"

#define EXPECTED_ID 0xcb
#define MAX_TEMP 100
#define MIN_TEMP 50

#ifndef SUCCESS
/*! Local I2C define for result SUCCESS (if not already). */
#define SUCCESS 0
#endif
#ifndef FAILURE
/*! Local I2C define for result FAILURE (if not already). */
#define FAILURE 1
#endif

extern int32_t adi_initpinmux(void);

/* Set max data size to 8 bytes */
#define DATASIZE 8

 /* data array statics */
uint8_t txData[DATASIZE];
uint8_t rxData[DATASIZE];


/*********************************************************************
*
*   Function:   main
*
*********************************************************************/
int main (void)
{
    /* device memory */
    uint8_t devMem[ADI_I2C_MEMORY_SIZE];

    /* device handle */
    ADI_I2C_HANDLE hDevice;

    /* addressing/command phase "prologue" array */
    uint8_t prologueData[5];

    /* transaction structure */
    ADI_I2C_TRANSACTION xfr;

    /* result */
    ADI_I2C_RESULT result = ADI_I2C_SUCCESS;

    /* HW Error result */
    uint32_t hwErrors;

    /* test system initialization */
    common_Init();

    /* power init */
    adi_pwr_Init();

    /* pinmux init */
    adi_initpinmux();

    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
        DEBUG_MESSAGE("Failed to set clock divider for HCLK.");
        return FAILURE;
    }

    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        DEBUG_MESSAGE("Failed to set clock divider for PCLK.");
        return FAILURE;
    }

    /* announce test */
    DEBUG_MESSAGE("Running ADI ADT7420 I2C Temperature Sensor example...");

    /* test "loop" */
    while (1) {

        /* open driver */
        if (adi_i2c_Open(0, &devMem, ADI_I2C_MEMORY_SIZE, &hDevice))
            break;

        /* check reset flow */
        if (adi_i2c_Reset(hDevice))
            break;

#if 1
        /* check set speed API */
        if (adi_i2c_SetBitRate(hDevice, 400000))  // top-end
            break;
#else
        /* check set speed API */
        if (adi_i2c_SetBitRate(hDevice, 55000))  // bottom-end
            break;
#endif

        /* test ADT7420 I2C temperature sensor (U6) on ADuCM4x50 EZ-Kit */

        /* set slave address for ADI ADT7420 */
        if (adi_i2c_SetSlaveAddress(hDevice, 0x48))
            break;

        /* do a simple one-byte read of chip ID */
        prologueData[0]     = 0x0b;  /* address of ID register */
        xfr.pPrologue       = &prologueData[0];
        xfr.nPrologueSize   = 1;
        xfr.pData           = rxData;
        xfr.nDataSize       = 1;
        xfr.bReadNotWrite   = true;
        xfr.bRepeatStart    = true;

        /* clear chip ID readback value in receive buffer */
        rxData[0] = 0;

        /* blocking read */
        result = adi_i2c_ReadWrite(hDevice, &xfr, &hwErrors);
        if (result) {
            break;
        }

        /* Note: this DEBUG_MESSAGE introduces an approximate 32ms gap between the previous and subsequent read APIs. */
        DEBUG_MESSAGE("Chip ID register: 0x%02x.", rxData[0]);

        /* verify expected ID */
        if (EXPECTED_ID != rxData[0]) {
            DEBUG_MESSAGE("ADI ADT7420 chip ID register does not match expected value.");
            break;
        }

        /* report config register */
        prologueData[0]     = 0x03;  /* address of config register */
        xfr.pPrologue       = &prologueData[0];
        xfr.nPrologueSize   = 1;
        xfr.pData           = rxData;
        xfr.nDataSize       = 1;
        xfr.bReadNotWrite   = true;
        xfr.bRepeatStart    = true;

        /* blocking read */
        result = adi_i2c_ReadWrite(hDevice, &xfr, &hwErrors);
        if (result) {
            break;
        }

		/* log config register value */
        DEBUG_MESSAGE("Config register: 0x%02x.", rxData[0]);

        /* read temperature registers */
        prologueData[0]     = 0;  /* address of 1st temperature register */
        xfr.pPrologue       = &prologueData[0];
        xfr.nPrologueSize   = 1;
        xfr.pData           = rxData;
        xfr.nDataSize       = 2;
        xfr.bReadNotWrite   = true;
        xfr.bRepeatStart    = true;

        /* blocking read */
        result = adi_i2c_ReadWrite(hDevice, &xfr, &hwErrors);
        if (result) {
            break;
        }

        /* translate temperature reading to human-readable form */
        uint16_t temp;
        float ctemp, ftemp;

        temp = (rxData[0] << 8) | (rxData[1]);
        ctemp = (temp >> 3) / 16.0;
        ftemp = ctemp * (9.0 / 5.0) + 32.0;

		/* log temperature reading */
        DEBUG_MESSAGE("Current temperature: %05.1f C.", ctemp);
        DEBUG_MESSAGE("Current temperature: %05.1f F.", ftemp);

        /* range check */
        if ((MAX_TEMP < ftemp) || (MIN_TEMP > ftemp)) {
            DEBUG_MESSAGE("ADI ADT7420 temperature measure out of range.");
            break;
		}

        /* success */
        DEBUG_MESSAGE("Success... result = 0x%04x.", result);
        common_Pass();
        return SUCCESS;
    }

    /* failure */
    DEBUG_MESSAGE("result = 0x%04x.", result);
    common_Fail("Unsuccessful run of \"temperature_sensor\" example.");
    return FAILURE;
}
