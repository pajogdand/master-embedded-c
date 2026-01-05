/*
 * File Name   : 37_bit_field_register.c
 * Folder      : 04_embedded
 *
 * Program Name:
 *   Bit Field Register
 *
 * Description :
 *   Demonstrates usage of bit-fields in structures
 *   to represent hardware control registers.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 37_bit_field_register.c -o 37_bit_field_register
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - bit fields
 *   - embedded systems
 */

#include <stdio.h>

/* Bit-field Register Definition */
typedef struct
{
    unsigned int reg;
    struct
    {
        unsigned int enable    : 1;
        unsigned int mode      : 2;
        unsigned int interrupt : 1;
        unsigned int reserved  : 4;
    } bits;
} control_reg_t;

/* Pointer to register */
control_reg_t *p_ctrl_reg;

/* Function Prototype */
void bit_field_register(void);

/* Main Function */
int main(void)
{
    bit_field_register();
    return 0;
}

/* Function Definition */
void bit_field_register(void)
{
    control_reg_t ctrl_reg = {0};

    /* Assign values */
    ctrl_reg.bits.enable    = 1;
    ctrl_reg.bits.mode      = 3;   /* Binary: 11 */
    ctrl_reg.bits.interrupt = 1;

    /* Pointer assignment */
    p_ctrl_reg = &ctrl_reg;

    /* Access bit-fields */
    printf("Enable    : %u\n", p_ctrl_reg->bits.enable);
    printf("Mode      : %u\n", p_ctrl_reg->bits.mode);
    printf("Interrupt : %u\n", p_ctrl_reg->bits.interrupt);

    /* Print raw register value (for understanding) */
    printf("Size of register : %lu byte(s)\n", sizeof(control_reg_t));


    // we can use bitwise operaters for the same
    ctrl_reg.reg |= (1 << 0);
    ctrl_reg.reg |= (2 << 1);
    ctrl_reg.reg &= ~(1 << 3);
    
    printf("Enable    : %u\n", p_ctrl_reg->bits.enable);
    printf("Mode      : %u\n", p_ctrl_reg->bits.mode);
    printf("Interrupt : %u\n", p_ctrl_reg->bits.interrupt);
    
}
