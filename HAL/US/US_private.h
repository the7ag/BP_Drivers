/**
 * @file US_private.h
 * @brief This file contains the private interface for the US HAL drivers.
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
#ifndef US_PRIVATE_H_
#define US_PRIVATE_H_
// This struct defines an ultrasonic sensor object with its properties
typedef struct US_t
{
    u8 State;               // State of the ultrasonic sensor
    u8 Echo_pin;            // Echo pin number (GPIO_PINx)
    u8 Echo_port;           // Echo pin port (GPIO_PORTA, GPIO_PORTB)
    u8 Trig_pin;            // Trigger pin number (GPIO_PINx)
    u8 Trig_port;           // Trigger Port Name (GPIO_PORTx)
    u32 DistanceRange;      // Distance range of the ultrasonic sensor
    u32 Timeout;            // Timeout value for the ultrasonic sensor
}US_t;
// These constants define the out of range and disable states for the ultrasonic sensor
#define OUT_OF_RANGE            -1 
#define ULTRASONIC_DISABLE      -2
// These constants define the rising and falling edge states for the ultrasonic sensor
#define RISING_DETECTED         0
#define FALLING_DETECTED        1
// These constants define the reading states for the ultrasonic sensor
#define READING_PENDING         0
#define READING_DONE            1
// This function calculates the distance for the ultrasonic sensor based on the echo signal
void CalcDistance();

#endif /* US_PRIVATE_H_ */