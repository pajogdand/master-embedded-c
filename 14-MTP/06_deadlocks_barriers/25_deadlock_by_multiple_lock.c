    pthread_mutex_unlock(&flash_mutex);
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

/* Thread function */
#define NUM_THREADS 5
int global_variable = 0;
pthread_mutex_t *lock;
void *my_thread(void *arg)
{
    printf("Inside my_thread function\n");
    pthread_mutex_lock(&lock);
    global_variable++;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tid[i], NULL, my_thread, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Final value of global_variable: %d\n", global_variable);
    return 0;
}
