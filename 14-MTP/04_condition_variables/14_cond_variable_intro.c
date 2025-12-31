/*
 * File Name   : 14_cond_variable_intro.c
 * Folder      : 09_pthreads/04_condition_variables
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - POSIX Threads (pthread)
 *   - gcc 14_cond_variable_intro.c -lpthread
 *
 * Author      : Pravin Jogdand
 * Date        : 29-12-2025
 *
 * Interview Tags :
 *   - pthreads
 */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
pthread_mutex_t fuel_lock;
pthread_cond_t cond_fuel;
int fuel = 0;
/* Thread function */
void *fuel_filling(void *arg)
{
    printf("Inside fuel_filling function\n");
    while(1)
    {
        pthread_mutex_lock(&fuel_lock);
        fuel = fuel + 20;
        pthread_mutex_unlock(&fuel_lock);
        printf("Fuel filled ==> Current fuel: %d liters\n", fuel);
        pthread_cond_broadcast(&cond_fuel);
        sleep(2); // Simulate time taken to fill fuel
    }
    return NULL;
}

void *car(void *arg)
{
    printf("Inside car function\n");
    pthread_mutex_lock(&fuel_lock);
    while((fuel < 40))
    {
        printf("Not enough fuel to start the car. Current fuel: %d liters. Waiting for fuel...\n", fuel);
        pthread_cond_wait(&cond_fuel, &fuel_lock);
        // this is quivalent to:
        // pthread_mutex_unlock(&fuel_lock);
        // wait for condition signal
        // pthread_mutex_lock(&fuel_lock);
        // sleep(1); // Simulate waiting time
    }

    fuel = fuel - 40;
    pthread_mutex_unlock(&fuel_lock);
    printf("Car started! Remaining fuel <== %d liters\n", fuel);
    return NULL;
}

int main(void)
{
    pthread_t tid[5];

    pthread_mutex_init(&fuel_lock, NULL);
    pthread_cond_init(&cond_fuel, NULL);

    for(int i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating car thread %d\n", i);
        if(i == 4)
        {
            if(pthread_create(&tid[0], NULL, fuel_filling, NULL) == 0)
            {
            printf("fuel_filling thread created successfully\n");
            }
            else
            {
            perror("pthread_create failed");
            return 1;
            };
        }
        else
        {
            if(pthread_create(&tid[i], NULL, car, NULL) == 0)
            {
            printf("car thread created successfully\n");
            }
            else
            {
            perror("pthread_create failed");
            return 1;
            }
        }
    }


    for(int i = 1; i < NUM_THREADS - 1; i++)
    {
        if (pthread_join(tid[i], NULL) != 0)
        {
            perror("pthread_join failed");
            return 1;
        }
    }

    pthread_mutex_destroy(&fuel_lock);
    pthread_cond_destroy(&cond_fuel);
    return 0;
}
