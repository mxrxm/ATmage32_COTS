 /*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EEPROM_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:HAL
 *   SWC:EEPROM
 *
 */
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

 
void EEPROM_voidSendDataByte(u16 Copy_u16Address,u8 Copy_u8DataByte);
u8 EEPROM_voidReadDataByte(u16 Copy_u16Address);

#endif
