/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_private.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:HAL
 *   SWC:CLCD
 *
 */
#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

u8 CLCD_u8ExtraChar[] = {
    0b00000, 0b00000, 0b11111, 0b00101, 0b00111, 0b00000, 0b00000, 0b00000, // Ù…
    0b00000, 0b00000, 0b00111, 0b00100, 0b00100, 0b00100, 0b11100, 0b00000, // Ø±
    0b00000, 0b00000, 0b00001, 0b00001, 0b11111, 0b00000, 0b01010, 0b0000,  // ÙŠ
    0b00000, 0b00000, 0b11111, 0b11000, 0b10000, 0b10000, 0b10000, 0b00000};//Ù…

static void CLCD_voidSendFallingEdge    (void);

#endif
