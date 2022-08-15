#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/SYSTICK/SYSTIC_interface.h"
#include "Motor_interface.h"
#include "Motor_config.h"

void HMOTOR_voidMotorInit(void)
{

	MGPIO_voidGpioInit(GPIOA);
	MGPIO_voidGpioInit(GPIOB);
	MGPIO_voidGpioInit(GPIOC);
	/* Motor 1 */
	MGPIO_voidSetPinDirection(MOTOR_1_PORT , MOTOR_1_PIN_1,OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(MOTOR_1_PORT , MOTOR_1_PIN_2 ,OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(MOTOR_1_PWM_PORT , MOTOR_1_PWM_PIN,OUTPUT_SPEED_50MHZ_PP);
	/* MOTOR 2 */
	MGPIO_voidSetPinDirection(MOTOR_2_PORT , MOTOR_2_PIN_1,OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(MOTOR_2_PORT , MOTOR_2_PIN_2 ,OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(MOTOR_2_PWM_PORT , MOTOR_2_PWM_PIN,OUTPUT_SPEED_50MHZ_PP);
	/* MOTOR 3 */
	MGPIO_voidSetPinDirection(MOTOR_3_PORT , MOTOR_3_PIN_1,OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(MOTOR_3_PORT , MOTOR_3_PIN_2 ,OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(MOTOR_3_PWM_PORT , MOTOR_3_PWM_PIN,OUTPUT_SPEED_50MHZ_PP);
	/* MOTOR 4 */
	MGPIO_voidSetPinDirection(MOTOR_4_PORT , MOTOR_4_PIN_1,OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(MOTOR_4_PORT , MOTOR_4_PIN_2 ,OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(MOTOR_4_PWM_PORT , MOTOR_4_PWM_PIN,OUTPUT_SPEED_50MHZ_PP);

	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_1 , LOW);
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_2 , LOW);
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_1 , LOW);
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_2 , LOW);
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_1 , LOW);
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_2 , LOW);
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_1 , LOW);
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_2 , LOW);



}
void HMOTOR_voidForward(void)
{
	MGPIO_voidSetPinValue(MOTOR_1_PWM_PORT , MOTOR_1_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_1 ,HIGH );
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_2 ,LOW);

	MGPIO_voidSetPinValue(MOTOR_3_PWM_PORT , MOTOR_3_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_1 ,HIGH );
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_2 ,LOW);

	MGPIO_voidSetPinValue(MOTOR_2_PWM_PORT , MOTOR_2_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_1 ,HIGH);
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_2 ,LOW);

	MGPIO_voidSetPinValue(MOTOR_4_PWM_PORT , MOTOR_4_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_1 ,HIGH);
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_2 ,LOW);

}
void HMOTOR_voidTurnRight(void)
{

	MGPIO_voidSetPinValue(MOTOR_1_PWM_PORT , MOTOR_1_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_1 ,HIGH );
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_2 ,LOW);

	MGPIO_voidSetPinValue(MOTOR_3_PWM_PORT , MOTOR_3_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_1 ,HIGH );
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_2 ,LOW);


	MGPIO_voidSetPinValue(MOTOR_2_PWM_PORT , MOTOR_2_PWM_PIN , LOW) ;
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_1 ,HIGH);
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_2 ,HIGH);

	MGPIO_voidSetPinValue(MOTOR_4_PWM_PORT , MOTOR_4_PWM_PIN , LOW) ;
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_1 ,HIGH);
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_2 ,HIGH);


}
void HMOTOR_voidTurnLeft(void)
{
	MGPIO_voidSetPinValue(MOTOR_1_PWM_PORT , MOTOR_1_PWM_PIN , LOW) ;
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_1 ,LOW );
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_2 ,HIGH);
	MGPIO_voidSetPinValue(MOTOR_3_PWM_PORT , MOTOR_3_PWM_PIN , LOW) ;
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_1 ,HIGH );
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_2 ,HIGH);

	MGPIO_voidSetPinValue(MOTOR_2_PWM_PORT , MOTOR_2_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_1 ,HIGH);
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_2 ,LOW);

	MGPIO_voidSetPinValue(MOTOR_4_PWM_PORT , MOTOR_4_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_1 ,HIGH);
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_2 ,LOW);

}
void HMOTOR_voidBackward(void)
{
	MGPIO_voidSetPinValue(MOTOR_1_PWM_PORT , MOTOR_1_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_1 ,LOW );
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_2 ,HIGH);

	MGPIO_voidSetPinValue(MOTOR_3_PWM_PORT , MOTOR_3_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_1 ,LOW );
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_2 ,HIGH);

	MGPIO_voidSetPinValue(MOTOR_2_PWM_PORT , MOTOR_2_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_1 ,LOW);
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_2 ,HIGH);

	MGPIO_voidSetPinValue(MOTOR_4_PWM_PORT , MOTOR_4_PWM_PIN , HIGH) ;
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_1 ,LOW);
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_2 ,HIGH);



}
void HMOTOR_voidStop(void)
{
	MGPIO_voidSetPinValue(MOTOR_1_PWM_PORT , MOTOR_1_PWM_PIN , LOW) ;
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_1 ,LOW );
	MGPIO_voidSetPinValue(MOTOR_1_PORT , MOTOR_1_PIN_2 ,LOW);

	MGPIO_voidSetPinValue(MOTOR_3_PWM_PORT , MOTOR_3_PWM_PIN , LOW) ;
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_1 ,LOW );
	MGPIO_voidSetPinValue(MOTOR_3_PORT , MOTOR_3_PIN_2 ,LOW);

	MGPIO_voidSetPinValue(MOTOR_2_PWM_PORT , MOTOR_2_PWM_PIN , LOW) ;
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_1 ,LOW);
	MGPIO_voidSetPinValue(MOTOR_2_PORT , MOTOR_2_PIN_2 ,LOW);

	MGPIO_voidSetPinValue(MOTOR_4_PWM_PORT , MOTOR_4_PWM_PIN , LOW) ;
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_1 ,LOW);
	MGPIO_voidSetPinValue(MOTOR_4_PORT , MOTOR_4_PIN_2 ,LOW);

	}
void HMOTOR_voidSetMotorSpeed(u8 copy_u8MotorNum , u8 copy_u8MotorSpeed)
{
	u8 Local_u8low = 100 - copy_u8MotorSpeed;
		switch(copy_u8MotorNum)
		{
		case MOTOR_1 :
				MGPIO_voidSetPinValue(MOTOR_1_PWM_PORT,MOTOR_1_PWM_PIN,HIGH);
				MSTK_voidSetBusyWait(8*copy_u8MotorSpeed , DIRECT);
				MGPIO_voidSetPinValue(MOTOR_1_PWM_PORT,MOTOR_1_PWM_PIN,LOW);;
				MSTK_voidSetBusyWait(8*Local_u8low , DIRECT);
				break;

		case MOTOR_2 :
				MGPIO_voidSetPinValue(MOTOR_2_PWM_PORT,MOTOR_2_PWM_PIN,HIGH);
				MSTK_voidSetBusyWait(8*copy_u8MotorSpeed , DIRECT);
				MGPIO_voidSetPinValue(MOTOR_2_PWM_PORT,MOTOR_2_PWM_PIN,LOW);;
				MSTK_voidSetBusyWait(8*Local_u8low , DIRECT);
				break;

		case MOTOR_3 :
				MGPIO_voidSetPinValue(MOTOR_3_PWM_PORT,MOTOR_3_PWM_PIN,HIGH);
				MSTK_voidSetBusyWait(8*copy_u8MotorSpeed , DIRECT);
				MGPIO_voidSetPinValue(MOTOR_3_PWM_PORT,MOTOR_3_PWM_PIN,LOW);;
				MSTK_voidSetBusyWait(8*Local_u8low , DIRECT);
				break;

		case MOTOR_4 :
				MGPIO_voidSetPinValue(MOTOR_4_PWM_PORT,MOTOR_4_PWM_PIN,HIGH);
				MSTK_voidSetBusyWait(8*copy_u8MotorSpeed , DIRECT);
				MGPIO_voidSetPinValue(MOTOR_4_PWM_PORT,MOTOR_4_PWM_PIN,LOW);;
				MSTK_voidSetBusyWait(8*Local_u8low , DIRECT);
				break;
		}

}

