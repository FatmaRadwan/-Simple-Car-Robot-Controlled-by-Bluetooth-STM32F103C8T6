/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 8 August 2021                                                       */
/************************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* 
 Options :
 RCC_HSE_CRYSTAL
 RCC_HSE_RC
 RCC_HSI
 RCC_PLL                 
 */
#define RCC_CLOCK_TYPE      RCC_HSE_CRYSTAL
/* 
   Options :   
 RCC_PLL_IN_HSI_DIV_2
 RCC_PLL_IN_HSE
 RCC_PLL_IN_HSE_DIV_2           
 */	
 #if RCC_CLOCK_TYPE == RCC_PLL
 
 #define RCC_PLL_INPUT     RCC_PLL_IN_HSE_DIV_2
 
 #endif
 
 /* Options :
  PLL input clock x 2
  PLL input clock x 3
  PLL input clock x 4
  PLL input clock x 5
  PLL input clock x 6
  PLL input clock x 7
  PLL input clock x 8
  PLL input clock x 9
  PLL input clock x 10
  PLL input clock x 11
  PLL input clock x 12
  PLL input clock x 13
  PLL input clock x 14
  PLL input clock x 15
  PLL input clock x 16
  PLL input clock x 16  */

 #if RCC_CLOCK_TYPE== RCC_PLL

 #define RCC_PLL_MUL_VAL  PLL_INPUT_CLOCK_4

 #endif
		



#endif
