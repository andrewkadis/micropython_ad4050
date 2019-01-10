/*
 *******************************************************************************

 Copyright(c) 2017 Analog Devices, Inc. All Rights Reserved.

 This software is proprietary and confidential.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.

 ******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <adi_processor.h>
#include <drivers/spi/adi_spi.h>
#include <drivers/pwr/adi_pwr.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/dma/adi_dma.h>
#include "spi_loopback_freertos.h"

#include "FreeRTOS.h"
#include "task.h"

/* Debugging facilities for all examples */
#include "common.h"



/***************************** TEST RTOS MAP FILE *****************************/
#include <rtos_map/adi_rtos_map.h>


/* Helper macro */
#define CHECK_ERROR(result, expected, message) \
do {\
    if ( (expected) != (result))\
    {\
        printf(message); \
        while(1) {} \
    }\
} while (0);


/******************************************************************************/


#define STACK_SZ  (configMINIMAL_STACK_SIZE + 50u)

/* Define the stacks, TCBs and Handles for the SPI slave a SPI master tasks */
static StackType_t  spiSlaveTaskStack[STACK_SZ];
static StaticTask_t spiSlaveTaskTCB;
static TaskHandle_t spiSlaveTaskHandle;

static StackType_t  spiMasterTaskStack[STACK_SZ];
static StaticTask_t spiMasterTaskTCB;
static TaskHandle_t spiMasterTaskHandle;

/* Define the stack and TCB for the Idle task */
StaticTask_t idleTask;
StackType_t  idleTaskStack[STACK_SZ];


/* 
 * The FreeRTOS implementation uses BASEPRI to create Critical Regions.
 * Basically, any interrupt at or above BASEPRI will be prevented from
 * executing when a FreeRTOS API needs to create a critical region.
 *
 * On the ADuCM4x50 all interrupt priorities are assigned '0' by default.
 * Therefore, any FreeRTOS application will need to move all interrupts
 * that could result in a FreeRTOS API call being made from an ISR, to
 * a lower priority than configMAX_SYSCALL_INTERRUPT_PRIORITY.
 */
static void assignInterruptPriorities(void)
{
  /* Any ISR that calls into the FreeRTOS must change its priority   */
  /* The most likely call is a to xSemaphoreGiveFromISR from many of */
  /* the drivers.                                                    */
  /* The tuning of interrupt priorities is application specific.     */  
  uint32_t i = RTC1_EVT_IRQn;
  for( i=(uint32_t)RTC1_EVT_IRQn; i<=(uint32_t)CLKG_ROOTCLK_ERR_IRQn; i++)
  {
    NVIC_SetPriority((IRQn_Type)i,     configMAX_SYSCALL_INTERRUPT_PRIORITY );
  }
 
  NVIC_SetPriority(SysTick_IRQn,        configMAX_SYSCALL_INTERRUPT_PRIORITY);
  NVIC_SetPriority(PendSV_IRQn,         configMAX_SYSCALL_INTERRUPT_PRIORITY);


}

/* 
 * @brief      Application start function for low-level initialization and RTOS creation
 *
 * @retval     Returns 0u if failure occurs, should never return
 */
int main(void)
{
    
#if( configUSE_TRACE_FACILITY == 1 )
    vTraceInitTraceData();
    uint32_t traceRet = uiTraceStart();
    if( traceRet != 1 )
    {
        DEBUG_MESSAGE("Failed to start the trace");
    }
    vTraceSetISRProperties(1, "ISR SPI 0", 0);
    vTraceSetISRProperties(2, "ISR SPI 1", 0);
#endif
    
    /* For the FreeRTOS, assign HW interrupt priorities */
    assignInterruptPriorities();
    
    adi_initpinmux();

    /* Common system initialization */
    common_Init();

    /* Power initialization */
    if(ADI_PWR_SUCCESS != adi_pwr_Init())
    {
        DEBUG_MESSAGE("Failed to intialize the power service");
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service");
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service\n");
    }
  
    /* Create the tasks */
    spiSlaveTaskHandle = xTaskCreateStatic(spiSlaveTask, "SPI Slave", STACK_SZ, NULL, TASK_SLAVE_PRIO, &spiSlaveTaskStack[0], &spiSlaveTaskTCB);
    if( spiSlaveTaskHandle == 0)
    {
      printf("SPI Slave Task creation failed\n");
      return 1;
    }
    spiMasterTaskHandle = xTaskCreateStatic(spiMasterTask, "SPI Master", STACK_SZ, NULL, TASK_MASTER_PRIO, &spiMasterTaskStack[0], &spiMasterTaskTCB);
    if( spiMasterTaskHandle == 0)
    {
      printf("SPI Master Task creation failed\n");
      return 1;
    }

    /* Start the RTOS (does not return) */
    vTaskStartScheduler();
    
    return 0;
}


void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &idleTask;
  *ppxIdleTaskStackBuffer = &idleTaskStack[0];
  *pulIdleTaskStackSize = STACK_SZ;
}


