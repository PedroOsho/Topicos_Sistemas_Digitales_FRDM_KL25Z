/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "clock_config.h"
#include "pin_mux.h"
#include "fsl_adc16.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIO BOARD_LED_RED_GPIO
#define BOARD_LED_GPIO_PIN BOARD_LED_RED_GPIO_PIN

#define EXT_BOARD_LED_G_GPIO EXT_BOARD_LED_G_RED_GPIO
#define EXT_BOARD_LED_G_GPIO_PIN EXT_BOARD_LED_G_RED_GPIO_PIN

#define EXT_BOARD_LED_F_GPIO EXT_BOARD_LED_F_RED_GPIO
#define EXT_BOARD_LED_F_GPIO_PIN EXT_BOARD_LED_F_RED_GPIO_PIN

#define EXT_BOARD_LED_A_GPIO EXT_BOARD_LED_A_RED_GPIO
#define EXT_BOARD_LED_A_GPIO_PIN EXT_BOARD_LED_A_RED_GPIO_PIN

#define EXT_BOARD_LED_B_GPIO EXT_BOARD_LED_B_RED_GPIO
#define EXT_BOARD_LED_B_GPIO_PIN EXT_BOARD_LED_B_RED_GPIO_PIN

#define EXT_BOARD_LED_E_GPIO EXT_BOARD_LED_E_RED_GPIO
#define EXT_BOARD_LED_E_GPIO_PIN EXT_BOARD_LED_E_RED_GPIO_PIN

#define EXT_BOARD_LED_D_GPIO EXT_BOARD_LED_D_RED_GPIO
#define EXT_BOARD_LED_D_GPIO_PIN EXT_BOARD_LED_D_RED_GPIO_PIN

#define EXT_BOARD_LED_C_GPIO EXT_BOARD_LED_C_RED_GPIO
#define EXT_BOARD_LED_C_GPIO_PIN EXT_BOARD_LED_C_RED_GPIO_PIN

#define BUTTON_PLUS BUTON_PLUS_1
#define BUTTON_PLUS_PIN BUTON_PLUS_PIN1

#define BUTTON_RESET BUTON_RESET_1
#define BUTTON_RESET_PIN BUTON_RESET_PIN1

#define BUTTON_SUB BUTON_SUB_1
#define BUTTON_SUB_PIN BUTON_SUB_PIN1

#define TRUE 1u
#define FALSE 0u

#define T_SBYTE int8_t



/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief delay a while.
 */
void delay(void);
void Disp_7_seg(T_SBYTE lsb_Digito);

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile T_SBYTE rsb_Digito_unidad = 0;
/*******************************************************************************
 * Code
 ******************************************************************************/
void delay(void)
{
    volatile uint32_t lsb_Tiempo = 0;
    for (lsb_Tiempo = 0; lsb_Tiempo < 1100000; ++lsb_Tiempo)
    {
        __asm("NOP"); /* delay */
    }
}
void Disp_7_seg(T_SBYTE lsb_Digito){

	if(lsb_Digito==0)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);


	}
	else if(lsb_Digito==1)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);


	}
	else if(lsb_Digito==2)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);


	}
	else if(lsb_Digito==3)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

	}
	else if(lsb_Digito==4)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

	}

	else if(lsb_Digito==5)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

	}
	else if(lsb_Digito==6)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

	}
	else if(lsb_Digito==7)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

	}
	else if(lsb_Digito==8)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

	}
	else if(lsb_Digito==9)
	{
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

        GPIO_SetPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);

	}
	else
	{

	}
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput, 0,
    };
    gpio_pin_config_t button_config = {
    	kGPIO_DigitalInput, 0,
        };

    /* Board pin, clock, debug console init */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Init output LED GPIO. */
    //GPIO_PinInit(BOARD_LED_GPIO, BOARD_LED_GPIO_PIN, &led_config);
    GPIO_PinInit( EXT_BOARD_LED_G_GPIO, EXT_BOARD_LED_G_GPIO_PIN, &led_config);
    GPIO_PinInit( EXT_BOARD_LED_F_GPIO, EXT_BOARD_LED_F_GPIO_PIN, &led_config);
    GPIO_PinInit( EXT_BOARD_LED_A_GPIO, EXT_BOARD_LED_A_GPIO_PIN, &led_config);
    GPIO_PinInit( EXT_BOARD_LED_B_GPIO, EXT_BOARD_LED_B_GPIO_PIN, &led_config);
    GPIO_PinInit( EXT_BOARD_LED_E_GPIO, EXT_BOARD_LED_E_GPIO_PIN, &led_config);
    GPIO_PinInit( EXT_BOARD_LED_D_GPIO, EXT_BOARD_LED_D_GPIO_PIN, &led_config);
    GPIO_PinInit( EXT_BOARD_LED_C_GPIO, EXT_BOARD_LED_C_GPIO_PIN, &led_config);

    GPIO_PinInit( BUTTON_PLUS, BUTTON_PLUS_PIN, &button_config);
    GPIO_PinInit( BUTTON_RESET, BUTTON_RESET_PIN, &button_config);
    GPIO_PinInit( BUTTON_SUB, BUTTON_SUB_PIN, &button_config);


    while (1)
    {

    	if(rsb_Digito_unidad>9)
    	{
    		rsb_Digito_unidad=0;
    	}
    	if(rsb_Digito_unidad<0)
    	{
    		rsb_Digito_unidad=9;
    	}


    	Disp_7_seg(rsb_Digito_unidad);

    	if(GPIO_ReadPinInput(BUTTON_PLUS, BUTTON_PLUS_PIN)==TRUE)
    	{
    		while(GPIO_ReadPinInput(BUTTON_PLUS, BUTTON_PLUS_PIN)==TRUE)
    		{
    			//wait
    		}
    		rsb_Digito_unidad++;
    	}
    	if(GPIO_ReadPinInput(BUTTON_RESET, BUTTON_RESET_PIN)==TRUE)
    	{
    		while(GPIO_ReadPinInput(BUTTON_RESET, BUTTON_RESET_PIN)==TRUE)
    		{
    			//wait
    		}
    		rsb_Digito_unidad=0;
    	}
    	if(GPIO_ReadPinInput(BUTTON_SUB, BUTTON_SUB_PIN)==TRUE)
    	{
    		while(GPIO_ReadPinInput(BUTTON_SUB, BUTTON_SUB_PIN)==TRUE)
    		{
    			//wait
    		}
    		rsb_Digito_unidad--;
    	}
    }
}

/*  delay();
        GPIO_SetPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_SetPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);
        //GPIO_SetPinsOutput(BOARD_LED_GPIO, 1u << BOARD_LED_GPIO_PIN);
        delay();
        //GPIO_ClearPinsOutput(BOARD_LED_GPIO, 1u << BOARD_LED_GPIO_PIN);
        //GPIO_TogglePinsOutput(BOARD_LED_GPIO, 1u << BOARD_LED_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_G_GPIO, 1u << EXT_BOARD_LED_G_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_F_GPIO, 1u << EXT_BOARD_LED_F_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_A_GPIO, 1u << EXT_BOARD_LED_A_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_B_GPIO, 1u << EXT_BOARD_LED_B_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_E_GPIO, 1u << EXT_BOARD_LED_E_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_D_GPIO, 1u << EXT_BOARD_LED_D_GPIO_PIN);
        GPIO_ClearPinsOutput(EXT_BOARD_LED_C_GPIO, 1u << EXT_BOARD_LED_C_GPIO_PIN);
        */
