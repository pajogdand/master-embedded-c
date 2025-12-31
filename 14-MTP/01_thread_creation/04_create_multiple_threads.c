/*
 * File Name   : 04_create_multiple_threads.c
 * Folder      : 09_pthreads/01_thread_creation
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 04_create_multiple_threads.c -lpthread
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
    printf("Inside my_thread function\n");
    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];

  
    if(pthread_create(&tid[0], NULL, my_thread, NULL) != 0)
    {
        perror("pthread_create failed");
        return 1;
    }
    if(pthread_create(&tid[1], NULL, my_thread, NULL) != 0)
    {
        perror("pthread_create failed");
        return 1;
    }


    if(pthread_join(tid[0], NULL) != 0)
    {
        perror("pthread_join failed");
        return 1;
    }
    if(pthread_join(tid[1], NULL) != 0)
    {
        perror("pthread_join failed");
        return 1;
    }

    return 0;
}
