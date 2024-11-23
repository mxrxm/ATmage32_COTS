/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LED_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:LED
*
*/
#ifndef   LED_PROGRAM_C_
#define   LED_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include"LED_interface.h"



void LED_voidOn          ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH );
		
	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW  );
		
	}
}
void LED_voidOff         ( LED_Type LED_Configuration )
{
		
	if( LED_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW  );
		
	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH  );
		
	}
}
void LED_voidToggle      ( LED_Type LED_Configuration )
{
	DIO_enumTogglePinValue  ( LED_Configuration.Port , LED_Configuration.Pin );
}
#endif