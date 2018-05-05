/*
 * D7Segmentos_Managger.c

 *
 *  Created on: Feb 14, 2018
 *      Author: PEDRO FIGUEROA
 */

#include "stdtypes.h"
#include "stdint.h"
#include "D7Segmentos_Managger.h"
#include "MKL25Z4.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

void D7Segmentos_Managger_Task(void)
{
	//PORTB Clock Source Enable
	CLOCK_EnableClock(kCLOCK_PortB);

	port_pin_config_t ls_LedGreenPinMux;
	ls_LedGreenPinMux.mux = kPORT_MuxAsGpio;

	//PIN Configuration
	PORT_SetPinConfig(PORTB, LED_GREEN_PIN_NUMBER, &ls_LedGreenPinMux);

	gpio_pin_config_t ls_LedGreenPinCfg;
	ls_LedGreenPinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedGreenPinCfg.outputLogic = FALSE;


	//PIN Initialization
	GPIO_PinInit(GPIOB, LED_GREEN_PIN_NUMBER, &ls_LedGreenPinCfg);

	return;
}
