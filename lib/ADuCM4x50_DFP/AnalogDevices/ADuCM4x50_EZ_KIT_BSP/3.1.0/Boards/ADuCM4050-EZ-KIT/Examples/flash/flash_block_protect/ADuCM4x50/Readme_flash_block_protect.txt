            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: flash_block_protect

Description:  Application example demonstrating use of Flash device driver memory protections.
 

Overview:
=========
    This example demonstrates configuration of the Flash device driver to protect a block of memory
    after having written a page of data to it.  The data is written, verified, and then protected.
    The protected memory is then verified that it survives an attempted page erase.  Results are
    reported to the terminal.
    
    Because of an unusual side-effect, the memory protection is gated by a user requirement to press
    a pushbutton within a fixed timeout period.  Pushbutton PB2 (SW5) is used for this purpose.
    Pressing the pushbutton within the timeout period enables the block write protection.  Allowing
    the timeout to expire without a pushbutton press bypasses the write protection.
    
    The write protection is gated because:  Flash-based code that write-protects blocks will cause the
    write-protection (and data at time of write-protect assertion) to apparently not clear... even after
    a mass erase or power-on-reset.  This apparently "stuck" write-protection results from the flash-based
    write-protect code running after reset (as usual), but still prior to the debugger halting the target
    through the debug interrupt.  The debugger target halt occurs WELL AFTER the flash code has already
    run, thereby relocking the block and making it appear the write-protection was never reset.  This can
    be difficult Catch-22 situation to recover from, requiring repeated hardware resets and reflashing new
    code that does not assert the write-protection.
    
    NOTE: Processor requires a HARDWARE RESET to clear write-protection.
    
    The application performs the usual declarations and initializations, followed by a write of
    random data to the internal flash memory which is then verified.
    
    Both callback and buffer query/get buffer management methods are supported.  Also, both DMA
    and PIO data transfer methods are supported.
    
    The flash driver has user configurable static build macros that are managed in the
    adi_flash_config.h file found in the installation "ADuCM4x50_EZ_Kit\Include\config" directory. 
    All static configurations are set to their hardware (power-on-reset) values by default.

    See complete "Flash Device Driver" module in the "ADuCM4x50 Device Drivers API Reference Manual"
    html documentation for full description of the I2C API and data structures.


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
		This macro is controlled at the top of the flash_block_protect.c example source file and
		controls use of application callbacks for obtaining write operation results.
		Enable this macro to test with callbacks, disable it to test with buffer query/get calls.
	

Hardware Setup:
===============
There is no special hardware setting to manage other than default jumper settings for the EZ-Kit.
    
 
External connections:
=====================
    Emulator connection required.  	This test requires a live debugger session to run because it uses
    semi-hosted printf output to write to the Terminal I/O window.  Therefore, the test will hard fault
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
		4. Await a pushbutton to perform the block write-protect.
		5. If a block is write-protected, try to erase the protected page and verify the erase attempt fails.
		6. Readback (again) and reverify the target data write is still intact.
		7. Prints either "All Done!", if success or "FAILURE" (with result code and message) and exits.
		
    NOTE: HARDWARE RESET(RESET and SYSTEM-POWER-CYCLE) required to clear flash block write-protect.    
References:
===========
    ADuCM4x50 Hardware Reference Manual
