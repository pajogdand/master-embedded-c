/*
 * File Name   : 02_process_vs_thread.c
 * Folder      : 09_pthreads/00_basics
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 02_process_vs_thread.c -lpthread
 *
 * Author      : Pravin Jogdand
 * Date        : 29-12-2025
 *
 * Interview Tags :
 *   - pthreads
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
/* Thread function */
int global_var = 10;
void *my_thread(void *arg)
{
    printf("Inside my_thread function\n");
    printf("process ID ID: %u\n",getpid());
    printf("Global variable address in thread: %p\n",&global_var);
    printf("Global variable value in thread before increment: %d\n",global_var);
    return NULL;
}

int main(void)
{
    pthread_t tid;

    // pthread_create(&tid, NULL, my_thread, NULL);
    // printf("Inside main function\n");
    // printf("process ID ID: %u\n",getpid());
    // global_var++;
    // printf("Global variable address in main: %p\n",&global_var);
    // printf("Global variable value in main after increment: %d\n",global_var);
    // pthread_join(tid, NULL);
    
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("Inside child process and PID: %d\n", getpid());
        printf("Global variable address in child: %p\n", &global_var);
        printf("Global variable value in child before increment: %d\n", global_var);
        global_var++;
        printf("Global variable value in child after increment: %d\n", global_var);
    }
    else
    {
        sleep(10);
        printf("Inside parent process and PID: %d\n", getpid());
        printf("Global variable address in parent: %p\n", &global_var);
        printf("Global variable value in parent after child increment: %d\n", global_var); 
    }


    return 0;
}
