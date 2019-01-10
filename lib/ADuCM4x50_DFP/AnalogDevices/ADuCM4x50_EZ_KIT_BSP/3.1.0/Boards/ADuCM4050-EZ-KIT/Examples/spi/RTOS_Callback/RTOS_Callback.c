/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      RTOS_Callback.c
 * @brief     SPI Master slave loopback RTOS based example primary source file. 
 */

/*=============  I N C L U D E S   =============*/

#include "os.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <drivers/spi/adi_spi.h>
#include <drivers/pwr/adi_pwr.h>
#include <drivers/dma/adi_dma.h>
#include "RTOS_Callback.h"


/*=============  D E F I N E S   =============*/


/*=============  R T O S D A T A   =============*/


static OS_TCB g_Task_Slave_TCB;
static OS_TCB g_Task_Master_TCB;


static CPU_STK g_Task_Slave_Stack  [TASK_STK_SIZE];
static CPU_STK g_Task_Master_Stack  [TASK_STK_SIZE];

extern void SlaveTask(void *);
extern void MasterTask(void *);

int32_t adi_initpinmux(void);

/*********************************************************************
*
*   Function:   main
*
*********************************************************************/
int main (void)
{
    adi_initpinmux();
    /* test system initialization */
    common_Init();
    /* Initialize power service */
    if((adi_pwr_Init())!= ADI_PWR_SUCCESS )
    {
        DEBUG_MESSAGE("Power-init  failed");
        exit(0);
    }
    /* Set core clock divider to "1" which sets it to 26Mhz*/
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
        DEBUG_MESSAGE("Failed to initialize the power service\n");
        exit(0);
    }
    /* Set peripheral clock  divider to "1" which sets it to 26Mhz*/    
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        DEBUG_MESSAGE("Failed to initialize the power service\n");
        exit(0);
    }


    OS_ERR OSRetVal;

    /* Initialize the RTOS */
    OSInit(&OSRetVal);
    if (OSRetVal != OS_ERR_NONE)
    {
        printf("Failed to initialize the RTOS \n");
        return(0);
    }

    /* Create the Start-up Task*/
    OSTaskCreate (&g_Task_Slave_TCB, /* address of TCB */
        "SPI Slave Task",            /* Task name */
        SlaveTask,                   /* Task "Run" function */
        NULL,                        /* arg for the "Run" function*/
        TASK_SLAVE_PRIO,             /* priority */
        g_Task_Slave_Stack,          /* base of the stack */
        TASK_STK_SIZE - 1u,          /* limit for stack growth */
        TASK_STK_SIZE,               /* stack size in CPU_STK */
        0u,                          /* number of messages allowed */
        (OS_TICK)  0u,               /* time_quanta */
        NULL,                        /* extension pointer */
        (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
        &OSRetVal);


    if (OSRetVal != OS_ERR_NONE)
    {
        printf("Failed to create SPI Slave task\n");
        return(1);
    }
    /* Create the Start-up Task*/
    OSTaskCreate (&g_Task_Master_TCB,     /* address of TCB */
        "SPI Master Task",                /* Task name */
        MasterTask,                       /* Task "Run" function */
        NULL,                             /* arg for the "Run" function*/
        TASK_MASTER_PRIO,                 /* priority */
        g_Task_Master_Stack,              /* base of the stack */
        TASK_STK_SIZE - 1u ,              /* limit for stack growth */
        TASK_STK_SIZE,                    /* stack size in CPU_STK */
        0u,                               /* number of messages allowed */
        (OS_TICK)  0u,                    /* time_quanta */
        NULL,                             /* extension pointer */
        (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
        &OSRetVal);


    if (OSRetVal != OS_ERR_NONE)
    {
        printf("Failed to create SPI Master task\n");
        return(1);
    }

    /* Start OS */
    OSStart(&OSRetVal);

    if (OSRetVal != OS_ERR_NONE)
    {
        printf("Failed to start RTOS\n");
    }
}

               
/*****/

