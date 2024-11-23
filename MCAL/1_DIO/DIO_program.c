/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:MCAL
 *   SWC:DIO/GPIO
 *
 */
#ifndef _DIO_PROGRAM_C_
#define _DIO_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

DIO_ErrorStatus DIO_enumSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if ((copy_u8PORT <= DIO_PORTD) && (copy_u8PIN <= DIO_PIN7))
	{

		if (copy_u8Direction == DIO_PIN_OUTPUT)
		{
			switch (copy_u8PORT)
			{
			case DIO_PORTA:
				SET_BIT(DDRA, copy_u8PIN);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB, copy_u8PIN);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC, copy_u8PIN);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD, copy_u8PIN);
				break;
			default:
				LOC_enumState = DIO_OK;
			}
		}
		else if (copy_u8Direction == DIO_PIN_INPUT)
		{
			switch (copy_u8PORT)
			{
			case DIO_PORTA:
				CLR_BIT(DDRA, copy_u8PIN);
				break;
			case DIO_PORTB:
				CLR_BIT(DDRB, copy_u8PIN);
				break;
			case DIO_PORTC:
				CLR_BIT(DDRC, copy_u8PIN);
				break;
			case DIO_PORTD:
				CLR_BIT(DDRD, copy_u8PIN);
				break;
			default:
				LOC_enumState = DIO_OK;
			}
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if ((copy_u8PORT <= DIO_PORTD) && (copy_u8PIN <= DIO_PIN7))
	{
		if (copy_u8Value == DIO_PIN_HIGH)
		{
			switch (copy_u8PORT)
			{
			case DIO_PORTA:
				SET_BIT(PORTA, copy_u8PIN);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB, copy_u8PIN);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC, copy_u8PIN);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD, copy_u8PIN);
				break;
			default:
				LOC_enumState = DIO_OK;
			}
		}
		else if (copy_u8Value == DIO_PIN_LOW)
		{
			switch (copy_u8PORT)
			{
			case DIO_PORTA:
				CLR_BIT(PORTA, copy_u8PIN);
				break;
			case DIO_PORTB:
				CLR_BIT(PORTB, copy_u8PIN);
				break;
			case DIO_PORTC:
				CLR_BIT(PORTC, copy_u8PIN);
				break;
			case DIO_PORTD:
				CLR_BIT(PORTD, copy_u8PIN);
				break;
			default:
				LOC_enumState = DIO_NOK;
			}
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumGetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 *Copy_PtrData)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if ((copy_u8PORT <= DIO_PORTD) && (copy_u8PIN <= DIO_PIN7))
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:
			*Copy_PtrData = GET_BIT(PINA, copy_u8PIN);
			break;
		case DIO_PORTB:
			*Copy_PtrData = GET_BIT(PINB, copy_u8PIN);
			break;
		case DIO_PORTC:
			*Copy_PtrData = GET_BIT(PINC, copy_u8PIN);
			break;
		case DIO_PORTD:
			*Copy_PtrData = GET_BIT(PIND, copy_u8PIN);
			break;
		default:
			LOC_enumState = DIO_NOK;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumTogPinValue(u8 copy_u8PORT, u8 copy_u8PIN)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if ((copy_u8PORT <= DIO_PORTD) && (copy_u8PIN <= DIO_PIN7))
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:
			TOG_BIT(PINA, copy_u8PIN);
			break;
		case DIO_PORTB:
			TOG_BIT(PINB, copy_u8PIN);
			break;
		case DIO_PORTC:
			TOG_BIT(PINC, copy_u8PIN);
			break;
		case DIO_PORTD:
			TOG_BIT(PIND, copy_u8PIN);
			break;
		default:
			LOC_enumState = DIO_NOK;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumSetPortDirection(u8 copy_u8PORT, u8 copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if (copy_u8PORT <= DIO_PORTD)
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:
			DDRA = copy_u8Direction;
			break;
		case DIO_PORTB:
			DDRB = copy_u8Direction;
			break;
		case DIO_PORTC:
			DDRC = copy_u8Direction;
			break;
		case DIO_PORTD:
			DDRD = copy_u8Direction;
			break;
		default:
			LOC_enumState = DIO_NOK;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumSetPortValue(u8 copy_u8PORT, u8 copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if (copy_u8PORT <= DIO_PORTD)
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:
			PORTA = copy_u8Value;
			break;
		case DIO_PORTB:
			PORTB = copy_u8Value;
			break;
		case DIO_PORTC:
			PORTC = copy_u8Value;
			break;
		case DIO_PORTD:
			PORTD = copy_u8Value;
			break;
		default:
			LOC_enumState = DIO_NOK;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumGetPortValue(u8 copy_u8PORT, u8 *Copy_PtrData)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if (copy_u8PORT <= DIO_PORTD)
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:
			*Copy_PtrData = PINA;
			break;
		case DIO_PORTB:
			*Copy_PtrData = PINB;
			break;
		case DIO_PORTC:
			*Copy_PtrData = PINC;
			break;
		case DIO_PORTD:
			*Copy_PtrData = PIND;
			break;
		default:
			LOC_enumState = DIO_NOK;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumTogPortValue(u8 copy_u8PORT)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if (copy_u8PORT <= DIO_PORTD)
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:
			PORTA = ~PORTA;
			break;
		case DIO_PORTB:
			PORTB = ~PORTB;
			break;
		case DIO_PORTC:
			PORTC = ~PORTC;
			break;
		case DIO_PORTD:
			PORTD = ~PORTD;
			break;
		default:
			LOC_enumState = DIO_NOK;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumConnectPullup(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8ConnectPullup)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		if (Copy_u8ConnectPullup == DIO_PIN_HIGH)
		{
			CLR_BIT(SFIOR, PUD);
			switch (Copy_u8PORT)
			{
			case DIO_PORTA:
				CLR_BIT(DDRA, Copy_u8PIN);
				SET_BIT(PORTA, Copy_u8PIN);
				break;
			case DIO_PORTB:
				CLR_BIT(DDRB, Copy_u8PIN);
				SET_BIT(PORTB, Copy_u8PIN);
				break;
			case DIO_PORTC:
				CLR_BIT(DDRC, Copy_u8PIN);
				SET_BIT(PORTC, Copy_u8PIN);
				break;
			case DIO_PORTD:
				CLR_BIT(DDRD, Copy_u8PIN);
				SET_BIT(PORTD, Copy_u8PIN);
				break;
			default:
				LOC_enumState = DIO_NOK;
			}
		}
		else
		{
			SET_BIT(SFIOR, PUD);
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumWriteLowNibbles(u8 Copy_u8PORT, u8 Copy_u8value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if ((Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value &= 0x0f;
		switch (Copy_u8PORT)
		{
		case DIO_PORTA:
			PORTA &= 0xf0; // Set only the high nibble of the port A by the given value
			PORTA |= Copy_u8value;
			break;
		case DIO_PORTB:
			PORTB &= 0xf0; // Set only the high nibble of the port B by the given value
			PORTB |= Copy_u8value;
			break;
		case DIO_PORTC:
			PORTC &= 0xf0; // Set only the high nibble of the port C by the given value
			PORTC |= Copy_u8value;
			break;
		case DIO_PORTD:
			PORTD &= 0xf0; // Set only the high nibble of the port D by the given value
			PORTD |= Copy_u8value;
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumWriteHighNibbles(u8 Copy_u8PORT, u8 Copy_u8value)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if ((Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value = (Copy_u8value << 4);
		switch (Copy_u8PORT)
		{
		case DIO_PORTA:
			PORTA &= 0x0f;		   // make sure the high bits = 0000
			PORTA |= Copy_u8value; // Set only the high nibble of the port A by the given value
			break;
		case DIO_PORTB:
			PORTB &= 0x0f; // Set only the high nibble of the port B by the given value
			PORTB |= Copy_u8value;
			break;
		case DIO_PORTC:
			PORTC &= 0x0f; // Set only the high nibble of the port C by the given value
			PORTC |= Copy_u8value;
			break;
		case DIO_PORTD:
			PORTD &= 0x0f; // Set only the high nibble of the port D by the given value
			PORTD |= Copy_u8value;
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState;
}

#endif
