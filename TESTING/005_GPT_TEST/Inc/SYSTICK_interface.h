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
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

typedef void(*SYSTICK_CallbackFunc_t)(void);
/**
 * @brief Initializes the SysTick timer with the specified reload value.
 *
 * This function initializes the SysTick timer with the specified reload value. The timer is configured to use the processor clock
 * or a divided clock source based on the configuration settings. It also allows generating an interrupt when the timer reaches zero.
 * This function sets the initial value of the timer and prepares it for counting down.
 *
 * @param[in] Copy_Ticks The number of clock cycles to reload the SysTick timer with.
 *
 * @note The actual time duration for the timer to reach zero depends on the clock frequency and the value passed as `Copy_Ticks`.
 * 
 * @warning This function should be used carefully, as improper configuration may lead to unexpected behavior.
 *
 * @return
 *     - E_OK if the reload value was set successfully.
 *     - E_NOT_OK if the reload value is out of range (see STK_RELOAD_MAX for the valid range). */
Std_ReturnType MCAL_SYSTICK_xINIT(u32 Copy_Ticks);
/**
 * @brief Initialize the SysTick Timer
 *
 * This function initializes the SysTick timer with the specified configuration settings.
 * It can be used to configure the timer's clock source and enable/disable interrupts when
 * the timer reaches zero.
 *
 * @note The SysTick timer is typically used for timekeeping or creating delays in software.
 *
 * @warning This function should be called before using the SysTick timer for any timing-related tasks.
 *
 * @param None.
 *
 * @return
 *     - E_OK if the reload value was set successfully.
 *     - E_NOT_OK if the reload value is out of range (see STK_RELOAD_MAX for the valid range). *
 * @sa MCAL_STK_Start
 * @sa MCAL_STK_Stop
 * @sa MCAL_STK_SetReloadValue
 */
Std_ReturnType MCAL_SYSTICK_vINIT();
/**
 * @brief Set the SysTick Timer Reload Value
 *
 * This function sets the reload value of the SysTick timer, which determines the period
 * at which the timer generates interrupts or counts down.
 *
 * @param[in] Copy_ReloadValue The reload value to set (must be within the valid range).
 *
 * @note The actual time duration between interrupts or timer overflows depends on the
 *       system clock frequency and the specified reload value.
 *
 * @return
 *     - E_OK if the reload value was set successfully.
 *     - E_NOT_OK if the reload value is out of range (see STK_RELOAD_MAX for the valid range).
 */
Std_ReturnType MCAL_SYSTICK_SetReloadValue(u32 Copy_ReloadValue);
/**
 * @brief Starts the SysTick timer.
 *
 * This function starts the SysTick timer. Once the timer is started, it will count down from the reload value specified in the
 * "STK_Init" function until it reaches zero. When the timer reaches zero, it will generate an interrupt and reload with
 * the initial value.
 *
 * @param None.
 *
 * @return
 *     - E_OK if the reload value was set successfully.
 *     - E_NOT_OK if the reload value is out of range (see STK_RELOAD_MAX for the valid range). */
Std_ReturnType MCAL_SYSTICK_Start();
/**
 * @brief Stops the SysTick timer.
 *
 * This function stops the SysTick timer. Once the timer is stopped, it will no longer count down or generate interrupts.
 *
 * @param None.
 *
 * @return
 *     - E_OK if the reload value was set successfully.
 *     - E_NOT_OK if the reload value is out of range (see STK_RELOAD_MAX for the valid range). */
Std_ReturnType MCAL_SYSTICK_Stop();
/**
 * @brief Resets the SysTick timer.
 *
 * This function disables the SysTick timer, clears the current value, sets the reload value to 0,
 * and clears the count flag.
 *
 * @param None.
 *
 * @return
 *     - E_OK if the reload value was set successfully.
 *     - E_NOT_OK if the reload value is out of range (see STK_RELOAD_MAX for the valid range). */
Std_ReturnType MCAL_SYSTICK_Reset();
/**
 * @brief Gets the current value of the SysTick timer.
 *
 * This function gets the current value of the SysTick timer. The timer value represents the number of ticks remaining until
 * the timer reaches zero.
 *
 * @param Remaining_Counts The current value of the SysTick timer .
 *
 * @return
 *     - E_OK if the reload value was set successfully.
 *     - E_NOT_OK if the reload value is out of range (see STK_RELOAD_MAX for the valid range).
 *  */
Std_ReturnType MCAL_SYSTICK_GetRemainingCounts(u32* Remaining_Counts);
/**
 * @brief Get the number of elapsed ticks since the last SysTick timer reset.
 *
 * This function calculates the number of ticks that have elapsed since the last reset of the SysTick timer.
 * The elapsed time is calculated as the difference between the value of the SysTick timer when this function
 * is called and the initial value of the timer when it was last reset.
 *
 * @note This function assumes that the SysTick timer is running and has not overflowed since it was last reset.
 * If the timer has overflowed, the elapsed ticks value will be incorrect and the function may return unexpected results.
 *
 * @param Elapsed_Counts The number of elapsed ticks as an unsigned 32-bit integer.
 * 
 * @return
 *     - E_OK if the reload value was set successfully.
 *     - E_NOT_OK if the reload value is out of range (see STK_RELOAD_MAX for the valid range). */
Std_ReturnType MCAL_SYSTICK_GetElapsedCounts(u32* Elapsed_Counts);
/**
 * @brief Blocks the CPU for the specified number of microseconds.
 *
 * This function blocks the CPU for the specified number of microseconds using the SysTick timer. The function calculates the
 * number of ticks required to wait for the specified number of microseconds based on the current system clock frequency and
 * the reload value of the SysTick timer.
 *
 * @param[in] Copy_u32Microseconds The number of microseconds to wait. This value should be less than or equal to 16777215 (0x00FFFFFF).
 *
 *
 * @return E_OK if the delay was successful, E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_SYSTICK_DelayUS(f32 Copy_MicroSeconds);
/**
 * @brief Blocks the CPU for the specified number of milliseconds.
 *
 * This function blocks the CPU for the specified number of milliseconds using the SysTick timer. The function calculates the
 * number of ticks required to wait for the specified number of milliseconds based on the current system clock frequency and
 * the reload value of the SysTick timer.
 *
 * @param[in] Copy_Milliseconds The number of milliseconds to wait. This value should be less than or equal to 16777215 (0x00FFFFFF).
 *
 * 
 * @return E_OK if the delay was successful, E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_SYSTICK_DelayMS(f32 Copy_MilliSeconds);
/**
 * @brief Configures the SysTick timer for a single-shot interval and associates a callback function.
 *
 * This function sets up the SysTick timer to generate a single interrupt after the specified
 * interval in microseconds. It saves the provided callback function pointer and calculates
 * the number of ticks required for the given interval. The timer is configured for a single-shot
 * operation and starts counting down. When the timer reaches zero, the saved callback function
 * is called. Returns E_OK if the configuration was successful; otherwise, returns E_NOT_OK.
 *
 * @param[in] Copy_Microseconds The interval in microseconds after which the timer should expire.
 * @param[in] Callback_Func      A pointer to the callback function to be executed when the timer expires.
 *
 * @return
 *     - E_OK     if the configuration was successful.
 *     - E_NOT_OK if an error occurred (e.g., if the callback function pointer is NULL).
 * 
 * @see STK_SINGLE_INTERVAL
 * @see MCAL_STK_SetIntervalSingle
 */
Std_ReturnType MCAL_SYSTICK_SetIntervalSingle(f32 Copy_MicroSeconds , SYSTICK_CallbackFunc_t Callback_Func );
/**
 * @brief Configures the SysTick timer for a periodic interval and associates a callback function.
 *
 * This function sets up the SysTick timer to operate in a periodic interval mode. It calculates
 * the number of ticks required to wait for the specified duration in microseconds and configures
 * the SysTick timer's reload value accordingly. When the timer reaches zero, it generates interrupts
 * at regular intervals defined by the specified microseconds. The associated callback function
 * is executed upon each interrupt.
 *
 * @param[in] Copy_Microseconds The interval duration in microseconds for SysTick timer interrupts.
 * @param[in] Callback_Func A pointer to the function to be executed upon each SysTick interrupt.
 *
 * @note The maximum delay achievable with this function, when the SysTick timer clock is 1 MHz, is approximately 16 seconds.
 * @note Ensure that the callback function has a void return type and takes no parameters (void (*CallbackFunc)(void)).
 * @note This function enables the SysTick timer and its interrupt.
 *
 * @return
 *     - E_OK if the SysTick timer was configured successfully.
 *     - E_NOT_OK if an invalid callback function pointer is provided.
 *
 * @see STK_SINGLE_INTERVAL
 * @see MCAL_STK_SetIntervalSingle
 */
Std_ReturnType MCAL_SYSTICK_SetIntervalPeriodic(f32 Copy_MicroSeconds , SYSTICK_CallbackFunc_t Callback_Func);


#endif /* SYSTICK_INTERFACE_H_ */