/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:DIO/GPIO
*
*/

#ifndef  _DIO_INTERFACE_H_
#define  _DIO_INTERFACE_H_

#include"STD_TYPES.h"
#include"DIO_private.h"

typedef enum
{
	DIO_NOK,
	DIO_OK
}DIO_ErrorStatus;


#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT 0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


#define PUD   2


// IO Pins 
 DIO_ErrorStatus DIO_enumSetPinDirection  ( u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Direction); 
 DIO_ErrorStatus DIO_enumSetPinValue      ( u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Value); 
 DIO_ErrorStatus DIO_enumGetPinValue      ( u8 copy_u8PORT,u8 copy_u8PIN,u8* Copy_PtrData); 
 DIO_ErrorStatus DIO_enumTogPinValue      ( u8 copy_u8PORT,u8 copy_u8PIN);
 
// Internal Pull Up
DIO_ErrorStatus DIO_enumConnectPullup        (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup ); 

 // IO Ports 
 
 DIO_ErrorStatus DIO_enumSetPortDirection ( u8 copy_u8PORT,u8 copy_u8Direction); 
 DIO_ErrorStatus DIO_enumSetPortValue     ( u8 copy_u8PORT,u8 copy_u8Value); 
 DIO_ErrorStatus DIO_enumGetPortValue     ( u8 copy_u8PORT,u8* Copy_PtrData ); 
 DIO_ErrorStatus DIO_enumTogPortValue     ( u8 copy_u8PORT ); 
 // IO Nibbles
DIO_ErrorStatus DIO_enumWriteHighNibbles (u8 Copy_u8PORT,u8 value);
DIO_ErrorStatus DIO_enumWriteLowNibbles  (u8 Copy_u8PORT,u8 value);

#endif
