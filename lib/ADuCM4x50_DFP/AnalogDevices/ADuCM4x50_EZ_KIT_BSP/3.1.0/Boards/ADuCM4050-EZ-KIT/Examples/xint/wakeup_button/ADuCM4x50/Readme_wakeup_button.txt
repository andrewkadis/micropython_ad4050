         Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: wakeup_button

Description:  Demonstrates the use of XINT driver to Toggle LED when the 
              wakeup button is pressed on the ADuCM4x50 EZ-Kit.


Overview:
=========    
    This example uses the XINT driver to configure the wakeup button 
    (GPIO input) and LED's (GPIO output) on the ADuCM4x50 EZ-Kit.  The 
    External interrupt driver is used to configure for generating interrupt 
    when the push button is pressed. The SW3 (wakeup button)
    callback is used to toggle the LED4.

User Configuration Macros:
==========================
    None.
        
Hardware Setup:
===============
    ADuCM4x50-EZ-Kit should be configured with default settings jumper 
    settings. Please refer ADuCM4050 EZ-Kit Manual for default 
    jumper settings.

External connections:
=====================
    None.
    
How to build and run:
=====================    
    Prepare hardware as explained in the Hardware Setup section.
    Build the project, load the executable to ADuCM4x50, and run it.

Expected Result:
=================    
    Press SW3 (Wakeup button) and observe LED4 toggle.

References:
===========
    ADuCM4x50 Hardware Reference Manual
