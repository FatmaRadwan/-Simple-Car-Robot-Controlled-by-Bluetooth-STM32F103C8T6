/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 8 August 2021                                                       */
/************************************************************************************/


#ifndef RCC_PRIVATE_H
#define RCC_RRIVATE_H

/* Register Definitions                  */
/* Base Address OF RCC is 0x4002 1000    */

#define RCC_CR          *((u32*)0x40021000)
#define RCC_CFGR        *((u32*)0x40021004)
#define RCC_CIR         *((u32*)0x40021008)
#define RCC_APB2RSTR    *((u32*)0x4002100C)
#define RCC_APB1RSTR    *((u32*)0x40021010)
#define RCC_AHBENR      *((u32*)0x40021014)
#define RCC_APB2ENR     *((u32*)0x40021018)
#define RCC_APB1ENR     *((u32*)0x4002101C)
#define RCC_BDCR        *((u32*)0x40021020)
#define RCC_CSR         *((u32*)0x40021024)

/* Clock  Types  */
#define   RCC_HSE_CRYSTAL  0
#define   RCC_HSE_RC       1
#define   RCC_HSI          2
#define   RCC_PLL          3   

/* RCC PLL Input */ 
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE        1
#define RCC_PLL_IN_HSE_DIV_2  2   

/* PLL Multiplication Factor  */
#define PLL_INPUT_CLOCK_2     0000
#define PLL_INPUT_CLOCK_3     0001
#define PLL_INPUT_CLOCK_4     0010
#define PLL_INPUT_CLOCK_5     0011
#define PLL_INPUT_CLOCK_6     0100
#define PLL_INPUT_CLOCK_7     0101
#define PLL_INPUT_CLOCK_8     0110
#define PLL_INPUT_CLOCK_9     0111
#define PLL_INPUT_CLOCK_10    1000
#define PLL_INPUT_CLOCK_11    1001
#define PLL_INPUT_CLOCK_12    1010
#define PLL_INPUT_CLOCK_13    1011
#define PLL_INPUT_CLOCK_14    1100
#define PLL_INPUT_CLOCK_15    1101
#define PLL_INPUT_CLOCK_16    1110


#endif
