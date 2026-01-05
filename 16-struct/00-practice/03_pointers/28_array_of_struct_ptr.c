/*
 * File Name   : 28_array_of_struct_ptr.c
 * Folder      : 03_pointers
 *
 * Program Name:
 *   28 array of struct ptr
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 28_array_of_struct_ptr.c -o 28_array_of_struct_ptr
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
    my_struct s[2] = { {1} , {2}};
    my_struct *sp[2] = {&s[0] ,&s[1]};
    
    printf("Using structure array       : %d\n", s[0].i);
    printf("Using structure pointer     : %d\n", sp[0]->i);
    printf("Second element via pointer  : %d\n", sp[1]->i);
}