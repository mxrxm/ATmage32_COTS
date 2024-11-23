/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:CLCD
*
*/
#ifndef   CLCD_PROGRAM_C_
#define   CLCD_PROGRAM_C_
#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

static u8 LOC_u8CurrentRow=ROW1;
static u8 LOC_u8CurrentColumn=COL1;

/***************************************************************************************/

/*

   ###########  8 Bits Mode  ###########
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PA7|---------------->|D7        |
 |        PA6|---------------->|D6        |
 |        PA5|---------------->|D5        |
 |        PA4|---------------->|D4        |
 |        PA3|---------------->|D3        |
 |        PA2|---------------->|D2        |
 |        PA1|---------------->|D1        |
 |        PA0|---------------->|D0        |
 |           |                 |          |
 |        PC2|---------------->|E         |
 |        PC1|---------------->|RW        |
 |        PC0|---------------->|RS        |
 -----------                   ----------
 */
/***************************************************************************************/
/*

   ###########  4 Bits Mode  ###########
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PA7|---------------->|D7        |
 |        PA6|---------------->|D6        |
 |        PA5|---------------->|D5        |
 |        PA4|---------------->|D4        |
 ||          |                 |          |
 |           |                 |          |
 |           |                 |          |
 |           |                 |          |
 |           |                 |          |
 |        PC2|---------------->|E         |
 |        PC1|---------------->|RW        |
 |        PC0|---------------->|RS        |
 -----------                   ----------
 */
/***************************************************************************************/


void CLCD_voidInit        ( void ){

	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)

	 _delay_ms(50);

	/*return home*/
	CLCD_voidSendCommand( lcd_Home );
	_delay_ms(30);

	/*FUNCTION SET Command*/
	CLCD_voidSendCommand( CLCD_MODE );
	_delay_ms(1);

	/* DISPLAY & Cursor (ON / OFF) Control */
	CLCD_voidSendCommand( lcd_DisplayOn_CursorOff );
	_delay_ms(1);

	/* DISPLAY CLEAR */
	CLCD_voidClearScreen();

	/* ENTRY MODE  Set*/
	CLCD_voidSendCommand( lcd_EntryMode );
	_delay_ms(1);



}


void CLCD_voidSendData    ( u8 Copy_u8Data ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   CLCD_MODE == EIGHT_BITS

	DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Data        );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	CLCD_voidSendFallingEdge();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   CLCD_MODE == FOUR_BITS

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	DIO_enumWriteHighNibbles (CLCD_DATA_PORT ,(Copy_u8Data>>4));            // send the most 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();
	DIO_enumWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Data);               // send the least 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();

	#endif


    // Update the column counter and row position
    LOC_u8CurrentColumn++;

    if (LOC_u8CurrentColumn>COL16) {
    	if(LOC_u8CurrentRow==ROW1){
    		LOC_u8CurrentRow = ROW2;
    	}
    	else{
    		LOC_u8CurrentRow = ROW1;
    	}
        LOC_u8CurrentColumn = COL1;
        CLCD_voidSetPosition(LOC_u8CurrentRow, LOC_u8CurrentColumn);
    }
	_delay_ms(1);
}

void CLCD_voidGetPosition(u8* Copy_u8Row, u8* Copy_u8Col) {
    *Copy_u8Row = LOC_u8CurrentRow;
    *Copy_u8Col = LOC_u8CurrentColumn;
}



void CLCD_voidSendCommand ( u8 Copy_u8Command ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   CLCD_MODE == EIGHT_BITS

	DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Command     );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	// RW always connect to GND to Write
	DIO_enumSetPinValue          (CLCD_CONTROL_PORT,CLCD_RW , DIO_PIN_LOW    );
	CLCD_voidSendFallingEdge();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   CLCD_MODE == FOUR_BITS

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	DIO_enumWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command>>4);             // send the most 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();
	DIO_enumWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command);                // send the least 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);

}
void CLCD_voidSendString  ( const u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		CLCD_voidSendData( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}

}
//void CLCD_voidSendNumber   ( u64 Copy_u64Number    ){
//
//	u64 LOC_u64Reversed = 1 ;
//
//	if( Copy_u64Number == 0 ){ CLCD_voidSendData('0'); }
//
//	else{
//
//		while( Copy_u64Number != 0 ){
//
//			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
//			Copy_u64Number /= 10 ;
//
//		}
//		while( LOC_u64Reversed != 1 ){
//
//			CLCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
//			LOC_u64Reversed /= 10 ;
//
//		}
//
//	}
//
//}
void CLCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	u8 LOC_u8data ;
	LOC_u8CurrentColumn=Copy_u8Col;
	LOC_u8CurrentRow=Copy_u8Row;

	/* In These cases will set at (0,0) ==> if the user enter invalid location */
	if(Copy_u8Row>ROW2||Copy_u8Row<ROW1||Copy_u8Col>COL16||Copy_u8Col<COL1)  //check
	{
		LOC_u8data = lcd_SetCursor ;   // first location
	}


	else if( Copy_u8Row == ROW1 ){

		LOC_u8data = ( ( lcd_SetCursor ) + ( Copy_u8Col ) );              //Row1 -> 0x80+col-1
	}

	else if( Copy_u8Row == ROW2 ){

		LOC_u8data = ( ( lcd_SetCursor ) + (64) + ( Copy_u8Col ) ) ;       //Row2 -> 0xc0+col-1

	}
	CLCD_voidSendCommand ( LOC_u8data );
	_delay_ms(1);

}
void CLCD_voidSendNumber(s64 Copy_s64Number) {
    // Buffer to hold the string representation of the number
    char buffer[21];  // Enough space for 20 digits and a null terminator (handling 64-bit numbers)

    // Check if the number is 0
    if (Copy_s64Number == 0) {
        CLCD_voidSendData('0');
        return;
    }

    // Handle negative numbers
    u8 isNegative = 0;
    if (Copy_s64Number < 0) {
        isNegative = 1;
        Copy_s64Number = -Copy_s64Number;  // Convert to positive for processing
    }

    // Convert the number to a string (in reverse)
    u8 i = 0;
    while (Copy_s64Number != 0) {
        buffer[i++] = (Copy_s64Number % 10) + '0';  // Convert digit to character
        Copy_s64Number /= 10;
    }

    // If the number was negative, add the '-' sign
    if (isNegative) {
        buffer[i++] = '-';
    }

    // Send the number to the LCD in correct order
    while (i > 0) {
        CLCD_voidSendData(buffer[--i]);  // Send each character from the end of the buffer
    }
}

void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand(lcd_Clear);
	_delay_ms(10); //wait more than 1.53 ms
}


static void CLCD_voidSendFallingEdge(void)
{
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_LOW  );
	_delay_ms(1);
}
void CLCD_voidSendExtraChar( u8 Copy_u8Row , u8 Copy_u8Col ){

	u8 LOC_u8Iterator = 0 ;
	/* 1- Go To CGRAM            */
	CLCD_voidSendCommand( lcd_CGRAM );  // Make AC refers to the first Place/Address at CGRAM


	/* 2- Draw Character in CGRAM        */
	/* Hint : it will be copied to DDRAM automatically */
	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]) ; LOC_u8Iterator++){

		CLCD_voidSendData( CLCD_u8ExtraChar[LOC_u8Iterator] );

	}


	/* 3- Back (AC) To DDRAM          */
	CLCD_voidSetPosition(Copy_u8Row,Copy_u8Col);


	/* 4- Send Character Address */
	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++ ){

		CLCD_voidSendData( LOC_u8Iterator );

	}

}


void CLCD_voidSendIcon(u8 *Copy_u8icon, u8 Copy_u8Row, u8 Copy_u8Col, u8 Copy_u8IconNum) {
    u8 LOC_u8Iterator;
    u8 CGRAMAddress = Copy_u8IconNum * 8; // Each custom character occupies 8 bytes in CGRAM

    /* 1- Go To CGRAM */
    CLCD_voidSendCommand(0x40 + CGRAMAddress);  // Set CGRAM address to the starting address of the icon

    /* 2- Draw Character in CGRAM */
    for (LOC_u8Iterator = 0; LOC_u8Iterator < 8; LOC_u8Iterator++) {
        CLCD_voidSendData(Copy_u8icon[LOC_u8Iterator]);
    }

    /* 3- Back (AC) To DDRAM */
    CLCD_voidSetPosition(Copy_u8Row, Copy_u8Col);

    /* 4- Send Character Address to DDRAM */
    CLCD_voidSendData(Copy_u8IconNum);  // Send the character number to display the custom character
}

#endif
