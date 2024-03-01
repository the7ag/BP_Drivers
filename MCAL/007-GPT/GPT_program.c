/**
 * @file GPT_program.c
 * @brief This file contains the private interface for the GPT module.
 *
 * @copyright Copyright (c) 2023
 * 
 * This module provides low-level functions for configuring and controlling the general purpose timers in the ARM Cortex-M processor.
 * The general purpose timers can be used for various timing and synchronization purposes in embedded systems.
 *
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 28 NOV 2023
 * @version V01
 * @author Mohamed Ali Bayoumi
 */

/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"
/**************************************** MCAL *****************************************************/
#include "RCC_interface.h"
#include "GPT_interface.h"
#include "GPT_private.h"
#include "GPT_config.h"
// Represents the ratio between microseconds and timer ticks
static volatile f32 microSecToTickRatio=0;
// Interval mode flags for different GPT timers (initialized to 0)
static volatile u8 GPT_TIM1_IntervalMode=0;
static volatile u8 GPT_TIM2_IntervalMode=0;
static volatile u8 GPT_TIM3_IntervalMode=0;
static volatile u8 GPT_TIM4_IntervalMode=0;

// Macro to set the interval mode for GPT Timer 1
#define GPT_TIM1_SetIntervalMode(MODE) GPT_TIM1_IntervalMode = MODE

// Macro to set the interval mode for GPT Timer 2
#define GPT_TIM2_SetIntervalMode(MODE) GPT_TIM2_IntervalMode = MODE

// Macro to set the interval mode for GPT Timer 3
#define GPT_TIM3_SetIntervalMode(MODE) GPT_TIM3_IntervalMode = MODE

// Macro to set the interval mode for GPT Timer 4
#define GPT_TIM4_SetIntervalMode(MODE) GPT_TIM4_IntervalMode = MODE

// Macro to get the interval mode for GPT Timer 1
#define GPT_TIM1_GetIntervalMode() (GPT_TIM1_IntervalMode & 1)

// Macro to get the interval mode for GPT Timer 2
#define GPT_TIM2_GetIntervalMode() (GPT_TIM2_IntervalMode & 1)

// Macro to get the interval mode for GPT Timer 3
#define GPT_TIM3_GetIntervalMode() (GPT_TIM3_IntervalMode & 1)

// Macro to get the interval mode for GPT Timer 4
#define GPT_TIM4_GetIntervalMode() (GPT_TIM4_IntervalMode & 1)

// Function pointers to callback functions for different GPT timers
static void (*TIM1_CallBack)(void);
static void (*TIM2_CallBack)(void);
static void (*TIM3_CallBack)(void);
static void (*TIM4_CallBack)(void);
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_init(u8 Copy_TIMx,GPT_Config_t* Copy_GPT_Config)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    GPT_TIMx_SetPeriod(Copy_TIMx,Copy_GPT_Config->ARR);
    #if TIM_Ratio == MilliSeconds
        u16 Local_Prescalar = (u16)(TIM_Clk_Freq / 1000000)-1;
        GPT_TIMx_SetPreScalar(Copy_TIMx , Local_Prescalar);
    #elif TIM_Ratio == Seconds
        u16 Local_Prescalar = (u16)(TIM_Clk_Freq / 1000)-1;
        GPT_TIMx_SetPreScalar(Copy_TIMx , Local_Prescalar);
    #else
        #error "Wrong Tim Period"
        local_functionStates = E_NOT_OK;
        return local_functionStates;
    #endif
    GPT_TIMx_SetARRBuffer(Copy_TIMx , Copy_GPT_Config->ARB);
    GPT_TIMx_SetCountDIR(Copy_TIMx , Copy_GPT_Config->GPT_DIR);
    GPT_TIMx_PWM_SetAllignmentMode(Copy_TIMx , Copy_GPT_Config->AllignMode);
    GPT_TIMx_SetClkDiv(Copy_TIMx , Copy_GPT_Config->CLK_Factor);
    GPT_TIMx_SetInterrupt(Copy_TIMx , Copy_GPT_Config->INTState);
    GPT_TIMx_SetPreScalar(Copy_TIMx,Copy_GPT_Config->Prescalar);
    //GPT_TIMx_Enable(Copy_TIMx);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_Enable(u8 Copy_GPT_TIMx)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    SET_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CEN );
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_Disable(u8 Copy_GPT_TIMx)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CEN );
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetCountDIR(u8 Copy_GPT_TIMx,GPT_CountDir_t Copy_CLKCountDir)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_CLKCountDir)
    {
    case UPCounter:
        CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_DIR );
        local_functionStates = E_OK;
        break;
    case DOWNCounter:
        SET_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_DIR );
        local_functionStates = E_OK;
        break;
    case Center_AllignedMode:
        CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_DIR );
        SET_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CMS1 );
        CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CMS0 );
        local_functionStates = E_OK;
        break;
    default:
        local_functionStates = E_NOT_OK;
        local_functionStates = E_NOT_OK;
        break;
    }
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetPreScalar(u8 Copy_GPT_TIMx,u16 Copy_PrescalarValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    TIM[Copy_GPT_TIMx]->PSC = Copy_PrescalarValue;
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetPeriod(u8 Copy_TIMx,u16 Copy_Period)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    TIM[Copy_TIMx]->ARR = Copy_Period;
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetClkDiv(u8 Copy_GPT_TIMx,GPT_CLKDiv_t Copy_CLKDivValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_CLKDivValue)
    {
    case DIV_1:
        CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CKD0 );
        CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CKD1 );
        local_functionStates = E_OK;
        break;
    case DIV_2:
        SET_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CKD0 );
        CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CKD1 );
        local_functionStates = E_OK;
        break;
    case DIV_4:
        CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CKD0 );
        SET_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CKD1 );
        local_functionStates = E_OK;
        break;
    default:
        local_functionStates = E_NOT_OK;
        local_functionStates = E_NOT_OK;
        break;
    }
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetARRBuffer(u8 Copy_GPT_TIMx,GPT_ArrBufferState_t Copy_ArrBufferState)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_ArrBufferState)
    {
    case Disaple_Arr_Buffer:
       CLR_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMx_CR1_ARPE );
        local_functionStates = E_OK;
        break;
    case Enable_Arr_Buffer :
        SET_BIT( TIM[Copy_GPT_TIMx]->CR1 , TIMx_CR1_ARPE );
        local_functionStates = E_OK;
        break;
    default:
        local_functionStates = E_NOT_OK;
        break;
    }
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetInterrupt(u8 Copy_GPT_TIMx,GPT_INTState_t Copy_INTState)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_INTState)
    {
    case GPT_Disaple_Interrupt:
       CLR_BIT( TIM[Copy_GPT_TIMx]->DIER , TIMX_DIER_UIE );
        local_functionStates = E_OK;
        break;
    case GPT_Enaple_Interrupt :
        SET_BIT( TIM[Copy_GPT_TIMx]->DIER , TIMX_DIER_UIE );
        local_functionStates = E_OK;
        break;
    default:
        local_functionStates = E_NOT_OK;
        break;
    }
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetBusyWait(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    TIM[Copy_TIMx]->ARR = (u16)(Copy_Ticks * Copy_TickType);
    CLR_BIT( TIM[Copy_TIMx]->DIER , TIMX_DIER_UIE);
    SET_BIT( TIM[Copy_TIMx]->CR1 , TIMX_CR1_CEN );
    while(TIM[Copy_TIMx]->CNT != (TIM[Copy_TIMx]->ARR)-1);
    TIM[Copy_TIMx]->CNT =0;
    CLR_BIT( TIM[Copy_TIMx]->CR1 , TIMX_CR1_CEN );
    TIM[Copy_TIMx]->ARR = 0;
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetIntervalSingle(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType, void (*Copy_voidpF)(void))
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    GPT_TIMx_Disable(Copy_TIMx);
    TIM[Copy_TIMx]->ARR = 0;
    TIM[Copy_TIMx]->ARR = (u16)(Copy_Ticks * Copy_TickType);
    CLR_BIT( TIM[Copy_TIMx]->DIER , TIMX_DIER_UIE);
    switch (Copy_TIMx)
    {
    case TIM1:
        TIM1_CallBack = Copy_voidpF;
        GPT_TIM1_SetIntervalMode(TIM_SINGLE_INTERVAL_MODE);
        break;
    case TIM2:
        TIM2_CallBack = Copy_voidpF;
        GPT_TIM2_SetIntervalMode(TIM_SINGLE_INTERVAL_MODE);
        break;
    case TIM3:
        TIM3_CallBack = Copy_voidpF;
        GPT_TIM3_SetIntervalMode(TIM_SINGLE_INTERVAL_MODE);
        break;
    case TIM4:
        TIM4_CallBack = Copy_voidpF;
        GPT_TIM4_SetIntervalMode(TIM_SINGLE_INTERVAL_MODE);
        break;
    default:
        local_functionStates = E_NOT_OK;
        break;
    }
    SET_BIT( TIM[Copy_TIMx]->DIER , TIMX_DIER_UIE);
    GPT_TIMx_Enable(Copy_TIMx);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_SetIntervalPeriodic(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType, void (*Copy_voidpF)(void))
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    GPT_TIMx_Disable(Copy_TIMx);
    TIM[Copy_TIMx]->ARR = 0;
    TIM[Copy_TIMx]->ARR = (u16)(Copy_Ticks * Copy_TickType);
    CLR_BIT( TIM[Copy_TIMx]->DIER , TIMX_DIER_UIE);
    switch (Copy_TIMx)
    {
    case TIM1:
        TIM1_CallBack = Copy_voidpF;
        GPT_TIM1_SetIntervalMode(TIM_PERIODIC_INTERVAL_MODE);
        break;
    case TIM2:
        TIM2_CallBack = Copy_voidpF;
        GPT_TIM2_SetIntervalMode(TIM_PERIODIC_INTERVAL_MODE);
        break;
    case TIM3:
        TIM3_CallBack = Copy_voidpF;
        GPT_TIM3_SetIntervalMode(TIM_PERIODIC_INTERVAL_MODE);
        break;
    case TIM4:
        TIM4_CallBack = Copy_voidpF;
        GPT_TIM4_SetIntervalMode(TIM_PERIODIC_INTERVAL_MODE);
        break;
    default:
        local_functionStates = E_NOT_OK;
        break;
    }
    CLR_BIT(TIM[Copy_TIMx]->SR , TIMX_SR_UIF);
    SET_BIT( TIM[Copy_TIMx]->DIER , TIMX_DIER_UIE);
    GPT_TIMx_Enable(Copy_TIMx);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_GetRemainingTime(u8 Copy_TIMx,GPT_CountDir_t Copy_CountDir , u16* Copy_Remaining)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_CountDir)
    {
    case UPCounter:
        *Copy_Remaining = (u16)(TIM[Copy_TIMx]->ARR -TIM[Copy_TIMx]->CNT);
        local_functionStates = E_OK;
        break;
    case DOWNCounter:
        *Copy_Remaining = (u16)(TIM[Copy_TIMx]->CNT);
        local_functionStates = E_OK;
        break;
    default:
        *Copy_Remaining = (u16)(TIM[Copy_TIMx]->CNT);
        local_functionStates = E_OK;
        break;
    }
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void TIM1_UP_IRQHandler (void)
{
    if(GPT_TIM1_GetIntervalMode() == TIM_SINGLE_INTERVAL_MODE)
    {
        CLR_BIT( TIM[0]->DIER , TIMX_DIER_UIE );
        CLR_BIT( TIM[0]->CR1 , TIMX_CR1_CEN );
        TIM[0]->ARR =0;
    }else
    {

    }
    TIM1_CallBack();
    CLR_BIT(TIM[0]->SR,TIMX_SR_UIF);

}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void TIM2_UP_IRQHandler (void)
{
    if(GPT_TIM2_GetIntervalMode() == TIM_SINGLE_INTERVAL_MODE)
    {
        CLR_BIT( TIM[1]->DIER , TIMX_DIER_UIE );
        CLR_BIT( TIM[1]->CR1 , TIMX_CR1_CEN );
        TIM[1]->ARR =0;
    }else
    {

    }
    TIM2_CallBack();
    CLR_BIT(TIM[1]->SR,TIMX_SR_UIF);
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void TIM3_UP_IRQHandler (void)
{
    if(GPT_TIM3_GetIntervalMode() == TIM_SINGLE_INTERVAL_MODE)
    {
        CLR_BIT( TIM[2]->DIER , TIMX_DIER_UIE );
        CLR_BIT( TIM[2]->CR1 , TIMX_CR1_CEN );
        TIM[2]->ARR =0;
    }else
    {

    }
    TIM3_CallBack();
    CLR_BIT(TIM[2]->SR,TIMX_SR_UIF);
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void TIM4_UP_IRQHandler (void)
{
    if(GPT_TIM4_GetIntervalMode() == TIM_SINGLE_INTERVAL_MODE)
    {
        CLR_BIT( TIM[3]->DIER , TIMX_DIER_UIE );
        CLR_BIT( TIM[3]->CR1 , TIMX_CR1_CEN );
        TIM[3]->ARR =0;
    }else
    {

    }
    TIM4_CallBack();
    CLR_BIT(TIM[3]->SR,TIMX_SR_UIF);
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_PWM_INIT(u8 Copy_TIMx,GPT_PWM_Config_t* Copy_PWM_Config)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    GPT_TIMx_PWM_SetChannel(Copy_TIMx , Copy_PWM_Config->PWM_Channel,Copy_PWM_Config->PWM_Mode);
    GPT_TIMx_SetPeriod( Copy_TIMx , Copy_PWM_Config->ARR);
    SET_BIT( TIM[Copy_TIMx]->CR1 , TIMx_CR1_ARPE);
    SET_BIT( TIM[Copy_TIMx]->CR1 , TIMX_CR1_CEN);
    SET_BIT( TIM[Copy_TIMx]->EGR , TIMX_EGR_UG);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_PWM_SetAllignmentMode(u8 Copy_GPT_TIMx,GPT_PWM_AllignMode_t Copy_AllignMode)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_AllignMode)
    {
    case Edge_AllignedMode:
        CLR_BIT(TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CMS0);
        CLR_BIT(TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CMS1);
        local_functionStates = E_OK;
        break;
    case Center_AllignedMode:
        CLR_BIT(TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CMS0);
        SET_BIT(TIM[Copy_GPT_TIMx]->CR1 , TIMX_CR1_CMS1);
        local_functionStates = E_OK;
        break;
    default:
        break;
    }
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_TIMx_PWM_SetChannel(u8 Copy_GPT_TIMx,GPT_PWM_Channel_t Copy_Channel,GPT_PWM_Mode_t Copy_PWM_Mode)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_Channel)
    {
    case TIM_Channel1:
        TIM[Copy_GPT_TIMx]->CCMR1 = TIM[Copy_GPT_TIMx]->CCMR1 & ~(0b1111<<4);
        TIM[Copy_GPT_TIMx]->CCMR1 = TIM[Copy_GPT_TIMx]->CCMR1 | (Copy_PWM_Mode<<4);
        SET_BIT( TIM[Copy_GPT_TIMx]->CCMR1 , TIMX_CCMR1_OC1PE);
        SET_BIT( TIM[Copy_GPT_TIMx]->CCER , TIMX_CCER_CC1E );
        SET_BIT( TIM[Copy_GPT_TIMx]->CCER , TIMX_CCER_CC1P );
        SET_BIT(TIM[Copy_GPT_TIMx]->BDTR ,TIMX_BDTR_MOE);
        break;
    case TIM_Channel2:
        TIM[Copy_GPT_TIMx]->CCMR1 = TIM[Copy_GPT_TIMx]->CCMR1 & ~(0b1111<<12);
        TIM[Copy_GPT_TIMx]->CCMR1 = TIM[Copy_GPT_TIMx]->CCMR1 | (Copy_PWM_Mode<<12);
        SET_BIT( TIM[Copy_GPT_TIMx]->CCMR1 , TIMX_CCMR1_OC2PE);
        SET_BIT( TIM[Copy_GPT_TIMx]->CCER , TIMX_CCER_CC2E );
        SET_BIT( TIM[Copy_GPT_TIMx]->CCER , TIMX_CCER_CC2P );
        SET_BIT(TIM[Copy_GPT_TIMx]->BDTR ,TIMX_BDTR_MOE);
        break;
    case TIM_Channel3:
        TIM[Copy_GPT_TIMx]->CCMR2 = TIM[Copy_GPT_TIMx]->CCMR2 & ~(0b1111<<4);
        TIM[Copy_GPT_TIMx]->CCMR2 = TIM[Copy_GPT_TIMx]->CCMR2 | (Copy_PWM_Mode<<4);
        SET_BIT( TIM[Copy_GPT_TIMx]->CCMR2 , TIMX_CCMR2_OC3PE);
        SET_BIT( TIM[Copy_GPT_TIMx]->CCER , TIMX_CCER_CC3E );
        SET_BIT( TIM[Copy_GPT_TIMx]->CCER , TIMX_CCER_CC3P );
        SET_BIT(TIM[Copy_GPT_TIMx]->BDTR ,TIMX_BDTR_MOE);
        break;
    case TIM_Channel4:
        TIM[Copy_GPT_TIMx]->CCMR2 = TIM[Copy_GPT_TIMx]->CCMR2 & ~(0b1111<<4);
        TIM[Copy_GPT_TIMx]->CCMR2 = TIM[Copy_GPT_TIMx]->CCMR2 | (Copy_PWM_Mode<<12);
        SET_BIT( TIM[Copy_GPT_TIMx]->CCMR2 , TIMX_CCMR2_OC4PE);
        SET_BIT( TIM[Copy_GPT_TIMx]->CCER , TIMX_CCER_CC4E );
        SET_BIT( TIM[Copy_GPT_TIMx]->CCER , TIMX_CCER_CC4P );
        SET_BIT(TIM[Copy_GPT_TIMx]->BDTR ,TIMX_BDTR_MOE);
        break;
    default:
        local_functionStates = E_NOT_OK;
        break;
    }
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_PWM_SetDutyCycle(u8 Copy_TIMx,GPT_PWM_Channel_t Copy_Channel , u8 Copy_DutyCycle)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    u16 Local_Pulse = TIM[Copy_TIMx]->ARR * Copy_DutyCycle/100.0;
    switch (Copy_Channel)
    {
    case TIM_Channel1 :
        TIM[Copy_TIMx]->CCR1=Local_Pulse;
        break;
    case TIM_Channel2 :
        TIM[Copy_TIMx]->CCR2=Local_Pulse;
        break;
    case TIM_Channel3 :
        TIM[Copy_TIMx]->CCR3=Local_Pulse;
        break;
    case TIM_Channel4 :
        TIM[Copy_TIMx]->CCR4=Local_Pulse;
        break;
    default:
        local_functionStates = E_NOT_OK;
        break;
    }
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_PWM_DEINIT(u8 Copy_TIMx,GPT_PWM_Channel_t Copy_Channel)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_Channel)
    {
    case TIM_Channel1:
        TIM[Copy_TIMx]->CCMR1 = TIM[Copy_TIMx]->CCMR1 & ~(0b1111<<4);
        CLR_BIT( TIM[Copy_TIMx]->CCMR1 , TIMX_CCMR1_OC1PE);
        CLR_BIT( TIM[Copy_TIMx]->CCER , TIMX_CCER_CC1E );
        CLR_BIT( TIM[Copy_TIMx]->CCER , TIMX_CCER_CC1P );
        break;
    case TIM_Channel2:
        TIM[Copy_TIMx]->CCMR1 = TIM[Copy_TIMx]->CCMR1 & ~(0b1111<<12);
        CLR_BIT( TIM[Copy_TIMx]->CCMR1 , TIMX_CCMR1_OC2PE);
        CLR_BIT( TIM[Copy_TIMx]->CCER , TIMX_CCER_CC2E );
        CLR_BIT( TIM[Copy_TIMx]->CCER , TIMX_CCER_CC2P );
        break;
    case TIM_Channel3:
        TIM[Copy_TIMx]->CCMR2 = TIM[Copy_TIMx]->CCMR2 & ~(0b1111<<4);
        CLR_BIT( TIM[Copy_TIMx]->CCMR2 , TIMX_CCMR2_OC3PE);
        CLR_BIT( TIM[Copy_TIMx]->CCER , TIMX_CCER_CC3E );
        CLR_BIT( TIM[Copy_TIMx]->CCER , TIMX_CCER_CC3P );
        break;
    case TIM_Channel4:
        TIM[Copy_TIMx]->CCMR2 = TIM[Copy_TIMx]->CCMR2 & ~(0b1111<<4);
        CLR_BIT( TIM[Copy_TIMx]->CCMR2 , TIMX_CCMR2_OC4PE);
        CLR_BIT( TIM[Copy_TIMx]->CCER , TIMX_CCER_CC4E );
        CLR_BIT( TIM[Copy_TIMx]->CCER , TIMX_CCER_CC4P );
        break;
    default:
        local_functionStates = E_NOT_OK;
        break;
    }
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType GPT_PWM_GetCounterValue(u8 Copy_TIMx,u16* Copy_PWMValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    *Copy_PWMValue = TIM[Copy_TIMx]->CNT;
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_FUNCTION   ====================================================*/