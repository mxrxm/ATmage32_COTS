/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  KPD_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:KPD
*
*/
#ifndef   KPD_PROGRAM_C_
#define   KPD_PROGRAM_C_

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"DIO_interface.h"

#include"KPD_private.h"
#include"KPD_interface.h"
#include"KPD_config.h"


 void KPD_voidInit(void){
/********************************Row intilaization***************************************************/


     DIO_enumConnectPullup  ( KPD_PORT , KPD_R0 , DIO_PIN_HIGH );
     DIO_enumConnectPullup  ( KPD_PORT , KPD_R1 , DIO_PIN_HIGH );
     DIO_enumConnectPullup  ( KPD_PORT , KPD_R2 , DIO_PIN_HIGH );
     DIO_enumConnectPullup  ( KPD_PORT , KPD_R3 , DIO_PIN_HIGH );


/********************************coloumn intilaization***************************************************/
	DIO_enumSetPinDirection ( KPD_PORT , KPD_C0, DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection ( KPD_PORT , KPD_C1, DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection ( KPD_PORT , KPD_C2, DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection ( KPD_PORT , KPD_C3, DIO_PIN_OUTPUT );

 
	DIO_enumSetPinValue    ( KPD_PORT , KPD_C0 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_C1 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_C2 , DIO_PIN_HIGH );
	DIO_enumSetPinValue    ( KPD_PORT , KPD_C3 , DIO_PIN_HIGH );


 }
 
 u8   KPD_u8Getpressed(void)
 {

    u8 LOC_u8PressedKey=KPD_NO_PRESSED_KEY;
   static u8 LOC_u8KPDArr[ROW_NUMBER][COLOUMN_NUMBER]=KPD_u8Buttons;
   static u8 LOC_u8ColoumnArr[COLOUMN_NUMBER]=KPD_COLUMNS;
   static u8 LOC_u8ROWArr[ROW_NUMBER]=KPD_ROWS;//momkn a3ml alarray b define 34an yb2a more configrable
     
   u8 LOC_u8ColoumnIdx,LOC_u8RowIdx,LOC_u8ReadState;

	for(LOC_u8ColoumnIdx=0;LOC_u8ColoumnIdx<COLOUMN_NUMBER;LOC_u8ColoumnIdx++){
		/*Activate the current column*/
         DIO_enumSetPinValue(KPD_PORT,LOC_u8ColoumnArr[LOC_u8ColoumnIdx],DIO_PIN_LOW);

			for(LOC_u8RowIdx=0;LOC_u8RowIdx<ROW_NUMBER;LOC_u8RowIdx++){
				/*Read the rows*/
        		 DIO_enumGetPinValue(KPD_PORT,LOC_u8ROWArr[LOC_u8RowIdx],&LOC_u8ReadState);

				/*check the state*/
				 if(DIO_PIN_LOW==LOC_u8ReadState){
					LOC_u8PressedKey=LOC_u8KPDArr[LOC_u8RowIdx][LOC_u8ColoumnIdx];
					 
                       /*polling until the key is released*/
					    while(DIO_PIN_LOW==LOC_u8ReadState){
        		 	    	DIO_enumGetPinValue(KPD_PORT,LOC_u8ROWArr[LOC_u8RowIdx],&LOC_u8ReadState);
					    }


					return LOC_u8PressedKey;/*bdl ma a3ml delay lldebouncing */
				 }

			}
			/*Deactivate the current coloumn*/
         DIO_enumSetPinValue(KPD_PORT,LOC_u8ColoumnArr[LOC_u8ColoumnIdx],DIO_PIN_HIGH);
	}


  return LOC_u8PressedKey;
 }
#endif
