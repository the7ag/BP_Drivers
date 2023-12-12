/**
 * @brief This module contains functions for configuring the Nested Vectored Interrupt Controller (NVIC).
 *
 * @author Mohamed Ali Bayoumi
 * @date 20 OCT 2023
 * @version V01
 *
 * This module provides functions for enabling and disabling interrupts, setting interrupt priorities, and other
 * configuration options for the NVIC. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */

#ifndef MCAL_NVIC_PRIVATE_H_
#define MCAL_NVIC_PRIVATE_H_
/**
 * @defgroup NVIC_Registers NVIC Registers
 * @brief NVIC (Nested Vectored Interrupt Controller) Registers.
 * @{
 */
#define NVIC_BASE_ADDRESS   0xE000E100

/**
 * @brief NVIC ISER Registers.
 * @{
 */
#define NVIC_ISER0              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x000))))
#define NVIC_ISER1              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x004))))
#define NVIC_ISER2              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x008))))
/**
 * @brief NVIC ICER Registers.
 * @{
 */
#define NVIC_ICER0              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x080))))
#define NVIC_ICER1              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x084))))
#define NVIC_ICER2              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x088))))
/**
 * @brief NVIC ISPR Registers.
 * @{
 */
#define NVIC_ISPR0              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x100))))
#define NVIC_ISPR1              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x104))))
#define NVIC_ISPR2              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x108))))
/**
 * @brief NVIC ICPR Registers.
 * @{
 */
#define NVIC_ICPR0              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x180))))
#define NVIC_ICPR1              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x184))))
#define NVIC_ICPR2              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x188))))
/**
 * @brief NVIC IABR Registers.
 * @{
 */
#define NVIC_IABR0              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x200))))
#define NVIC_IABR1              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x204))))
#define NVIC_IABR2              (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x208))))
/** @} */

/**
 * @brief NVIC IPR Base Address
 */     
#define NVIC_IPR_Base_Address   (((volatile u32 *)((NVIC_BASE_ADDRESS) + (0x300))))
/**
 * @brief NVIC STIR Base Address
 */  
#define NVIC_STIR               (*((volatile u32 *)((NVIC_BASE_ADDRESS) + (0xE00))))
/**
 * @brief Priority Grouping Values
 * @{
 */
#define NVIC_16GROUP_0SUB       0x05FA0300U 
#define NVIC_8GROUP_2SUB        0x05FA0400U 
#define NVIC_4GROUP_4SUB        0x05FA0500U 
#define NVIC_2GROUP_8SUB        0x05FA0600U 
#define NVIC_0GROUP_16SUB       0x05FA0700U 

/**
 * @} (end of group NVIC_Registers)
 */
#endif /* MCAL_NVIC_PRIVATE_H_ */