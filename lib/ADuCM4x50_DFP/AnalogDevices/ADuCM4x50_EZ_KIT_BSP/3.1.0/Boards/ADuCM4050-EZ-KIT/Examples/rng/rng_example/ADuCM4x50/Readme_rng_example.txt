

         Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: RNG Example

Description: This example demonstrates how to configure the random number
             generator to generate random numbers.



Overview:
=========
The example configures the random number generator, collects random numbers from
the device and prints them to the terminal.
For more information on driver modes of operation please refer to the driver API
documentation.


User Configuration Macros:
==========================
Set RNG_ENABLE_CALLBACK to 1 to enable callback mode.
Set NUM_RANDOM_NUMS to indicate how many random numbers should be calculated.

Hardware Setup:
===============
None required.

External connections:
=====================
None.

How to build and run:
=====================
1.	Prepare hardware as explained in the Hardware Setup section.
2.	Build the project, load the executable to the EZ-Kit, and run it
3.	Look for the debug information displayed on terminal I/O window

Expected Result:
=================
A set of random numbers are printed in the terminal and to finish the example
the example prints "All done".
References:
===========
    ADuCM4x50 Hardware Reference Manual.
