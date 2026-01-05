/*
 * File Name   : 03_read_and_display.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   03 read and display
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 03_read_and_display.c -o 03_read_and_display
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
void read_and_display(void);

/* Main Function */
int main(void)
{
    read_and_display();
    return 0;
}

/* Function Definition */
void read_and_display(void)
{
    my_struct ms;
    ms.i = 0;
    ms.c = 'c';
    ms.f = 1.1f;

    
    /* TODO: Implement logic */
}
