 /*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SPI_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:SPI 
*
*/
#ifndef  _SPI_CONFIG_H_
#define  _SPI_CONFIG_H_

 /*
 SPI Data Mode:
 1- SPI_RISING_SAMPLE_FALLING_SETUP
 2- SPI_RISING_SETUP_FALLING_SAMPLE
 3- SPI_FALLING_SAMPLE_RISING_SETUP
 4- SPI_FALLING_SETUP_RISING_SAMPLE 
 */
#define SPI_DATA_MODE   SPI_RISING_SETUP_FALLING_SAMPLE
/*********************************************************************************************/
/*
SPI CLK select (SCK):
 1- SPI_CLK_2_PRESCALE  
 2- SPI_CLK_4_PRESCALE  
 3- SPI_CLK_8_PRESCALE  
 4- SPI_CLK_16_PRESCALE 
 5- SPI_CLK_32_PRESCALE 
 6- SPI_CLK_64_PRESCALE 
 7- SPI_CLK_128_PRESCALE
*/
#define SPI_CLK   SPI_CLK_16_PRESCALE
/*********************************************************************************************/
/*
SPI Interrupt:
1- Enable
2- Disable
*/
#define SPI_INTERRUPT  Disable
/*********************************************************************************************/
/*
SPI Data Order:
1- SPI_START_MSB
2- SPI_START_LSB 
*/
#define SPI_DATA_ORDER  SPI_START_MSB
/*********************************************************************************************/
#define SPI_TIMEOUT	10000

#endif
