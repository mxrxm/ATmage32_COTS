/*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EXTI_private.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:EXTI
*
*/
#ifndef  _EXTI_PRIVATE_H_
#define  _EXTI_PRIVATE_H_
 
  
#define GICR      *( (volatile u8*)0x5B )  
#define GIFR      *( (volatile u8*)0x5A )  
#define MCUCR     *( (volatile u8*)0x55 )  
#define MCUCSR    *( (volatile u8*)0x54 )  

#define GICR_INT0  6
#define GICR_INT1  7
#define GICR_INT2  5

#define GIFR_INT0  6
#define GIFR_INT1  7
#define GIFR_INT2  5
 
#define MCUCR_ISC11  3  
#define MCUCR_ISC10  2
#define MCUCR_ISC01  1
#define MCUCR_ISC00  0

#define MCUCSR_INT2  6

#endif
