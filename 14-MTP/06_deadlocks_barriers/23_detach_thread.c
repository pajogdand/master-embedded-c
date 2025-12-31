/*
 * File Name   : 20_deadlock_example.c
 * Folder      : 09_pthreads/06_deadlocks_barriers
 *
 * Description :
 *   Demonstrates use of pthread_barrier for synchronized
 *   startup and pthread_detach for background threads
 *   in embedded systems.
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

void *my_thread(void *arg)
{
    int id = *(int *)arg;
    free(arg);

    /* Phase 1: Initialization */
    if (id == 0)
    {
        printf("[Sensor] Initializing...\n");
        sleep(2);
    }
    else if (id == 1)
    {
        printf("[Network] Initializing...\n");
        sleep(3);
    }
    else if (id == 2)
    {
        printf("[Storage] Initializing...\n");
        sleep(1);
    }

    printf("Thread %d waiting at barrier\n", id);
    pthread_barrier_wait(&init_barrier);

    /* Detach after synchronized startup */
    pthread_detach(pthread_self());
    printf("Thread %d detached and running in background\n", id);

    /* Phase 2: Background task */
    for (int i = 0; i < 5; i++)
    {
        printf("Thread %d background work cycle %d\n", id, i);
        sleep(1);
    }

    printf("Thread %d exiting\n", id);
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

    /* No pthread_join() here */
    printf("Main thread exiting without joining threads\n");

    pthread_barrier_destroy(&init_barrier);

    /* Allow detached threads to run */
    sleep(7);
    return 0;
}
