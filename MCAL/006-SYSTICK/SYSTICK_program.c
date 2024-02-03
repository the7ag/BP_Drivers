/**
 * @brief This module contains functions for configuring the system tick core peripheral.
 *
 * @author Mohamed Ali Bayoumi
 * @date 28 OCT 2023
 * @version V01
 *
 * this module is used to enable disaple the systick and setting it's value and setting it's callback function
 * when an interrupt happens
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************************** MCAL *****************************************************/
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
/*====================================================   Global_Variables   ====================================================*/
static SYSTICK_CallbackFunc_t SYSTICK_Callback=NULL;
static u8 SYSTICK_ModeOfInterval;
/*====================================================   Start_FUNCTION   ====================================================*/
/**
 * @defgroup Public_Functions STK Driver
 * @{
 */
Std_ReturnType MCAL_SYSTICK_xINIT(u32 Copy_Ticks)
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /**< Disable SysTick timer */
    SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
    /**< Configure SysTick timer to use the processor clock */
    #if SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_1
        SYSTICK->CTRL |= SYSTICK_CTRL_CLKSRC_MASK; /**< Set bit 2 to use the processor clock */
    #elif SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_8
        SYSTICK->CTRL &= ~SYSTICK_CTRL_CLKSRC_MASK;  /**< Clear bit 2 to use the processor clock/8 */
    #else
        #error "Invalid STK_CTRL_CLKSOURCE value. Please choose STK_CTRL_CLKSOURCE_1 or STK_CTRL_CLKSOURCE_8."
    #endif
    /**< Generate interrupt when it reaches zero */
    #if SYSTICK_TICKINT == SYSTICK_TICKINT_ENABLED
        SYSTICK->CTRL |= SYSTICK_CTRL_TICKINT_MASK; /**< Set bit 1 to enable interrupt when the counter reaches zero */
    #elif SYSTICK_TICKINT == SYSTICK_TICKINT_DISABLED
        SYSTICK->CTRL &= ~SYSTICK_CTRL_TICKINT_MASK; /**< Clear bit 1 to disable interrupt when the counter reaches zero */
    #else
        #error "Invalid STK_CTRL_TICKINT value. Please choose STK_CTRL_TICKINT_ENABLE or STK_CTRL_TICKINT_DISABLE."
    #endif
    /**< Load the initial value into the SysTick timer */
    SYSTICK->LOAD = Copy_Ticks;
    Local_FunctionStatus= E_OK;
    return Local_FunctionStatus;
}
Std_ReturnType MCAL_SYSTICK_vINIT()
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /**< Disable SysTick timer */
    SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
    /**< Configure SysTick timer to use the processor clock */
    #if SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_1
        SYSTICK->CTRL |= SYSTICK_CTRL_CLKSRC_MASK; /**< Set bit 2 to use the processor clock */
    #elif SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_8
        SYSTICK->CTRL &= ~SYSTICK_CTRL_CLKSRC_MASK;  /**< Clear bit 2 to use the processor clock/8 */
    #else
        #error "Invalid STK_CTRL_CLKSOURCE value. Please choose STK_CTRL_CLKSOURCE_1 or STK_CTRL_CLKSOURCE_8."
    #endif
    /**< Generate interrupt when it reaches zero */
    #if SYSTICK_TICKINT == SYSTICK_TICKINT_ENABLED
        SYSTICK->CTRL |= SYSTICK_CTRL_TICKINT_MASK; /**< Set bit 1 to enable interrupt when the counter reaches zero */
    #elif SYSTICK_TICKINT == SYSTICK_TICKINT_DISABLED
        SYSTICK->CTRL &= ~SYSTICK_CTRL_TICKINT_MASK; /**< Clear bit 1 to disable interrupt when the counter reaches zero */
    #else
        #error "Invalid STK_CTRL_TICKINT value. Please choose STK_CTRL_TICKINT_ENABLE or STK_CTRL_TICKINT_DISABLE."
    #endif
    Local_FunctionStatus= E_OK;
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_SetReloadValue(u32 Copy_ReloadValue)
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /**< Check if the reload value is within the valid range */ 
    if (Copy_ReloadValue > SYSTICK_RELOAD_MAX)
    {
        /**< Return E_NOT_OK to indicate failure */ 
        return Local_FunctionStatus;
    }
    /**< Assign the reload value to the STK_LOAD register */ 
    SYSTICK->LOAD = Copy_ReloadValue;
    /**< Return E_OK to indicate success */ 
    Local_FunctionStatus=E_OK;

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_Start()
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /**< Enable SysTick timer */
    SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE_MASK;
    Local_FunctionStatus=E_OK;
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_Stop()
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /**< Disable SysTick timer */
    SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
    Local_FunctionStatus=E_OK;
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_Reset()
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /**< Disable SysTick timer */
    SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
    /**< Set the reload value to 0 */
    SYSTICK->LOAD=0;
    /**< Clear the current value */
    SYSTICK->VAL=0;
    /**< Clear the count flag */
    SYSTICK->CTRL &= ~SYSTICK_CTRL_COUNTFLAG_MASK;
    Local_FunctionStatus=E_OK;
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_GetRemainingCounts(u32* Remaining_Counts)
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /* Get the current value of the SysTick timer */ 
    *Remaining_Counts=SYSTICK->VAL;
    Local_FunctionStatus=E_OK;
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_GetElapsedCounts(u32* Elapsed_Counts)
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
//     static u32 Local_PreviousValue =0; /**< Store the previous SysTick timer value */
//     u32 Local_CurrentValue=SYSTICK->VAL; /**< Get the current SysTick timer value */
//     /**< Check if the timer has wrapped around (current value is less than the previous value) */
//     if(Local_CurrentValue < Local_PreviousValue)
//     {
//         /**< Calculate elapsed ticks considering timer overflow */
//         *Elapsed_Counts = Local_PreviousValue - Local_CurrentValue;
//     }
//     else
//     {
//         /**< Calculate elapsed ticks without timer overflow */
//         *Elapsed_Counts = (u32)SYSTICK->LOAD - (Local_CurrentValue - Local_PreviousValue);
//    }
    *Elapsed_Counts=(SYSTICK->LOAD - SYSTICK->VAL);
    /**< Update the previous value for the next call */
   // Local_PreviousValue=Local_CurrentValue;
    Local_FunctionStatus=E_OK;
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_DelayUS(f32 Copy_MicroSeconds)
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /**< Calculate the number of ticks required for the given microseconds */ 
    u32 Local_TickRequired = (u32)(Copy_MicroSeconds * (STK_AHB_CLK / 1000000.0));
    if (SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_8)
    {
 	    Local_TickRequired/=8;
    }
    /**< Check if the ticks required is within the valid range */ 
    if (Local_TickRequired <= SYSTICK_RELOAD_MAX)
   {
        /**< Set the reload value of the SysTick timer */ 
        SYSTICK->LOAD = Local_TickRequired;
        /**< Enable the SysTick timer */ 
        CLR_BIT(SYSTICK->CTRL,1);
        MCAL_SYSTICK_Start();
        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
        while(GET_BIT(SYSTICK->CTRL,16)==0);
        /**< Disable the SysTick timer */ 
        CLR_BIT(SYSTICK->CTRL,0);
        /**< Reset the timer value */ 
        MCAL_SYSTICK_Reset();
        Local_FunctionStatus= E_OK;
    }else if(Local_TickRequired > SYSTICK_RELOAD_MAX)
    {

        /**< Calculate the number of Overflows */
        u32 Local_OverFlowCount = Local_TickRequired / SYSTICK_RELOAD_MAX;
        /**< Check the first timer value to get the exact delay */
        u32 Local_InitialValue = Local_TickRequired % SYSTICK_RELOAD_MAX;
        /**< Set the reload value of the SysTick timer */
        SYSTICK->LOAD = Local_InitialValue;
        /**< Enable the SysTick timer */
        SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE_MASK;
        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */
        while(!(SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG_MASK));
        /**< Disable the SysTick timer */
        SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
        /**< Set the reload value of the SysTick timer for the rest of the  */
        SYSTICK->LOAD = SYSTICK_RELOAD_MAX-1;
        /**< Enable the SysTick timer */
        SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE_MASK;
        /**< Loop untill there's no more OVF */
        for(u32 Local_Counter=0 ; Local_Counter<=Local_OverFlowCount ; Local_Counter++)
        {
            /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */
            while(!(SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG_MASK));
        }
        /**< Disable the SysTick timer */
        SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
        /**< Reset the SysTick timer */
        MCAL_SYSTICK_Reset();
        Local_FunctionStatus= E_OK;
    }
    else
    {
        return Local_FunctionStatus;
    }
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_DelayMS(f32 Copy_MilliSeconds)
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    /**< Calculate the number of ticks required for the given microseconds */ 
    u32 Local_TickRequired = (u32)(Copy_MilliSeconds * (STK_AHB_CLK / 1000.0));
    if (SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_8)
    {
 	    Local_TickRequired/=8;
    }
    /**< Check if the ticks required is within the valid range */ 
    if (Local_TickRequired <= SYSTICK_RELOAD_MAX)
    {
        /**< Set the reload value of the SysTick timer */ 
        SYSTICK->LOAD = Local_TickRequired;
        /**< Enable the SysTick timer */ 
        SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE_MASK;
        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
        while(!(SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG_MASK));
        /**< Disable the SysTick timer */ 
        SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
        /**< Reset the timer value */ 
        MCAL_SYSTICK_Reset();
        Local_FunctionStatus= E_OK;
    }else if(Local_TickRequired > SYSTICK_RELOAD_MAX)
    {
        /**< Calculate the number of Overflows */ 
        u32 Local_OverFlowCount = Local_TickRequired / SYSTICK_RELOAD_MAX;
        /**< Check the first timer value to get the exact delay */  
        u32 Local_InitialValue = Local_TickRequired % SYSTICK_RELOAD_MAX;
        /**< Set the reload value of the SysTick timer */ 
        SYSTICK->LOAD = Local_InitialValue;
        /**< Enable the SysTick timer */ 
        SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE_MASK;
        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
        while(!(SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG_MASK));
        /**< Disable the SysTick timer */ 
        SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
        /**< Set the reload value of the SysTick timer for the rest of the  */ 
        SYSTICK->LOAD = SYSTICK_RELOAD_MAX-1;
        /**< Enable the SysTick timer */ 
        SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE_MASK;
        /**< Loop untill there's no more OVF */ 
        for(u32 Local_Counter=0 ; Local_Counter<=Local_OverFlowCount ; Local_Counter++)
        {
            /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
            while(!(SYSTICK->CTRL & SYSTICK_CTRL_COUNTFLAG_MASK));
        }
        /**< Disable the SysTick timer */ 
        SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
        /**< Reset the SysTick timer */ 
        MCAL_SYSTICK_Reset();
        Local_FunctionStatus= E_OK;
    }
    else
    {
        return Local_FunctionStatus;
    }
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_SetIntervalSingle(f32 Copy_MicroSeconds , SYSTICK_CallbackFunc_t Callback_Func )
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    if(Callback_Func != NULL)
    {
        /**< Save the callback function pointer */
        SYSTICK_Callback = Callback_Func;
        /* Calculate the number of ticks required to wait for the specified number of microseconds */
        u32 Local_TickRequired = (u32)(Copy_MicroSeconds * (STK_AHB_CLK / 1000000));
        if (SYSTICK_AHB_CLKSRC == SYSTICK_CLKSRC_DIV_8)
        {
     	    Local_TickRequired/=8;
        }
       // Local_TickRequired/=8;
        /* Set the reload value for the SysTick timer */
        SYSTICK->LOAD = Local_TickRequired;
        /**< Set the Mode of interval to be single */
        SYSTICK_ModeOfInterval=SYSTICK_SINGLE_INTERVAL;
        /* Start the SysTick timer and enable the interrupt */
        MCAL_SYSTICK_Start();
        /**< Configured successfully */
        Local_FunctionStatus= E_OK;
    }else
    {
        /**< Invalid callback function pointer */
        Local_FunctionStatus= E_NOT_OK;
    }
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_SYSTICK_SetIntervalPeriodic(f32 Copy_MicroSeconds , SYSTICK_CallbackFunc_t Callback_Func)
{
    Std_ReturnType Local_FunctionStatus= E_NOT_OK;
    if(Callback_Func != NULL)
    {
        /**< Save the callback function pointer */
        SYSTICK_Callback = Callback_Func;
        /* Calculate the number of ticks required to wait for the specified number of microseconds */
        u32 Local_TickRequired = (u32)(Copy_MicroSeconds * (STK_AHB_CLK / 1000000));
        /* Set the reload value for the SysTick timer */
        SYSTICK->LOAD = Local_TickRequired-1;
        /**< Set the Mode of interval to be periodic */
        SYSTICK_ModeOfInterval=SYSTICK_PERIOD_INTERVAL;
        /* Start the SysTick timer and enable the interrupt */
        SYSTICK->CTRL |= SYSTICK_CTRL_TICKINT_MASK;
        SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE_MASK;
        /**< Configured successfully */
        Local_FunctionStatus= E_OK;
    }else
    {
        /**< Invalid callback function pointer */
        Local_FunctionStatus= E_NOT_OK;
    }
    return Local_FunctionStatus;
}
/**
 * @} // End of Public_Functions
 */

/**
 * @defgroup IRQ_Handlers IRQ Handlers
 * @{
 */
void SysTick_Handler(void)
{
    if (SYSTICK_Callback != NULL)
    {
        if (SYSTICK_ModeOfInterval == SYSTICK_SINGLE_INTERVAL)
        {
            /**< Disable interrupt when the counter reaches zero */
            SYSTICK->CTRL &= ~SYSTICK_CTRL_TICKINT_MASK;
            /**< Disable SysTick timer */
            SYSTICK->CTRL &= ~SYSTICK_CTRL_ENABLE_MASK;
            /**< Clear the current value */
            SYSTICK->LOAD=0;
            /**< Set the reload value to 0 */
            SYSTICK->VAL=0;
        }
        /**< Callback notification */
        SYSTICK_Callback();
        /**< Clear the count/interrupt flag */
        SYSTICK->CTRL &= ~SYSTICK_CTRL_COUNTFLAG_MASK;
    }
}
/**
 * @} // End of IRQ_Handlers
 */
