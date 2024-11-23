 /*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SPI_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:SPI 
*
*/

#ifndef  _SPI_INTERFACE_H_
#define  _SPI_INTERFACE_H_

#define SPI_SLAVE   0 
#define SPI_MASTER  1


void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
void SPI_voidEnable(void);
void SPI_voidDisable(void);
void SPI_voidEnableInterrupt(void);
void SPI_voidDisableInterrupt(void);
u8 SPI_u8Tranceive (u8 Copy_u8TData , u8 * Copy_u8RData);
u8 SPI_u8SetCallBack(void (*Copy_pvoidCallBack)(void));
u8 SPI_u8SetMasterOrSlave(u8 Copy_u8config );
#endif
