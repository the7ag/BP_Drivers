/**
 * @file USART_program.c
 * @brief This file contains the program for the USART (Universal Synchronous/Asynchronous Receiver/Transmitter) module.
 *
 * @copyright Copyright (c) 2023
 * 
 * This module provides low-level functions for configuring and controlling USART communication in embedded systems. USART communication is commonly used for serial communication between microcontrollers and peripheral devices such as sensors, displays, and other microcontrollers.
 *
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 29 FEB 2024
 * @version V01
 * @author Mohamed Ali Bayoumi
 */
/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"
/**************************************** MCAL *****************************************************/
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"