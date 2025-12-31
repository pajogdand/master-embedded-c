/*
 * File Name   : 20_deadlock_example.c
 * Folder      : 09_pthreads/06_deadlocks_barriers
 *
 * Description :
 *   Demonstrates use of pthread_barrier for synchronizing
 *   initialization of multiple embedded subsystems.
 *
 *   Example:
 *     Thread 0 -> Sensor initialization
 *     Thread 1 -> Network initialization
 *     Thread 2 -> Storage initialization
 *
 *   All threads must finish initialization before
 *   entering normal operation.
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 20_deadlock_example.c -lpthread
 *
 * Author      : Pravin Jogdand
 * Date        : 29-12-2025
 *
 * Interview Tags :
 *   - pthreads
 *   - barrier
 *   - embedded synchronization
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 3

pthread_barrier_t init_barrier;

void *my_thread(void *arg)
{
    int id = *(int *)arg;
    free(arg);

    /* Phase 1: Initialization */
    if (id == 0)
    {
        printf("[Sensor] Initializing sensors...\n");
        sleep(2);
        printf("[Sensor] Initialization done\n");
    }
    else if (id == 1)
    {
        printf("[Network] Initializing network...\n");
        sleep(3);
        printf("[Network] Initialization done\n");
    }
    else if (id == 2)
    {
        printf("[Storage] Initializing storage...\n");
        sleep(1);
        printf("[Storage] Initialization done\n");
    }

    printf("Thread %d waiting at init barrier\n", id);
    pthread_barrier_wait(&init_barrier);

    /* Phase 2: Normal operation */
    printf("Thread %d entering normal operation\n", id);

    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];

    pthread_barrier_init(&init_barrier, NULL, NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *index = malloc(sizeof(int));
        *index = i;
        pthread_create(&tid[i], NULL, my_thread, index);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_barrier_destroy(&init_barrier);
    return 0;
}
