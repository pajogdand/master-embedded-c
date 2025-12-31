/*
 * File Name   : 05_thread_in_loop.c
 * Folder      : 09_pthreads/01_thread_creation
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 05_thread_in_loop.c -lpthread
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

#define NUM_THREADS 5

/* Thread function */
void *my_thread(void *arg)
{
    int thread_index = *((int *)arg);
    printf("Inside my_thread function, thread_index = %d\n", thread_index);
    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tid[i], NULL, my_thread, &i);
    }

    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    return 0;
}
