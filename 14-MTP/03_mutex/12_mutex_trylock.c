/*
 * File Name   : 12_mutex_trylock.c
 * Folder      : 09_pthreads/03_mutex
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 12_mutex_trylock.c -lpthread
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
/* Thread function */
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
/* Thread function */
pthread_mutex_t lock;

// void *my_thread(void *arg)
// {
//     int *thread_number = (int *)arg;
//     printf("waiting for lock in %d\n" , *thread_number);
//     pthread_mutex_lock(&lock);
//     printf("lock aquired by thread %d.\n", *thread_number);
//     sleep(1); // Simulate some work
//     pthread_mutex_unlock(&lock);
//     return NULL;
// }

void *my_thread(void *arg)
{
    int *thread_number = (int *)arg;
    printf("waiting for lock in %d\n" , *thread_number);
    // if unable to acquire lock, it returns immediately 
    // 0 = success, otherwise error code
    // exampe: EBUSY - Mutex already locked by another thread
    if(pthread_mutex_trylock(&lock) == 0)
    {
        printf("lock aquired by thread %d.\n", *thread_number);
        sleep(1); // Simulate some work
        pthread_mutex_unlock(&lock);
    }
    else
    {
        printf("Thread %d could not acquire the lock.\n", *thread_number);
    }
    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating thread %d\n", i);
        int *thread_number = (int *)malloc(sizeof(int));
        *thread_number = i;
        if (pthread_create(&tid[i], NULL, my_thread, thread_number) != 0)
        {
            perror("pthread_create failed");
            return 1;
        }
    }
    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
