/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 8 August 2021                                                       */
/************************************************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0
#define RCC_APB1      1 
#define RCC_APB2      2

/*			RCC_AHBENR Pins 		*/
#define 	AHB_DMA1		0
#define 	AHB_DMA2		1
#define 	AHB_SRAM		2
#define 	AHB_FLITF		4
#define 	AHB_CRCEN		5
#define 	AHB_FSMCN		8
#define 	AHB_SDIO		10
/* 			RCC_APB2ENR Pins 		*/
#define 	APB2_AFIO		0
#define 	APB2_GPIOA		2
#define 	APB2_GPIOB		3
#define 	APB2_GPIOC		4
#define 	APB2_ADC1		9
#define 	APB2_ADC2		10
#define 	APB2_TIM1		11
#define 	APB2_SPI1		12
#define 	APB2_TIM8		13
#define 	APB2_USART1		14
#define 	APB2_ADC3		15
#define 	APB2_TIM9		19
#define 	APB2_TIM10		20
#define 	APB2_TIM11		21
/* 			RCC_APB1ENR Pins 		*/
#define 	APB1_TIM2		0
#define 	APB1_TIM3		1
#define 	APB1_TIM4		2
#define 	APB1_TIM5		3
#define 	APB1_TIM6		4
#define 	APB1_TIM7		5
#define 	APB1_TIM12		6
#define 	APB1_TIM13		7
#define 	APB1_TIM14		8
#define 	APB1_WWDG		11
#define 	APB1_SPI2		14
#define 	APB1_SPI3		15
#define 	APB1_USART2		17
#define 	APB1_USART3		18
#define 	APB1_USART4		19
#define 	APB1_USART5		20
#define 	APB1_I2C1		21
#define 	APB1_I2C2		22
#define 	APB1_USB		23
#define 	APB1_CAN		25


void RCC_voidInitSysClock (void);
void RCC_voidEnableClock  (u8 , u8 );
void RCC_voidDisableClock (u8 , u8 );





#endif
