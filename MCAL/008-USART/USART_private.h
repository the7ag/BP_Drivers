/**
 * @file USART_private.h
 * @brief This file contains the private interface for the USART (Universal Synchronous/Asynchronous Receiver/Transmitter) module.
 *
 * @copyright Copyright (c) 2023
 * 
 * This module provides low-level functions and data structures for configuring and controlling USART communication in embedded systems. USART communication is commonly used for serial communication between microcontrollers and peripheral devices such as sensors, displays, and other microcontrollers.
 *
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 29 FEB 2024
 * @version V01
 * @author Mohamed Ali Bayoumi
 */

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

// Structure representing the USART registers
typedef struct 
{
    volatile uint32_t SR;   // Status register
    volatile uint32_t DR;   // Data register
    volatile uint32_t BRR;  // Baud rate register
    volatile uint32_t CR1;  // Control register 1
    volatile uint32_t CR2;  // Control register 2
    volatile uint32_t CR3;  // Control register 3
    volatile uint32_t GTPR; // Guard time and prescaler register
} USART_t;

// Base addresses for USART peripherals
#define USART1 ((volatile USART_t*)0x40013800)
#define USART2 ((volatile USART_t*)0x40004400)

// IDs for USART peripherals
#define USART1_ID           0
#define USART2_ID           1

// Constants for stop bit configuration
#define USART_1_STOP_BIT    0b00
#define USART_2_STOP_BIT    0b10

// Constants for USART enable/disable
#define USART_DISABLED      0
#define USART_ENABLED       1

// Constants for data bit configuration
#define USART_8_DATA_BITS   0
#define USART_9_DATA_BITS   2

// Function prototype for calculating the BRR register value
uint16_t calcBRRReg(uint32_t Copy_baudRate, uint8_t Copy_UARTx);

#endif /* USART_PRIVATE_H */
