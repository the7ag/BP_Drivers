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
#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_
/**
 * @brief Specifies the clock source for the SysTick timer.
 *
 * This option determines whether the SysTick timer uses the processor clock or
 * an external clock source.
 *
 * @note
 * The external clock source must be connected to the STKCLK pin on the microcontroller.
 *
 * @note
 * This option is only applicable if the SysTick timer is configured to use an
 * external clock source (STK_CLKSOURCE = STK_CLKSOURCE_EXT).
 *
 * @param SYSTICK_CLKSRC_DIV_1 Clock source is the clock of STK.
 * @param SYSTICK_CLKSRC_DIV_8 Clock source/8 is the clock of STK.
 *
 * @retval None
 */
#define SYSTICK_AHB_CLKSRC  SYSTICK_CLKSRC_DIV_8
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
#define SYSTICK_TICKINT SYSTICK_TICKINT_ENABLED

#endif /* SYSTICK_CONFIG_H_ */