/*
 * File Name   : 19_producer_consumer.c
 * Folder      : 09_pthreads/05_semaphores
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 19_producer_consumer.c -lpthread
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
#include <semaphore.h>

#define NUM_THREADS 4

int buffer[10];
int count = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
sem_t empty, full;

/* Thread function */

void *producer(void *arg)
{
    printf("Inside producer function\n");
    while(1)
    {
       
        // if(count < 10)
        // {
            sem_wait(&empty);
                pthread_mutex_lock(&lock);
                    if(count <10)
                    {
                        buffer[count] = rand() % 100;
                        printf("Produced: %d\n", buffer[count]);
                        count++;
                    }
                pthread_mutex_unlock(&lock);
                usleep((rand() % 901 + 100) * 1000); // Simulate time taken to produce an item
            sem_post(&full);
        // }
        // else
        // {
        //     sem_wait(&consumed);
        //     printf("Buffer is full, producer is waiting...\n");
        //     sem_post(&produced);
        // }

    }
    return NULL;
}

void *consumer(void *arg)
{
    printf("Inside consumer function\n");

    int y = 0;

    while(1)
    {
        
        // if(count > 0)
        // {
            sem_wait(&full);
                pthread_mutex_lock(&lock);
                    if(count < 10)
                    {
                        y = buffer[count - 1];
                        printf("Consumed: %d\n", y);
                        count--;
                    }    
                pthread_mutex_unlock(&lock);
                usleep((rand() % 901 + 100) * 1000);
            sem_post(&empty);
        // }
        // else
        // {
            // sem_wait(&consumed);
            // printf("Buffer is empty, consumer is waiting...\n");
            // sem_post(&produced);
        // }

    }

    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];

    sem_init(&empty , 0 , 10);
    sem_init(&full , 0 , 0);
    for(int i = 0; i < NUM_THREADS; i++)
    {
        if(i % 2 == 0)
            pthread_create(&tid[i], NULL, producer, NULL);
        else
            pthread_create(&tid[i], NULL, consumer, NULL);
    }

    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
