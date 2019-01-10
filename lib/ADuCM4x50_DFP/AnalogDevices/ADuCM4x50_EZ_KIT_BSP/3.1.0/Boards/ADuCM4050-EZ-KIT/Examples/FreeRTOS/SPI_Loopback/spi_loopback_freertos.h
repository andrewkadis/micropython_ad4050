/*********************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*
*
*           Primary header file for SPI driver example which contains the
*           processor specific defines.
*
*/

#ifndef _SPI_LOOPBACK_FREERTOS_H_
#define _SPI_LOOPBACK_FREERTOS_H_


/* Choose a SPI device, note that the pinmux is for SPI2 */
#define SPI_DEVICE_NUM    2U

/** define size of data buffers, DMA max size is 1024 on the processor */
#define BUFFERSIZE 5

/* In RD_CTL mode the master will first transmit between 1 and 16 bytes */
#define SPI_RD_CTL_NBYTES_TX   3
#define SPI_RD_CTL_NBYTES_RX   5

#if defined(__ADUCM4x50__)
/* Application specific return values */
#define SUCCESS 0
#define FAILURE 1
#endif

#if defined (__ADUCM302x__)
#define CLKG_ROOTCLK_ERR_IRQn  64    /*!< Root Clock Error Interrupt Number Assignment*/
#endif

/* SPI slave iterrupts should fire first to ensure that the Slave task sets its buffers */
/* before the master. SPIO is ISR #31 which, by default, is higher priority than SPI1 which is ISR #58 */
/* SPI device number which act as MASTER */
#define SPI_MASTER_DEVICE_NUM 0
/* SPI device number which act as Slave */
#define SPI_SLAVE_DEVICE_NUM  1 

/* Slave task has to establish the SPI slave before the master can try to */
/* communicate with it. Therefore, slave has higher priority              */
#define TASK_SLAVE_PRIO         (8u)
#define TASK_MASTER_PRIO        (7u)

/* Pin muxing */
extern int32_t adi_initpinmux(void);

/* Task prototypes */
extern void spiSlaveTask(void *pvParameters);
extern void spiMasterTask(void *pvParameters);



#endif /* _SPI_LOOPBACK_FREERTOS_H_ */
