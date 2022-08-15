#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/SYSTICK/SYSTIC_interface.h"
#include "HAL/Motor_interface.h"
#include "HAL/BlueTooth/BLUETOOTH_interface.h"


void main (void)
{

	RCC_voidInitSysClock ();
	MSTK_voidInit();

	HMOTOR_voidMotorInit();
	HBLUETOOTH_voidBluetoothInit();
	RCC_voidEnableClock(RCC_APB2 , APB2_USART1);
	/* A9 TX */
	MGPIO_voidSetPinDirection(GPIOA , PIN9 , OUTPUT_SPEED_50MHZ_PP);
	/* A10 Rx  */
	MGPIO_voidSetPinDirection(GPIOA , PIN10 , INPUT_FLOATING);
	USART1_voidInit();

	/* Buzzer */
	MGPIO_voidSetPinDirection(GPIOC , PIN13 , OUTPUT_SPEED_10MHZ_PP);

		u8 local_u8Data ;
	while (1)
	{

		USART1_u8ReceiveNoBlock(&local_u8Data);
	if (local_u8Data == 'f'  )
	{
			MGPIO_voidSetPinValue(GPIOC , PIN13 , HIGH);
			HMOTOR_voidForward();
			MSTK_voidSetBusyWait(3000 , MILLISECOND);
			HMOTOR_voidStop();
			MGPIO_voidSetPinValue(GPIOC  , PIN13 , LOW);
	}

	else if (local_u8Data == 'b' )
	{
		MGPIO_voidSetPinValue(GPIOC , PIN13 , HIGH);
		HMOTOR_voidBackward();
		MSTK_voidSetBusyWait(3000 , MILLISECOND);
		HMOTOR_voidStop();
		MGPIO_voidSetPinValue(GPIOC  , PIN13 , LOW);
	}
	else if (local_u8Data == 'l' )
	{
		MGPIO_voidSetPinValue(GPIOC , PIN13 , HIGH);
		HMOTOR_voidTurnRight();
		MSTK_voidSetBusyWait(1000 , MILLISECOND);
		HMOTOR_voidStop();
		MGPIO_voidSetPinValue(GPIOC  , PIN13 , LOW);

	}
	else if (local_u8Data == 'r' )
	{
		MGPIO_voidSetPinValue(GPIOC , PIN13 , HIGH);
		HMOTOR_voidTurnLeft();
		MSTK_voidSetBusyWait(1000 , MILLISECOND);
		HMOTOR_voidStop();
		MGPIO_voidSetPinValue(GPIOC  , PIN13 , LOW);

	}
	else if (local_u8Data == 'n')
	{
		HMOTOR_voidStop();
	}

	}

}
