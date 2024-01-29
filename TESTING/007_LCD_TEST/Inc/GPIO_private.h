/**
 * @brief This module contains functions for configuring and controlling General Purpose Input/Output (GPIO) pins.
 *
 * @author Mohamed Ali Bayoumi
 * @date    6 OCT 2023
 * @version V01
 *
 * This module provides functions for configuring the mode, speed, and pull-up/down resistors of GPIO pins,
 * as well as reading and writing their values. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */

#ifndef MCAL_GPIO_PRIVATE_H_
#define MCAL_GPIO_PRIVATE_H_

#define GPIO_BUS                RCC_APB2

#define GPIO_PORTA_BASE_ADDRESS  0x40010800U
#define GPIO_PORTB_BASE_ADDRESS  0x40010C00U
#define GPIO_PORTC_BASE_ADDRESS  0x40011000U
/*
#define GPIO_PORTD_BASE_ADDRESS  0x40011400U
#define GPIO_PORTE_BASE_ADDRESS  0x40011800U
#define GPIO_PORTF_BASE_ADDRESS  0x40011C00U
#define GPIO_PORTG_BASE_ADDRESS  0x40012000U
*/
/******************************************< REGISTERS ADDRESSES FOR PORT ******************************************/
typedef struct GPIO_REGISTERS
{
    u32 CRL;    /* Port configuration register low  Address offset: 0x00 */
    u32 CRH;    /* Port configuration register high Address offset: 0x04 */
    u32 IDR;    /* Port input data register Address offset: 0x08h */
    u32 ODR;    /* Port output data register Address offset: 0x0C */
    u32 BSRR;   /* Port bit set/reset register Address offset: 0x10 */
    u32 BRR;    /* Port bit reset register Address offset: 0x14 */
    u32 LCKR;   /* Port configuration lock register Address offset: 0x18 */
}GPIOx_t;

/******************************************< STRUCT FOR PORT ******************************************/

#define MCAL_GPIOA ( (GPIOx_t*) GPIO_PORTA_BASE_ADDRESS )
#define MCAL_GPIOB ( (GPIOx_t*) GPIO_PORTB_BASE_ADDRESS )
#define MCAL_GPIOC ( (GPIOx_t*) GPIO_PORTC_BASE_ADDRESS )
/*
#define MCAL_GPIOD ( (GPIOx_t*) GPIO_PORTD_BASE_ADDRESS )
#define MCAL_GPIOE ( (GPIOx_t*) GPIO_PORTE_BASE_ADDRESS )
#define MCAL_GPIOF ( (GPIOx_t*) GPIO_PORTF_BASE_ADDRESS )
#define MCAL_GPIOG ( (GPIOx_t*) GPIO_PORTG_BASE_ADDRESS )
*/

#define LCKK        16

#endif /* MCAL_GPIO_PRIVATE_H_ */