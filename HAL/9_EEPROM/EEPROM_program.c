/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EEPROM_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:EEPROM
*
*/
#ifndef   EEPROM_PROGRAM_C_
#define   EEPROM_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include<util/delay.h>

#define EEPROM_FIXED_ADDRESS		0b01010000

void EEPROM_voidSendDataByte(u16 Copy_u16Address,u8 Copy_u8DataByte)
{

	u8 Local_u8AddressPacket;
	Local_u8AddressPacket=((EEPROM_FIXED_ADDRESS) | (EEPROM_A2<<2) | (u8)(Copy_u16Address>>8));
	/*Send The Start Condition*/
	TWI_SendStartCondition();
	/*Send the Block address*/
	 TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);
	/*Send the Byte address*/
	 TWI_MasterWriteDataByte((u8)Copy_u16Address);
	 _delay_ms(10);
	/*Send the Data Byte*/
	 TWI_MasterWriteDataByte(Copy_u8DataByte);
	 _delay_ms(10);
	/*Send The Stop Condition*/
	TWI_SendStopCondition();
	_delay_ms(10);
}


u8 EEPROM_voidReadDataByte(u16 Copy_u16Address)
{
	u8 Local_u8AddressPacket;
	u8 Local_u8DataByte;
	Local_u8AddressPacket=((EEPROM_FIXED_ADDRESS) | (EEPROM_A2<<2) | (u8)(Copy_u16Address>>8));
    /*Send The Start Condition*/
	TWI_SendStartCondition();
    /*Send the Block address*/
	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);
    /*Send the Byte address*/
	TWI_MasterWriteDataByte((u8)Copy_u16Address);
    _delay_ms(10);
    /*Send Repeated Start to change the Operation*/
    TWI_SendRepeatedStart();
    /*Send the Block address*/
    TWI_SendSlaveAddressWithRead(Local_u8AddressPacket);
    /*Read the Data Byte*/
    TWI_MasterReadDataByte(&Local_u8DataByte);
	_delay_ms(10);
    /*Send The Stop Condition*/
    TWI_SendStopCondition();
	_delay_ms(10);

    return Local_u8DataByte;

 }
 
#endif
