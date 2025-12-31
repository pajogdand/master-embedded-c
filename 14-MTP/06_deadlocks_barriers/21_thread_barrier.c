/*
 * File Name   : 20_deadlock_example.c
 * Folder      : 09_pthreads/06_deadlocks_barriers
 *
 * Description :
 *   TODO: Add description
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
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>

/* Thread function */
#define NUM_THREADS 5
pthread_barrier_t barrier;
void *my_thread(void *arg)
{
    while(1)
    {
        printf("waiting for barrier in my_thread function\n");
        pthread_barrier_wait(&barrier);
        printf("passed the barrier in my_thread function\n");
        sleep(1); // Simulate some work 
    }
    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];
    
    pthread_barrier_init(&barrier, NULL, NUM_THREADS);

    for(int i = 0; i < NUM_THREADS; i++)
    {
        if(pthread_create(&tid[i], NULL, my_thread, NULL) != 0)
        {
            perror("pthread_create failed");
            return 1;
        }
    }

    for(int i = 0; i < NUM_THREADS; i++)
    {
        if(pthread_join(tid[i], NULL) != 0)
        {
            perror("pthread_join failed");
            return 1;
        }
    }

    return 0;
}
