/*
 * File Name   : 38_memory_mapped_register.c
 * Folder      : 04_embedded
 *
 * Program Name:
 *   Memory Mapped Register Using Structure
 *
 * Description :
 *   Demonstrates access to memory-mapped hardware registers
 *   using a structure and volatile pointer.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 38_memory_mapped_register.c -o 38_memory_mapped_register
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - memory mapped register
 *   - structures
 *   - volatile
 *   - embedded systems
 */

#include <stdio.h>
#include <stdint.h>

/* Base address of peripheral (simulated) */
#define PERIPHERAL_BASE_ADDR   (0x40000000U)

/* Register layout structure */
typedef struct
{
    volatile uint32_t CTRL;      /* Control Register */
    volatile uint32_t STATUS;    /* Status Register */
    volatile uint32_t DATA;      /* Data Register */
} peripheral_reg_t;

/* Pointer to memory-mapped registers */
#define PERIPHERAL   ((peripheral_reg_t *)PERIPHERAL_BASE_ADDR)

/* Bit definitions for CTRL register */
#define CTRL_ENABLE_BIT      (1U << 0)
#define CTRL_MODE_MASK       (3U << 1)
#define CTRL_INT_BIT         (1U << 3)

/* Function Prototype */
void memory_mapped_register(void);

/* Main Function */
int main(void)
{
    memory_mapped_register();
    return 0;
}

/* Function Definition */
void memory_mapped_register(void)
{
    /* Enable peripheral */
    PERIPHERAL->CTRL |= CTRL_ENABLE_BIT;

    /* Set mode = 2 */
    PERIPHERAL->CTRL &= ~CTRL_MODE_MASK;
    PERIPHERAL->CTRL |= (2U << 1);

    /* Disable interrupt */
    PERIPHERAL->CTRL &= ~CTRL_INT_BIT;

    /* Simulated readback */
    printf("CTRL   = 0x%08X\n", PERIPHERAL->CTRL);
    printf("STATUS = 0x%08X\n", PERIPHERAL->STATUS);
    printf("DATA   = 0x%08X\n", PERIPHERAL->DATA);
}
