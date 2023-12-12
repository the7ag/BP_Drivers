/**
 * @brief This module contains functions for configuring the system tick core peripheral.
 *
 * @author Mohamed Ali Bayoumi
 * @date 28 OCT 2023
 * @version V01
 *
 * this module is used to enable disaple the systick and setting it's value and setting it's callback function
 * when an interrupt happens
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_
/*****************************< Register Definitions *****************************/
#define SYSTICK_BASE_ADDRESS        0xE000E010

typedef struct 
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}SYSTICK_RegDef_t;

#define SYSTICK ((SYSTICK_RegDef_t*)(SYSTICK_BASE_ADDRESS))
/**
 * @brief Maximum Reload Value for SysTick Timer
 *
 * This macro defines the maximum valid reload value that can be used for configuring
 * the SysTick timer's period. The SysTick timer is a down-counter that generates interrupts
 * or overflows at regular intervals based on its reload value.
 *
 * @note The actual time duration between interrupts or overflows depends on the system clock
 *       frequency and the value set using this macro.
 *
 * @warning Setting a reload value greater than this maximum may result in undefined behavior.
 *
 * @see MCAL_STK_SetReloadValue
 */
#define SYSTICK_RELOAD_MAX 0x00FFFFFF
/*****************************< The following are defines for the bit fields in the STK_CTRL register. *****************************/

#define SYSTICK_CTRL_ENABLE_MASK    0x00000001
#define SYSTICK_CTRL_TICKINT_MASK   0x00000002
#define SYSTICK_CTRL_CLKSRC_MASK    0x00000004
#define SYSTICK_CTRL_COUNTFLAG_MASK 0x00010000

/**
 * @brief Specifies the clock source for the SysTick timer.
 *
 * This option determines whether the SysTick timer uses the processor clock or
 * an external clock source.
 *
 * @param SYSTICK_CLKSRC_DIV_1 Clock source is the processor clock.
 * @param SYSTICK_CLKSRC_DIV_8 Clock source is the processor clock divided by 8.
 *
 * @retval None
 */
#define SYSTICK_CLKSRC_DIV_1          0
#define SYSTICK_CLKSRC_DIV_8          1
/**
 * @brief Sets the system clock frequency for the SysTick peripheral.
 *
 * This function sets the system clock frequency for the SysTick peripheral. It does not allow changes to the values defined by the STK_CTRL_CLKSOURCE constant.
 *
 * @note
 * The available options for STK_CTRL_CLKSOURCE are:
 * - SYSTICK_CLKSRC_DIV_1: Processor clock (AHB clock) divided by 1
 * - SYSTICK_CLKSRC_DIV_8: Processor clock (AHB clock) divided by 8
 *
 * @retval None
 */
#if SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_1
    #define STK_AHB_CLK 8000000
#elif SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_8
    #define STK_AHB_CLK 1000000
#else
    #error "Wrong CLK SRC for STK"asm
#endif
/**
 * @brief Specifies whether the SysTick timer exception request is enabled.
 *
 * This option determines whether the SysTick timer asserts an exception request
 * when the counter reaches zero.
 *
 * @param SYSTICK_TICKINT_ENABLED Counting down to zero asserts the SysTick exception request.
 * @param SYSTICK_TICKINT_DISABLED Counting down to zero does not assert the SysTick exception request.
 *
 * @retval None
 */

#define SYSTICK_TICKINT_ENABLED       1
#define SYSTICK_TICKINT_DISABLED      0
/**
 * @brief Specifies the operation mode of the SysTick timer interval.
 *
 * The SysTick timer can operate in two modes: single-shot interval and periodic interval.
 * - "STK_SINGLE_INTERVAL": Indicates that the SysTick timer operates in single-shot mode.
 *   In this mode, the timer generates an interrupt only once after the specified interval
 *   and then stops until reconfigured.
 *
 * - "STK_PERIOD_INTERVAL": Indicates that the SysTick timer operates in periodic mode.
 *   In this mode, the timer generates interrupts at regular intervals specified by the
 *   reload value, and it continues operating until explicitly disabled.
 *
 * These macros are used to configure the behavior of the SysTick timer interval, providing
 * control over whether the timer generates interrupts once (single-shot) or repeatedly
 * (periodic) at the specified interval.
 *
 * @note Choose the appropriate mode based on your application's timing requirements.
 *
 * @see SYSTICK_SINGLE_INTERVAL
 * @see SYSTICK_PERIOD_INTERVAL
 */
#define SYSTICK_SINGLE_INTERVAL       0
#define SYSTICK_PERIOD_INTERVAL       1

#endif /* SYSTICK_PRIVATE_H_ */
