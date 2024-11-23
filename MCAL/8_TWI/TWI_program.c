 
/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TWI_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author: Mariem Ossama
 *   Layer: MCAL
 *   SWC: TWI
 *
 */

#ifndef  _TWI_PROGRAM_C_
#define  _TWI_PROGRAM_C_


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "VECTORS_private.h"
#include "DIO_interface.h"

#include "TWI_interface.h"
#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_config.h"

 

void TWI_voidMasterInit (u8 Copy_u8Address)
{
    /*Intialize the Clk*/
    TWBR= (u8) (((F_CPU/TWI_SCL)-16) / (2*TWI_PRESCALE));
    #if TWI_PRESCALE==TWI_NO_PRESCALE
    TWSR=0;
    #elif TWI_PRESCALE==TWI_4_PRESCALE
    TWSR=1;
    #elif TWI_PRESCALE==TWI_16_PRESCALE
    TWSR=2;
    #elif TWI_PRESCALE==TWI_64_PRESCALE
    TWSR=3;
    #endif
    /*Assign the addresse*/
    if(Copy_u8Address!=0)
    {
        TWAR=(Copy_u8Address<<1);
    }

    /*Enable The ACK bit*/
    SET_BIT(TWCR,TWCR_TWEA);
    /*Enable THe TWI*/
    SET_BIT(TWCR,TWCR_TWEN);
}
/******************************************************************************************************************/
void TWI_voidSlaveInit  (u8 Copy_u8Address)
{
    /*Intialize the Slave addresse*/
    TWAR=(Copy_u8Address<<1);
    /*Enable Acknowledge bit*/
	SET_BIT(TWCR,TWCR_TWEA);
    /*Enable THe TWI*/
    SET_BIT(TWCR,TWCR_TWEN);    
}
/******************************************************************************************************************/
TWI_Error_Stat TWI_SendStartCondition(void)
{
    TWI_Error_Stat local_ErrorStatus=NoError;
    /*Send Start Condition On the Bus*/
    SET_BIT(TWCR,TWCR_TWSTA);
    /*Clear the Interrupt Flag To Start The Operation*/
    SET_BIT(TWCR,TWCR_TWINT);
    /*Wait on the Flag Untill The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT));
    /*Check on the Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_START_ACK)
    {
        local_ErrorStatus=StartConditionErr;
    }
    return local_ErrorStatus;
}
/******************************************************************************************************************/
TWI_Error_Stat TWI_SendRepeatedStart (void)
{
    TWI_Error_Stat local_ErrorStatus=NoError;
    /*Send Start Condition On the Bus*/
    SET_BIT(TWCR,TWCR_TWSTA);
    /*Clear the Interrupt Flag To Start The Operation*/
    SET_BIT(TWCR,TWCR_TWINT);
    /*Wait on the Flag Untill The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT));
     /*Check on the Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_RE_START_ACK)
    {
        local_ErrorStatus=RepeatedStartErr;
    }
    return local_ErrorStatus;
}
/******************************************************************************************************************/
TWI_Error_Stat TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
    TWI_Error_Stat local_ErrorStatus=NoError;
    /*Clear the Start Condition Bit*/
    CLR_BIT(TWCR,TWCR_TWSTA);
    /*Set the Slave Addresse in the 7 MSB in The TWDR*/
    TWDR=(Copy_u8SlaveAddress<<1);
    /*Send the Write Request*/
    CLR_BIT(TWDR,0);
    /*Clear the Interrupt Flag To Start The Operation*/
    SET_BIT(TWCR,TWCR_TWINT);
    /*Wait on the Flag Untill The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT));
     /*Check on the Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_MSTR_TRANS_SLA_W_ACK)
    {
        local_ErrorStatus=SlaveAddressWithWriteErr;
    }    
    return local_ErrorStatus;
}
/******************************************************************************************************************/
TWI_Error_Stat TWI_SendSlaveAddressWithRead (u8 Copy_u8SlaveAddress)
{
    TWI_Error_Stat local_ErrorStatus=NoError;
    /*Clear the Start Condition Bit*/
    CLR_BIT(TWCR,TWCR_TWSTA);
    /*Set the Slave Addresse in the 7 MSB in The TWDR*/
    TWDR=(Copy_u8SlaveAddress<<1);
    /*Send the Read Request*/
    SET_BIT(TWDR,0);
    /*Clear the Interrupt Flag To Start The Operation*/
    SET_BIT(TWCR,TWCR_TWINT);
    /*Wait on the Flag Until The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT));
    /*Check on the Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_MSTR_TRANS_SLA_R_ACK)
    {
        local_ErrorStatus=SlaveAddressWithReadErr;
    }    
    return local_ErrorStatus;
}
/******************************************************************************************************************/
TWI_Error_Stat TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
    TWI_Error_Stat local_ErrorStatus=NoError;
    /*Write The Data Byte In The Register*/
    TWDR=Copy_u8DataByte;
    /*Clear the Interrupt Flag To Start The Operation*/
    SET_BIT(TWCR,TWCR_TWINT);
    /*Wait on the Flag Until The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT));
    /*Check on the Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_MSTR_TRANS_DATA_ACK)
    {
        local_ErrorStatus=MasterWriteByteErr;
    }   
    return local_ErrorStatus;
}
/******************************************************************************************************************/
TWI_Error_Stat TWI_MasterReadDataByte (u8* Copy_pu8DataByte)
{
    TWI_Error_Stat local_ErrorStatus=NoError;

    /*Clear Flag To Make the Slave Send data*/
    SET_BIT(TWCR,TWCR_TWINT);
    /*Wait on the Flag Until The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT)); 
    /*Check On the Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_MSTR_RCVD_DATA_ACK)
    {
        local_ErrorStatus=MasterReadByteErr;
    }  
    else
    {  

    /*Read The Data Byte From The Register*/
    *Copy_pu8DataByte=TWDR;

    }
 
    return local_ErrorStatus;
}
/******************************************************************************************************************/
TWI_Error_Stat TWI_SlaveWriteDataByte(u8 Copy_u8DataByte)
{
    TWI_Error_Stat local_ErrorStatus=NoError;
    /*Write The Data Byte In The Register*/
    TWDR=Copy_u8DataByte;
    /*Clear the Interrupt Flag To Start The Operation*/
    SET_BIT(TWCR,TWCR_TWINT);
    /*Wait on the Flag Until The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT));
    /*Check on the Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_SLAVE_TRANS_DATA_ACK)
    {
        local_ErrorStatus=SlaveWriteByteErr;
    }      
    return local_ErrorStatus;
}
/******************************************************************************************************************/
TWI_Error_Stat TWI_SlaveReadDataByte (u8* Copy_pu8DataByte)
{
    TWI_Error_Stat local_ErrorStatus=NoError;
    /*Clear the Flag to Start Recieving the SLA+R Request*/
    SET_BIT(TWCR,TWCR_TWINT);
    /*Wait on the Flag Until The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT));
    /*Check The Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_SLAVE_RCVD_SLA_W_REQ_ACK)
    {
        local_ErrorStatus=SlaveReadByteErr;
    }
    /*Clear the Flag to Start Recieving the Data*/
    SET_BIT(TWCR,TWCR_TWINT);        
    /*Wait on the Flag Until The Previous Operation Is Compelete*/
    while(!GET_BIT(TWCR,TWCR_TWINT));
    /*Check The Status*/
    if( (TWSR&TWI_STAT_MASK) != TWI_SLAVE_RCVD_DATA_ACK)
    {
        local_ErrorStatus=SlaveReadByteErr;
    }
    else
    {
        /*Read the Data*/
        *Copy_pu8DataByte=TWDR;
    }    
    return local_ErrorStatus;
}
/******************************************************************************************************************/
void TWI_SendStopCondition(void)
{
    /*generate Stop condition on the bus*/
    SET_BIT(TWCR,TWCR_TWSTO);
    /*Clear Flag To Make the Slave Send data*/
    SET_BIT(TWCR,TWCR_TWINT);
   
}
/******************************************************************************************************************/ 


#endif /*_TWI_PROGRAM_C_*/
