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

#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_tpm.h"

#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_TPM_BASEADDR TPM1

/* TPM channel used for input capture */
#define BOARD_TPM_INPUT_CAPTURE_CHANNEL kTPM_Chnl_0

/* Interrupt number and interrupt handler for the TPM instance used */
#define TPM_INTERRUPT_NUMBER TPM1_IRQn
#define TPM_INPUT_CAPTURE_HANDLER TPM1_IRQHandler

/* Interrupt to enable and flag to read; depends on the TPM channel used */
#define TPM_CHANNEL_INTERRUPT_ENABLE kTPM_Chnl0InterruptEnable
#define TPM_CHANNEL_FLAG kTPM_Chnl0Flag

#define BOARD_TPM_IRQ_NUM TPM2_IRQn
#define BOARD_TPM_HANDLER TPM2_IRQHandler
/* Get source clock for TPM driver */
#define TPM_SOURCE_CLOCK (CLOCK_GetFreq(kCLOCK_PllFllSelClk)/4)
#define BOARD_TPM TPM2

#define RX_LIN_PORT RX_LIN_PORT_
#define RX_LIN_PIN	RX_LIN_PIN_

#define BIT_RATED_19200 651
#define BIT_RATED_28800 434
#define BIT_RATED_14400 868
#define BIT_RATED_9600 	1302

#define MI_ID 0xD

#define T_BIT	bool


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void Slave_MS(uint8_t CASES);
void BRAKE_FUNCT(void);
void SYNC_FUNCT(void);
void ID_FUNCT(void);
void DATA_FUNCT(void);
void CS_FUNCT(void);
void ERROR_FUNCT(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile bool tpmIsrFlag = false;
T_BIT		rbi_tpmIsrFlag = false;
uint32_t 	BIT_RATED=0;

T_BIT		BRAKE_ARRAY[13];
uint8_t		BRAKE_ARRAY_POSITION=0;

T_BIT 		SYNC_ARRAY[8];
uint8_t		SYNC_ARRAY_POSITION=0;

uint8_t		ID_ARRAY_POSITION=0;
uint8_t		ID_BYTE=0;

uint8_t		DATA_LONG=0;

enum State_enum {
    BRAKE,
    SYNC,
    ID,
	DATA,
	CS
};
/*******************************************************************************
 * Code
 ******************************************************************************/
void TPM_INPUT_CAPTURE_HANDLER(void)
{
	BIT_RATED=0;
    tpmIsrFlag = true;
    while (tpmIsrFlag != true)
    {}
    Slave_MS(BRAKE);
    tpmIsrFlag=false;
    /* Clear interrupt flag.*/
    TPM_ClearStatusFlags(DEMO_TPM_BASEADDR, TPM_CHANNEL_FLAG);
}
void BOARD_TPM_HANDLER(void)
{
    /* Clear interrupt flag.*/

    TPM_ClearStatusFlags(BOARD_TPM, kTPM_TimeOverflowFlag);
    BIT_RATED ++;
    //rbi_tpmIsrFlag = TRUE;
}

/*!
 * @brief Main function
 */
int main(void)
{
    tpm_config_t tpmInfo;
    tpm_config_t tpmInfo2;


    /* Board pin, clock, debug console init */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Select the clock source for the TPM counter as kCLOCK_PllFllSelClk */
    CLOCK_SetTpmClock(1U);

    /* Print a note to terminal */
    PRINTF("\r\nTPM input capture example\r\n");
    PRINTF("\r\nOnce the input signal is received the input capture value is printed\r\n");

    TPM_GetDefaultConfig(&tpmInfo);
    /* Initialize TPM module */
    TPM_Init(DEMO_TPM_BASEADDR, &tpmInfo);
    /* Setup input capture on a TPM channel */
    TPM_SetupInputCapture(DEMO_TPM_BASEADDR, BOARD_TPM_INPUT_CAPTURE_CHANNEL, kTPM_FallingEdge);
    /* Set the timer to be in free-running mode */
    DEMO_TPM_BASEADDR->MOD = 0xFFFF;
    /* Enable channel interrupt when the second edge is detected */
    TPM_EnableInterrupts(DEMO_TPM_BASEADDR, TPM_CHANNEL_INTERRUPT_ENABLE);
    /* Enable at the NVIC */
    EnableIRQ(TPM_INTERRUPT_NUMBER);
    TPM_StartTimer(DEMO_TPM_BASEADDR, kTPM_SystemClock);

    TPM_GetDefaultConfig(&tpmInfo2);
	/* TPM clock divide by 4 */
    tpmInfo2.prescale = kTPM_Prescale_Divide_4;
    /* Initialize TPM module */
    TPM_Init(BOARD_TPM, &tpmInfo2);
    /*
     * Set timer period.
     */
    TPM_SetTimerPeriod(BOARD_TPM, USEC_TO_COUNT(1U, TPM_SOURCE_CLOCK/1000));
    TPM_EnableInterrupts(BOARD_TPM, kTPM_TimeOverflowInterruptEnable);
    EnableIRQ(BOARD_TPM_IRQ_NUM);
    TPM_StartTimer(BOARD_TPM, kTPM_SystemClock);


    while (1)
    {

    }
}


void Slave_MS(uint8_t CASES)
{
	switch(CASES){
	case BRAKE:
		BRAKE_FUNCT();
		break;
	case SYNC:
		SYNC_FUNCT();
		break;
	case ID:
		ID_FUNCT();
		break;
	case DATA:
		DATA_FUNCT();
		break;
	case CS:
		CS_FUNCT();
		break;
	default:
		ERROR_FUNCT();
		break;
	}
}
void BRAKE_FUNCT(void){

		if(BRAKE_ARRAY_POSITION<8){
				if(BIT_RATED >= BIT_RATED_19200)
				{
					//escribir el valor del puerto en BRAKE_ARRAY[BRAKE_ARRAY_POSITION]
					if(GPIO_ReadPinInput(RX_LIN_PORT, RX_LIN_PIN)==0){
					BRAKE_ARRAY[BRAKE_ARRAY_POSITION]=0;
					BRAKE_ARRAY_POSITION++;
					BIT_RATED=0;
					Slave_MS(BRAKE);
					}
					else
					{
						BRAKE_ARRAY_POSITION=0;
						BIT_RATED=0;
					}
				}

		}
		else if (BRAKE_ARRAY_POSITION>7 && BRAKE_ARRAY_POSITION<10){
				if(BIT_RATED >= BIT_RATED_28800)
				{
					//escribir el valor del puerto en BRAKE_ARRAY[BRAKE_ARRAY_POSITION]
					if(GPIO_ReadPinInput(RX_LIN_PORT, RX_LIN_PIN)==0){
					BRAKE_ARRAY[BRAKE_ARRAY_POSITION]=0;
					BRAKE_ARRAY_POSITION++;
					BIT_RATED=0;
					Slave_MS(BRAKE);
					}
					else
					{
						BRAKE_ARRAY_POSITION=0;
						BIT_RATED=0;
					}
				}

		}
		else if (BRAKE_ARRAY_POSITION>9 && BRAKE_ARRAY_POSITION<13){
				if(BIT_RATED >= BIT_RATED_14400)
				{
					if(GPIO_ReadPinInput(RX_LIN_PORT, RX_LIN_PIN)==0){
					BRAKE_ARRAY[BRAKE_ARRAY_POSITION]=0;
					BRAKE_ARRAY_POSITION++;
					BIT_RATED=0;
					Slave_MS(BRAKE);
					}
					else
					{
						BRAKE_ARRAY_POSITION=0;
						BIT_RATED=0;
					}
				}
		}
		else if (BRAKE_ARRAY_POSITION>13)
		{
			BRAKE_ARRAY_POSITION=0;
			BIT_RATED=0;
			Slave_MS(SYNC);
		}
		else{}
}

void SYNC_FUNCT(void){
	if(BRAKE_ARRAY_POSITION<8){
					if(BIT_RATED >= BIT_RATED_9600)
					{
						//escribir el valor del puerto en BRAKE_ARRAY[BRAKE_ARRAY_POSITION]
						if(GPIO_ReadPinInput(RX_LIN_PORT, RX_LIN_PIN)==0){
						SYNC_ARRAY[SYNC_ARRAY_POSITION]=0;
						BRAKE_ARRAY_POSITION++;
						BIT_RATED=0;
						}
						else
						{
						SYNC_ARRAY[SYNC_ARRAY_POSITION]=1;
						BRAKE_ARRAY_POSITION++;
						BIT_RATED=0;
						}
					}
					Slave_MS(SYNC);
	}
	else
	{
		SYNC_ARRAY_POSITION=0;
		BIT_RATED=0;

		if(SYNC_ARRAY[0] == 1 && SYNC_ARRAY[1] == 0 && SYNC_ARRAY[2] == 1 && SYNC_ARRAY[3] == 0 && SYNC_ARRAY[4] == 1 && SYNC_ARRAY[5] == 0 && SYNC_ARRAY[6] == 1 && SYNC_ARRAY[7] == 0)
		{
		Slave_MS(ID);
		}
	}
}
void ID_FUNCT(void){
	if(ID_ARRAY_POSITION<8){
		if(BIT_RATED >= BIT_RATED_9600)
		{
		ID_BYTE<<=1;
		ID_BYTE=+GPIO_ReadPinInput(RX_LIN_PORT, RX_LIN_PIN);
		ID_ARRAY_POSITION++;
		Slave_MS(ID);
		}
	}
	else{
		BIT_RATED=0;
		ID_ARRAY_POSITION=0;

		if(ID_BYTE>>4 == MI_ID){
			if((ID_BYTE & 0x0C) == 0x00 && (ID_BYTE & 0x0C) == 0x04){
				DATA_LONG=2;
			}
			else if((ID_BYTE & 0x0C) == 0x08){
				DATA_LONG=4;
			}
			else if((ID_BYTE & 0x0C) == 0x0C){
				DATA_LONG=8
			}
			else{}
			Slave_MS(DATA_FUNCT);
		}
		else{
		}
	}
}
void DATA_FUNCT(void){}
void CS_FUNCT(void){}
void ERROR_FUNCT(){}
