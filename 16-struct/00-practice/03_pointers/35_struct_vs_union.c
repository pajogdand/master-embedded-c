/*
 * File Name   : 35_struct_vs_union.c
 * Folder      : 03_pointers
 *
 * Program Name:
 *   Struct vs Union
 *
 * Description :
 *   Demonstrates the difference between structure
 *   and union in terms of memory allocation
 *   and data access.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 35_struct_vs_union.c -o 35_struct_vs_union
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - union
 */

#include <stdio.h>

/* Structure Definition */
typedef struct
{
    int   i;
    char  c;
    float f;
} my_struct;

/* Union Definition */
typedef union
{
    int   i;
    char  c;
    float f;
} my_union;

/* Function Prototype */
void struct_vs_union(void);

/* Main Function */
int main(void)
{
    struct_vs_union();
    return 0;
}

/* Function Definition */
void struct_vs_union(void)
{
    my_struct s;
    my_union  u;

    /* Assign values */
    s.i = 10;
    s.c = 'A';
    s.f = 3.14f;

    u.i = 10;
    u.c = 'A';     /* Overwrites previous value */
    u.f = 3.14f;   /* Overwrites again */

    /* Print structure values */
    printf("STRUCT VALUES\n");
    printf("i = %d\n", s.i);
    printf("c = %c\n", s.c);
    printf("f = %.2f\n", s.f);

    /* Print union values */
    printf("\nUNION VALUES\n");
    printf("i = %d\n", u.i);
    printf("c = %c\n", u.c);
    printf("f = %.2f\n", u.f);

    /* Size comparison */
    printf("\nSIZE COMPARISON\n");
    printf("Size of struct = %lu bytes\n", sizeof(my_struct));
    printf("Size of union  = %lu bytes\n", sizeof(my_union));
}
