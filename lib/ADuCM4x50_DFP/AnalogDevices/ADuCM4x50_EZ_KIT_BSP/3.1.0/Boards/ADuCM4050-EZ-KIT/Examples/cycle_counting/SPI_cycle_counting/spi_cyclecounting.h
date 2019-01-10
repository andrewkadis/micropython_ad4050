/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*
*
*           Primary header file for SPI driver example which contains the
*           processor specific defines.
*
*/

#ifndef SPI_CYCLECOUNTINT_H_
#define SPI_CYCLECOUNTINT_H_


/* Choose a SPI device, note that the pinmux is for SPI2 */
#define SPI_DEVICE_NUM    2U

/** define size of data buffers, DMA max size is 255 */
#define BUFFERSIZE 1024

/* define the SPI bit rate for this example */
#define SPI_BIT_RATE 400000  /* 100 KHz by default */

/* Pin muxing */
extern int32_t adi_initpinmux(void);

#endif /* SPI_CYCLECOUNTINT_H_ */
