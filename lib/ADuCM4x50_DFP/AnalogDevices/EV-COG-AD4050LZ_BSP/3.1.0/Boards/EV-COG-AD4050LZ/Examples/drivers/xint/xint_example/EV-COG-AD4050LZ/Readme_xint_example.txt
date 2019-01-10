         Analog Devices, Inc. EV-COG-AD4050LZ Application Example

Project Name: xint_example

Description:
============
  Demonstrates the use of XINT driver.


Overview:
=========
    This example demonstrates how the XINT driver can be used to trigger an
    interrupt on a push button.

User Configuration Macros:
==========================
    EXAMPLE_TIMEOUT_SEC - The number of seconds to wait for the push-button
                          before terminating the example.

Hardware Setup:
===============
    JP8 must be in Position A.  This is the default position, so no hardware
    changes should be necessary.

External connections:
=====================
    None.

How to build and run:
=====================
    Build the project and download using the debugger.

Expected Result:
=================
On a successful run of the program, the following message will be printed:

		Push BTN1 to trigger an external interrupt.

		Push button pressed!

		All done!

On an unsuccessful run of the program, the following message will be printed:

		Push BTN1 to trigger an external interrupt.

		Failed: You did not press BTN1 before timeout.

References:
===========
    ADuCM4x50 Hardware Reference Manual
