
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

void HMOTOR_voidMotorInit(void) ;
void HMOTOR_voidForward(void);
void HMOTOR_voidTurnRight(void);
void HMOTOR_voidTurnLeft(void);
void HMOTOR_voidBackward(void);
void HMOTOR_voidStop(void);
void HMOTOR_voidSetMotorSpeed(u8 copy_u8MotorNum , u8 copy_u8MotorSpeed);



#define 		MOTOR_1			0
#define 		MOTOR_2			1
#define 		MOTOR_3			2
#define 		MOTOR_4			3

#endif
