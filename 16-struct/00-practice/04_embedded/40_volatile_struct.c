/*
 * File Name   : 40_volatile_struct.c
 * Folder      : 04_embedded
 *
 * Program Name:
 *   Volatile Structure
 *
 * Description :
 *   Demonstrates use of volatile keyword with structures
 *   for hardware and asynchronous data access.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 40_volatile_struct.c -o 40_volatile_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - volatile
 *   - structures
 *   - embedded systems
 */

#include <stdio.h>

/* Structure Definition */
typedef struct
{
    int   i;
    char  c;
    float f;
} my_struct;

/* Volatile structure variable */
volatile my_struct sensor_data;

/* Function Prototype */
void volatile_struct(void);

/* Main Function */
int main(void)
{
    volatile_struct();
    return 0;
}

/* Function Definition */
void volatile_struct(void)
{
    /* Assign values */
    sensor_data.i = 10;
    sensor_data.c = 'V';
    sensor_data.f = 25.5f;

    /* Read values */
    printf("i = %d\n", sensor_data.i);
    printf("c = %c\n", sensor_data.c);
    printf("f = %.2f\n", sensor_data.f);
}
