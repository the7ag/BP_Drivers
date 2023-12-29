/**
 * @file LCD_program.c
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
/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"
/**************************************** MCAL *****************************************************/
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"
/**************************************** HAL *****************************************************/
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
/*====================================================   Start_FUNCTION   ====================================================*/
/**
 * @brief Initializes the LCD driver based on the configured mode (8-bit or 4-bit).
 *
 * @retval Std_ReturnType returns E_OK if initialization is successful, E_NOK if an error occurs during initialization.
 */
Std_ReturnType LCD_Init(void){
    // Variable to track the function status, initially set to E_NOT_OK
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    // Initialize the system tick timer
    MCAL_SYSTICK_vINIT();

    // Check the configured LCD mode and initialize accordingly
    #if LCD_MODE == LCD_MODE_8_BIT
        // Set control pins and data pins for 8-bit mode
        MCAL_GPIO_SetPinMode(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D0_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D1_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D2_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D3_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D4_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D5_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D6_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D7_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);

        // Delay for LCD startup (30ms)
        MCAL_SYSTICK_DelayMS(30);

        // LCD initialization sequence for 8-bit mode
        LCD_SendCmnd(LCD_HOME);
        MCAL_SYSTICK_DelayMS(1);
        LCD_SendCmnd(LCD_FUNCTIONSET8BIT);
        MCAL_SYSTICK_DelayMS(1);
        LCD_SendCmnd(LCD_DISPLAYON);
        MCAL_SYSTICK_DelayMS(1);
        LCD_SendCmnd(LCD_CLEAR);
        MCAL_SYSTICK_DelayMS(1);
        LCD_SendCmnd(LCD_ENTRYMODE);
        MCAL_SYSTICK_DelayMS(1);

        // Update function status to indicate successful initialization
        Local_FunctionStatus = E_OK;

    #elif LCD_MODE == LCD_MODE_4_BIT
        // Set control pins and data pins for 4-bit mode
        MCAL_GPIO_SetPinMode(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D4_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D5_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D6_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);
        MCAL_GPIO_SetPinMode(LCD_DATA_PORT, LCD_D7_PIN, GPIO_OUTPUT_LOW_SPEED_PUSHPULL);

        // Delay for LCD startup (30ms)
        MCAL_SYSTICK_DelayMS(30);

        // LCD initialization sequence for 4-bit mode
        LCD_SendCmnd(LCD_HOME);
        MCAL_SYSTICK_DelayMS(1);
        LCD_SendCmnd(LCD_FUNCTIONSET4BIT);
        MCAL_SYSTICK_DelayMS(1);
        LCD_SendCmnd(LCD_DISPLAYON);
        MCAL_SYSTICK_DelayMS(1);
        LCD_SendCmnd(LCD_CLEAR);
        MCAL_SYSTICK_DelayMS(1);
        LCD_SendCmnd(LCD_ENTRYMODE);
        MCAL_SYSTICK_DelayMS(1);

        // Update function status to indicate successful initialization
        Local_FunctionStatus = E_OK;

    #else
        // Update function status to indicate initialization failure due to incorrect mode configuration
        Local_FunctionStatus = E_NOT_OK;

    #endif

    // Return the function status indicating the success or failure of the initialization
    return Local_FunctionStatus;
}
/**
 * @brief Sends a command to the LCD module.
 *
 * @param[in] Copy_Cmnd The command to be sent to the LCD.
 * @retval Std_ReturnType returns E_OK if the command sending is successful, E_NOK if an error occurs during the process.
 */
Std_ReturnType LCD_SendCmnd(u8 Copy_Cmnd)
{
    // Variable to track the function status, initially set to E_NOT_OK
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    // Check the configured LCD mode and send the command accordingly
    #if LCD_MODE == LCD_MODE_8_BIT
        // Set RS and RW pins to low for command transmission
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_LOW);
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, GPIO_LOW);

        // Set data pins with bits from the command
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_Cmnd, 7));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_Cmnd, 6));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_Cmnd, 5));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_Cmnd, 4));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D3_PIN, GET_BIT(Copy_Cmnd, 3));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D2_PIN, GET_BIT(Copy_Cmnd, 2));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D1_PIN, GET_BIT(Copy_Cmnd, 1));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D0_PIN, GET_BIT(Copy_Cmnd, 0));

        // Pulse the E pin to send the command
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_HIGH);
        MCAL_SYSTICK_DelayMS(2); // Delay for LCD processing
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_LOW);

        // Update function status to indicate successful command transmission
        Local_FunctionStatus = E_OK;

    #elif LCD_MODE == LCD_MODE_4_BIT
        // Set RS pin to low for command transmission
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_LOW);

        // Set data pins with higher nibble of the command
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_Cmnd, 7));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_Cmnd, 6));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_Cmnd, 5));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_Cmnd, 4));

        // Pulse the E pin to send higher nibble of the command
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_HIGH);
        MCAL_SYSTICK_DelayMS(2); // Delay for LCD processing
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_LOW);

        // Set data pins with lower nibble of the command
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_Cmnd, 3));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_Cmnd, 2));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_Cmnd, 1));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_Cmnd, 0));

        // Pulse the E pin to send lower nibble of the command
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_HIGH);
        MCAL_SYSTICK_DelayMS(2); // Delay for LCD processing
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_LOW);

        // Update function status to indicate successful command transmission
        Local_FunctionStatus = E_OK;

    #else
        // Update function status to indicate transmission failure due to incorrect mode configuration
        Local_FunctionStatus = E_NOT_OK;

    #endif

    // Return the function status indicating the success or failure of the command transmission
    return Local_FunctionStatus;
}
/**
 * @brief Sends a character to the LCD module.
 *
 * @param[in] Copy_Data The character data to be sent to the LCD for display.
 * @retval Std_ReturnType returns E_OK if the character sending is successful, E_NOK if an error occurs during the process.
 */
Std_ReturnType LCD_SendChar(u8 Copy_Data)
{
    // Variable to track the function status, initially set to E_NOT_OK
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    // Check the configured LCD mode and send the character accordingly
    #if LCD_MODE == LCD_MODE_8_BIT
        // Set RS pin high for character transmission
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_HIGH);
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, GPIO_LOW);

        // Set data pins with bits from the character
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_Data, 7));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_Data, 6));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_Data, 5));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_Data, 4));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D3_PIN, GET_BIT(Copy_Data, 3));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D2_PIN, GET_BIT(Copy_Data, 2));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D1_PIN, GET_BIT(Copy_Data, 1));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D0_PIN, GET_BIT(Copy_Data, 0));

        // Pulse the E pin to send the character
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_HIGH);
        MCAL_SYSTICK_DelayMS(2); // Delay for LCD processing
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_LOW);

        // Update function status to indicate successful character transmission
        Local_FunctionStatus = E_OK;

    #elif LCD_MODE == LCD_MODE_4_BIT
        // Set RS pin high for character transmission
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_HIGH);

        // Set data pins with higher nibble of the character
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_Data, 7));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_Data, 6));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_Data, 5));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_Data, 4));

        // Pulse the E pin to send higher nibble of the character
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_HIGH);
        MCAL_SYSTICK_DelayMS(2); // Delay for LCD processing
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_LOW);

        // Set data pins with lower nibble of the character
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_Data, 3));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_Data, 2));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_Data, 1));
        MCAL_GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_Data, 0));

        // Pulse the E pin to send lower nibble of the character
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_HIGH);
        MCAL_SYSTICK_DelayMS(2); // Delay for LCD processing
        MCAL_GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_LOW);

        // Update function status to indicate successful character transmission
        Local_FunctionStatus = E_OK;

    #else
        // Update function status to indicate transmission failure due to incorrect mode configuration
        Local_FunctionStatus = E_NOT_OK;

    #endif

    // Return the function status indicating the success or failure of the character transmission
    return Local_FunctionStatus;
}
/**
 * @brief Sends a string of characters to the LCD module.
 *
 * @param[in] Copy_String Pointer to the string of characters to be displayed on the LCD.
 * @retval Std_ReturnType returns E_OK if the string sending is successful, E_NOK if an error occurs during the process.
 */ 
Std_ReturnType LCD_SendString (u8* Copy_String)
{
    // Variable to track the function status, initially set to E_NOT_OK
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    u8 Local_i = 0; // Initialize Local_i to 0 to start iterating through the string

    // Loop through each character in the string until the null terminator is encountered
    for (Local_i; Copy_String[Local_i] != '\0'; Local_i++) {
        // Send each character of the string to be displayed on the LCD
        LCD_SendChar(Copy_String[Local_i]);
    }

    // All characters sent successfully, update function status to indicate success
    Local_FunctionStatus = E_OK;

    // Return the function status indicating the success or failure of string transmission
    return Local_FunctionStatus;
}
/**
 * @brief Sends an integer value to be displayed on the LCD.
 *
 * @param[in] Copy_Data The integer value to be displayed on the LCD.
 * @retval Std_ReturnType returns E_OK if the integer sending is successful, E_NOK if an error occurs during the process.
 */
Std_ReturnType LCD_SendIntger(s32 Copy_Data)
{
    // Variable to track the function status, initially set to E_NOT_OK
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    u32 Local_str[10]; // Array to hold the string representation of the integer

    itoa(Copy_Data, Local_str, 10); // Convert the integer to a string (base 10)

    // Send the string representation of the integer to be displayed on the LCD
    LCD_SendString((u8*)Local_str); // Assuming LCD_SendString function expects a u8* type

    // Update function status to indicate successful transmission of the integer
    Local_FunctionStatus = E_OK;

    // Return the function status indicating the success or failure of integer transmission
    return Local_FunctionStatus;
}
/**
 * @brief Sends a floating-point value to be displayed on the LCD.
 *
 * @param[in] Copy_Data The floating-point value to be displayed on the LCD.
 * @retval Std_ReturnType returns E_OK if the floating-point sending is successful, E_NOK if an error occurs during the process.
 */
Std_ReturnType LCD_SendFloat(f64 Copy_Data)
{
    // Variable to track the function status, initially set to E_NOT_OK
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    s32 Local_int_part;   // Variable to hold the integer part of the floating-point value
    f32 Local_frac_part;  // Variable to hold the fractional part of the floating-point value

    // Separate the floating-point value into its integer and fractional parts
    Local_int_part = (s32)Copy_Data;
    Local_frac_part = Copy_Data - Local_int_part;
    Local_frac_part = (s32)(Local_frac_part * 1000); // Scale up the fractional part

    // Send the integer part of the floating-point value to the LCD
    LCD_SendInteger(Local_int_part);

    // Send the decimal point to the LCD
    LCD_SendChar('.');

    // Send the scaled-up fractional part to the LCD
    LCD_SendInteger(Local_frac_part);

    // Update function status to indicate successful transmission of the floating-point value
    Local_FunctionStatus = E_OK;

    // Return the function status indicating the success or failure of floating-point value transmission
    return Local_FunctionStatus;
}
/**
 * @brief Positions the cursor to a specific coordinate (X, Y) on the LCD display.
 *
 * @param[in] Copy_Y The vertical position (row) on the LCD.
 * @param[in] Copy_X The horizontal position (column) on the LCD.
 * @retval Std_ReturnType returns E_OK if cursor positioning is successful, E_NOK if an error occurs during the process.
 */
Std_ReturnType LCD_Gotoyx(u8 Copy_Y,u8 Copy_X)
{
    // Variable to track the function status, initially set to E_NOT_OK
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    u8 Local_Address = 0; // Variable to hold the calculated LCD address

    // Check if the provided row (Y) and column (X) values are within valid range
    if (Copy_Y < 2 && Copy_X < 16) {
        // Calculate the corresponding address based on row and column
        Local_Address = (Copy_Y * 0x40) + Copy_X;
        Local_Address = SetBit(Local_Address, 7); // Set bit 7 for addressing the DDRAM

        // Send command to the LCD to set the cursor to the calculated position
        LCD_SendCommand(Local_Address);

        // Update function status to indicate successful cursor positioning
        Local_FunctionStatus = E_OK;
    }

    // Return the function status indicating the success or failure of cursor positioning
    return Local_FunctionStatus;
}
/**
 * @brief Writes a custom special character to a specific position (X, Y) on the LCD.
 *
 * @param[in] Copy_Pattern Pointer to the array representing the pattern of the special character.
 * @param[in] Copy_PatternNumber The pattern number of the custom character (usually 0-7).
 * @param[in] Copy_XPos The horizontal position (column) on the LCD.
 * @param[in] Copy_YPos The vertical position (row) on the LCD.
 * @retval Std_ReturnType returns E_OK if writing the special character is successful, E_NOK if an error occurs during the process.
 */
Std_ReturnType LCD_WriteSpecialCharacter(u8* Copy_Pattern, u8 Copy_PatternNumber,u8 Copy_XPos,u8 Copy_YPos)
{
    // Variable to track the function status, initially set to E_NOT_OK
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    u8 Local_Address, Local_PatternCounter; // Variables for address and pattern counter

    // Calculate the address in CGRAM based on the pattern number (each pattern occupies 8 bytes)
    Local_Address = Copy_PatternNumber * 8;

    // Set CGRAM Address with bit 6 = 1 and bit 7 = 0 (CGRAM addresses range from 0x40 to 0x7F)
    LCD_SendCommand(Local_Address + 64);

    // Write the required pattern data inside the CGRAM
    for (Local_PatternCounter = 0; Local_PatternCounter < 8; Local_PatternCounter++) {
        LCD_SendChar(Copy_Pattern[Local_PatternCounter]);
    }

    // Shift the address counter to DDRAM to prepare for character display
    LCD_Gotoyx(Copy_YPos, Copy_XPos);

    // Display the CGRAM pattern on the LCD at the specified position
    LCD_SendChar(Copy_PatternNumber);

    // Update function status to indicate successful writing and displaying of the custom character pattern
    Local_FunctionStatus = E_OK;

    // Return the function status indicating the success or failure of the operation
    return Local_FunctionStatus;
}
