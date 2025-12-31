/*
 * File Name   : 17_semaphore_intro.c
 * Folder      : 09_pthreads/05_semaphores
 *
 * Description :
 *   Demonstrates use of a BINARY semaphore
 *   to protect a global shared variable.
 *
 *   Multiple threads increment a global counter.
 *   Binary semaphore ensures mutual exclusion.
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
 *   - binary semaphore
 *   - critical section
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 1

sem_t my_sem;
pthread_mutex_t mutexFuel;

int *global;

void* routine(void* args) {
    *global += 50;
    printf("Current value is %d\n", *global);
    sem_post(&my_sem);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    global = malloc(sizeof(int));
    *global = 50;
    pthread_mutex_init(&mutexFuel, NULL);
    sem_init(&my_sem, 0, 0);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Failed to create thread");
        }
    }
    sem_wait(&my_sem); // this is kind of blocking call which will be sigaled by sem_post in thread
     // why this is blocking call , becuase, current value of my_sem is 0 as it is init by sem_init(&my_sem, 0, 0);
     // and thumb rule says, if it 0 then do not execute statement below to it.
     // and after executing of sem_post(&my_sem) my_sem value will be incremneted to 1 ,and the folllowing lines will be executed.
    printf("Deallocating global\n");
    free(global);

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    sem_destroy(&my_sem);
    return 0;
}