/*
 * File Name   : 26_struct_pointer_basic.c
 * Folder      : 03_pointers
 *
 * Program Name:
 *   26 struct pointer basic
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 26_struct_pointer_basic.c -o 26_struct_pointer_basic
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

    printf("i value = %d , i value = *d" , s.i , (*sp).i);
    
}
