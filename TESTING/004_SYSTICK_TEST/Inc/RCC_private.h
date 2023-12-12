/***************************************************************************************************/
/************************* Author  : Mohamed Ali Bayoumi    ****************************************/
/************************* Date    : 30/9/2023              ****************************************/
/************************* Version : 0.1                    ****************************************/
/************************* MODULE  : MCAL_RCC_private.h     ****************************************/
/***************************************************************************************************/
#ifndef MCAL_RCC_PRIVATE_H_
#define MCAL_RCC_PRIVATE_H_


/**
 * @defgroup RCC_Registers
 * @brief Reset and Clock Control (RCC) Registers
 *
 * This module provides definitions for the RCC (Reset and Clock Control) registers
 * for configuring and controlling system clocks and resets in the microcontroller.
 *
 * @{
 */
/**
 * @brief RCC Base Address
 *
 * For caluclating the rest of the registers addresses
 */
#define RCC_BASE_ADDRESS    (0x40021000)

/**
 * @brief RCC Control Register (CR)
 *
 * This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
 */
#define RCC_CR              (*((volatile u32*)( (RCC_BASE_ADDRESS) + (0x00) )))
/**
 * @brief RCC Configuration Register (CFGR)
 *
 * This register configures the system clock sources, prescalers, and peripherals clocks.
 */
#define RCC_CFGR              (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x04))))
/**
 * @brief RCC Clock Interrupt Register (CIR)
 *
 * This register manages clock interrupts and flags.
 */
#define RCC_CIR             (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x08))))
/**
 * @brief RCC APB2 Peripheral Reset Register (APB2RSTR)
 *
 * This register controls the reset state of peripherals connected to APB2 bus.
 */
#define RCC_APB2RSTR        (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x0C))))
/**
 * @brief RCC APB1 Peripheral Reset Register (APB1RSTR)
 *
 * This register controls the reset state of peripherals connected to APB1 bus.
 */
#define RCC_APB1RSTR        (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x10))))
/**
 * @brief RCC AHB Peripheral Clock Enable Register (AHBENR)
 *
 * This register enables clock access for peripherals connected to AHB bus.
 */
#define RCC_AHBENR          (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x14))))
/**
 * @brief RCC APB1 Peripheral Clock Enable Register (APB1ENR)
 *
 * This register enables clock access for peripherals connected to APB1 bus.
 */
#define RCC_APB2ENR         (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x18))))
/**
 * @brief RCC APB2 Peripheral Clock Enable Register (APB2ENR)
 *
 * This register enables clock access for peripherals connected to APB2 bus.
 */
#define RCC_APB1ENR         (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x1C))))
/**
 * @brief RCC Backup Domain Control Register (BDCR)
 *
 * This register provides control over backup domain and RTC (Real-Time Clock).
 */
#define RCC_BDCR            (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x20))))
/**
 * @brief RCC Control and Status Register (CSR)
 *
 * This register provides various control and status flags.
 */
#define RCC_CSR             (*((volatile u32 *)((RCC_BASE_ADDRESS) + (0x24))))
/** @} */ // end of RCC Control Register (CR)

/**
 * @defgroup RCC_CR_Bit_Definitions RCC Control Register (RCC_CR) Bit Definitions
 * @{
 */
#define RCC_CR_HSION            0   //  Internal High-Speed Clock Enable
#define RCC_CR_HSIRDY           1   //  Internal High-Speed Clock Read
#define RCC_CR_HSICAL           8   //  Internal High-Speed Clock Calibration
#define RCC_CR_HSEON            16  //  External High-Speed Clock Enable
#define RCC_CR_HSERDY           17  //  External High-Speed Clock Ready
#define RCC_CR_HSEBYP           18  //  External High-Speed Clock Bypass
#define RCC_CR_CSSON            19  //  Clock Security System Enable
#define RCC_CR_PLLON            24  //  PLL Enable
#define RCC_CR_PLLRDY           25  //  PLL Ready
/** @} */ // end of RCC_CR_Bit_Definitions

/**
 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */
#define RCC_HSI                 0   //  High-Speed Internal Clock Source (HSI) 
#define RCC_HSE                 1   //  High-Speed External Clock Source (HSE)
#define RCC_PLL                 2   //  Phase-Locked Loop Clock Source (PLL)
/** @} */ // end of RCC_Clock_Source
/**
 * @defgroup RCC_HSE_Clock_Type RCC HSE Clock Type Macros
 * @{
 */
#define RCC_CRYSTAL_CLK_        0   //  Crystal Oscillator Clock Type
#define RCC_RC_CLK_             1   //  RC Oscillator Clock Type
/** @} */ // end of RCC_HSE_Clock_Type
/**
 * @defgroup RCC_PLL_Clock_Type RCC PLL Clock Type Macros
 * @{
 */
#define RCC_PLL_HSI             0   //  PLL SRC HSI
#define RCC_PLL_HSE             1   //  PLL SRC HSE
#define RCC_PLL_HSE_DIV_EN      1   //  EN Div by 2
#define RCC_PLL_HSE_DIV_DIS     0   //  Dis Div by 2
/** @} */ // end of RCC_PLL_Clock_Type

/**
 * @defgroup RCC_CFGR_Bit_Definitions RCC Configration Register (RCC_CFGR) Bit Definitions
 * @{
 */
#define RCC_CFGR_PLLSRC         16  //  PLL entry clock source
#define RCC_CFGR_PLLXTPRE       17  //  HSE divider for PLL entry
#define RCC_CFGR_AHB_PRE_DIS    4   //  AHB prescaler
#define RCC_CFGR_APB1_PRE_DIS   8   //  APB low-speed prescaler (APB1)  
#define RCC_CFGR_APB2_PRE_DIS   11  //  APB high-speed prescaler (APB2)
#define RCC_CFGR_ADC_PRE_DIS    14  //  ADC prescaler
#define RCC_CFGR_PLL_MUX_DIS    18  //  PLL multiplication factor
#define RCC_CFGR_USB_PRE_DIS    22  //  USB prescaler
#define RCC_CFGR_MCO_DIS        24  //  Microcontroller clock output
/** @} */ // end of RCC_CFGR_Bit_Definitions

/**
 * @defgroup RCC_MCO_CLK_SRC RCC MCO CLK SRC
 * @{
 */
#define RCC_MCO_NoCLK           0   //  No clock
#define RCC_MCO_SYSCLK          4   //  System clock (SYSCLK) selected
#define RCC_MCO_HSI             5   //  HSI clock selected
#define RCC_MCO_HSE             6   //  HSE clock selected
#define RCC_MCO_PLL_Pre_2       7   //  PLL clock divided by 2 selected
/** @} */ // end of RCC_MCO_CLK_SRC


#endif /* MCAL_RCC_PRIVATE_H_ */
