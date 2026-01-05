/*
 * File Name   : 06_pass_by_value.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   06 pass by value
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 06_pass_by_value.c -o 06_pass_by_value
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
void pass_by_value(my_struct ms);
/* Main Function */
int main(void)
{
    my_struct ms = {1, 'c' , 1.1f};

    printf("Before i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);
    pass_by_value(ms);
    printf("After i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);
    return 0;
}

/* Function Definition */
void pass_by_value(my_struct ms)
{
    ms.i = 2;
    ms.c = 'b';
    ms.f = 2.1f;
    
    /* TODO: Implement logic */
}
