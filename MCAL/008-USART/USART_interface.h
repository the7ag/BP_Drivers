/**
 * @file USART_interface.h
 * @brief This file contains the interface for the USART (Universal Synchronous/Asynchronous Receiver/Transmitter) module.
 *
 * @copyright Copyright (c) 2023
 * 
 * This module provides functions for configuring and controlling USART communication in embedded systems. USART communication is commonly used for serial communication between microcontrollers and peripheral devices such as sensors, displays, and other microcontrollers.
 *
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 29 FEB 2024
 * @version V01
 * @author Mohamed Ali Bayoumi
 */
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "Std_Types.h" // Include necessary header for standard return types

#define USART_1           0
#define USART_2           1

// Function prototypes for USART operations

/**
 * @brief Initialize USART module with specified baud rate.
 *
 * @param Copy_baudRate The baud rate to configure USART with.
 * @param Copy_UARTx    The USART peripheral ID (e.g., USART_1 or USART_2).
 * @return Std_ReturnType Std_ReturnType indicating success or failure.
 */
Std_ReturnType USARTx_INIT(uint32_t Copy_baudRate, uint8_t Copy_UARTx);

/**
 * @brief Send a byte over USART.
 *
 * @param Copy_Byte    The byte to send.
 * @param Copy_UARTx   The USART peripheral ID (e.g., USART_1 or USART_2).
 * @return Std_ReturnType Std_ReturnType indicating success or failure.
 */
Std_ReturnType USARTx_SendByte(uint8_t Copy_Byte, uint8_t Copy_UARTx);

/**
 * @brief Receive a byte over USART.
 *
 * @param state           Pointer to a variable to store the status of the receive operation.
 * @param Recived_Byte    Pointer to a variable to store the received byte.
 * @param Copy_UARTx      The USART peripheral ID (e.g., USART_1 or USART_2).
 * @return Std_ReturnType Std_ReturnType indicating success or failure.
 */
Std_ReturnType USARTx_ReceiveByte(uint8_t *state, uint8_t *Recived_Byte, uint8_t Copy_UARTx);

/**
 * @brief Send a string over USART.
 *
 * @param STRINGToSend    Pointer to the string to send.
 * @param Copy_UARTx      The USART peripheral ID (e.g., USART_1 or USART_2).
 * @return Std_ReturnType Std_ReturnType indicating success or failure.
 */
Std_ReturnType USARTx_SendString(uint8_t *STRINGToSend, uint8_t Copy_UARTx);

/**
 * @brief Receive a string over USART.
 *
 * @param STRINGToReceive Pointer to a buffer to store the received string.
 * @param Copy_UARTx      The USART peripheral ID (e.g., USART_1 or USART_2).
 * @return Std_ReturnType Std_ReturnType indicating success or failure.
 */
Std_ReturnType USARTx_ReceiveString(uint8_t *STRINGToReceive, uint8_t Copy_UARTx);

#endif /* USART_INTERFACE_H */
