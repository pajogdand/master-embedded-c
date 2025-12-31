/*
 * File Name   : battery_monitor.c
 * Description :
 *   Embedded-style example demonstrating:
 *   - Binary semaphore for event signaling
 *   - Mutex for shared data protection
 *
 * Scenario:
 *   ADC thread updates battery level
 *   Control thread waits for update and processes it
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

pthread_mutex_t battery_mutex;
sem_t data_ready_sem;

int battery_level = 0;

/* Simulates ADC / Sensor Task */
void* sensor_thread(void* arg)
{
    while (1)
    {
        sleep(1);  // Simulate ADC sampling time

        pthread_mutex_lock(&battery_mutex);
        battery_level += 5;
        printf("[Sensor] Battery level updated: %d\n", battery_level);
        if(battery_level > 100)
            battery_level = 0;
        pthread_mutex_unlock(&battery_mutex);

        /* Notify control task */
        // We not use here pthread_mutex_lock here
        sem_post(&data_ready_sem);
    }
    return NULL;
}

/* Simulates Control / Monitoring Task */
void* control_thread(void* arg)
{
    while (1)
    {
        /* Wait for sensor update */
        // We can not use pthread_mutex_unlock here
        sem_wait(&data_ready_sem);

        pthread_mutex_lock(&battery_mutex);
        printf("[Control] Processing battery level: %d\n", battery_level);
        pthread_mutex_unlock(&battery_mutex);
    }
    return NULL;
}

int main(void)
{
    pthread_t sensor_tid, control_tid;

    pthread_mutex_init(&battery_mutex, NULL);
    sem_init(&data_ready_sem, 0, 0);   // Binary semaphore (event-based)

    pthread_create(&sensor_tid, NULL, sensor_thread, NULL);
    pthread_create(&control_tid, NULL, control_thread, NULL);

    pthread_join(sensor_tid, NULL);
    pthread_join(control_tid, NULL);

    pthread_mutex_destroy(&battery_mutex);
    sem_destroy(&data_ready_sem);

    return 0;
}
