/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SSD_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:SSD
*
*/
#ifndef   SSD_PROGRAM_C_
#define   SSD_PROGRAM_C_
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static u8 Local_u8SSDNumbersCathode[10] = SSD_NUMBER_ARR_COMMON_CATHODE ;
static u8 Local_u8SSDNumbersAnode[10] = SSD_NUMBER_ARR_COMMON_ANODE ;


//----------------------------------------------------------------------------------------------------------------------------------------------------
 
void SSD_voidSendNumber( SSD_Type Copy_structConfig , u8 Copy_u8Number ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPortValue( Copy_structConfig.DataPort , Local_u8SSDNumbersCathode[ Copy_u8Number ] );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPortValue( Copy_structConfig.DataPort , ( Local_u8SSDNumbersAnode[ Copy_u8Number ] ) );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
void SSD_voidEnable    ( SSD_Type Copy_structConfig ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );
		DIO_enumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_LOW );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );
		DIO_enumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
void SSD_voidDisable   ( SSD_Type Copy_structConfig ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );
		DIO_enumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );

	}
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );
		DIO_enumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_LOW );

	}

}

#endif