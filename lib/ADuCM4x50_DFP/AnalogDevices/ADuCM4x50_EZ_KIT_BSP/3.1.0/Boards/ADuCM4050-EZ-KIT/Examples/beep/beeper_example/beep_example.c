/******************************************************************************
 * @file:    beep_example.c
 * @brief:   Beeper Driver Example
 *
 Copyright (c) 2016 Analog Devices, Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  - Modified versions of the software must be conspicuously marked as such.
  - This software is licensed solely and exclusively for use with processors
    manufactured by or for Analog Devices, Inc.
  - This software may not be combined or merged with other code in any manner
    that would cause the software to become subject to terms and conditions
    which differ from those listed here.
  - Neither the name of Analog Devices, Inc. nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.
  - The use of this software may or may not infringe the patent rights of one
    or more patent holders.  This license does not release you from the
    requirement that you obtain separate licenses from these patent holders
    to use this software.

THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-
INFRINGEMENT, TITLE, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANALOG DEVICES, INC. OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, PUNITIVE OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, DAMAGES ARISING OUT OF
CLAIMS OF INTELLECTUAL PROPERTY RIGHTS INFRINGEMENT; PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/

/** \addtogroup BEEP_Test BEEP Test
 *  Example code demonstrating use of the BEEP functions.
 *  @{
 */

/*==========  I N C L U D E  ==========*/

#include <stdio.h>
#include <drivers/pwr/adi_pwr.h>
#include <drivers/beep/adi_beep.h>
#include <common.h>

/* prototypes */
extern int32_t   adi_initpinmux (void);
void             beepCallback(void *pCBUnused, uint32_t Event, void *pvUnused);

/* Device handle */
ADI_BEEP_HANDLE hBeep = NULL;

/* required beeper driver memory */
uint8_t BeepMemory[ADI_BEEP_MEMORY_SIZE];

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

int main (void)
{
  ADI_BEEP_RESULT eResult;
  
  /* enable the beeper pins */
  adi_initpinmux();
  
  /* test system initialization. This functions will also add the 
  pinmuxing  required for the UART device. */
  
  common_Init();
  
  do
  {
    if(ADI_PWR_SUCCESS != adi_pwr_Init())
    {
      eResult = ADI_BEEP_FAILURE;
      break;
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
      eResult = ADI_BEEP_FAILURE;
      break;
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
      eResult = ADI_BEEP_FAILURE;
      break;
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetLFClockMux(ADI_CLOCK_MUX_LFCLK_LFOSC))
    {
      eResult = ADI_BEEP_FAILURE;
      break;
    }    
    
    if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Open(ADI_BEEP_DEVID_0,
                                                     &BeepMemory,
                                                     sizeof(BeepMemory),
                                                     &hBeep)))
    {
      DEBUG_MESSAGE("adi_beep_Open failed\n");
      break;
    }
    
    if (ADI_BEEP_SUCCESS != (eResult = adi_beep_RegisterCallback(hBeep,
                                                                 beepCallback,
                                                                 NULL)))
    {
      DEBUG_MESSAGE("adi_beep_RegisterCallback failed\n");
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
    for(cnt = 0u; cnt < 1000000; cnt++) {}
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
    
    if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Close(hBeep)))
    {
      DEBUG_MESSAGE("adi_beep_Close failed\n");
      break;
    }
    
  } while(0);
  
  if(ADI_BEEP_SUCCESS == eResult)
  {
    DEBUG_MESSAGE("Beep example completed successfully");
    DEBUG_MESSAGE("All done!");
  }
  else
  {
    DEBUG_MESSAGE("Failed to run the Beep example");
    
  }
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
    DEBUG_MESSAGE("PlayOne: adi_beep_PlayNote failed\n");
    return eResult;
  }
  
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Wait(hBeep)))
  {
    DEBUG_MESSAGE("PlayOne: adi_beep_Wait failed\n");
    return eResult;
  }
  
  
  /* ... and check if we got the right callback */
  if ((bNoteDone != true) || (bSequenceDone != false))
  {
    DEBUG_MESSAGE("PlayOne: Note callback failed \n");
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
    DEBUG_MESSAGE("PlayAlarm: adi_beep_PlayTwoTone failed\n");
    return eResult;
  }
  
  /* Wait until the sequence is complete. */
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Wait(hBeep)))
  {
    DEBUG_MESSAGE("PlayAlarm: adi_beep_Wait failed\n");
    return eResult;
  }
  
  /* ... and check if we got the right callbacks */
  if ((bNoteDone != false) || (bSequenceDone != true))
  {
    DEBUG_MESSAGE("PlayAlarm: Twotone callback failed \n");
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
    DEBUG_MESSAGE("PlayTune: adi_beep_PlaySequence failed\n");
    return eResult;
  }
  
  /* wait for the sequence to complete */
  if (ADI_BEEP_SUCCESS != (eResult = adi_beep_Wait(hBeep)))
  {
    DEBUG_MESSAGE("PlayTune: adi_beep_Wait failed\n");
    return eResult;
  }
  
  /* ...and check that we got the right callbacks */
  if ((bNoteDone != false) || (bSequenceDone != true))
  {
    DEBUG_MESSAGE("PlayTune: Sequence callback failed \n");
    return eResult;
  }        
  
  return eResult;
}
#endif
#endif
    
/*@}*/


