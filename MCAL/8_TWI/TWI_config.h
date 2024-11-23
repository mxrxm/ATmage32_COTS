 /*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TWI_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:TWI 
*
*/
#ifndef  _TWI_CONFIG_H_
#define  _TWI_CONFIG_H_
 
 
/*
TWI CLK PRESCALE: 
1- TWI_NO_PRESCALE  
2- TWI_4_PRESCALE   
3- TWI_16_PRESCALE  
4- TWI_64_PRESCALE  
*/  
#define TWI_PRESCALE    TWI_NO_PRESCALE 
/*********************************************************************************************/
#define TWI_SCL   400000UL 
/*********************************************************************************************/
#define F_CPU 8000000UL

#endif
