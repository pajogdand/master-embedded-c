/*
 * File Name   : 30_pass_struct_ptr.c
 * Folder      : 03_pointers
 *
 * Program Name:
 *   30 pass struct ptr
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 30_pass_struct_ptr.c -o 30_pass_struct_ptr
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>

/* Structure Definition */
typedef struct
{
    int   i;
    char  c;
    float f;
} my_struct;

/* Pointer to structure */
my_struct *p_my_struct;

/* Function Prototype */
void pass_struct_ptr(void);

/* Main Function */
int main(void)
{
    pass_struct_ptr();
    return 0;
}

/* Function Definition */
void pass_struct_ptr(void)
{
    /* TODO: Implement logic */
}
