/*
 * (C) Copyright 2016 - Analog Devices, Inc. All Rights Reserved.
 *
 * This software is proprietary and confidential.  By using this software
 * you agree to the terms of the associated Analog Devices License Agreement.
 *
 * Project Name:   Power_On_Self_Test 
 * Hardware:       ADuCM4x50 EZKIT
 *
 * Description:    This example performs POST on the ADuCM4x50 EZKIT
 *
 * Please view the Readme_post.html file for detailed information related to
 * switch and jumper settings, LED indicators, etc.
 *
 * Enter POST standard test loop by pressing PB2 at startup, or by entering
 * a sequence using PB1 and PB2 to choose a specific test.
 */

#include <drivers/pwr/adi_pwr.h>
#include "post_common.h"

/* pinmux API */
extern int32_t adi_initpinmux(void);

/*
 *  Test Dummies
 */
int Test_Dummy_Pass(void) {return 1;}    /* a dummy test that returns pass */
int Test_Dummy_Fail(void) {return 0;}    /* a dummy test that returns fail */

/*
 *  global variables and defines
 */
static int g_loops = 0;
char aDebugString[150u];
bool g_bLoopFlagCheck = false;                /* flag used to check for loop flag test */
bool g_bLoopOnTest = false;                    /* when set will cause next test to loop forever */
bool g_bIsTestChosen = false;                /* test chosen flag */
int g_nSelectedTest = 0;                    /* chosen test */
volatile int g_nPostState = STATE_START;    /* POST state used when entering a test */
extern volatile bool g_button_0_pushed;
extern volatile bool g_button_1_pushed;
bool ContinousLoop = false;                    /* flag to continue running tests after a failure */


/* expected peripheral clock is 26MHz */
#define EXPECTED_PCLK 26000000

/* firmware version */
#define POST_VERSION 2


/* check board rev */
#if defined(EZKIT_REV_0_1) || defined(EZKIT_REV_1_0)
#else
#error *** EZ-Board rev not specified, please define a valid rev ***          
#endif

typedef int (*pfnTests)(void);

typedef struct _PostTestParameters
{
    pfnTests        m_pTestFunction;    /* test function pointer */
    bool            m_bStandardLoop;    /* is this part of the standard loop? */
    bool            m_bOneTime;         /* does this test run one-time? */
    bool            m_bIgnoreFailures;  /* ignore failures for this test? */
    unsigned int    m_uiPassed;         /* number of times this test passed */
    unsigned int    m_uiFailed;         /* number of times this test failed */
    char            m_pszName[16];      /* NULL terminated string with test name */
} PostTestParameters;


/* Test Stubs to be implimented with real code in their own files... */
int TEST_TEMP_COMPARE      (void) {return 0;}    /* a dummy test that returns fail */
int TEST_RTC_CHECK         (void) {return 0;}    /* a dummy test that returns fail */
int TEST_RTC_RETAIN        (void) {return 0;}    /* a dummy test that returns fail */



/*
 *  test structure - Configurable structure allows you to specify function pointers,
 *  whether the test is part of the standard loop, whether it should run one-time,
 *  and whether to ignore failures.  We also track the number of passes and fails
 *  for each test which can be displayed with the Display_Status command.
 */
PostTestParameters g_Tests[] =
{
    /* ===================================================================================================================== */
    /*                        | PART OF |ONE  |IGNORE|# OF |# OF |    TEST NAME      |        |   PB   |  LEDS | blinks on   */
    /*    TEST FUNCTION       | STANDARD|TIME?|FAILS?|PASS |FAIL |  15 CHARS + NULL  | TEST # |sequence| [3:1] |  failure    */
    /*                        | LOOP?   |     |      |     |     | 123456789ABCDEF0  |        |        |       |             */
    /* ===================================================================================================================== */
    { Test_Standard_Loop,        true,   false, false,  0,    0,  "Standard Loop"    }, /*  0 |  00000 |  000  |  one time   */
    { TEST_VERSION,              true,   false, false,  0,    0,  "Proc Version"     }, /*  1 |  00001 |  001  |  one time   */
    { TEST_PBLED,                true,   true,  false,  0,    0,  "Pushbuttons/LED"  }, /*  2 |  00010 |  010  |  one time   */
    { TEST_UART,                 true,   true,  false,  0,    0,  "UART"             }, /*  3 |  00011 |  011  |  one time   */
    { TEST_BEEPER,               true,   true, false,   0,    0,  "Beeper"           }, /*  4 |  00100 |  100  |  one time   */
    { TEST_SPI_FLASH,            true,   false, false,  0,    0,  "SPI Flash"        }, /*  5 |  00101 |  101  |  one time   */
    { TEST_SPI_ACCELEROMETER,    true,   true, false,   0,    0,  "SPI Accel"        }, /*  6 |  00110 |  110  |  one time   */
    { TEST_RGB,                  true,   false, false,  0,    0,  "RGB Timer Test"   }, /*  7 |  00111 |  111  |  one time   */
    /* --------------------------------------------------------------------------------------------------------------------- */
    { TEST_TWI_TEMP,             true,   false, false,  0,    0,  "TWI Temp"         }, /*  8 |  01000 |  001  | two times   */
    { Test_Dummy_Pass,           false,  false, true,   0,    0,  "Not Used #9"      }, /*  9 |  01001 |  010  | two times   */
    { TEST_WAKEUP,               true,   true,  false,  0,    0,  "Wakeup"           }, /* 10 |  01010 |  011  | two times   */
    { TEST_ADC,                  true,   true,  false,  0,    0,  "ADC"              }, /* 11 |  01011 |  100  | two times   */
    { TEST_RTC_SET,              true,   false, false,  0,    0,  "RTC Clk Set"      }, /* 12 |  01100 |  101  | two times   */
    { Test_Dummy_Fail,           false,  false, false,  0,    0,  "Not Used #13"     }, /* 13 |  01101 |  110  | two times   */
    { Test_Dummy_Fail,           false,  false, false,  0,    0,  "Not Used #14"     }, /* 14 |  01110 |  111  | two times   */
    /* --------------------------------------------------------------------------------------------------------------------- */
    { Test_Dummy_Fail,           false,  false, false,  0,    0,  "Not Used #15"     }, /* 15 |  01111 |  001  | three times */
    { BLINK_FW_VERSION,          true,   false, false,  0,    0,  "Display FW Ver"   }, /* 16 |  10000 |  010  | three times */
    { TEST_LFX,                  true,   false, true,   0,    0,  "LFX"              }, /* 17 |  10001 |  011  | three times */
    { Test_Dummy_Fail,           false,  false, true,   0,    0,  "Not Used #18"     }, /* 18 |  10010 |  100  | three times */
    { Display_Post_Status,       true,   false, false,  0,    0,  "Display Status"   }, /* 19 |  10011 |  101  | three times */
    { Test_Dummy_Fail,           false,  false, true,   0,    0,  "Not Used #20"     }, /* 20 |  10100 |  110  | three times */
    { Toggle_Loop_Flag,          false,  false, false,  0,    0,  "Toggle LoopFlag"  }  /* 21 |  10101 |  111  | three times */
    /* --------------------------------------------------------------------------------------------------------------------- */
};
#define NUM_POST_TESTS (sizeof(g_Tests)/sizeof(g_Tests[0]))


/* 8 different test states */
enTEST_STATES states[] = {TEST_0_SET, TEST_1_SET, TEST_2_SET, TEST_3_SET,
                          TEST_4_SET, TEST_5_SET, TEST_6_SET, TEST_7_SET};



/*
 *   Function:    PerformTest
 *   Description: This executes a specified test and displays status
 *                 LEDs accordingly.
 */
int PerformTest( int nTestId )
{
    int   nResult = FAILURE;    /* assume failure */
    int   nRound = 0;           /* which round does this test run in */
    int   n = 0, m = 0;         /* indexes */
    int   test_indicator;       /* test indicator, with 3 LEDs only 0-7 */

    /* determine the test pattern */
    test_indicator = nTestId % 7;
    if (0 == test_indicator)
    {
        if (0 != nTestId)
        {
            test_indicator = 7;
        }
    }

    if (nTestId > 21)
    {
        return FAILURE;
    }

    /* display test pattern */
    Delay(LED_BLINK_SLOW * 15);

    Drive_LED_Bank( 0x0000 );
    Drive_LED_Bank( states[test_indicator] );

    if (nTestId < NUM_POST_TESTS)
        nResult = g_Tests[nTestId].m_pTestFunction();    /* call test function */
   
    /* if test failed */
    if (FAILURE == nResult)
    {
        /* update count */
        g_Tests[nTestId].m_uiFailed++;

        /* display test stats */
        sprintf(gPrintString,  _BOLDTEXT_"" _MAGENTATEXT_"\n\nTest %s: "_NORMALTEXT_"passed %d  "_BOLDTEXT_""_REDTEXT_"failed %d"_NORMALTEXT_"",
                        g_Tests[nTestId].m_pszName,
                        g_Tests[nTestId].m_uiPassed,
                        g_Tests[nTestId].m_uiFailed );
        INFO(gPrintString);
        INFO("Press PB2 to skip past this failure\n");

        /* determine which round this test runs in, for example
            with 3 LEDs tests 1 through 7 are in round 1,
            tests 8 through 14 are round 2 and so on */
        nRound = nTestId / 7;
        if ( nTestId % 7 )
            nRound += 1;

        /* blink forever or if we are to ignore failures we break out after a while */
        while (1)
        {

            /* exit out of loop if pb1 pressed */
            if (g_button_1_pushed && nResult)
            {
                   g_button_1_pushed = 0;
                   return nResult;
            }
            /* we blink the test number once for each round so the user
               can determine which test failed since multiple tests use
               the same LED pattern such as tests 1, 8, 15, etc. */
            for ( n = 0; n < nRound; n++ )
            {
                Drive_LED_Bank( 0x0000);
                Delay(LED_BLINK_SLOW * 3);
                Drive_LED_Bank( states[test_indicator]);
                Delay(LED_BLINK_SLOW * 3);
            }

            /* long delay off after it blinks for each round */
            Drive_LED_Bank( 0x0000);
            Delay(LED_BLINK_SLOW * 18);

            /* if we are to ignore failures only blink a handful
                times, then return */
            m++;
            if ( (10 == m) && (IGNORE_FAILURES == g_Tests[nTestId].m_bIgnoreFailures) )
                return nResult;
        }
    }

    /* test passed */
    else
    {
        /* update count */
        g_Tests[nTestId].m_uiPassed++;

        /* display test stats */
        /* Test has always passed, no reported failures */
        if ( ( g_Tests[nTestId].m_uiPassed ) && !( g_Tests[nTestId].m_uiFailed ) )
        {
            sprintf(gPrintString,   _MAGENTATEXT_"\n\n%s: "_BOLDTEXT_""_GREENTEXT_"passed %d"_NORMALTEXT_"  failed %d",
                g_Tests[nTestId].m_pszName,
                g_Tests[nTestId].m_uiPassed,
                g_Tests[nTestId].m_uiFailed );
            INFO(gPrintString);
        }
        /* Test has always failed, no reported passes */
        else if ( !( g_Tests[nTestId].m_uiPassed ) && ( g_Tests[nTestId].m_uiFailed ) )
        {
            sprintf(gPrintString,  _MAGENTATEXT_"\n\n%s: "_NORMALTEXT_"passed %d  "_BOLDTEXT_""_REDTEXT_"failed %d"_NORMALTEXT_"",
                g_Tests[nTestId].m_pszName,
                g_Tests[nTestId].m_uiPassed,
                g_Tests[nTestId].m_uiFailed );
            INFO(gPrintString);
        }
        /* test has passed and failed */
        else
        {
            sprintf(gPrintString,   _MAGENTATEXT_"\n\n%s: "_BOLDTEXT_""_GREENTEXT_"passed %d"_NORMALTEXT_"  "_BOLDTEXT_""_REDTEXT_"failed %d"_NORMALTEXT_"",
                g_Tests[nTestId].m_pszName,
                g_Tests[nTestId].m_uiPassed,
                g_Tests[nTestId].m_uiFailed );
            INFO(gPrintString);
        }

    }

    return nResult;
}


int main()
{
/*
 *   Function:    main
 *   Description: This is the main entry point where everything starts.
 */

	int i = 0;                            /* index */
    bool bFirstTrip = true;                /* set first time through the loop only */
    bool bExit = false;                    /* flag indicating we should exit */
    ADI_PWR_RESULT    ePowerResult;
    uint32_t pclk;


    /* setup the M3 VTOR and System Control Block inits */
    SystemInit();

    /* demote all programmable interrupts from default highest priority level
       (0) to the lowest priority supported by the hardware so that we can
       promote other interrupts as needed (lower numbers mean higher priority)
    */
    for (IRQn_Type irq = RTC1_EVT_IRQn; irq < DMA0_CH23_DONE_IRQn; irq++)
        NVIC_SetPriority(irq, LOWEST_PRIORITY);

    /* promote UART above the others so we can report a live UART feed
       (even from other interrupts) during testing of pushbutton test
       selection interrupts, wakeup from hibernation interrupts, etc.
    */
    NVIC_SetPriority(UART0_EVT_IRQn, UART_PRIORITY);

     /* Power service Init */
    adi_pwr_Init();

    /* set peripheral clock for uart */
    if((ePowerResult = adi_pwr_SetClockDivider(ADI_CLOCK_HCLK, 1u)) != ADI_PWR_SUCCESS)
    {
        sprintf(gPrintString, "Could not set HCLK 0x%08X", ePowerResult);
        INFO(gPrintString);
        FAIL("bad clock");
        return(FAILURE);
    }

    if((ePowerResult = adi_pwr_SetClockDivider(ADI_CLOCK_PCLK, 1u)) != ADI_PWR_SUCCESS)
    {
        sprintf(gPrintString, "Could not set PCLK 0x%08X", ePowerResult);
        INFO(gPrintString);
        FAIL("bad clock");
        return(FAILURE);
    }




   /* test framework initialization */
    test_Init();

    /* Consolodated Pin Mux Init for all POST tests */
    if (adi_initpinmux())
    {
         FAIL("Failed to configure port I/O multiplexing.");
         return(FAILURE);
    }
    /* check peripheral clock */
    if((ePowerResult = adi_pwr_GetClockFrequency (ADI_CLOCK_PCLK, &pclk)) != ADI_PWR_SUCCESS)
    {
        sprintf(gPrintString, "Could not get PCLK 0x%08X", ePowerResult);
        INFO(gPrintString);
        FAIL("bad clock");
        return(FAILURE);
    }

    /* verify clock */
    if (EXPECTED_PCLK != pclk)
    {
        sprintf(gPrintString, "Expected PCLK clock different than actual 0x%08X", (uint16_t)pclk);
        INFO(gPrintString);
        FAIL("bad clock");
        return(FAILURE);
    }


    /* display some debug info */
    sprintf(gPrintString, "\n\n\n");
    INFO(gPrintString);
    HEAD( "ADuCM4x50 EZKIT Power-On Self-Test" );

    sprintf(gPrintString, "\nBuilt on %s, at %s", __DATE__, __TIME__);
    INFO(gPrintString);

    sprintf(gPrintString,  "Firmware version: %d", POST_VERSION);
    INFO(gPrintString);

    /* initialize our GP timer that us a timing interrupt every 1ms */
    Init_Timer();

    /* initialize pieces required to run POST */
    Init_PushButtons();
    Init_LEDs();

    /* loop forever */
    while (!bExit)
    {
        g_bIsTestChosen = false;
        g_nSelectedTest = 0;
        g_nPostState = STATE_START;

        /* check PB0 right away */
        /* if PB0 is pressed we want to enter the standard loop */
        if ( g_button_0_pushed && bFirstTrip )
        {
            g_nSelectedTest = 0x0;
            g_bIsTestChosen = true;
            g_nPostState = STATE_SELECTED;
        }

        /* else blink the LEDs while waiting for user to enter test via pushbuttons */
        sprintf(gPrintString,  _ITALICTEXT_""_CYANTEXT_"\n\nWaiting for a test to be selected...");
        INFO( gPrintString );
        
        Drive_LED_Bank( 0x0000 );

        /* drop into LED flash mode until we get a test chosen with the pushbuttons */
        Strobe_LEDs(0x44, 0x11, LED_STROBE_DELAY, &g_bIsTestChosen);

        Drive_LED_Bank( 0x0000 );

        /* make sure it's a valid test */
        if( g_nSelectedTest < NUM_POST_TESTS )
        {
            /* report the test selection */
            sprintf(gPrintString,  "Test %d \"%s\" selected\n", g_nSelectedTest, g_Tests[g_nSelectedTest].m_pszName );
            INFO(gPrintString);

            /* execute the test */
            do
            {
                g_bLoopFlagCheck = false;

                /*******************************************************
                       run test
                   *******************************************************/
                PerformTest( g_nSelectedTest );

                /* wait, then reset the LEDs */
                Delay(LED_BLINK_SLOW * 25);

                /* indicate everything passed */
                Drive_LED_Bank( 0x0000 );

                /* blink a few times to indicate the test is complete before looping */
                for (i = 0; i < 8; i++)
                {
                    Blink_LED_Bank( LED_BLINK_SLOW );
                }

            /* while we want to loop */
            } while ( g_bLoopOnTest && !g_bLoopFlagCheck );
        }

        /* else it's an unsupported test (or loop flag) */
        else
        {
            sprintf( gPrintString, "\n"_YELLOWTEXT_"Test %d is not a supported test"_NORMALTEXT_"", g_nSelectedTest );
            INFO(gPrintString);
        }

        bFirstTrip = false;        /* update flag */
    }

    INFO( "Exiting POST" );
}

/*
 *   Function:    Test_Standard_Loop
 *   Description: Runs each test that is part of the standard loop.
 */
int Test_Standard_Loop( void )
{
    bool bLoop = true;            /* flag to breakout for debug */
    bool bFirst = true;            /* first time flag */
    unsigned int test = 0;        /* test index */
    int i = 0;                    /* index */


    INFO( "\nStandard loop tests selected..." );

    /* loop on these tests forever */
    while ( bLoop )
    {
        /* start at 1 (skip standard loop test) or we end up in an infinite loop */
        for( test = 1; (test < NUM_POST_TESTS) && bLoop; test++ )
        {
            /* if part of standard loop */
            if ( g_Tests[test].m_bStandardLoop )
            {
                /* if first pass or not a one-time test we can run it */
                if ( bFirst || !(g_Tests[test].m_bOneTime) )
                {

                    /* run the test */
                    sprintf(gPrintString,  "\nRunning test %d \"%s\"...\n", test, g_Tests[test].m_pszName );
                    INFO(gPrintString);
                    PerformTest( test );

                    Delay(LED_BLINK_FAST * 20);

                    /* indicate everything passed */
                    Drive_LED_Bank( 0x0000 );

                    /* blink a few times to indicate the test is complete before looping */
                    for (i = 0; i < 4; i++)
                    {
                        Blink_LED_Bank( LED_BLINK_SLOW );
                    }
                }
            }

            if( g_button_1_pushed )
            {
                INFO( "<<< PB2 break out detected >>>" );
                g_button_1_pushed = false;
                bLoop = false;
            }
        }

        /* update flag and count */
        bFirst = false;
        g_loops++;

        /* indicate everything passed */
        Drive_LED_Bank( 0x0000 );
        Blink_LED_Bank( LED_BLINK_SLOW);
    }

    return SUCCESS;
}

/*
 *   Function:    Toggle_Loop_Flag
 *   Description: Toggles the loop flag which allows us to loop
 *                 continuously on a test or not.
 */
int Toggle_Loop_Flag(void)
{
    g_bLoopFlagCheck = true;            /* set flag so we don't run this test more than once */
    g_bLoopOnTest = !g_bLoopOnTest;        /* toggle the state of the loop flag */

    sprintf(gPrintString,  "Test loop flag state changed to %d", (int)g_bLoopOnTest );
    INFO(gPrintString);

    return SUCCESS;
}

/*
 *   Function:    Display_Post_Status
 *   Description: Prints out the status of the POST including pass and fail
 *                    counts for each test.
 */
int Display_Post_Status(void)
{
    int test = 0;

    INFO( "\nPOST stats:\n" );

    INFO( "     TEST NAME     PASS   FAIL   STD LOOP   ONE TIME   IGNORE" );
    INFO( "==============================================================" );

    /* only show status for implemented tests */
    for ( test = 1; test < NUM_POST_TESTS ; test++ )
    {
        sprintf(gPrintString,  "%16s   %3d    %3d        %d          %d         %d",
                 g_Tests[test].m_pszName,
                 g_Tests[test].m_uiPassed,
                 g_Tests[test].m_uiFailed,
            (int)g_Tests[test].m_bStandardLoop,
            (int)g_Tests[test].m_bOneTime,
            (int)g_Tests[test].m_bIgnoreFailures );
        INFO(gPrintString);
    }

    return SUCCESS;
}

/*
 *   Function:    BLINK_FW_VERSION
 *   Description: displays firmware version via LEDs
 */
int BLINK_FW_VERSION( void )
{
    int n = 0;                /* index */

    HEAD( "Blink Firmware Version" );

    sprintf(gPrintString,  "Built on %s, at %s", __DATE__, __TIME__ );
    INFO(gPrintString);

    sprintf(gPrintString,  "Firmware version: %d", POST_VERSION);
    INFO(gPrintString);

    /* blink the MAJOR rev on LED0 */
    for ( n = 0; n < POST_VERSION; n++ )
    {
        Drive_LED_Bank( 0x0000 );
        Delay(LED_BLINK_SLOW * 3);
        Drive_LED_Bank( TEST_1_SET );
        Delay(LED_BLINK_SLOW * 3);
    }

    /* delay */
    Drive_LED_Bank( 0x0000 );
    Delay(LED_BLINK_SLOW * 5);

    /* blink a bar to indicate we're done showing version */
    Drive_LED_Bank( 0x0000 );

    return PASS();
}

