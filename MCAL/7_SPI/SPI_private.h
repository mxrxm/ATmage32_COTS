 /*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SPI_private.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:SPI 
*
*/
#ifndef  _SPI_PRIVATE_H_
#define  _SPI_PRIVATE_H_

 #define SPI_RISING_SAMPLE_FALLING_SETUP    0
 #define SPI_RISING_SETUP_FALLING_SAMPLE    1
 #define SPI_FALLING_SAMPLE_RISING_SETUP    2
 #define SPI_FALLING_SETUP_RISING_SAMPLE    3


#define SPI_CLK_2_PRESCALE      0
#define SPI_CLK_4_PRESCALE      1
#define SPI_CLK_8_PRESCALE      2
#define SPI_CLK_16_PRESCALE     3
#define SPI_CLK_32_PRESCALE     4
#define SPI_CLK_64_PRESCALE     5
#define SPI_CLK_128_PRESCALE    6

#define Disable     0
#define Enable      1


#define SPI_START_MSB      0
#define SPI_START_LSB      1

#endif
