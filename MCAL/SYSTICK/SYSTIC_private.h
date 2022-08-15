/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 26 August 2021                                                      */
/************************************************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H 

/* Define Struct Containes STK Register */
typedef struct {
	
	u32 CTRL  ; 
	u32 LOAD  ;
	u32 VAL   ; 
	u32 CALIB ;
	
} SYS_TICK_t ;

/* Define Pointer To Struct */
#define   SYS_TICK     ((SYS_TICK_t*)0xE000E010)  // pointer to Struct

/* Clock Source */
#define    AHB_CLOCK            1
#define    AHB_DIV_8_CLOCK      0

/* Mode Of Interval */
#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1

#endif 
