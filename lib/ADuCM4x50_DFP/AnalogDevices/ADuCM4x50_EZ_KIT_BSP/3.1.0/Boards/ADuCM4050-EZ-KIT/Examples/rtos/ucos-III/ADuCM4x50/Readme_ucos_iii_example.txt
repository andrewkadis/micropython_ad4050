            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: rtos_ucos_iii_example

Description:  Demonstrates uCOS-III RTOS in ADuCM4x50 processors. This example
              demonstrates task and semaphore creation and context switching.

              This example has not been ported to CCES.

Overview:
=========
    This example creates a "crypto" task, a LED switch on task and a LED switch
    off task.  The crypto task does the encryption and decryption of a
    block in a loop. The task switches on the LED before encryption and
    switches it off before decryption. The crypto task posts a semaphore to
    the LED control task to do the operation.

    This example uses a modified icf file since it needs more SRAM data memory.

    This example uses a unified ucos-iii Cortex-M Port folder which was
    released by Micrium in version 3.06.00 of the kernel.  The structure of the
    port for previous versions was deprecated and not supported here.

    Version 3.06.00 of uCOS-III requires the following minimum versions:
    * uC-CPU V1.31.00
    * uC-LIB V1.38.02

Hardware Setup:
===============
    ADuCM4x50-EZ-Kit should be configured with default settings jumper
    settings. Please refer ADuCM4050 EZ-Kit Manual for default
    jumper settings.

External connections:
=====================
    None.

Environment Setup for IAR:
==========================
    Environment variable 'ADUCM4x50_MICRIUM_DIR' should be set to the Software
    folder under the Micrium sources(i.e C:\Micrium\Software).
	
	Environment Variable Value
	 
    ADUCM4x50_MICRIUM_DIR        The full path to the source directory. E.g.
                                      C:\Micrium\Software
	
	
Keil:
=====
    For Keil toolchain, Generic Micrium RTOS should be installed 
	to get uCOS-III kernal and support files
	Install : CMSIS Pack Manager -> Generic -> Micrium::RTOS

CCES:
=====
	This example has not been ported to CCES

How to build and run:
=====================
    Prepare hardware as explained in the Hardware Setup section.
    Build the project, load the executable to ADuCM4x50, and run it.

Expected Result:
=====================
	Observe that LED-4 keep blinking when the task is running being done.
    Look for the debug information displayed on terminal I/O.
    The example should print All done! in about  10 seconds.

References:
=====================
    ADuCM4x50 Hardware Reference Manual
