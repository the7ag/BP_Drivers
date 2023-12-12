/**
 * @brief This module contains functions for configuring and controlling General Purpose Input/Output (GPIO) pins.
 *
 * @author Mohamed Ali Bayoumi
 * @date 6 oct 2023
 * @version V01
 *
 * This module provides functions for configuring the mode, speed, and pull-up/down resistors of GPIO pins,
 * as well as reading and writing their values. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */


/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************************** MCAL *****************************************************/
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_GPIO_SetPinMode(u8 Copy_PortID , u8 Copy_PinID , u8 Copy_PinMode)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch (Copy_PortID)
    {
    case GPIO_PORTA:
        if( Copy_PinID < 8 )
        {
            MCAL_GPIOA->CRL &= ~( (0b1111) << (Copy_PinID*4) );
            MCAL_GPIOA->CRL |= ( (Copy_PinMode) << (Copy_PinID*4) );
            Local_FunctionStatus = E_OK;
        }else if ( Copy_PinID < 16)
        {
            MCAL_GPIOA->CRH &= ~( (0b1111) << (Copy_PinID*4) );
            MCAL_GPIOA->CRH |= ( (Copy_PinMode) << (Copy_PinID*4) );
            Local_FunctionStatus = E_OK;
        }
        else
        {
            Local_FunctionStatus = E_NOT_OK;
        }
    break;
    case GPIO_PORTB:
        if( Copy_PinID < 8 )
        {
            MCAL_GPIOB->CRL &= ~( (0b1111) << (Copy_PinID*4) );
            MCAL_GPIOB->CRL |= ( (Copy_PinMode) << (Copy_PinID*4) );
            Local_FunctionStatus = E_OK;
        }else if ( Copy_PinID < 16)
        {
            MCAL_GPIOB->CRH &= ~( (0b1111) << (Copy_PinID*4) );
            MCAL_GPIOB->CRH |= ( (Copy_PinMode) << (Copy_PinID*4) );
            Local_FunctionStatus = E_OK;
        }
        else
        {
            Local_FunctionStatus = E_NOT_OK;
        }
    break;
    case GPIO_PORTC:
        if( Copy_PinID < 8 )
        {
            MCAL_GPIOC->CRL &= ~( (0b1111) << (Copy_PinID*4) );
            MCAL_GPIOC->CRL |= ( (Copy_PinMode) << (Copy_PinID*4) );
            Local_FunctionStatus = E_OK;
        }else if ( Copy_PinID < 16)
        {
            MCAL_GPIOC->CRH &= ~( (0b1111) << (Copy_PinID*4) );
            MCAL_GPIOC->CRH |= ( (Copy_PinMode) << (Copy_PinID*4) );
            Local_FunctionStatus = E_OK;
        }
        else
        {
            Local_FunctionStatus = E_NOT_OK;
        }
    break;
    default:
            Local_FunctionStatus = E_NOT_OK;
    break;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_GPIO_SetPinValue(u8 Copy_PortID , u8 Copy_PinID , u8 Copy_PinValue)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch (Copy_PortID)
    {
    case GPIO_PORTA:
        switch (Copy_PinValue)
        {
        case GPIO_HIGH:
            SET_BIT( (MCAL_GPIOA->ODR) , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_LOW:
            CLR_BIT( (MCAL_GPIOA->ODR) , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }
    break;
    case GPIO_PORTB:
        switch (Copy_PinValue)
        {
        case GPIO_HIGH:
            SET_BIT(MCAL_GPIOB->ODR , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_LOW:
            CLR_BIT(MCAL_GPIOB->ODR , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }
    break;
    case GPIO_PORTC:
        switch (Copy_PinValue)
        {
        case GPIO_HIGH:
            SET_BIT(MCAL_GPIOC->ODR , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_LOW:
            CLR_BIT(MCAL_GPIOC->ODR , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }
    break;
    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_GPIO_GetPinValue(u8 Copy_PortID , u8 Copy_PinID , u8 *Copy_PinReturnValue)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if(Copy_PinReturnValue != NULL){
        switch (Copy_PortID)
        {
        case GPIO_PORTA:
            *Copy_PinReturnValue = GET_BIT(MCAL_GPIOA->IDR , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_PORTB:
            *Copy_PinReturnValue = GET_BIT(MCAL_GPIOB->IDR , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_PORTC:
            *Copy_PinReturnValue = GET_BIT(MCAL_GPIOC->IDR , Copy_PinID);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_GPIO_AtomicSetPin(u8 Copy_PortID , u8 Copy_PinID )
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch (Copy_PortID)
    {
    case GPIO_PORTA:
        SET_BIT(MCAL_GPIOA->BSRR , Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;
    case GPIO_PORTB:
        SET_BIT(MCAL_GPIOB->BSRR , Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;
    case GPIO_PORTC:
        SET_BIT(MCAL_GPIOC->BSRR , Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;
    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_GPIO_AtomicResetPin(u8 Copy_PortID , u8 Copy_PinID )
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch (Copy_PortID)
    {
    case GPIO_PORTA:
        SET_BIT(MCAL_GPIOA->BRR , Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;
    case GPIO_PORTB:
        SET_BIT(MCAL_GPIOB->BRR , Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;
    case GPIO_PORTC:
        SET_BIT(MCAL_GPIOC->BRR , Copy_PinID);
        Local_FunctionStatus = E_OK;
        break;
    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/


Std_ReturnType MCAL_GPIO_LCKPin(u8 Copy_PortID , u8 Copy_PinID ,u8 Copy_PinState)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch (Copy_PortID)
    {
    case GPIO_PORTA:
        if(Copy_PinState == GPIO_LOCKED)
        {SET_BIT(MCAL_GPIOA->LCKR , Copy_PinID);}
        else if( Copy_PinState == GPIO_UNLOCKED)
        {CLR_BIT(MCAL_GPIOA -> LCKR , Copy_PinID);}
        SET_BIT(MCAL_GPIOA->LCKR , LCKK);
        CLR_BIT(MCAL_GPIOA->LCKR , LCKK);
        SET_BIT(MCAL_GPIOA->LCKR , LCKK);
        while(!GET_BIT(MCAL_GPIOA->LCKR , LCKK));
        Local_FunctionStatus = E_OK;
        break;
    case GPIO_PORTB:
        if(Copy_PinState == GPIO_LOCKED)
        {SET_BIT(MCAL_GPIOB->LCKR , Copy_PinID);}
        else if(Copy_PinState == GPIO_UNLOCKED)
        {CLR_BIT(MCAL_GPIOB->LCKR , Copy_PinID);}
        SET_BIT(MCAL_GPIOB->LCKR , LCKK);
        CLR_BIT(MCAL_GPIOB->LCKR , LCKK);
        SET_BIT(MCAL_GPIOB->LCKR , LCKK);
        while(!GET_BIT(MCAL_GPIOB->LCKR , LCKK));
        Local_FunctionStatus = E_OK;
        break;
    case GPIO_PORTC:
        if(Copy_PinState == GPIO_LOCKED)
        {SET_BIT(MCAL_GPIOC->LCKR , Copy_PinID);}
        else if(Copy_PinState == GPIO_UNLOCKED)
        {CLR_BIT(MCAL_GPIOC->LCKR , Copy_PinID);}
        SET_BIT(MCAL_GPIOC->LCKR , LCKK);
        CLR_BIT(MCAL_GPIOC->LCKR , LCKK);
        SET_BIT(MCAL_GPIOC->LCKR , LCKK);
        while(!GET_BIT(MCAL_GPIOC->LCKR , LCKK));
        Local_FunctionStatus = E_OK;
        break;
    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   END_ FILE   ====================================================*/
