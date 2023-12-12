/**
 * @brief This module contains functions for configuring the Nested Vectored Interrupt Controller (NVIC).
 *
 * @author Mohamed Ali Bayoumi
 * @date 20 OCT 2023
 * @version V01
 *
 * This module provides functions for enabling and disabling interrupts, setting interrupt priorities, and other
 * configuration options for the NVIC. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */

/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************************** MCAL *****************************************************/
#include "SCB_interface.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if( Copy_IRQn >= NVIC_WWDG_IRQn && Copy_IRQn <= NVIC_I2C1_EV_IRQn)
    {
        NVIC_ISER0 = (1 << Copy_IRQn);
        Local_FunctionStatus=E_OK;
    }
    else if ( Copy_IRQn >= NVIC_I2C1_ER_IRQn && Copy_IRQn <= 63)
    {
        NVIC_ISER1 = (1 << (Copy_IRQn-32));
        Local_FunctionStatus=E_OK;
    }
    else if(Copy_IRQn >= 64 && Copy_IRQn <= 67)
    {
        NVIC_ISER2 = (1 << (Copy_IRQn-64));
        Local_FunctionStatus=E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if( Copy_IRQn >= NVIC_WWDG_IRQn && Copy_IRQn <= NVIC_I2C1_EV_IRQn)
    {
        NVIC_ICER0 = (1 << Copy_IRQn);
        Local_FunctionStatus=E_OK;
    }
    else if ( Copy_IRQn >= NVIC_I2C1_ER_IRQn && Copy_IRQn <= 63)
    {
        NVIC_ICER1 = (1 << (Copy_IRQn-32));
        Local_FunctionStatus=E_OK;

    }
    else if(Copy_IRQn >= 64 && Copy_IRQn <= 67)
    {
        NVIC_ICER2 = (1 << (Copy_IRQn-64));
        Local_FunctionStatus=E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if( Copy_IRQn >= NVIC_WWDG_IRQn && Copy_IRQn <= NVIC_I2C1_EV_IRQn)
    {
        NVIC_ISPR0 = (1 << Copy_IRQn);
        Local_FunctionStatus=E_OK;
    }
    else if ( Copy_IRQn >= NVIC_I2C1_ER_IRQn && Copy_IRQn <= 63)
    {
        NVIC_ISPR1 = (1 << (Copy_IRQn-32));
        Local_FunctionStatus=E_OK;

    }
    else if(Copy_IRQn >= 64 && Copy_IRQn <= 67)
    {
        NVIC_ISPR2 = (1 << (Copy_IRQn-64));
        Local_FunctionStatus=E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if( Copy_IRQn >= NVIC_WWDG_IRQn && Copy_IRQn <= NVIC_I2C1_EV_IRQn)
    {
        NVIC_ICPR0 = (1 << Copy_IRQn);
        Local_FunctionStatus=E_OK;
    }
    else if ( Copy_IRQn >= NVIC_I2C1_ER_IRQn && Copy_IRQn <= 63)
    {
        NVIC_ICPR1 = (1 << (Copy_IRQn-32));
        Local_FunctionStatus=E_OK;

    }
    else if(Copy_IRQn >= 64 && Copy_IRQn <= 67)
    {
        NVIC_ICPR2 = (1 << (Copy_IRQn-64));
        Local_FunctionStatus=E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn , u8* PendingIRQ)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if( Copy_IRQn >= NVIC_WWDG_IRQn && Copy_IRQn <= NVIC_I2C1_EV_IRQn)
    {
        *PendingIRQ = NVIC_ISPR0 & (1 << Copy_IRQn);
        Local_FunctionStatus=E_OK;
    }
    else if ( Copy_IRQn >= NVIC_I2C1_ER_IRQn && Copy_IRQn <= 63)
    {
        *PendingIRQ = NVIC_ISPR1 & (1 << (Copy_IRQn - 32) );
        Local_FunctionStatus=E_OK;

    }
    else if(Copy_IRQn >= 64 && Copy_IRQn <= 67)
    {
        *PendingIRQ = NVIC_ISPR2 & (1 << (Copy_IRQn - 64 ) );
        Local_FunctionStatus=E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_NVIC_GetActiveIRQ(IRQn_Type Copy_IRQn , u8* ActiveIRQ)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if( Copy_IRQn >= NVIC_WWDG_IRQn && Copy_IRQn <= NVIC_I2C1_EV_IRQn)
    {
        *ActiveIRQ = NVIC_IABR0 & (1 << Copy_IRQn);
        Local_FunctionStatus=E_OK;
    }
    else if ( Copy_IRQn >= NVIC_I2C1_ER_IRQn && Copy_IRQn <= 63)
    {
        *ActiveIRQ = NVIC_IABR1 & (1 << (Copy_IRQn - 32) );
        Local_FunctionStatus=E_OK;
    }
    else if(Copy_IRQn >= 64 && Copy_IRQn <= 67)
    {
        *ActiveIRQ = NVIC_IABR2 & (1 << (Copy_IRQn - 64 ));
        Local_FunctionStatus=E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_NVIC_xSetPriority(IRQn_Type Copy_IRQn , u32 Copy_Priority)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_IRQn < NUMBER_OF_INTERRUPTS && Copy_Priority <= MAX_PRIORITY)
    {
        NVIC_IPR_Base_Address[Copy_IRQn / 4] = ((Copy_Priority << ((Copy_IRQn % 4)*8))<<4) ;
        MCAL_SCB_SetPriorityGrouping(NVIC_0GROUP_16SUB);
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_NVIC_vSetPriority(IRQn_Type Copy_IRQn , u8 Copy_GroupPriority , u8 Copy_SubPriority )
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    u8 NVIC_MAX_GROUP_PRIORITY,NVIC_MAX_SUB_PRIORITY;
    #if NVIC_PRIORITY_GROUPS == NVIC_16GROUP_0SUB
        Local_PrioirtyNum = Copy_GroupPriority;
        NVIC_MAX_GROUP_PRIORITY=16;
        NVIC_MAX_SUB_PRIORITY=0;
    #elif NVIC_PRIORITY_GROUPS == NVIC_8GROUP_2SUB
        Copy_GroupPriority= ((Copy_GroupPriority << 1) | Copy_SubPriority);
        NVIC_MAX_GROUP_PRIORITY=8;
        NVIC_MAX_SUB_PRIORITY=2;
    #elif NVIC_PRIORITY_GROUPS == NVIC_4GROUP_4SUB
        Copy_GroupPriority= ((Copy_GroupPriority << 2) | Copy_SubPriority);
        NVIC_MAX_GROUP_PRIORITY=4;
        NVIC_MAX_SUB_PRIORITY=4;
    #elif NVIC_PRIORITY_GROUPS == NVIC_2GROUP_8SUB
        Copy_GroupPriority= ((Copy_GroupPriority << 3) | Copy_SubPriority);
        NVIC_MAX_GROUP_PRIORITY=2;
        NVIC_MAX_SUB_PRIORITY=8;
    #elif NVIC_PRIORITY_GROUPS == NVIC_0GROUP_16SUB
        Copy_GroupPriority= Copy_SubPriority;
        NVIC_MAX_GROUP_PRIORITY=0;
        NVIC_MAX_SUB_PRIORITY=16;
    #else
    #error "Wrong Grouping"
    #endif
    if( Copy_IRQn > 0 && Copy_GroupPriority < NVIC_MAX_GROUP_PRIORITY && Copy_SubPriority < NVIC_MAX_SUB_PRIORITY)
    {
        NVIC_IPR_Base_Address[Copy_IRQn / 4] = ((Copy_GroupPriority << (((Copy_IRQn % 4) * 8))<<4)) ;
        Local_FunctionStatus = E_OK;
    }
    else{
        Local_FunctionStatus = E_NOT_OK;
    }
    MCAL_SCB_SetPriorityGrouping(NVIC_PRIORITY_GROUPS);
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType MCAL_NVIC_GetPriority(IRQn_Type Copy_IRQn , u8* Priority)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_IRQn < 0 )
    {
        return Local_FunctionStatus;
    }
    u8* Local_PriorityREG= (u8*) &NVIC_IPR_Base_Address[Copy_IRQn / 4];
    *Priority = ( ( Local_PriorityREG[Copy_IRQn % 4] >> ((Copy_IRQn % 4) * 8 )) >> 4);
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
