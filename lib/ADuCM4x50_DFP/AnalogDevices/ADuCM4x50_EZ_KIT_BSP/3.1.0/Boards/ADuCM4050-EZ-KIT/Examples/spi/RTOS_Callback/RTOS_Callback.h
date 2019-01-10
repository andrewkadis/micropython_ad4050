/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
* @file     RTOS_Callback.h
*
* @brief    Primary header file for SPI driver Maser <==> Slave loopback example.
*
* @details  Primary header file for SPI driver example which contains the
*           processor specific defines.
*
*/

#ifndef _RTOSCALLBACK_H_
#define _RTOSCALLBACK_H_

/** define size of data buffers, DMA max size is 255 */
#define BUFFERSIZE 5 

/* SPI device number which act as MASTER */
#define SPI_MASTER_DEVICE_NUM 0 

/* SPI device number which act as Slave */
#define SPI_SLAVE_DEVICE_NUM  1 

/* Pin muxing */
extern int32_t adi_initpinmux(void);


#if defined(__ADUCM4x50__)
#define FAILURE 1
#define SUCCESS 0
#endif

#if defined(__ADUCM302x__)
#define TASK_STK_SIZE           (100u)
#elif defined(__ADUCM4x50__)
#define TASK_STK_SIZE           (200u)
#else
#error SPI is not ported for this processor
#endif

/* Slave task has to establish the SPI slave before the master can try to */
/* communicate with it. Therefore, slave has higher priority              */
#define TASK_SLAVE_PRIO         (11u)
#define TASK_MASTER_PRIO        (12u)

#endif /* _RTOSCALLBACK_H_ */
