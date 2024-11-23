/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  STEPPER_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:HAL
 *   SWC:STEPPER
 *
 */
#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_
#define MAX_SPEED 2

void STEPPER_voidInit();
void STEPPER_voidOFF();
void STEPPER_voidRotateClockwise(u16 Copy_u16Degree,u16 Copy_u16Speed );
void STEPPER_voidRotateCounterClockwise(u16 Copy_u16Degree,u16 Copy_u16Speed);



#endif
