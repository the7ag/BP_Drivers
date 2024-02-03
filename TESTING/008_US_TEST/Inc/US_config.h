/**
 * @file US_config.h
 * @brief This file contains the config for the US HAL drivers.
 *
 * @copyright Copyright (c) 2023
 * 
 * This driver library streamlines the integration and utilization of ultrasonic sensors,
 *  offering precise distance measurement capabilities in embedded systems with efficient handling of sensor data and configuration.
 *
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 13 dec 2023
 * @version V01
 * @author Mohamed Ali Bayoumi
 */
#ifndef US_CONFIG_H_
#define US_CONFIG_H_

// This constant defines the number of ultrasonic sensor being used.
#define NUMBER_OF_ULTRASONIC_USED       3
// This constant defines the timer period for the ultrasonic sensor
#define TIMER_PERIOD                    (10000)

#endif /* US_CONFIG_H_ */
