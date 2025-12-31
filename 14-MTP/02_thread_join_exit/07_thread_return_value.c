/*
 * File Name   : 07_thread_return_value.c
 * Folder      : 09_pthreads/02_thread_join_exit
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 07_thread_return_value.c -lpthread
 *
 * Author      : Pravin Jogdand
 * Date        : 29-12-2025
 *
 * Interview Tags :
 *   - pthreads
 */

#include <stdio.h>
#include <pthread.h>

#include <stdlib.h>   // ✅ REQUIRED for malloc/free

/* Thread function */
void *my_thread(void *arg)
{
    int *value = malloc(sizeof(int));
    if (value == NULL)
    {
        perror("malloc failed");
    }

    *value = 100;
    printf("Inside my_thread function\n");
    return value;
}

int main(void)
{
    pthread_t tid;
    int *thread_return_value = NULL;

    printf("Inside main function\n");

    pthread_create(&tid, NULL, my_thread, NULL);
    pthread_join(tid, (void **)&thread_return_value);

    if (thread_return_value != NULL)
    {
        printf("Thread returned value: %d\n", *thread_return_value);
        free(thread_return_value);
    }

    return 0;
}
