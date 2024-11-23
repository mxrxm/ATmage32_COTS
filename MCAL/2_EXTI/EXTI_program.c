/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EXTI_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:MCAL
 *   SWC:EXTI 
 *
 */
#ifndef _EXTI_PROGRAM_C_
#define _EXTI_PROGRAM_C_


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "VECTORS_private.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

 


/* Global array of pointer to each ISR with index 0,1,2 */
void (*EXTI_CallBack[3]) (void) = { NULL } ; 




void EXTI_voidINT0Init(void) {
	
	/*set sense control*/
	         #if EXTI_SENSE_MODE_0==EXTI_LOW_LEVEL
			  
			   CLR_BIT(MCUCR,MCUCR_ISC01 );   CLR_BIT(MCUCR,MCUCR_ISC00);
			   
			  #elif EXTI_SENSE_MODE_0==EXTI_ANY_CHANGE
			  
			   CLR_BIT(MCUCR,MCUCR_ISC01);   SET_BIT(MCUCR,MCUCR_ISC00);
			   
			  #elif EXTI_SENSE_MODE_0==EXTI_FALLING_EDGE
			  
			   SET_BIT(MCUCR,MCUCR_ISC01);   CLR_BIT(MCUCR,MCUCR_ISC00);
			   
			  #elif EXTI_SENSE_MODE_0==EXTI_RISING_EDGE
			  
			   SET_BIT(MCUCR,MCUCR_ISC01);   SET_BIT(MCUCR,MCUCR_ISC00);
			   

			  #endif
			  
	/*periphrel intrrupt control*/
        SET_BIT(GICR,GICR_INT0);  
	
}

void EXTI_voidINT1Init(void) 
{
		   
			  #if  EXTI_SENSE_MODE_1==EXTI_LOW_LEVEL
			  
			   CLR_BIT(MCUCR,MCUCR_ISC11);   CLR_BIT(MCUCR,MCUCR_ISC10);
			   
			  #elif EXTI_SENSE_MODE_1==EXTI_ANY_CHANGE
			  
			   CLR_BIT(MCUCR,MCUCR_ISC11);   SET_BIT(MCUCR,MCUCR_ISC10);
			   
			  #elif EXTI_SENSE_MODE_1==EXTI_FALLING_EDGE
			  
			   SET_BIT(MCUCR,MCUCR_ISC11);   CLR_BIT(MCUCR,MCUCR_ISC10);
			   
			  #elif EXTI_SENSE_MODE_1==EXTI_RISING_EDGE
			  
			   SET_BIT(MCUCR,MCUCR_ISC11);   SET_BIT(MCUCR,MCUCR_ISC10);
              #endif
			  	/*periphrel intrrupt control*/
	          SET_BIT(GICR,GICR_INT1);  
		
}

void EXTI_voidINT2Init(void) {
	/*set sense control*/
		#if EXTI_SENSE_MODE_2==EXTI_FALLING_EDGE
			  
	     CLR_BIT(MCUCSR,MCUCSR_INT2);
	     
	    #elif EXTI_SENSE_MODE_2==EXTI_RISING_EDGE
	    
	     SET_BIT(MCUCSR,MCUCSR_INT2); 


		#endif
		/*Peripheral interrupt control*/
        SET_BIT(GICR,GICR_INT2);  
}

void EXTI_voidSetSignalLatch    ( u8 Copy_u8SenseMode , u8 Copy_u8Line ){
	/*l 3yza a8yr l configuration during l runtime*/
	/* For EXTI0 & EXTI1 */
	if( Copy_u8Line == EXTI_LINE0 || Copy_u8Line == EXTI_LINE1 ){


		switch( Copy_u8SenseMode ){

		/* INT Sense Control (Trigger) For EXTI0 & EXTI1   */
		case EXTI_LOW_LEVEL    : CLR_BIT( MCUCR , Copy_u8Line ); CLR_BIT( MCUCR ,  (Copy_u8Line + 1 )); break;
		case EXTI_ANY_CHANGE   : SET_BIT( MCUCR , Copy_u8Line ); CLR_BIT( MCUCR ,  (Copy_u8Line + 1 )); break;
		case EXTI_FALLING_EDGE : CLR_BIT( MCUCR , Copy_u8Line ); SET_BIT( MCUCR ,  (Copy_u8Line + 1 )); break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCR , Copy_u8Line ); SET_BIT( MCUCR ,  (Copy_u8Line + 1 )); break;

		}
	}

	/* For EXTI2 */
	if(Copy_u8Line==EXTI_LINE2){

		switch( Copy_u8SenseMode ){
		
		/* INT Sense Control (Trigger) For EXTI0 & EXTI1   */
		case EXTI_FALLING_EDGE : CLR_BIT( MCUCSR ,MCUCSR_INT2 );  break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCSR ,MCUCSR_INT2);   break;

		}

	}

}
void EXTI_voidSetCallBack( void (*Copy_pvoidCallBack)(void), u8 Copy_u8EXTILine ){
	
	if( Copy_pvoidCallBack != NULL )
 
	  EXTI_CallBack[Copy_u8EXTILine] = Copy_pvoidCallBack;



}

u8 EXTI_u8GetFlag( u8 Copy_u8Line ){
		u8 flag;
			switch (Copy_u8Line){
		case EXTI_LINE0 : flag=GET_BIT(GIFR,GIFR_INT0);  break;
		case EXTI_LINE1 : flag=GET_BIT(GIFR,GIFR_INT1);  break;
		case EXTI_LINE2 : flag=GET_BIT(GIFR,GIFR_INT2);  break;
			}
		return flag;
}


void   EXTI_voidClearFlag         ( u8 Copy_u8Line )
{
	switch (Copy_u8Line){
	case EXTI_LINE0 : SET_BIT(GIFR,GIFR_INT0);  break;
	case EXTI_LINE1 : SET_BIT(GIFR,GIFR_INT1);  break;
	case EXTI_LINE2 : SET_BIT(GIFR,GIFR_INT2);  break;
}
}


void EXTI_voidDisableInterrupt  ( u8 Copy_u8Line ){
	switch (Copy_u8Line){
		case EXTI_LINE0 : CLR_BIT(GICR,GICR_INT0);  break;
		case EXTI_LINE1 : CLR_BIT(GICR,GICR_INT1);  break;
		case EXTI_LINE2 : CLR_BIT(GICR,GICR_INT2);  break;
	}
}

void EXTI_voidEnableInterrupt   ( u8 Copy_u8Line ){
		switch (Copy_u8Line){
		case EXTI_LINE0 : SET_BIT(GICR,GICR_INT0);  break;
		case EXTI_LINE1 : SET_BIT(GICR,GICR_INT1);  break;
		case EXTI_LINE2 : SET_BIT(GICR,GICR_INT2);  break;
	}
}


 ISR(INT0){

  EXTI_CallBack[0](); // Call the callback function

 }
 ISR(INT1){

  EXTI_CallBack[1](); // Call the callback function

 }
 ISR(INT2){

  EXTI_CallBack[2](); // Call the callback function

 }


#endif
