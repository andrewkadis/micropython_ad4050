
            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: Power On Self Test (POST)

Description:  Application example with manufacturing tests for the EZ-KIT 

Overview:
=========
	This example allows the user to test the many peripherals of the EZ-Kit.  This example is also 
	pre-programmed into the on-board flash memory.  By following the directions below you can also 
	program this example (or one of your own) into the ADuCM4040 EZ-Kit flash. 

	POST was designed so that you can use the EZ-Kit push buttons to select a specific test to run.
	Any failures will  blink the failing test code and stop further testing until reset.


User Configuration Macros:
==========================`
	POST_COMMON_USES_UART 
		This will redirect the output to UART terminal. Remove this symbol to output the string to 
		console window output methods. Output is directed to UART by default.Hyper terminal setting 
		is as below:
			9600 baud, 8 data bits, no parity, 1 stop bit, no flow control
	EZKIT_REV_1_0
		This macro must match the board revision
					
					
Hardware Setup:
===============
	ADuCM4050-EZ-Kit configured with default settings with following jumper installation.
		JP1  - Connect jumper between pins
		JP2  - Connect jumper between pins
		JP3  - Connect jumper between pins
		JP4  - Connect jumper between pins
		JP5  - Connect jumper between pins
		JP6  - Connect jumper between pins
		JP7   - Not connected.
		JP8   - Not connected.
		JP9   - Connect jumper between pins
		JP10  - Connect jumper between pins 1 and 2. Rest open
		JP11  - Connect jumper between pins 1 and 2. Rest open
		JP12  - Connect jumper between pins 3 and 4. Rest open
		JP13  - Connect jumper between pins
		JP14  - Connect jumper between pins 1 and 3. Rest open
		JP15  - Connect jumper between pins 1 and 3. Also connect jumper between pins 2 and 4.
		JP16  - Not connected.
		JP17  - Not connected.
		JP18  - Connect jumper between pins

	Redirecting the output to UART terminal

		On the ADuCM-4050 EZ-Kit, the UART output is processed by the FTDI 
		FT232R USB-to-UART interface chip (and associated Virtual COM Port (VCP) Software 
		Drivers on the host side) incorporated on the evaluation board. The FTDI chip 
		uses a device driver to extract the USB stream back to a UART COM port on the
		host for capture by a terminal emulator using default "9600-8-N-1" settings.
		See the FTDI device and driver links following for installation guide, Application
		Notes and documentation on the FTDI products:

		http://www.ftdichip.com/Products/ICs/FT232R.htm -- FTDI device information
		http://www.ftdichip.com/Drivers/VCP.htm         -- FTDI driver information

External connections:
=====================
        Either a UART or an emulator connection is required, depending on the output choice.
  
How to build and run:
=====================
	Load the project file to build and load the example.

			
	Open a UART console utility such as Tera Term with the following settings:

		Baud:   9600
		Data:   8 bits 
		Parity: None
		Stop:   1 bit
		Flow Control: None

	Load the executable and run it.
		
		Selecting Tests 
			
			POST uses a pushbutton sequence to select individual tests.  It requires the
			user to enter a 5 button sequence to choose a test.  In the PB sequence in the 
			chart below, pressing a 0 refers to SW4(PB1), and pressing a 1 refers to SW5(PB2).

			Note that POST allows the user to run multiple tests without resetting the
			board.  After a test runs successfully, it will return to the standard blinking
			pattern.  At this time the user may choose to run another test.  

			The user can loop through all the tests by selecting the standard loop --        
                        sequence 0-0-0-0-0. The user can interrupt the loop by pressing PB2.

			The table below is also in main.c 

========================================================================================================
                        | PART OF |ONE  |IGNORE|   TEST NAME      |        |   PB   |  LEDS | blinks on
    TEST FUNCTION       | STANDARD|TIME?|FAILS?| 15 CHARS + NULL  | TEST # |sequence| [3:1] |  failure
                        | LOOP?   |     |      |123456789ABCDEF0  |        |        |       |        
========================================================================================================
Test_Standard_Loop,        true,   false, false, "Standard Loop"  |      0 |  00000 |  000  |  one time
TEST_VERSION,              true,   false, false, "Proc Version"   |      1 |  00001 |  001  |  one time
TEST_PBLED,                true,   true,  false, "Pushbuttons/LED"|      2 |  00010 |  010  |  one time
TEST_UART,                 true,   true,  false, "UART"           |      3 |  00011 |  011  |  one time 
TEST_BEEPER,               true,   true,  false, "Beeper"         |      4 |  00100 |  100  |  one time 
TEST_SPI_FLASH,            true,   false, false, "SPI Flash"      |      5 |  00101 |  101  |  one time
TEST_SPI_ACCELEROMETER,    true,   true,  false, "SPI Accel"      |      6 |  00110 |  110  |  one time
TEST_RGB,                  true,   false, false, "RGB Timer Test" |      7 |  00111 |  111  |  one time
 --------------------------------------------------------------------------------------------------------
TEST_TWI_TEMP,             true,   false, false, "TWI Temp"       |      8 |  01000 |  001  | two times 
Test_Dummy_Pass,           false,  false, true,  "Not Used #9"    |      9 |  01001 |  010  | two times
TEST_WAKEUP,               true,   true,  false, "Wakeup"         |     10 |  01010 |  011  | two times
TEST_ADC,                  true,   true,  false, "ADC"            |     11 |  01011 |  100  | two times
TEST_RTC_SET,              true,   false, false, "RTC Clk Set"    |     12 |  01100 |  101  | two times
Test_Dummy_Fail,           false,  false, false, "Not Used #13"   |     13 |  01101 |  110  | two times
Test_Dummy_Fail,           false,  false, false, "Not Used #14"   |     14 |  01110 |  111  | two times
 --------------------------------------------------------------------------------------------------------
Test_Dummy_Fail,           false,  false, false, "Not Used #15"   |     15 |  01111 |  001  | three times
BLINK_FW_VERSION,          true,   false, false, "Display FW Ver" |     16 |  10000 |  010  | three times
TEST_LFX,                  true,   false, true,  "LFX"            |     17 |  10001 |  011  | three times
Test_Dummy_Fail,           false,  false, true,  "Not Used #18"   |     18 |  10010 |  100  | three times
Display_Post_Status,       true,   false, false, "Display Status" |     19 |  10011 |  101  | three times
Test_Dummy_Fail,           false,  false, true,  "Not Used #20"   |     20 |  10100 |  110  | three times
Toggle_Loop_Flag,          false,  false, false, "Toggle LoopFlag"|     21 |  10101 |  111  | three times
---------------------------------------------------------------------------------------------------------


References:
===========
	ADuCM4x50 Hardware Reference Manual
	ADuCM4050 WLCSP EZ-Kit Manual
	ADuCM4050 LFCSP EZ-Kit Manual
	ADuCM4050 WLCSP EZ-Kit Schematic
	ADuCM4050 LFCSP EZ-Kit Schematic

			
