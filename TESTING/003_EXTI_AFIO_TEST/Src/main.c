/*
 * Author 	: Mohamed Ali Bayoumi
 * Date 	: 27/OCT/20223
 *  File 	: Main.c
 * */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

void interruptRequest(void);
int main(void)
{
	/*RCC*/
	MCAL_RCC_InitSysClock();
	/*Enable AFIO*/
	MCAL_Rcc_EnablePrephiral(RCC_APB2_AFIOEN, RCC_APB2);
	/*Enable Port A*/
	MCAL_Rcc_EnablePrephiral(RCC_APB2_IOPAEN, RCC_APB2);
	/*Enable the PIN*/
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT_PULL_DOWN_MODE);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_MID_SPEED_PUSHPULL);
	/*Enable  EXTI0 From NVIC */
	MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	/*Enable GPIO from AFIO*/
	MCAL_AFIO_SetEXTIConfigration(AFIO_EXTI0, AFIO_GPIOA);
	/*EXTI0 Set Trigger Sensitive to Rising Edge*/
	MCAL_EXTI_SetTrigger(EXTI_LINE0, EXTI_RISING_EDGE);
	/*Enable EXTI0 From EXTI*/
	MCAL_EXTI_EnableLine(EXTI_LINE0);
	MCAL_EXTI_SetCallback(EXTI_LINE0, interruptRequest);
    /* Loop forever */
	for(;;);
}
void interruptRequest(void)
{
	static u8 Local_Temp=0;
	if(Local_Temp ==0)
	{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
		Local_Temp=1;
	}else
	{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
		Local_Temp=0;
	}
}
