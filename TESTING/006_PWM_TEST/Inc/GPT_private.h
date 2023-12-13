/**
 * @file GPT_private.h
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
#ifndef GPT_PRIVATE_H_
#define GPT_PRIVATE_H_

/*******************************< Number of timers in the microcontrollers *******************************/
#define TIM_IN_STM32F103C6		4
/*******************************< Register Definitions *******************************/
/**
 * @brief TIM Base Address.
 *
 * This macros defines the base address of the GENERAL PURPOSE TIMERS (GPT) peripheral.
 */
#define GPT_TIM1_BASEADDRESS    0x40012C00
#define GPT_TIM2_BASEADDRESS    0x40000000
#define GPT_TIM3_BASEADDRESS    0x40000400
#define GPT_TIM4_BASEADDRESS    0x40000800
#define GPT_TIM5_BASEADDRESS    0x40000C00
#define GPT_TIM6_BASEADDRESS    0x40001000
#define GPT_TIM7_BASEADDRESS    0x40001400
#define GPT_TIM8_BASEADDRESS    0x40013400
#define GPT_TIM9_BASEADDRESS    0x40014C00
/*******************************< Bit Definitions *******************************/
/**
 * @brief Bit definitions of the registers.
 *
 * This macros defines the different bit locations of the GENERAL PURPOSE TIMERS (GPT) registers.
 */
/*******************************< CR1 *******************************/
#define TIMX_CR1_CEN    0
#define TIMX_CR1_DIR    4
#define TIMX_CR1_CMS0   5
#define TIMX_CR1_CMS1   6
#define TIMx_CR1_ARPE   7
#define TIMX_CR1_CKD0   8
#define TIMX_CR1_CKD1   9
/*******************************< DIER *******************************/
#define TIMX_DIER_UIE   0
/*******************************< SR *******************************/
#define TIMX_SR_UIF     0
/*******************************< EGR *******************************/
#define TIMX_EGR_UG     0
/*******************************< CCMR1 *******************************/
#define TIMX_CCMR1_OC1PE 3
#define TIMX_CCMR1_OC2PE 11
/*******************************< CCMR2 *******************************/
#define TIMX_CCMR2_OC3PE 3
#define TIMX_CCMR2_OC4PE 11
/*******************************< CCER *******************************/
#define TIMX_CCER_CC1E  0
#define TIMX_CCER_CC1P  1
#define TIMX_CCER_CC2E  4
#define TIMX_CCER_CC2P  5
#define TIMX_CCER_CC3E  8
#define TIMX_CCER_CC3P  9
#define TIMX_CCER_CC4E  12
#define TIMX_CCER_CC4P  13
/**
 * @brief GPT Register Map.
 *
 * This struct defines the register map of the GPT peripheral, providing volatile access to the Control Register 1 (CR1),
 * Control Register 2 (CR2), slave mode control register (SMCR), DMA/interrupt enable register (DIER), 
 * status register (SR), event generation register (EGR), capture/compare mode register 1 (CCMR1),
 * capture/compare mode register 2 (CCMR2), capture/compare enable register (CCER), counter (CNT),
 * prescaler (PSC), auto-reload register (ARR), repetition counter register (RCR), capture/compare register 1 (CCR1)
 * capture/compare register 2 (CCR2), capture/compare register 3 (CCR3),  capture/compare register 4 (CCR4)
 * break and dead-time register (BDTR), DMA control register (DCR) and DMA address for full transfer (DMAR)
 */ 
typedef struct {
    volatile u16 CR1;
    u16 RESERVED0;
    volatile u16 CR2;
    u16 RESERVED1;
    volatile u16 SMCR;
    u16 RESERVED2;
    volatile u16 DIER;
    u16 RESERVED3;
    volatile u16 SR;
    u16 RESERVED4;
    volatile u16 EGR;
    u16 RESERVED5;
    volatile u16 CCMR1;
    u16 RESERVED6;
    volatile u16 CCMR2;
    u16 RESERVED7;
    volatile u16 CCER;
    u16 RESERVED8;
    volatile u16 CNT;
    u16 RESERVED9;
    volatile u16 PSC;
    u16 RESERVED10;
    volatile u16 ARR;
    u16 RESERVED11;
    volatile u16 RCR;
    u16 RESERVED12;
    volatile u16 CCR1;
    u16 RESERVED13;
    volatile u16 CCR2;
    u16 RESERVED14;
    volatile u16 CCR3;
    u16 RESERVED15;
    volatile u16 CCR4;
    u16 RESERVED16;
    volatile u16 BDTR;
    u16 RESERVED17;
    volatile u16 DCR;
    u16 RESERVED18;
    volatile u32 DMAR;
}GPT_TIM_RegDef_t;
/**
 * @brief GPT Register Access.
 *
 * This macro provides access to the GPT peripheral using the register map defined in GPT_TIM_RegDef_t. It defines GPT as a volatile
 * pointer to the base address of the GPT peripheral.
 */
volatile GPT_TIM_RegDef_t* TIM[TIM_IN_STM32F103C6]={
    (volatile GPT_TIM_RegDef_t*)GPT_TIM1_BASEADDRESS,
    (volatile GPT_TIM_RegDef_t*)GPT_TIM2_BASEADDRESS,
    (volatile GPT_TIM_RegDef_t*)GPT_TIM3_BASEADDRESS,
    (volatile GPT_TIM_RegDef_t*)GPT_TIM4_BASEADDRESS,
};
/**< Macro for the milliseconds */
#define MilliSeconds    0
/**< Macro for the seconds */
#define Seconds         1
/**
 * @brief Enable the GPTx 
 *
 * This function Enables the GPTx setting it to its default state.
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to enable
 * @return Std_ReturnType
 *   - E_OK     : GPT enabled successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_Enable(u8 Copy_GPT_TIMx);
/**
 * @brief Disaples the GPTx 
 *
 * This function Disaples the GPTx setting it to its default state.
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to disaple
 * @return Std_ReturnType
 *   - E_OK     : GPT Disapled successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_Disable(u8 Copy_GPT_TIMx);
/**
 * @brief Sets the GPTx prescalar
 *
 * This function sets the prescalar value for the timer.
 * The counter clock frequency (CK_CNT) is equal to fCK_PSC / (PSC[15:0] + 1)
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to set the prescalar for.
 * @param[in] Copy_PrescalarValue The prescalar value you want to set.
 * @return Std_ReturnType
 *   - E_OK     : GPT prescalar is set successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_SetPreScalar(u8 Copy_GPT_TIMx,u16 Copy_PrescalarValue);
/**
 * @brief Sets the GPTx CLKDIV
 *
 * This function sets the CLKDIV value for the timer.
 * the division ratio between the timer clock (CK_INT) frequency and the 
 * dead-time and sampling clock (tDTS)used by the dead-time generators and the digital filte
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to set the CLK Div for.
 * @param[in] Copy_CLKDivValue The CLKDIV value you want to set.
 *                     Options: DIV_1 DIV_2 DIV_4
 * @return Std_ReturnType
 *   - E_OK     : GPT CLKDIV is set successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_SetClkDiv(u8 Copy_GPT_TIMx,GPT_CLKDiv_t Copy_CLKDivValue);
/**
 * @brief Sets the GPTx ARR value
 *
 * This function sets the Auto Relod Register (ARR) value for the timer.
 * The counter is blocked while the auto-reload value is null.
 *
 * @param[in] Copy_TIMx The GPT you want to set the period for.
 * @param[in] Copy_Period The Period you want for the ARR register
 * @return Std_ReturnType
 *   - E_OK     : GPT period is set successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_SetPeriod(u8 Copy_TIMx,u16 Copy_Period);
/**
 * @brief Sets the GPTx count DIR
 *
 * This function sets the count direction for the timer.
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to set the direction for.
 * @param[in] Copy_CLKCountDir Sets the count direction ( UPCounter, DOWNCounter,CenterAlligned)
 * @return Std_ReturnType
 *   - E_OK     : GPT direction is set successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_SetCountDIR(u8 Copy_GPT_TIMx,GPT_CountDir_t Copy_CLKCountDir);
/**
 * @brief Enables the GPTx Buffer for ARR 
 *
 * This function Enbales the GPTx Buffer for ARR.
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to set the arr buffer for.
 * @param[in] Copy_ArrBufferState ARR buffer state (Disaple_Arr_Buffer,Enable_Arr_Buffer)
 * @return Std_ReturnType
 *   - E_OK     : GPT  arr buffer is set successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_SetARRBuffer(u8 Copy_GPT_TIMx,GPT_ArrBufferState_t Copy_ArrBufferState);
/**
 * @brief Enables the GPTx interrupt
 *
 * This function enables the GPTx interrupt
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to set the inerrupt for.
 * @param[in] Copy_INTState GPT Interrupt state (GPT_Disaple_Interrupt,GPT_Enaple_Interrupt)
 * @return Std_ReturnType
 *   - E_OK     : GPT inerrupt is set successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_SetInterrupt(u8 Copy_GPT_TIMx,GPT_INTState_t Copy_INTState);
/**
 * @brief Sets the GPTx Allignment mode
 *
 * This function Sets the GPTx Allignment mode
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to set the Allignment for.
 * @param[in] Copy_INTState GPT Interrupt state (Edge_AllignedMode,Center_AllignedMode)
 * @return Std_ReturnType
 *   - E_OK     : GPT Allignment is set successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_PWM_SetAllignmentMode(u8 Copy_GPT_TIMx,GPT_PWM_AllignMode_t Copy_AllignMode);
/**
 * @brief Sets the GPTx PWM Channel mode
 *
 * This function Sets the GPTx PWM Channel mode
 *
 * @param[in] Copy_GPT_TIMx The GPT you want to set the PWM Channel for.
 * @param[in] Copy_Channel GPT PWM Channel  (TIM_Channel1,TIM_Channel2,TIM_Channel3,TIM_Channel4)
 * @param[in] Copy_PWM_Mode GPT PWM Channel Type  (PWM_11,PWM_22)
 * @return Std_ReturnType
 *   - E_OK     : GPT PWM Channel MODE is set successfully.
 *   - E_NOT_OK : An error occurred (invalid GPT).
 * 
 * @note This function is only called within the driver it cannot be called elsewhere
 * 
 */
Std_ReturnType GPT_TIMx_PWM_SetChannel(u8 Copy_GPT_TIMx,GPT_PWM_Channel_t Copy_Channel,GPT_PWM_Mode_t Copy_PWM_Mode);



#endif /* GPT_PRIVATE_H_ */