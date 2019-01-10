/*********************************************************************************
   @file    adi_adp5300.h
   @brief   Header file for the ADP5300 Driver.
            This header file will have processor specific definitions.
             
 -----------------------------------------------------------------------------
Copyright (c) 2017 Analog Devices, Inc.

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

#ifndef __ADP5300_H__
#define __ADP5300_H__

#include <drivers/gpio/adi_gpio.h>
#include <adi_processor.h>
#include <adi_callback.h>


/** 
 *  @addtogroup ADP5300_Driver ADP5300 Driver
 *  @{
 *
 *  @brief Driver for the ADP5300 Voltage Regulator.
 */

#if (defined(__ADUCM302x__) || defined(__ADUCM4x50__))
/*!< Pin for the MODE pin on the ADP5300.			*/
#define ADI_ADP5300_MODE_PIN 	(ADI_GPIO_PIN_0)
/*!< Port for the MODE pin on the ADP5300.			*/
#define ADI_ADP5300_MODE_PORT 	(ADI_GPIO_PORT2)

/*!< Pin for the STOP pin on the ADP5300.			*/
#define ADI_ADP5300_STOP_PIN 	(ADI_GPIO_PIN_12)
/*!< Port for the STOP pin on the ADP5300.			*/
#define ADI_ADP5300_STOP_PORT 	(ADI_GPIO_PORT0)

/*!< Pin for the VOUTOK pin on the ADP5300.			*/
#define ADI_ADP5300_VOUTOK_PIN 	(ADI_GPIO_PIN_15)
/*!< Port for the VOUTOK pin on the ADP5300.	    */
#define ADI_ADP5300_VOUTOK_PORT (ADI_GPIO_PORT1)
#else
#error ADP5300 is not ported for this processor
#endif

/*!< GPIO Group interrupt for the VOUTOK pin. Needs to be a ADI_GPIO_IRQ enumeration. */
#define ADI_VOUTOK_IRQ_GROUP 	(ADI_GPIO_INTA_IRQ)	

/*!
 *  @enum    ADI_ADP5300_MODE
 *
 *  @brief   ADP5300 operational modes.
 *
 *  @details Buck regulator operational modes. PWM mode is a low noise mode 
 *           and can be used when sampling noise sensitive peripherals.
 *			 Hysteresis mode is high current but saves power. This can be
 *			 used during non noise sensitive operations such as being in 
 *		     hibernate.  
 */
typedef enum {
	ADI_ADP5300_MODE_HYSTERESIS, 	/*!< Hysteresis mode.   		    */
	ADI_ADP5300_MODE_PWM	        /*!< PWM mode.        		 		*/
} ADI_ADP5300_MODE;

/*!
 *  @enum    ADI_ADP5300_SWITCHING
 *
 *  @brief   ADP5300 switching modes.
 *
 *  @details The ADP5300 includes a STOP input pin that can temporarily stop the
 *			 regulator switching in hysteresis mode. When switching has stopped, a
 *			 quiet system is acheived which is ideal for noise sensitive circuitry like 
 *			 a data conversion or data transmission. 
 */
typedef enum {
	ADI_ADP5300_SWITCHING_STOP,		/*!< Stop switching.         		 */
	ADI_ADP5300_SWITCHING_RESUME	/*!< Resume switching.        	     */
} ADI_ADP5300_SWITCHING;

/*!
 * @brief  Initialize the ADP5300.
 *
 * @details This function sets up the GPIO STOP and SYNC/MODE pins as MCU outputs and VOUTOK
 *		   as a GPIO input. It also sets the mode to hysteresis and resumes regulator switching.
 *
 * @return ADI_GPIO_RESULT.
 *                  - ADI_GPIO_SUCCESS             If successfully initialized.
 *                  - ADI_GPIO_NOT_INITIALIZED [D] If GPIO driver not yet initialized.
 *                  - ADI_GPIO_INVALID_PINS    [D] If the defined pins are invalid.
 * 
 * @note  adi_gpio_init() needs to be called before this function can be called as this 
 *		  driver uses the gpio.
 */
ADI_GPIO_RESULT adi_adp5300_Init();

/*!
 * @brief  Set the mode of the ADP5300.
 *
 * @details The ADP5300 includes a SYNC/MODE pin to allow flexible mode configuration. 
 *		    In PWM mode, the regulator can supply lower output noise for noise sensitive
 *			applications. In hysteresis mode, the regualtor can act as a keep-alive power 
 *			supply in a battery powered system, but with a relatively high output ripple.
 * 
 * @param  [in] eMode : Mode to set the ADP5300.
 *
 * @return ADI_GPIO_RESULT.
 *                  - ADI_GPIO_SUCCESS             If successfully set the mode.
 *                  - ADI_GPIO_NOT_INITIALIZED [D] If GPIO driver not yet initialized.
 *                  - ADI_GPIO_INVALID_PINS    [D] If the defined pins are invalid.
 */
ADI_GPIO_RESULT adi_adp5300_SetMode(ADI_ADP5300_MODE eMode);

/*!
 * @brief  Set the switching state of the ADP5300.
 *
 * @details The ADP5300 has an input STOP pin that can temporarily stop regulator
 *		    switching in hystersis mode, forcing the regulator to rely on the 
 *			output capacitor to supply the load. In this period, a quiet system
 *			can be acheived which benefits noise sensitive circuitry like an
 *			rf transmission or analog sensing.  
 *			Note: Swithing takes 10's of nanoseconds to fully stop.
 * 
 * @param  [in] bState : Switching state to set the ADP5300.
 *
 * @return ADI_GPIO_RESULT.
 *                  - ADI_GPIO_SUCCESS             If successfully set switching.
 *                  - ADI_GPIO_NOT_INITIALIZED [D] If GPIO driver not yet initialized.
 *                  - ADI_GPIO_INVALID_PINS    [D] If the defined pins are invalid.
 */
ADI_GPIO_RESULT adi_adp5300_SetSwitching(ADI_ADP5300_SWITCHING bState);

/*!
 * @brief  Enable/disable the VOUTOK interrupt.
 *
 * @details The ADP5300 has an output VOUTOK pin. When the regulated output
 *			voltage drops below 87% (typical) of its nominal output for a 
 *			delay time greater than approximately 10 Âµs, the VOUTOK pin goes 
 *          low. The MCU will be interrupted when this occurs to resume switching.
 * 
 * @param  [in] bEnable : Enable/Disable VOUTOK interrupt.
 *					- 1 : Enable IRQ.
 *					- 0 : Disable IRQ. 
 *
 * @return ADI_GPIO_RESULT.
 *                  - ADI_GPIO_SUCCESS             If successfully enabled the interrupt.
 *                  - ADI_GPIO_NOT_INITIALIZED [D] If GPIO driver not yet initialized.
 *                  - ADI_GPIO_INVALID_PINS    [D] If the defined pins are invalid.
 *
 * @note   This ADP5300 drivers owns the callback for this interrupt. When the VOUTOK pin 
 *		   drops below the threshold, the driver will be notified and will resume switching
 *		   automatically. 
 */
ADI_GPIO_RESULT adi_adp5300_EnableVoutokInt(uint8_t bEnable);

/*!
 * @brief  Read VOUTOK output pin.
 *
 * @details The ADP5300 has an output VOUTOK pin. When the regulated output
 *			voltage drops below 87% (typical) of its nominal output for a 
 *			delay time greater than approximately 10 Âµs, the VOUTOK pin goes 
 *          low. This function reads the status of that pin. 
 * 
 * @param  [out] pState : State of the VOUTOK pin.
 *					- 1 : VOUTOK high.
 *					- 0 : VOUTOK low. 
 *
 * @return ADI_GPIO_RESULT.
 *                  - ADI_GPIO_SUCCESS             If successfully read the pin state.
 *                  - ADI_GPIO_NOT_INITIALIZED [D] If GPIO driver not yet initialized.
 *                  - ADI_GPIO_INVALID_PINS    [D] If the defined pins are invalid.
 */
ADI_GPIO_RESULT adi_adp5300_ReadVoutokState(uint8_t * const pState);


/*! \cond PRIVATE */

/*!
 * @brief      Callback for the output power good signal.
 *
 * @details    This function is called when VOUTOK changes from high to low. This means that
 *             the voltage has dropped below a threshold.
 */
void VoutokCallback(void * pCBParam, uint32_t Event, void * pArg);

/*! \endcond */

/** @} */

#endif
