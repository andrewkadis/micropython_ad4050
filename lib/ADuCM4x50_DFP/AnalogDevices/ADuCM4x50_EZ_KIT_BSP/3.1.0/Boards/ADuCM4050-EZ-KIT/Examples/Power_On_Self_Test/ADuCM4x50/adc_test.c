/*
 *  (C) Copyright 2016 - Analog Devices, Inc. All Rights Reserved.
 *
 * This software is proprietary and confidential.  By using this software
 * you agree to the terms of the associated Analog Devices License Agreement.
 *
 * Project Name:  	Power_On_Self_Test
 *
 * Hardware:		    ADuCM4x50 EZKIT
 *
 * Description:	    This examples tests the ADC on the ADuCM4x50 EZKIT.
 */


/*==========  I N C L U D E  ==========*/

#include <drivers/adc/adi_adc.h>
#include <drivers/general/adi_drivers_general.h>
#include "post_common.h"
/*=============  D A T A  =============*/

/* ADC Handle */
ADI_ALIGNED_PRAGMA(4)
ADI_ADC_HANDLE hDevice ADI_ALIGNED_ATTRIBUTE(4);

#define ADC_DEV_NUM                (0u)

/* Memory Required for adc driver */
ADI_ALIGNED_PRAGMA(4)
static uint8_t DeviceMemory[ADI_ADC_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

static void usleep(uint32_t usec);

extern volatile bool g_button_1_pushed;


int TEST_ADC (void)
{
    uint32_t nBatteryVoltage;
    uint32_t intvalue;
    uint32_t fractvalue;
    bool bCalibrationDone = false;

    HEAD("ADC Test");

    INFO("Please connect pins 1-2 all on JP17 ");
    INFO("Press PB2 to continue");
    
    g_button_1_pushed = false;
    while (g_button_1_pushed == false) { ; }
    g_button_1_pushed = false;
    
    
    do
    {
        
       // open driver and power on
         if (adi_adc_Open(ADC_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice) != ADI_ADC_SUCCESS) {
            FAIL("Failed to open adc driver");
            return FAILURE;
         }
         if (adi_adc_PowerUp (hDevice, true) != ADI_ADC_SUCCESS) {
            FAIL("Failed to power up adc ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }
       // set up adc reference
         if (adi_adc_SetVrefSource (hDevice, ADI_ADC_VREF_SRC_EXT) != ADI_ADC_SUCCESS) {
            FAIL("Failed to set up reference for adc ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }
       // set up sub system
         if (adi_adc_EnableADCSubSystem (hDevice, true) != ADI_ADC_SUCCESS) {
            FAIL("Failed to set up adc subsystem ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }

       // wait 5 ms just to be sure (2.5 ms is minimum)
         usleep(5000);

       // Start calibration
         if (adi_adc_StartCalibration (hDevice) != ADI_ADC_SUCCESS) {
            FAIL("Failed to set up adc subsystem ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }

         
        bCalibrationDone = false;
       // wait for calibration done
        while (!bCalibrationDone)
        {
           if (adi_adc_IsCalibrationDone (hDevice, &bCalibrationDone) != ADI_ADC_SUCCESS) {
               FAIL("Failed to get calibration status");
               adi_adc_Close(hDevice);
               return FAILURE;
            }
        }

       //now get the result
         if (adi_adc_GetBatteryVoltage (hDevice,136533,&nBatteryVoltage) != ADI_ADC_SUCCESS) {
            FAIL("Failed to get battery voltage ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }

        intvalue = nBatteryVoltage >>16; // integer portion
        fractvalue = (nBatteryVoltage & 0xffff) /653;  // qd conversion to a 2 digit fract

        sprintf(gPrintString, "Measured Battery Voltage using ADC: %d.%02d volts", (uint16_t)intvalue,(uint16_t)fractvalue);
        INFO(gPrintString);
        
        if (!(
                 (0x20000 < nBatteryVoltage          /* 2.0 in 16.16 format */ )
              && (         nBatteryVoltage < 0x30000 /* 3.0 in 16.16 format */ )
              ))
        {
            FAIL("Measured Battery voltage is not in the required range");
            adi_adc_Close(hDevice);
            return FAILURE;
        }        
        

        /* success */
       adi_adc_Close(hDevice);

    } while (0);

    INFO("Please connect pins 2-3 all on JP17 ");
    INFO("Press PB2 to continue");
    
    g_button_1_pushed = false;
    while (g_button_1_pushed == false) { ; }
    g_button_1_pushed = false;
    
    

    
    do
    {
        
        
       // open driver and power on
         if (adi_adc_Open(ADC_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice) != ADI_ADC_SUCCESS) {
            FAIL("Failed to open adc driver");
            return FAILURE;
         }
         if (adi_adc_PowerUp (hDevice, true) != ADI_ADC_SUCCESS) {
            FAIL("Failed to power up adc ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }
       // set up adc reference
         if (adi_adc_SetVrefSource (hDevice, ADI_ADC_VREF_SRC_EXT) != ADI_ADC_SUCCESS) {
            FAIL("Failed to set up reference for adc ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }
       // set up sub system
         if (adi_adc_EnableADCSubSystem (hDevice, true) != ADI_ADC_SUCCESS) {
            FAIL("Failed to set up adc subsystem ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }

       // wait 5 ms just to be sure (2.5 ms is minimum)
         usleep(5000);

       // Start calibration
         if (adi_adc_StartCalibration (hDevice) != ADI_ADC_SUCCESS) {
            FAIL("Failed to set up adc subsystem ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }

      bCalibrationDone = false;

         
       // wait for calibration done
        while (!bCalibrationDone)
        {
           if (adi_adc_IsCalibrationDone (hDevice, &bCalibrationDone) != ADI_ADC_SUCCESS) {
               FAIL("Failed to get calibration status");
               adi_adc_Close(hDevice);
               return FAILURE;
            }
        }

       //now get the result
         if (adi_adc_GetBatteryVoltage (hDevice,34133,&nBatteryVoltage) != ADI_ADC_SUCCESS) {
            FAIL("Failed to get battery voltage ");
            adi_adc_Close(hDevice);
            return FAILURE;
         }
        
        intvalue = nBatteryVoltage >>16; // integer portion
        fractvalue = (nBatteryVoltage & 0xffff) /653;  // qd conversion to a 2 digit fract

        sprintf(gPrintString, "Measured Battery Voltage using ADC: %d.%02d volts", (uint16_t)intvalue,(uint16_t)fractvalue);
        INFO(gPrintString);
        
        if (!(
                 (0x10000 < nBatteryVoltage          /* 1.0 in 16.16 format */ )
              && (         nBatteryVoltage < 0x18000 /* 1.5 in 16.16 format */ )
              ))
        {
            FAIL("Measured Battery voltage is not in the required range");
            adi_adc_Close(hDevice);
            return FAILURE;
        }        
        
        

        /* success */
        adi_adc_Close(hDevice);
        PASS();

    } while (0);
    return(SUCCESS);
}



static void usleep(uint32_t usec)
{
    volatile int y = 0;
    while (y++ < usec) {
        volatile int x = 0;
        while (x < 16) {
          x++;
        }
    }
}

