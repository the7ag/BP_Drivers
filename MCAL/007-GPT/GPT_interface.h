/**
 * @file GPT_interface.h
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
#ifndef GPT_INTERFACE_H_
#define GPT_INTERFACE_H_
/*Timer Difnition*/
#define TIM1    0
#define TIM2    1
#define TIM3    2
#define TIM4    3

#define TIM_SINGLE_INTERVAL_MODE    0
#define TIM_PERIODIC_INTERVAL_MODE  1

typedef enum 
{
    DIV_1,
    DIV_2,
    DIV_4
}GPT_CLKDiv_t;

typedef enum 
{
    UPCounter,
    DOWNCounter,
    CenterAlligned
}GPT_CountDir_t;

typedef enum 
{
    Disaple_Arr_Buffer,
    Enable_Arr_Buffer
}GPT_ArrBufferState_t;

typedef enum{
    GPT_Disaple_Interrupt,
    GPT_Enaple_Interrupt
}GPT_INTState_t;
typedef enum{
    Edge_AllignedMode,
    Center_AllignedMode=2
}GPT_PWM_AllignMode_t;

typedef enum{
    TIM_Channel1,
    TIM_Channel2,
    TIM_Channel3,
    TIM_Channel4
}GPT_PWM_Channel_t;

typedef enum{
    PWM_11=0b110,
    PWM_22=0b111
}GPT_PWM_Mode_t;

typedef enum {
    TIM_CLK_SRC_INTERNAL,
    TIM_CLK_SRC_EXTERNAL_MODE1,
    TIM_CLK_SRC_EXTERNAL_MODE2
}GPT_TIM_CLK_SRC_t;

typedef enum
{
    Active_High,
    Active_Low
}GPT_TIM_POLARITY_t;

typedef enum
{
    Rising,
    Falling
}GPT_TIM_EDGE_t;

typedef struct 
{
    u16 ARR;
    GPT_CountDir_t GPT_DIR;
    GPT_PWM_AllignMode_t AllignMode;
    GPT_CLKDiv_t CLK_Factor;
    GPT_ArrBufferState_t ARB;
    GPT_INTState_t INTState;
}GPT_Config_t;

typedef struct 
{
    u16 ARR;
    GPT_PWM_Channel_t PWM_Channel;
    u16 Freq;
    GPT_PWM_Mode_t PWM_Mode;
    
}GPT_PWM_Config_t;

Std_ReturnType GPT_TIMx_init(u8 Copy_TIMx,GPT_Config_t* Copy_GPT_Config);
Std_ReturnType GPT_TIMx_SetBusyWait(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType);
Std_ReturnType GPT_TIMx_SetIntervalSingle(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType, void (*Copy_voidpF)(void));
Std_ReturnType GPT_TIMx_SetIntervalPeriodic(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType, void (*Copy_voidpF)(void));
Std_ReturnType GPT_TIMx_GetRemainingTime(u8 Copy_TIMx,GPT_CountDir_t Copy_CountDir , u16* Copy_Remaining);

void TIM1_UP_IRQHandler (void);
void TIM2_UP_IRQHandler (void);
void TIM3_UP_IRQHandler (void);
void TIM4_UP_IRQHandler (void);

Std_ReturnType GPT_PWM_INIT(u8 Copy_TIMx,GPT_PWM_Config_t* Copy_PWM_Config);
Std_ReturnType GPT_PWM_SetDutyCycle(u8 Copy_TIMx,GPT_PWM_Channel_t Copy_Channel , u8 Copy_DutyCycle);
Std_ReturnType GPT_PWM_DEINIT(u8 Copy_TIMx,GPT_PWM_Channel_t Copy_Channel);
Std_ReturnType GPT_PWM_GetCounterValue(u8 Copy_TIMx,u16* Copy_PWMValue);




#endif /* GPT_INTERFACE_H_ */