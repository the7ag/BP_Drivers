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
/**
 * @defgroup AFIO_Remap_Options AFIO Remap Options
 * @{
 */

/**
 * @brief Enumeration of AFIO remap configuration options.
 *
 * This enumeration defines different remap configurations for the AFIO peripheral.
 * Users can select a configuration that suits their needs and customize pin assignments.
 * The SWJ_CFG value and pin status are provided for each configuration.
 *
 * @note Users should select one of these options when configuring the AFIO remap settings.
 * 
 * @note User options include:
 *                      - AFIO_REMAP_NONE: No remap (default).
 *                      - AFIO_REMAP_FULL: Full SWJ (JTAG-DP + SW-DP) but without NJTRST.
 *                      - AFIO_REMAP_PARTIAL: JTAG-DP Disabled and SW-DP Enabled.
 *                      - AFIO_REMAP_CUSTOM: Custom remap (user-defined).
 *
 * @note Pin Availability for Each Configuration:
 *                      - AFIO_REMAP_NONE:
 *                            - PA13/JTMS/SWDIO (Unavailable)
 *                            - PA14/JTCK/SWCLK (Unavailable)
 *                            - PA15/JTDI (Unavailable)
 *                            - PB3/JTDO/TRACE/SWO (Unavailable)
 *                            - PB4/NJTRST (Unavailable)
 *
 *                      - AFIO_REMAP_FULL:
 *                            - PA13/JTMS/SWDIO (Unavailable)
 *                            - PA14/JTCK/SWCLK (Unavailable)
 *                            - PA15/JTDI (Unavailable)
 *                            - PB3/JTDO/TRACE/SWO (Unavailable)
 *                            - PB4/NJTRST (Free)
 *
 *                      - AFIO_REMAP_PARTIAL:
 *                            - PA13/JTMS/SWDIO (Unavailable)
 *                            - PA14/JTCK/SWCLK (shared with JTDI) (Unavailable)
 *                            - PA15/JTDI (shared with JTCK/SWCLK) (Free)
 *                            - PB3/JTDO/TRACE/SWO (Free)
 *                            - PB4/NJTRST (Free)
 * 
 *                      - AFIO_REMAP_CUSTOM:
 *                            - This configuration allows users to customize the remap settings according to their needs. 
 *                              User configuration will determine the pin status.
 */
typedef enum 
{
    AFIO_REMAP_NONE,     /**< No remap (default) */ 
    AFIO_REMAP_FULL,     /**< Full SWJ (JTAG-DP + SW-DP) but without NJTRST */ 
    AFIO_REMAP_PARTIAL,  /**< JTAG-DP Disabled and SW-DP Enabled */ 
    AFIO_REMAP_CUSTOM,   /**< Custom remap (user-defined) */ 
} AFIO_RemapConfig_t;

/** @} */  // End of AFIO_Remap_Options group
/**
 * @defgroup AFIO_Functions AFIO Functions
 * @brief Functions for controlling the AFIO (Alternate Function I/O) peripheral.
 * @{
 */

/**
 * @brief Configure AF remap and debug I/O settings.
 *
 * This function configures the AF remap and debug I/O settings using the AFIO peripheral.
 *
 * @param[in] Copy_RemapConfig The configuration value for AF remap and debug I/O.
 * @return Std_ReturnType Returns E_OK if the configuration is successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType MCAL_AFIO_SetRemap(AFIO_RemapConfig_t Copy_RemapConfig);

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