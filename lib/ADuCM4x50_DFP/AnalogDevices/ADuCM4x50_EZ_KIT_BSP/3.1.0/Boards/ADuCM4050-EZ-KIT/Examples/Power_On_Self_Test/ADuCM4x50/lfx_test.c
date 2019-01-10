/*
 *  (C) Copyright 2016 - Analog Devices, Inc. All Rights Reserved.
 *
 * This software is proprietary and confidential.  By using this software
 * you agree to the terms of the associated Analog Devices License Agreement.
 *
 * Project Name:        Power_On_Self_Test
 *
 * Hardware:                ADuCM4x50 EZKIT
 *
 * Description:     This examples tests the LFX crystal on the ADuCM4x50 EZKIT.
 */




/*==========  I N C L U D E  ==========*/

#include <stddef.h>
#include <stdio.h>   
#include <string.h> 
#include "post_common.h"
#include <drivers/pwr/adi_pwr.h>





int TEST_LFX (void)
{

     ADI_PWR_RESULT eResult;
     ADI_CLOCK_SOURCE_STATUS clock_status;

    HEAD("LFX Test");

    INFO("Testing normal mode first ");

    if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_EnableClockSource(ADI_CLOCK_SOURCE_LFXTAL,true)))
    {
      return(eResult);
    }
    Delay(2000); // 2 seconds
    if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_GetClockStatus(ADI_CLOCK_SOURCE_LFXTAL,&clock_status)))
    {
      FAIL("Can't get clock status");
      return(eResult);
    }
    if (clock_status != ADI_CLOCK_SOURCE_ENABLED_STABLE) {
        FAIL("Normal lfx not stable");
        return (FAILURE);
    }

    INFO("Testing Robust mode ");
    // turn it off
    if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_EnableClockSource(ADI_CLOCK_SOURCE_LFXTAL,false)))
    {
      return(eResult);
    }

    //wait for it to go off
    while (clock_status == ADI_CLOCK_SOURCE_ENABLED_STABLE) {
        if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_GetClockStatus(ADI_CLOCK_SOURCE_LFXTAL,&clock_status)))
        {
          FAIL("Can't get clock status");
          return(eResult);
        }
    }
    // now put it in robust mode
    if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_EnableLFXTALRobustMode(true)))
    {
      FAIL("Can't set robust mode ");
      return(eResult);
    }

    // Select 5Mohm Load
    if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_SetLFXTALRobustModeLoad(ADI_PWR_LFXTAL_LOAD_5MOHM)))
    {
      FAIL("Can't select load ");
      return(eResult);
    }

    // turn it on
    if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_EnableClockSource(ADI_CLOCK_SOURCE_LFXTAL,true)))
    {
      FAIL("Can't enable clock source ");
      return(eResult);
    }

    Delay(2000); // 2 seconds

    // see if it is stable

    if(ADI_PWR_SUCCESS !=(eResult =adi_pwr_GetClockStatus(ADI_CLOCK_SOURCE_LFXTAL,&clock_status)))
    {
      FAIL("Can't get clock status");
      return(eResult);
    }
    if (clock_status != ADI_CLOCK_SOURCE_ENABLED_STABLE) {
        FAIL("Robust lfx not stable");
        return (FAILURE);
    }

    return(SUCCESS);
}

