/***************************************************************************************************/
/************************* Author  : Mohamed Ali Bayoumi    ****************************************/
/************************* Date    : 6/10/2023              ****************************************/
/************************* Version : 0.1                    ****************************************/
/************************* MODULE  : MCAL_GPIO_interface.h  ****************************************/
/***************************************************************************************************/
#ifndef MCAL_GPIO_INTERFACE_H_
#define MCAL_GPIO_INTERFACE_H_



#define GPIO_PORTA              0
#define GPIO_PORTB              1
#define GPIO_PORTC              2

#define GPIO_PIN0               0
#define GPIO_PIN1               1
#define GPIO_PIN2               2
#define GPIO_PIN3               3
#define GPIO_PIN4               4
#define GPIO_PIN5               5
#define GPIO_PIN6               6
#define GPIO_PIN7               7
#define GPIO_PIN8               8
#define GPIO_PIN9               9
#define GPIO_PIN10              10
#define GPIO_PIN11              11
#define GPIO_PIN12              12
#define GPIO_PIN13              13
#define GPIO_PIN14              14
#define GPIO_PIN15              15

#define GPIO_INPUT_ANALOG_MODE              0b0000
#define GPIO_INPUT_FLOATING_MODE            0b0100
#define GPIO_INPUT_PULL_UP_MODE             0b1000
#define GPIO_INPUT_PULL_DOWN_MODE           0b1000

#define GPIO_OUTPUT_LOW_SPEED_PUSHPULL      0b0001
#define GPIO_OUTPUT_LOW_SPEED_OPEN_DRAIN    0b0101
#define GPIO_OUTPUT_LOW_SPEED_AF_PP         0b1001
#define GPIO_OUTPUT_LOW_SPEED_AF_OD         0b1101
#define GPIO_OUTPUT_MID_SPEED_PUSHPULL      0b0010
#define GPIO_OUTPUT_MID_SPEED_OPEN_DRAIN    0b0110
#define GPIO_OUTPUT_MID_SPEED_AF_PP         0b1010
#define GPIO_OUTPUT_MID_SPEED_AF_OD         0b1110
#define GPIO_OUTPUT_HIGH_SPEED_PUSHPULL     0b0011
#define GPIO_OUTPUT_HIGH_SPEED_OPEN_DRAIN   0b0111
#define GPIO_OUTPUT_HIGH_SPEED_AF_PP        0b1011
#define GPIO_OUTPUT_HIGH_SPEED_AF_OD        0b1111

#define GPIO_LOW                                  0
#define GPIO_HIGH                                 1
                  
#define GPIO_UNLOCKED                             0
#define GPIO_LOCKED                               1


Std_ReturnType Mcal_GPIO_SetPinMode(u8 Copy_PortID , u8 Copy_PinID , u8 Copy_PinMode);
Std_ReturnType Mcal_GPIO_SetPinValue(u8 Copy_PortID , u8 Copy_PinID , u8 Copy_PinValue);
Std_ReturnType Mcal_GPIO_GetPinValue(u8 Copy_PortID , u8 Copy_PinID , u8 *Copy_PinReturnValue);
Std_ReturnType Mcal_GPIO_AtomicSetPin(u8 Copy_PortID , u8 Copy_PinID );
Std_ReturnType Mcal_GPIO_AtomicResetPin(u8 Copy_PortID , u8 Copy_PinID );
Std_ReturnType Mcal_GPIO_LCKPin(u8 Copy_PortID , u8 Copy_PinID ,u8 Copy_PinState);


#endif /* MCAL_GPIO_INTERFACE_H_ */
