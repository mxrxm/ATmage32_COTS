/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  BUZZ_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:BUZZ
*
*/
#ifndef   BUZZ_PROGRAM_C_
#define   BUZZ_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include"BUZZ_interface.h"

void BUZZ_voidOn          ( BUZZ_Type BUZZ_Configuration )
{
	if( BUZZ_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( BUZZ_Configuration.Port , BUZZ_Configuration.Pin , DIO_PIN_HIGH );
		
	}else if( BUZZ_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( BUZZ_Configuration.Port , BUZZ_Configuration.Pin , DIO_PIN_LOW  );
		
	}
}
void BUZZ_voidOff         ( BUZZ_Type BUZZ_Configuration )
{
		
	if( BUZZ_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( BUZZ_Configuration.Port , BUZZ_Configuration.Pin , DIO_PIN_LOW  );
		
	}else if( BUZZ_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( BUZZ_Configuration.Port , BUZZ_Configuration.Pin , DIO_PIN_HIGH  );
		
	}
}
void BUZZ_voidToggle      ( BUZZ_Type BUZZ_Configuration )
{
	DIO_enumTogglePinValue  ( BUZZ_Configuration.Port , BUZZ_Configuration.Pin );
}
#endif