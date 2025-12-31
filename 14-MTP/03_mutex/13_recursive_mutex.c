/*
 * File Name   : 13_recursive_mutex.c
 * Folder      : 09_pthreads/03_mutex
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 13_recursive_mutex.c -lpthread
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
void *my_thread(void *arg)
{
    printf("Inside my_thread function\n");
    return NULL;
}

int main(void)
{
    pthread_t tid;

    pthread_create(&tid, NULL, my_thread, NULL);
    pthread_join(tid, NULL);

    return 0;
}
