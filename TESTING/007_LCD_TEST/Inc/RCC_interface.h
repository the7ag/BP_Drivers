/***************************************************************************************************/
/************************* Author  : Mohamed Ali Bayoumi    ****************************************/
/************************* Date    : 30/9/2023              ****************************************/
/************************* Version : 0.1                    ****************************************/
/************************* MODULE  : MCAL_RCC_interface.h   ****************************************/
/***************************************************************************************************/
#ifndef MCAL_RCC_INTERFACE_H_
#define MCAL_RCC_INTERFACE_H_

/**
 * @defgroup RCC_Peripheral_Macros RCC Peripheral Macros
 * @brief Macros related to clock configuration for different peripherals.
 * @{
 */

/**
 * @defgroup RCC_Clock_Domains Clock Domains
 * @brief Macros defining the available clock domains for peripheral clock configuration.
 * @{
 */

/**
 * @brief Available clock domains for peripheral clock configuration.
 */

#define RCC_AHB             0
#define RCC_APB1            1
#define RCC_APB2            2
/** @} */

/**
 * @defgroup RCC_AHBENR_Bit_Def RCC_AHBENR Bit Definitions
 * @brief Macros representing the bit positions in the AHB Peripheral Clock Enable Register (RCC_AHBENR).
 * @{
 */

#define RCC_AHB_DMA1EN      0   /* DMA1 clock enable */
#define RCC_AHB_DMA2EN      1   /* DMA2 clock enable */
#define RCC_AHB_SRAMEN      2   /* SRAM interface clock enable */
#define RCC_AHB_FLITFEN     4   /* FLITF clock enable */
#define RCC_AHB_CRCEN       6   /* CRC clock enable */
#define RCC_AHB_FSMCEN      8   /* FSMC clock enable */
#define RCC_AHB_SDIO        10  /* SDIO clock enable  */
/** @} */

/**
 * @defgroup RCC_APB1ENR_Bit_Def RCC_APB1ENR Bit Definitions
 * @brief Macros representing the bit positions in the APB1 Peripheral Clock Enable Register (RCC_APB1ENR).
 * @{
 */
#define RCC_APB1_TIM2EN     0   /* TIM2 timer clock enable */
#define RCC_APB1_TIM3EN     1   /* TIM3 timer clock enable */
#define RCC_APB1_TIM4EN     2   /* TIM4 timer clock enable */
#define RCC_APB1_TIM5EN     3   /* TIM5 timer clock enable */
#define RCC_APB1_TIM6EN     4   /* TIM6 timer clock enable */
#define RCC_APB1_TIM7EN     5   /* TIM7 timer clock enable */
#define RCC_APB1_TIM12EN    6   /* TIM12 timer clock enable */
#define RCC_APB1_TIM13EN    7   /* TIM13 timer clock enable */
#define RCC_APB1_TIM14EN    8   /* TIM14 timer clock enable */
#define RCC_APB1_WWDGEN     11  /* Window watchdog clock enable */
#define RCC_APB1_SPI2EN     14  /* SPI2 clock enable */
#define RCC_APB1_SPI3EN     15  /* SPI 3 clock enable */
#define RCC_APB1_USART2EN   17  /* USART2 clock enable */
#define RCC_APB1_USART3EN   18  /* USART3 clock enable */
#define RCC_APB1_USART4EN   19  /* USART4 clock enable */
#define RCC_APB1_USART5EN   20  /* USART5 clock enable */
#define RCC_APB1_I2C1EN     21  /* I2C1 clock enable */
#define RCC_APB1_I2C2EN     22  /* I2C2 clock enable */
#define RCC_APB1_USBEN      23  /* USB clock enable */
#define RCC_APB1_CANEN      25  /* CAN clock enable */
#define RCC_APB1_BKPEN      27  /* Backup interface clock enable */
#define RCC_APB1_PWREN      28  /* Power interface clock enable */
#define RCC_APB1_DACEN      29  /* DAC interface clock enable */
/** @} */

/**
 * @defgroup RCC_APB2ENR_Bit_Def RCC_APB2ENR Bit Definitions
 * @brief Macros representing the bit positions in the APB2 Peripheral Clock Enable Register (RCC_APB2ENR).
 * @{
 */

#define RCC_APB2_AFIOEN     0   /* Alternate function IO clock enable */
#define RCC_APB2_IOPAEN     2   /* IO port A clock enable */
#define RCC_APB2_IOPBEN     3   /* IO port B clock enable */
#define RCC_APB2_IOPCEN     4   /* IO port C clock enable */
#define RCC_APB2_IOPDEN     5   /* IO port D clock enable */
#define RCC_APB2_IOPEEN     6   /* IO port E clock enable */
#define RCC_APB2_IOPFEN     7   /* IO port F clock enable */
#define RCC_APB2_IOPGEN     8   /* IO port G clock enable */
#define RCC_APB2_ADC1EN     9   /* ADC 1 interface clock enable */
#define RCC_APB2_ADC2EN     10  /* ADC 2 interface clock enable */
#define RCC_APB2_TIM1EN     11  /* TIM1 timer clock enable */
#define RCC_APB2_SPI1EN     12  /* SPI1 clock enable */
#define RCC_APB2_TIM8EN     13  /* TIM8 Timer clock enable */
#define RCC_APB2_USART1EN   14  /* USART1 clock enable */
#define RCC_APB2_ADC3EN     15  /* ADC3 interface clock enable */
#define RCC_APB2_TIM9EN     19  /* TIM9 timer clock enable */
#define RCC_APB2_TIM10EN    20  /* TIM10 timer clock enable */
#define RCC_APB2_TIM11EN    21  /* TIM11 timer clock enable */
/** @} */

/**
 * @defgroup RCC_CFGR_AHB_PRE_Def RCC_CFGR AHB Bus Prescalar
 * @brief Macros representing the prescalar values for the AHB bus in to use in the RCC CFGR
 * @{
 */

#define AHB_Pre_0           0   /*  SYSCLK not divided */
#define AHB_Pre_2           8   /*  SYSCLK divided by 2 */
#define AHB_Pre_4           9   /*  SYSCLK divided by 4 */
#define AHB_Pre_8           10  /*  SYSCLK divided by 8 */
#define AHB_Pre_16          11  /*  SYSCLK divided by 16 */
#define AHB_Pre_64          12  /*  SYSCLK divided by 64 */
#define AHB_Pre_128         13  /*  SYSCLK divided by 128 */
#define AHB_Pre_256         14  /*  SYSCLK divided by 256 */
#define AHB_Pre_512         15  /*  SYSCLK divided by 512 */
/** @} */
/**
 * @defgroup RCC_CFGR_APB1_PRE_Def RCC_CFGR APB1 Bus Prescalar
 * @brief Macros representing the prescalar values for the APB1 bus in to use in the RCC CFGR
 * @{
 */
#define APB1_Pre_0          0   /* HCLK not divided */
#define APB1_Pre_2          4   /* HCLK divided by 2 */
#define APB1_Pre_4          5   /* HCLK divided by 4 */
#define APB1_Pre_8          6   /* HCLK divided by 8 */
#define APB1_Pre_16         7   /* HCLK divided by 16 */
/** @} */
/**
 * @defgroup RCC_CFGR_APB2_PRE_Def RCC_CFGR APB1 Bus Prescalar
 * @brief Macros representing the prescalar values for the APB2 bus in to use in the RCC CFGR
 * @{
 */
#define APB2_Pre_0          0   /* HCLK not divided */
#define APB2_Pre_2          4   /* HCLK divided by 2 */
#define APB2_Pre_4          5   /* HCLK divided by 4 */
#define APB2_Pre_8          6   /* HCLK divided by 8 */
#define APB2_Pre_16         7   /* HCLK divided by 16 */
/** @} */
/**
 * @defgroup RCC_CFGR_ADC_PRE_Def RCC_CFGR ADC Prescalar
 * @brief Macros representing the prescalar values for the ADC in to use in the RCC CFGR
 * @{
 */
#define ADC_Pre_2           0   /* PCLK2 divided by 2 */
#define ADC_Pre_4           1   /* PCLK2 divided by 4 */
#define ADC_Pre_6           2   /* PCLK2 divided by 6 */
#define ADC_Pre_8           3   /* PCLK2 divided by 8 */
/** @} */
/**
 * @defgroup RCC_CFGR_PLL_MUL_Def RCC_CFGR PLL Multiplaction Factor
 * @brief Macros representing the Multiplaction factor  for the PLL in to use in the RCC CFGR
 * @{
 */
#define PLL_Mul_2           0   /* PLL input clock x 2 */
#define PLL_Mul_3           1   /* PLL input clock x 3 */
#define PLL_Mul_4           2   /* PLL input clock x 4 */
#define PLL_Mul_5           3   /* PLL input clock x 5 */
#define PLL_Mul_6           4   /* PLL input clock x 6 */
#define PLL_Mul_7           5   /* PLL input clock x 7 */
#define PLL_Mul_8           6   /* PLL input clock x 8 */
#define PLL_Mul_9           7   /* PLL input clock x 9 */
#define PLL_Mul_10          8   /* PLL input clock x 10 */
#define PLL_Mul_11          9   /* PLL input clock x 11 */
#define PLL_Mul_12          10  /*  PLL input clock x 12 */
#define PLL_Mul_13          11  /*  PLL input clock x 13 */
#define PLL_Mul_14          12  /*  PLL input clock x 14 */
#define PLL_Mul_15          13  /*  PLL input clock x 15 */
#define PLL_Mul_16          14  /*  PLL input clock x 16 */
#define PLL_Mul_16_2        15  /*  PLL input clock x 16 */
/** @} */
/**
 * @defgroup RCC_CFGR_USB_PRE_Def RCC_CFGR USB Prescalar Value
 * @brief Macros representing prescalar value for usb to use in the RCC CFGR
 * @{
 */
#define USB_Pre_1_5         0
#define USB_Pre_0           1
/** @} */
/** @} */  /* End of RCC_Peripheral_Macros group */

/**
 * @defgroup RCC_API RCC APIs
 * @brief Functions for RCC (Reset and Clock Control) configuration.
 * @{
 */

/**
 * @brief Initialize the system clock configuration.
 *
 * This function initializes the system clock configuration according to the desired settings.
 * It should be called early in the program to properly configure the clock system.
 *
 * @return Std_ReturnType
 * @retval E_OK     Clock initialization successful.
 * @retval E_NOT_OK Clock initialization failed.
 */
Std_ReturnType MCAL_RCC_InitSysClock(void);
/**
 * @brief Enables the CLK security system.
 *
 * This function enables the CLK security system when using HSE
 *
 * @return Std_ReturnType
 * @retval E_OK     Clock Security system enabled successfully.
 * @retval E_NOT_OK Clock Security system enabled failed.
 */
Std_ReturnType MCAL_RCC_EnableClkSecuritySystem(void);
/**
 * @brief Disable the CLK security system.
 *
 * This function Disables the CLK security system when using HSE
 *
 * @return Std_ReturnType
 * @retval E_OK     Clock Security system disabled successfully.
 * @retval E_NOT_OK Clock Security system disabled failed.
 */
Std_ReturnType MCAL_RCC_DisapleClkSecuritySystem(void);

/**
 * @brief TSets the AHB bus prescalar
 *
 * This function sets the prescalar value for the AHB bus
 * @param[in] Copy_PreValue The value of the prescalar
 * @return Std_ReturnType
 * @retval E_OK     Prescalar value was set successfully 
 * @retval E_NOT_OK Clock Prescalar value wasn't set successfully.
 */
Std_ReturnType MCAL_RCC_SetAHB_Pre(u8 Copy_PreValue);
/**
 * @brief TSets the APB1 bus prescalar
 *
 * This function sets the prescalar value for the APB1 bus
 * @param[in] Copy_PreValue The value of the prescalar
 * @return Std_ReturnType
 * @retval E_OK     Prescalar value was set successfully 
 * @retval E_NOT_OK Clock Prescalar value wasn't set successfully.
 */
Std_ReturnType MCAL_RCC_SetAPB1_Pre(u8 Copy_PreValue);
/**
 * @brief Sets the APB2 bus prescalar
 *
 * This function sets the prescalar value for the APB2 bus
 * @param[in] Copy_PreValue The value of the prescalar
 * @return Std_ReturnType
 * @retval E_OK     Prescalar value was set successfully 
 * @retval E_NOT_OK Clock Prescalar value wasn't set successfully.
 */
Std_ReturnType MCAL_RCC_SetAPB2_Pre(u8 Copy_PreValue);
/**
 * @brief Sets the ADC prescalar
 *
 * This function sets the prescalar value for the ADC
 * @param[in] Copy_PreValue The value of the prescalar
 * @return Std_ReturnType
 * @retval E_OK     Prescalar value was set successfully 
 * @retval E_NOT_OK Clock Prescalar value wasn't set successfully.
 */
Std_ReturnType MCAL_RCC_SetADC_Pre(u8 Copy_PreValue);
/**
 * @brief Sets the Multplicand for PLL
 *
 * This function sets the Multiplication factor for PLL
 * @param[in] Copy_PreValue The value of the Multiplaction factor
 * @return Std_ReturnType
 * @retval E_OK     Prescalar value was set successfully 
 * @retval E_NOT_OK Clock Prescalar value wasn't set successfully.
 */
Std_ReturnType MCAL_RCC_SetPLL_MUL(u8 Copy_PreValue);
/**
 * @brief Sets the USB prescalar
 *
 * This function sets the prescalar value for the USB
 * @param[in] Copy_PreValue The value of the prescalar
 * @return Std_ReturnType
 * @retval E_OK     Prescalar value was set successfully 
 * @retval E_NOT_OK Clock Prescalar value wasn't set successfully.
 */
Std_ReturnType MCAL_RCC_SetUSB_Pre(u8 Copy_PreValue);
/**
 * @brief Enabled MCO
 *
 * This function enabled MCO and sets it's output src as set in the config file
 * @return Std_ReturnType
 * @retval E_OK     Prescalar value was set successfully 
 * @retval E_NOT_OK Clock Prescalar value wasn't set successfully.
 */
Std_ReturnType MCAL_RCC_EnaleMCO(void);
/**
 * @brief Enable a specific peripheral on a specific bus.
 *
 * This function enables a specific peripheral on a specific bus.
 *
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType
 * @retval E_OK     Peripheral enabling successful.
 * @retval E_NOT_OK Peripheral enabling failed.
 */
Std_ReturnType MCAL_Rcc_EnablePrephiral(u8 Copy_PeripheralId , u8 Copy_BusId);
/**
 * @brief Disable a specific peripheral.
 *
 * This function disables a previously enabled peripheral.
 * 
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType
 * @retval E_OK     Peripheral disabling successful.
 * @retval E_NOT_OK Peripheral disabling failed.
 */
Std_ReturnType MCAL_Rcc_DisablePrephiral(u8 Copy_PeripheralId , u8 Copy_BusId);
/*** @}*/
#endif /* MCAL_RCC_INTERFACE_H_ */