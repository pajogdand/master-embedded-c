/*
 * File Name   : 36_sensor_data.c
 * Folder      : 04_embedded
 *
 * Program Name:
 *   Sensor Data using Structure
 *
 * Description :
 *   Demonstrates how to store and access sensor data
 *   using a structure and structure pointer.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 36_sensor_data.c -o 36_sensor_data
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - embedded systems
 */

#include <stdio.h>

/* Structure Definition */
typedef struct
{
    int   i;     /* Sensor ID */
    char  c;     /* Sensor status */
    float f;     /* Sensor reading */
} my_struct;

/* Pointer to structure */
my_struct *p_my_struct;

/* Function Prototype */
void sensor_data(void);

/* Main Function */
int main(void)
{
    sensor_data();
    return 0;
}

/* Function Definition */
void sensor_data(void)
{
    my_struct sensor;

    /* Assign sensor values */
    sensor.i = 101;          /* Sensor ID */
    sensor.c = 'A';          /* A = Active */
    sensor.f = 36.75f;       /* Temperature value */

    /* Assign pointer to structure */
    p_my_struct = &sensor;

    /* Access structure members using pointer */
    printf("Sensor ID     : %d\n", p_my_struct->i);
    printf("Sensor Status : %c\n", p_my_struct->c);
    printf("Sensor Value  : %.2f\n", p_my_struct->f);
}
