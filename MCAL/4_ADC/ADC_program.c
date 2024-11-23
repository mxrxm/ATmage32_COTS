
/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  ADC_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author: Mariem Ossama
 *   Layer: MCAL
 *   SWC: ADC
 *
 */
#ifndef _ADC_PROGRAM_C_
#define _ADC_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "VECTORS_private.h"
#include "DIO_interface.h"

#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"

static u16* ADC_pu16Reading=NULL;
static void (*ADC_pvoidCallBack)(void) = NULL;
static u8 ADC_ChainSize,ADC_ASYNCH_FLAG=0,ADC_u8Index;
static u16* ADC_ChainResult;
static u8* ADC_ChainChannnel;
static u8 ADC_u8BusyState=IDLE;

void ADC_voidInit(void) {
    /* Voltage reference mode */
    #if ADC_Voltage_Reference == ADC_External_VREF
        CLR_BIT(ADMUX, ADMUX_REFS1);
        CLR_BIT(ADMUX, ADMUX_REFS0);

    #elif ADC_Voltage_Reference == ADC_Internal_AVCC
        CLR_BIT(ADMUX, ADMUX_REFS1);
        SET_BIT(ADMUX, ADMUX_REFS0);

    #elif ADC_Voltage_Reference == ADC_Internal_2_56
        SET_BIT(ADMUX, ADMUX_REFS1);
        SET_BIT(ADMUX, ADMUX_REFS0);

    #endif

    /* ADC Resolution */
    #if ADC_RESOLUTION == EIGHT_BIT_RES
        SET_BIT(ADMUX, ADMUX_ADLAR);

    #elif ADC_RESOLUTION == TEN_BIT_RES
        CLR_BIT(ADMUX, ADMUX_ADLAR);

    #endif

    /* Prescaler selection */
        ADCSRA &= ADC_PRE_MASK ;
        ADCSRA |= ADC_PRESCALER ;

    /* Interrupt mode */
    #if ADC_INTERRUPT_MODE == ADC_INTERRUPT_DISABLE
        CLR_BIT(ADCSRA, ADCSRA_ADIE);

    #elif ADC_INTERRUPT_MODE == ADC_INTERRUPT_ENABLE
        SET_BIT(ADCSRA, ADCSRA_ADIE);
        /* ADC Trigger source na msh fahma aihh de */
        SFIOR = (SFIOR & 0x1F) | (ADC_TRIGGER & 0xE0);

    #endif

    /* Enable ADC */
    SET_BIT(ADCSRA, ADCSRA_ADEN);

}

void ADC_voidDisable (void)
{
	CLR_BIT(ADCSRA , ADCSRA_ADEN) ;
}
void ADC_voidEnable (void)
{
	SET_BIT(ADCSRA , ADCSRA_ADEN) ;
}

void ADC_voidInterruptEnable() {
    SET_BIT(ADCSRA, ADCSRA_ADIE);
}

void ADC_voidInterruptDisable() {
    CLR_BIT(ADCSRA, ADCSRA_ADIE);
}

u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler)
{
	u8 Local_u8ErrorState = OK ;

	if (Copy_u8Prescaler <= 128 && Copy_u8Prescaler%2==0)
	{
		/*Set Prescaler Value*/
		ADCSRA &= ADC_PRE_MASK ;
		ADCSRA |= Copy_u8Prescaler ;
	}
	else {
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionSynch(u8 copy_u8Channel,u16* Copy_u16Reading) {
	u32 Loc_u32Counter=0;
	u8 loc_u8Errorstate=OK;


	if(ADC_u8BusyState==IDLE)
	{
		ADMUX &=ADMUX_MASK;
		ADMUX |=copy_u8Channel; // Safely set channel

		/* Start conversion */
		SET_BIT(ADCSRA, ADCSRA_ADSC);

    	/*busy waiting (polling) on the flag*/
        while ((GET_BIT(ADCSRA, ADCSRA_ADIF) == 0)&&(Loc_u32Counter!=ADC_u32TIMEOUT))
        	{
        		Loc_u32Counter=Loc_u32Counter+1;
        	}

        if(Loc_u32Counter==ADC_u32TIMEOUT)
        {		/*Loop is broken because time out is reached*/
        			loc_u8Errorstate=NOK;
        }
        else
        {  		/*Loop is broken because flag is raised*/
        			/* Clear the flag */
					SET_BIT(ADCSRA, ADCSRA_ADIF);


				#if ADC_RESOLUTION == TEN_BIT_RES
					*Copy_u16Reading = TEN_BIT_MASK & ADC;

				#elif ADC_RESOLUTION == EIGHT_BIT_RES
					*Copy_u16Reading =ADCH;

				#endif
        }
	}
	else
	{
		loc_u8Errorstate=BUSY_FUNC;
	}
    return loc_u8Errorstate;
}
u8 ADC_u8StartConversionAsynch(u8 copy_u8Channel,void (*Copy_pvoidCallBack)(void),u16* Copy_pu16Reading)
{
	u8 loc_u8Errorstate=OK;

	if(ADC_u8BusyState==IDLE)
	{
		if((Copy_pvoidCallBack==NULL)||(Copy_pu16Reading==NULL))
		{
			loc_u8Errorstate=NULL_Pointer;
		}
		else
		{  	/*Set flag*/
			ADC_ASYNCH_FLAG=1;

			/*Set the Busy State to not work until being Idle*/
			ADC_u8BusyState=BUSY;

			/*Initialize the reading Global variable*/
			ADC_pu16Reading=Copy_pu16Reading;

			/*Initialize the Call back function Global variables*/
			ADC_pvoidCallBack=Copy_pvoidCallBack;

			/* Set the channel */
			ADMUX &=ADMUX_MASK;
			ADMUX |=copy_u8Channel;

			/* Start conversion */
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/*Enable ADC Interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
	}
	else
	{
		loc_u8Errorstate=BUSY_FUNC;
	}
	return loc_u8Errorstate;
}


 
u8 ADC_u8StartChainConversion( ADC_ChainType* Copy_Chain)
{		
	 u8 Local_u8ErrrorStatus=OK;

	 
	if(Copy_Chain && Copy_Chain->Channel && Copy_Chain->NotificationFunc && Copy_Chain->result) 
	{ 
		if ( ADC_u8BusyState==IDLE)
		{
			/* update the Busy state*/
			ADC_u8BusyState=BUSY;

			/*Set the ISR falg*/
			ADC_ASYNCH_FLAG=0;

			/*Intialize the Global data*/
			ADC_ChainChannnel=Copy_Chain->Channel;
			ADC_ChainSize=Copy_Chain->Size;
			ADC_ChainResult=Copy_Chain->result;
			ADC_pvoidCallBack=Copy_Chain->NotificationFunc;

			/*intailize the index*/
			ADC_u8Index=0;

			/*intialize the first channel*/
			ADMUX &=ADMUX_MASK;
			ADMUX |=ADC_ChainChannnel[ADC_u8Index];

			/*Start the first Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC Conversion Compelete Interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	else
		{
			Local_u8ErrrorStatus=BUSY_FUNC;
		}
	}
	else 
	{
		Local_u8ErrrorStatus=NULL_Pointer;
	}
	return Local_u8ErrrorStatus;
}



ISR(ADC_vect) {

	if(ADC_ASYNCH_FLAG==1){
		/*Read the ADC Result*/
		#if ADC_RESOLUTION == TEN_BIT_RES
			*ADC_pu16Reading = TEN_BIT_MASK & ADC;

		#elif ADC_RESOLUTION == EIGHT_BIT_RES
			*ADC_pu16Reading =ADCH;

		#endif
		/*return the ADC state to idle */
		ADC_u8BusyState=IDLE;

		/*Invoke the Callback notification function*/

		ADC_pvoidCallBack();

		/*Disable ADC conversion Complete Interrupt*/

		CLR_BIT(ADCSRA,ADCSRA_ADIE);

		/*Return */
	}
	else
	{
		if(ADC_u8Index==ADC_ChainSize){

		/*return the ADC state to idle */
		ADC_u8BusyState=IDLE;

		/*Invoke the Callback notification function*/
		ADC_pvoidCallBack();

		/*Disable ADC conversion Complete Interrupt*/
		CLR_BIT(ADCSRA,ADCSRA_ADIE);

		}
		else
		{
		/*Read the ADC Result*/
		#if ADC_RESOLUTION == TEN_BIT_RES
			ADC_ChainResult[ADC_u8Index] = TEN_BIT_MASK & ADC;

		#elif ADC_RESOLUTION == EIGHT_BIT_RES
			ADC_ChainResult[ADC_u8Index]=ADCH;

		#endif	
		
		/*Start the next Conversion*/
		ADMUX &= ADMUX_MASK ;
		ADMUX |= ADC_ChainChannnel[ADC_u8Index++] ;
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		}
	}

}
#endif /*_ADC_PROGRAM_C_*/

