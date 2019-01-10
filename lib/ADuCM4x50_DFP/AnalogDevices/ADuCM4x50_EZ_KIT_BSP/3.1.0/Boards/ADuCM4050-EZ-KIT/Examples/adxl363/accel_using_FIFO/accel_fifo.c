/*********************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
* @file     accel_fifo.c
*
* @brief    This is the primary source file adxl363 accelerometer example.
*
* @details  This example demonstrates how to configure the adxl363 accelerometer
*           and collect the data from it using the FIFO on teh ADXL363 chip.
*           The SPI interface is used to configure the accelerometer registers 
*           and then collect the data from the accelerometer.
*/

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <common.h>
#include <drivers/adxl363/adi_adxl363.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/pwr/adi_pwr.h>

/* Set the number of times the FIFO should be emptied */
#define TEST_ITERATIONS                     10

/* GPIO port and pin to which interrupt pin1 of ADXL363 is connected */
#define ADXL363_INT1_GPIO_PORT              ADI_GPIO_PORT2
#define ADXL363_INT1_GPIO_PIN               ADI_GPIO_PIN_1

/* GPIO port and pin to which interrupt pin2 of ADXL363 is connected */
#define ADXL363_INT2_GPIO_PORT              ADI_GPIO_PORT2
#define ADXL363_INT2_GPIO_PIN               ADI_GPIO_PIN_11


/* Memory for GPIO callbacks */
uint8_t GPIOCallbackMem[ADI_GPIO_MEMORY_SIZE];

/* Memory required for accelerometer driver */
uint8_t AccelMem[ADI_ADXL363_MEMORY_SIZE];

/* Allocate space for the entire fifo depth */
uint16_t data[ADI_ADXL363_MAX_FIFO_SAMPLES];  /* Buffer to read samples */

/* Accelerometer device handle */
ADI_ADXL363_HANDLE              hADXL363;

/* Opens and sets up the accelerometer driver */
static ADI_ADXL363_RESULT SetupAccel(void);

/* Reads the Fifo */
static ADI_ADXL363_RESULT ReadFifoData(void);

/* Flag which indicates whether an interrupt is detected */
static volatile bool gbIntDetected = false;

extern void adi_initpinmux(void);

int main(void)
{
    ADI_PWR_RESULT ePwrResult;
    ADI_GPIO_RESULT eGpioResult;
    ADI_ADXL363_RESULT eAccResult;    
    
    adi_initpinmux();
    common_Init();
    
    ePwrResult = adi_pwr_Init();
    DEBUG_RESULT("adi_pwr_Init failed.", ePwrResult, ADI_PWR_SUCCESS);
    
    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_HCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (HCLK) failed.", ePwrResult, ADI_PWR_SUCCESS);
    
    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_PCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (PCLK) failed.", ePwrResult, ADI_PWR_SUCCESS);
    
    /* Initialize GPIO service for getting accelerometer interrupts */
    eGpioResult = adi_gpio_Init(GPIOCallbackMem, ADI_GPIO_MEMORY_SIZE);
    DEBUG_RESULT("GPIO failed", eGpioResult, ADI_GPIO_SUCCESS);

    /* Setup accelerometer */
    eAccResult = SetupAccel();
    DEBUG_RESULT("Setup failed", eAccResult, ADI_ADXL363_SUCCESS);
    
    DEBUG_MESSAGE("Entering FIFO mode" );
    
    /* Collect data from FIFO */
    eAccResult = ReadFifoData();
    DEBUG_RESULT("Fifo read failed", eAccResult, ADI_ADXL363_SUCCESS);
    
    eAccResult = adi_adxl363_Close(hADXL363);
    DEBUG_RESULT("adxl363 close failed", eAccResult, ADI_ADXL363_SUCCESS);

    /* Example over! */
    common_Pass();
    return 0;
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
    DEBUG_MESSAGE("Failed to open the accelerometer driver \n");
    return ADI_ADXL363_FAILURE;
  }
  
  /* Register a callback for the accelerometer */
  if( adi_adxl363_RegisterCallback(hADXL363, 
                                   AccelCallback, 
                                   NULL) != ADI_ADXL363_SUCCESS)
  {
    DEBUG_MESSAGE("Failed to register callback \n");
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
    DEBUG_MESSAGE("Failed to configure interrupt pin1 \n");
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
    DEBUG_MESSAGE("Failed to configure interrupt pin2 \n");
    return ADI_ADXL363_FAILURE;
  }
  
  /* Configure the interrupt polarity to fire when transitioning low-to-high */
  if(adi_adxl363_SetIntPolarity (hADXL363,
                                 ADI_ADXL363_INTPIN1,
                                 false
                                   ) != ADI_ADXL363_SUCCESS)
  {
    DEBUG_MESSAGE("Failed to configure interrupt polarity \n");
    return ADI_ADXL363_FAILURE;
  }  
  
  return ADI_ADXL363_SUCCESS;
}

/* Configure the Fifo, and read blocks of data when a watermark is
 * reached. */

static ADI_ADXL363_RESULT ReadFifoData(void)
{
  uint16_t cnt;                /* Number of samples to read */
  uint8_t  ints;               /* Interrupts fired */
  uint32_t nTestCounter = 0u;  /* test counter */
  
  
  /* Clear any previous interrupts by reading the status register */
  if(adi_adxl363_GetIntStatus (hADXL363, &ints) != ADI_ADXL363_SUCCESS )
  {
    DEBUG_MESSAGE("Failed to get interrupt status \n");
    return ADI_ADXL363_FAILURE;
  }
  /* Clear the memory before starting */
  memset(data, 0, ADI_ADXL363_MAX_FIFO_SAMPLES * sizeof(uint16_t));  
  
  /* Start measurements */
  if(adi_adxl363_Enable(hADXL363, true) != ADI_ADXL363_SUCCESS)
  {
    DEBUG_MESSAGE("Failed to enable accelerometer \n");
    return ADI_ADXL363_FAILURE;
  }

  while(nTestCounter < TEST_ITERATIONS){
    
    /* Wait for an interrupt to fire */
    if(gbIntDetected == true) {
      
      /* Get the source(s) of interrupt - also clears the interrupts */
      if(adi_adxl363_GetIntStatus (hADXL363,
                                   &ints) != ADI_ADXL363_SUCCESS )
      {
        DEBUG_MESSAGE("Failed to get interrupt source \n");
      }
      
      /* Have we reached the FIFO watermark? */
      if((ints & ADI_ADXL363_INT_WATERMARK) == ADI_ADXL363_INT_WATERMARK) {
        /* Get the count - may contain more than the watermark number */
        if(ADI_ADXL363_SUCCESS == adi_adxl363_GetEntriesInFIFO(hADXL363, &cnt)) {
          /* Make sure there are samples to read */
          if(cnt != 0) {
            /* Read the FIFO */
            if(ADI_ADXL363_SUCCESS != adi_adxl363_ReadFIFO(hADXL363,
                                                           data,
                                                           cnt)) {
              DEBUG_MESSAGE("Could not collect FIFO data \n");
              return ADI_ADXL363_FAILURE;
            }
          }
          else {
             DEBUG_MESSAGE("Fifo does not contain any data \n");
             return ADI_ADXL363_FAILURE;
          }
        }
        nTestCounter++;
      }
      
      DEBUG_MESSAGE("Fifo successfully emptied");
      gbIntDetected = false;   /* Clear the interrupt flag */
      /* Clear the memory for another run. */
      memset(data, 0, ADI_ADXL363_MAX_FIFO_SAMPLES*sizeof(uint16_t)); 
    }
  }
  return ADI_ADXL363_SUCCESS;
}
       
