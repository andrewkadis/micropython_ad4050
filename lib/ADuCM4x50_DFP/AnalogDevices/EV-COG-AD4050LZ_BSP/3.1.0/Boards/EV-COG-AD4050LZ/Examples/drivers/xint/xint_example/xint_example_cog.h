/*********************************************************************************
   @file:   xint_example_cog.h
   @brief:  User configuration macros for XINT example.
 -------------------------------------------------------------------------------

Copyright(c) 2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/


#ifndef XINT_EXAMPLE_COG_H
#define XINT_EXAMPLE_COG_H


/*! Number of seconds to wait for a button press before timing out */
#define EXAMPLE_TIMEOUT_SEC (10)


/*! Macro validation */
#if (1000*EXAMPLE_TIMEOUT_SEC > 0xFFFFFFFF)
#error "Requested timeout will overflow 32-bit integer"
#endif


#endif /* XINT_EXAMPLE_COG_H */
