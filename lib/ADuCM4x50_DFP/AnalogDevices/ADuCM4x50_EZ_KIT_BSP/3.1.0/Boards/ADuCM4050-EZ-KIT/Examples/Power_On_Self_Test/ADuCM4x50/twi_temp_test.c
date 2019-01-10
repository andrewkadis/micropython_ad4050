
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
 * Description:     This examples tests the temperature sensor on the ADuCM4x50 EZKIT.
 */


/*=============  I N C L U D E S   =============*/

#include <stdio.h>  /* for DEBUG_MESSAGE */

/* Managed drivers and/or services include */
#include <drivers/i2c/adi_i2c.h>
#include <drivers/general/adi_drivers_general.h>
#include "system_ADuCM4050.h"
#include "drivers/pwr/adi_pwr.h"
#include "post_common.h"

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
ADI_ALIGNED_PRAGMA(4)
uint8_t txData[DATASIZE] ADI_ALIGNED_ATTRIBUTE(4);
ADI_ALIGNED_PRAGMA(4)
uint8_t rxData[DATASIZE] ADI_ALIGNED_ATTRIBUTE(4);


/*********************************************************************
*
*   Function:   TEST_TWI_TEMP
*
*********************************************************************/
int TEST_TWI_TEMP (void)
{
    /* device memory */
	ADI_ALIGNED_PRAGMA(4)
    uint8_t devMem[ADI_I2C_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

    /* device handle */
    ADI_I2C_HANDLE hDevice;

    /* addressing/command phase "prologue" array */
	ADI_ALIGNED_PRAGMA(4)
    uint8_t prologueData[5] ADI_ALIGNED_ATTRIBUTE(4);

    /* transaction structure */
    ADI_I2C_TRANSACTION xfr;

    /* result */
    ADI_I2C_RESULT result = ADI_I2C_FAILURE;

    /* HW Error result */
   
    uint32_t hwErrors;

    /* test system initialization */
   
 

    /* announce test */
    INFO("Running ADI ADT7420 I2C Temperature Sensor example...");

    /* test "loop" */
    while (1) {

     
        /* open driver */
        if (adi_i2c_Open(0, &devMem, ADI_I2C_MEMORY_SIZE, &hDevice))
            break;
    
        /* check reset flow */
        if (adi_i2c_Reset(hDevice))
            break;
    
        /* check set speed API */
        if (adi_i2c_SetBitRate(hDevice, 55000))  // bottom-end
            break;

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

        /* Note: this INFO introduces an approximate 32ms gap between the previous and subsequent read APIs. */
        sprintf(gPrintString,"Chip ID register: 0x%02x.", rxData[0]);
        INFO(gPrintString);

        /* verify expected ID */
        if (EXPECTED_ID != rxData[0]) {
            FAIL("ADI ADT7420 chip ID register does not match expected value.");
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
        sprintf(gPrintString,"Config register: 0x%02x.", rxData[0]);
        INFO(gPrintString);
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
        double ctemp, ftemp;

        temp = (rxData[0] << 8) | (rxData[1]);
        ctemp = (temp >> 3) / 16.0;
        ftemp = ctemp * 9.0 / 5.0 + 32.0;

		/* log temperature reading */
        sprintf(gPrintString,"Current temperature: %05.1f C.", ctemp);
        INFO(gPrintString);
        sprintf(gPrintString,"Current temperature: %05.1f F.", ftemp);
        INFO(gPrintString);

        /* range check */
        if ((MAX_TEMP < ftemp) || (MIN_TEMP > ftemp)) {
            FAIL("ADI ADT7420 temperature measure out of range.");
            break;
		}

        /* success */
        sprintf(gPrintString,"Success... result = 0x%04x.", result);
        INFO(gPrintString);
        PASS();
        adi_i2c_Close(hDevice);
        return SUCCESS;
    }

    /* failure */
    sprintf(gPrintString,"result = 0x%04x.", result);
    INFO(gPrintString);
    FAIL("Unsuccessful run of \"temperature_sensor\" example.");
    adi_i2c_Close(hDevice);
    return FAILURE;
}
