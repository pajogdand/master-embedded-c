/*
 * File Name   : 17_semaphore_intro.c
 * Folder      : 09_pthreads/05_semaphores
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 17_semaphore_intro.c -lpthread
 *
 * Author      : Pravin Jogdand
 * Date        : 29-12-2025
 *
 * Interview Tags :
 *   - pthreads
 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5
/* Thread function */
sem_t my_semaphore;

void *my_thread(void *arg)
{
    int thread_num = *((int *)arg);
    printf("Thread %d: Waiting to enter critical section\n", thread_num);
    sem_wait(&my_semaphore);
    printf("Doing something in thread %d\n", thread_num);
    sleep(10);
    sem_post(&my_semaphore);
    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];


    sem_init(&my_semaphore, 0, 2);
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *thread_num = (int *)malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&tid[i], NULL, my_thread, (void *)thread_num);
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&my_semaphore);
    return 0;
}
