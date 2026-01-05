/*
 * File Name   : 11_typedef_struct.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   11 typedef struct
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 11_typedef_struct.c -o 11_typedef_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>

/* Structure Definition */
struct first_way
{
    int   i;
    char  c;
    float f;
};

typedef struct first_way f_w;


typedef struct
{
    int   i;
    char  c;
    float f;
} my_struct;

/* Pointer to structure */
my_struct *p_my_struct;

/* Function Prototype */
void typedef_struct(void);

/* Main Function */
int main(void)
{
    typedef_struct();
    return 0;
}

/* Function Definition */
void typedef_struct(void)
{
    /* TODO: Implement logic */
}
