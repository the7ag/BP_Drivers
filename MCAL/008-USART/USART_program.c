/**
 * @file USART_program.c
 * @brief This file contains the program for the USART (Universal Synchronous/Asynchronous Receiver/Transmitter) module.
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
/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"
/**************************************** MCAL *****************************************************/
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

Std_ReturnType USARTx_INIT(u32 Copy_baudRate,u8 Copy_UARTx)
{
    switch (Copy_UARTx)
    {
    case USART_1:
        USART1->CR1=(
            USART1_RECEIVER_ENABLE                        <<  2|
            USART1_TRANSMITTER_ENABLE                     <<  3|
            USART1_RXNE_INTERRUPT_ENABLE                  <<  5|
            USART1_TRANSMISSION_COMPLETE_INTERRUPT_ENABLE <<  6|
            USART1_TXE_INTERRUPT_ENABLE                   <<  7|
            USART1_PARITY_SELECTION                       <<  9|
            USART1_PARITY_CONTROL_ENABLE                  << 10|
            USART1_WORD_LENGTH                            << 12
        );
        MOD_2BIT(USART1->CR2,12,USART1_STOP_BITS);
        USART1->BRR = calcBRRReg(Copy_baudRate,USART1_ID);
        USART1->SR = 0;
        SET_BIT(USART1->CR1 , 13);
        break;
    case USART_2:
            USART2->CR1=(
            USART2_RECEIVER_ENABLE                        <<  2|
            USART2_TRANSMITTER_ENABLE                     <<  3|
            USART2_RXNE_INTERRUPT_ENABLE                  <<  5|
            USART2_TRANSMISSION_COMPLETE_INTERRUPT_ENABLE <<  6|
            USART2_TXE_INTERRUPT_ENABLE                   <<  7|
            USART2_PARITY_SELECTION                       <<  9|
            USART2_PARITY_CONTROL_ENABLE                  << 10|
            USART2_WORD_LENGTH                            << 12
        );
        MOD_2BIT(USART2->CR2,12,USART2_STOP_BITS);
        USART2->BRR = calcBRRReg(Copy_baudRate,USART2_ID);
        USART2->SR = 0;
        SET_BIT(USART2->CR1 , 13);
        break;
    default: 
        #error "Enter Correct USART ID"
        break;
    }
}

Std_ReturnType USARTx_SendByte(u8 Copy_Byte,u8 Copy_UARTx)
{
    switch (Copy_UARTx)
    {
    case USART_1:
        USART1->DR=Copy_Byte;
        while(GET_BIT(USART1->SR,6)==0);
        break;
    case USART_2:
        USART2->DR=Copy_Byte;
        while(GET_BIT(USART2->SR,6)==0);
        break;
    default: 
        #error "Enter Correct USART ID"
        break;
    }
}

Std_ReturnType USARTx_ReceiveByte(u8* state,u8* Recived_Byte,u8 Copy_UARTx)
{
    u8 Local_dataAvailable=1;
    switch (Copy_UARTx)
    {
    case USART_1:
        if((GET_BIT((USART1->SR),5)) == 1)
        {
            *Recived_Byte=((u8)USART1->DR);
        }
        else
        {
            Local_dataAvailable=0;
        }
        *state =Local_dataAvailable;
        break;
    case USART_2:
        if((GET_BIT((USART2->SR),5)) == 1)
        {
            *Recived_Byte=((u8)USART2->DR);
        }
        else
        {
            Local_dataAvailable=0;
        }
        *state =Local_dataAvailable;
        break;
    default: 
        #error "Enter Correct USART ID"
        break;
    }
}


Std_ReturnType USARTx_SendString(u8* STRINGToSend,u8 Copy_UARTx)
{
    u8 Local_index=0;
    switch (Copy_UARTx)
    {
    case USART_1:
        while(1)
        {
            USART1->DR=STRINGToSend[Local_index];
            while((GET_BIT((USART1->SR),7)) == 0);
            if(STRINGToSend[Local_index]=='\0')
            {
                break;
            }
            else
            {
                Local_index++;
            }
        }
        while(GET_BIT(USART1->SR,6)==0);
        break;
    case USART_2:
        while(1)
        {
            USART2->DR=STRINGToSend[Local_index];
            while((GET_BIT((USART2->SR),7)) == 0);
            if(STRINGToSend[Local_index]=='\0')
            {
                break;
            }
            else
            {
                Local_index++;
            }
        }
        while(GET_BIT(USART2->SR,6)==0);
        break;
    default: 
        #error "Enter Correct USART ID"
        break;
    }
}

Std_ReturnType USARTx_ReceiveString(u8* STRINGToReceive,u8 Copy_UARTx)
{
    u8 Local_index=0,Local_byte,Local_state;
    switch (Copy_UARTx)
    {
    case USART_1:
        USARTx_ReceiveByte(&Local_state,&Local_byte,USART_1);
        if(Local_state==1)
        {
            STRINGToReceive[Local_index]=Local_byte;
        }
        while(STRINGToReceive[Local_index] !='\0' &&   STRINGToReceive[Local_index] != '#')
        {
            Local_index++;
            Local_byte=0;
            while(Local_byte==0)
            {
                USARTx_ReceiveByte(&Local_state,&Local_byte,USART_1);
            }
            STRINGToReceive[Local_index]=Local_byte;
        }
        STRINGToReceive[Local_index]='\0';
        break;
    case USART_2:
        USARTx_ReceiveByte(&Local_state,&Local_byte,USART_2);
        if(Local_state == 1)
        {
            STRINGToReceive[Local_index]=Local_byte;
        }
        while(STRINGToReceive[Local_index] !='\0' &&   STRINGToReceive[Local_index] != '#')
        {
            Local_index++;
            Local_byte=0;
            while(Local_byte == 0)
            {
                USARTx_ReceiveByte(&Local_state,&Local_byte,USART_2);
            }
            STRINGToReceive[Local_index]=Local_byte;
        }
        STRINGToReceive[Local_index]='\0';
        break;
    default: 
        #error "Enter Correct USART ID"
        break;
    }
}

u16 calcBRRReg(u32 Copy_baudRate,u8 Copy_UARTx)
{
    uint16 mantissa;
    float32 fraction, div;
    
    /* Calculate the divisor based on the system clock and baud rate */
    switch(USARTX)
    {
        case USART1_ID:
            div = RCC_APB2_CLK_FRQ / (float32)(baudRate << 4); //peripheral clock for USART1
        break;

        case USART2_ID:
            div = RCC_APB1_CLK_FRQ / (float32)(baudRate << 4); //peripheral clock for USART2
        break;
    }
    /* Extract the integer part of the divisor as the mantissa */
    mantissa = div;
    
    /* Extract the fractional part of the divisor as the fraction and round it to the nearest integer */
    fraction = (uint32)((div - mantissa) * 16 + 0.5);
    
    /* Add the integer part of the fraction to the mantissa and adjust the fraction for the BRR register format */
    mantissa += ((uint32)fraction >> 4);
    fraction  =  (uint32)fraction & 0xf;
    
    /* Combine the mantissa and fraction into the BRR register value and return it */
    return ((uint16)((mantissa << 4) | (uint32)fraction));
}