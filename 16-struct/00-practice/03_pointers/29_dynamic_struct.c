/*
 * File Name   : 29_dynamic_struct.c
 * Folder      : 03_pointers
 *
 * Program Name:
 *   29 dynamic struct
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 29_dynamic_struct.c -o 29_dynamic_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
typedef struct
{
    int   i;
} my_struct;

/* Pointer to structure */
my_struct *p_my_struct;

/* Function Prototype */
my_struct* get_dynamic_struct(void);

/* Main Function */
int main(void)
{
    my_struct *sp = get_dynamic_struct();
    
    if(!sp)
        printf("Invalid pointer\n");
    printf("sp->i = %d \n" , sp->i);
    return 0;
}

/* Function Definition */
my_struct* get_dynamic_struct(void)
{
    my_struct *sp =(my_struct *)malloc(sizeof(my_struct));
    if(!sp) return NULL;
    sp->i = 1;

    return sp;
}
