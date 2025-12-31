/*
 * File Name   : 09_detached_thread.c
 * Folder      : 09_pthreads/02_thread_join_exit
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 09_detached_thread.c -lpthread
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
    pthread_detach(tid);
    pthread_create(&tid, NULL, my_thread, NULL);
    printf("Thread detached successfully\n");

    return 0;
}
