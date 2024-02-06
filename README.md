# STM32F103C8 Drivers

This repository contains driver libraries for various peripherals of the STM32F103C8 microcontroller, along with testing examples for each driver.
![0_r7Y5Z7LXcx2Bmy3f](https://github.com/MuteMotion/BP_Drivers/assets/95578914/839d0bd5-5a56-4b53-b7e1-2ce71a2d7127)

## Supported Drivers

### 1. RCC (Reset and Clock Control)
- The RCC driver provides functions to configure the system clock and manage peripheral clocks.

### 2. GPIO (General Purpose Input/Output)
- The GPIO driver facilitates configuration and control of GPIO pins for input and output operations.

### 3. NVIC (Nested Vectored Interrupt Controller)
- The NVIC driver manages interrupt priorities and enables/disables interrupts for different peripherals.

### 4. SCB (System Control Block)
- The SCB driver provides functions to configure system control settings.

### 5. EXTI (External Interrupts)
- The EXTI driver handles external interrupt configurations and interrupt line management.

### 6. AFIO (Alternate Function I/O)
- The AFIO driver configures alternate function GPIO pins and remapping options.

### 7. SYSTICK
- The SYSTICK driver manages the SysTick timer for creating time delays.

### 8. General Purpose Timers
- This driver provides functions to configure and control general-purpose timers (TIM1, TIM2, etc.).

### 9. Ultrasonic Driver
- The Ultrasonic driver offers functionality to interface and control ultrasonic sensors for distance measurement.

### 10. LCD Driver
- The LCD driver facilitates interfacing and controlling an LCD (Liquid Crystal Display) module with the STM32F103C8 microcontroller. It provides functions for initializing the display, writing data or commands, and managing the display output.

### 11. Motor Driver
- The Motor driver enables control of motors connected to the STM32F103C8 microcontroller. It offers functions for motor initialization, direction control, speed regulation, and other motor-related operations.

## Testing

### RCC Testing
- The RCC driver can be tested by configuring the system clock to various frequencies. An example code demonstrating clock switching can be found in `001_RCC_GPIO_TEST`.

### GPIO Testing
- GPIO driver testing involves setting pins to input/output mode, toggling their state, and reading input values. Use `001_RCC_GPIO_TEST.c` to validate GPIO functionality.

### NVIC Testing
- To test NVIC functionality, configure and trigger interrupts for different peripherals. `002_NVIC_SCB_TEST` demonstrates interrupt handling.

### SCB Testing
- SCB driver testing involves configuring system control settings such as resetting the system. Use `002_NVIC_SCB_TEST` to validate SCB functionalities.

### EXTI Testing
- Test the EXTI driver by configuring external interrupt lines and observing interrupt triggers. Use `003_EXTI_AFIO_TEST` for testing EXTI functionality.

### AFIO Testing
- AFIO testing includes configuring alternate function GPIO pins and verifying their functionality. Use `003_EXTI_AFIO_TEST` for testing AFIO features.

### SYSTICK Testing
- To test the SYSTICK driver, create delays and measure time intervals using the SysTick timer. `004_SYSTICK_TEST` demonstrates SysTick usage.

### General Purpose Timers (GPT) Testing including PWM
- Test the GPT driver by configuring general-purpose timers in various modes like PWM (Pulse Width Modulation) and observing their behavior. Use `005_GPT_TEST` to test timer functionalities, including PWM functions in `006_PWM_TEST`.

### Ultrasonic Driver Testing
- Utilize the Ultrasonic driver to interface with ultrasonic sensors for distance measurement. Example codes and usage guidelines can be found in the respective folder.

### LCD Testing
- To test the LCD driver, an example code demonstrating the initialization and basic operations of the LCD module can be found in `006_LCD_TEST.c`. This includes initializing the LCD, writing text or custom characters, and performing basic display operations.

### Motor Driver Testing
- Test the Motor driver by initializing motors, controlling their direction and speed, and performing motor-related operations. Example codes and usage guidelines can be found in the respective folder.

## Usage
1. Clone the repository:


## Usage
1. Clone the repository:
 ```
   git clone https://github.com/MuteMotion/BP_Drivers.git
   ```
2. Include the required driver files in your STM32 project.
3. Use the respective test files as a reference to understand and implement driver functionalities in your application.

## Contributions
Contributions are welcome! If you'd like to improve these drivers or add support for additional peripherals, feel free to submit a pull request.
