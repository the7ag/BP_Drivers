/**
 **********************************************************************************************************************************
 * @brief This module contains functions for configuring and controlling General Purpose Input/Output (GPIO) pins.
 *
 * @author Mohamed Ali Bayoumi
 * @date    6 OCT 2023
 * @version V02
 ***********************************************************************************************************************************
 * This module provides functions for configuring the mode, speed, and pull-up/down resistors of GPIO pins,
 * as well as reading and writing their values. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 **********************************************************************************************************************************
 */

#ifndef MCAL_GPIO_INTERFACE_H_
#define MCAL_GPIO_INTERFACE_H_


/***********************************< THE AVAILABLE PORTS IN STM32F103C8 ***********************************/
#define GPIO_PORTA              0
#define GPIO_PORTB              1
#define GPIO_PORTC              2
/***********************************< THE AVAILABLE PINS IN STM32F103C8 ***********************************/
#define GPIO_PIN0               0
#define GPIO_PIN1               1
#define GPIO_PIN2               2
#define GPIO_PIN3               3
#define GPIO_PIN4               4
#define GPIO_PIN5               5
#define GPIO_PIN6               6
#define GPIO_PIN7               7
#define GPIO_PIN8               8
#define GPIO_PIN9               9
#define GPIO_PIN10              10
#define GPIO_PIN11              11
#define GPIO_PIN12              12
#define GPIO_PIN13              13
#define GPIO_PIN14              14
#define GPIO_PIN15              15
/***********************************< PORT BIT CONFIGURATION OPTIONS ***********************************/

#define GPIO_INPUT_ANALOG_MODE              0b0000
#define GPIO_INPUT_FLOATING_MODE            0b0100
#define GPIO_INPUT_PULL_UP_MODE             0b1000
#define GPIO_INPUT_PULL_DOWN_MODE           0b1000

#define GPIO_OUTPUT_LOW_SPEED_PUSHPULL      0b0001
#define GPIO_OUTPUT_LOW_SPEED_OPEN_DRAIN    0b0101
#define GPIO_OUTPUT_LOW_SPEED_AF_PP         0b1001
#define GPIO_OUTPUT_LOW_SPEED_AF_OD         0b1101
#define GPIO_OUTPUT_MID_SPEED_PUSHPULL      0b0010
#define GPIO_OUTPUT_MID_SPEED_OPEN_DRAIN    0b0110
#define GPIO_OUTPUT_MID_SPEED_AF_PP         0b1010
#define GPIO_OUTPUT_MID_SPEED_AF_OD         0b1110
#define GPIO_OUTPUT_HIGH_SPEED_PUSHPULL     0b0011
#define GPIO_OUTPUT_HIGH_SPEED_OPEN_DRAIN   0b0111
#define GPIO_OUTPUT_HIGH_SPEED_AF_PP        0b1011
#define GPIO_OUTPUT_HIGH_SPEED_AF_OD        0b1111

/***********************************< THE AVAILABLE VALUES FOR OUTPUT ***********************************/

#define GPIO_LOW                                  0
#define GPIO_HIGH                                 1
      /***********************************< THE AVAILABLE VALUES FOR LOCK ***********************************/
            
#define GPIO_UNLOCKED                             0
#define GPIO_LOCKED                               1
/***********************************< FUNCTIONS PROTOTYPES AND DESCRIPTION ***********************************/
/**
 * @brief Configures the direction (input or output) and mode of a specific pin of a specific port in a microcontroller.
 *
 * This function sets the direction (input or output) and mode of a specific pin of a specific port in a microcontroller by configuring the corresponding pin configuration register.
 *
 * @param[in] Copy_PortID An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: GPIOA, GPIOB, or GPIOC.
 * @param[in] Copy_PinID An 8-bit unsigned integer that represents the pin number that the function will configure. This parameter should be one of the following options: GPIO_PIN0, GPIO_PIN1, GPIO_PIN2, GPIO_PIN3, GPIO_PIN4, GPIO_PIN5, GPIO_PIN6, GPIO_PIN7, GPIO_PIN8, GPIO_PIN9, GPIO_PIN10, GPIO_PIN11, GPIO_PIN12, GPIO_PIN13, GPIO_PIN14, or GPIO_PIN15.
 * @param[in] Copy_PinMode An 8-bit unsigned integer that represents the mode of the pin that the function will configure. This parameter should be one of the following options:
 *            - GPIO_INPUT_ANALOG_MODE for analog input mode
 *            - GPIO_INPUT_FLOATING_MODE for floating input mode
 *            - GPIO_INPUT_PULL_DOWN_MODE for input mode with pull-down configuration
 *            - GPIO_INPUT_PULL_UP_MODE for input mode with pull-up configuration
 *            - GPIO_OUTPUT_MID_SPEED_PUSHPULL for output mode with push-pull configuration and maximum output speed of 10 MHz
 *            - GPIO_OUTPUT_MID_SPEED_OPEN_DRAIN for output mode with open-drain configuration and maximum output speed of 10 MHz
 *            - GPIO_OUTPUT_MID_SPEED_AF_PP for alternative function mode with push-pull configuration and maximum output speed of 10 MHz
 *            - GPIO_OUTPUT_LOW_SPEED_AF_OD for alternative function mode with open-drain configuration and maximum output speed of 10 MHz
 *            - GPIO_OUTPUT_LOW_SPEED_PUSHPULL for output mode with push-pull configuration and maximum output speed of 2 MHz
 *            - GPIO_OUTPUT_LOW_SPEED_OPEN_DRAIN for output mode with open-drain configuration and maximum output speed of 2 MHz
 *            - GPIO_OUTPUT_LOW_SPEED_AF_PP for alternative function mode with push-pull configuration and maximum output speed of 2 MHz
 *            - GPIO_OUTPUT_LOW_SPEED_AF_OD for alternative function mode with open-drain configuration and maximum output speed of 2 MHz
 *            - GPIO_OUTPUT_HIGH_SPEED_PUSHPULL for output mode with push-pull configuration and maximum output speed of 50 MHz
 *            - GPIO_OUTPUT_HIGH_SPEED_OPEN_DRAIN for output mode with open-drain configuration and maximum output speed of 50 MHz
 *            - GPIO_OUTPUT_HIGH_SPEED_AF_PP for alternative function mode with push-pull configuration and maximum output speed of 50 MHz
 *            - GPIO_OUTPUT_HIGH_SPEED_AF_OD for alternative function mode with open-drain configuration and maximum output speed of 50 MHz
 *
 * @retval Std_ReturnType returns E_OK if function ok E_NOK if function error happens
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the pin configuration registers of each port are named GPIOx_CRL_R (for pins 0 to 7) and GPIOx_CRH_R (for pins 8 to 15) where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To configure pin 5 of port A as an output pin with push-pull configuration and maximum output speed of 50 MHz, the following code can be used:
 *      @code
 *      MCAL_GPIO_SetPinMode(GPIOA, GPIO_PIN5, GPIO_OUTPUT_HIGH_SPEED_PUSHPULL);
 *      @endcode
 */
Std_ReturnType MCAL_GPIO_SetPinMode(u8 Copy_PortID , u8 Copy_PinID , u8 Copy_PinMode);
/**
 * @brief Sets the value of a specific pin of a specific port in a microcontroller.
 *
 * This function sets the value (high or low) of a specific pin of a specific port in a microcontroller by writing to the corresponding output data register.
 *
 * @param[in] Copy_PortID An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: GPIOA, GPIOB, or GPIOC.
 * @param[in] Copy_PinID An 8-bit unsigned integer that represents the pin number that the function will set the value of. This parameter should be one of the following options: GPIO_PIN0, GPIO_PIN1, GPIO_PIN2, GPIO_PIN3, GPIO_PIN4, GPIO_PIN5, GPIO_PIN6, GPIO_PIN7, GPIO_PIN8, GPIO_PIN9, GPIO_PIN10, GPIO_PIN11, GPIO_PIN12, GPIO_PIN13, GPIO_PIN14, or GPIO_PIN15.
 * @param[in] Copy_PinValue An 8-bit unsigned integer that represents the value that the function will set the pin to. This parameter should be one of the following options:
 *            - GPIO_HIGH to set the pin to high voltage level (logic 1)
 *            - GPIO_LOW to set the pin to low voltage level (logic 0)
 *
 * @retval Std_ReturnType returns E_OK if function ok E_NOK if function error happens
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the output data registers of each port are named GPIOx_ODR_R where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To set pin 5 of port B to high voltage level, the following code can be used:
 *      @code
 *      MCAL_GPIO_SetPinValue(GPIOB, GPIO_PIN5, GPIO_HIGH);
 *      @endcode
 */
Std_ReturnType MCAL_GPIO_SetPinValue(u8 Copy_PortID , u8 Copy_PinID , u8 Copy_PinValue);
/**
 * @brief Gets the value of a specific pin of a specific port in a microcontroller.
 *
 * This function gets the value (high or low) of a specific pin of a specific port in a microcontroller by reading from the corresponding input data register.
 *
 * @param[in] Copy_PortID An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: GPIOA, GPIOB, or GPIOC.
 * @param[in] Copy_PinID An 8-bit unsigned integer that represents the pin number that the function will get the value of. This parameter should be one of the following options: GPIO_PIN0, GPIO_PIN1, GPIO_PIN2, GPIO_PIN3, GPIO_PIN4, GPIO_PIN5, GPIO_PIN6, GPIO_PIN7, GPIO_PIN8, GPIO_PIN9, GPIO_PIN10, GPIO_PIN11, GPIO_PIN12, GPIO_PIN13, GPIO_PIN14, or GPIO_PIN15.
 * @param[in] Copy_PinReturnValue An 8-bit unsigned integer pointerrepresents the value of the specified pin. This parameter should be one of the following options:
 *            - 1 to indicate that the pin is at high voltage level (logic 1)
 *            - 0 to indicate that the pin is at low voltage level (logic 0)

 * @retval Std_ReturnType returns E_OK if function ok E_NOK if function error happens
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the input data registers of each port are named GPIOx_IDR_R where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To get the value of pin 3 of port A, the following code can be used:
 *      @code
 *      u8 PinValue;
 *      MCAL_GPIO_GetPinValue(GPIOA, GPIO_PIN3 , &PinValue);
 *      @endcode
 */
Std_ReturnType MCAL_GPIO_GetPinValue(u8 Copy_PortID , u8 Copy_PinID , u8 *Copy_PinReturnValue);
/**
 * @brief Sets the value of a specific pin of a specific port in a microcontroller.
 *
 * This function sets the value (high ) of a specific pin of a specific port in a microcontroller by writing to the corresponding BSR register.
 *
 * @param[in] Copy_PortID An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: GPIOA, GPIOB, or GPIOC.
 * @param[in] Copy_PinID An 8-bit unsigned integer that represents the pin number that the function will set the value of. This parameter should be one of the following options: GPIO_PIN0, GPIO_PIN1, GPIO_PIN2, GPIO_PIN3, GPIO_PIN4, GPIO_PIN5, GPIO_PIN6, GPIO_PIN7, GPIO_PIN8, GPIO_PIN9, GPIO_PIN10, GPIO_PIN11, GPIO_PIN12, GPIO_PIN13, GPIO_PIN14, or GPIO_PIN15.
 *
 * @retval Std_ReturnType returns E_OK if function ok E_NOK if function error happens
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the output data registers of each port are named GPIOx_ODR_R where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To set pin 5 of port B to high voltage level, the following code can be used:
 *      @code
 *      MCAL_GPIO_AtomicSetPin(GPIOB, GPIO_PIN5);
 *      @endcode
 */
Std_ReturnType MCAL_GPIO_AtomicSetPin(u8 Copy_PortID , u8 Copy_PinID );
/**
 * @brief Clears the value of a specific pin of a specific port in a microcontroller.
 *
 * This function Clears the value (LOW) of a specific pin of a specific port in a microcontroller by writing to the corresponding BSR register.
 *
 * @param[in] Copy_PortID An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: GPIOA, GPIOB, or GPIOC.
 * @param[in] Copy_PinID An 8-bit unsigned integer that represents the pin number that the function will set the value of. This parameter should be one of the following options: GPIO_PIN0, GPIO_PIN1, GPIO_PIN2, GPIO_PIN3, GPIO_PIN4, GPIO_PIN5, GPIO_PIN6, GPIO_PIN7, GPIO_PIN8, GPIO_PIN9, GPIO_PIN10, GPIO_PIN11, GPIO_PIN12, GPIO_PIN13, GPIO_PIN14, or GPIO_PIN15.
 *
 * @retval Std_ReturnType returns E_OK if function ok E_NOK if function error happens
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the output data registers of each port are named GPIOx_ODR_R where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To clear pin 5 of port B to high voltage level, the following code can be used:
 *      @code
 *      MCAL_GPIO_AtomicResetPin(GPIOB, GPIO_PIN5);
 *      @endcode
 */
Std_ReturnType MCAL_GPIO_AtomicResetPin(u8 Copy_PortID , u8 Copy_PinID );
/**
 * @brief Locks the pin configration of a spacific pin
 *
 * This function locks the the config register for a spacific pin form changing during runtime
 *
 * @param[in] Copy_PortID An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: GPIOA, GPIOB, or GPIOC.
 * @param[in] Copy_PinID An 8-bit unsigned integer that represents the pin number that the function will set the value of. This parameter should be one of the following options: GPIO_PIN0, GPIO_PIN1, GPIO_PIN2, GPIO_PIN3, GPIO_PIN4, GPIO_PIN5, GPIO_PIN6, GPIO_PIN7, GPIO_PIN8, GPIO_PIN9, GPIO_PIN10, GPIO_PIN11, GPIO_PIN12, GPIO_PIN13, GPIO_PIN14, or GPIO_PIN15.
 *
 * @retval Std_ReturnType returns E_OK if function ok E_NOK if function error happens
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the output data registers of each port are named GPIOx_ODR_R where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To lock a spacific pin config
 *      @code
 *      MCAL_GPIO_LCKPin(GPIOB, GPIO_PIN5);
 *      @endcode
 */
Std_ReturnType MCAL_GPIO_LCKPin(u8 Copy_PortID , u8 Copy_PinID ,u8 Copy_PinState);


#endif /* MCAL_GPIO_INTERFACE_H_ */
