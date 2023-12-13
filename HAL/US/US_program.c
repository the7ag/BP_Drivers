/**
 * @file US_program.c
 * @brief This file contains the program for the US HAL drivers.
 *
 * @copyright Copyright (c) 2023
 * 
 * This driver library streamlines the integration and utilization of ultrasonic sensors,
 *  offering precise distance measurement capabilities in embedded systems with efficient handling of sensor data and configuration.
 *
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 13 dec 2023
 * @version V01
 * @author Mohamed Ali Bayoumi
 */
/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"
/**************************************** MCAL *****************************************************/
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
/**************************************** HAL *****************************************************/
#include "US_interface.h"
#include "US_private.h"
#include "US_config.h"
/**************************************** Global Var *****************************************************/
static volatile US_t Ultrasonic[NUMBER_OF_ULTRASONIC_USED];
static volatile f32 distance;
static volatile u8 echoRisingFlag,readingState;
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType Ultrasonic_init(Ultrasonic_ID_t ID, Ultrasonic_config_t * Ultrasonic_config)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    Ultrasonic[ID].Echo_pin=Ultrasonic_config->Echo_pin;
    Ultrasonic[ID].Echo_port=Ultrasonic_config->Echo_port;
    Ultrasonic[ID].Trig_pin=Ultrasonic_config->Trigger_pin;
    Ultrasonic[ID].Trig_port=Ultrasonic_config->Trigger_port;
    Ultrasonic[ID].DistanceRange=Ultrasonic_config->DistanceRange;
    Ultrasonic[ID].Timeout=(u32)((Ultrasonic[ID].DistanceRange*58.842)+.5);

    MCAL_Rcc_EnablePrephiral(Ultrasonic[ID].Echo_port,RCC_APB2);
    MCAL_Rcc_EnablePrephiral(Ultrasonic[ID].Trig_port,RCC_APB2);

    MCAL_Rcc_EnablePrephiral(RCC_APB2_AFIOEN,RCC_APB2);
    
    MCAL_GPIO_SetPinMode(Ultrasonic[ID].Echo_port ,Ultrasonic[ID].Echo_pin ,GPIO_INPUT_FLOATING_MODE);
    MCAL_GPIO_SetPinMode(Ultrasonic[ID].Trig_pin,Ultrasonic[ID].Trig_port,GPIO_OUTPUT_LOW_SPEED_PUSHPULL);

    MCAL_AFIO_SetEXTIConfigration((EXTI_LINE0 + Ultrasonic[ID].Echo_pin),Ultrasonic[ID].Echo_port);
    u8 EXTI_IRQ_NUM=EXTI_LINE0 + Ultrasonic[ID].Echo_pin;
    if(EXTI_IRQ_NUM ==0)
    {
        MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
    }else if (EXTI_IRQ_NUM ==1)
    {
        MCAL_NVIC_EnableIRQ(NVIC_EXTI1_IRQn);
    }else if (EXTI_IRQ_NUM ==2)
    {
        MCAL_NVIC_EnableIRQ(NVIC_EXTI2_IRQn);
    }else if (EXTI_IRQ_NUM ==3)
    {
        MCAL_NVIC_EnableIRQ(NVIC_EXTI3_IRQn);
    }else if (EXTI_IRQ_NUM ==4)
    {
        MCAL_NVIC_EnableIRQ(NVIC_EXTI4_IRQn);
    }else if (EXTI_IRQ_NUM>=5 && EXTI_IRQ_NUM <=9)
    {
        MCAL_NVIC_EnableIRQ(NVIC_EXTI9_5_IRQn);
    }else 
    {
        MCAL_NVIC_EnableIRQ(NVIC_EXTI15_10_IRQn);
    }

    MCAL_EXTI_SetCallback(Ultrasonic[ID].Echo_pin,CalcDistance);
    MCAL_EXTI_EnableLine(Ultrasonic[ID].Echo_pin);
    MCAL_EXTI_SetTrigger(Ultrasonic[ID].Echo_pin,EXTI_BOTH_EDGE);
    MCAL_SYSTICK_vINIT();
    Local_FunctionStatus=E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType Ultrasonic_readDistance(Ultrasonic_ID_t ID,f32* copy_US_reading)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if(Ultrasonic[ID].State == Ultrasonic_enable)
    {
        echoRisingFlag=RISING_DETECTED;
        readingState=READING_PENDING;
        MCAL_EXTI_EnableLine(Ultrasonic[ID].Echo_pin);
        MCAL_EXTI_SetTrigger(Ultrasonic[ID].Echo_pin,EXTI_BOTH_EDGE);
        MCAL_GPIO_SetPinValue(Ultrasonic[ID].Trig_port,Ultrasonic[ID].Trig_pin,GPIO_LOW);
        MCAL_SYSTICK_DelayMS(2);
        MCAL_GPIO_SetPinValue(Ultrasonic[ID].Trig_port,Ultrasonic[ID].Trig_pin,GPIO_HIGH);
        MCAL_SYSTICK_DelayMS(10);
        MCAL_GPIO_SetPinValue(Ultrasonic[ID].Trig_port,Ultrasonic[ID].Trig_pin,GPIO_LOW);
        while(readingState == READING_PENDING)
        {
            u32 local_Counts;
            MCAL_SYSTICK_GetElapsedCounts(&local_Counts);
            if(local_Counts>Ultrasonic[ID].Timeout)
            {
                MCAL_EXTI_DisableLine(Ultrasonic[ID].Echo_pin);
                readingState=READING_DONE;
                MCAL_SYSTICK_Stop();
                *copy_US_reading=OUT_OF_RANGE;
                break;
            }
        } return Local_FunctionStatus;
    }
    else
    {
        *copy_US_reading=(f32)ULTRASONIC_DISABLE;
        return Local_FunctionStatus;
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType Ultrasonic_setRange(Ultrasonic_ID_t ID, uint16 Range_cm)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    Ultrasonic[ID].DistanceRange=Range_cm;
    Ultrasonic[ID].Timeout=(u32)((Ultrasonic[ID].DistanceRange*58.842)+.5);
    Local_FunctionStatus=E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnTypeid Ultrasonic_setState(Ultrasonic_ID_t ID, Ultrasonic_state_t state)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    Ultrasonic[ID].state=state;
    Local_FunctionStatus=E_OK;
    return Local_FunctionStatus;
}
void CalcDistance()
{
    if(echoRisingFlag == RISING_DETECTED)
    {
        MCAL_SYSTICK_SetIntervalSingle(TIMER_PERIOD,NULL);
        echoRisingFlag=FALLING_DETECTED;
    }else
    {
        if (readingState != READING_DONE)
        {
            readingState=READING_DONE;
            MCAL_SYSTICK_GetElapsedCounts(&distance);
            distance*=.017; 
            MCAL_SYSTICK_Stop();
        }
        
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
