/*
THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES INC. ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT, ARE
DISCLAIMED. IN NO EVENT SHALL ANALOG DEVICES INC. BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

YOU ASSUME ANY AND ALL RISK FROM THE USE OF THIS CODE OR SUPPORT FILE.

IT IS THE RESPONSIBILITY OF THE PERSON INTEGRATING THIS CODE INTO AN APPLICATION
TO ENSURE THAT THE RESULTING APPLICATION PERFORMS AS REQUIRED AND IS SAFE.

     Module      : FlashADuCM4050.c
     Description : Flash programming routines for the ADuCM4050 device, for
                         the IAR flash programmer setup
*/

#include "flash_loader.h"

#include <ADuCM4050_cdef.h>

/* Size of a flash block */
#define FLASH_BLOCK_SIZE                   (0x800)

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


/* Interrupt traps */
void DebugTrap(void)       { while (1); }
void NMITrap(void)         { while (1); }
void HFTrap(void)          { while (1); }
void MemManageTrap(void)   { while (1); }
void BusFaultTrap(void)    { while (1); }
void UsageTrap(void)       { while (1); }
void DefaultTrap(void)     { while (1); }


/* Handy macros borrowed from startup.c */
#define KEEP_VAR(var)                  __root var
#define SECTION_PLACE(def,sectionname) def @ sectionname

SECTION_PLACE(KEEP_VAR(const unsigned long VectorTable[]), ".intvec") =
{
    0x0,
    (unsigned long)DebugTrap,      /* 1 Reset - Dummy! */
    (unsigned long)NMITrap,        /* 2 NMI            */
    (unsigned long)HFTrap,         /* 3 Hard fault     */
    (unsigned long)MemManageTrap,  /* 4 MemManage      */
    (unsigned long)BusFaultTrap,   /* 5 BusFault       */
    (unsigned long)UsageTrap,      /* 6 UsageFault     */
    (unsigned long)DefaultTrap,    /* 7 Reserved       */
    (unsigned long)DefaultTrap,    /* 8 Reserved       */
    (unsigned long)DefaultTrap,    /* 9 Reserved       */
    (unsigned long)DefaultTrap,    /* 10 Reserved      */
    (unsigned long)DefaultTrap,    /* 11 SVC           */
    (unsigned long)DefaultTrap,    /* 12 Debug monitor */
    (unsigned long)DefaultTrap,    /* 13 Reserved      */
    (unsigned long)DefaultTrap,    /* 14 PendSV        */
    (unsigned long)DefaultTrap,    /* 15 SysTick       */
};

uint32_t FlashChipErase(void);


#if USE_ARGC_ARGV
uint32_t FlashInit(void *base_of_flash, uint32_t image_size, uint32_t link_address, uint32_t flags, int argc, char const *argv[])
#else
uint32_t FlashInit(void *base_of_flash, uint32_t image_size, uint32_t link_address, uint32_t flags)
#endif
{
    uint32_t Result = RESULT_OK;

    /* Try to turn off the watchdog while we are programming flash */
    *pREG_WDT0_CTL = 0;

    /* Disable all NVIC IRQs */
    *pREG_NVIC0_INTCLRE0 = 0xFFFFFFFF;
    *pREG_NVIC0_INTCLRE1 = 0xFFFFFFFF;

    /* SysTick control register "reset" */
    *pREG_NVIC0_STKSTA   = 0x0;

    *pREG_NVIC0_INTVEC   = (unsigned long)VectorTable;
    *pREG_NVIC0_INTCFSR  = 0xFFFFFFFF; /* Clear all bits that are currently set */

    /* Enable the usage fault, bus fault and mem-manage fault handlers */
    *pREG_NVIC0_INTSHCSR = 0x00070000;

    /* Ensure internal HF oscillator is enabled so flash has a guaranteed clock */
    *pREG_CLKG0_OSC_KEY  = 0xcb14;  /* Unlock key */
    *pREG_CLKG0_OSC_CTL |= BITM_CLKG_OSC_CTL_HFOSC_EN;

    /* Ensure rclk mux select is set for internal HF oscillator */
    *pREG_CLKG0_CLK_CTL0 &= ~BITM_CLKG_CLK_CTL0_RCLKMUX; /* Set rclk mux select to zero */

    /* Clear any flash related interrupt-enable bits. No interrupts for ECC
     * errors, command -failed, -almost-complete or -complete events. */
    *pREG_FLCC0_IEN = 0;

    /* Write the user key */
    *pREG_FLCC0_KEY = FEE_USERKEY;

    /* Set the timing parameters to reset values, just in case */
    *pREG_FLCC0_TIME_PARAM0 =
          (0xb << BITP_FLCC_TIME_PARAM0_TNVH1)
        | (0x9 << BITP_FLCC_TIME_PARAM0_TERASE)
        | (0x9 << BITP_FLCC_TIME_PARAM0_TRCV)
        | (0x5 << BITP_FLCC_TIME_PARAM0_TNVH)
        | (0x0 << BITP_FLCC_TIME_PARAM0_TPROG)
        | (0x9 << BITP_FLCC_TIME_PARAM0_TPGS)
        | (0x5 << BITP_FLCC_TIME_PARAM0_TNVS)
        | (0x0 << BITP_FLCC_TIME_PARAM0_DIVREFCLK);
    *pREG_FLCC0_TIME_PARAM1 =
          (0x0 << BITP_FLCC_TIME_PARAM1_WAITSTATES)
        | (0x4 << BITP_FLCC_TIME_PARAM1_TWK);

    /* Make sure info flash remapping is off */
    *pREG_FLCC0_VOL_CFG = BITM_FLCC_VOL_CFG_INFO_REMAP;

    /* Clear the user key */
    *pREG_FLCC0_KEY = 0;

    if (flags & FLAG_ERASE_ONLY) {
        /* Flash loader has been invoked with the sole purpose of erasing the whole flash memory */
        Result = FlashChipErase();
        if (Result == RESULT_OK) {
            Result = RESULT_ERASE_DONE;
        }
    } else if (*pREG_FLCC0_POR_SEC & BITM_FLCC_POR_SEC_SECURE) {
        /* The flash is access-protected. Mass erase to clear protection. */
        Result = FlashChipErase();
    }

    return Result;
}


/*!
     \fn        uint32_t FlashWrite(void *block_start, uint32_t offset_into_block, uint32_t count, char const *buffer)
     \brief     Program flash data

     \param block_start        Start of the block to write to
     \param offset_into_block  Offset in bytes into the block to write to
     \param count              Number of bytes to write
     \param buffer             Src buffer of bytes to write

     \return uint32_t          Error code
*/
uint32_t FlashWrite(void *block_start, uint32_t offset_into_block, uint32_t count, char const *buffer)
{
    uint32_t Result = RESULT_OK;
    uint32_t status;

    /* Initialize source and destination pointers as 64-bit types */
    uint64_t *pDst = (uint64_t *)((uint8_t *)block_start + offset_into_block);
    uint64_t *pSrc = (uint64_t *)buffer;

    /* Save ECC configuration */
    uint32_t saved_ecc_cfg = *pREG_FLCC0_ECC_CFG;

    /* Enable ECC for both user and info flash, and set page pointer to zero */
    *pREG_FLCC0_ECC_CFG = BITM_FLCC_ECC_CFG_EN | BITM_FLCC_ECC_CFG_INFOEN;

    /* Write the user key */
    *pREG_FLCC0_KEY = FEE_USERKEY;

    /* Iterate over the count */
    for ( ; count; count -= sizeof(uint64_t), pSrc++, pDst++) {

        /* Clear status */
        *pREG_FLCC0_STAT = 0xffffffff; /* W1C */

        /* Write 64 bits */
        *pREG_FLCC0_KH_DATA0 = (uint32_t) (*pSrc);
        *pREG_FLCC0_KH_DATA1 = (uint32_t) (*pSrc >> 32);

        /* Set the write address and issue the write */
        *pREG_FLCC0_KH_ADDR = (unsigned long)pDst;
        *pREG_FLCC0_CMD     = FEE_CMD_WRITE;

        /* Verify write command was accepted without error */
        if ((*pREG_FLCC0_STAT) & FEE_STA_CMD_RESULT_MASK) {
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

    /* Restore saved ECC configuration */
    *pREG_FLCC0_ECC_CFG = saved_ecc_cfg;

    return Result;
}


/*!
     \fn       uint32_t FlashErase(void *block_start, uint32_t block_size)
     \brief    Erase the block starting at block_start

     \param block_start  Start address of block to be erased
     \param block_size   Size of block to be erased.

     \return  uint32_t   Error code
*/
uint32_t FlashErase(void *block_start, uint32_t  block_size)
{
    uint32_t Result = RESULT_OK;
    uint32_t status;

    /* Clear any status from any previous command */
    *pREG_FLCC0_STAT = 0xffffffff; /* W1C */

    /* Write the page start address */
    *pREG_FLCC0_PAGE_ADDR0 = ((uint32_t)block_start);

    /* Page erase command has implicit extent; no need to set end address! */

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


/*!
     \fn      uint32_t FlashChipErase(void)
     \brief   Perform a mass erase
     \return  uint32_t  Error code
*/
uint32_t FlashChipErase(void)
{
    uint32_t Result = RESULT_OK;
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
