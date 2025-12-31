/*
 * File Name   : 11_mutex_lock_unlock.c
 * Folder      : 09_pthreads/03_mutex
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 11_mutex_lock_unlock.c -lpthread
 *
 * Author      : Pravin Jogdand
 * Date        : 29-12-2025
 *
 * Interview Tags :
 *   - pthreads
 */

#include <stdio.h>
#include <pthread.h>

/* Thread function */
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
/* Thread function */
int global_var = 0;
pthread_mutex_t lock;

void *my_thread(void *arg)
{
    printf("Inside my_thread function\n");
    for(int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&lock);
        global_var++;
        pthread_mutex_unlock(&lock);
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
        if (pthread_create(&tid[i], NULL, my_thread, NULL) != 0)
        {
            perror("pthread_create failed");
            return 1;
        }
    }
    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    printf("Final value of global_var: %d\n", global_var);  
    pthread_mutex_destroy(&lock);
    return 0;
}
