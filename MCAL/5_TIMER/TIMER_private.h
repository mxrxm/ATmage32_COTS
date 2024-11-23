/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TIMER_private.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:TIMER 
*
*/
#ifndef  _TIMER_PRIVATE_H_
#define  _TIMER_PRIVATE_H_

#define TIMER_NORMAL							0
#define TIMER_PHASE_CORRECT_PWM					1
#define TIMER_CTC								2
#define TIMER_FAST_PWM							3
 
#define TIMER1_NORMAL                                   0
#define TIMER1_PWM_8_BIT_MODE                           1
#define TIMER1_PWM_9_BIT_MODE                           2
#define TIMER1_PWM_10_BIT_MODE                          4
#define TIMER1_CTC_OCR1A_MODE                           5
#define TIMER1_FAST_PWM_8_BIT_MODE                      6
#define TIMER1_FAST_PWM_9_BIT_MODE                      8
#define TIMER1_FAST_PWM_10_BIT_MODE                     9
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE     10
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE    11
#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE              12
#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE             13
#define TIMER1_CTC_ICR1_MODE                            14
#define TIMER1_FAST_PWM_ICR1_MODE                       15
#define TIMER1_FAST_PWM_OCR1A_MODE                      16


#define OC_DISCONNECTED						0
#define CTC_TOGGLE_OC						1
#define CTC_CLEAR_OC						2					
#define CTC_SET_OC							3
#define NON_INVERTING_FAST_PWM				4
#define INVERTING_FAST_PWM					5
#define NON_INVERTING_PHASE_CORRECT_PWM		6
#define INVERTING_PHASE_CORRECT_PWM			7
 
#define NO_CLK								0
#define SYSTEM_CLK_NO_PRESCALE				1
#define SYSTEM_CLK_8_PRESCALE				2
#define SYSTEM_CLK_64_PRESCALE				3
#define SYSTEM_CLK_256_PRESCALE				4
#define SYSTEM_CLK_1024_PRESCALE			5
#define EXT_CLK_FALLING_EDGE				6
#define EXT_CLK_RISING_EDGE					7


#define TIMER_INT_DISABLE                   0
#define TIMER_INT_OVERFLOW                  1
#define TIMER_INT_COMPARE_MATCH             2
#define TIMER_INT_BOTH                      3

#define DISABLE     0
#define ENABLE      1

#define PRESCALE_MASK                       0b11111000
#define TIFR_MASK                           0b11111100

#define WDT_16K_Cycle_Timeout_16300us			0
#define WDT_32K_Cycle_Timeout_32500us			1
#define WDT_64K_Cycle_Timeout_65ms				2
#define WDT_128K_Cycle_Timeout_130ms			3
#define WDT_256K_Cycle_Timeout_260ms			4
#define WDT_512K_Cycle_Timeout_520ms			5
#define WDT_1024K_Cycle_Timeout_1s				6
#define WDT_2048K_Cycle_Timeout_2100ms			7


#endif
