/*
 * File Name   : 20_deadlock_example.c
 * Folder      : 09_pthreads/06_deadlocks_barriers
 *
 * Description :
 *   Demonstrates DEADLOCK using pthread_mutex
 *   after synchronized startup with pthread_barrier.
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 20_deadlock_example.c -lpthread
 *
 * Author      : Pravin Jogdand
 * Date        : 29-12-2025
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 3

pthread_barrier_t init_barrier;
pthread_mutex_t sensor_mutex;
pthread_mutex_t network_mutex;

/*
 * File Name   : circular_wait_deadlock.c
 *
 * Description :
 *   Demonstrates circular wait caused by
 *   inconsistent mutex lock ordering.
 *
 * Thread A:
 *   i2c_mutex -> flash_mutex
 *
 * Thread B:
 *   flash_mutex -> i2c_mutex
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t i2c_mutex;
pthread_mutex_t flash_mutex;

/* Thread A */
void *sensor_task(void *arg)
{
    pthread_mutex_lock(&i2c_mutex);
    printf("Sensor: locked i2c_mutex\n");
    sleep(1);

    pthread_mutex_lock(&flash_mutex);  // WAIT FOREVER
    printf("Sensor: locked flash_mutex\n");
    sleep(2);
    pthread_mutex_unlock(&flash_mutex);
    
    pthread_mutex_unlock(&i2c_mutex);
    return NULL;
}

/* Thread B */
void *storage_task(void *arg)
{
    pthread_mutex_lock(&flash_mutex);
    printf("Storage: locked flash_mutex\n");
    sleep(1);

    pthread_mutex_lock(&i2c_mutex);   // WAIT FOREVER
    printf("Storage: locked i2c_mutex\n");
    sleep(2);
    pthread_mutex_unlock(&i2c_mutex);
    
    pthread_mutex_unlock(&flash_mutex);
    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    pthread_mutex_init(&i2c_mutex, NULL);
    pthread_mutex_init(&flash_mutex, NULL);

    pthread_create(&t1, NULL, sensor_task, NULL);
    pthread_create(&t2, NULL, storage_task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
