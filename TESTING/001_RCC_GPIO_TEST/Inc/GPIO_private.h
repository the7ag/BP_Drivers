/***************************************************************************************************/
/************************* Author  : Mohamed Ali Bayoumi    ****************************************/
/************************* Date    : 6/10/2023              ****************************************/
/************************* Version : 0.1                    ****************************************/
/************************* MODULE  : MCAL_GPIO_private.h    ****************************************/
/***************************************************************************************************/

#ifndef MCAL_GPIO_PRIVATE_H_
#define MCAL_GPIO_PRIVATE_H_

#define GPIO_BUS                RCC_APB2

#define GPIO_PORTA_BASE_ADDRESS  0x40010800U
#define GPIO_PORTB_BASE_ADDRESS  0x40010C00U
#define GPIO_PORTC_BASE_ADDRESS  0x40011000U

#define GPIO_PORTD_BASE_ADDRESS  0x40011400U
#define GPIO_PORTE_BASE_ADDRESS  0x40011800U
#define GPIO_PORTF_BASE_ADDRESS  0x40011C00U
#define GPIO_PORTG_BASE_ADDRESS  0x40012000U

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

#define MCAL_GPIOA ( (GPIOx_t*) GPIO_PORTA_BASE_ADDRESS )
#define MCAL_GPIOB ( (GPIOx_t*) GPIO_PORTB_BASE_ADDRESS )
#define MCAL_GPIOC ( (GPIOx_t*) GPIO_PORTC_BASE_ADDRESS )
#define MCAL_GPIOD ( (GPIOx_t*) GPIO_PORTD_BASE_ADDRESS )
#define MCAL_GPIOE ( (GPIOx_t*) GPIO_PORTE_BASE_ADDRESS )
#define MCAL_GPIOF ( (GPIOx_t*) GPIO_PORTF_BASE_ADDRESS )
#define MCAL_GPIOG ( (GPIOx_t*) GPIO_PORTG_BASE_ADDRESS )

#define LCKK        16

#endif /* MCAL_GPIO_PRIVATE_H_ */