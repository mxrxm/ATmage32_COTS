 /*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LM35_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:HAL
 *   SWC:LM35
 *
 */
#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#define ADC_10_RES 0
#define ADC_8_RES  1



typedef struct
	{
		u8 Copy_u8LM35Channel ;
		u8 Copy_u8ADCVoltageReference ;       /* Vref = 5 , 2.56 , External  */
		u8 Copy_u8ADCResolution ;            /* ADC_10_RES or ADC_8_RES  */
	} LM35_CONFIG ;
	
	u8 LM35_u8GetTemp (LM35_CONFIG * lm35 , u8 * Copy_u8TempValue) ;





#endif
