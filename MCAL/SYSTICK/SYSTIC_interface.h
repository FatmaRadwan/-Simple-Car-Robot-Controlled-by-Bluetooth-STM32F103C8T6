/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 26 August 2021                                                      */
/************************************************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H 

/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable Systick                          */
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks , u8 Copy_u8TimeMode);
void MSTK_voidSetIntervalSingle  ( u8 Copy_u8TimeMode , u32 Copy_u32Ticks, void (*Copy_ptr)(void) ) ;
void MSTK_voidSetIntervalPeriodic( u8 Copy_u8TimeMode , u32 Copy_u32Ticks, void (*Copy_ptr)(void) ) ;
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#define   MILLISECOND   0
#define   MICROSECOND   1 
#define   DIRECT 	    2


#endif 
