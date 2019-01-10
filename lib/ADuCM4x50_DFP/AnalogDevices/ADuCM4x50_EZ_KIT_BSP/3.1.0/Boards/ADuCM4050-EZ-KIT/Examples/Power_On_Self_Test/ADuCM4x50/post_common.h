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
 * Description:     This file contains common defines for all of POST
 */


#ifndef __POST_COMMON_H__
#define __POST_COMMON_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <adi_processor.h>


#include "drivers\uart\adi_uart.h"
#include "drivers\wdt\adi_wdt.h"
#include "pbled_test.h"
#include "timer_isr.h"

    #define _NORMALTEXT_          ""
    #define _BOLDTEXT_            ""
    #define _ITALICTEXT_          ""
    #define _BLINKTEXT_           ""
    #define _REDTEXT_             ""
    #define _GREENTEXT_           ""
    #define _YELLOWTEXT_          ""
    #define _BLUETEXT_            ""
    #define _MAGENTATEXT_         ""
    #define _CYANTEXT_            ""
    #define _WHITETEXT_           ""
    #define _BLACKTEXT_           ""
    #define _CLEARSCREEN_         ""
    #define _CURSORHOME_          ""
    #define _DEVICESTATUS_        ""
    #define _DEVICEOK_            ""



#define FAILURE 1
#define SUCCESS 0
/* macros */
#define DEBUG_RESULT(s,result,expected_value) \
  do { \
    if ((result) != (expected_value)) { \
      sprintf(aDebugString,"%s  %d", __FILE__,__LINE__); \
      test_Fail(aDebugString); \
    } \
  } while (0)


/* set lowest interrupt priority (highest number)
   according to number of priority bits on-chip */
#define LOWEST_PRIORITY ((1U << __NVIC_PRIO_BITS) -1)

/* bump UART interrupt priority by one (lower number = higher priority)
   so that UART output continues during low-power hibernation test */
#define UART_PRIORITY (LOWEST_PRIORITY - 1)

/* UART macros */
#define UART_DEBUG_DEV_ID         0
#define UART_DEBUG_BUFFER_SIZE    256
#define UART_DEBUG_MEM_SIZE       ADI_UART_BIDIR_MEMORY_SIZE
#define UART_DEBUG_DIRECTION      ADI_UART_DIR_BIDIRECTION

/* UART clock dividers yielding 9600 baud, computed for a 6.5MHz PCLK */
#define UART_DEBUG_BAUD           9600
#define UART_DEBUG_DIV_C             6
#define UART_DEBUG_DIV_M             3
#define UART_DEBUG_DIV_N          1078
#define UART_DEBUG_OSR               3

/* preprocessor tweaks to convert "__LINE__" from int to a char string... */
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)

#define PASS() test_Pass()
#define FAIL(s) sprintf(gPrintString,"%s  %d", __FILE__,__LINE__);test_Fail(gPrintString);sprintf(gPrintString,"%s \n\rFailed\n\r", s);test_Fail(gPrintString);


#define INFO(s) test_Info(s)
#define HEAD(s) test_Head(s)

/* define this macro to invert LED drive logic, as on the GluMicro eval board */
#define NEGATIVE_LED_LOGIC

#define NUM_LEDS 3

#define LED1 0x0001
#define LED2 0x0002
#define LED3 0x0004

/* LED delay constants, all in milliseconds */
#define LED_STROBE_DELAY    11
#define LED_BLINK_FAST      (LED_STROBE_DELAY * 3)
#define LED_BLINK_SLOW      (LED_BLINK_FAST * 2)

#define IGNORE_FAILURES			1
#define DO_NOT_IGNORE_FAILURES	0

/* global print string */
#define GLOBAL_PRINT_STRING_SIZE 256
extern char gPrintString[GLOBAL_PRINT_STRING_SIZE];
extern char aDebugString[150u];

/*******************************************************************
*  function prototypes
*******************************************************************/
int test_Init(void);
int test_Pass(void);
int test_Fail(char *FailureReason);
int test_Info(char *InfoString);
int test_Head(char *InfoString);

int Test_Standard_Loop(void);
int Toggle_Loop_Flag(void);
int Display_Post_Status(void);

int BLINK_FW_VERSION(void);
int DISPLAY_STR(char *);
int TEST_ADC(void);
int TEST_ADC_CHANNEL(void);
int TEST_BEEPER(void);
int TEST_CHECK_RTC(void);
int TEST_DISPLAY(void);
int TEST_PBLED(void);
int TEST_SET_RTC(void);
int TEST_SPI_ACCELEROMETER(void);
int TEST_RGB(void);
int TEST_SPI_FLASH(void);
int TEST_TWI_TEMP(void);
int TEST_UART(void);
int TEST_VERSION(void);
int TEST_WAKEUP(void);
int TEST_RTC_SET(void);
int TEST_LFX(void);


/*******************************************************************
*  global variables and defines
*******************************************************************/
enum _POST_STATE
{
	STATE_START,
	STATE_1,
	STATE_2,
	STATE_3,
	STATE_4,
	STATE_SELECTED
};

typedef enum TESTS_tag						/* LED PATTERN */
{
	TEST_0  = 0,							/* 00000 */
	TEST_1  = LED1,							/* 00001 */
	TEST_2  = LED2,							/* 00010 */
	TEST_3  = (LED1 | LED2),				/* 00011 */
	TEST_4  = LED3,							/* 00100 */
	TEST_5  = (LED1 | LED3),				/* 00101 */
	TEST_6  = (LED2 | LED3),				/* 00110 */
	TEST_7  = (LED1 | LED2 | LED3),			/* 00111 */

	LAST_TEST = 0x100
}enTESTS;

typedef enum TEST_STATES_tag
{
	TEST_0_CLR = 0,
	TEST_0_SET = 0,
	TEST_0_TGL = 0,
	TEST_0_EXT = 0,

	TEST_1_CLR = 0,
	TEST_1_SET = 1,
	TEST_1_TGL = 2,
	TEST_1_EXT = 3,

	TEST_2_CLR = (TEST_1_CLR << 2),
	TEST_2_SET = (TEST_1_SET << 2),
	TEST_2_TGL = (TEST_1_TGL << 2),
	TEST_2_EXT = (TEST_1_EXT << 2),

	TEST_3_CLR = (TEST_2_CLR | TEST_1_CLR),
	TEST_3_SET = (TEST_2_SET | TEST_1_SET),
	TEST_3_TGL = (TEST_2_TGL | TEST_1_TGL),
	TEST_3_EXT = (TEST_2_EXT | TEST_1_EXT),

	TEST_4_CLR = (TEST_1_CLR << 4),
	TEST_4_SET = (TEST_1_SET << 4),
	TEST_4_TGL = (TEST_1_TGL << 4),
	TEST_4_EXT = (TEST_1_EXT << 4),

	TEST_5_CLR = (TEST_4_CLR | TEST_1_CLR),
	TEST_5_SET = (TEST_4_SET | TEST_1_SET),
	TEST_5_TGL = (TEST_4_TGL | TEST_1_TGL),
	TEST_5_EXT = (TEST_4_EXT | TEST_1_EXT),

	TEST_6_CLR = (TEST_4_CLR | TEST_2_CLR),
	TEST_6_SET = (TEST_4_SET | TEST_2_SET),
	TEST_6_TGL = (TEST_4_TGL | TEST_2_TGL),
	TEST_6_EXT = (TEST_4_EXT | TEST_2_EXT),

	TEST_7_CLR = (TEST_4_CLR | TEST_2_CLR | TEST_1_CLR),
	TEST_7_SET = (TEST_4_SET | TEST_2_SET | TEST_1_SET),
	TEST_7_TGL = (TEST_4_TGL | TEST_2_TGL | TEST_1_TGL),
	TEST_7_EXT = (TEST_4_EXT | TEST_2_EXT | TEST_1_EXT),

	LAST_TEST_STATES
}enTEST_STATES;

#endif /* __POST_COMMON_H__ */
