/*
 * File Name   : 15_sizeof_struct.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   15 sizeof struct
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 15_sizeof_struct.c -o 15_sizeof_struct
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
    int   i;    /* 4 bytes */
    char  c;    /* 1 byte  */
    float f;    /* 4 bytes */
} my_struct;

void sizeof_struct(void);

int main(void)
{
    sizeof_struct();
    return 0;
}

void sizeof_struct(void)
{
    printf("Size of int   : %lu bytes\n", sizeof(int));
    printf("Size of char  : %lu bytes\n", sizeof(char));
    printf("Size of float : %lu bytes\n", sizeof(float));

    printf("\nSize of my_struct : %lu bytes\n", sizeof(my_struct));
}
