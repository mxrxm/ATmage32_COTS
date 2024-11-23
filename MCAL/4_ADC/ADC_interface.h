/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  ADC_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:ADC 
*
*/

#ifndef  _ADC_INTERFACE_H_
#define  _ADC_INTERFACE_H_

#define ADC_Channel_0         0
#define ADC_Channel_1         1
#define ADC_Channel_2         2
#define ADC_Channel_3         3
#define ADC_Channel_4         4
#define ADC_Channel_5         5
#define ADC_Channel_6         6
#define ADC_Channel_7         7

/*Differential Channels*/
#define ADC_CH0_CH0_10x       8
#define ADC_CH1_CH0_10x       9

#define ADC_CH0_CH0_200x      10
#define ADC_CH1_CH0_200x      11

#define ADC_CH2_CH2_10x       12
#define ADC_CH3_CH2_10x       13

#define ADC_CH2_CH2_200x      14
#define ADC_CH3_CH2_200x      15

#define ADC_CH0_CH1_1x        16
#define ADC_CH1_CH1_1x        17
#define ADC_CH2_CH1_1x        18
#define ADC_CH3_CH1_1x        19
#define ADC_CH4_CH1_1x        20
#define ADC_CH5_CH1_1x        21
#define ADC_CH6_CH1_1x        22
#define ADC_CH7_CH1_1x        23
#define ADC_CH0_CH2_1x        24
#define ADC_CH1_CH2_1x        25
#define ADC_CH2_CH2_1x        26
#define ADC_CH3_CH2_1x        27
#define ADC_CH4_CH2_1x        28

 /*ADC CLK Pre-scale*/
 #define  ADC_2_PRESCALE      2
 #define  ADC_4_PRESCALE      4
 #define  ADC_8_PRESCALE      8
 #define  ADC_16_PRESCALE     16
 #define  ADC_32_PRESCALE     32
 #define  ADC_64_PRESCALE     64
 #define  ADC_128_PRESCALE    128

/*Trigger source modes*/
#define   ADC_Free_Running_mode         0
#define   ADC_Analog_Comparator         1
#define   ADC_EXTI_Request_0			    2
#define   ADC_Timer0_Compare_Match      3
#define   ADC_Timer0_Overflow			    4
#define   ADC_Timer1_Compare_Match_B	 5
#define   ADC_Timer1_Overflow			    6
#define   ADC_Timer1_Capture_Event0     7

 
 typedef struct 
 {
    u8* Channel; 
    u16* result;            
    u8 Size;    
    void(*NotificationFunc)(void);  

 }ADC_ChainType;
 
 



void ADC_voidInit(void);

void ADC_voidEnable(void);
void ADC_voidDisable (void);

void ADC_voidInterruptEnable (void);
void ADC_voidInterruptDisable(void);

u8 ADC_u8StartConversionSynch(u8 copy_u8Channel,u16* Copy_u16Reading);
u8 ADC_u8StartConversionAsynch(u8 copy_u8Channel,void (*Copy_pvoidCallBack)(void),u16* Copy_pu16Reading);

u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler);

u8 ADC_u8StartChainConversion( ADC_ChainType* Copy_Chain);


 
#endif
