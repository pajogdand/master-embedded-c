/*
 * File Name   : 27_arrow_operator.c
 * Folder      : 03_pointers
 *
 * Program Name:
 *   27 arrow operator
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 27_arrow_operator.c -o 27_arrow_operator
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
} my_struct;

/* Pointer to structure */
my_struct *p_my_struct;

/* Function Prototype */
void struct_pointer_basic(void);

/* Main Function */
int main(void)
{
    struct_pointer_basic();
    return 0;
}

/* Function Definition */
void struct_pointer_basic(void)
{
    my_struct s = {1};
    my_struct *sp = &s;

    printf("i value = %d , i value = *d" , s.i , sp->i);
    
}