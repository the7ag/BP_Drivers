/***************************************************************************************************/
/************************* Author  : Mohamed Ali Bayoumi    ****************************************/
/************************* Date    : 30/9/2023              ****************************************/
/************************* Version : 0.1                    ****************************************/
/************************* MODULE  : MCAL_RCC_config.h      ****************************************/
/***************************************************************************************************/
#ifndef MCAL_RCC_CONFIG_H_
#define MCAL_RCC_CONFIG_H_


/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.*/
#define RCC_SYSCLK   RCC_HSE


/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE
    #define RCC_CLK_BP RCC_CRYSTAL_CLK_
#endif /* RCC_HSE */

/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_PLL.
 * @note Choose one of the available options:
 *       RCC_PLL_HSI        -  HSI oscillator clock / 2 selected as PLL input clock.
 *       RCC_PLL_HSE        -  HSE oscillator clock selected as PLL input clock
 */
# if  RCC_SYSCLK == RCC_PLL
   #define RCC_PLL_SRC RCC_PLL_HSI
/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_PLL.
 * @note Choose one of the available options:
 *       RCC_PLL_HSE_DIV_DIS        - HSE clock not divided
 *       RCC_PLL_HSE_DIV_EN        -  HSE clock divided by 2
 */
   #if RCC_PLL_SRC == RCC_PLL_HSE
       #define RCC_PLL_HSE_DIV RCC_PLL_HSE_DIV_DIS
   #endif /* RCC_PLL_SRC */
#endif /* RCC_PLL */

/**
 * @brief Configure the MCO out 
 * @note Choose one of the available options:
 *       RCC_MCO_NoCLK           -  No clock
 *       RCC_MCO_SYSCLK          -  System clock (SYSCLK) selected
 *       RCC_MCO_HSI             -   HSI clock selected
 *       RCC_MCO_HSE             -   HSE clock selected
 *       RCC_MCO_PLL_Pre_2       -   PLL clock divided by 2 selected
 */
#define RCC_MCO_SRC RCC_MCO_NoCLK

/*** @}*/

#endif /* MCAL_RCC_CONFIG_H_ */
