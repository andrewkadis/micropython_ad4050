            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: temperature_sensor

Description:  Application example demonstrating I2C device and driver communication to read the ADI ADT7420 temperature sensor.
 

Overview:
=========
    This example demonstrates configuration of I2C device driver to read the external ADI ADT7420
    temperature sensor and report the current device temperature to the Terminal I/O window in the
    debugging view.
    
    The application performs the usual declarations and initializations, followed by a pseudo "while"
    test loop that "tries" various API calls and breaks out on failures.  Successful calls stay in
    the loop until the end loop, whereupon SUCCESS is seen.
    
    The test "loop" opens and resets the I2C driver and I2C hardware.  It then configures the I2C
    bitrate, sets the slave device I2C address (0x48), does a few key register reads and then reads
    the two temperature registers, computes and prints the corresponding temperature values.
    
    The I2C driver takes care of both the transaction "prologue" and "data" phases and I2C interrupt
    processing.
    
    The I2C driver has user configurable static build macros that can be managed in the adi_i2c_config.h
    file found in the installation "ADuCM4x50_EZ_Kit\Include\config" directory. 

    See complete "I2C Device Driver" module in the "ADuCM4x50 Device Drivers API Reference Manual"
    html documentation for full description of the I2C API and data structures.


User Configuration Macros:
==========================
    DATASIZE: This macro controls the maximum transmit and receive data buffer sizes used in the example.
              The example as configured reads only two bytes; the two temperature values.


Hardware Setup:
===============
    Jumper JP5 is required to be installed, providing power to the ADI ADT7420 temperature sensor.
    Otherwise, no other user-configurable jumper settings are required.  The sensor is hardwired on the
    ADuCM4x50_EZ_Kit to I2C physical slave address 0x48.
    
 
External connections:
=====================
    Emulator connection required.  	This test requires a live debugger session to run because it uses
    semi-hosted printf output to write to the Terminal I/O window.  Therefore, the test will hard fault
    on the first printf write attempt if no debugger is attached.  This can be seen on the logic analyzer
    as a failure in steps 2 and 3, below, due to the missing debugger interrupt handler (i.e., emulator
    attached) to handle the semi-hosted printf calls (debugger interrupts).



How to build and run:
=====================
    Load the project file, build, load and run the example.  Open the Terminal I/O window view to view output.
    Specifically:
    

Expected Result:
=====================
	The example performs the following operations:
		1. Reads/displays the ADT7420 device ID register,
		2. Reads/displays the ADT7420 device configuration register,
		3. Reads/computes/displays the ADT7420 device temperature,
		4. Prints either "SUCCESS" or "FAILURE" (with result code) and exits main.

    After which, the terminal I/O Window should show something like:

		Chip ID register content is: 0xcb
		Config register content is: 0x00
		temp reading is:  22.6 degrees C
		temp reading is:  72.7 degrees F
		result = 0x0000
    
        
References:
===========
    ADuCM4x50 Hardware Reference Manual
