
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
 * Description:     This examples tests the Real-Time Clock on the ADuCM4x50 EZKIT.
 */


/*=============  I N C L U D E S   =============*/


/* real time clock service include file */
#include <drivers/rtc/adi_rtc.h>
#include <drivers/pwr/adi_pwr.h>	
#include "post_common.h"

/* system time include file */
#include <time.h>

/**************************************************************

 Below are masks that are OR's into the final result, to 
 determine what specific things may have failed.
 
***************************************************************/
 

#define RTC_ALARM_OFFSET        5

#define ADI_RTC_NUM_ALARMS      3

uint8_t aRTCmem[ADI_RTC_MEMORY_SIZE];

#define LEAP_YEAR(x) (((0==x%4)&&(0!=x%100))||(0==x%400))

ADI_RTC_HANDLE hRTCDev;

volatile uint8_t nRTCIntCount=0;

#define RTC_DEVICE_NUM       0

void rtc_ReportTime(void) 
{
    char buffer[128];
    uint32_t nRtcCount;
    if(adi_rtc_GetCount(hRTCDev,&nRtcCount)!= ADI_RTC_SUCCESS)
    {
        FAIL("\n Failed to get the count");
        return;
    }
    sprintf (buffer, " Interrupt no : %d   RTC Count value  time: %04d",(uint16_t)nRTCIntCount,(uint16_t)nRtcCount);
    INFO(buffer);

}

uint32_t BuildSeconds(void)
{
    /* count up seconds from the epoc (1/1/70) to the most recient build time */

    char timestamp[] = __DATE__ " " __TIME__;
    int month_days [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint32_t days, month, date, year, hours, minutes, seconds;
    char Month[4];

    // parse the build timestamp
    sscanf(timestamp, "%s %d %d %d:%d:%d", (char *)Month, (int *)&date, (int *)&year, (int *)&hours, (int *)&minutes, (int *)&seconds);

    // parse ASCII month to a value
    if     ( !strncmp(Month, "Jan", 3 )) month = 1;
    else if( !strncmp(Month, "Feb", 3 )) month = 2;
    else if( !strncmp(Month, "Mar", 3 )) month = 3;
    else if( !strncmp(Month, "Apr", 3 )) month = 4;
    else if( !strncmp(Month, "May", 3 )) month = 5;
    else if( !strncmp(Month, "Jun", 3 )) month = 6;
    else if( !strncmp(Month, "Jul", 3 )) month = 7;
    else if( !strncmp(Month, "Aug", 3 )) month = 8;
    else if( !strncmp(Month, "Sep", 3 )) month = 9;
    else if( !strncmp(Month, "Oct", 3 )) month = 10;
    else if( !strncmp(Month, "Nov", 3 )) month = 11;
    else if( !strncmp(Month, "Dec", 3 )) month = 12;
    else month = 0;				
    // count days from prior years
    days=0;
    for (int y=1970; y<year; y++) {
        days += 365;
        if (LEAP_YEAR(y))
            days += 1;
    }

    // add days for current year
    for (int m=1; m<month; m++)
        days += month_days[m-1];

    // adjust if current year is a leap year
    if ( (LEAP_YEAR(year) && ( (month > 2) || ((month == 2) && (date == 29)) ) ) )
        days += 1;

    // add days this month (not including current day)
    days += date-1;

    return (days*24*60*60 + hours*60*60 + minutes*60 + seconds);
}

ADI_RTC_RESULT rtc_UpdateAlarm (void) {
    ADI_RTC_RESULT eResult;
    uint32_t rtcCount;
    
    if(ADI_RTC_SUCCESS != (eResult = adi_rtc_GetCount(hRTCDev,&rtcCount)))
    {
        FAIL("\n Failed to Get  the count ");
        return(ADI_RTC_FAILURE);
    }
    if(ADI_RTC_SUCCESS != (eResult = adi_rtc_SetAlarm(hRTCDev,rtcCount + RTC_ALARM_OFFSET)))
    {
        FAIL("\n Failed to set the alarm");
        return(ADI_RTC_FAILURE);
    }
    return(eResult);    
}

/* RTC-0 callback */
static void rtc1Callback(void* hWut, uint32_t Event, void* pArg)
{
    //adi_rtc_ClearInterruptStatus(hRTCDev,ADI_RTC_ALARM_INT);
    nRTCIntCount++;
    rtc_ReportTime();    
    rtc_UpdateAlarm();

}

int TEST_RTC_SET(void)
{
    ADI_RTC_RESULT eResult;    
    uint32_t nBuildTime,nRtcCount; 
    nRTCIntCount =0;
    
    INFO("Running RTC Test" );
    INFO("Three interrupts will be generated at the interval of 5 seconds\n");
   

      if(ADI_PWR_SUCCESS !=adi_pwr_EnableClockSource(ADI_CLOCK_SOURCE_LFXTAL,true))
     {
        return(ADI_PWR_FAILURE);
      }
    
    nBuildTime =  BuildSeconds();
    
   
    
    if((eResult = adi_rtc_Open(RTC_DEVICE_NUM,aRTCmem,ADI_RTC_MEMORY_SIZE,&hRTCDev))!= ADI_RTC_SUCCESS) {
        FAIL("Failed to open the device");
        return(FAILURE);
    }
    
    
    if((eResult = adi_rtc_RegisterCallback(hRTCDev,rtc1Callback,hRTCDev))!= ADI_RTC_SUCCESS) {
        FAIL("Failed to register the callback");
        adi_rtc_Close(hRTCDev);
        return(FAILURE);
    }
    
    if((eResult = adi_rtc_SetCount(hRTCDev,nBuildTime))!= ADI_RTC_SUCCESS) {
        FAIL("Failed to set the count");
        adi_rtc_Close(hRTCDev);
        return(FAILURE);
    }
  
    if((eResult = adi_rtc_EnableInterrupts(hRTCDev, ADI_RTC_ALARM_INT, true))!= ADI_RTC_SUCCESS) {
        FAIL("adi_RTC_EnableInterrupts failed");
        adi_rtc_Close(hRTCDev);
        return(FAILURE);
    }

    if((eResult = adi_rtc_EnableAlarm(hRTCDev, true))!= ADI_RTC_SUCCESS) {
        FAIL("adi_RTC_EnableAlarm failed");
        adi_rtc_Close(hRTCDev);
        return(FAILURE);
    }
    
    if((eResult = adi_rtc_GetCount(hRTCDev,&nRtcCount))!= ADI_RTC_SUCCESS) {
        FAIL("\n Failed to get the count");
        adi_rtc_Close(hRTCDev);
        return(FAILURE);
    }
        
    if((eResult = adi_rtc_SetAlarm(hRTCDev,(RTC_ALARM_OFFSET) + nRtcCount))!= ADI_RTC_SUCCESS) {
        FAIL("\n Failed to set the alarm");    
        adi_rtc_Close(hRTCDev);
        return(FAILURE);
    }
    

    
    if((eResult = adi_rtc_Enable(hRTCDev,true))!= ADI_RTC_SUCCESS) {
        FAIL("Failed to enable the device");    
        adi_rtc_Close(hRTCDev);
        return(FAILURE);
    }
     
    while(nRTCIntCount < ADI_RTC_NUM_ALARMS);

    if((eResult = adi_rtc_Enable(hRTCDev,false))!= ADI_RTC_SUCCESS) {
        FAIL("Failed to enable the device");    
        adi_rtc_Close(hRTCDev);
        return(FAILURE);
    }

    if((eResult = adi_rtc_Close(hRTCDev))!= ADI_RTC_SUCCESS) {
        FAIL("Failed to close the device");    
        return(FAILURE);
    }
    
    if( eResult == ADI_RTC_SUCCESS )
    	 return PASS();
    else
    {
       FAIL("TEST_RTC failed.");
       return(FAILURE);
    }
}


#ifdef _MISRA_RULES
#pragma diag(pop)
#endif
