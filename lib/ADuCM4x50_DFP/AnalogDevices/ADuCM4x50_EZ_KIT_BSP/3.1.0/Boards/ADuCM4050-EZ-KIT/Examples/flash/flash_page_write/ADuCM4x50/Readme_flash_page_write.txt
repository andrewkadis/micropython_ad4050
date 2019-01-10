            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: flash_page_write

Description:  Application example demonstrating the Flash device driver writing data to flash memory.
 

Overview:
=========
    This example demonstrates configuration of the Flash device driver to write a page of data
    into the flash user-space memory.  Results are reported to the terminal.
    
    The application performs the usual declarations and initializations, followed by a write of
    random data to the internal flash memory which is then verified.
    
    Both callback and buffer query/get buffer management methods are supported.  Also, both DMA
    and PIO data transfer methods are supported.
    
    The flash driver has user configurable static build macros that are managed in the
    adi_flash_config.h file found in the installation "ADuCM4x50_EZ_Kit\Include\config" directory. 
    All static configurations are set to their hardware (power-on-reset) values by default.

    See complete "Flash Device Driver" module in the "ADuCM4x50 Device Drivers API Reference Manual"
    html documentation for full description of the Flash API and data structures.


User Configuration Macros:
==========================
    FEE_DEV_NUM:
    	This macro identifies the flash controller device instance.  Since there is only a single
    	instance of the flash controller, this macro is fixed to zero.
    
    PAGE_ADDR:
    	The flash test page address to which the test data is written.  Make sure this value does
    	not impinge on user (test) code.
    
	BUFF_SIZE:
		The amount of data to write to the test page.  Set to 2k, which spans a full page.
	
	FEE_ENABLE_CALLBACK
		This macro is controlled at the top of the flash_page_write.c example source file and
		controls use of application callbacks for obtaining write operation results.
		Enable this macro to test with callbacks, disable it to test with buffer query/get calls.
	

Hardware Setup:
===============
There is no special hardware setting to manage other than default jumper settings for the EZ-Kit.
    
 
External connections:
=====================
    Emulator connection required. This test requires a live debugger session to run because it uses
    semi-hosted printf output to write to the Terminal I/O window. Therefore, the test will hard fault
    on the first printf write attempt if no debugger is attached.
    
    No other external connections are required.



How to build and run:
=====================
    Open the project, build, load and run the example.  Open the terminal to view output.

Expected Result:
=====================
	The example performs the following operations:
		1. Erase target page flash memory.
		2. Write target page flash memory with random data.
		3. Readback and verify target data write.
		4. Prints "All Done!" if success or Failure message (with result code and message) and exits.
		
    NOTE: If flash_block_protect has been run before, then HARDWARE RESET is required to execute flash_page_write successfully.    
References:
===========
    ADuCM4x50 Hardware Reference Manual
