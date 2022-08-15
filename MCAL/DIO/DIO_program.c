/************************************************************************************/
/* Author     : Fatma Mohamed Ahmed                                                 */
/* Version    : V01                                                                 */
/* Date       : 12 August 2021                                                      */
/* Description: GPIO Function Imp                                                   */
/************************************************************************************/

#include   "../../LIB/STD_TYPES.h"
#include   "../../LIB/BIT_MATH.h"

#include "../RCC/RCC_interface.h"
#include   "DIO_interface.h"
#include   "DIO_private.h"
#include   "DIO_config.h"

void MGPIO_voidGpioInit(u8 copy_u8Port)
{
	switch(copy_u8Port)
	{
	case GPIOA :
					RCC_voidEnableClock(RCC_APB2,APB2_GPIOA); break ;
	case GPIOB:
					RCC_voidEnableClock(RCC_APB2,APB2_GPIOB); break ;
	case GPIOC:
					RCC_voidEnableClock(RCC_APB2,APB2_GPIOC); break ;
	}
}
void MGPIO_voidSetHalfPortDirection (u8 copy_u8Port ,u8 copy_u8PortMode , u8 copy_u8Mode) 
{
	switch(copy_u8Port )
	{
	case GPIOA :
				if (copy_u8PortMode == LOW_HALF)
				{
					for ( u8 indx = 0 ; indx <=7 ; indx ++ )
					{
						GPIOA_CRL &=  ~((0b111)       << (indx * 4));
						GPIOA_CRL |=   ((copy_u8Mode) << (indx * 4));
					}
					
				}
				else if (copy_u8PortMode == HIGH_HALF)
				{
					for ( u8 indx = 0 ; indx <=7 ; indx ++ )
					{
						GPIOA_CRH &=  ~((0b111)       << (indx * 4));
						GPIOA_CRH |=   ((copy_u8Mode) << (indx * 4));
					}
					
				}
				break ;
	case GPIOB:
				if (copy_u8PortMode == LOW_HALF)
				{
					for ( u8 indx = 0 ; indx <=7 ; indx ++ )
					{
						GPIOB_CRL &=  ~((0b111)       << (indx * 4));
						GPIOB_CRL |=   ((copy_u8Mode) << (indx * 4));
					}

				}
				else if (copy_u8PortMode == HIGH_HALF)
				{
					for ( u8 indx = 0 ; indx <=7 ; indx ++ )
					{
						GPIOB_CRH &=  ~((0b111)       << (indx * 4));
						GPIOB_CRH |=   ((copy_u8Mode) << (indx * 4));
					}

				}
				break ;
	case GPIOC:
				if (copy_u8PortMode == LOW_HALF)
				{
					for ( u8 indx = 0 ; indx <=7 ; indx ++ )
					{
						GPIOC_CRL &=  ~((0b111)       << (indx * 4));
						GPIOC_CRL |=   ((copy_u8Mode) << (indx * 4));
					}

				}
				else if (copy_u8PortMode == HIGH_HALF)
				{
					for ( u8 indx = 0 ; indx <=7 ; indx ++ )
					{
						GPIOC_CRH &=  ~((0b111)       << (indx * 4));
						GPIOC_CRH |=   ((copy_u8Mode) << (indx * 4));
					}

				}
				break ;

	default : 	break ;
				
	
	}
}

void MGPIO_voidSetHalfPortValue (u8 copy_u8Port ,u8 copy_u8PortMode , u8 copy_u8Value)
{
	switch (copy_u8Port)
	{
		case GPIOA :
					if (copy_u8PortMode == LOW_HALF)
					{
						if (copy_u8Value == HIGH)
						GPIOA_ODR |= (0x000000FF);
						else if (copy_u8Value == LOW)
						GPIOA_ODR &= ~(0x000000FF);
					}
					else if  (copy_u8PortMode == HIGH_HALF)
					{
						if (copy_u8Value == HIGH)
						GPIOA_ODR |= (0x0000FF00);
						else if (copy_u8Value == LOW)
						GPIOA_ODR &= ~(0x0000FF00);
					}
					break ;
	}
}

void MGPIO_voidSetPinDirection (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode) {

	switch(copy_u8Port )
	{
	case GPIOA :
				if (copy_u8Pin <= 7) {
					GPIOA_CRL &=  ~((0b111)       << (copy_u8Pin * 4));
					GPIOA_CRL |=   ((copy_u8Mode) << (copy_u8Pin * 4));
				}
				else if  (copy_u8Pin <= 15) 
				{
		
					copy_u8Pin = copy_u8Pin - 8 ;
					GPIOA_CRH &=  ~((0b111)       << (copy_u8Pin * 4));
					GPIOA_CRH |=   ((copy_u8Mode) << (copy_u8Pin * 4));
		
				}
				break ;
	case GPIOB :
				if (copy_u8Pin <= 7) 
				{
					GPIOB_CRL &=  ~((0b111)       << (copy_u8Pin * 4));
					GPIOB_CRL |=   ((copy_u8Mode) << (copy_u8Pin * 4));
				}
				else if  (copy_u8Pin <= 15)
				{

					copy_u8Pin = copy_u8Pin - 8 ;
					GPIOB_CRH &=  ~((0b111)       << (copy_u8Pin * 4));
					GPIOB_CRH |=   ((copy_u8Mode) << (copy_u8Pin * 4));

				}
				break ;
	case GPIOC :
		if (copy_u8Pin <= 7) {
					GPIOC_CRL &=  ~((0b111)       << (copy_u8Pin * 4));
					GPIOC_CRL |=   ((copy_u8Mode) << (copy_u8Pin * 4));
				}
					else if  (copy_u8Pin <= 15) {

					copy_u8Pin = copy_u8Pin - 8 ;
					GPIOC_CRH &=  ~((0b111)       << (copy_u8Pin * 4));
					GPIOC_CRH |=   ((copy_u8Mode) << (copy_u8Pin * 4));

								}
				break ;
	default :   break ;

	}



}

void MGPIO_voidSetPinValue (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value){
	switch(copy_u8Port ) 
	{

	case GPIOA :
				if (copy_u8Value == HIGH)
					SET_BIT(GPIOA_ODR  , copy_u8Pin ) ;
				else if (copy_u8Value == LOW)
					CLR_BIT(GPIOA_ODR ,copy_u8Pin );
				break ;
	case GPIOB :
				if (copy_u8Value == HIGH)
					SET_BIT(GPIOB_ODR  , copy_u8Pin ) ;
				else if (copy_u8Value == LOW)
					CLR_BIT(GPIOB_ODR ,copy_u8Pin );
				break ;
	case GPIOC :
				if (copy_u8Value == HIGH)
					SET_BIT(GPIOC_ODR  , copy_u8Pin ) ;
				else if (copy_u8Value == LOW)
					CLR_BIT	(GPIOC_ODR ,copy_u8Pin );
				break ;
	default :  break ;
	}


}

u8 MGPIO_voidGetPinValue (u8 copy_u8Port , u8 copy_u8Pin ){

	 u8 LocGetValue = 0;

	switch(copy_u8Port ) {

	case GPIOA :
					LocGetValue =  GET_BIT (GPIOA_IDR , copy_u8Pin) ;
					break ;
	case GPIOB :
					LocGetValue	=  GET_BIT (GPIOB_IDR , copy_u8Pin) ;
					break ;
	case GPIOC :
					LocGetValue =  GET_BIT (GPIOC_IDR , copy_u8Pin) ;
					break ;
    default :  		break ;

	}

	return LocGetValue ;

}

void MGPIO_voidTogglePin(u8 copy_u8Port , u8 copy_u8Pin)
{
	switch(copy_u8Port ) {

	case GPIOA :
					TOG_BIT (GPIOA_ODR , copy_u8Pin ) ;
					break ;
	case GPIOB :	
					TOG_BIT (GPIOB_ODR , copy_u8Pin ) ;
					break ; 
	case GPIOC :	
					TOG_BIT (GPIOC_ODR , copy_u8Pin ) ;
					break ;
	default    :    break ;
	}
	
}
