/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TIMER_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:TIMER 
*
*/

#ifndef  _TIMER_INTERFACE_H_
#define  _TIMER_INTERFACE_H_

/*INTERRUPT IDs USED IN CALLBACK*/
#define TIMER0_OVERFLOW         0
#define TIMER0_COMPARE 		    1

#define TIMER1_OVERFLOW		    2
#define TIMER1_COMPARE_B	    3
#define TIMER1_COMPARE_A     	4
#define TIMER1_CAPTURE			5

#define TIMER2_OVERFLOW         6
#define TIMER2_COMPARE     		7
/*used in setting PWM Duty Cycle function*/
#define TIMER0		0
#define TIMER1A		1
#define TIMER1B		3
#define TIMER2		2
/* Timer edges*/
#define TIMER_FALLING_EDGE	0
#define TIMER_RISING_EDGE	1
/*Watchdog prescale*/
#define WDT_16K_Cycle_Timeout_16300us			0
#define WDT_32K_Cycle_Timeout_32500us			1
#define WDT_64K_Cycle_Timeout_65ms				2
#define WDT_128K_Cycle_Timeout_130ms			3
#define WDT_256K_Cycle_Timeout_260ms			4
#define WDT_512K_Cycle_Timeout_520ms			5
#define WDT_1024K_Cycle_Timeout_1s				6
#define WDT_2048K_Cycle_Timeout_2100ms			7

/*****************************************************************************************************/
void TIMER0_voidInit(void);
void TIMER0_voidSetPreload (u8 Copy_u8Preload) ;
void TIMER0_voidSetCTC (u8 Copy_u8CTC) ;
u8   TIMER0_u8GetTimerCounterValue (void) ;
void TIMER0_voidForceCompare (void) ;
/*****************************************************************************************************/
void TIMER2_voidInit(void);
void TIMER2_voidSetPreload (u8 Copy_u8Preload) ;
void TIMER2_voidSetCTC (u8 Copy_u8CTC) ;
u8   TIMER2_u8GetTimerCounterValue (void) ;
void TIMER2_voidForceCompare (void) ;
/*****************************************************************************************************/
void TIMER1_voidInit(void);
void TIMER1_voidSetPreload (u16 Copy_u16Preload) ;
void TIMER1_voidSetCTCA (u16 Copy_u16CTC) ;
void TIMER1_voidSetCTCB (u16 Copy_u16CTC) ;
void TIMER1_voidSetICR1 (u16 Copy_u16ICR1) ;
void TIMER1_voidForceCompareA (void) ;
void TIMER1_voidForceCompareB (void) ;
u16  TIMER1_u16GetTimerCounterValue (void);
u16  TIMER1_u16GetICR(void);
/*****************************************************************************************************/
void ICU_voidInit(void);
u8   ICU_u8SetTriggerEdge(u8 Copy_u8Edge);
void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);
/*****************************************************************************************************/
u8 TIMER_u8SetCallBack(void(*Copy_pCallBack)(void),u8 Copy_u8InterruptSource);
u8 TIMER_u8SetPWMDutyCycle(u16 Copy_u16DutyCycle,u8 Copy_u8Timerline);
u8 TIMER_u8CLearFlag(u8 Copy_u8InterruptSource);
u8 TIMER_u8GetFlag(u8 Copy_u8InterruptSource);
/******************************************************************************************************/
void WDT_voidSleep  (void);
void WDT_voidEnable (void);
void WDT_voidDisable(void);
u8   WDT_u8Sleep  (u8 Copy_u8Sleeptime);


#endif
