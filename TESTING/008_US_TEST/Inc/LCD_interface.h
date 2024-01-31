/**
 * @file LCD_interface.h
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
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_CLEAR         	    0x01          /* replace all characters with ASCII 'space'                       */
#define LCD_HOME            	0x02          /* return cursor to first position on first line                   */
#define LCD_ENTRYMODE       	0x06          // shift cursor from left to right on read/write
#define LCD_DISPLAYOFF      	0x08          // turn display off
#define LCD_DISPLAYON       	0x0C          // display on, cursor off, don't blink character
#define LCD_FUNCTIONRESET   	0x30          // reset the LCD
#define LCD_FUNCTIONSET8BIT 	0x38          // 8-bit data, 2-line display, 5 x 7 font
#define LCD_FUNCTIONSET4BIT 	0x28          // 4-bit data, 2-line display, 5 x 7 font
#define LCD_SETCURSOR     	    0x80          // set cursor position
#define LCD_SHIFTDISPLAYLEFT	0x18		  //Moving the entire display from left to right
#define LCD_SHIFTDISPLAYRIGHT	0x1C		  //Moving the entire display from right to right
#define LCD_SHIFTCURSORRIGHT	0X14		  //Moving cursor to right
#define LCD_SHIFTCURSORLEFT		0x10		  //Moving cursor to left
/***********************************< FUNCTIONS PROTOTYPES AND DESCRIPTION ***********************************/
/**
 * @brief Initializes the LCD module connected to the microcontroller.
 *
 * This function initializes the LCD module connected to the microcontroller, setting up necessary configurations
 * such as communication protocols, pins, and internal settings to enable proper functioning of the LCD.
 *
 * @retval Std_ReturnType returns E_OK if the LCD initialization is successful, E_NOK if an error occurs during initialization.
 *
 * @note Ensure proper hardware connections and pin configurations before calling this function.
 *       This function might involve specific timing requirements or initial setup procedures that need to be met.
 *
 * @par Example:
 *      To initialize the connected LCD module, use the following code:
 *      @code
 *      if (LCD_Init() == E_OK) {
 *          // LCD initialization successful, perform further actions
 *      } else {
 *          // Handle LCD initialization failure
 *      }
 *      @endcode
 */
Std_ReturnType LCD_Init(void);
/**
 * @brief Sends a command to the LCD module.
 *
 * This function sends a specific command to the connected LCD module using a 16-bit unsigned integer value.
 * The command is responsible for instructing the LCD to perform certain actions or configurations, such as
 * setting display parameters, positioning the cursor, or executing specific operations.
 *
 * @param[in] Copy_Cmnd A 8-bit unsigned integer representing the command to be sent to the LCD module.
 *
 * @retval Std_ReturnType returns E_OK if the command is successfully sent, E_NOK if an error occurs during the process.
 *
 * @note Ensure that the command passed is compatible with the LCD module's specifications and commands supported.
 *       Verify proper initialization and setup of the LCD module before sending commands.
 *
 * @par Example:
 *      To send a command to the LCD module, use the following code:
 *      @code
 *      u16 commandToSend = 0x01; // Example command value
 *      if (LCD_SendCmnd(commandToSend) == E_OK) {
 *          // Command sent successfully, proceed with further operations if needed
 *      } else {
 *          // Handle command sending failure
 *      }
 *      @endcode
 */
Std_ReturnType LCD_SendCmnd(u8 Copy_Cmnd);
/**
 * @brief Sends a character data to display on the LCD module.
 *
 * This function sends an 8-bit character data to the connected LCD module for display purposes.
 * The character data is typically an ASCII code representing a character to be shown on the LCD screen.
 *
 * @param[in] Copy_Data An 8-bit unsigned integer representing the character data to be displayed on the LCD.
 *
 * @retval Std_ReturnType returns E_OK if the character data is successfully sent for display, E_NOK if an error occurs during the process.
 *
 * @note Ensure proper initialization and setup of the LCD module before sending character data.
 *       Verify the compatibility of the character data with the character set supported by the LCD.
 *
 * @par Example:
 *      To send a character to display on the LCD module, use the following code:
 *      @code
 *      u8 characterToSend = 'A'; // Example character data (ASCII code for 'A')
 *      if (LCD_SendChar(characterToSend) == E_OK) {
 *          // Character sent successfully for display
 *      } else {
 *          // Handle character sending failure
 *      }
 *      @endcode
 */
Std_ReturnType LCD_SendChar(u8 Copy_Data);
/**
 * @brief Sends a string of characters to display on the LCD module.
 *
 * This function sends a null-terminated string of characters to the connected LCD module for display purposes.
 * The string is represented as an array of 8-bit unsigned integers (characters) terminated by a null ('\0') character.
 *
 * @param[in] Copy_String A pointer to an array of 8-bit unsigned integers representing the string to be displayed on the LCD.
 *
 * @retval Std_ReturnType returns E_OK if the string is successfully sent for display, E_NOK if an error occurs during the process.
 *
 * @note Ensure proper initialization and setup of the LCD module before sending the string for display.
 *       Verify the compatibility of the characters in the string with the character set supported by the LCD.
 *       The string passed should be null-terminated to indicate the end of the string.
 *
 * @par Example:
 *      To send a string to display on the LCD module, use the following code:
 *      @code
 *      u8 myString[] = "Hello, LCD!"; // Example string
 *      if (LCD_SendString(myString) == E_OK) {
 *          // String sent successfully for display
 *      } else {
 *          // Handle string sending failure
 *      }
 *      @endcode
 */
Std_ReturnType LCD_SendString (u8* Copy_String);
/**
 * @brief Sends an integer value to display on the LCD module.
 *
 * This function sends a signed 32-bit integer value to the connected LCD module for display purposes.
 * It converts the integer value into a string representation and then sends the string to be displayed on the LCD.
 *
 * @param[in] Copy_Data A signed 32-bit integer representing the data to be displayed on the LCD.
 *
 * @retval Std_ReturnType returns E_OK if the integer value is successfully sent for display, E_NOK if an error occurs during the process.
 *
 * @note Ensure proper initialization and setup of the LCD module before sending the integer value for display.
 *       The function converts the integer value to a string for display; hence, it uses memory for the string representation.
 *
 * @par Example:
 *      To send an integer value to display on the LCD module, use the following code:
 *      @code
 *      s32 myInteger = 12345; // Example integer value
 *      if (LCD_SendInteger(myInteger) == E_OK) {
 *          // Integer value sent successfully for display
 *      } else {
 *          // Handle integer value sending failure
 *      }
 *      @endcode
 */
Std_ReturnType LCD_SendIntger(s32 Copy_Data);
/**
 * @brief Sends a floating-point value to display on the LCD module.
 *
 * This function sends a double precision (64-bit) floating-point value to the connected LCD module for display purposes.
 * It converts the floating-point value into a string representation and then sends the string to be displayed on the LCD.
 *
 * @param[in] Copy_Data A double precision (64-bit) floating-point number representing the data to be displayed on the LCD.
 *
 * @retval Std_ReturnType returns E_OK if the floating-point value is successfully sent for display, E_NOK if an error occurs during the process.
 *
 * @note Ensure proper initialization and setup of the LCD module before sending the floating-point value for display.
 *       The function converts the floating-point value to a string for display; hence, it uses memory for the string representation.
 *
 * @par Example:
 *      To send a floating-point value to display on the LCD module, use the following code:
 *      @code
 *      f64 myFloat = 3.14159; // Example floating-point value
 *      if (LCD_SendFloat(myFloat) == E_OK) {
 *          // Floating-point value sent successfully for display
 *      } else {
 *          // Handle floating-point value sending failure
 *      }
 *      @endcode
 */
Std_ReturnType LCD_SendFloat(f64 Copy_Data);
/**
 * @brief Positions the cursor to a specific coordinate (x, y) on the LCD module.
 *
 * This function positions the cursor to a specific coordinate (x, y) on the connected LCD module.
 * The coordinate system typically represents rows (Y) and columns (X) on the LCD display.
 *
 * @param[in] Copy_Y An 8-bit unsigned integer representing the vertical position (row) on the LCD.
 * @param[in] Copy_X An 8-bit unsigned integer representing the horizontal position (column) on the LCD.
 *
 * @retval Std_ReturnType returns E_OK if the cursor positioning is successful, E_NOK if an error occurs during the process.
 *
 * @note Ensure proper initialization and setup of the LCD module before positioning the cursor.
 *       The coordinate (0, 0) often represents the top-left corner of the LCD display.
 *
 * @par Example:
 *      To position the cursor to coordinates (2, 5) on the LCD module, use the following code:
 *      @code
 *      u8 row = 2;    // Row number (Y-coordinate)
 *      u8 column = 5; // Column number (X-coordinate)
 *      if (LCD_Gotoyx(row, column) == E_OK) {
 *          // Cursor positioned successfully at coordinates (2, 5)
 *      } else {
 *          // Handle cursor positioning failure
 *      }
 *      @endcode
 */
Std_ReturnType LCD_Gotoyx(u8 Copy_Y,u8 Copy_X);
/**
 * @brief Writes a custom special character to a specific position (X, Y) on the LCD module.
 *
 * This function writes a custom special character, defined by a pattern array, to a specified position (X, Y)
 * on the connected LCD module. The function requires the pattern array representing the character, the pattern number,
 * and the position (X, Y) where the character will be displayed.
 *
 * @param[in] Copy_Pattern A pointer to an array of 8-bit unsigned integers representing the pattern of the special character.
 * @param[in] Copy_PatternNumber An 8-bit unsigned integer representing the pattern number of the custom character (usually 0-7).
 * @param[in] Copy_XPos An 8-bit unsigned integer representing the horizontal position (column) on the LCD.
 * @param[in] Copy_YPos An 8-bit unsigned integer representing the vertical position (row) on the LCD.
 *
 * @retval Std_ReturnType returns E_OK if the special character writing is successful, E_NOK if an error occurs during the process.
 *
 * @note Ensure proper initialization and setup of the LCD module before writing the special character.
 *       The pattern array should represent the custom character's bitmap pattern in the LCD's character generator RAM.
 *
 * @par Example:
 *      To write a custom special character pattern to coordinates (2, 4) on the LCD module, use the following code:
 *      @code
 *      u8 myPattern[] = {0x1F, 0x11, 0x15, 0x15, 0x15, 0x15, 0x11, 0x1F}; // Example custom character pattern
 *      u8 patternNumber = 0; // Example pattern number
 *      u8 xPos = 4; // Column number (X-coordinate)
 *      u8 yPos = 2; // Row number (Y-coordinate)
 *      if (LCD_WriteSpecialCharacter(myPattern, patternNumber, xPos, yPos) == E_OK) {
 *          // Custom special character written successfully at coordinates (2, 4)
 *      } else {
 *          // Handle special character writing failure
 *      }
 *      @endcode
 */
Std_ReturnType LCD_WriteSpecialCharacter(u8* Copy_Pattern, u8 Copy_PatternNumber,u8 Copy_XPos,u8 Copy_YPos);

#endif /* LCD_INTERFACE_H_ */