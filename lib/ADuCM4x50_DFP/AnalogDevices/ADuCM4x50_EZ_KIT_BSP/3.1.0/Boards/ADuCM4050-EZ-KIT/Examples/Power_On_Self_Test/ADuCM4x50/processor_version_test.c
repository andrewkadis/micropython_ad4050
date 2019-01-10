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
 * Description: This examples performs a processor version check on the AduCM4x50 EZKIT
 */


#include "post_common.h"

/* direct from debugger display of these registers on 1st silicon */
#define EXPECTED_VENDOR_ID  0x4144
#define EXPECTED_CHIP_ID    0x002A
#define EXPECTED_CHIP_REV   0x0000
#define EXPECTED_CHIP_REVA  0x0008


/*
 *   Function:    TEST_VERSION
 *   Description: This function compares the version of the processor
 * 				 being run on with the version that the software was
 *				 built against.  This will catch a different version
 *				 of silicon than what it was built for.
 */
int TEST_VERSION(void)
{
	int actual_vendorID    = *pREG_SYS_ADIID & 0xffff;
   	int actual_chipID      = (*pREG_SYS_CHIPID & BITM_SYS_CHIPID_PARTID) >> BITP_SYS_CHIPID_PARTID;
   	int actual_chipRev     = *pREG_SYS_CHIPID & BITM_SYS_CHIPID_REV;

	int expected_vendorID  = EXPECTED_VENDOR_ID;
   	int expected_chipID    = EXPECTED_CHIP_ID;
   	int expected_chipRev   = EXPECTED_CHIP_REV;
   	int expected_chipReva   = EXPECTED_CHIP_REVA;

   	HEAD("Silicon Revision Test");

    sprintf(gPrintString, "    Vendor ID:        expected = 0x%04x, actual = 0x%04x", expected_vendorID, actual_vendorID);
    INFO(gPrintString);

   	sprintf(gPrintString, "    Silicon ID:       expected = 0x%04x, actual = 0x%04x", expected_chipID,   actual_chipID);
    INFO(gPrintString);

   	sprintf(gPrintString, "    Silicon Revision: expected = 0x%04x or 0x%04x, actual = 0x%04x", expected_chipRev, expected_chipReva,  actual_chipRev);
    INFO(gPrintString);

    do {
        if( actual_vendorID != expected_vendorID ) {
            INFO("Vendor ID mismatch");
            break;
        }

        if( actual_chipID != expected_chipID ) {
            INFO("Siicon ID mismatch");
            break;
        }

        if(( actual_chipRev != expected_chipRev ) && (actual_chipRev != expected_chipReva)) {
            INFO("Siicon revision mismatch");
            break;
        }

        /* success */
        return PASS();

    } while (0);

	/* failure */
      FAIL("\nTEST_VERSION failed.\n");
      return(FAILURE);
}
