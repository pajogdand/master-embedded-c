/*
 * File Name   : 50_oop_using_struct.c
 * Folder      : 05_advanced
 *
 * Program Name:
 *   OOP using Struct
 *
 * Description :
 *   Demonstrates object-oriented programming
 *   concepts in C using structures and
 *   function pointers.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 50_oop_using_struct.c -o 50_oop_using_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - OOP in C
 */

#include <stdio.h>

/* Forward declaration */
typedef struct device device_t;

/* "Class" definition */
struct device
{
    int id;

    /* Methods */
    void (*init)(device_t *self);
    void (*start)(device_t *self);
    void (*stop)(device_t *self);
};

/* -------- Method Implementations -------- */

void device_init(device_t *self)
{
    printf("Device %d initialized\n", self->id);
}

void device_start(device_t *self)
{
    printf("Device %d started\n", self->id);
}

void device_stop(device_t *self)
{
    printf("Device %d stopped\n", self->id);
}

/* -------- Object Creation -------- */

void device_create(device_t *dev, int id)
{
    dev->id    = id;
    dev->init  = device_init;
    dev->start = device_start;
    dev->stop  = device_stop;
}

/* -------- Test Function -------- */

void oop_using_struct(void)
{
    device_t my_device;

    /* Construct object */
    device_create(&my_device, 1);

    /* Call methods */
    my_device.init(&my_device);
    my_device.start(&my_device);
    my_device.stop(&my_device);
}

/* -------- Main -------- */
int main(void)
{
    oop_using_struct();
    return 0;
}
