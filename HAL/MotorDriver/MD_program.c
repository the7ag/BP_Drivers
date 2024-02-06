/**
 * @file MD_program.c
 * @brief Public interface implementation for the US HAL drivers.
 *
 * This file implements the functions declared in the MD_interface.h header file.
 * It provides functionality for controlling motors, including stopping, moving, and mapping motor speeds.
 *
 * @copyright Copyright (c) 2024
 * 
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 06 Feb 2024
 * @version V01
 * @author Mohamed Ali Bayoumi
 */

/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"

/**************************************** MCAL *****************************************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPT_interface.h"
#include "GPT_private.h"

/**************************************** HAL *****************************************************/
#include "MD_interface.h"
#include "MD_private.h"
#include "MD_config.h"

/*====================================================   Start_FUNCTION   ====================================================*/

/**
 * @brief Stops the motors.
 *
 * This function stops the motors by disabling PWM signals and setting direction pins to neutral.
 *
 * @param[in] Copy_Pins Pointer to the motor pins configuration structure.
 * @retval Std_ReturnType Returns E_OK if the operation is successful, E_NOT_OK otherwise.
 */
Std_ReturnType HAL_MOTOR_STOP(MOTOR_t* Copy_Pins) {
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
    // Disable PWM signals for both motors
    MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->L_PWM_PIN, GPIO_LOW);
    MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->R_PWM_PIN, GPIO_LOW);

    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}

/**
 * @brief Moves the motors in a specified direction at specified speeds.
 *
 * This function moves the motors in the specified direction at the specified speeds using PWM signals.
 *
 * @param[in] Copy_Pins Pointer to the motor pins configuration structure.
 * @param[in] Copy_Dir Direction of motor movement (MOTOR_FORWARD or MOTOR_BACKWARD).
 * @param[in] Copy_Speed_L Speed of the left motor.
 * @param[in] Copy_Speed_R Speed of the right motor.
 * @retval Std_ReturnType Returns E_OK if the operation is successful, E_NOT_OK otherwise.
 */
Std_ReturnType HAL_MOTOR_MOVE(MOTOR_t *Copy_Pins ,u8 Copy_Dir, u16 Copy_Speed_L, u16 Copy_Speed_R) {
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    static u8 Local_PrevDir;

    // Ensure speed values are within range (0-100)
    if (Copy_Speed_L > 100) {
        Copy_Speed_L = 100;
    }
    if (Copy_Speed_R > 100) {
        Copy_Speed_R = 100;
    }

    // Set motor direction based on the provided direction
    if (Local_PrevDir != Copy_Dir) {
        switch (Copy_Dir) {
            case MOTOR_FORWARD:
                // Set forward direction for both motors
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->L_DIR_PIN_B, GPIO_LOW);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->R_DIR_PIN_B, GPIO_LOW);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->L_DIR_PIN_F, GPIO_HIGH);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->R_DIR_PIN_F, GPIO_HIGH);
                break;
            case MOTOR_BACKWARD:
                // Set backward direction for both motors
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->L_DIR_PIN_F, GPIO_LOW);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->R_DIR_PIN_F, GPIO_LOW);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->L_DIR_PIN_B, GPIO_HIGH);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->R_DIR_PIN_B, GPIO_HIGH);
                break;
            default:
                // Default to forward direction for both motors
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->L_DIR_PIN_B, GPIO_LOW);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->R_DIR_PIN_B, GPIO_LOW);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->L_DIR_PIN_F, GPIO_HIGH);
                MCAL_GPIO_SetPinValue(Copy_Pins->MOTOR_PORT, Copy_Pins->R_DIR_PIN_F, GPIO_HIGH);
                break;
        }
        Local_PrevDir = Copy_Dir;
    }

    // Adjust motor speeds if they are different from the current speeds
    if (TIM[1]->CCR2 != Copy_Speed_L || TIM[1]->CCR4 != Copy_Speed_R) {
        GPT_PWM_SetDutyCycle(TIM2, TIM_Channel2, Copy_Speed_L);
        GPT_PWM_SetDutyCycle(TIM2, TIM_Channel4, Copy_Speed_R);
    }

    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}

/**
 * @brief Maps an input value to a specified range.
 *
 * This function maps an input value to a specified output range using linear interpolation.
 *
 * @param[out] return Pointer to the variable to store the mapped value.
 * @param[in] Copy_Input Input value to be mapped.
 * @param[in] Copy_Min1 Minimum value of the input range.
 * @param[in] Copy_Max1 Maximum value of the input range.
 * @param[in] Copy_Min2 Minimum value of the output range.
 * @param[in] Copy_Max2 Maximum value of the output range.
 * @retval Std_ReturnType Returns E_OK if the operation is successful, E_NOT_OK otherwise.
 */
Std_ReturnType HAL_MOTOR_MAP(u16* return, u16 Copy_Input, u16 Copy_Min1, u16 Copy_Max1, u16 Copy_Min2, u16 Copy_Max2) {
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    u16 Local_Range1Diff, Local_Range2Diff, Local_Output;

    // Calculate the differences between input and output ranges
    Local_Range1Diff = Copy_Max1 - Copy_Min1;
    Local_Range2Diff = Copy_Max2 - Copy_Min2;

    // Perform linear interpolation to map input value to output range
    Local_Output = (((Copy_Input - Copy_Min1) * Local_Range2Diff) / Local_Range1Diff) + Copy_Min2;

    // Store the mapped output value
    *return = Local_Output;

    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
