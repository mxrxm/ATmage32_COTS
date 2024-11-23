/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EXTI_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:EXTI
*
*/

#ifndef  _EXTI_INTERFACE_H_
#define  _EXTI_INTERFACE_H_

#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2


#define EXTI_LOW_LEVEL      0
#define EXTI_ANY_CHANGE     1
#define EXTI_FALLING_EDGE   2
#define EXTI_RISING_EDGE    3

void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);
void EXTI_voidSetSignalLatch    ( u8 Copy_u8SenseMode , u8 Copy_u8Line                  );
void EXTI_voidDisableInterrupt  ( u8 Copy_u8Line                                        );
void EXTI_voidEnableInterrupt   ( u8 Copy_u8Line                                        );
void EXTI_voidClearFlag         ( u8 Copy_u8Line                                        );
u8   EXTI_u8GetFlag             ( u8 Copy_u8Line                                        );
void EXTI_voidSetCallBack       ( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine );



#endif
