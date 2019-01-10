         Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: beeper_example    

Description: Example to show the basic functionality of the beeper peripheral.
  
Overview:
=========
  This example demonstrates how to configure and use the beeper to produce a range 
  of audible outputs.  

  The example has some configuration macros that can modify the output.  By
  default, the example will play a note, then a two-tone alarm, and then play
  a short sequence of varying notes.

  In the example, a callback is registered, but it is not essential for using the
  beeper. Once each playback setting has started, the adi_beep_Wait() API is used
  to block until the Note/Sequence is complete.  An alternative would be to use
  a flag or setting in the callback to indicate completion to the application.

User Configuration Macros:
==========================
  In beeper_example.c:
  PLAY_NOTE    Set to 1 will play a single-note beep.
  PLAY_ALARM   Set to 1 will play a short two-tone alarm.
  PLAY_TUNE    Set to 1 will play a short sequence of notes.
  By default, all these are set to 1.

  In adi_beep_config.h, the following macro can be used to enable/disable the 
  support for play sequences of notes (required when playing short tunes).  If 
  this feature is not required, then it can reduce footprint and execution time
  of the beep driver. Setting this to 0 disables the support for play 
  sequences:
  ADI_BEEP_INCLUDE_PLAY_SEQUENCE

Hardware Setup:
===============
  ADuCM4x50 EZ Kit configured with default settings.
    
External connections:
=====================
  None.
  
How to build and run:
=====================
  Build the project, load the executable to ADuCM4x50, open a "Terminal 
  Window" and run it.
    
Expected Result:
=================
   If successful, you will hear a range of sounds.  The application will
   finish by printing the following in the Terminal I/O window:
   "
   Beep example completed successfully
   All done!
   "
   
References:
===========
    ADuCM4x50 Hardware Reference Manual
