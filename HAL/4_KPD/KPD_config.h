/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  KPD_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:KPD
*
*/
#ifndef   KPD_CONFIG_H_
#define   KPD_CONFIG_H_



                         /* C0   C1  C2  C3  */
#define KPD_u8Buttons  {{'7','8','9','/'},\
				        {'4','5','6','*'},\
						{'1','2','3','-'},\
				        {'?','0','=','+'}}



#define COLOUMN_NUMBER 4
#define ROW_NUMBER 4
/*
 	 Options:-

 	 	 1-DIO_PORTA
 	 	 2-DIO_PORTB
 	 	 3-DIO_PORTC
 	 	 4-DIO_PORTD

 */

#define KPD_PORT  DIO_PORTD

/*
 Options :-

 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 * */

#define KPD_R0    DIO_PIN0
#define KPD_R1    DIO_PIN1
#define KPD_R2    DIO_PIN2
#define KPD_R3    DIO_PIN3

#define KPD_C0    DIO_PIN4
#define KPD_C1    DIO_PIN5
#define KPD_C2    DIO_PIN6
#define KPD_C3    DIO_PIN7

#define KPD_ROWS     {KPD_R0,KPD_R1,KPD_R2,KPD_R3}

#define KPD_COLUMNS  {KPD_C0,KPD_C1,KPD_C2,KPD_C3}

#endif
