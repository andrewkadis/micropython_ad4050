/*----------------------------------------------------------------------------
 * Name:    Retarget.c
 * Purpose: 'Retarget' layer for target-dependent low level functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *
 * Portions Copyright (c) 2016 Analog Devices, Inc.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <rt_misc.h>

#include <drivers/pwr/adi_pwr.h>
#include <drivers/uart/adi_uart.h>

#pragma import(__use_no_semihosting_swi)

#ifndef FAILURE
#define FAILURE true
#endif

#ifndef SUCCESS
#define SUCCESS false
#endif

#ifndef __DBG_ITM
#if !defined (SUPPRESS_UART_OUT)
/* PinMux definitions */
#define UART0_TX_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<20))
#define UART0_RX_PORTP0_MUX  ((uint32_t) ((uint32_t) 1<<22))

/* Memory required by the driver for TX and RX */
#define ADI_UART_MEMORY_SIZE    (ADI_UART_BIDIR_MEMORY_SIZE)

#define UART_DEVICE_NUM 0

/* Handle for UART device */
static ADI_UART_HANDLE hDevice;

/* Memory for  UART driver */
static uint8_t UartDeviceMem[ADI_UART_MEMORY_SIZE];

uint8_t uart_init_count = 0;

bool Init_Uart()
{
 
  return SUCCESS;
}

void Uninit_Uart(void)
{
 
}

void RedirectToUART(uint8_t *pData , uint32_t count)
{
  uint32_t hwError;
  /* Write out the buffer */
  adi_uart_Write(hDevice, pData, count, 0, &hwError);
}
#endif /* !SUPPRESS_UART_OUT */
#endif /* !__DBG_ITM */

#ifdef __DBG_ITM
volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;  /*  CMSIS Debug Input    */
#endif


struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;


int fputc(int c, FILE *f) {
#if defined __DBG_ITM
  ITM_SendChar(c);
#else
#if !defined (SUPPRESS_UART_OUT)

  RedirectToUART((void *) &c, 1);
#endif /* !SUPPRESS_UART_OUT */
#endif /* __DBG_ITM */
  return (c);
}


int fgetc(FILE *f) {
#if defined __DBG_ITM
  if (ITM_CheckChar())
    return ITM_ReceiveChar();
  return (-1);
#else
#if !defined (SUPPRESS_UART_OUT)
  int c;
  uint32_t hwError;
  adi_uart_Read(hDevice, (void *) &c, 1, 0, &hwError);
  return (c);
#else
  return (-1);
#endif /* !SUPPRESS_UART_OUT */
#endif /* __DBG_ITM */
}


int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}


void _ttywrch(int c) {
  fputc(c, &__stdout);
}


void _sys_exit(int return_code) {
#ifndef __DBG_ITM
#if !defined (SUPPRESS_UART_OUT)
  if(uart_init_count != 0) {
    Uninit_Uart();
    uart_init_count = 0;
  }
#endif /* !SUPPRESS_UART_OUT */
#endif /* !__DBG_ITM */
label:  goto label;  /* endless loop */
}
