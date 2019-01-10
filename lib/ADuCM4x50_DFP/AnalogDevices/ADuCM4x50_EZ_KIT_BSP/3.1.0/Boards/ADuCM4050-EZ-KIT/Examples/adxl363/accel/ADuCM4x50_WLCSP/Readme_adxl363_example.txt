            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: accelerometer

Description:  Demonstrate how to use the ADXL363 driver to produce interrupts
on activity events.
 

Overview:
=========
    In this example, the ADXL363 driver is used to configure the ADXL363 to 
    produce an interrupt when enough activity is detected on the accelerometer.
    The interrupt will be serviced, the X-Y-Z values will be printed to the
    terminal, along with some information about the interrupt received.
    
    The example uses a LOOP mode of operation - so a period of activity must
    be followed be a period of inactivity for the example to progress.
    

User Configuration Macros:
==========================
    Test configuration in adxl363_accel.c: 
    TEST_ITERATIONS can configure the number of times the example loops.
    
    Hardware configuration in adxl363_accel.c:
    ADXL363_INTx_GPIO_PORT can specify which GPIO port to configure for INT1 or INT2 
    ADXL363_INTx_GPIO_PIN  can specify which GPIO pin to configure for INT1 or INT2

    Hardware configuration in adi_adxl363_config.h:
    ADXL363_CFG_SPI_DEV_NUM and ADXL363_CFG_SPI_DEV_CS to set the SPI and chip select lines used.
    
Hardware Setup:
===============
    None.
 
External connections:
=====================
    None.

How to build and run:
=====================
    Build the project and download to a single ADuCM4x50 target. Open the output terminal and run.
	
	Note: The project has to be run to completion, indicated by "all done!". If the project run
		  is stopped midway, then SYSTEM RESET/POWER CYCLE is required to reset the adxl363.

Expected Result:
=====================
    The following should be printed to the terminal:
      "Tilt the device
       Got Data X = 0x0061, Y = 0x0013, Z = 0x045f
       Activity detected
       Inactivity detected
       Got Data X = 0x0030, Y = 0x0040, Z = 0x0473
       Awake
       ...
       All done!"

References:
===========
    ADuCM4x50 Hardware Reference Manual
