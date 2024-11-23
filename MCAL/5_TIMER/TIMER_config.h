/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TIMER_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:TIMER 
*
*/
#ifndef  _TIMER_CONFIG_H_
#define  _TIMER_CONFIG_H_


/*******************************************************************************/
 /*
 Waveform Generation Mode TIMER0/TIMER2:
	1-TIMER_NORMAL
	2-TIMER_PHASE_CORRECT_PWM
	3-TIMER_CTC
	4-TIMER_FAST_PWM
 */
#define TIMER0_WAVEFORM_MODE		TIMER_FAST_PWM

#define TIMER2_WAVEFORM_MODE		TIMER_NORMAL
/*******************************************************************************/
/* 
Waveform Generation Mode Timer1:
	 1-TIMER1_NORMAL
	 2-TIMER1_PWM_8_BIT_MODE
	 3-TIMER1_PWM_9_BIT_MODE
	 4-TIMER1_PWM_10_BIT_MODE
	 5-TIMER1_CTC_OCR1A_MODE
	 6-TIMER1_FAST_PWM_8_BIT_MODE
	 7-TIMER1_FAST_PWM_9_BIT_MODE
	 8-TIMER1_FAST_PWM_10_BIT_MODE
	 9-TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
	 10-TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
	 11-TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
	 12-TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
	 13-TIMER1_CTC_ICR1_MODE
	 14-TIMER1_FAST_PWM_ICR1_MODE
	 15-TIMER1_FAST_PWM_OCR1A_MODE
*/
#define TIMER1_WAVEFORM_MODE		TIMER1_NORMAL
/*******************************************************************************/
 /*
 Compare Match Output Mode:
	1-OC_DISCONNECTED
	2-CTC_TOGGLE_OC
	3-CTC_CLEAR_OC
	4-CTC_SET_OC
	5-NON_INVERTING_FAST_PWM
	6-INVERTING_FAST_PWM
	7-NON_INVERTING_PHASE_CORRECT_PWM
	8-INVERTING_PHASE_CORRECT_PWM
 */
#define TIMER0_OCO_MODE		NON_INVERTING_FAST_PWM

#define TIMER1_OC1A_MODE	OC_DISCONNECTED
#define TIMER1_OC1B_MODE	OC_DISCONNECTED

#define TIMER2_OCO_MODE		OC_DISCONNECTED
/*******************************************************************************/
 /*
 Clock Select(Pre-scale):
	1-NO_CLK
	2-SYSTEM_CLK_NO_PRESCALE
	3-SYSTEM_CLK_8_PRESCALE
	4-SYSTEM_CLK_64_PRESCALE
	5-SYSTEM_CLK_256_PRESCALE
	6-SYSTEM_CLK_1024_PRESCALE
	7-EXT_CLK_FALLING_EDGE
	8-EXT_CLK_RISING_EDGE
 */
#define TIMER0_PRESCALE		SYSTEM_CLK_8_PRESCALE

#define TIMER1_PRESCALE		SYSTEM_CLK_8_PRESCALE

#define TIMER2_PRESCALE		SYSTEM_CLK_64_PRESCALE
/*******************************************************************************/
 /*
 Interrupt Modes:
	1-DISABLE
	2-ENABLE
 */
#define TIMER0_OVERFLOW_INTERRUPT	DISABLE
#define TIMER0_CTC_INTERRUPT		DISABLE

#define TIMER1_OVERFLOW_INTERRUPT	DISABLE
#define TIMER1_CTCB_INTERRUPT		DISABLE
#define TIMER1_CTCA_INTERRUPT		DISABLE
#define TIMER1_ICR_INTERRUPT		DISABLE

#define TIMER2_OVERFLOW_INTERRUPT	DISABLE
#define TIMER2_CTC_INTERRUPT		DISABLE
/*******************************************************************************/
/*NOTE:COMMENT THE BELOW VALUES IF YOU DONT WANT TO USE PRE-BUILD CONFIGRATION*/
/*******************************************************************************/
/*Pre-load value for CTC and Normal mode*/
#define TIMER0_PRELOAD   	0

#define TIMER1_PRELOAD   	0

#define TIMER2_PRELOAD   	0
/*******************************************************************************/
/*Compare match value for CTC mode*/
#define TIMER0_OCR		 64

//#define TIMER1_OCRA		1000
//#define TIMER1_OCRB		1500

//#define TIMER2_OCR		125
/*******************************************************************************/
/*ICR1 for Timer1*/
#define TIMER1_ICR1 	0
/*******************************************************************************/
/*
 ICR1 Trigger Select
  1-TIMER_FALLING_EDGE
  2-TIMER_RISING_EDGE
 */
#define TIMER1_ICR1_TRIGGER  TIMER_RISING_EDGE
/*******************************************************************************/
/*
Watchdog Prescale:
 1-WDT_16K_Cycle_Timeout_16300us
 2-WDT_32K_Cycle_Timeout_32500us
 3-WDT_64K_Cycle_Timeout_65ms
 4-WDT_128K_Cycle_Timeout_130ms
 5-WDT_256K_Cycle_Timeout_260ms
 6-WDT_512K_Cycle_Timeout_520ms
 7-WDT_1024K_Cycle_Timeout_1s
 8-WDT_2048K_Cycle_Timeout_2100ms

 */
#define WATCHDOG_PRESCALE	WDT_16K_Cycle_Timeout_16300us

#endif
