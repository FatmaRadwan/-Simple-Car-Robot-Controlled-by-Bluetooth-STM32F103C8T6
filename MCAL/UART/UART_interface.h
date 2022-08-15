/*********************************************************************************************/
/*  Author   :    Fatma Mohamed Ahmed                                                        */
/*  Date     :    16/10/2021                                                                 */
/*********************************************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H




void USART1_voidInit(void);
void USART1_voidTransmit(u8 data[]);
u8   USART1_u8ReceiveTimeOut(u32 Copy_u32TimeOut);
u8   USART1_u8ReceiveNoBlock(u8* Copy_u8Data);
#endif
