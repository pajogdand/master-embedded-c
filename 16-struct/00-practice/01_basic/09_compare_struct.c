/*
 * File Name   : 09_compare_struct.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   09 compare struct
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 09_compare_struct.c -o 09_compare_struct
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
int compare_struct(const my_struct* , const my_struct*);

/* Main Function */
int main(void)
{
    my_struct ms;
    ms.i = 0;
    ms.c = 'a';
    ms.f = 1.1f;

    my_struct ms1;
    ms1.i = 0;
    ms1.c = 'b';
    ms1.f = 1.1f;

    // if(compare_struct(&ms, &ms1) == 1)
    if(compare_struct(&ms, &ms1))
        printf("struct are equal\n");
    else
        printf("struct are not equal\n");

    return 0;
}

/* Function Definition */
int compare_struct(const my_struct *a, const my_struct *b)
{
    return (a->i == b->i &&
            a->c == b->c &&
            a->f == b->f);
}