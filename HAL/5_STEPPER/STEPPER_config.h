/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  STEPPER_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:STEPPER
*
*/
#ifndef   STEPPER_CONFIG_H_
#define   STEPPER_CONFIG_H_
 
/*
 	 Options:-

 	 	 1-DIO_PORTA
 	 	 2-DIO_PORTB
 	 	 3-DIO_PORTC
 	 	 4-DIO_PORTD

 */

#define STEPPER_PORT  DIO_PORTD

/*
 Options :-

 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 * */

#define STEPPER_BLUE_PIN 	    DIO_PIN0
#define STEPPER_YELLOW_PIN	    DIO_PIN1
#define STEPPER_PINK_PIN    	DIO_PIN2
#define STEPPER_ORANGE_PIN    	DIO_PIN3

 

#endif
