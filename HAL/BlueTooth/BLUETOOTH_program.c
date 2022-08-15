/*
 * BLUETOOTH_program.c
 *
 *      Author: Fatma Mohamed Ahmed
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/UART/UART_interface.h"
#include "../../MCAL/RCC/RCC_interface.h"
#include "BLUETOOTH_interface.h"
#include "BLUETOOTH_config.h"
void HBLUETOOTH_voidBluetoothInit(void)
{

	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);
	RCC_voidEnableClock(RCC_APB2,4);

	//MGPIO_voidSetPinDirection(BLUETOOTH_EN_PORT , BLUETOOTH_EN_PIN,OUTPUT_SPEED_10MHZ_PP);
	//MGPIO_voidSetPinValue(BLUETOOTH_EN_PORT , BLUETOOTH_EN_PIN,HIGH);
}
u8 HBLUETOOTH_voidBluetoothReceive(void)
{
	u8 local_u8Data ;
	USART1_u8ReceiveNoBlock(&local_u8Data);
	return local_u8Data;
}




