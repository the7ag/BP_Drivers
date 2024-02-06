/**
 * @file MD_interface.h
 * @brief Public interface for the US HAL drivers.
 *
 * This header file defines the public interface for the US HAL drivers,
 * facilitating the integration and utilization of ultrasonic sensors in embedded systems.
 * It includes functions for controlling motors, such as stopping, moving, and mapping motor speeds.
 *
 * @copyright Copyright (c) 2024
 * 
 * @note This module is designed for ARM Cortex-M processors and may not be compatible with other architectures.
 *
 * @date 06 Feb 2024
 * @version V01
 * @author Mohamed Ali Bayoumi
 */

#ifndef MD_INTERFACE_H_
#define MD_INTERFACE_H_

#include "STD_TYPES.h"

/**
 * @brief Structure representing motor pins configuration.
 *
 * This structure defines the configuration for motor pins, including direction pins and PWM pins.
 */
typedef struct {
    u8 R_DIR_PIN_F : 4; // Right motor forward direction pin
    u8 L_DIR_PIN_F : 4; // Left motor forward direction pin
    u8 R_DIR_PIN_B : 4; // Right motor backward direction pin
    u8 L_DIR_PIN_B : 4; // Left motor backward direction pin
    u8 R_PWM_PIN   : 4; // Right motor PWM pin
    u8 L_PWM_PIN   : 4; // Left motor PWM pin
    u8 MOTOR_PORT  : 2; // Motor port identifier
} MOTOR_t;

#define MOTOR1  1 // Motor 1 identifier
#define MOTOR2  2 // Motor 2 identifier

#define MOTOR_BACKWARD  1 // Motor backward direction identifier
#define MOTOR_FORWARD   2 // Motor forward direction identifier

/**
 * @brief Stops the motors.
 *
 * This function stops the motors by disabling PWM signals and setting direction pins to neutral.
 *
 * @param[in] Copy_Pins Pointer to the motor pins configuration structure.
 * @retval Std_ReturnType Returns E_OK if the operation is successful, E_NOT_OK otherwise.
 */
Std_ReturnType HAL_MOTOR_STOP(MOTOR_t* Copy_Pins);

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
Std_ReturnType HAL_MOTOR_MOVE(MOTOR_t *Copy_Pins ,u8 Copy_Dir, u16 Copy_Speed_L, u16 Copy_Speed_R);

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
Std_ReturnType HAL_MOTOR_MAP(u16* return, u16 Copy_Input, u16 Copy_Min1, u16 Copy_Max1, u16 Copy_Min2, u16 Copy_Max2);

#endif /* MD_INTERFACE_H_ */
