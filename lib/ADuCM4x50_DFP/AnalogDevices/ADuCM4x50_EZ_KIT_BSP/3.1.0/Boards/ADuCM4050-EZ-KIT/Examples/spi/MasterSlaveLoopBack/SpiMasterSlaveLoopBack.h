/*********************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
* @file     SpiMasterSlaveLoopBack.h
*
* @brief    Primary header file for SPI driver Maser <==> Slave loopback example.
*
* @details  Primary header file for SPI driver example which contains the
*           processor specific defines.
*
*/

#ifndef _SPIMASTERSLAVELOOPBACK_H_
#define _SPIMASTERSLAVELOOPBACK_H_

/** define size of data buffers, DMA max size is 255 */
#define BUFFERSIZE            250u 

/* SPI device number which act as MASTER */
#define SPI_MASTER_DEVICE_NUM 0u 

/* SPI device number which act as Slave */
#define SPI_SLAVE_DEVICE_NUM  1u 



/* Pin muxing */
extern int32_t adi_initpinmux(void);

#endif /* _SPIMASTERSLAVELOOPBACK_H_ */
