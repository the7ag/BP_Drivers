/****************************************************************/
/******* Author    : Mohamed Ali Bayoumi        *****************/
/******* Date      : 21 OCT 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : SCB_private.h              *****************/
/****************************************************************/

#ifndef SCB_PRIVATE_H_
#define SCB_PRIVATE_H_
/**< Base address of the SCB registers */

#define SCB_BASE_ADDRESS        0xE000ED00

/**< SCB Registers */

#define SCB_ACTLR           (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x00))))
#define SCB_CPUID           (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x00))))
#define SCB_ICSR            (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x04))))
#define SCB_VTOR            (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x08))))
#define SCB_AIRCR           (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x0C))))
#define SCB_SCR             (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x10))))
#define SCB_CCR             (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x14))))
#define SCB_SHPR1           (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x18))))
#define SCB_SHPR2           (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x1C))))
#define SCB_SHPR3           (*((volatile u32 *)(0xE000ED20)))
#define SCB_SHCSR           (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x24))))
#define SCB_CFSR            (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x28))))
#define SCB_HFSR            (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x2C))))
#define SCB_MMFAR           (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x34))))
#define SCB_BFAR            (*((volatile u32 *)((SCB_BASE_ADDRESS) + (0x38))))
/**< Bit positions for SCB_SHCSR register */

#define SCB_SHCSR_MEMFAULTENA_POS    16  /**< Bit position for Memory Management Fault Enable */
#define SCB_SHCSR_BUSFAULTENA_POS    17  /**< Bit position for Bus Fault Enable */
#define SCB_SHCSR_USGFAULTENA_POS    18  /**< Bit position for Usage Fault Enable */

#endif /* SCB_PRIVATE_H_ */