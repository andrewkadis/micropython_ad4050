/* Copyright (c) 2010 - 2015 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.

   Portions Copyright (c) 2016-2017 Analog Devices, Inc.
   ---------------------------------------------------------------------------*/
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Flash Programming Functions adapted                   */
/*               for ADuCM4x50 512kB Flash                            */
/*                                                                     */
/***********************************************************************/

#include "FlashOS.H"        /* FlashOS Structures */
#include <ADuCM4050_cdef.h>

/* 
   Mandatory Flash Programming Functions (Called by FlashOS):
                int Init        (unsigned long adr,   // Initialize Flash
                                 unsigned long clk,
                                 unsigned long fnc);
                int UnInit      (unsigned long fnc);  // De-initialize Flash
                int EraseSector (unsigned long adr);  // Erase Sector Function
                int ProgramPage (unsigned long adr,   // Program Page Function
                                 unsigned long sz,
                                 unsigned char *buf);

   Optional  Flash Programming Functions (Called by FlashOS):
                int BlankCheck  (unsigned long adr,   // Blank Check
                                 unsigned long sz,
                                 unsigned char pat);
                int EraseChip   (void);               // Erase complete Device
      unsigned long Verify      (unsigned long adr,   // Verify Function
                                 unsigned long sz,
                                 unsigned char *buf);

       - BlankCheck   is necessary if Flash space is not mapped into CPU memory space
       - Verify       is necessary if Flash space is not mapped into CPU memory space
       - if EraseChip is not provided than EraseSector for all sectors is called
*/

#define RESULT_OK                   0
#define RESULT_ERROR                1

/* Init() 'fnc' argument codes indicating which step it's invoked for.
 * The debugger invokes Init() before the Erase, Program, and Verify steps
 * during download of a program.
 */
#define FNC_ERASE                   1
#define FNC_PROGRAM                 2
#define FNC_VERIFY                  3

/* Flash User Key */
#define FEE_USERKEY                        (0x676C7565)  /* (ascii "GLUE", in hex) */

/* Flash Commands */
#define FEE_CMD_IDLE                       ENUM_FLCC_CMD_IDLE
#define FEE_CMD_ABORT                      ENUM_FLCC_CMD_ABORT
#define FEE_CMD_SLEEP                      ENUM_FLCC_CMD_SLEEP
#define FEE_CMD_SIGN                       ENUM_FLCC_CMD_SIGN
#define FEE_CMD_WRITE                      ENUM_FLCC_CMD_WRITE
#define FEE_CMD_CHECK                      ENUM_FLCC_CMD_BLANK_CHECK
#define FEE_CMD_ERASEPAGE                  ENUM_FLCC_CMD_ERASEPAGE
#define FEE_CMD_MASSERASE                  ENUM_FLCC_CMD_MASSERASE

/* Flash Status */
#define FEE_STA_CMD_BUSY                   BITM_FLCC_STAT_CMDBUSY
#define FEE_STA_WRITE_CLOSED               BITM_FLCC_STAT_WRCLOSE
#define FEE_STA_CMD_COMPLETE               BITM_FLCC_STAT_CMDCOMP
#define FEE_STA_WRITE_ALMOST_COMPLETE      BITM_FLCC_STAT_WRALCOMP

#define FEE_STA_CMD_RESULT_SUCCESS         (0 << BITP_FLCC_STAT_CMDFAIL)
#define FEE_STA_CMD_RESULT_IGNORED         (1 << BITP_FLCC_STAT_CMDFAIL)
#define FEE_STA_CMD_RESULT_VERIFY_ERROR    (2 << BITP_FLCC_STAT_CMDFAIL)
#define FEE_STA_CMD_RESULT_ABORTED         (3 << BITP_FLCC_STAT_CMDFAIL)
#define FEE_STA_CMD_RESULT_MASK            ( FEE_STA_CMD_RESULT_SUCCESS      \
                                           | FEE_STA_CMD_RESULT_IGNORED      \
                                           | FEE_STA_CMD_RESULT_VERIFY_ERROR \
                                           | FEE_STA_CMD_RESULT_ABORTED )

/* Saved ECC configuration */
static uint32_t saved_ecc_cfg = 0;

static void DoInit (void);
static int DoEraseChip (void);

/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int Init (unsigned long adr, unsigned long clk, unsigned long fnc) {

    /* NOTE: adr & clk are unused here... */

    int Result = RESULT_OK;

    if (fnc == FNC_ERASE) {
        /* Initialization only needs to be done on the first step, i.e. Erase. */
        DoInit();

        /* Mass erase flash if it is access-protected. */
        if (*pREG_FLCC0_POR_SEC & BITM_FLCC_POR_SEC_SECURE) {
            Result = DoEraseChip();
        }
    } else if (fnc == FNC_PROGRAM) {
        /* Save ECC configuration */
        saved_ecc_cfg = *pREG_FLCC0_ECC_CFG;

        /* Enable ECC for both user and info flash, and set page pointer to zero */
        *pREG_FLCC0_ECC_CFG = BITM_FLCC_ECC_CFG_EN | BITM_FLCC_ECC_CFG_INFOEN;
    }

    return Result;
}


static void DoInit (void) {

    /* Try to turn off the watchdog while we are programming flash */
    *pREG_WDT0_CTL = 0;

    /* Disable all NVIC IRQs */
    *pREG_NVIC0_INTCLRE0 = 0xFFFFFFFF;
    *pREG_NVIC0_INTCLRE1 = 0xFFFFFFFF;

    /* SysTick control register "reset" */
    *pREG_NVIC0_STKSTA   = 0x0;

    *pREG_NVIC0_INTCFSR  = 0xFFFFFFFF; /* Clear all bits that are currently set */

    /* Enable the usage fault, bus fault and mem-manage fault handlers */
    *pREG_NVIC0_INTSHCSR = 0x00070000;

    /* Ensure internal HF oscillator is enabled so flash has a guaranteed clock */
    *pREG_CLKG0_OSC_KEY  = 0xcb14;  /* Unlock key */
    *pREG_CLKG0_OSC_CTL |= BITM_CLKG_OSC_CTL_HFOSC_EN;

    /* Ensure rclk mux select is set for internal HF oscillator */
    *pREG_CLKG0_CLK_CTL0 &= ~BITM_CLKG_CLK_CTL0_RCLKMUX; /* Set rclk mux select to zero */

    /* Disable any flash related interrupts */
    *pREG_FLCC0_IEN = 0;

    /* Write the user key */
    *pREG_FLCC0_KEY = FEE_USERKEY;

    /* Set the timing parameters to reset values, just in case, except TERASE
     * since the recommended value is now 0x9. The value can be kept as 0x9
     * when the flash loader terminates.
     */
    *pREG_FLCC0_TIME_PARAM0 = 
          (0xbu << BITP_FLCC_TIME_PARAM0_TNVH1)
        | (0x9u << BITP_FLCC_TIME_PARAM0_TERASE)
        | (0x9u << BITP_FLCC_TIME_PARAM0_TRCV)
        | (0x5u << BITP_FLCC_TIME_PARAM0_TNVH)
        | (0x0u << BITP_FLCC_TIME_PARAM0_TPROG)
        | (0x9u << BITP_FLCC_TIME_PARAM0_TPGS)
        | (0x5u << BITP_FLCC_TIME_PARAM0_TNVS)
        | (0x0u << BITP_FLCC_TIME_PARAM0_DIVREFCLK);
    *pREG_FLCC0_TIME_PARAM1 = 
          (0x0u << BITP_FLCC_TIME_PARAM1_WAITSTATES)
        | (0x4u << BITP_FLCC_TIME_PARAM1_TWK);

    /* Make sure info flash remapping is off */
    *pREG_FLCC0_VOL_CFG = BITM_FLCC_VOL_CFG_INFO_REMAP;

    /* Clear key */
    *pREG_FLCC0_KEY = 0;
}


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

int UnInit (unsigned long fnc) {

    if (fnc == FNC_PROGRAM) {
        /* Restore saved ECC configuration */
        *pREG_FLCC0_ECC_CFG = saved_ecc_cfg;
    }

    /* Clear the user key */
    *pREG_FLCC0_KEY = 0;

    return RESULT_OK; /* Finished without Errors */
}


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseChip (void) {

    DoInit();
    return DoEraseChip();
}


static int DoEraseChip (void) {

    int Result = RESULT_OK;
    uint32_t status;

    /* Clear any status from any previous command */
    *pREG_FLCC0_STAT = 0xffffffff; /* W1C */

    /* Issue the mass erase command */
    *pREG_FLCC0_KEY  = FEE_USERKEY;
    *pREG_FLCC0_CMD  = FEE_CMD_MASSERASE;

    /* Wait for the command to complete */
    do {
        status = *pREG_FLCC0_STAT;
    } while ((status & FEE_STA_CMD_COMPLETE) == 0x0);

    /* Check result of operation */
    if ((status & FEE_STA_CMD_RESULT_MASK) != FEE_STA_CMD_RESULT_SUCCESS) {
        Result = RESULT_ERROR; /* Command failed */
    }

    /* Clear key */
    *pREG_FLCC0_KEY = 0;

    return Result;
}


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

int EraseSector (unsigned long adr) {

    int Result = RESULT_OK;
    uint32_t status;

    /* Clear any status from any previous command */
    *pREG_FLCC0_STAT = 0xffffffff; /* W1C */

    /* Write the page start address */
    *pREG_FLCC0_PAGE_ADDR0 = ((uint32_t)adr);

    /* Page erase command has implicit extent;  no need to set end address! */

    /* Issue the page erase command */
    *pREG_FLCC0_KEY = FEE_USERKEY;
    *pREG_FLCC0_CMD = FEE_CMD_ERASEPAGE;

    /* Wait for the command to complete */
    do {
        status = *pREG_FLCC0_STAT;
    } while ((status & FEE_STA_CMD_COMPLETE) == 0x0);

    /* Check result of operation */
    if ((status & FEE_STA_CMD_RESULT_MASK) != FEE_STA_CMD_RESULT_SUCCESS) {
        Result = RESULT_ERROR; /* Command failed */
    }

    /* Clear key */
    *pREG_FLCC0_KEY = 0;

    return Result;
}


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf) {

    int Result = RESULT_OK;
    uint32_t status;

    /* For ADuCM4x50: all flash writes are 64-bit wide with INDIRECT addressing via Key-Hole registers... */

    /* Initialize source and destination pointers as 64-bit types */
    uint64_t *pDst = (uint64_t *)((uint64_t *)adr);
    uint64_t *pSrc = (uint64_t *)(buf); 

    /* Write the user key */
    *pREG_FLCC0_KEY = FEE_USERKEY;

    /* Iterate over the count */
    for ( ; sz; sz -= sizeof(uint64_t), pSrc++, pDst++) {

        /* Clear status */
        *pREG_FLCC0_STAT = 0xffffffff; /* W1C */

        /* Keil will ask for partial page writes, so there is no guarantee
         * that 'sz' is a multiple of 8.
         */
        if (sz >= sizeof(uint64_t)) {

            /* Full 64-bit writes... */
            *pREG_FLCC0_KH_DATA0 = (uint32_t) (*pSrc);
            *pREG_FLCC0_KH_DATA1 = (uint32_t) (*pSrc >> 32);

        } else {

            /* Partial 64-bit write, padded with all-ones */
            uint64_t u64TmpData  = 0xFFFFFFFFFFFFFFFF;
            uint8_t *pTmp = (uint8_t *)&u64TmpData;

            switch (sz) {

                /* Fallthrough writes all lower bytes */
                case 7: pTmp[6] = *(((uint8_t *)pSrc)+ 6);
                case 6: pTmp[5] = *(((uint8_t *)pSrc)+ 5);
                case 5: pTmp[4] = *(((uint8_t *)pSrc)+ 4);
                case 4: pTmp[3] = *(((uint8_t *)pSrc)+ 3);
                case 3: pTmp[2] = *(((uint8_t *)pSrc)+ 2);
                case 2: pTmp[1] = *(((uint8_t *)pSrc)+ 1);
                case 1: pTmp[0] = *(((uint8_t *)pSrc)+ 0);
                    break;

                default:
                    break;
            }

            /* Copy the 64-bit data to keyhole write data registers */
            *pREG_FLCC0_KH_DATA0 = (uint32_t) (u64TmpData);
            *pREG_FLCC0_KH_DATA1 = (uint32_t) (u64TmpData >> 32);

            sz = sizeof(uint64_t);  /* Forces loop termination after this iteration */

        }  /* End if/else block */

        /* Set the write address and issue the write */
        *pREG_FLCC0_KH_ADDR = (unsigned long)pDst;
        *pREG_FLCC0_CMD     = FEE_CMD_WRITE;

        /* Verify write command was accepted without error */
        if (*pREG_FLCC0_STAT & FEE_STA_CMD_RESULT_MASK) {
            Result = RESULT_ERROR; /* Command failed */
            break;
        }

        /* Poll for command complete */
        do {
            status = *pREG_FLCC0_STAT;
        } while ((status & FEE_STA_CMD_COMPLETE) == 0x0);

    }  /* End for loop */

    /* Clear the user key */
    *pREG_FLCC0_KEY = 0;

    return Result;
}
