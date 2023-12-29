/**
 * @file LCD_config.h
 * @brief This file contains the configuration settings for the LCD driver.
 *
 * @copyright Copyright (c) 2023
 * 
 * This driver library simplifies the integration and control of Liquid Crystal Displays (LCDs),
 * providing an interface for displaying information in embedded systems with efficient handling of display data and configuration.
 *
 * @note This module is developed for compatibility with a range of embedded systems and microcontrollers, but specific hardware constraints may apply.
 *
 * @date 29th December 2023
 * @version V1.0
 * @author Mohamed Ali
 */
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/** OPTIONS: 1- GPIO_PORTA
			 2- GPIO_PORTB
			 3- GPIO_PORTC
			 4- GPIO_PORTD */

#define LCD_CONTROL_PORT	GPIO_PORTA
#define LCD_RS_PIN		    GPIO_PIN0
#define LCD_E_PIN		    GPIO_PIN1
#define LCD_RW_PIN		    GPIO_PIN10

#define LCD_DATA_PORT	    GPIO_PORTA
#define	LCD_D0_PIN		    GPIO_PIN2
#define	LCD_D1_PIN		    GPIO_PIN3
#define	LCD_D2_PIN		    GPIO_PIN4
#define	LCD_D3_PIN		    GPIO_PIN5

#define	LCD_D4_PIN		    GPIO_PIN6
#define	LCD_D5_PIN		    GPIO_PIN7
#define	LCD_D6_PIN		    GPIO_PIN8
#define	LCD_D7_PIN		    GPIO_PIN9

/** OPTIONS: 1- LCD_MODE_8_BIT
 * 			 2- LCD_MODE_4_BIT
 */

#define LCD_MODE		LCD_MODE_4_BIT



#endif /* LCD_CONFIG_H_ */