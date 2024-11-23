/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LM35_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:LM35
*
*/
#ifndef   LM35_PROGRAM_C_
#define   LM35_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "MAP.h"
#include "LM35_private.h"
#include "LM35_interface.h"
#include "LM35_config.h"

u8 LM35_u8GetTemp (LM35_CONFIG * lm35 , u8 * Copy_u8TempValue)
{
	u8 Local_u8ErrorState = OK ;

	u16 Local_u16ADCResult ;
	u16 Local_u16AnalogValue ;
	
	u16 Local_u8ADCReference = ( lm35->Copy_u8ADCVoltageReference ) * 1000 ;  // To Convert from ( V --> mV )
	
	
	/* ADC Digital Reading  */
	ADC_u8StartConversionSynch( lm35->Copy_u8LM35Channel , &Local_u16ADCResult ) ;

	/* Check for ADC Resolution  */
	if ( lm35->Copy_u8ADCResolution == ADC_10_RES )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 1024UL) ;

	}
	else if ( lm35->Copy_u8ADCResolution == ADC_8_RES )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 256UL) ;
	}


	/* Convert ( mv --> Temp ) */
	* Copy_u8TempValue = Local_u16AnalogValue / 10 ;

	return Local_u8ErrorState ;
}
 
#endif
