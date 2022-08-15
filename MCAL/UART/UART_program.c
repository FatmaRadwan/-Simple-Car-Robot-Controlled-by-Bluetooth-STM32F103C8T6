/*********************************************************************************************/
/*  Author   :    Fatma Mohamed Ahmed                                                        */
/*  Date     :    16/10/2021                                                                 */
/*********************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"



void USART1_voidInit(void)
{
	
	#if   BAUD_RATE  ==  BAUD_RATE_9600_8MHZ
	USART1 -> BRR = 0x341;
	#elif BAUD_RATE  ==  BAUD_RATE_115200_8MHZ
	USART1 -> BRR = 0x45;
	#endif
	
	
	SET_BIT(USART1 -> CR1 , 2);     /* Enable Receiver */
	SET_BIT(USART1 -> CR1 , 3);     /* Enable Transmitter */
	SET_BIT(USART1 -> CR1 , 13);    /* Enable USART */
	
	USART1 -> SR = 0;              /* clear status register */

}
void USART1_voidTransmit(u8 data[])
{
	u8 i= 0;
	while(data[i] !='\0')
	{
		USART1 -> DR = data[i];
		while( GET_BIT(USART1 -> SR , TC) == 0 );
		i++;
	}
}
u8 USART1_u8ReceiveTimeOut(u32 Copy_u32TimeOut)
{
	u16 timeout = 0;
	u8 Local_u8ReceiveData=0;
	while( GET_BIT(USART1 -> SR , RXNE) == 0 )
	{
		timeout++;
		if(timeout == Copy_u32TimeOut)
		{
			Local_u8ReceiveData = 255;
			break;
		}
	
	}
	if(Local_u8ReceiveData == 0)
	{
		Local_u8ReceiveData = USART1 -> DR;
	}
	return Local_u8ReceiveData;
}

u8 USART1_u8ReceiveNoBlock(u8* Copy_u8Data)
{
	u8 Local_u8Result = 1;
	if(GET_BIT(USART1->SR , RXNE) == 1)
	{
		*Copy_u8Data = USART1 -> DR;
	}
	else
	{
		Local_u8Result = 0;
	}
	
	return Local_u8Result;
  	
}
