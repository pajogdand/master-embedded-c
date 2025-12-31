/*
 * File Name   : 15_cond_wait_signal.c
 * Folder      : 09_pthreads/04_condition_variables
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 15_cond_wait_signal.c -lpthread
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
