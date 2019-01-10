
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
 * Description:     This examples tests the basic uart functionality on the ADuCM4x50 EZKIT.
 */


/*=============  I N C L U D E S   =============*/

#include <stdio.h>
#include <drivers/general/adi_drivers_general.h>
#include "post_common.h"
extern ADI_UART_HANDLE   hUartDebugTerm;


 //   #include <services/int/adi_int.h>
    #include <drivers\uart\adi_uart.h>

    /* Number of Tx and Rx buffers */
    #define NUM_BUFFERS     2

    /* UART Handle */
    static ADI_UART_HANDLE  ghUART;
#ifndef POST_COMMON_USES_UART
    /* Memory required for operating UART in interrupt mode */
	ADI_ALIGNED_PRAGMA(4)
    static uint8_t  gUARTMemory[UART_DEBUG_MEM_SIZE] ADI_ALIGNED_ATTRIBUTE(4);
#endif
    /* Rx and Tx buffers */
	ADI_ALIGNED_PRAGMA(4)
    static uint8_t RxBuffer[NUM_BUFFERS] ADI_ALIGNED_ATTRIBUTE(4);

    /* Flag which indicates whether to stop the program */
    static volatile bool gStopFlag = false;

    /* Tests Char Echo in blocking mode */
    static int32_t TestBlockingMode(void);



int TEST_UART(void)
{
    HEAD( "UART Test" );

	/* bypass this test if we're already using UART for debug output */
#ifdef POST_COMMON_USES_UART

	INFO("UART loopback test bypassed: UART tasked as debug monitor");
        ghUART = hUartDebugTerm;
	TestBlockingMode();
        return PASS();
#else

	INFO("Attach terminal emulator (9600-8-N-1) to USB-UART connector P6");

	/* return codes */
	ADI_UART_RESULT    eResult;

	while (1) {
		/* Initialize UART for bidirection, DMA mode use */
		if((eResult = adi_uart_Open(UART_DEBUG_DEV_ID,
									 UART_DEBUG_DIRECTION,
									 gUARTMemory,
									 UART_DEBUG_MEM_SIZE,
									 &ghUART)) != ADI_UART_SUCCESS)
		{
			FAIL("Could not open UART Device");
			return FAILURE;
		}

		/* Set uart config */
		if((eResult = adi_uart_SetConfiguration(ghUART,
												ADI_UART_NO_PARITY,
												ADI_UART_ONE_STOPBIT,
												ADI_UART_WORDLEN_8BITS
											 )) != ADI_UART_SUCCESS)
		{
			FAIL("Could not set UART config modes");
			break;
		}

		/* Run the UART echo test in blocking mode */
		if (TestBlockingMode())
		{
			FAIL("Char Echo Test in blocking mode failed");
			break;
		}
                Delay(10);
		if((eResult = adi_uart_Close(ghUART)) != ADI_UART_SUCCESS)
		{
			FAIL("Could not close UART");
			return FAILURE;
		}


		/* success */
		return PASS();
	}  /* end while*/

    /* "use" eResult to quiet compiler warnings */
    eResult += 1;

	/* faulure */
        adi_uart_Close(ghUART);
	FAIL("\nTEST_UART failed\n");
        return FAILURE;
#endif  /* test bypass */
 
}


/* Test char echo in blocking mode */
static int32_t TestBlockingMode(void)
{
    /* UART return code */
    ADI_UART_RESULT     eResult;
    uint32_t error;
    
    INFO("Testing UART character echo");
    INFO("Press ENTER key to exit test ");

    gStopFlag = false;

    while (gStopFlag == false)
    {
		/* Read a character */
      if((eResult = adi_uart_Read(ghUART,&RxBuffer[0],1,0,&error)) != ADI_UART_SUCCESS)
		{
			sprintf(gPrintString, "Could not do a UART read 0x%08X ", eResult);
    			FAIL(gPrintString);
			return FAILURE;
		}

		if(RxBuffer[0] == '\r')
		{
			gStopFlag = true;
		}

		/* Write back the character */
		if((eResult = adi_uart_Write(ghUART,&RxBuffer[0],1,0,&error)) != ADI_UART_SUCCESS)
		{
			sprintf(gPrintString, "Could not do a UART write 0x%08X ", eResult);
	    		FAIL(gPrintString);
			return FAILURE;
		}
    }

    return SUCCESS;
}
