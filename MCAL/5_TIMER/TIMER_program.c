
/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TIMER_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author: Mariem Ossama
 *   Layer: MCAL
 *   SWC: TIMER
 *
 */

#ifndef  _TIMER_PROGRAM_C_
#define  _TIMER_PROGRAM_C_


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "VECTORS_private.h"
#include "DIO_interface.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"



 static void (*TIMER_CallBack[8])(void)={NULL};

/*****************************************************************************************************************/
/*TIMER0*/
 void TIMER0_voidInit(void)
 {
	 /*Initialize registers*/
		#ifdef TIMER0_PRELOAD
			TCNT0=TIMER0_PRELOAD;
		#endif

		#ifdef TIMER0_OCR
			OCR0=TIMER0_OCR;
		#endif
	 /*Set the wave form generation mode*/
	#if TIMER0_WAVEFORM_MODE==TIMER_NORMAL

	    CLR_BIT(TCCR0,TCCR0_WGM01); 	CLR_BIT(TCCR0,TCCR0_WGM00);

	#elif TIMER0_WAVEFORM_MODE==TIMER_PHASE_CORRECT_PWM

	    CLR_BIT(TCCR0,TCCR0_WGM01); 	SET_BIT(TCCR0,TCCR0_WGM00);	

	#elif TIMER0_WAVEFORM_MODE==TIMER_CTC

	    SET_BIT(TCCR0,TCCR0_WGM01); 	CLR_BIT(TCCR0,TCCR0_WGM00);	

	#elif TIMER0_WAVEFORM_MODE==TIMER_FAST_PWM

	    SET_BIT(TCCR0,TCCR0_WGM01); 	SET_BIT(TCCR0,TCCR0_WGM00);	
	 #endif

	/*Set the OC0 mode*/
	#if   TIMER0_OCO_MODE==OC_DISCONNECTED

		CLR_BIT(TCCR0,TCCR0_COM01);		CLR_BIT(TCCR0,TCCR0_COM00);

	#elif TIMER0_OCO_MODE==CTC_TOGGLE_OC

		CLR_BIT(TCCR0,TCCR0_COM01);		SET_BIT(TCCR0,TCCR0_COM00);	

	#elif TIMER0_OCO_MODE==CTC_CLEAR_OC || TIMER0_OCO_MODE==NON_INVERTING_FAST_PWM ||TIMER0_OCO_MODE==NON_INVERTING_PHASE_CORRECT_PWM

		SET_BIT(TCCR0,TCCR0_COM01);		CLR_BIT(TCCR0,TCCR0_COM00);

	#elif TIMER0_OCO_MODE==CTC_SET_OC || TIMER0_OCO_MODE==INVERTING_FAST_PWM ||TIMER0_OCO_MODE==INVERTING_PHASE_CORRECT_PWM

		SET_BIT(TCCR0,TCCR0_COM01);		SET_BIT(TCCR0,TCCR0_COM00);
 
	#endif

	/*Select Timer CLK PRE-Scale*/
		/*Mask the most 5 significant bits */
	   		TCCR0 &=PRESCALE_MASK;
		/*Set the least significant bits*/
		   TCCR0 |=TIMER0_PRESCALE;

	/*Set the Interrupt mode*/
		#if TIMER0_OVERFLOW_INTERRUPT==ENABLE
			SET_BIT(TIMSK, TIMSK_TOIE0);

		#elif TIMER0_OVERFLOW_INTERRUPT==DISABLE
			CLR_BIT(TIMSK, TIMSK_TOIE0);

		#endif

		#if TIMER0_CTC_INTERRUPT==ENABLE
			SET_BIT(TIMSK, TIMSK_OCIE0);

		#elif TIMER0_CTC_INTERRUPT==DISABLE
			CLR_BIT(TIMSK, TIMSK_OCIE0);

		#endif

 }
 
void TIMER0_voidSetPreload (u8 Copy_u8Preload) 
{
	TCNT0=Copy_u8Preload;
}
void TIMER0_voidSetCTC (u8 Copy_u8CTC) 
{
	OCR0=Copy_u8CTC;
}
u8   TIMER0_u8GetTimerCounterValue()
{
	return TCNT0;
} 
void TIMER0_voidForceCompare (void)
{
	SET_BIT(TCCR0,TCCR0_FOC0);
}

/*****************************************************************************************************************/
/*TIMER1*/
void TIMER1_voidInit(void)
{		
	/*Initialize registers*/
		#ifdef TIMER1_PRELOAD
			TCNT1=TIMER1_PRELOAD;
		#endif

		#ifdef TIMER1_OCRA
			OCR1A=TIMER1_OCRA;
		#endif

		#ifdef TIMER1_OCRB
			OCR1B=TIMER1_OCRB;
		#endif

		#ifdef TIMER1_ICR1
			ICR1=TIMER1_ICR1;
		#endif

	/*Select Timer1 wave generation mode*/

		#if TIMER1_WAVEFORM_MODE==TIMER1_NORMAL   
			CLR_BIT(TCCR1A,TCCR1A_WGM11);	CLR_BIT(TCCR1A,TCCR1A_WGM10);      
			CLR_BIT(TCCR1B,TCCR1B_WGM13);	CLR_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_PWM_8_BIT_MODE 
			CLR_BIT(TCCR1A,TCCR1A_WGM11);	SET_BIT(TCCR1A,TCCR1A_WGM10);      
			CLR_BIT(TCCR1B,TCCR1B_WGM13);	CLR_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_PWM_9_BIT_MODE
			SET_BIT(TCCR1A,TCCR1A_WGM11);	CLR_BIT(TCCR1A,TCCR1A_WGM10);      
			CLR_BIT(TCCR1B,TCCR1B_WGM13);	CLR_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_PWM_10_BIT_MODE
			SET_BIT(TCCR1A,TCCR1A_WGM11);	SET_BIT(TCCR1A,TCCR1A_WGM10);      
			CLR_BIT(TCCR1B,TCCR1B_WGM13);	CLR_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_CTC_OCR1A_MODE
			CLR_BIT(TCCR1A,TCCR1A_WGM11);	CLR_BIT(TCCR1A,TCCR1A_WGM10);      
			CLR_BIT(TCCR1B,TCCR1B_WGM13);	SET_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_FAST_PWM_8_BIT_MODE
			CLR_BIT(TCCR1A,TCCR1A_WGM11);	SET_BIT(TCCR1A,TCCR1A_WGM10);      
			CLR_BIT(TCCR1B,TCCR1B_WGM13);	SET_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_FAST_PWM_9_BIT_MODE
			SET_BIT(TCCR1A,TCCR1A_WGM11);	CLR_BIT(TCCR1A,TCCR1A_WGM10);      
			CLR_BIT(TCCR1B,TCCR1B_WGM13);	SET_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_FAST_PWM_10_BIT_MODE
			SET_BIT(TCCR1A,TCCR1A_WGM11);	SET_BIT(TCCR1A,TCCR1A_WGM10);      
			CLR_BIT(TCCR1B,TCCR1B_WGM13);	SET_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
			CLR_BIT(TCCR1A,TCCR1A_WGM11);	CLR_BIT(TCCR1A,TCCR1A_WGM10);      
			SET_BIT(TCCR1B,TCCR1B_WGM13);	CLR_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
			CLR_BIT(TCCR1A,TCCR1A_WGM11);	SET_BIT(TCCR1A,TCCR1A_WGM10);      
			SET_BIT(TCCR1B,TCCR1B_WGM13);	CLR_BIT(TCCR1B,TCCR1B_WGM12);    

		#elif TIMER1_WAVEFORM_MODE==TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
			SET_BIT(TCCR1A,TCCR1A_WGM11);	CLR_BIT(TCCR1A,TCCR1A_WGM10);      
			SET_BIT(TCCR1B,TCCR1B_WGM13);	CLR_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
			SET_BIT(TCCR1A,TCCR1A_WGM11);	SET_BIT(TCCR1A,TCCR1A_WGM10);      
			SET_BIT(TCCR1B,TCCR1B_WGM13);	CLR_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_CTC_ICR1_MODE
			CLR_BIT(TCCR1A,TCCR1A_WGM11);	CLR_BIT(TCCR1A,TCCR1A_WGM10);      
			SET_BIT(TCCR1B,TCCR1B_WGM13);	SET_BIT(TCCR1B,TCCR1B_WGM12);

		#elif TIMER1_WAVEFORM_MODE==TIMER1_FAST_PWM_ICR1_MODE       
			SET_BIT(TCCR1A,TCCR1A_WGM11);	CLR_BIT(TCCR1A,TCCR1A_WGM10);      
			SET_BIT(TCCR1B,TCCR1B_WGM13);	SET_BIT(TCCR1B,TCCR1B_WGM12);
				#if TIMER1_ICR1_TRIGGER==TIMER_FALLING_EDGE
					CLR_BIT(TCCR1B,TCCR1B_ICES1);
				#elif TIMER1_ICR1_TRIGGER==TIMER_RISING_EDGE
					SET_BIT(TCCR1B,TCCR1B_ICES1);
				#endif

		#elif TIMER1_WAVEFORM_MODE==TIMER1_FAST_PWM_OCR1A_MODE    
			SET_BIT(TCCR1A,TCCR1A_WGM11);	SET_BIT(TCCR1A,TCCR1A_WGM10);      
			SET_BIT(TCCR1B,TCCR1B_WGM13);	SET_BIT(TCCR1B,TCCR1B_WGM12);

		#endif      

			/*Set the OC1A mode*/
	#if   TIMER1_OC1A_MODE==OC_DISCONNECTED

		CLR_BIT(TCCR1A,TCCR1A_COM1A1);		CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	#elif TIMER1_OC1A_MODE==CTC_TOGGLE_OC

		CLR_BIT(TCCR1A,TCCR1A_COM1A1);		SET_BIT(TCCR1A,TCCR1A_COM1A0);	

	#elif TIMER1_OC1A_MODE==CTC_CLEAR_OC || TIMER1_OC1A_MODE==NON_INVERTING_FAST_PWM || TIMER1_OC1A_MODE==NON_INVERTING_PHASE_CORRECT_PWM

		SET_BIT(TCCR1A,TCCR1A_COM1A1);		CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	#elif TIMER1_OC1A_MODE==CTC_SET_OC || TIMER1_OC1A_MODE==INVERTING_FAST_PWM || TIMER1_OC1A_MODE==INVERTING_PHASE_CORRECT_PWM

		SET_BIT(TCCR1A,TCCR1A_COM1A1);		SET_BIT(TCCR1A,TCCR1A_COM1A0);
 
	#endif	

		/*Set the OC1B mode*/
	#if   TIMER1_OC1B_MODE==OC_DISCONNECTED

		CLR_BIT(TCCR1B,TCCR1A_COM1B1);		CLR_BIT(TCCR1B,TCCR1A_COM1B0);

	#elif TIMER1_OC1B_MODE==CTC_TOGGLE_OC

		CLR_BIT(TCCR1B,TCCR1A_COM1B1);		SET_BIT(TCCR1B,TCCR1A_COM1B0);	

	#elif TIMER1_OC1B_MODE==CTC_CLEAR_OC || TIMER1_OC1B_MODE==NON_INVERTING_FAST_PWM || TIMER1_OC1B_MODE==NON_INVERTING_PHASE_CORRECT_PWM

		SET_BIT(TCCR1B,TCCR1A_COM1B1);		CLR_BIT(TCCR1B,TCCR1A_COM1B0);

	#elif TIMER1_OC1B_MODE==CTC_SET_OC || TIMER1_OC1B_MODE==INVERTING_FAST_PWM || TIMER1_OC1B_MODE==INVERTING_PHASE_CORRECT_PWM

		SET_BIT(TCCR1B,TCCR1A_COM1B1);		SET_BIT(TCCR1B,TCCR1A_COM1B0);
 
	#endif			            


	/*Select Timer CLK PRE-Scale */
		/*Mask the most 5 significant bits */
	   		TCCR1B &=PRESCALE_MASK;
		/*Set the least significant bits*/
	   		TCCR1B |=TIMER1_PRESCALE;

	/*Set the Interrupt mode */
		#if  TIMER1_OVERFLOW_INTERRUPT== ENABLE
			SET_BIT(TIMSK,TIMSK_TOIE1);

		#elif TIMER1_OVERFLOW_INTERRUPT== DISABLE
			CLR_BIT(TIMSK,TIMSK_TOIE1);

		#endif

		#if TIMER1_CTCB_INTERRUPT	== ENABLE
			SET_BIT(TIMSK,TIMSK_OCIE1B);

		#elif TIMER1_CTCB_INTERRUPT	== DISABLE
			CLR_BIT(TIMSK,TIMSK_OCIE1B);

		#endif 

		#if TIMER1_CTCA_INTERRUPT	== ENABLE
			SET_BIT(TIMSK,TIMSK_OCIE1A);

		#elif TIMER1_CTCA_INTERRUPT	== DISABLE
			CLR_BIT(TIMSK,TIMSK_OCIE1A);

		#endif
		
		#if TIMER1_ICR_INTERRUPT	== ENABLE
			SET_BIT(TIMSK,TIMSK_TICIE1);

		#elif TIMER1_ICR_INTERRUPT	== DISABLE
			CLR_BIT(TIMSK,TIMSK_TICIE1);

		#endif
}
void TIMER1_voidSetPreload (u16 Copy_u16Preload) 
{
	TCNT1=Copy_u16Preload;
}
void TIMER1_voidSetCTCA (u16 Copy_u16CTC) 
{
	OCR1A=Copy_u16CTC;
}
void TIMER1_voidSetCTCB (u16 Copy_u16CTC) 
{
	OCR1B=Copy_u16CTC;
}
u16  TIMER1_u16GetTimerCounterValue (void)
{
	return TCNT1;
}
void TIMER1_voidSetICR1 (u16 Copy_u16ICR1)
{
	ICR1=Copy_u16ICR1;
}
u16  TIMER1_u16GetICR(void)
{
	return ICR1;
}
void TIMER1_voidForceCompareA (void)
{
	SET_BIT(TCCR1A,TCCR1A_FOC1A);
}
void TIMER1_voidForceCompareB (void)
{
	SET_BIT(TCCR1A,TCCR1A_FOC1B);
}
/*****************************************************************************************************/
/*INPUT CAPTURE UNIT*/
void ICU_voidInit(void)
{
	/*Set the edge trigger for the ICU*/
	#if TIMER1_ICR1_TRIGGER==TIMER_FALLING_EDGE
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	#elif TIMER1_ICR1_TRIGGER==TIMER_RISING_EDGE
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	#endif

	/*Enable the ICU*/
	SET_BIT(TIMSK,TIMSK_TICIE1);


}
u8   ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Edge){
	case TIMER_FALLING_EDGE:	CLR_BIT(TCCR1B,TCCR1B_ICES1); break;
	case TIMER_RISING_EDGE:		SET_BIT(TCCR1B,TCCR1B_ICES1); break;
	default: Local_u8ErrorState=NOK;	 break;
	}
	return Local_u8ErrorState;

}
void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
/*****************************************************************************************************/
/*TIMER2*/
void TIMER2_voidInit(void)
{
	 /*Initialize registers*/
		#ifdef TIMER2_PRELOAD
			TCNT2=TIMER2_PRELOAD;
		#endif

		#ifdef TIMER2_OCR
			OCR2=TIMER2_OCR;
		#endif
		 /*Set the wave form generation mode*/
	#if TIMER2_WAVEFORM_MODE==TIMER_NORMAL

	    CLR_BIT(TCCR2,TCCR2_WGM21); 	CLR_BIT(TCCR2,TCCR2_WGM20);

	#elif TIMER2_WAVEFORM_MODE==TIMER_PHASE_CORRECT_PWM

	    CLR_BIT(TCCR2,TCCR2_WGM21); 	SET_BIT(TCCR2,TCCR2_WGM20);	

	#elif TIMER2_WAVEFORM_MODE==TIMER_CTC

	    SET_BIT(TCCR2,TCCR2_WGM21); 	CLR_BIT(TCCR2,TCCR2_WGM20);	

	#elif TIMER2_WAVEFORM_MODE==TIMER_FAST_PWM

	    SET_BIT(TCCR2,TCCR2_WGM21); 	SET_BIT(TCCR2,TCCR2_WGM20);	

	 #endif

	/*Set the OC2 mode*/
	#if   TIMER2_OC2_MODE==OC_DISCONNECTED

		CLR_BIT(TCCR2,TCCR2_COM21);		CLR_BIT(TCCR2,TCCR2_COM20);

	#elif TIMER2_OC2_MODE==CTC_TOGGLE_OC

		CLR_BIT(TCCR2,TCCR2_COM21);		SET_BIT(TCCR2,TCCR2_COM20);	

	#elif TIMER2_OC2_MODE==CTC_CLEAR_OC || TIMER2_OC2_MODE==NON_INVERTING_FAST_PWM ||TIMER2_OC2_MODE==NON_INVERTING_PHASE_CORRECT_PWM

		SET_BIT(TCCR2,TCCR2_COM21);		CLR_BIT(TCCR2,TCCR2_COM20);

	#elif TIMER2_OC2_MODE==CTC_SET_OC || TIMER2_OC2_MODE==INVERTING_FAST_PWM ||TIMER2_OC2_MODE==INVERTING_PHASE_CORRECT_PWM

		SET_BIT(TCCR2,TCCR2_COM21);		SET_BIT(TCCR2,TCCR2_COM20);
 
	#endif

	/*Select Timer CLK PRE-Scale*/

		/*Mask the most 5 significant bits */
	   		TCCR2 &=PRESCALE_MASK;
		/*Set the least significant bits*/
	   		TCCR2|=TIMER2_PRESCALE;

	/*Set the Interrupt mode*/
		#if TIMER2_OVERFLOW_INTERRUPT==ENABLE
			SET_BIT(TIMSK, TIMSK_TOIE2);

		#elif TIMER2_OVERFLOW_INTERRUPT==DISABLE
			CLR_BIT(TIMSK, TIMSK_TOIE2);

		#endif

		#if TIMER2_CTC_INTERRUPT==ENABLE
			SET_BIT(TIMSK, TIMSK_OCIE2);

		#elif TIMER2_CTC_INTERRUPT==DISABLE
			CLR_BIT(TIMSK, TIMSK_OCIE2);

		#endif

}

void TIMER2_voidSetPreload (u8 Copy_u8Preload)
{
	TCNT2=Copy_u8Preload;
}
void TIMER2_voidSetCTC (u8 Copy_u8CTC) 
{
	OCR2=Copy_u8CTC;
}
u8   TIMER2_u8GetTimerCounterValue (void) 
{
	return TCNT2;
}
void TIMER2_voidForceCompare (void)
{
	SET_BIT(TCCR2,TCCR2_FOC2);
}
/*****************************************************************************************************************/
u8 TIMER_u8SetCallBack(void(*Copy_pCallBack)(void), u8 Copy_u8InterruptSource)
{
	u8 Local_u8ErrorStatus=OK;
		if(Copy_pCallBack!=NULL){
			if( Copy_u8InterruptSource<8 && Copy_u8InterruptSource>=0)
			{
				TIMER_CallBack[Copy_u8InterruptSource]=Copy_pCallBack;
			}
			else
			{
				Local_u8ErrorStatus=NOK;
			}
		}
		else
		{
			Local_u8ErrorStatus=NULL_Pointer;
		}
		return Local_u8ErrorStatus;
}
u8 TIMER_u8SetPWMDutyCycle(u16 Copy_u16DutyCycle,u8 Copy_u8Timerline)
{
	u8 Local_u8ErrorStatus=OK;
		switch(Copy_u8Timerline){
		case TIMER0:	OCR0=Copy_u16DutyCycle;			break;
		case TIMER1A: 	OCR1A=Copy_u16DutyCycle;		break;
		case TIMER1B: 	OCR1B=Copy_u16DutyCycle;		break;
		case TIMER2:	OCR2=Copy_u16DutyCycle;			break;
		default:Local_u8ErrorStatus=NOK;  break;
		}
	return Local_u8ErrorStatus;
}

u8 TIMER_u8CLearFlag(u8 Copy_u8InterruptSource)
{
	u8 Local_u8ErrorStatus=OK;
		if(Copy_u8InterruptSource>=0 && Copy_u8InterruptSource<8)
		{
			SET_BIT(TIFR,Copy_u8InterruptSource) ;
		}
		else
		{
			Local_u8ErrorStatus=NOK;

		}
 return Local_u8ErrorStatus;
}
u8 TIMER_u8GetFlag(u8 Copy_u8InterruptSource)
{
	u8 Local_u8ErrorStatus=OK;
	u8 Local_u8Flag;
	if(Copy_u8InterruptSource>=0 && Copy_u8InterruptSource<8)
	{
		Local_u8Flag=GET_BIT(TIFR,Copy_u8InterruptSource) ;
	}
	else
	{
		Local_u8ErrorStatus=NOK;
		return Local_u8ErrorStatus;
	}


	return Local_u8Flag;

}
/*****************************************************************************************************************/
/*WATCHDOG*/
void WDT_voidSleep  (void)
{
	/*Set Watchdog Pre-scale*/
	WDTCR &=PRESCALE_MASK;
	WDTCR |=WATCHDOG_PRESCALE;
}
void WDT_voidEnable (void)
{
	SET_BIT (WDTCR , WDTCR_WDE);

}
void WDT_voidDisable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR |= (1<<WDTCR_WDTOE) | (1<<WDTCR_WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}
u8   WDT_u8Sleep  (u8 Copy_u8Sleeptime)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u8Sleeptime>=0 && Copy_u8Sleeptime<8)
	{
		WDTCR &=PRESCALE_MASK;
		WDTCR |=Copy_u8Sleeptime;
	}
	else
	{
		Local_u8ErrorStatus=NOK;

	}
	return Local_u8ErrorStatus;
}


/*****************************************************************************************************************/
/*INTERRUPT SERVICE ROUTINES*/

ISR(TIMER0_OVF)
{
	if(TIMER_CallBack[TIMER0_OVERFLOW]!=NULL)
	{
	TIMER_CallBack[TIMER0_OVERFLOW]();
	}
}
ISR(TIMER0_COMP)
{
	if(TIMER_CallBack[TIMER0_COMPARE]!=NULL)
	{
	 TIMER_CallBack[TIMER0_COMPARE]();
	}
}
ISR(TIMER1_OVF)
{
	if(TIMER_CallBack[TIMER1_OVERFLOW]!=NULL)
	{
	TIMER_CallBack[TIMER1_OVERFLOW]();
	}
}


ISR(TIMER1_CAPT)
{
	if(TIMER_CallBack[TIMER1_CAPTURE]!=NULL)
	{
	TIMER_CallBack[TIMER1_CAPTURE]();
	}
}

ISR(TIMER1_COMPA)
{
	if(TIMER_CallBack[TIMER1_COMPARE_A]!=NULL)
	{
	TIMER_CallBack[TIMER1_COMPARE_A]();
	}
}

ISR(TIMER1_COMPB)
{
	if(TIMER_CallBack[TIMER1_COMPARE_B]!=NULL)
	{
	TIMER_CallBack[TIMER1_COMPARE_B]();
	}
}

ISR(TIMER2_OVF)
{
	if(TIMER_CallBack[TIMER2_OVERFLOW]!=NULL)
	{
	TIMER_CallBack[TIMER2_OVERFLOW]();
	}
}

ISR(TIMER2_COMP)
{
	if(TIMER_CallBack[TIMER2_COMPARE]!=NULL)
	{
	TIMER_CallBack[TIMER2_COMPARE]();
	}
}

#endif /*_TIMER_PROGRAM_C_*/
