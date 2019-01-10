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
 * Description:     This examples tests the beeper on the ADuCM4x50 EZKIT.
 */


/*==========  I N C L U D E  ==========*/

#include <stdio.h>
#include <drivers/pwr/adi_pwr.h>
#include <drivers/beep/adi_beep.h>
#include <drivers/general/adi_drivers_general.h>
#include "post_common.h"

/* prototypes */
extern int32_t   adi_initpinmux (void);
ADI_BEEP_RESULT  beep_Init      (void);
ADI_BEEP_RESULT  beep_Start     (void);
void             beepCallback(void *pCBUnused, uint32_t Event, void *pvUnused);

/* Device handle */
ADI_BEEP_HANDLE hBeep = NULL;

/* required beeper driver memory */
ADI_ALIGNED_PRAGMA(4)
uint8_t BeepMemory[ADI_BEEP_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);          

/* Basic functionality */
#define PLAY_NOTE     1
#define PLAY_ALARM    1
#define PLAY_TUNE     1

/* Local functions to perform, and check, each action. */
ADI_BEEP_RESULT PlayOne(void);
ADI_BEEP_RESULT PlayAlarm(void);
ADI_BEEP_RESULT PlayTune(void);

/* the playlist */
#if PLAY_TUNE == 1
ADI_BEEP_NOTE playList1[] = {
    /* Close Encounters: D-E-C-C(octave lower)-G */
    { ADI_BEEP_FREQ_D6,        ADI_BEEP_DUR_16_32 },
    { ADI_BEEP_FREQ_E6,        ADI_BEEP_DUR_16_32 },
    { ADI_BEEP_FREQ_C6,        ADI_BEEP_DUR_16_32 },
    { ADI_BEEP_FREQ_C5,        ADI_BEEP_DUR_16_32 },
    { ADI_BEEP_FREQ_G5,        ADI_BEEP_DUR_32_32 },
    { ADI_BEEP_FREQ_REST,      ADI_BEEP_DUR_1_32 },
};
uint8_t playLength1 = sizeof(playList1)/sizeof(playList1[0]);
#endif

/* Boolean flag indicating callback success */
volatile bool bNoteDone     = false;
volatile bool bSequenceDone = false;

/* Used for a delay loop */
volatile uint32_t cnt = 0; 

int TEST_BEEPER (void)
{
  ADI_BEEP_RESULT eResult;
  
  do
  {
    if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Open(ADI_BEEP_DEVID_0,
                                                     &BeepMemory,
                                                     sizeof(BeepMemory),
                                                     &hBeep)))
    {
      INFO("adi_beep_Open failed\n");
      break;
    }
    
    if (ADI_BEEP_SUCCESS != (eResult = adi_beep_RegisterCallback(hBeep,
                                                                 beepCallback,
                                                                 NULL)))
    {
      INFO("adi_beep_RegisterCallback failed\n");
      break;
    }

#if PLAY_NOTE == 1
    if (ADI_BEEP_SUCCESS != (eResult = PlayOne()))
    {
      break;
    }
    
    /* Wait a while, just to break-up the audible sequence. 
    * This can also be achieved by using a "REST" note for 
    * the beep driver. */
    for(cnt = 0u; cnt < 10000; cnt++) {}
#endif
#if PLAY_ALARM == 1
    if (ADI_BEEP_SUCCESS != (eResult = PlayAlarm()))
    {
      break;
    }
    
    /* Wait a while, just to break-up the audible sequence. 
    * This can also be achieved by using a "REST" note for 
    * the beep driver. */
    for(cnt = 0u; cnt < 1000000; cnt++) {}
#endif
#if PLAY_TUNE == 1        
    if (ADI_BEEP_SUCCESS != (eResult = PlayTune()))
    {
      break;
    }
#endif
    
    
  } while(0);
    if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Close(hBeep)))
    {
      INFO("adi_beep_Close failed\n");
    }
  
  if(ADI_BEEP_SUCCESS == eResult)
  {
    INFO("Beep example completed successfully");
    INFO("All done!");
  }
  else
  {
    INFO("Failed to run the Beep example");
    FAIL("TEST_BEEPER failed");
    return FAILURE;
  }
  return SUCCESS;
}


/* Optional application callback */
void beepCallback(void *pCBUnused, uint32_t Event, void *pvUnused) {

    if(Event & (ADI_BEEP_INTERRUPT_NOTE_END)) {  
       bNoteDone = true;
    }

    if(Event & ADI_BEEP_INTERRUPT_SEQUENCE_END) { 
       bSequenceDone = true;
    }
 }


#if PLAY_NOTE == 1
ADI_BEEP_RESULT PlayOne(void)
{
  ADI_BEEP_RESULT eResult;
  ADI_BEEP_NOTE note = {ADI_BEEP_FREQ_Gs6, ADI_BEEP_DUR_8_32};
  
  bNoteDone     = false;
  bSequenceDone = false;
  
  
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_PlayNote(hBeep, note)))
  {
    INFO("PlayOne: adi_beep_PlayNote failed\n");
    return eResult;
  }
  
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Wait(hBeep)))
  {
    INFO("PlayOne: adi_beep_Wait failed\n");
    return eResult;
  }
  
  
  /* ... and check if we got the right callback */
  if ((bNoteDone != true) || (bSequenceDone != false))
  {
    INFO("PlayOne: Note callback failed \n");
    return eResult;
  }
  
  return eResult;
}
#endif

#if PLAY_ALARM == 1
ADI_BEEP_RESULT PlayAlarm(void)
{
  ADI_BEEP_RESULT eResult;
  ADI_BEEP_NOTE note1, note2;
  
  /* Play the following two notes, 5 times */
  uint8_t count   = 5u;
  note1.frequency = ADI_BEEP_FREQ_A4;     /* Low... */
  note1.duration  = ADI_BEEP_DUR_2_32;
  
  note2.frequency = ADI_BEEP_FREQ_A7;     /*... then high */
  note2.duration  = ADI_BEEP_DUR_2_32;
  
  /* Reset the callback checks */
  bNoteDone     = false;
  bSequenceDone = false;
  
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_PlayTwoTone(hBeep, note1, note2, count)))
  {
    INFO("PlayAlarm: adi_beep_PlayTwoTone failed\n");
    return eResult;
  }
  
  /* Wait until the sequence is complete. */
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Wait(hBeep)))
  {
    INFO("PlayAlarm: adi_beep_Wait failed\n");
    return eResult;
  }
  
  /* ... and check if we got the right callbacks */
  if ((bNoteDone != false) || (bSequenceDone != true))
  {
    INFO("PlayAlarm: Twotone callback failed \n");
    return eResult;
  }        
  return eResult;
}
#endif 

#if PLAY_TUNE == 1
#if ADI_BEEP_INCLUDE_PLAY_SEQUENCE != 1
#error To use the "adi_beep_PlaySequence()" API, the ADI_BEEP_INCLUDE_PLAY_SEQUENCE macro must be set to 1 in the adi_beep_config.h file.
#else 
ADI_BEEP_RESULT PlayTune(void)
{
  ADI_BEEP_RESULT eResult;
  
  bNoteDone     = false;
  bSequenceDone = false;
  
  /* Play the tune */
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_PlaySequence(hBeep, playList1, playLength1)))
  {
    INFO("PlayTune: adi_beep_PlaySequence failed\n");
    return eResult;
  }
  
  /* wait for the sequence to complete */
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Wait(hBeep)))
  {
    INFO("PlayTune: adi_beep_Wait failed\n");
    return eResult;
  }
  
  /* ...and check that we got the right callbacks */
  if ((bNoteDone != false) || (bSequenceDone != true))
  {
    INFO("PlayTune: Sequence callback failed \n");
    return eResult;
  }        
  
  return eResult;
}
#endif
#endif
    

