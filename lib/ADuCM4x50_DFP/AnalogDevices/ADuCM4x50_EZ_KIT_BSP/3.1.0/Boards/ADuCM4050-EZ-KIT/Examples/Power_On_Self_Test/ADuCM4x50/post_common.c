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
 * Description:     This is common code for all the POST tests
 */


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/* DEBUG OUTPUT
   define the POST_COMMON_USES_UART macro in project settings to redirect semi-hosted
   output to the debug console (the default sevice) to the hardware UART device.

   The required pin muxing for UART should already be configured as part of the
   centralized pin muxing in post_pinmux.c.
*/

#include "post_common.h"

/* global print string */
char gPrintString[GLOBAL_PRINT_STRING_SIZE];

#ifdef POST_COMMON_USES_UART
/* UART debug terminal globals */
ADI_UART_HANDLE   hUartDebugTerm = NULL;
char              uartDebugMem[UART_DEBUG_MEM_SIZE];
#endif

/**
 * Initialize the test system, including SystemInit and Wdog
 *
 * @param  none
 * @return none
 *
 * @brief  Set up the test system
 *         Send output to wherever output should go
 */
int test_Init()
{

    while (1) {

        /* Disable WDT for testing*/

        if (adi_wdt_Enable(false, NULL)) {
            FAIL("adi_WDT_SetEnable failed");
            break;
        }


#ifdef POST_COMMON_USES_UART
      //  uint32_t baudrate;

        /* open UART device 0 in blocking, non-intrrpt, unidirectional transmit mode */
        if (adi_uart_Open(UART_DEBUG_DEV_ID, UART_DEBUG_DIRECTION, uartDebugMem, UART_DEBUG_MEM_SIZE, &hUartDebugTerm))
            break;

#endif

        /* success */
        return SUCCESS;

    }  /* end while */

    return FAILURE;
}



/**
 * Passing result
 *
 * @param  none
 * @return none
 *
 * @brief  Report a passing test result
 */
int test_Pass()
{
    char pass[] = "PASS!\n\r";

#ifdef POST_COMMON_USES_UART
    char *p;
    int32_t size;
    uint32_t error;

    p = pass;
    size = strlen(p);

    if (adi_uart_Write(hUartDebugTerm, p, size, false, &error)) {
        FAIL("adi_UART_BufTx failed");
        return FAILURE;;
    }
#else
    printf(pass);
#endif

    return SUCCESS;
}


/**
 * Failing result
 *
 * @param  none
 * @return none
 *
 * @brief  Report a failing test result
 */
int test_Fail(char *FailureReason)
{
    char fail[] = "FAIL: ";
    char term[] = "\n\r";

#ifdef POST_COMMON_USES_UART
    int32_t size;
    uint32_t error;

    size = strlen(fail);

    /* ignore return codes since there's nothing we can do if it fails */
    adi_uart_Write(hUartDebugTerm, fail, size, false, &error);

    size = strlen(FailureReason);

    /* ignore return codes since there's nothing we can do if it fails */
    adi_uart_Write(hUartDebugTerm, FailureReason, size, false, &error);

    size = strlen(term);

    /* ignore return codes since there's nothing we can do if it fails */
    adi_uart_Write(hUartDebugTerm, term, size, false, &error);
#else
    printf(fail);
    printf(FailureReason);
    printf(term);

#endif

    return FAILURE;
}


/**
 * Info
 *
 * @param  none
 * @return none
 *
 * @brief  Report test info
 */
int test_Info(char *InfoString)
{
    char term[] = "\n\r";

#ifdef POST_COMMON_USES_UART
    int32_t size;
    uint32_t error;

    size = strlen(InfoString);

    /* ignore return codes since there's nothing we can do if it fails */
    adi_uart_Write(hUartDebugTerm, InfoString, size, false, &error);

    size = strlen(term);

    /* ignore return codes since there's nothing we can do if it fails */
    adi_uart_Write(hUartDebugTerm, term, size, false, &error);

#else
    printf(InfoString);
    printf(term);
#endif

    return SUCCESS;
}


/**
 * Header
 *
 * @param  none
 * @return none
 *
 * @brief  Report test header
 */
int test_Head(char *InfoString)
{
	char banner[] = "**************************************************";

	test_Info(banner);
	test_Info(InfoString);
	test_Info(banner);

    return SUCCESS;
}
