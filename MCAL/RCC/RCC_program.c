/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 8 August 2021                                                       */
/************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock (void) {
	
	#if    RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CR   = 0x00010000 ;   // Enable HSE Crystal
	RCC_CFGR = 0x00000001 ;   // make HSE As Input Clock To the System

#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR = 0x00050000  ;    // Enable HSE RC
	RCC_CFGR = 0x00000001 ;   // make HSE As Input Clock To the System

  /***************************************************************************************************************/
	#elif  RCC_CLOCK_TYPE == RCC_HSI
	RCC_CR   = 0x00000081  ;  // enable HSI
	RCC_CFGR = 0x00000000  ;  // make HSI As Input Clock To the System

   /**************************************************************************************************************/
	#elif  RCC_CLOCK_TYPE == RCC_PLL

    #if RCC_PLL_INPUT  == RCC_PLL_IN_HSE
	RCC_CR   = 0x01010000 ;    // Enable PLL with HSE
	RCC_CFGR = 0x00000000 ;
    #elif RCC_PLL_INPUT  == RCC_PLL_IN_HSE_DIV_2
	RCC_CR   = 0x01010000 ;  // enable HSE with PLL
	RCC_CFGR = 0x00000000 ;
	RCC_CFGR = (RCC_PLL_MUL_VAl << 18) + 0x00030002 ;   // Choose PLL clock to get out to The System multiply by factor

    #elif RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	RCC_CR   = 0x01000081 ;    // Enable PLL and HSI
	RCC_CFGR   = 0x00000000 ;
	RCC_CFGR = (RCC_PLL_MUL_VAl << 18) + 0x00000002 ;  // Choose PLL clock to get out to The System multiply by factor

    #endif

	
	#else
		#error ("You Choosed Wrong Clock Type")
	#endif
	
}

void RCC_voidEnableClock (u8 Copy_u8BusId , u8 Copy_u8PerId ) {
	
	
	if (Copy_u8PerId <= 31  ) {
		
		switch (Copy_u8BusId )
		{
			case RCC_AHB  :  SET_BIT(RCC_AHBENR   , Copy_u8PerId )  ;   break ;
			case RCC_APB1 :  SET_BIT(RCC_APB1ENR  , Copy_u8PerId )  ;   break ;
			case RCC_APB2 :  SET_BIT(RCC_APB2ENR  , Copy_u8PerId )  ;   break ;
			default       : /* Return Error */                          break ;
			
			
		}
	}
	else {
		/* Return Error */
		
	}
	
}
void RCC_voidDisableClock (u8 Copy_u8BusId , u8 Copy_u8PerId ) {
	
	if (Copy_u8PerId <= 31 )  {
		
		switch (Copy_u8BusId )
		{
			case RCC_AHB  :  CLR_BIT(RCC_AHBENR   , Copy_u8PerId );   break ;
			case RCC_APB1 :  CLR_BIT(RCC_APB1ENR  , Copy_u8PerId );   break ;
			case RCC_APB2 :  CLR_BIT(RCC_APB2ENR  , Copy_u8PerId );   break ;
			default       : /* Return Error */                        break ;
			
			
		}
	}
	else {
		/* Return Error */
		
	}
	
}
