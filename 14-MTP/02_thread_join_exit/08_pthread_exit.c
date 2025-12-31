/*
 * File Name   : 08_pthread_exit.c
 * Folder      : 09_pthreads/02_thread_join_exit
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 08_pthread_exit.c -lpthread
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
        pthread_exit(NULL);
    }

    *value = 42;
    printf("Inside my_thread function, value = %d\n", *value);
    // this is another way to return value from thread
    pthread_exit((void *)value);
}

int main(void)
{
    pthread_t tid;
    int *thread_return_value = NULL;

    printf("Inside main function\n");

    pthread_create(&tid, NULL, my_thread, NULL);
    
    int *result = NULL;
    int ret = pthread_join(tid, (void **)&result);
    if (ret != 0)
    {   
        perror("pthread_join failed");
        return 1;
    }
    printf("Thread returned value: %d\n", *result);

    free(result); // Free the allocated memory in main thread
    return 0;
}
