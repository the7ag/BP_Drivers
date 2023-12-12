/**
 * @brief This module contains functions for configuring the Alternative Function Input/Output (AFIO) peripheral.
 *
 * @author Mohamed Ali Bayoumi
 * @date 27 OCT 2023
 * @version V01
 *
 * This module provides functions for configuring the remap and event output options of certain GPIO pins using the AFIO
 * peripheral. It is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

#define AFIO_EXTI0					0     
#define AFIO_EXTI1					1     
#define AFIO_EXTI2					2     
#define AFIO_EXTI3					3     
#define AFIO_EXTI4					4     
#define AFIO_EXTI5					5     
#define AFIO_EXTI6					6     
#define AFIO_EXTI7					7     
#define AFIO_EXTI8					8     
#define AFIO_EXTI9					9     
#define AFIO_EXTI10 				10    
#define AFIO_EXTI11 				11    
#define AFIO_EXTI12 				12    
#define AFIO_EXTI13 				13    
#define AFIO_EXTI14 				14    
#define AFIO_EXTI15				    15   

#define AFIO_GPIO_NONE              ((INVALID_VALUE)-1)
#define AFIO_GPIOA                  0
#define AFIO_GPIOB                  1
#define AFIO_GPIOC                  2


/**
 * @brief Configures EXTI (External Interrupt) line mapping for a specific GPIO port.
 *
 * This function maps a specific GPIO pin to an EXTI line by configuring the EXTI
 * control registers. EXTI lines are used to trigger external interrupts based on
 * GPIO pin events.
 *
 * @param[in] Copy_Line The EXTI line number (0 to 15) to configure.
 * @param[in] Copy_PortMap The GPIO port mapping configuration (0, 1, or 2) for the EXTI line.
 *
 * @note This function should be called to configure EXTI mapping for GPIO pins that will
 *       trigger external interrupts.
 *
 * @return Std_ReturnType E_OK if the configuration is successful, E_NOT_OK otherwise.
 *
 * @code
 * /// Example usage:
 * /// Configure EXTI line 4 to use GPIO port B mapping.
 * Std_ReturnType result = MCAL_AFIO_SetEXTIConfiguration(AFIO_EXTI14, AFIO_GPIOA);
 * if (result == E_OK) {
 *     /// Configuration successful
 * } else {
 *     /// Configuration failed
 * }
 * @endcode
 */
Std_ReturnType MCAL_AFIO_SetEXTIConfigration(u8 Copy_Line , u8 Copy_PortMap);

#endif /* AFIO_INTERFACE_H_ */