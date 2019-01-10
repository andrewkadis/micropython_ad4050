/*!
 *****************************************************************************
  @file adi_adp5300.c

  @brief Defines the driver for the adp5300 voltage regulator
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
#include <drivers/voltage_regulator/adi_adp5300.h>


ADI_GPIO_RESULT adi_adp5300_Init()
{
	ADI_GPIO_RESULT 	eGpioResult;

	eGpioResult = adi_gpio_OutputEnable(ADI_ADP5300_MODE_PORT, ADI_ADP5300_MODE_PIN, true);
	
	if (eGpioResult == ADI_GPIO_SUCCESS)
	{
		eGpioResult = adi_gpio_OutputEnable(ADI_ADP5300_STOP_PORT, ADI_ADP5300_STOP_PIN, true);

		if (eGpioResult == ADI_GPIO_SUCCESS)
		{
			eGpioResult = adi_gpio_InputEnable(ADI_ADP5300_VOUTOK_PORT, ADI_ADP5300_VOUTOK_PIN, true);

			if (eGpioResult == ADI_GPIO_SUCCESS)
			{
				eGpioResult = adi_adp5300_SetMode(ADI_ADP5300_MODE_HYSTERESIS);

				if (eGpioResult == ADI_GPIO_SUCCESS)
				{
					return(adi_adp5300_SetSwitching(ADI_ADP5300_SWITCHING_RESUME));
				}
			}
		}
	}

	return(eGpioResult);
}


ADI_GPIO_RESULT adi_adp5300_SetMode(ADI_ADP5300_MODE eMode)
{
	if(eMode == ADI_ADP5300_MODE_HYSTERESIS)
	{
		return(adi_gpio_SetLow(ADI_ADP5300_MODE_PORT, ADI_ADP5300_MODE_PIN));
	}	
	else
	{
		return(adi_gpio_SetHigh(ADI_ADP5300_MODE_PORT, ADI_ADP5300_MODE_PIN));	
	}
}

ADI_GPIO_RESULT adi_adp5300_SetSwitching(ADI_ADP5300_SWITCHING bState)
{
	if(bState == ADI_ADP5300_SWITCHING_RESUME)
	{
		return(adi_gpio_SetLow(ADI_ADP5300_STOP_PORT, ADI_ADP5300_STOP_PIN));
	}	
	else
	{
		return(adi_gpio_SetHigh(ADI_ADP5300_STOP_PORT, ADI_ADP5300_STOP_PIN));	
	}
}

ADI_GPIO_RESULT adi_adp5300_EnableVoutokInt(uint8_t bEnable)
{
	ADI_GPIO_RESULT 	eGpioResult;

	if(bEnable == 1u)
	{
		eGpioResult = adi_gpio_RegisterCallback(ADI_VOUTOK_IRQ_GROUP, VoutokCallback, NULL);
	
		if (eGpioResult == ADI_GPIO_SUCCESS)
		{
			eGpioResult = adi_gpio_SetGroupInterruptPins(ADI_ADP5300_VOUTOK_PORT, ADI_VOUTOK_IRQ_GROUP, ADI_ADP5300_VOUTOK_PIN);

			if (eGpioResult == ADI_GPIO_SUCCESS)
			{
				return(adi_gpio_SetGroupInterruptPolarity(ADI_ADP5300_VOUTOK_PORT, 0u));
			}
		}
	}
	else
	{
		eGpioResult = adi_gpio_RegisterCallback(ADI_VOUTOK_IRQ_GROUP, NULL, NULL);

		if (eGpioResult == ADI_GPIO_SUCCESS)
		{
			return(eGpioResult = adi_gpio_SetGroupInterruptPins(ADI_ADP5300_VOUTOK_PORT, ADI_VOUTOK_IRQ_GROUP, 0u));
		}
	}

	return(eGpioResult);
}

ADI_GPIO_RESULT adi_adp5300_ReadVoutokState(uint8_t * const pState)
{
	ADI_GPIO_RESULT 	eGpioResult;
	uint16_t 			pValue;

	eGpioResult = adi_gpio_GetData(ADI_ADP5300_VOUTOK_PORT, ADI_ADP5300_VOUTOK_PIN, &pValue);

    if(pValue & ADI_ADP5300_VOUTOK_PIN)
    {
    	*pState = 1u;
    }
    else
    {
    	*pState = 0u;
    }

    return(eGpioResult);
}

/*! \cond PRIVATE */


void VoutokCallback(void * pCBParam, uint32_t Event, void * pArg)
{
	adi_adp5300_SetSwitching(ADI_ADP5300_SWITCHING_RESUME);
}

/*! \endcond */

