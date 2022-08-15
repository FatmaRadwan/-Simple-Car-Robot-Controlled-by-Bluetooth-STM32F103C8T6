/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 26 August 2021                                                      */
/************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SYSTIC_interface.h"
#include "SYSTIC_private.h"
#include "SYSTIC_config.h"

/* Global Pointer To Function */
static void (*callBack) (void) ;

/* Global Varibale that store The Mode Of interval */
static u8 MSTK_u8ModeOfInterval ;

/* Initialze of STK Function */
void MSTK_voidInit(void) {
#if STK_CLOCK_SOURCE   == AHB_DIV_8_CLOCK
	SYS_TICK -> CTRL = 0x00000000;  // Choose AHB/8 As A clock Source
#elif STK_CLOCK_SOURCE == AHB_CLOCK
	SYS_TICK -> CTRL = 0x00000004;  // Choose AHB As A clock Source
#endif
}
/* Set Delay */
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks , u8 Copy_u8TimeMode){
	
		switch (Copy_u8TimeMode){
		case MILLISECOND : Copy_u32Ticks = Copy_u32Ticks * 1000 ; break ;
		case MICROSECOND : Copy_u32Ticks = Copy_u32Ticks * 100  ; break ;
		default          : break ; }
		
		/* Store Ticks in Load Register */
		SYS_TICK -> LOAD = Copy_u32Ticks ; 
		
		/* Enable STK  */
		SET_BIT(SYS_TICK -> CTRL,0);
		
		/*Wait The COUNTFLAG until Reach to 0 Count , and return 1 */
		while ((GET_BIT(SYS_TICK -> CTRL , 16) ) == 0) asm("NOP") ;
		
		/* Stop STK */
		CLR_BIT(SYS_TICK -> CTRL ,0 );
		
		/*Empty CTRL And VAL Register */
		SYS_TICK -> LOAD = 0 ;
		SYS_TICK -> VAL = 0 ;		
}
void MSTK_voidSetIntervalSingle  ( u8 Copy_u8TimeMode , u32 Copy_u32Ticks, void (*Copy_ptr)(void) ) {

		CLR_BIT(SYS_TICK -> CTRL , 0) ;
		SYS_TICK -> VAL = 0 ;
		switch (Copy_u8TimeMode)
			{
			case MILLISECOND : Copy_u32Ticks = Copy_u32Ticks * 1000 ; break ;
			case MICROSECOND : Copy_u32Ticks = Copy_u32Ticks * 100  ; break ;
			default          : break ; 
			}
		
		/* Store Ticks in Load Register */	
		SYS_TICK -> LOAD = Copy_u32Ticks ;
		
		/* Enable STK  */
		SET_BIT(SYS_TICK -> CTRL,0);
		
		/* Store The Pointer Address in CallBack Pointer */
		callBack = Copy_ptr ;
		
		/* Store The Mode Of interval */
		MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL ;
		
		/* Enable Interrupt */
		SET_BIT(SYS_TICK -> CTRL,1);
}
void MSTK_voidSetIntervalPeriodic( u8 Copy_u8TimeMode , u32 Copy_u32Ticks, void (*Copy_ptr)(void) ) {
			
		switch (Copy_u8TimeMode)
			{
			case MILLISECOND : Copy_u32Ticks = Copy_u32Ticks * 1000 ; break ;
			case MICROSECOND : Copy_u32Ticks = Copy_u32Ticks * 100  ; break ;
			case DIRECT		 : 		break ;
			default          : break ; 
			}
		
		/* Store Ticks in Load Register */	
		SYS_TICK -> LOAD = Copy_u32Ticks ;
		
		/* Enable STK  */
		SET_BIT(SYS_TICK -> CTRL,0);
		
		/* Store The Pointer Address in CallBack Pointer */
		callBack = Copy_ptr ;
		
		/* Store The Mode Of interval */
		MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL ;
		
		/* Enable Interrupt */
		SET_BIT(SYS_TICK -> CTRL,1);
}

void MSTK_voidStopInterval(void) {
		/* Disable Interrupt and STK  */
		CLR_BIT(SYS_TICK -> CTRL , 0) ;
		CLR_BIT(SYS_TICK -> CTRL , 1) ;
		
		/*Empty CTRL And VAL Register */
		SYS_TICK -> LOAD = 0 ;
		SYS_TICK -> VAL = 0 ;		
}

u32  MSTK_u32GetElapsedTime(void) {
	
		volatile u32 Local_u32ElabsedTime ;
		Local_u32ElabsedTime = ( (SYS_TICK -> LOAD ) - ( SYS_TICK -> VAL)) ;
		return  Local_u32ElabsedTime ;

}
u32  MSTK_u32GetRemainingTime(void) {
		return (SYS_TICK -> VAL) ;
}
void SysTick_Handler (void) {
    u8 Local_u8Temprary ;
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL ) {
		/* Disable Interrupt and STK  */
		CLR_BIT(SYS_TICK -> CTRL , 0) ;
		CLR_BIT(SYS_TICK -> CTRL , 1) ;
				/*Empty CTRL And VAL Register */
		SYS_TICK -> LOAD = 0 ;
		SYS_TICK -> VAL = 0 ;	
	}
	callBack();
	
	/* Clear Interrupt Flag By reading it */
	Local_u8Temprary = GET_BIT(SYS_TICK -> CTRL , 16) ;
	}


