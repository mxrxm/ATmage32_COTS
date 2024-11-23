/*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EXTI_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:EXTI 
*
*/
#ifndef  _EXTI_CONFIG_H_
#define  _EXTI_CONFIG_H_
 
/*
 Options :-

     1-EXTI_LOW_LEVEL      
     2-EXTI_ANY_CHANGE     
     3-EXTI_FALLING_EDGE   
     4-EXTI_RISING_EDGE    

 */

#define EXTI_SENSE_MODE_0  EXTI_RISING_EDGE
#define EXTI_SENSE_MODE_1  EXTI_FALLING_EDGE
#define EXTI_SENSE_MODE_2  EXTI_FALLING_EDGE

#endif
