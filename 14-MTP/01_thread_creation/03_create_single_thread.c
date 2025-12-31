/*
 * File Name   : 03_create_single_thread.c
 * Folder      : 09_pthreads/01_thread_creation
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 03_create_single_thread.c -lpthread
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
void *my_thread(void *arg)
{
    int value = *((int *)arg);
    value++;
    printf("Inside my_thread function\n");
    printf("Value received from main: %d\n", value);
    return NULL;
}

void *my_thread_with_ret_val(void *arg)
{
    int value = *((int *)arg);
    value++;
    printf("Inside my_thread_with_ret_val function\n");
    printf("Value received from main: %d\n", value);
    int *ret_val = malloc(sizeof(int));
    *ret_val = value;
    return (void *)ret_val;
}

int main(void)
{
    pthread_t tid;
     
    int value_from_main = 10;
    if(pthread_create(&tid, NULL, my_thread, &value_from_main) != 0)
    {
        perror("pthread_create failed");
        return 1;
    }
    pthread_join(tid, NULL);

    /* Create thread with return value */
    int *ret_value = NULL;

    if (pthread_create(&tid, NULL, my_thread_with_ret_val, &value_from_main) != 0)
    {
        perror("pthread_create failed");
        return 1;
    }

    pthread_join(tid, (void **)&ret_value);

    if (ret_value != NULL)
    {
        printf("[main] Return value from thread: %d\n", *ret_value);
        free(ret_value);
    }


    return 0;
}
