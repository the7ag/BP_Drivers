/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Ali Bayoumi
 * @brief          : Main program body
 ******************************************************************************
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

int main(void)
{
	MCAL_RCC_InitSysClock();
	MCAL_Rcc_EnablePrephiral(RCC_APB2_IOPAEN, RCC_APB2);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_MID_SPEED_PUSHPULL);
	MCAL_SYSTICK_vINIT();
    /* Loop forever */
	for(;;)
	{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
		MCAL_SYSTICK_DelayMS(1000);
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
		MCAL_SYSTICK_DelayMS(1000);
	}
}
