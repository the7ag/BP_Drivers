/**
 * @file USART_private.h
 * @brief This file contains the private interface for the USART (Universal Synchronous/Asynchronous Receiver/Transmitter) module.
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
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct 
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;
}USART_t;

#define USART1 ((volatile USART_t*)0x40013800)
#define USART2 ((volatile USART_t*)0x40004400)

#define USART1_ID           0
#define USART2_ID           1

#define USART_1_STOP_BIT    0b00
#define USART_2_STOP_BIT    0b10

#define USART_DISABLED      0
#define USART_ENABLED       1


#define USART_8_DATA_BITS   0
#define USART_9_DATA_BITS   2


u16 calcBRRReg(u32 Copy_baudRate,u8 Copy_UARTx);


#endif /* USART_PRIVATE_H */