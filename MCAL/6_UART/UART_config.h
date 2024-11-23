 /*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  UART_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:UART 
*
*/
#ifndef  _UART_CONFIG_H_
#define  _UART_CONFIG_H_
 
/*
Transmit/Receive
 1-Disable
 2-Enable
 */
#define UART_TRANSMIT 	Enable
#define UART_RECEIVE 	Enable
/********************************************************************************************/
/*
Interrupts:
 1-Disable
 2-Enable
 */
#define UART_TRANSMIT_INTERRUPT 		Disable
#define UART_RECEIVE_INTERRUPT 			Enable
#define UART_DATA_REG_EMPTY_INTERRUPT	Disable
/*
 Operation Mode:
 1-UART_Asynch_Op
 2-UART_Synch_Op
  */
#define UART_OPERATION	UART_Asynch_Op
/********************************************************************************************/
/*
 parity Mode:
  1-Disabled
  2-Even_Parity
  3-Odd_Parity
 */
#define UART_PARITY		Disabled
/********************************************************************************************/
/*
 Stop Bit mode:
 1-One_Bit
 2-Two_Bit
  */
#define UART_STOP_BIT	One_Bit
/********************************************************************************************/
/*
Data Bit Mode:
Data_5_Bit
Data_6_Bit
Data_7_Bit
Data_8_Bit
Data_9_Bit
*/
#define UART_DATA_BITS	Data_8_Bit
/********************************************************************************************/
#if UART_OPERATION==UART_Synch_Op
/*
 Polarity Mode:
 1-Rising_XCK_Edge
 2-Falling_XCK_Edge
 */
#define UART_CLK_POLARITY	Rising_XCK_Edge
#endif
/********************************************************************************************/
/*Baud Rate(bps):
 1-	 2400
 2-	 4800
 3-	 9600
 4-	 14400
 5-	 19200
 6-	 28800
 7-	 38400
 8-	 57600
 9-	 76800
 10- 115200
 11- 230100
 12- 250000
 13- 500000
 14- 1000000

 */
#define UART_BAUD_RATE	9600
/********************************************************************************************/
/*
 Double the baud rate
 1-Disable
 2-Enable
 */
#define UART_U2X	Disable
/********************************************************************************************/
#define UART_TIMEOUT	10000
#endif
