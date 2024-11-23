/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SERVO_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:SERVO
*
*/
#ifndef   SERVO_CONFIG_H_
#define   SERVO_CONFIG_H_
 
/*The System clock in MHZ*/
#define SERVO_CLK 			8

/*the pre-scale used according to the channel*/
#define SERVO_PRE_SCALE		64
/*
 * Choose the channel:
 * 1-TIMER1A
 * 2-TIMER1B
 * */
#define SERVO_CHANNEL		TIMER1A
/*servo parameters in micro second*/
#define SERVO_PERIOD_TIME   20000
#define SERVO_MIN_DUTY 		1000
#define SERVO_MAX_DUTY 		2000
/*in real time change into 750us-2500us*/

#endif
