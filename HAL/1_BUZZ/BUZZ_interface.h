/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  BUZZ_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:HAL
 *   SWC:BUZZ
 *
 */
#ifndef BUZZ_INTERFACE_H_
#define BUZZ_INTERFACE_H_

#define ACTIVE_HIGH 1
#define ACTIVE_LOW 0

typedef struct
{

	u8 Port;
	u8 Pin;
	u8 Active_State;

} BUZZ_Type;

void BUZZ_voidOn(BUZZ_Type BUZZ_Configuration);
void BUZZ_voidOff(BUZZ_Type BUZZ_Configuration);
void BUZZ_voidToggle(BUZZ_Type BUZZ_Configuration);

#endif