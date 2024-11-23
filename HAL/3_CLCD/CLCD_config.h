/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:CLCD
*
*/
#ifndef   CLCD_CONFIG_H_
#define   CLCD_CONFIG_H_
/***************************************************************************************/
 /*    1-FOUR_BITS
       2-EIGHT_BITS
 */
/***************************************************************************************/

#define CLCD_MODE  FOUR_BITS

/***************************************************************************************/

#define CLCD_DATA_PORT      DIO_PORTA
/* RS,RW,EN */
#define CLCD_CONTROL_PORT   DIO_PORTA

/***************************************************************************************/


#define CLCD_RS             DIO_PIN1
#define CLCD_RW             DIO_PIN2
#define CLCD_EN             DIO_PIN3

/***************************************************************************************/
#define CLCD_D4             DIO_PIN4
#define CLCD_D5             DIO_PIN5
#define CLCD_D6             DIO_PIN6
#define CLCD_D7             DIO_PIN7


#endif
