/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  ADC_register.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author: Mariem Ossama
*   Layer: MCAL
*   SWC: ADC
*
*/

#ifndef _ADC_REGISTER_H
#define _ADC_REGISTER_H

#define ADMUX          *((volatile u8*)0x27)    // ADC multiplexer selection register
#define ADMUX_REFS1     7                       // Reference selection bit 1
#define ADMUX_REFS0     6                       // Reference selection bit 0
#define ADMUX_ADLAR     5                       // ADC left adjust result (8-bit)

#define ADCSRA         *((volatile u8*)0x26)    // ADC control and status register
#define ADCSRA_ADEN     7                       // ADC enable
#define ADCSRA_ADSC     6                       // Start conversion
#define ADCSRA_ADATE    5                       // Auto trigger enable
#define ADCSRA_ADIF     4                       // Interrupt flag
#define ADCSRA_ADIE     3                       // Interrupt enable
#define ADCSRA_ADPS2    2                       // Prescaler bit 2
#define ADCSRA_ADPS1    1                       // Prescaler bit 1
#define ADCSRA_ADPS0    0                       // Prescaler bit 0

#define SFIOR_ADTS2		7
#define SFIOR_ADTS1		6
#define SFIOR_ADTS0		5

#define ADCH           *((volatile u8*)0x25)    // ADC data register high byte
#define ADCL           *((volatile u8*)0x24)    // ADC data register low byte

#define ADC            *((volatile u16*)0x24)   // Combined ADC data (16-bit access)

#endif  // ADC_REGISTER_H
