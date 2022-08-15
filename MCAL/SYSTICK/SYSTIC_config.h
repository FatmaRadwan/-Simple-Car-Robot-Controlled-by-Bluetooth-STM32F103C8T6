/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 26 August 2021                                                      */
/************************************************************************************/
#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H 

/*OPTIONS
* 0 // Don't Use Interrupt 
* 1 // Use Interrupt 
*/
#define STK_INT       1

/* OPTIONS 
 * AHB_CLOCK
   AHB_DIV_8_CLOCK
*/ 
#define STK_CLOCK_SOURCE    AHB_DIV_8_CLOCK
#endif 
