/*
 * File Name   : 10_mutex_intro.c
 * Folder      : 09_pthreads/03_mutex
 *
 * Description :
 *   TODO: Add the  5 numbers from array using multiple threads and mutex , 
 *         for example array = {0,1,2,3,4, 5,6,7,8,9} , final sum should be 45
 *          tread 1 : 0,1,2,3,4
 *          tread 2 : 5,6,7,8,9
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 10_mutex_intro.c -lpthread
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

#define NUM_THREADS 2

#define ARRAY_SIZE 10
int array[ARRAY_SIZE] = {0,1,2,3,4, 5,6,7,8,9};
int sum = 0;

pthread_mutex_t lock;
void *my_thread(void *arg)
{
    int thread_number = *(int *)arg;
    int local_sum = 0;

    int start = thread_number * (ARRAY_SIZE / NUM_THREADS);
    int end   = start + (ARRAY_SIZE / NUM_THREADS);

    printf("Thread %d processing index %d to %d\n",
            thread_number, start, end - 1);

    for (int i = start; i < end; i++)
    {
        local_sum += array[i];
    }

    /* Update shared sum once */
    pthread_mutex_lock(&lock);
    sum += local_sum;
    pthread_mutex_unlock(&lock);

    free(arg);
    return NULL;
}


int main(void)
{
    pthread_t tid[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < NUM_THREADS; i++)
    {
        int *thread_number = (int* )malloc(sizeof(int));
        *thread_number = i;
        printf("Creating thread %d\n", i);
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

    printf("Final sum: %d\n", sum); 
    pthread_mutex_destroy(&lock);
    return 0;
}
