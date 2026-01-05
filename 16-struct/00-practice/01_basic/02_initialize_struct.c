/*
 * File Name   : 02_initialize_struct.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   02 initialize struct
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 02_initialize_struct.c -o 02_initialize_struct
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
void initialize_struct(void);

/* Main Function */
int main(void)
{
    initialize_struct();
    return 0;
}

/* Function Definition */
void initialize_struct(void)
{
    my_struct ms = {1, 'c' , 1.1f};
    
    printf("i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);
    /* TODO: Implement logic */
}
