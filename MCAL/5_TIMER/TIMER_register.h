/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TIMER_register.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author: Mariem Ossama
*   Layer: MCAL
*   SWC: TIMER
*
*/

#ifndef _TIMER_REGISTER_H_
#define _TIMER_REGISTER_H_

/************************************************************************************************************************/
#define  TCNT0      *((volatile u8*)0x52)    //Timer/Counter0 Register  


#define  TCCR0      *((volatile u8*)0x53)    //Timer/Counter0 Control Register  
#define  TCCR0_FOC0         7                //Force Output Compare(at non-pwm mode)                         
#define  TCCR0_WGM00        6                //Waveform Generation Mode Bit-0
#define  TCCR0_COM01        5                //Compare Match Output Mode Bit-1
#define  TCCR0_COM00        4                //Compare Match Output Mode Bit-0
#define  TCCR0_WGM01        3                //Waveform Generation Mode Bit-1
#define  TCCR0_CS02         2                //Clock Select (pre-scale) Bit-2 
#define  TCCR0_CS01         1                //Clock Select (pre-scale) Bit-1
#define  TCCR0_CS00         0                //Clock Select (pre-scale) Bit-0


#define  OCR0       *((volatile u8*)0x5C)    //Timer/Counter0 Output Compare Register 

/************************************************************************************************************************/

#define  TIMSK      *((volatile u8*)0x59)    //Timer/Counter Interrupt Mask Register
#define  TIMSK_TOIE0        0                //Timer/Counter0 Overflow Interrupt Enable
#define  TIMSK_OCIE0        1                //Timer/Counter0 Output Compare Match Interrupt Enable
#define  TIMSK_TOIE1		2                //Timer/Counter1 Overflow Interrupt Enable
#define  TIMSK_OCIE1B		3                //Timer/Counter1 Output Compare B Match Interrupt Enable
#define  TIMSK_OCIE1A		4                //Timer/Counter1 Output Compare A Match Interrupt Enable
#define  TIMSK_TICIE1		5                //Timer/Counter1 Input Capture Interrupt Enable
#define  TIMSK_TOIE2		6                //Timer/Counter2 Overflow Interrupt Enable
#define  TIMSK_OCIE2		7                //Timer/Counter2 Output Compare Match Interrupt Enable


#define  TIFR       *((volatile u8*)0x58)   //Timer/Counter Interrupt Flag Register
#define  TIFR_TOV0          0               //Timer/Counter0 Overflow Flag
#define  TIFR_OCF0          1  				//Timer/Counter0 Output Compare Flag
#define  TIFR_TOV1  		2               //Timer/Counter1 Overflow Flag
#define  TIFR_OCF1B			3               //Timer/Counter1 Output Compare B Match Flag
#define  TIFR_OCF1A			4               //Timer/Counter1 Output Compare A Match Flag
#define  TIFR_ICF1			5               //Timer/Counter1 Input Capture Flag
#define  TIFR_TOV2			6               //Timer/Counter2 Overflow Flag
#define  TIFR_OCF2			7               //Timer/Counter2 Output Compare Flag 2

/************************************************************************************************************************/         

#define TCCR1A      *((volatile u8*)0x4F)    //Timer/Counter1 Control Register A  
#define TCCR1A_COM1A1       7                //Compare Output Mode for Compare unit A Bit-1
#define TCCR1A_COM1A0       6                //Compare Output Mode for Compare unit A Bit-0
#define TCCR1A_COM1B1       5                //Compare Output Mode for Compare unit B Bit-1
#define TCCR1A_COM1B0       4                //Compare Output Mode for Compare unit B Bit-0
#define TCCR1A_FOC1A        3                //Force Output Compare for Compare unit A
#define TCCR1A_FOC1B        2                //Force Output Compare for Compare unit B
#define TCCR1A_WGM11        1                //Waveform Generation Mode Bit-1
#define TCCR1A_WGM10        0                //Waveform Generation Mode Bit-0
 
        
#define TCCR1B      *((volatile u8*)0x4E)
#define TCCR1B_ICNC1        7                //Input Capture Noise Canceler
#define TCCR1B_ICES1        6                //Input Capture Edge Select 
#define TCCR1B_WGM13        4                //Waveform Generation Mode Bit-3
#define TCCR1B_WGM12        3                //Waveform Generation Mode Bit-2
#define TCCR1B_CS12         2                //Clock Select (pre-scale) Bit-2
#define TCCR1B_CS11         1                //Clock Select (pre-scale) Bit-1
#define TCCR1B_CS10         0                //Clock Select (pre-scale) Bit-0
     
#define TCNT1H      *((volatile u8*)0x4D)    //Timer/Counter1 Counter Register High Byte           
#define TCNT1L      *((volatile u8*)0x4C)    //Timer/Counter1 Counter Register Low Byte            
#define OCR1AH      *((volatile u8*)0x4B)    //Timer/Counter1 Output Compare Register A High Byte  
#define OCR1AL      *((volatile u8*)0x4A)    //Timer/Counter1 Output Compare Register A Low Byte  
#define OCR1BH      *((volatile u8*)0x49)    //Timer/Counter1 Output Compare Register B High Byte  
#define OCR1BL      *((volatile u8*)0x48)    //Timer/Counter1 Output Compare Register B Low Byte  
#define ICR1H       *((volatile u8*)0x47)    //Timer/Counter1 Input Capture Register High Byte      
#define ICR1L       *((volatile u8*)0x46)    //Timer/Counter1 Input Capture Register Low Byte       

/*16 bits registers*/
#define TCNT1        *((volatile u16*)0x4C)  //Timer/Counter1 Counter Register
#define OCR1A        *((volatile u16*)0x4A)  //Timer/Counter1 Output Compare Register A
#define OCR1B        *((volatile u16*)0x48)  //Timer/Counter1 Output Compare Register B
#define ICR1         *((volatile u16*)0x46)  //Timer/Counter1 Input Capture Register
 
/************************************************************************************************************************/

#define TCCR2        *((volatile u8*)0x45)   //Timer/Counter2 Control Register   
#define TCCR2_FOC2          7                //Force Output Compare
#define TCCR2_WGM20         6                //Waveform Generation Mode Bit-0
#define TCCR2_COM21         5                //Compare Match Output Mode Bit-1
#define TCCR2_COM20         4                //Compare Match Output Mode Bit-0
#define TCCR2_WGM21         3                //Waveform Generation Mode Bit-1
#define TCCR2_CS22          2                //Clock Select (pre-scale) Bit-2
#define TCCR2_CS21          1                //Clock Select (pre-scale) Bit-1
#define TCCR2_CS20          0                //Clock Select (pre-scale) Bit-0

#define  TCNT2       *((volatile u8*)0x44)   //Timer/Counter2 (8 Bits) 
#define  OCR2        *((volatile u8*)0x43)   //Timer/Counter2 Output Compare Register

/************************************************************************************************************************/

#define SFIOR_PSR10         0				//Timer/Counter0/1 Prescale Reset
#define SFIOR_PSR2          1				//Timer/Counter2 Prescale Reset

/************************************************************************************************************************/

#define WDTCR		*((volatile u8*)0x41)
#define WDTCR_WDTOE			4				//Watchdog Turn-off Enable
#define WDTCR_WDE			3				//Watchdog Enable
#define WDTCR_WDP2			2				//Watchdog Timer Prescaler Bit-2
#define WDTCR_WDP1			1				//Watchdog Timer Prescaler Bit-1
#define WDTCR_WDP0			0				//Watchdog Timer Prescaler Bit-0


#endif  /*TIMER_REGISTER_H*/
