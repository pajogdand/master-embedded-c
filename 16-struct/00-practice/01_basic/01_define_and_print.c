/*
 * File Name   : 01_define_and_print.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   01 define and print
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 01_define_and_print.c -o 01_define_and_print
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
void define_and_print(void);

/* Main Function */
int main(void)
{
    define_and_print();
    return 0;
}

/* Function Definition */
void define_and_print(void)
{
    my_struct ms;
    ms.i = 0;
    ms.c = 'a';
    ms.f = 1.1f;

    printf("i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);
    /* TODO: Implement logic */
}
