/*
 * File Name   : 14_nested_struct.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   Nested structure
 *
 * Description :
 *   Demonstrates use of a structure within another structure.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 14_nested_struct.c -o 14_nested_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>

/* Inner Structure */
typedef struct
{
    int   i;
    char  c;
    float f;
} my_struct;

/* Outer Structure (Nested Struct) */
typedef struct
{
    my_struct inner;   /* structure within structure */
    int       id;
} nested_struct_t;

/* Function Prototype */
void nested_struct(void);

/* Main Function */
int main(void)
{
    nested_struct();
    return 0;
}

/* Function Definition */
void nested_struct(void)
{
    nested_struct_t ns;

    /* Assign values */
    ns.id = 1;
    ns.inner.i = 10;
    ns.inner.c = 'A';
    ns.inner.f = 2.5f;

    /* Access values */
    printf("ID = %d\n", ns.id);
    printf("Inner :: i = %d, c = %c, f = %.2f\n",
           ns.inner.i, ns.inner.c, ns.inner.f);
}
