/*****************************************************************************
 * @file:    rtc alarm.c
 * @brief:   Real-Time Clock input capture/output compare example 
 * @version: $Revision: 32592 $
 * @date:    $Date: 2015-11-04 07:07:20 -0500 (Wed, 04 Nov 2015) $
 *-----------------------------------------------------------------------------
 *
Copyright (c) 2016-2017 Analog Devices, Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  - Modified versions of the software must be conspicuously marked as such.
  - This software is licensed solely and exclusively for use with processors
    manufactured by or for Analog Devices, Inc.
  - This software may not be combined or merged with other code in any manner
    that would cause the software to become subject to terms and conditions
    which differ from those listed here.
  - Neither the name of Analog Devices, Inc. nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.
  - The use of this software may or may not infringe the patent rights of one
    or more patent holders.  This license does not release you from the
    requirement that you obtain separate licenses from these patent holders
    to use this software.

THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
TITLE, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
NO EVENT SHALL ANALOG DEVICES, INC. OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, PUNITIVE OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, DAMAGES ARISING OUT OF CLAIMS OF INTELLECTUAL
PROPERTY RIGHTS INFRINGEMENT; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/

#include <time.h>
#include <stddef.h>  /* for 'NULL' */
#include <stdio.h>   /* for scanf */
#include <string.h>  /* for strncmp */
#include <drivers/pwr/adi_pwr.h>
#include <drivers/rtc/adi_rtc.h>
#include <drivers/gpio/adi_gpio.h>
#include "common.h"
#include "rtc_io_example.h"

/* Counter for Sensor Strobe event */
volatile uint32_t nSensorStrobeCount = 0;

/* Counter for input_capture event */
volatile uint32_t nInputCaptureCnt = 0;

/* Device memory to operate the RTC device */
static uint8_t aRtcDevMem[ADI_RTC_MEMORY_SIZE];

/* RTC device handle */
ADI_RTC_HANDLE  hDevice;

/* pinmux the RTC Sensor Strobe signal*/
int32_t adi_initpinmux(void);

/* GPIO memory to operate */
 static uint8_t gpioMemory[ADI_GPIO_MEMORY_SIZE];
 
 /* Flag to indicate that a new input event has occurred */
 volatile bool bNewEvent = false;
 
 /* Info buffer to redirect the output to UART */
 char InfoBuff[200];
 
int main (void)
{
    ADI_RTC_RESULT eResult;
    ADI_GPIO_RESULT eResultGPIO;
    uint16_t value = 0, i=0;

    /* test system initialization */
    common_Init();
    /* Initialization of clock */
    InitClock();
    /* initialize driver */
    adi_initpinmux();    
    
    if((eResultGPIO = InitGPIO())!= ADI_GPIO_SUCCESS )
    {
     DEBUG_RESULT("Failed to enable the GPIO driver",eResultGPIO,ADI_GPIO_SUCCESS);
    }
   

   /* initialize driver */
   if((eResult = rtc_Init())!= ADI_RTC_SUCCESS )
   {
      DEBUG_MESSAGE("\nFailed to initialize RTC device \n");
   }
   
   /* Enable the RTC device */
   eResult = adi_rtc_Enable ( hDevice, true);
   DEBUG_RESULT("Failed initialize the RTC device", eResult, ADI_RTC_SUCCESS);
    
    /*   process the input events */  
    while(nInputCaptureCnt <= MAX_OUTCOMP)
    {
       if(bNewEvent == true)
       {
          eResult = adi_rtc_GetInputCaptureValue(hDevice, INPUT_CHANNEL, &value);
          DEBUG_RESULT("Failed to get the input capture value", eResult, ADI_RTC_SUCCESS);
          
          sprintf(InfoBuff," EVENT-NO : %04d\t : INPUT-COUNT SNAP-SHOT :  %04X",i++,value);
          DEBUG_MESSAGE(InfoBuff);
          bNewEvent= false;
       }
    }
    
    uint32_t tempInputCaptureCnt = nInputCaptureCnt;
    uint32_t tempSensorStrobeCount = nSensorStrobeCount;

    /* Enable the RTC device */
    eResult = adi_rtc_Close ( hDevice );
    DEBUG_RESULT("Failed Close the RTC device", eResult, ADI_RTC_SUCCESS);
 
    if( tempInputCaptureCnt == tempSensorStrobeCount )
    {
      common_Pass();
    }
    else
    {
      common_Fail("\n RTC test failed \n");
    }

}

/* RTC-1 Callback handler */
void RtcCallback (void *pCBParam, uint32_t nEvent, void *EventArg) 
  {
    if((ADI_RTC_SENSOR_STROBE_CH1_INT & nEvent) == ADI_RTC_SENSOR_STROBE_CH1_INT )
    {
      /* Toggle LED */
       adi_gpio_Toggle(ADI_GPIO_PORT1, ADI_GPIO_PIN_12);
       nSensorStrobeCount++;
    }
    if((INPUT_CHANNEL_INT & nEvent) == INPUT_CHANNEL_INT )
    {
       /* Toggle LED */
      adi_gpio_Toggle(ADI_GPIO_PORT1, ADI_GPIO_PIN_13);
      nInputCaptureCnt++;
      bNewEvent= true;
    }
    
  }
  

/* Initialize the RTC device
 */
ADI_RTC_RESULT rtc_Init (void) 
{
    /* Note that most of the RTC configuration is handled statically (at build time)
     * See the file config/adi_rtc_config.h where the following RTC features are configured
     *
     *   RTC Count Register values
     *   Set Sensor Strobe value
     *   Enabling Sensor Strobe
     *   Enabling Auto Reload
     *   Setting the Reload Value
     *   Enabling Input Compare
     *   Enabling Snapshot Overwrite
     *   Enabling Sensor Strobe and Input Capture interrupts
     */

        

    ADI_RTC_RESULT eResult;
    
    eResult = adi_rtc_Open(RTC_DEVICE_NUM, aRtcDevMem, ADI_RTC_MEMORY_SIZE, &hDevice);
    DEBUG_RESULT("\n Failed to open the device %04d", eResult, ADI_RTC_SUCCESS);

    eResult = adi_rtc_RegisterCallback(hDevice, RtcCallback, hDevice);
    DEBUG_RESULT("\n Failed to register the callback function to  the device", eResult, ADI_RTC_SUCCESS);
    

    return(eResult);
}


/* Initialize the power service
 */
ADI_PWR_RESULT InitClock()
{
  ADI_PWR_RESULT eResult;
  if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_Init()))
  {
    return(eResult);
  }
   
  if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_SetLFClockMux(ADI_CLOCK_MUX_LFCLK_LFXTAL)))
  {
    return(eResult);
  }

  if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_EnableClockSource(ADI_CLOCK_SOURCE_LFXTAL,true)))
  {
    return(eResult);
  }
  
  if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1)))
  {
    return(eResult);
  }
  if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1)))
  {
    return(eResult);
  }
  
  return(eResult);
 
}
/* Initialize the GPIO service to toggle LEDs */

ADI_GPIO_RESULT InitGPIO(void)
{
        ADI_GPIO_RESULT eResultGPIO;
        /* init the GPIO service */
        eResultGPIO = adi_gpio_Init(gpioMemory, ADI_GPIO_MEMORY_SIZE);
        DEBUG_RESULT("Failed to Initialize the GPIO driver",eResultGPIO,ADI_GPIO_SUCCESS);

        /* set GPIO output LED 4 to toggle when Sensor Strobe event happens. */
        eResultGPIO = adi_gpio_OutputEnable(ADI_GPIO_PORT1, ADI_GPIO_PIN_12, true);
        DEBUG_RESULT("Failed to enable the output for GPIO",eResultGPIO,ADI_GPIO_SUCCESS);
        
        /* set GPIO output LED 3 to toggle when  input campture event happens. */
        eResultGPIO = adi_gpio_OutputEnable(ADI_GPIO_PORT1, ADI_GPIO_PIN_13, true);
        DEBUG_RESULT("Failed to enable the output for GPIO",eResultGPIO,ADI_GPIO_SUCCESS);
    
        /* set GPIO input to capture the pulse generated by RTC. */        
        eResultGPIO = adi_gpio_InputEnable(ADI_GPIO_PORT2, ADI_GPIO_PIN_1, true);
        DEBUG_RESULT("Failed to enable the input for GPIO",eResultGPIO,ADI_GPIO_SUCCESS);
                    
        return(ADI_GPIO_SUCCESS);
}
