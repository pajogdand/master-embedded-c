/*
 * File Name   : 05_array_of_struct.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   05 array of struct
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 05_array_of_struct.c -o 05_array_of_struct
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
void array_of_struct(void);

/* Main Function */
int main(void)
{
    array_of_struct();
    return 0;
}

/* Function Definition */
void array_of_struct(void)
{
    my_struct ms[3];

    for(int cnt=0;cnt<3; cnt++)
    {
        ms[cnt].i = cnt;
        ms[cnt].c = 'c' + cnt;
        ms[cnt].f = 1.1f + 1;
    }

    for(int cnt =0; cnt<3;cnt++)
    {
        printf(" i=%d; c=%c; f=%f\n", ms[cnt].i, ms[cnt].c , ms[cnt].f);
    }
    
}
