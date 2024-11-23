/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  ADC_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:ADC 
*
*/
#ifndef  _ADC_CONFIG_H_
#define  _ADC_CONFIG_H_
 
/*
  Reference voltage modes:
 1- ADC_External_VREF
 2- ADC_Internal_AVCC
 3- ADC_Internal_2_56
*/

#define ADC_Voltage_Reference   ADC_Internal_AVCC

/*****************************************************************************/
/*
 Data mode:
 1- TEN_BIT_RES (Right adjust)
 2- EIGHT_BIT_RES (Left adjust)
 */

#define ADC_RESOLUTION   EIGHT_BIT_RES

/*****************************************************************************/
/*
 CLK Prescaler:

 1-ADC_2_PRESCALE          
 2-ADC_4_PRESCALE          
 3-ADC_8_PRESCALE          
 4-ADC_16_PRESCALE          
 5-ADC_32_PRESCALE          
 6-ADC_64_PRESCALE          
 7-ADC_128_PRESCALE          

 Note : 50kHZ to 200kHZ 10 bit res
        more than 200kHZ 8 bit res
 */

#define ADC_PRESCALER  ADC_64_PRESCALE

/*****************************************************************************/

/*
 ADC Trigger Source selection:
  1- ADC_Free_Running_mode
  2- ADC_Analog_Comparator
  3- ADC_EXTI_Request_0
  4- ADC_Timer0_Compare_Match
  5- ADC_Timer0_Overflow
  6- ADC_Timer1_Compare_Match_B
  7- ADC_Timer1_Overflow
  8- ADC_Timer1_Capture_Event

  Note : ADATE must be set
 */

#define ADC_TRIGGER ADC_Free_Running_mode

/*****************************************************************************/

/*
 ADC INTERRUPT:
  1- ADC_INTERRUPT_ENABLE
  2- ADC_INTERRUPT_DISABLE

 */

#define ADC_INTERRUPT_MODE ADC_INTERRUPT_DISABLE

/*****************************************************************************/

#define ADC_u32TIMEOUT 50000




#endif
