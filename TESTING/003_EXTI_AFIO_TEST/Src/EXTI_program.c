/**
 * @brief This module contains functions for configuring and controlling the External Interrupt (EXTI) peripheral.
 *
 * @author Mohamed Ali Bayoumi
 * @date 25 OCT 2024
 * @version V01
 *
 * This module provides functions for configuring the interrupt source, trigger type, and enabling/disabling EXTI lines.
 * It also includes functions for clearing the EXTI pending flag and getting the interrupt status. It is designed to be
 * used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************************** MCAL *****************************************************/
/**< GPIO */
#include "GPIO_interface.h"
/**< AFIO */
#include "AFIO_interface.h"
/**< GPIO */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
/**************************************** Global Variables Section *****************************************************/
static EXTI_CallbackFunc_t EXTI_Callback[16] = {NULL};
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_Init(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    for (u8 line = 0; line < EXTI_LINES_COUNT; line++)
    {
        if( Exti_Configrations[line].LineEnabled == EXTI_LINE_ENABLED)
        {
            MCAL_EXTI_EnableLine(line);
            MCAL_EXTI_SetTrigger(line,Exti_Configrations[line].TriggerType);
            MCAL_EXTI_SetCallback(line , Exti_Configrations[line].SetCallback);
            MCAL_AFIO_SetEXTIConfigration(line , Exti_Configrations[line].GPIO_PortMap);
            Local_FunctionStatus = E_OK;
        }else
        {
            MCAL_EXTI_DisableLine(line);
            Local_FunctionStatus = E_OK;
        }
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_EnableLine(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < EXTI_LINES_COUNT)
    {
        
        SET_BIT( EXTI->IMR , Copy_Line );
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_DisableLine(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < EXTI_LINES_COUNT)
    {
        
        CLR_BIT( EXTI->IMR , Copy_Line );
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_SetTrigger(u8 Copy_Line , u8 TriggerType)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < EXTI_LINES_COUNT)
    {
        switch (TriggerType)
        {
        case EXTI_RISING_EDGE:
            SET_BIT(EXTI->RTSR , Copy_Line);
            CLR_BIT(EXTI->FTSR , Copy_Line);
            Local_FunctionStatus = E_OK;
            break;
        case EXTI_FALLING_EDGE:
            CLR_BIT(EXTI->RTSR , Copy_Line);
            SET_BIT(EXTI->FTSR , Copy_Line);
            Local_FunctionStatus = E_OK;
            break;
        case EXTI_BOTH_EDGE:
            SET_BIT(EXTI->RTSR , Copy_Line);
            SET_BIT(EXTI->FTSR , Copy_Line);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_ClearPending(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < EXTI_LINES_COUNT)
    {
        
        SET_BIT( EXTI->PR , Copy_Line );
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_SW_INT(u8 Copy_Line)
{   
     Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < EXTI_LINES_COUNT)
    {
        
        SET_BIT( EXTI->SWIER , Copy_Line );
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_EnableEvent(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < EXTI_LINES_COUNT)
    {
        
        SET_BIT( EXTI->EMR , Copy_Line );
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_DisablEvent(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < EXTI_LINES_COUNT)
    {
        
        CLR_BIT( EXTI->EMR , Copy_Line );
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_EXTI_SetCallback(u8 Copy_Line , EXTI_CallbackFunc_t CallbackFunc)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if(CallbackFunc == NULL)
    {
        return Local_FunctionStatus;
    }
    EXTI_Callback[Copy_Line] = CallbackFunc;
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI0_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE0]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI1_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE1]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI2_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE2]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI3_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE3]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI4_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE4]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI5_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE5]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI6_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE6]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI7_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE7]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI8_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE8]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI9_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE9]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI10_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE10]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI11_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE11]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI12_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE12]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI13_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE13]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI14_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE14]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI15_IRQHandler(void)
{
    if (EXTI_Callback != NULL)
    {
        EXTI_Callback[EXTI_LINE15]();
    }
}
/*====================================================   END_FUNCTION   ====================================================*/
