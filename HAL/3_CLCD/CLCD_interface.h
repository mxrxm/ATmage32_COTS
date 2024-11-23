/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:HAL
 *   SWC:CLCD
 *
 */
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define FOUR_BITS                     0x28          //4 bits mode initialization
#define EIGHT_BITS                    0x38          //8 bits mode initialization (8-bit data, 2-line display, 5 x 7 font )
 /* COMMAND */

#define lcd_DisplayOn_CursorOff       0x0c          // display on, cursor off, don't blink character 
#define lcd_DisplayOn_CursorOn        0x0e          // display on, cursor on, don't blink character 
#define lcd_DisplayOff_CursorOff      0x08          // turn display off
#define lcd_Clear                     0x01          //replace all characters with ASCII 'space'  
#define lcd_EntryMode                 0x06          // shift cursor from left to right on read/write
#define lcd_Home                      0x02          // return cursor to first position on first line 
#define lcd_CGRAM                     0x40          // the first Place/Address at CGRAM
#define lcd_SetCursor                 0x80          // set cursor position
#define lcd_FunctionReset             0x30          // reset the LCD

/* ROWS */
#define ROW1 0
#define ROW2 1

/* COLUMNS */
#define COL1  0
#define COL2  1
#define COL3  2
#define COL4  3
#define COL5  4
#define COL6  5
#define COL7  6
#define COL8  7
#define COL9  8
#define COL10 9
#define COL11 10
#define COL12 11
#define COL13 12
#define COL14 13
#define COL15 14
#define COL16 15

void CLCD_voidInit                      ( void                                  );
void CLCD_voidSendData                  ( u8 Copy_u8Data                        );
void CLCD_voidSendCommand               ( u8 Copy_u8Commend                     );
void CLCD_voidSendString                ( const u8 * Copy_u8ptrString           );
void CLCD_voidSendNumber                ( s64 Copy_s64Number                    );
void CLCD_voidSetPosition               ( u8 Copy_u8Row         , u8 Copy_u8Col );
void CLCD_voidGetPosition				( u8*Copy_u8Row		    , u8* Copy_u8Col);
void CLCD_voidSendExtraChar             ( u8 Copy_u8Row         , u8 Copy_u8Col );
void CLCD_voidClearScreen               (void                                   );
void CLCD_voidSendIcon                  (u8 *Copy_u8icon, u8 Copy_u8Row, u8 Copy_u8Col, u8 Copy_u8IconNum);
#endif
