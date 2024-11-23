
/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  UART_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author: Mariem Ossama
 *   Layer: MCAL
 *   SWC: UART
 *
 */

#ifndef _UART_PROGRAM_C_
#define _UART_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "VECTORS_private.h"
#include "DIO_interface.h"

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_private.h"
#include "UART_config.h"

static u8 *UART_pu8SendData = NULL;
static u8 *UART_pu8ReceiveData = NULL;
static u8 UART_u8BufferSize;
static u8 UART_u8Index;
static u8 UART_u8State = IDLE;
static void (*UART_pvNotificationFunc[3])(void) = {NULL};
/*Flags*/
static u8 RECEIVE_ASYNCH_FLAG, TRANS_ASYNCH_FLAG;

void UART_voidInit()
{
	u8 Local_u8UCSRC = 0;
	u16 Local_u16UBRR = 0;
	/* Set baud rate */
	#if UART_U2X == Disable
		CLR_BIT(UCSRA, UCSRA_U2X);
		Local_u16UBRR = (u16)((f32)(500000UL / UART_BAUD_RATE) - 1);
	#elif UART_U2X == Enable
		SET_BIT(UCSRA, UCSRA_U2X);
		Local_u16UBRR = (u16)((f32)(1000000UL / UART_BAUD_RATE) - 1);
	#endif

	UBRRH = (u8)(Local_u16UBRR >> 8);
	UBRRL = (u8)Local_u16UBRR;

	/* Enable receiver and transmitter */
	UCSRB |= (UART_RECEIVE << UCSRB_RXEN) | (UART_TRANSMIT << UCSRB_TXEN);

	/*Set Interrupt Modes*/
	UCSRB |= (UART_RECEIVE_INTERRUPT << UCSRB_RXCIE) | (UART_TRANSMIT_INTERRUPT << UCSRB_TXCIE) | (UART_DATA_REG_EMPTY_INTERRUPT << UCSRB_UDRIE);

	/* Set frame format */
	/*select UCSRC Register */
	SET_BIT(Local_u8UCSRC, UCSRC_URSEL);
	/*Set Operation Mode*/
	#if UART_OPERATION == UART_Asynch_Op
		CLR_BIT(Local_u8UCSRC, UCSRC_UMSEL);
		CLR_BIT(Local_u8UCSRC, UCSRC_UCPOL);
	#elif UART_OPERATION == UART_Synch_Op
		SET_BIT(Local_u8UCSRC, UCSRC_UMSEL);
	#endif

	/*Select the CLK polarity*/
	#if UART_CLK_POLARITY == Rising_XCK_Edge
		CLR_BIT(Local_u8UCSRC, UCSRC_UCPOL);
	#elif UART_CLK_POLARITY == Falling_XCK_Edge
		SET_BIT(Local_u8UCSRC, UCSRC_UCPOL);
	#endif


	/* Set the parity mode */
	#if UART_PARITY == Disabled
		CLR_BIT(Local_u8UCSRC, UCSRC_UPM1);
		CLR_BIT(Local_u8UCSRC, UCSRC_UPM0);
	#elif UART_PARITY == Even_Parity
		SET_BIT(Local_u8UCSRC, UCSRC_UPM1);
		CLR_BIT(Local_u8UCSRC, UCSRC_UPM0);
	#elif UART_PARITY == Odd_Parity
		SET_BIT(Local_u8UCSRC, UCSRC_UPM1);
		SET_BIT(Local_u8UCSRC, UCSRC_UPM0);
	#endif

	/*Set Stop Bit*/
	#if UART_STOP_BIT == One_Bit
		CLR_BIT(Local_u8UCSRC, UCSRC_USBS);
	#elif UART_STOP_BIT == Two_Bit
		SET_BIT(Local_u8UCSRC, UCSRC_USBS);
	#endif

	/*Set Data Bits*/
	#if UART_DATA_BITS == Data_5_Bit
		CLR_BIT(Local_u8UCSRC, UCSRC_UCSZ1);
		CLR_BIT(Local_u8UCSRC, UCSRC_UCSZ0);
	#elif UART_DATA_BITS == Data_6_Bit
		CLR_BIT(Local_u8UCSRC, UCSRC_UCSZ1);
		SET_BIT(Local_u8UCSRC, UCSRC_UCSZ0);
	#elif UART_DATA_BITS == Data_7_Bit
		SET_BIT(Local_u8UCSRC, UCSRC_UCSZ1);
		CLR_BIT(Local_u8UCSRC, UCSRC_UCSZ0);
	#elif UART_DATA_BITS == Data_8_Bit
		SET_BIT(Local_u8UCSRC, UCSRC_UCSZ1);
		SET_BIT(Local_u8UCSRC, UCSRC_UCSZ0);
	#elif UART_DATA_BITS == Data_9_Bit
		SET_BIT(Local_u8UCSRC, UCSRC_UCSZ1);
		SET_BIT(Local_u8UCSRC, UCSRC_UCSZ0);
		SET_BIT(UCSRB, UCSRB_UCSZ2);
	#endif
	/*Assign the UCSRC */
	UCSRC = Local_u8UCSRC;
}
/***********************************************************************************************************************/

u8 UART_u8TransmitSynch(u16 Copy_u16Data)
{
	u8 Local_u8ErrorStatus = OK;
	u32 Local_u32TimeoutCounter = 0;
	/*Check state*/
	if (UART_u8State == IDLE)
	{
		/* Wait for empty data register buffer */
		while ((GET_BIT(UCSRA, UCSRA_UDRE) == 0) && (Local_u32TimeoutCounter != UART_TIMEOUT))
		{
			Local_u32TimeoutCounter++;
		}
		if (Local_u32TimeoutCounter == UART_TIMEOUT)
		{
			Local_u8ErrorStatus = NOK;
		}
		else
		{
			/* Copy 9th bit to TXB8 */
		#if UART_DATA_BITS == Data_9_Bit

			if (Copy_u16Data & 0x0100)
			{
				SET_BIT(UCSRB, UCSRB_TXB8);
			}
			else
			{
				CLR_BIT(UCSRB, UCSRB_TXB8);
			}
		#endif

			/* Put data into buffer, sends the data */
			UDR = Copy_u16Data;

			/*return the state*/
			UART_u8State = IDLE;
		}
	}

	else
	{
		Local_u8ErrorStatus = BUSY_FUNC;
	}

	return Local_u8ErrorStatus;
}
/***********************************************************************************************************************/

u8 UART_u8ReceiveSynch(u16 *Copy_u16Data)
{
	u8 Local_u8ErrorStatus = OK;
	u32 Local_u32TimeoutCounter = 0;
	/*Check state*/
	if (Copy_u16Data != NULL)
	{
		if (UART_u8State == IDLE)
		{
			/* Wait for empty receive buffer */
			while ((GET_BIT(UCSRA, UCSRA_RXC) == 0) && (Local_u32TimeoutCounter != UART_TIMEOUT))
			{
				Local_u32TimeoutCounter++;
			}
			if (Local_u32TimeoutCounter == UART_TIMEOUT)
			{
				Local_u8ErrorStatus = NOK;
			}
			else
			{
				/* Put data into variable*/
				*Copy_u16Data = UDR;

				/* Copy 9th bit to the variable */
				#if UART_DATA_BITS == Data_9_Bit
					*Copy_u16Data |= (GET_BIT(UCSRB, UCSRB_RXB8) << 9);
				#endif

				/*Clear the flag*/
				SET_BIT(UCSRA, UCSRA_RXC);

				/*return the state*/
				UART_u8State = IDLE;
			}
		}

		else
		{
			Local_u8ErrorStatus = BUSY_FUNC;
		}
	}
	else
	{
		Local_u8ErrorStatus = NULL_Pointer;
	}

	return Local_u8ErrorStatus;
}
/***********************************************************************************************************************/

u8 UART_u8TransmitASynch(u16 Copy_u16Data, void (*Copy_pCallBack)(void))
{
	u8 local_u8ErrorState = OK;
	if (Copy_pCallBack != NULL)
	{
		/*SET FLAG*/
		TRANS_ASYNCH_FLAG = 1;
		/*Set the State*/
		UART_u8State = BUSY;
		/*set the notification function*/
		UART_pvNotificationFunc[UART_TRANSFERE_COMPLETE] = Copy_pCallBack;
		/*Send the data*/
		/* Copy 9th bit to TXB8 */
		#if UART_DATA_BITS == Data_9_Bit

		if (Copy_u16Data & 0x0100)
		{
			SET_BIT(UCSRB, UCSRB_TXB8);
		}
		else
		{
			CLR_BIT(UCSRB, UCSRB_TXB8);
		}
		#endif
		/*Enable the transfere complete interrupt*/
		SET_BIT(UCSRB, UCSRB_TXCIE);

		/* Put data into buffer, sends the data */
		UDR = Copy_u16Data;
	}
	else
	{
		local_u8ErrorState = NULL_Pointer;
	}

	return local_u8ErrorState;
}
/***********************************************************************************************************************/

u8 UART_u8ReceiveASynch(u8 *Copy_u8Data, void (*Copy_pCallBack)(void))
{
	u8 local_u8ErrorState = OK;
	if (Copy_pCallBack != NULL)
	{
		/*SET FLAG*/
		RECEIVE_ASYNCH_FLAG = 1;

		/*Set the State*/
		UART_u8State = BUSY;

		/*set the notification function*/
		UART_pvNotificationFunc[UART_RECEIVE_COMPLETE] = Copy_pCallBack;

		/*enable the receive complete interrupt*/
		SET_BIT(UCSRB, UCSRB_RXCIE);

		/* Put data into variable*/
		UART_pu8ReceiveData = Copy_u8Data;
	}
	else
	{
		local_u8ErrorState = NULL_Pointer;
	}

	return local_u8ErrorState;
}
/***********************************************************************************************************************/

u8 UART_u8SendStringSynch(const u8 *Copy_u8Data)
{
	u8 Local_u8ErrorState = OK;
	u8 Local_u8Iterator = 0;
	if (Copy_u8Data != NULL)
	{
		while (Copy_u8Data[Local_u8Iterator] != '\0')
		{
			Local_u8ErrorState = UART_u8TransmitSynch(Copy_u8Data[Local_u8Iterator]);
			Local_u8Iterator++;
			if (Local_u8ErrorState == NOK)
			{
				return Local_u8ErrorState;
			}
		}
	}
	else
	{
		Local_u8ErrorState = NULL_Pointer;
	}
	return Local_u8ErrorState;
}
/***********************************************************************************************************************/

u8 UART_u8SendStringAsynch(const u8 *Copy_u8Data, void (*Copy_pCallBack)(void))
{
	u8 Local_u8ErrorState = OK;

	if (UART_u8State == IDLE)
	{
		if ((Copy_u8Data != NULL) && (Copy_pCallBack != NULL))
		{
			/*Set the Transfer flag*/
			TRANS_ASYNCH_FLAG=0;

			/*Set the UART State*/
			UART_u8State = BUSY;

			/*Assign the UART data globally*/
			UART_pu8SendData = Copy_u8Data;
			UART_pvNotificationFunc[UART_TRANSFERE_COMPLETE] = Copy_pCallBack;

			/*USART Data Register Empty Interrupt Enable*/
			SET_BIT(UCSRB, UCSRB_TXCIE);

			/*Set Index to first element*/
			UART_u8Index = 0;

			UDR = UART_pu8SendData[UART_u8Index];


		}
		else
		{
			Local_u8ErrorState = NULL_Pointer;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;
}
/***********************************************************************************************************************/

u8 UART_u8ReceiveBufferSynch(u8 *Copy_pchString, u32 Copy_uint32BufferSize)
{
	u8 Local_u8ErrorState = OK;
	u8 Local_u8Iterator = 0;
	if (Copy_pchString != NULL)
	{
		while (Local_u8Iterator < Copy_uint32BufferSize)
		{
			Local_u8ErrorState = UART_u8ReceiveSynch(&Copy_pchString[Local_u8Iterator]);
			Local_u8Iterator++;
			if (Local_u8ErrorState == NOK)
			{
				return Local_u8ErrorState;
			}
		}
		Copy_pchString[Copy_uint32BufferSize] = '\0';
	}
	else
	{
		Local_u8ErrorState = NULL_Pointer;
	}
	return Local_u8ErrorState;
}
/***********************************************************************************************************************/

u8 UART_u8ReceiveBufferAsynch(u8 *Copy_u8Data, u32 Copy_uint32BufferSize, void (*Copy_pCallBack)(void))
{
	u8 Local_u8ErrorState = OK;

	if (UART_u8State == IDLE)
	{
		if ((Copy_u8Data != NULL) && (Copy_pCallBack != NULL))
		{
			/*SET the flag*/
			RECEIVE_ASYNCH_FLAG = 0;

			/*Set the UART State*/
			UART_u8State = BUSY;

			/*Assign the UART data globally*/
			UART_pu8ReceiveData = Copy_u8Data;
			UART_u8BufferSize = Copy_uint32BufferSize;
			UART_pvNotificationFunc[UART_RECEIVE_COMPLETE] = Copy_pCallBack;

			/*USART Receive Interrupt Enable*/
			SET_BIT(UCSRB, UCSRB_RXCIE);

			/*Set Index to first element*/
			UART_u8Index = 0;


		}
		else
		{
			Local_u8ErrorState = NULL_Pointer;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

/***********************************************************************************************************************/
ISR(UART_TXC)
{
	if (TRANS_ASYNCH_FLAG == 1)
	{

		/*return the state to idle */
		UART_u8State = IDLE;

		/*Invoke the Callback notification function*/

		UART_pvNotificationFunc[UART_TRANSFERE_COMPLETE]();

		/*Disable Transfer Complete Interrupt*/

		CLR_BIT(UCSRB, UCSRB_TXCIE);

		/*Return */
	}
	else if(TRANS_ASYNCH_FLAG == 0)
	{
		/*Increment the index*/
		UART_u8Index++;

		if (UART_pu8SendData[UART_u8Index] == '\0')
		{
			/*Reset the index*/
			UART_u8Index = 0;

			/*return the state*/
			UART_u8State = IDLE;

			/*Invoke the Callback notification function*/
			UART_pvNotificationFunc[UART_TRANSFERE_COMPLETE]();

			/*USART Data Register Empty Interrupt Disable*/
			CLR_BIT(UCSRB, UCSRB_TXCIE);

			/*Return */
		}
		else
		{
			/*Send Data */
			UDR = UART_pu8SendData[UART_u8Index];
		}
	}
}
ISR(UART_UDRE)
{
}
ISR(UART_RXC)
{
	if (RECEIVE_ASYNCH_FLAG == 1)
	{

		/*return the state to idle */
		UART_u8State = IDLE;

		/*Assign the value of the UDR*/
		*UART_pu8ReceiveData = UDR;

		/* Copy 9th bit to the variable */

		#if UART_DATA_BITS == Data_9_Bit
		*UART_pu16ReceiveData |= (GET_BIT(UCSRB, UCSRB_RXB8) << 9);
		#endif

		/*Invoke the Callback notification function*/

		UART_pvNotificationFunc[UART_RECEIVE_COMPLETE]();

		/*Disable Receive conversion Complete Interrupt*/

		CLR_BIT(UCSRB, UCSRB_RXCIE);

		/*Return */
	}
	else if (RECEIVE_ASYNCH_FLAG == 0)
	{

		/*receive Data */
		UART_pu8ReceiveData[UART_u8Index] = UDR;
		/*Increment the index*/
		UART_u8Index++;

		if (UART_u8Index == UART_u8BufferSize)
		{
			/*Reset the index*/
			UART_u8Index = 0;

			/*Add the String Terminator*/
			UART_pu8ReceiveData[UART_u8BufferSize] = '\0';

			/*return the state*/
			UART_u8State = IDLE;

			/*Invoke the Callback notification function*/
			UART_pvNotificationFunc[UART_RECEIVE_COMPLETE]();

			/*USART Data Receive  Complete Interrupt Disable*/
			CLR_BIT(UCSRB, UCSRB_RXCIE);

			/*Return */
		}
	}
}
#endif /*_UART_PROGRAM_C_*/
