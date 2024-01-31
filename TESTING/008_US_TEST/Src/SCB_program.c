/****************************************************************/
/******* Author    : Mohamed Ali Bayoumi        *****************/
/******* Date      : 21 OCT 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : SCB_program.c              *****************/
/****************************************************************/
/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************************** MCAL *****************************************************/
#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_SCB_SetPriorityGrouping(u32 Copy_PrioirtyGrouping)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    SCB_AIRCR=Copy_PrioirtyGrouping;
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void EnableGlobalInterrupts()
{
    __asm volatile ("cpsie i");
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void DisableGlobalInterrupts()
{
    __asm volatile ("cpsid i");
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_SCB_EnableMemFault()
{   
     Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    SCB_SHCSR |= ( 1 << SCB_SHCSR_MEMFAULTENA_POS );
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_SCB_EnableBusFault()
{
     Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    SCB_SHCSR |= ( 1 << SCB_SHCSR_BUSFAULTENA_POS );
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_SCB_EnableUsageFault()
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    SCB_SHCSR |= ( 1 << SCB_SHCSR_USGFAULTENA_POS );
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_SCB_ClearBusFault()
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;\
    SCB_SHCSR &= ~( 1 << SCB_SHCSR_BUSFAULTENA_POS );
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_SCB_ClearMemFault()
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    SCB_SHCSR &= ~( 1 << SCB_SHCSR_MEMFAULTENA_POS );
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_SCB_ClearUsageFault()
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    SCB_SHCSR &= ~( 1 << SCB_SHCSR_USGFAULTENA_POS );
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
