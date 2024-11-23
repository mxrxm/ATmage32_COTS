 /*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  TWI_private.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:MCAL
*   SWC:TWI 
*
*/
#ifndef  _TWI_PRIVATE_H_
#define  _TWI_PRIVATE_H_

/*States*/

#define TWI_START_ACK                   0x08       /* start has been sent */
#define TWI_RE_START_ACK                0x10       /* repeated start */
#define TWI_STOP                        0xA0       /*Stop caondition*/ 
#define TWI_ARB_LOST                    0x38       /*Arbitration lost in SLA+W or data bytes*/

#define TWI_MSTR_TRANS_SLA_W_ACK        0x18       /* Master transmit ( slave address + Write request ) ACK */
#define TWI_MSTR_TRANS_SLA_W_NACK       0x20       /* Master transmit ( slave address + Write request ) NACK */
#define TWI_MSTR_TRANS_DATA_ACK         0x28       /* Master transmit data ACK */
#define TWI_MSTR_TRANS_DATA_NACK        0x30       /* Master transmit data NACK */
#define TWI_MSTR_TRANS_SLA_R_ACK        0x40       /* Master transmit ( slave address + Read request ) ACK */
#define TWI_MSTR_TRANS_SLA_R_NACK       0x48       /* Master transmit ( slave address + Read request ) NACK */

#define TWI_MSTR_RCVD_DATA_ACK          0x50        /* Master received data and returned ACK */
#define TWI_MSTR_RCVD_DATA_NACK         0x58        /* Master received data and returned NACK */

#define TWI_SLAVE_RCVD_SLA_R_REQ_ACK    0xA8        /*  slave address is received with read request and returned ACK */
#define TWI_SLAVE_RCVD_SLA_W_REQ_ACK    0x60        /* slave address is received with write request returned ACK*/
#define TWI_SLAVE_RCVD_GEN_CALL_REQ_ACK 0x70        /*General call address has been received and returned ACK */
#define TWI_SLAVE_RCVD_DATA_ACK         0x80        /* Slave received data and returned ACK */
#define TWI_SLAVE_RCVD_DATA_NACK        0x88        /* Slave received data and returned NACK */


#define  TWI_SLAVE_TRANS_DATA_ACK       0xB8        /*Slave has transmitted Data byte and received ACK */
#define  TWI_SLAVE_TRANS_DATA_NACK      0xC0        /*Slave has transmitted Data byte and received NACK */

 
/* Prescalers */
#define TWI_NO_PRESCALE     1
#define TWI_4_PRESCALE      4
#define TWI_16_PRESCALE     16
#define TWI_64_PRESCALE     64

#define TWI_STAT_MASK       0b11111000
#endif
