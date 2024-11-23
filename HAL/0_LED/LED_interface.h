/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LED_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:LED
*
*/
#ifndef   LED_INTERFACE_H_
#define   LED_INTERFACE_H_

#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0

typedef struct{
	
	u8 Port         ;
	u8 Pin          ;
	u8 Active_State ;
	
}LED_Type;

  

void LED_voidOn          ( LED_Type LED_Configuration );

void LED_voidOff         ( LED_Type LED_Configuration );
 
void LED_voidToggle      ( LED_Type LED_Configuration );
 

#endif