/**
 * @file GPT_config.h
 * @brief This file contains the private interface for the GPT module.
 *
 * @copyright Copyright (c) 2023
 * 
 * This module provides low-level functions for configuring and controlling the general purpose timers in the ARM Cortex-M processor.
 * The general purpose timers can be used for various timing and synchronization purposes in embedded systems.
 *
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 28 NOV 2023
 * @version V01
 * @author Mohamed Ali Bayoumi
 */
#ifndef GPT_CONFIG_H_
#define GPT_CONFIG_H_

/*
Config the CLK for the timer
*/
#define 	TIM_Clk_Freq		RCC_APB2_CLK_FRQ
/*
 * RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);*
 * Timer Number				from			to
 * 1						PA8				PA11
 * 2						PA0				PA3
 * 3                        PA6 to PA7 + PB0 to PB1
 * 4  						PB6  			PB9
 * Pin Mode:GPIO_Mode_AFPP, GPIO_Speed_50MHz
 *
 *
 *
 *
 *
 * if you want timer counts milliseconds and microseconds:*/
/* [Must]  Select Ratio
Options:
     MilliSeconds                   For Microseconds and MilliSeconds
     Seconds    					For MilliSeconds and Seconds
*/
#define TIM_Ratio		MilliSeconds


#endif /* GPT_CONFIG_H_ */