/**
 * @file US_interface.h
 * @brief This file contains the public interface for the US HAL drivers.
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
#ifndef US_INTERFACE_H_
#define US_INTERFACE_H_
/*
 * Enum for the ID of the ultrasonic sensors.
 * The three sensors are named Right, Left, and Middle.
 */
typedef enum US_ID_t
{
    Right,
    Left,
    Middle
}US_ID_t;
/*
 * Enum for the state of the ultrasonic sensors.
 * The sensors can be either enabled or disabled.
 * In case of disabled, User can't read distance.
 */
typedef enum Ultrasonic_state_t
{
    Ultrasonic_enable,
    Ultrasonic_disable
}Ultrasonic_state_t;
/* This structure defines the configuration parameters for an ultrasonic sensor */
typedef struct US_config_t
{
    u16 DistanceRange;           // The maximum distance range that the sensor can measure, then send OUT_OF_RANGE(-1) value.
    Ultrasonic_state_t state;    // The current state of the sensor (enabled or disabled)
    u8 Echo_pin;                 // The input pin used to receive the echo signal from the sensor (GPIO_PINx)
    u8 Echo_port;                // The GPIO port used to receive the echo signal (GPIO_PORTx)   
    u8 Trigger_pin;              // The output pin used to send the trigger signal to the sensor
    u8 Trigger_port;             // The GPIO port used to send the trigger signal
}US_config_t;
/**
 * @brief Initializes and configures the Ultrasonic interface.
 *
 * This function initializes and configures the required modules for the
 * Ultrasonic interface, including RCC, DIO, AFIO, EXTI, STK, and NVIC.
 *
 * @param[in] ID                Identifier for the Ultrasonic interface.
 * @param[in] Ultrasonic_config Pointer to the configuration structure
 *                              for the Ultrasonic interface.
 *
 * @return Std_ReturnType
 *   - E_OK     : Initialization successful.
 *   - E_NOT_OK : Error occurred during initialization.
 */
Std_ReturnType Ultrasonic_init(US_ID_t ID, US_config_t * Ultrasonic_config);
/**
 * @brief Reads the distance measured by an ultrasonic sensor.
 *
 * This function reads the distance measured by the ultrasonic sensor
 * specified by 'ID' and returns the value in centimeters.
 *
 * @param[in]  ID              Identifier for the ultrasonic sensor.
 * @param[out] copy_US_reading Pointer to store the measured distance
 *                             in centimeters.
 *
 * @return Std_ReturnType
 *   - E_OK     : Reading successful.
 *   - E_NOT_OK : Error occurred during reading.
 */
Std_ReturnType Ultrasonic_readDistance(US_ID_t ID,f32* copy_US_reading);
/**
 * @brief Sets the range and timeout values for an ultrasonic sensor.
 *
 * This function sets the range and timeout values for the ultrasonic sensor
 * specified by 'ID' to enhance performance.
 *
 * @param[in] ID       Identifier for the ultrasonic sensor.
 * @param[in] Range_cm Range value in centimeters to be set for the sensor.
 *
 * @return Std_ReturnType
 *   - E_OK     : Setting range successful.
 *   - E_NOT_OK : Error occurred while setting range or invalid parameters.
 */
Std_ReturnType Ultrasonic_setRange(US_ID_t ID, u16 Range_cm);
/**
 * @brief Sets the state for an ultrasonic sensor.
 *
 * This function sets the state for the ultrasonic sensor specified by 'ID'.
 * When the state is set to 'Ultrasonic_disable', readings will not execute for this sensor.
 *
 * @param[in] ID    Identifier for the ultrasonic sensor.
 * @param[in] state State to be set for the sensor (e.g., Ultrasonic_disable).
 *
 * @return Std_ReturnType
 *   - E_OK     : Setting state successful.
 *   - E_NOT_OK : Error occurred while setting state or invalid parameters.
 */
Std_ReturnType Ultrasonic_setState(US_ID_t ID, Ultrasonic_state_t state);

void callback_fun();

#endif /* US_INTERFACE_H_ */
