/*
 * File Name   : 13_struct_with_pointer.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   13 struct with pointer
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 13_struct_with_pointer.c -o 13_struct_with_pointer
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
} my_struct_t;

/* Pointer to structure */
typedef my_struct_t *my_struct_ptr_t;

/* Function Prototype */
my_struct_ptr_t struct_with_pointer(void);

/* Main Function */
int main(void)
{
    my_struct_ptr_t my_local_str_ptr = struct_with_pointer();
    
    printf("got value for strct_with_pointer function =%d\n", my_local_str_ptr->i);
    return 0;
}

/* Function Definition */
my_struct_ptr_t struct_with_pointer(void)
{
    my_struct_t *s = NULL;

    s = (my_struct_t *)malloc(sizeof(my_struct_t));
    if(!s) 
    {
        printf("issue in allocating the memory\n");
        return NULL;
    }

    (*s).i = 100;
    //s->i = 100;
    
    return s;
}
