/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  PORT_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:PORT 
*
*/
#ifndef  _PORT_CONFIG_H_
#define  _PORT_CONFIG_H_
/*
options
  0 INPUT
  1 OUTPUT
*/
 
 
#define PORTA_PIN0_DIR    0		//ADC0
#define PORTA_PIN1_DIR    1		//ADC1
#define PORTA_PIN2_DIR    1		//ADC2
#define PORTA_PIN3_DIR    1		//ADC3
#define PORTA_PIN4_DIR    1		//ADC4
#define PORTA_PIN5_DIR    1		//ADC5
#define PORTA_PIN6_DIR    1		//ADC6
#define PORTA_PIN7_DIR    1		//ADC7
	
#define PORTB_PIN0_DIR    0		//XCK,T0		
#define PORTB_PIN1_DIR    0		//T1		
#define PORTB_PIN2_DIR    0		//INT2,AIN0	
#define PORTB_PIN3_DIR    1		//OC0,AIN1	
#define PORTB_PIN4_DIR    0		//SS		
#define PORTB_PIN5_DIR    0		//MOSI		
#define PORTB_PIN6_DIR    0		//MISO		
#define PORTB_PIN7_DIR    0		//SCK		
	
#define PORTC_PIN0_DIR    0 	//SCL
#define PORTC_PIN1_DIR    0 	//SDA
#define PORTC_PIN2_DIR    0 	//TCK
#define PORTC_PIN3_DIR    0 	//TMS
#define PORTC_PIN4_DIR    0 	//TDO
#define PORTC_PIN5_DIR    0 	//TDI
#define PORTC_PIN6_DIR    0 	//TOSC1
#define PORTC_PIN7_DIR    0 	//TOSC2
	
#define PORTD_PIN0_DIR    0 	//RXD
#define PORTD_PIN1_DIR    0 	//TXD
#define PORTD_PIN2_DIR    0		//INT0
#define PORTD_PIN3_DIR    0		//INT1
#define PORTD_PIN4_DIR    0		//OC1B
#define PORTD_PIN5_DIR    0 	//OC1A
#define PORTD_PIN6_DIR    0 	//ICP1
#define PORTD_PIN7_DIR    0 	//ICP1

 
/*  $ Choose:-
			1- INPUT_FLOATING -0
			2- INPUT_PULLUP -1
			3- OUTPUT_LOW  -0
			4- OUTPUT_HIGH -1
*/

/*
 Hint : This is the initial values for the system we could change it using DIO driver
*/
#define PORTA_PIN0_INITIAL_VALUE	0	//ADC0
#define PORTA_PIN1_INITIAL_VALUE    0	//ADC1
#define PORTA_PIN2_INITIAL_VALUE    0	//ADC2
#define PORTA_PIN3_INITIAL_VALUE    0	//ADC3
#define PORTA_PIN4_INITIAL_VALUE    0	//ADC4
#define PORTA_PIN5_INITIAL_VALUE    0	//ADC5
#define PORTA_PIN6_INITIAL_VALUE    0	//ADC6
#define PORTA_PIN7_INITIAL_VALUE	0	//ADC7

#define PORTB_PIN0_INITIAL_VALUE	0	//XCK,T0
#define PORTB_PIN1_INITIAL_VALUE    0	//T1		
#define PORTB_PIN2_INITIAL_VALUE    0	//INT2,AIN0
#define PORTB_PIN3_INITIAL_VALUE    0	//OC0,AIN1
#define PORTB_PIN4_INITIAL_VALUE    0	//SS		
#define PORTB_PIN5_INITIAL_VALUE    0	//MOSI		
#define PORTB_PIN6_INITIAL_VALUE    0	//MISO		
#define PORTB_PIN7_INITIAL_VALUE	0	//SCK		

#define PORTC_PIN0_INITIAL_VALUE	0	//SCL
#define PORTC_PIN1_INITIAL_VALUE    0	//SDA
#define PORTC_PIN2_INITIAL_VALUE    0	//TCK
#define PORTC_PIN3_INITIAL_VALUE    0	//TMS
#define PORTC_PIN4_INITIAL_VALUE    0	//TDO
#define PORTC_PIN5_INITIAL_VALUE    0	//TDI
#define PORTC_PIN6_INITIAL_VALUE    0	//TOSC1
#define PORTC_PIN7_INITIAL_VALUE	0	//TOSC2

#define PORTD_PIN0_INITIAL_VALUE	0	//RXD
#define PORTD_PIN1_INITIAL_VALUE    0	//TXD
#define PORTD_PIN2_INITIAL_VALUE    0	//INT0
#define PORTD_PIN3_INITIAL_VALUE    0	//INT1
#define PORTD_PIN4_INITIAL_VALUE    0	//OC1B
#define PORTD_PIN5_INITIAL_VALUE    0	//OC1A
#define PORTD_PIN6_INITIAL_VALUE    0	//ICP1
#define PORTD_PIN7_INITIAL_VALUE	0	//ICP1

/******************************************************/
 
#endif
