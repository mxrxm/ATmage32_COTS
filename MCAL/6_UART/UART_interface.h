 /*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  UART_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:UART 
*
*/

#ifndef  _UART_INTERFACE_H_
#define  _UART_INTERFACE_H_

#define UART_TRANSFERE_COMPLETE     0
#define UART_RECEIVE_COMPLETE       1
#define UART_DATA_REG_EMPTY         2


void UART_voidInit();

u8 UART_u8TransmitSynch	(u16 Copy_u16Data);
u8 UART_u8ReceiveSynch(u16* Copy_u16Data);

u8 UART_u8TransmitASynch	(u16 Copy_u16Data,void(*Copy_pCallBack)(void));
u8 UART_u8ReceiveASynch		(u8* Copy_u8Data,void(*Copy_pCallBack)(void));

u8 UART_u8SendStringSynch	(const u8* Copy_u8Data);
u8 UART_u8SendStringAsynch	(const u8* Copy_u8Data,void(*Copy_pCallBack)(void));

u8 UART_u8ReceiveBufferSynch	(u8 * Copy_pchString , u32 Copy_uint32BufferSize) ;
u8 UART_u8ReceiveBufferAsynch 	(u8* Copy_u8Data, u32 Copy_uint32BufferSize , void (* Copy_pCallBack)(void)) ;

#endif
