/*
 * File Name   : driver_callbacks.c
 *
 * Description :
 *   Demonstrates driver-like design using
 *   function pointers inside a structure.
 *   (probe, remove, read, write)
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - function pointers
 *   - driver model
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* Driver operations structure */
typedef struct
{
    int  (*probe)(void);
    void (*remove)(void);
    int  (*read)(char *buf, int len);
    int  (*write)(const char *buf, int len);
} driver_ops_t;

/* Driver object */
typedef struct
{
    const char     *name;
    driver_ops_t   *ops;
} driver_t;

char driverBuffer[255];
/* -------- Driver Functions -------- */

int driver_probe(void)
{
    printf("Driver probed successfully\n");
    return 0;
}

void driver_remove(void)
{
    printf("Driver removed\n");
}

int driver_read(char *buf, int len)
{
    printf("Driver read: %d bytes\n", len);
    strncpy(buf,driverBuffer,len);
    return len;
}

int driver_write(const char *buf, int len)
{
    printf("Driver write: %d bytes\n", len);
    strncpy(driverBuffer,buf,len);
    printf("driverBuffer %s\n",driverBuffer);
    return len;
}

/* -------- Driver Ops Instance -------- */
driver_ops_t my_driver_ops =
{
    .probe  = driver_probe,
    .remove = driver_remove,
    .read   = driver_read,
    .write  = driver_write
};

/* -------- Driver Instance -------- */
driver_t my_driver =
{
    .name = "my_demo_driver",
    .ops  = &my_driver_ops
};


/* -------- Test Function -------- */
void driver_test(void)
{
    // calling direver funtion directly:
    my_driver_ops.probe();

    // calling driver function
    char userSpaceBuffer[16];
    printf("Driver name = %s\n" , my_driver.name);
    
    /* Call probe */

    // if((*(my_driver.ops)).probe() == 0)
    // {
    //     (*(my_driver.ops)).write("DATA", sizeof("DATA"));
    //     (*(my_driver.ops)).read(userSpaceBuffer, 4);
    // }
    if (my_driver.ops->probe() == 0)
    {
        my_driver.ops->write("DATA", sizeof("DATA"));
        my_driver.ops->read(userSpaceBuffer, 4);
    }

    
    /* Remove driver */
    my_driver.ops->remove();
}

/* -------- Main -------- */
int main(void)
{
    driver_test();
    return 0;
}
