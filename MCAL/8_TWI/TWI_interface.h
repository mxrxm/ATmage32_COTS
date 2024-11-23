 /*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TWI_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:TWI 
*
*/

#ifndef  _TWI_INTERFACE_H_
#define  _TWI_INTERFACE_H_

#define TWI_SLAVE   0 
#define TWI_MASTER  1

/* Error Status fot TWI */
typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	SlaveWriteByteErr,
	SlaveReadByteErr,
	
}TWI_Error_Stat;

/*Pass Zero To the Master when it's Not Used As A Reciever */
void TWI_voidMasterInit (u8 Copy_u8Address);
void TWI_voidSlaveInit  (u8 Copy_u8Address);

TWI_Error_Stat TWI_SendStartCondition(void);
TWI_Error_Stat TWI_SendRepeatedStart (void);

TWI_Error_Stat TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
TWI_Error_Stat TWI_SendSlaveAddressWithRead (u8 Copy_u8SlaveAddress);

TWI_Error_Stat TWI_MasterWriteDataByte(u8 Copy_u8DataByte);
TWI_Error_Stat TWI_MasterReadDataByte (u8* Copy_pu8DataByte);

TWI_Error_Stat TWI_SlaveWriteDataByte(u8 Copy_u8DataByte);
TWI_Error_Stat TWI_SlaveReadDataByte (u8* Copy_pu8DataByte);

void TWI_SendStopCondition(void);
 
#endif
