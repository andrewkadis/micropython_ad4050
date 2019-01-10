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
 * Description:     This examples tests the adxl363 accelerometer on the ADuCM4x50 EZKIT.
 */


#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <drivers/general/adi_drivers_general.h>
#include <drivers/adxl363/adi_adxl363.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/pwr/adi_pwr.h>
#include "post_common.h"

/* Set the number of times the data should be collected */
#define TEST_ITERATIONS                     2

/* GPIO port and pin to which interrupt pin1 of ADXL363 is connected */
#define ADXL363_INT1_GPIO_PORT              ADI_GPIO_PORT2
#define ADXL363_INT1_GPIO_PIN               ADI_GPIO_PIN_1

/* GPIO port and pin to which interrupt pin2 of ADXL363 is connected */
#define ADXL363_INT2_GPIO_PORT              ADI_GPIO_PORT2
#define ADXL363_INT2_GPIO_PIN               ADI_GPIO_PIN_11

/* Memory for GPIO callbacks */
ADI_ALIGNED_PRAGMA(4)
uint8_t GPIOCallbackMem[ADI_GPIO_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Memory required for accelerometer driver */
ADI_ALIGNED_PRAGMA(4)
uint8_t AccelMem[ADI_ADXL363_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Accelerometer device handle */
ADI_ADXL363_HANDLE              hADXL363;

/* Opens and sets up the accelerometer driver */
static ADI_ADXL363_RESULT SetupAccel(void);

/* Collect the data from accelerometer */
static ADI_ADXL363_RESULT CollectData(void);

/* Handles the detected interrupts from task/non-ISR level */
static ADI_ADXL363_RESULT HandleEvent(uint8_t IntSource);

/* Flag which indicates whether an interrupt is detected */
static volatile bool gbIntDetected = false;
static volatile uint32_t nTestCounter = 0u; 

/* Local Msg buffer for printing the accelerometer data in ReadData() */
ADI_ALIGNED_PRAGMA(4)
uint8_t g_MsgBuf[50] ADI_ALIGNED_ATTRIBUTE(4);

extern void adi_initpinmux(void);


int TEST_SPI_ACCELEROMETER(void)
{
    ADI_ADXL363_RESULT eAccResult;    
    
    
    /* Setup accelerometer */
    eAccResult = SetupAccel();
    DEBUG_RESULT("Setup failed", eAccResult, ADI_ADXL363_SUCCESS);
    
    INFO("Tilt the device \n" );
    
    /* Collect data from accelerometer */
    eAccResult = CollectData();
    if (eAccResult != ADI_ADXL363_SUCCESS) {
        INFO("Data read failed");
        adi_adxl363_Close(hADXL363);
     } else {
        eAccResult = adi_adxl363_Close(hADXL363);
        if (eAccResult != ADI_ADXL363_SUCCESS) {
            INFO("adxl363 close failed");
        }
     }

    /* Example over! */
    
    if (eAccResult == ADI_ADXL363_SUCCESS) 
        PASS();


    Init_PushButtons();


    return eAccResult;
}

/* Accelerometer callback - to indicate when data is ready */
static void AccelCallback(void *pCBParam, uint32_t Port, void *pin)
{
  gbIntDetected = true;
  return;
}


/* Opens and sets up the accelerometer driver */
static ADI_ADXL363_RESULT SetupAccel(void)
{
  
  /* Open the accelerometer driver */
  if(adi_adxl363_Open (AccelMem,
                       ADI_ADXL363_MEMORY_SIZE,
                       &hADXL363 ) != ADI_ADXL363_SUCCESS)
  {
    INFO("Failed to open the accelerometer driver \n");
    return ADI_ADXL363_FAILURE;
  }
  
  /* Register a callback for the accelerometer */
  if( adi_adxl363_RegisterCallback(hADXL363, 
                                   AccelCallback, 
                                   NULL) != ADI_ADXL363_SUCCESS)
  {
    INFO("Failed to register callback \n");
    return ADI_ADXL363_FAILURE;
  }
  
  /* Set the GPIO pins connected to the host for accelerometer interrupts */
  if(adi_adxl363_ConfigIntPin (hADXL363,
                               ADI_GPIO_INTA_IRQ,
                               ADI_ADXL363_INTPIN1,
                               ADXL363_INT1_GPIO_PORT,
                               ADXL363_INT1_GPIO_PIN
                                 ) != ADI_ADXL363_SUCCESS)
  {
    INFO("Failed to configure interrupt pin1 \n");
    return ADI_ADXL363_FAILURE;
  }
  
  /* Set the GPIO pins connected to the host for accelerometer interrupts */
  if(adi_adxl363_ConfigIntPin (hADXL363,
                               ADI_GPIO_INTA_IRQ,
                               ADI_ADXL363_INTPIN2,
                               ADXL363_INT2_GPIO_PORT,
                               ADXL363_INT2_GPIO_PIN  
                                 ) != ADI_ADXL363_SUCCESS)
  {
    INFO("Failed to configure interrupt pin2 \n");
    return ADI_ADXL363_FAILURE;
  }
  
  /* Configure the interrupt polarity to fire when transitioning low-to-high */
  if(adi_adxl363_SetIntPolarity (hADXL363,
                                 ADI_ADXL363_INTPIN1,
                                 false
                                   ) != ADI_ADXL363_SUCCESS)
  {
    INFO("Failed to configure interrupt polarity \n");
    return ADI_ADXL363_FAILURE;
  }  
  
  return ADI_ADXL363_SUCCESS;
}


/* Collects the data from accelerometer */
static ADI_ADXL363_RESULT CollectData(void)
{
    uint8_t IntSource;
 //   uint32_t nTestCounter = 0u;  /* test counter */    
     
    /* Enable the measurement */
    if(adi_adxl363_Enable(hADXL363, true) != ADI_ADXL363_SUCCESS)
    {
        INFO("Failed to enable accelerometer \n");
        return ADI_ADXL363_FAILURE;
    }
    
    /* Wait for TEST_ITERATIONS number of interrupts */
    while(nTestCounter < TEST_ITERATIONS){
      /* Handle all the pending interrupts so that the interrupt line goes low */
      if(gbIntDetected == true)
      {
        /* Get the source(s) of interrupt */
        if(adi_adxl363_GetIntStatus (hADXL363,
                                     &IntSource
                                       ) != ADI_ADXL363_SUCCESS )
        {
          INFO("Failed to get interrupt source \n");
          return ADI_ADXL363_FAILURE;
        }
        
        /* Handle the reported interrupt(s) */
        if(IntSource != 0)
        {
          if(HandleEvent(IntSource) != ADI_ADXL363_SUCCESS)
          {
            INFO("Failed to handle the interrupt source \n");
            return ADI_ADXL363_FAILURE;
          }
        }
        
        /* Clear the interrupt detected flag after handling all the interrrupt sources */
        gbIntDetected = false;
        nTestCounter++;
        
        /* Clear any subsequent Activity/Inactivity interrupts since the previous 
         * status read, which may have happened during the print statements.
         * Simply wait for another round of activity/inactivity. */
        if(adi_adxl363_GetIntStatus (hADXL363,
                                     &IntSource
                                       ) != ADI_ADXL363_SUCCESS )
        {
          INFO("Failed to get interrupt source \n");
          return ADI_ADXL363_FAILURE;
        }
      }
    }
    return ADI_ADXL363_SUCCESS; 
}

/* Reads and then prints the x-y-z data from the ADXL363. */
static ADI_ADXL363_RESULT ReadData( void)
{
    uint16_t    LocalBuf[3];

    if(adi_adxl363_ReadData(hADXL363, LocalBuf) != ADI_ADXL363_SUCCESS)
    {
        INFO("Failed to read the data from accelerometer \n");
    }

    sprintf((char *)&g_MsgBuf[0], "Got Data X = 0x%04x, Y = 0x%04x, Z = 0x%04x\n", LocalBuf[0], LocalBuf[1], LocalBuf[2]);
    INFO((char *)g_MsgBuf);

    return ADI_ADXL363_SUCCESS;
}
       

/* Handles the detected interrupts, *not* called from ISR level */
static ADI_ADXL363_RESULT HandleEvent(uint8_t IntSource)
{
    ADI_ADXL363_RESULT Result = ADI_ADXL363_SUCCESS;
    uint8_t Mask;
    uint8_t i;

    for(i = 0; i < 8; i++)
    {
        Mask = (1 << i);

        switch(IntSource & Mask)
        {         
            case ADI_ADXL363_INT_AWAKE:
                INFO("Awake \n");
                Result = ReadData();
                break;

            case ADI_ADXL363_INT_INACTIVITY:
                INFO("Inactivity detected \n");
                break;

            case ADI_ADXL363_INT_ACTIVITY:
                INFO("Activity detected \n");
                break;

            case ADI_ADXL363_INT_DATA_READY:
                Result = ReadData();
                break;

            default:
                break;
        }

        if(Result != ADI_ADXL363_SUCCESS)
        {
            return Result;
        }

        /* Clear the handled bit */
        IntSource &= ~Mask;

        /* Stop the loop if no more interrupts to handle */
        if(IntSource == 0)
        {
            break;
        }
    }

    return Result;
}


