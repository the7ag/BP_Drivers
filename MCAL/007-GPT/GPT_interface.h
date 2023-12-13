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
/**
 * @brief Timer definitions.
 *
 * These definitions represent different timer identifiers.
 */
#define TIM1    0   /**< Timer 1 */
#define TIM2    1   /**< Timer 2 */
#define TIM3    2   /**< Timer 3 */
#define TIM4    3   /**< Timer 4 */

/**
 * @brief Timer mode definitions.
 *
 * These definitions specify different modes for timer operations.
 */
#define TIM_SINGLE_INTERVAL_MODE    0   /**< Single interval mode */
#define TIM_PERIODIC_INTERVAL_MODE  1   /**< Periodic interval mode */

/**
 * @brief Enumeration for General Purpose Timer (GPT) clock divider options.
 *
 * This enumeration defines different clock divider options for GPT.
 */
typedef enum {
    DIV_1,   /**< Clock divider 1: No division */
    DIV_2,   /**< Clock divider 2 */
    DIV_4    /**< Clock divider 4 */
} GPT_CLKDiv_t;

/**
 * @brief Enumeration for General Purpose Timer (GPT) counting directions/modes.
 *
 * This enumeration defines different counting directions or modes for GPT.
 */
typedef enum {
    UPCounter,        /**< Up counter mode */
    DOWNCounter,      /**< Down counter mode */
    CenterAlligned    /**< Center-aligned mode */
} GPT_CountDir_t;

/**
 * @brief Enumeration for General Purpose Timer (GPT) ARR (Auto-Reload Register) buffer states.
 *
 * This enumeration defines states for enabling or disabling ARR buffer in GPT.
 */
typedef enum {
    Disable_Arr_Buffer, /**< Disable ARR buffer */
    Enable_Arr_Buffer   /**< Enable ARR buffer */
} GPT_ArrBufferState_t;
/**
 * @brief Enumeration for General Purpose Timer (GPT) interrupt states.
 *
 * This enumeration defines states for enabling or disabling interrupts in GPT.
 */
typedef enum {
    GPT_Disable_Interrupt, /**< Disable interrupt */
    GPT_Enable_Interrupt   /**< Enable interrupt */
} GPT_INTState_t;

/**
 * @brief Enumeration for General Purpose Timer (GPT) PWM alignment modes.
 *
 * This enumeration defines different PWM alignment modes for GPT.
 */
typedef enum {
    Edge_AllignedMode,       /**< Edge-aligned mode */
    Center_AllignedMode = 2  /**< Center-aligned mode */
} GPT_PWM_AllignMode_t;

/**
 * @brief Enumeration for General Purpose Timer (GPT) PWM channels.
 *
 * This enumeration defines different PWM channels for GPT.
 */
typedef enum {
    TIM_Channel1,   /**< PWM Channel 1 */
    TIM_Channel2,   /**< PWM Channel 2 */
    TIM_Channel3,   /**< PWM Channel 3 */
    TIM_Channel4    /**< PWM Channel 4 */
} GPT_PWM_Channel_t;

/**
 * @brief Enumeration for General Purpose Timer (GPT) PWM modes.
 *
 * This enumeration defines different PWM modes for GPT.
 */
typedef enum {
    PWM_11 = 0b110,   /**< PWM mode 11 */
    PWM_22 = 0b111    /**< PWM mode 22 */
} GPT_PWM_Mode_t;

/**
 * @brief Enumeration for General Purpose Timer (GPT) clock sources.
 *
 * This enumeration defines different clock sources for GPT.
 */
typedef enum {
    TIM_CLK_SRC_INTERNAL,            /**< Internal clock source */
    TIM_CLK_SRC_EXTERNAL_MODE1,     /**< External clock source, mode 1 */
    TIM_CLK_SRC_EXTERNAL_MODE2      /**< External clock source, mode 2 */
} GPT_TIM_CLK_SRC_t;

/**
 * @brief Enumeration for General Purpose Timer (GPT) signal polarities.
 *
 * This enumeration defines signal polarities for GPT operations.
 */
typedef enum {
    Active_High,  /**< Active high signal polarity */
    Active_Low    /**< Active low signal polarity */
} GPT_TIM_POLARITY_t;
/**
 * @brief Enumeration for General Purpose Timer (GPT) edge types.
 *
 * This enumeration defines types of edges for GPT timing operations.
 */
typedef enum {
    Rising,   /**< Rising edge */
    Falling   /**< Falling edge */
} GPT_TIM_EDGE_t;
/**
 * @brief Configuration structure for General Purpose Timer (GPT) settings.
 *
 * This structure defines parameters required to configure the GPT module.
 */
typedef struct {
    u16 ARR;                            /**< Auto-Reload Register value */
    u16 Prescalar;                      /**< Prescaler value */
    GPT_CountDir_t GPT_DIR;             /**< GPT counting direction */
    GPT_PWM_AllignMode_t AllignMode;    /**< PWM alignment mode */
    GPT_CLKDiv_t CLK_Factor;            /**< GPT clock division factor */
    GPT_ArrBufferState_t ARB;           /**< ARR (Auto-Reload Register) buffer state */
    GPT_INTState_t INTState;            /**< GPT interrupt state */
} GPT_Config_t;
/**
 * @brief Configuration structure for General Purpose Timer (GPT) PWM settings.
 *
 * This structure defines parameters required to configure PWM (Pulse Width Modulation)
 * using a GPT for a specific channel.
 */
typedef struct {
    u16 ARR;                        /**< Auto-Reload Register value */
    GPT_PWM_Channel_t PWM_Channel;  /**< PWM channel */
    u16 Freq;                       /**< Frequency of the PWM signal */
    GPT_PWM_Mode_t PWM_Mode;        /**< Mode of PWM operation */
} GPT_PWM_Config_t;
/**
 * @brief Initializes and configures the General Purpose Timer (GPT) module.
 *
 * This function initializes and configures the specified GPT timer indicated by 'Copy_TIMx'
 * based on the provided GPT configuration 'Copy_GPT_Config'.
 *
 * @param[in] Copy_TIMx         The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[in] Copy_GPT_Config   Pointer to the configuration structure for GPT.
 *
 * @return Std_ReturnType
 *   - E_OK     : GPT initialization successful.
 *   - E_NOT_OK : Error occurred during GPT initialization (invalid timer or configuration).
 */
Std_ReturnType GPT_TIMx_init(u8 Copy_TIMx,GPT_Config_t* Copy_GPT_Config);
/**
 * @brief Sets the GPT timer to perform a busy wait for a specified number of ticks.
 *
 * This function configures the specified GPT timer indicated by 'Copy_TIMx'
 * to perform a busy wait for a specified number of ticks ('Copy_Ticks') based on
 * the specified tick type ('Copy_TickType').
 *
 * @param[in] Copy_TIMx       The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[in] Copy_Ticks      Number of ticks for the busy wait.
 * @param[in] Copy_TickType   Type of ticks to wait for (e.g., rising edge, falling edge, etc.).
 *
 * @return Std_ReturnType
 *   - E_OK     : GPT busy wait configured successfully.
 *   - E_NOT_OK : Error occurred during GPT configuration (invalid timer or parameters).
 */
Std_ReturnType GPT_TIMx_SetBusyWait(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType);
/**
 * @brief Sets the GPT timer for a single interval with a specified callback function.
 *
 * This function configures the specified GPT timer indicated by 'Copy_TIMx' to trigger
 * a single interval after a specified number of ticks ('Copy_Ticks') based on the specified
 * tick type ('Copy_TickType'). Upon completion of the interval, the provided callback function
 * ('Copy_voidpF') will be executed.
 *
 * @param[in] Copy_TIMx       The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[in] Copy_Ticks      Number of ticks for the interval.
 * @param[in] Copy_TickType   Type of ticks to wait for (e.g., rising edge, falling edge, etc.).
 * @param[in] Copy_voidpF     Pointer to the callback function to be executed after the interval.
 *
 * @return Std_ReturnType
 *   - E_OK     : GPT interval set successfully.
 *   - E_NOT_OK : Error occurred during GPT configuration (invalid timer or parameters).
 */
Std_ReturnType GPT_TIMx_SetIntervalSingle(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType, void (*Copy_voidpF)(void));
/**
 * @brief Sets the GPT timer for periodic intervals with a specified callback function.
 *
 * This function configures the specified GPT timer indicated by 'Copy_TIMx' to trigger
 * periodic intervals after a specified number of ticks ('Copy_Ticks') based on the specified
 * tick type ('Copy_TickType'). Upon completion of each interval, the provided callback function
 * ('Copy_voidpF') will be executed.
 *
 * @param[in] Copy_TIMx       The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[in] Copy_Ticks      Number of ticks for each periodic interval.
 * @param[in] Copy_TickType   Type of ticks to wait for (e.g., rising edge, falling edge, etc.).
 * @param[in] Copy_voidpF     Pointer to the callback function to be executed after each interval.
 *
 * @return Std_ReturnType
 *   - E_OK     : GPT periodic intervals set successfully.
 *   - E_NOT_OK : Error occurred during GPT configuration (invalid timer or parameters).
 */
Std_ReturnType GPT_TIMx_SetIntervalPeriodic(u8 Copy_TIMx,u16 Copy_Ticks , u16 Copy_TickType, void (*Copy_voidpF)(void));
/**
 * @brief Retrieves the remaining time of the GPT timer.
 *
 * This function retrieves the remaining time of the specified GPT timer ('Copy_TIMx') based on
 * the specified counting direction ('Copy_CountDir') and stores the remaining time in the
 * variable pointed to by 'Copy_Remaining'.
 *
 * @param[in]  Copy_TIMx      The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[in]  Copy_CountDir  Counting direction for the timer.
 * @param[out] Copy_Remaining Pointer to store the remaining time of the timer.
 *
 * @return Std_ReturnType
 *   - E_OK     : Remaining time retrieval successful.
 *   - E_NOT_OK : Error occurred during retrieval (invalid timer or parameters).
 */

Std_ReturnType GPT_TIMx_GetRemainingTime(u8 Copy_TIMx,GPT_CountDir_t Copy_CountDir , u16* Copy_Remaining);
/**
 * @brief Initializes and configures the General Purpose Timer (GPT) for PWM generation.
 *
 * This function initializes and configures the specified GPT timer indicated by 'Copy_TIMx'
 * for PWM (Pulse Width Modulation) generation based on the provided PWM configuration
 * 'Copy_PWM_Config'.
 *
 * @param[in] Copy_TIMx          The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[in] Copy_PWM_Config    Pointer to the configuration structure for PWM generation.
 *
 * @return Std_ReturnType
 *   - E_OK     : GPT PWM initialization successful.
 *   - E_NOT_OK : Error occurred during GPT PWM initialization (invalid timer or configuration).
 */
Std_ReturnType GPT_PWM_INIT(u8 Copy_TIMx,GPT_PWM_Config_t* Copy_PWM_Config);
/**
 * @brief Sets the duty cycle for a specific channel of the GPT timer configured for PWM.
 *
 * This function sets the duty cycle for a specific channel ('Copy_Channel') of the GPT timer
 * indicated by 'Copy_TIMx', which has been configured for PWM (Pulse Width Modulation).
 * The duty cycle value ('Copy_DutyCycle') determines the ratio of the signal's high time
 * to the total period. The duty cycle is set as a percentage value (0 to 100).
 *
 * @param[in] Copy_TIMx       The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[in] Copy_Channel    The specific channel for which the duty cycle is to be set.
 * @param[in] Copy_DutyCycle  Duty cycle value to set for the channel (0 to 100).
 *
 * @return Std_ReturnType
 *   - E_OK     : Duty cycle set successfully.
 *   - E_NOT_OK : Error occurred while setting the duty cycle or invalid parameters.
 */
Std_ReturnType GPT_PWM_SetDutyCycle(u8 Copy_TIMx,GPT_PWM_Channel_t Copy_Channel , u8 Copy_DutyCycle);
/**
 * @brief Deinitializes and stops PWM for a specific channel of the GPT timer.
 *
 * This function deinitializes and stops the PWM (Pulse Width Modulation) operation
 * for a specific channel ('Copy_Channel') of the GPT timer indicated by 'Copy_TIMx'.
 *
 * @param[in] Copy_TIMx       The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[in] Copy_Channel    The specific channel for which PWM is to be deinitialized.
 *
 * @return Std_ReturnType
 *   - E_OK     : PWM deinitialization successful.
 *   - E_NOT_OK : Error occurred during PWM deinitialization or invalid parameters.
 */
Std_ReturnType GPT_PWM_DEINIT(u8 Copy_TIMx,GPT_PWM_Channel_t Copy_Channel);
/**
 * @brief Retrieves the counter value of the GPT timer used for PWM.
 *
 * This function retrieves the current counter value of the GPT timer ('Copy_TIMx')
 * used for PWM (Pulse Width Modulation) and stores it in the variable pointed to by 'Copy_PWMValue'.
 *
 * @param[in]  Copy_TIMx      The identifier for the GPT timer (e.g., TIM1, TIM2, etc.).
 * @param[out] Copy_PWMValue  Pointer to store the current PWM counter value.
 *
 * @return Std_ReturnType
 *   - E_OK     : Counter value retrieval successful.
 *   - E_NOT_OK : Error occurred during retrieval or invalid parameters.
 */
Std_ReturnType GPT_PWM_GetCounterValue(u8 Copy_TIMx,u16* Copy_PWMValue);

void TIM1_UP_IRQHandler (void);
void TIM2_UP_IRQHandler (void);
void TIM3_UP_IRQHandler (void);
void TIM4_UP_IRQHandler (void);





#endif /* GPT_INTERFACE_H_ */