/*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  VECTORS_private.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:VECTORS
*
*/
#ifndef  _VECTORS_PRIVATE_H_
#define  _VECTORS_PRIVATE_H_

#define  ISR(__vector_NUM )  void __vector_NUM(void)__attribute__((signal)); \
                             void __vector_NUM(void)

#define  INT0           __vector_1    /*External Interrupt Request 0*/
#define  INT1           __vector_2    /*External Interrupt Request 1*/
#define  INT2           __vector_3    /*External Interrupt Request 2*/    

#define  TIMER2_COMP    __vector_4    /*Timer/Counter2 Compare Match*/
#define  TIMER2_OVF     __vector_5    /*Timer/Counter2 Overflow*/

#define  TIMER1_CAPT    __vector_6    /*Timer/Counter1 Capture Event*/
#define  TIMER1_COMPA   __vector_7    /*Timer/Counter1 Compare Match A*/ 
#define  TIMER1_COMPB   __vector_8    /*Timer/Counter1 Compare Match B*/
#define  TIMER1_OVF     __vector_9    /*Timer/Counter1 Overflow*/ 

#define  TIMER0_COMP    __vector_10   /*Timer/Counter0 Compare Match*/
#define  TIMER0_OVF     __vector_11   /*Timer/Counter0 Overflow*/

#define   SPI_STC       __vector_12   /*Serial Transfer Complete*/
#define   UART_RXC      __vector_13   /*USART, Rx Complete*/
#define   UART_UDRE     __vector_14   /*USART Data Register Empty*/
#define   UART_TXC      __vector_15   /*USART, Tx Complete*/

#define   ADC_vect      __vector_16   /*ADC Conversion Complete*/

#define   EE_RDY        __vector_17   /*EEPROM Ready*/ 

#define   ANA_COMP      __vector_18   /*Analog Comparator*/

#define   TWI           __vector_19   /*Two-wire Serial Interface*/

#define   SPM_RDY       __vector_20   /*Store Program Memory Ready*/

#endif
