            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: tmr_example_rgb

Description:  Demonstrate how to use the Red-Green-Blue (RGB) timer to generate 3 PWM output signals with the same period but different duty cycles.
 

Overview:
=========
    In this example, the RGB timer is configured to timeout every 1 second. Please refer to the GP timer example for how to configure
    the timers for a specific timeout period, the RGB is the same as the GP timers for basic hardware timer and event configuration. 
    Unlike the GP timer example, this example shows how to use the timer driver API and configuration data structures to generate 3
    pulse width modulation (PWM) signals using the RGB timer. The PWM outputs have a 10%, 25%, and 20% duty cycles respectively. It is 
    important to note that GPIO pinmuxing is required to actually view these signals on output pins. The example runs for a user 
    configurable amount of time.

    The user can probe the PWM output pins listed below or view the on-board RGB LED to confirm the test is running as expected. 

User Configuration Macros:
==========================
    EXAMPLE_TIME (tmr_example_rgb.h) - This macro can be used to control how long the example should run before finishing.

Hardware Setup:
===============
    None.
 
External connections:
=====================
    To view the PWM signals with a probe, this example requires the ADZ-BRKOUT-EX3 extender card. This product does
    not come with the ADuCM4050 EZ-Kit and can be purchased online. Once the extender card is obtained, make the 
    following connections:
    * Connect J1 of the ADZ-BRKOUT-EX3 to P1A of the ADuCM4050 EZ-Kit.

    Then connect the probe or logic analyzer to the following pins:
    * P5.82 (RGB0_PWM0)
    * P5.84 (RGB0_PWM1)
    * P5.83 (RGB0_PWM2)

How to build and run:
=====================
    Build the project and download to a single ADuCM4x50 target. Open the output terminal and run.

Expected Result:
=====================
    The string "All done!" should be printed to the terminal. The expected LED pattern is a combination 
    of red, green, and blue blinking at a frequency of 1 second.

 
References:
===========
    ADuCM4x50 Hardware Reference Manual
