/**
 * @file USART_interface.h
 * @brief This file contains the INTERFACE for the USART (Universal Synchronous/Asynchronous Receiver/Transmitter) module.
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
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

Std_ReturnType USART1_INIT(u32 Copy_baudRate);
Std_ReturnType USART2_INIT(u32 Copy_baudRate);

Std_ReturnType USART1_SendByte(u8 Copy_Byte);
Std_ReturnType USART2_SendByte(u8 Copy_Byte);

Std_ReturnType USART1_ReceiveByte(u8* Buffer,u8* Recived_Byte);
Std_ReturnType USART2_ReceiveByte(u8* Buffer,u8* Recived_Byte);

Std_ReturnType USART1_SendString(u8* STRINGToSend);
Std_ReturnType USART2_SendString(u8* STRINGToSend);

Std_ReturnType USART1_ReceiveString(u8* STRINGToReceive);
Std_ReturnType USART2_ReceiveString(u8* STRINGToReceive);

#endif /* USART_INTERFACE_H */