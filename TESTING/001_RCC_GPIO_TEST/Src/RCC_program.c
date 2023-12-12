/***************************************************************************************************/
/************************* Author  : Mohamed Ali Bayoumi    ****************************************/
/************************* Date    : 30/9/2023              ****************************************/
/************************* Version : 0.1                    ****************************************/
/************************* MODULE  : MCAL_RCC_program.c     ****************************************/
/***************************************************************************************************/

/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************************** MCAL *****************************************************/
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType Mcal_RCC_InitSysClock(void)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    #if RCC_SYSCLK == RCC_HSI
        /* Enable HSI */
        SET_BIT( RCC_CR , RCC_CR_HSION);
        /* Wait until the clock is stable */
        while( !GET_BIT( RCC_CR , RCC_CR_HSIRDY ) );
        /* Select the HSI As system CLOCK */
        CLR_BIT( RCC_CFGR , 0 );
        CLR_BIT( RCC_CFGR , 1 );
        local_functionStates = E_OK;
    #elif RCC_SYSCLK == RCC_HSE
        /* Select Which extrnal source for the Extrnal clock */
    	#if RCC_CLK_BP == RCC_CRYSTAL_CLK_
            CLR_BIT(RCC_CR , RCC_CR_HSEBYP);  
        #elif RCC_CLK_BP == RCC_RC_CLK_
            SET_BIT(RCC_CR , RCC_CR_HSEBYP);  
        #else
            #error "Wrong Choice !!"
        #endif /* RCC_CLK_BP */
        /* Enable */
        SET_BIT( RCC_CR , RCC_CR_HSEON); 
        /* Wait until the clock is stable */
        while( !GET_BIT(RCC_CR , RCC_CR_HSERDY) );
        /* Select HSE As system CLOCK */
        SET_BIT( RCC_CFGR , 0);
        CLR_BIT( RCC_CFGR , 1);
        local_functionStates = E_OK;
    #elif RCC_SYSCLK == RCC_PLL
        #if RCC_PLL_SRC == RCC_PLL_HSI
            /* Enable HSI */
            SET_BIT( RCC_CR , RCC_CR_HSION);
            /* Disable PLL to change the source */
            CLR_BIT( RCC_CR , RCC_CR_PLLON);
            /* wait untill the clock is steady */
            while( !GET_BIT( RCC_CR , RCC_CR_PLLRDY) );
            /* Set the PLL SRC to be HSI */
            CLR_BIT ( RCC_CFGR , RCC_CFGR_PLLSRC );
            /* Enable PLL */
            SET_BIT( RCC_CR , RCC_CR_PLLON);
            /* wait untill the clock is steady */
            while( !GET_BIT( RCC_CR , RCC_CR_PLLRDY) );
            /* Select PLL as clock src */
            CLR_BIT( RCC_CFGR , 0 );
            SET_BIT( RCC_CFGR , 1 );
            local_functionStates = E_OK;
        #elif RCC_PLL_SRC == RCC_PLL_HSE
            /* Select Which extrnal source for the Extrnal clock */
            #if RCC_CLK_BP == RCC_CRYSTAL_CLK_
                CLR_BIT(RCC_CR , RCC_CR_HSEBYP);  
            #elif RCC_CLK_BP == RCC_RC_CLK_
                SET_BIT(RCC_CR , RCC_CR_HSEBYP);  
            #else
                #error "Wrong Choice !!"
            #endif /* RCC_CLK_BP */
            #if RCC_PLL_HSE_DIV == RCC_PLL_HSE_DIV_DIS
                CLR_BIT( RCC_CFGR , RCC_CFGR_PLLXTPRE);
            #elif RCC_PLL_HSE_DIV == RCC_PLL_HSE_DIV_EN
                SET_BIT( RCC_CFGR , RCC_CFGR_PLLXTPRE);
            #endif /* RCC_PLL_HSE_DIV */
            /* Enable */
            SET_BIT( RCC_CR , RCC_CR_HSEON); 
            /* Disable PLL to change the source */
            CLR_BIT( RCC_CR , RCC_CR_PLLON);
            /* wait untill the clock is steady */
            while( !GET_BIT( RCC_CR , RCC_CR_PLLRDY) );
            /* Set the PLL SRC to be HSE */
            SET_BIT ( RCC_CFGR , RCC_CFGR_PLLSRC );
            /* Enable PLL */
            SET_BIT( RCC_CR , RCC_CR_PLLON);
            /* wait untill the clock is steady */
            while( !GET_BIT( RCC_CR , RCC_CR_PLLRDY) );
            /* Select PLL as clock src */
            CLR_BIT( RCC_CFGR , 0 );
            SET_BIT( RCC_CFGR , 1 );
            local_functionStates = E_OK;
        #else 
            #error "Wrong Choice !!"
        #endif /* RCC_PLL_SRC */
    #else 
        #error "Wrong Choice !!"
    #endif /* RCC_SYSCLK */
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_Rcc_EnablePrephiral(u8 Copy_PeripheralId , u8 Copy_BusId)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_BusId)
    {
    case RCC_AHB:
    SET_BIT( RCC_AHBENR , Copy_PeripheralId );
    local_functionStates = E_OK;
    break;
    case RCC_APB1:
    SET_BIT ( RCC_AHBENR , Copy_PeripheralId );
    local_functionStates = E_OK;
    break;
    case RCC_APB2:
    SET_BIT ( RCC_APB2ENR , Copy_PeripheralId );
    local_functionStates = E_OK;
    break;
    default:
    local_functionStates =E_NOT_OK;
    break;
    }
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_Rcc_DisablePrephiral(u8 Copy_PeripheralId , u8 Copy_BusId)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    switch (Copy_BusId)
    {
    case RCC_AHB:
    CLR_BIT( RCC_AHBENR , Copy_PeripheralId );
    local_functionStates = E_OK;
    break;
    case RCC_APB1:
    CLR_BIT ( RCC_AHBENR , Copy_PeripheralId );
    local_functionStates = E_OK;
    break;
    case RCC_APB2:
    CLR_BIT ( RCC_APB2ENR , Copy_PeripheralId );
    local_functionStates = E_OK;
    break;
    default:
    local_functionStates =E_NOT_OK;
        break;
    }
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_EnableClkSecuritySystem(void)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    #if RCC_SYSCLK == RCC_HSE
        SET_BIT( RCC_CR , RCC_CR_CSSON);
        local_functionStates = E_OK;
    #endif
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_DisapleClkSecuritySystem(void)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    CLR_BIT( RCC_CR , RCC_CR_CSSON);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_SetAHB_Pre(u8 Copy_PreValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    RCC_CFGR |= (Copy_PreValue << RCC_CFGR_AHB_PRE_DIS);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_SetAPB1_Pre(u8 Copy_PreValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    RCC_CFGR |= (Copy_PreValue << RCC_CFGR_APB1_PRE_DIS);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_SetAPB2_Pre(u8 Copy_PreValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    RCC_CFGR |= (Copy_PreValue << RCC_CFGR_APB2_PRE_DIS);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_SetADC_Pre(u8 Copy_PreValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    RCC_CFGR |= (Copy_PreValue << RCC_CFGR_ADC_PRE_DIS);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_SetPLL_MUL(u8 Copy_PreValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    RCC_CFGR |= (Copy_PreValue << RCC_CFGR_PLL_MUX_DIS);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_SetUSB_Pre(u8 Copy_PreValue)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    RCC_CFGR |= (Copy_PreValue << RCC_CFGR_USB_PRE_DIS);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

Std_ReturnType Mcal_RCC_EnaleMCO(void)
{
    Std_ReturnType local_functionStates = E_NOT_OK;
    RCC_CFGR |= (RCC_MCO_SRC << RCC_CFGR_MCO_DIS);
    local_functionStates = E_OK;
    return local_functionStates;
}
/*====================================================   END_ FUNCTION   ====================================================*/
