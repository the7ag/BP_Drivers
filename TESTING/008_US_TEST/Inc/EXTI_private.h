/**
 * @brief This module contains functions for configuring and controlling the External Interrupt (EXTI) peripheral.
 *
 * @author Mohamed Ali Bayoumi
 * @date 25 OCT 2024
 * @version V01
 *
 * This module provides functions for configuring the interrupt source, trigger type, and enabling/disabling EXTI lines.
 * It also includes functions for clearing the EXTI pending flag and getting the interrupt status. It is designed to be
 * used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_
/*******************************< Register Definitions *******************************/
/**
 * @brief EXTI Base Address.
 *
 * This macro defines the base address of the External Interrupt (EXTI) peripheral.
 */
#define EXTI_BASE_ADDRESS       0x40010400
/**
 * @brief EXTI Register Map.
 *
 * This struct defines the register map of the EXTI peripheral, providing volatile access to the Interrupt Mask Register (IMR),
 * Event Mask Register (EMR), Rising Trigger Selection Register (RTSR), Falling Trigger Selection Register (FTSR),
 * Software Interrupt Event Register (SWIER), and Pending Register (PR).
 */ 
typedef struct 
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_RegDef_t;
/**
 * @brief EXTI Register Access.
 *
 * This macro provides access to the EXTI peripheral using the register map defined in EXTI_t. It defines EXTI as a volatile
 * pointer to the base address of the EXTI peripheral.
 */
#define EXTI ((EXTI_RegDef_t*)EXTI_BASE_ADDRESS)

/**< Total number of EXTI lines available */
#define EXTI_LINES_COUNT    16
/**< EXTI line enabled */
#define EXTI_LINE_ENABLED       1
/**< EXTI line disabled */
#define EXTI_LINE_DISABLED      0
/**
 * @name EXTI Port Mapping
 * @{
 */
#define EXTI_GPIO_NONE      ((INVALID_VALUE)-1) /**< A special value indicating no GPIO port is mapped to the EXTI line. */
#define EXTI_PORTMAP_GPIOA  0 /**< Map EXTI line to GPIO Port A. */
#define EXTI_PORTMAP_GPIOB  1 /**< Map EXTI line to GPIO Port B. */
#define EXTI_PORTMAP_GPIOC  2 /**< Map EXTI line to GPIO Port C. */
/** @} */
/**< EXTI Configuration Structure */

typedef struct 
{
    EXTI_CallbackFunc_t SetCallback;
    u8 GPIO_PortMap: 3;
    u8 TriggerType: 2;
    u8 LineEnabled:1;
    u8 : 2;
}EXTI_Configration_t;

/**< EXTI line configuration settings */
extern EXTI_Configration_t Exti_Configrations[EXTI_LINES_COUNT];


#endif /* EXTI_PRIVATE_H_ */
