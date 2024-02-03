/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "RCC_interface.h"
#include "NVIC_interface.h"
/*APP*/


int main(void)
{
	/*Setup*/
	Mcal_RCC_InitSysClock();
	MCAL_NVIC_EnableIRQ(NVIC_SPI1_IRQn);
	MCAL_NVIC_xSetPriority(NVIC_SPI1_IRQn, 10);
	for(;;)
	{
	 /* Loop forever */
	MCAL_NVIC_EnableIRQ(NVIC_SPI1_IRQn);
	MCAL_NVIC_DisableIRQ(NVIC_SPI1_IRQn);
	}
}
