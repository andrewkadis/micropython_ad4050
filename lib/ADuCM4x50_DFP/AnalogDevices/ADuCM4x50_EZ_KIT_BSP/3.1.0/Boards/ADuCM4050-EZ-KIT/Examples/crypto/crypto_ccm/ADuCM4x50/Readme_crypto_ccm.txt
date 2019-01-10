            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: crypto_ccm

Description:  Application example demonstrating the Crypto device driver in ccm cipher mode.
 

Overview:
=========
    This example demonstrates configuration of the Crypto device driver to perform a ccm
    cipher encrypt/decrypt operation.  
    
    The application performs the usual declarations and initializations, followed by a ccm crypto
	data transformation.
    
	For CCM, random data is used and decrypted results are verified against origional input data.

    Both callback and buffer query/get buffer management methods are supported.  Also, both DMA
    and PIO data transfer methods are supported.
    
    The Crypto driver has user configurable static build macros that are managed in the
    adi_crypto_config.h file found in the installation "ADuCM4x50_EZ_Kit\Include\config" directory. 
    All static configurations are set to their hardware (power-on-reset) values by default.

    See complete "Crypto Device Driver" module in the "ADuCM4x50 Device Drivers API Reference Manual"
    html documentation for full description of the Crypto Driver API and data structures.


User Configuration Macros:
==========================
	CRYPTO_ENABLE_CALLBACK
		This macro is controlled at the top of the crypto_example.c source file and controls use of
		application callbacks for obtaining buffer operation results, as well as event notifications.
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
    Load the project file, build, load and run the example.  Open the Terminal I/O window view to view output.
    

Expected Result:
=====================
	The example performs the following operations and reports progress to the Terminal I/O window:
		1. Encode and decode random data using CCM cipher mode.
		2. Readback and verify decoded, as well as authentication digest in CCM mode.
		3. On failure, look for failure-specific messages.
		4. On success, look for message:
			"All done! Crypto example completed successfully".
		
        
References:
===========
    ADuCM4x50 Hardware Reference Manual
