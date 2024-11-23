/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SERVO_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:SERVO
*
*/
#ifndef   SERVO_PROGRAM_C_
#define   SERVO_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_interface.h"
#include "MAP.h"
#include "SERVO_private.h"
#include "SERVO_interface.h"
#include "SERVO_config.h"

static u16 SERVO_MIN,SERVO_MAX,SERVO_PERIOD;

void SERVO_voidInit(void)
{
	SERVO_PERIOD=(u16)(((f32)SERVO_PERIOD_TIME*SERVO_CLK)/(f32)SERVO_PRE_SCALE);
	SERVO_MIN=(u16)(((f32)SERVO_MIN_DUTY*SERVO_CLK)/(f32)SERVO_PRE_SCALE);
	SERVO_MAX=(u16)(((f32)SERVO_MAX_DUTY*SERVO_CLK)/(f32)SERVO_PRE_SCALE);
	TIMER1_voidSetICR1(SERVO_PERIOD);
}
void SERVO_voidSetAngle(s16 angle)
{
	u16 dutycycle;
	dutycycle=Map(-90,90,SERVO_MIN,SERVO_MAX,angle);
	TIMER_u8SetPWMDutyCycle(dutycycle,SERVO_CHANNEL);

}

#endif
