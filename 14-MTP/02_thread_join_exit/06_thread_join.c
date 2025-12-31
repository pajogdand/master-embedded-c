/*
 * File Name   : 06_thread_join.c
 * Folder      : 09_pthreads/02_thread_join_exit
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 06_thread_join.c -lpthread
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

    printf("Inside main function\n");
    pthread_create(&tid, NULL, my_thread, NULL);
    // sleep(1);
    printf("Waiting for thread to complete...\n");
    pthread_join(tid, NULL);

    return 0;
}
