

#include <stdint.h>

#include "stm32h743xx.h"

uint32_t global_variable;
void main(void){


    // 1. Enable clocking of the GPIO peripheral on the HB4 bus.
    RCC->AHB4ENR |= RCC_AHB4ENR_GPIOEEN;

    // Dummy readout to ensure clock synchronization on the AHB4 bus.
    volatile uint32_t dummy = RCC->AHB4ENR;
    (void)dummy;

    // 2. Configures pin PE3 as a general-purpose output (MODER3 = 01)
    GPIOE->MODER &= ~(3UL << (3 * 2));  // Clears the 2 bits on pin 3.
    GPIOE->MODER |=  (1UL << (3 * 2));  // Define as output (01)

    // 3. Set output type to Push-Pull (OTYPER3 = 0)
    GPIOE->OTYPER &= ~(1UL << 3);

    // 4. Infinite loop flashing blue LED (PE3)
    while (1)
    {
        //Toggle the state of pin P3 using the ONR register.
        GPIOE->ODR ^= (1UL << 3);
        global_variable++;
        // Simple software delay (standard HSI runs at 64 MHz on the STM32H7)
        for (volatile uint32_t i = 0; i < 4000000; i++)
        {
            __NOP();
        }
    }
}
