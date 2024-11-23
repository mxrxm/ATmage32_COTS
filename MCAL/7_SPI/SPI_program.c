 
/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SPI_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author: Mariem Ossama
 *   Layer: MCAL
 *   SWC: SPI
 *
 */

#ifndef  _SPI_PROGRAM_C_
#define  _SPI_PROGRAM_C_


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "VECTORS_private.h"
#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_private.h"
#include "SPI_config.h"

static volatile u8 SPI_u8State=IDLE;
static void (*SPI_pvoidCallBack)(void) = NULL;

void SPI_voidMasterInit(void)
{
	/*SPI Clk Select*/
	#if 	SPI_CLK== SPI_CLK_2_PRESCALE
		SET_BIT(SPSR,SPSR_SPI2X);
		CLR_BIT(SPCR,SPCR_SPR1);	CLR_BIT(SPCR,SPCR_SPR0);
	#elif 	SPI_CLK== SPI_CLK_4_PRESCALE
		CLR_BIT(SPSR,SPSR_SPI2X);
		CLR_BIT(SPCR,SPCR_SPR1);	CLR_BIT(SPCR,SPCR_SPR0);
	#elif 	SPI_CLK== SPI_CLK_8_PRESCALE
		SET_BIT(SPSR,SPSR_SPI2X);
		CLR_BIT(SPCR,SPCR_SPR1);	SET_BIT(SPCR,SPCR_SPR0);
	#elif 	SPI_CLK== SPI_CLK_16_PRESCALE
		CLR_BIT(SPSR,SPSR_SPI2X);
		CLR_BIT(SPCR,SPCR_SPR1);	SET_BIT(SPCR,SPCR_SPR0);
	#elif 	SPI_CLK== SPI_CLK_32_PRESCALE
		SET_BIT(SPSR,SPSR_SPI2X);
		SET_BIT(SPCR,SPCR_SPR1);	CLR_BIT(SPCR,SPCR_SPR0);
	#elif 	SPI_CLK== SPI_CLK_64_PRESCALE
		CLR_BIT(SPSR,SPSR_SPI2X);
		SET_BIT(SPCR,SPCR_SPR1);	CLR_BIT(SPCR,SPCR_SPR0);
	#elif 	SPI_CLK== SPI_CLK_128_PRESCALE
		CLR_BIT(SPSR,SPSR_SPI2X);
		SET_BIT(SPCR,SPCR_SPR1);	SET_BIT(SPCR,SPCR_SPR0);
	#endif
/*Intialize the Data Mode*/
	#if 	SPI_DATA_MODE== SPI_RISING_SAMPLE_FALLING_SETUP
		CLR_BIT(SPCR,SPCR_CPOL);	CLR_BIT(SPCR,SPCR_CPHA);
	#elif 	SPI_DATA_MODE== SPI_RISING_SETUP_FALLING_SAMPLE
		CLR_BIT(SPCR,SPCR_CPOL);	SET_BIT(SPCR,SPCR_CPHA);
	#elif 	SPI_DATA_MODE== SPI_FALLING_SAMPLE_RISING_SETUP
		SET_BIT(SPCR,SPCR_CPOL);	CLR_BIT(SPCR,SPCR_CPHA);
	#elif 	SPI_DATA_MODE== SPI_FALLING_SETUP_RISING_SAMPLE
		SET_BIT(SPCR,SPCR_CPOL);	SET_BIT(SPCR,SPCR_CPHA);
	#endif
	/*Intialize the Data order*/
	 SPCR |=(SPI_DATA_ORDER<<SPCR_DORD);
	 /*Intialize the Interrupt mode*/
	 SPCR |=(SPI_INTERRUPT<<SPCR_SPIE);
	/*Select master*/
	SET_BIT(SPCR,SPCR_MSTR);
	 /*Enable the SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}
void SPI_voidSlaveInit(void)
{
	/*Set the Data Mode*/
#if 	SPI_DATA_MODE== SPI_RISING_SAMPLE_FALLING_SETUP
	CLR_BIT(SPCR,SPCR_CPOL);	CLR_BIT(SPCR,SPCR_CPHA);
#elif 	SPI_DATA_MODE== SPI_RISING_SETUP_FALLING_SAMPLE
	CLR_BIT(SPCR,SPCR_CPOL);	SET_BIT(SPCR,SPCR_CPHA);
#elif 	SPI_DATA_MODE== SPI_FALLING_SAMPLE_RISING_SETUP
	SET_BIT(SPCR,SPCR_CPOL);	CLR_BIT(SPCR,SPCR_CPHA);
#elif 	SPI_DATA_MODE== SPI_FALLING_SETUP_RISING_SAMPLE
	SET_BIT(SPCR,SPCR_CPOL);	SET_BIT(SPCR,SPCR_CPHA);
#endif
	/*Select Slave*/
	CLR_BIT(SPCR,SPCR_MSTR);
	 /*Enable the SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidEnable(void)
{
	SET_BIT(SPCR,SPCR_SPE);
}
void SPI_voidDisable(void)
{
	CLR_BIT(SPCR,SPCR_SPE);
}
void SPI_voidEnableInterrupt(void)
{
	SET_BIT(SPCR,SPCR_SPIE);
}
void SPI_voidDisableInterrupt(void)
{
	CLR_BIT(SPCR,SPCR_SPIE);
}

u8 SPI_u8Tranceive (u8 Copy_u8TData, u8 *Copy_u8RData)
{
    u8 Local_u8ErrorState = OK;
    u32 Local_uint32TimeoutCounter = 0;

    // Check if SPI is busy
    if (SPI_u8State == IDLE)
    {
        SPI_u8State = BUSY;
        SPDR = Copy_u8TData;
        // Wait for transmission to complete
        while (((GET_BIT(SPSR, SPSR_SPIF)) == 0) && (Local_uint32TimeoutCounter != SPI_TIMEOUT))
        {
            Local_uint32TimeoutCounter++;
        }

        // Check for timeout
        if (Local_uint32TimeoutCounter == SPI_TIMEOUT)
        {
            Local_u8ErrorState = NOK;
        }
        else
        {
            // Now that the previous transmission is complete, write new data
                *Copy_u8RData = SPDR;
                SPI_u8State = IDLE;
        }

    }
    else
    {
        Local_u8ErrorState = BUSY;
    }

    return Local_u8ErrorState;
}

u8 SPI_u8SetMasterOrSlave(u8 Copy_u8config )
{	u8 Local_u8ErrorStatus=OK;
		switch (Copy_u8config)
		{
		case SPI_SLAVE:		CLR_BIT(SPCR,SPCR_MSTR);	break;
		case SPI_MASTER: 	SET_BIT(SPCR,SPCR_MSTR);	break;
		default:	Local_u8ErrorStatus=NOK;			break;
		}
	return	Local_u8ErrorStatus;
}

u8 SPI_u8SetCallBack(void (*Copy_pvoidCallBack)(void))
{ 	u8 Local_u8ErrorStatus=OK;
		if(Copy_pvoidCallBack!=NULL)
		{
			SPI_pvoidCallBack=Copy_pvoidCallBack;
		}
		else
		{
			Local_u8ErrorStatus=NULL_Pointer;
		}
	return Local_u8ErrorStatus;
} 

ISR(SPI_STC)
{
	if(SPI_pvoidCallBack!=NULL){
		SPI_pvoidCallBack();
	}
}


#endif /*_SPI_PROGRAM_C_*/
