/*
 * File Name   : 18_counting_semaphore_resource_pool.c
 * Folder      : 09_pthreads/05_semaphores
 *
 * Description :
 *   Demonstrates practical use of a COUNTING semaphore
 *   to manage a limited number of hardware resources
 *   (e.g., DMA / ADC / UART channels) in embedded systems.
 *
 *   Only MAX_RESOURCES threads are allowed to access
 *   the critical hardware section simultaneously.
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 18_counting_semaphore_resource_pool.c -lpthread
 *
 * Author      : Pravin Jogdand
 * Date        : 29-12-2025
 *
 * Interview Tags :
 *   - pthreads
 *   - counting semaphore
 *   - embedded systems
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_THREADS     8
#define MAX_RESOURCES   3   // Limited hardware resources

/* Counting Semaphore */
sem_t resource_sem;

void DMA_Operation()
{
    // Simulate DMA operation
    printf("Performing DMA Operation...\n");
    sleep(1);
}

void ADC_Operation()
{
    // Simulate ADC operation
    printf("Performing ADC Operation...\n");
    sleep(1);
}

void UART_Operation()
{
    // Simulate UART operation
    printf("Performing UART Operation...\n");
    sleep(1);
}

/* Thread function */
void *hardware_task(void *arg)
{
    int id = *(int *)arg;
    free(arg);

    printf("[Thread %d] Waiting for hardware resource...\n", id);
    sem_wait(&resource_sem);   // Acquire resource

    printf("[Thread %d] Resource acquired (DMA/ADC/UART)\n", id);
    DMA_Operation();
    ADC_Operation();
    UART_Operation();
    sleep(rand() % 3 + 1);     // Simulate hardware usage

    sleep(10);

    // printf("[Thread %d] Releasing resource\n", id);
    sem_post(&resource_sem);   // Release resource

    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];

    /* Initialize counting semaphore */
    sem_init(&resource_sem, 0, MAX_RESOURCES);

    for (int i = 0; i < NUM_THREADS; i++)
    {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[i], NULL, hardware_task, id);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&resource_sem);
    return 0;
}
