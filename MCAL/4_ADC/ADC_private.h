/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  ADC_private.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:ADC 
*
*/
#ifndef  _ADC_PRIVATE_H_
#define  _ADC_PRIVATE_H_

#define  ADC_External_VREF      0
#define  ADC_Internal_AVCC      5
#define  ADC_Internal_2_56      2.56
 
#define  TEN_BIT_RES            10
#define  EIGHT_BIT_RES          8

#define   ADC_INTERRUPT_ENABLE  1
#define   ADC_INTERRUPT_DISABLE 0

#define TEN_BIT_MASK            0x03FF
#define EIGHT_BIT_MASK          0x00FF
#define ADMUX_MASK              0xE0
#define ADC_PRE_MASK            0xF8

#endif
