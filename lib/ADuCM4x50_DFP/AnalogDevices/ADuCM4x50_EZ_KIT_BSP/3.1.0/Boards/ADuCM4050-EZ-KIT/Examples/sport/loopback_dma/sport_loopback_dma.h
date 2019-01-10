/*******************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*******************************************************************************/
/**
* @file     sport_loopback_dma.h
*
* @brief    Primary header file for SPORT driver example.
*
* @details  Primary header file for SPORT driver example which contains the
*           processor specific defines.
*
*/
#ifndef SPORT_LOOPBACK_DMA_H
#define SPORT_LOOPBACK_DMA_H

/** Sport Device identifier (in [0 .. ADI_SPORT_NUM_INSTANCES - 1]) */
#define SPORT_DEVICE_ID         (0u)

/** size of RX/TX buffers */
#define BUFFER_SIZE             (2048u)

#endif /* SPORT_LOOPBACK_DMA_H */
