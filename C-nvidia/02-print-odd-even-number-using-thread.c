#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t	mutexFuel;
pthread_cond_t	condFuel;
int		num = 0;
int		MAX_LIMIT = 19;

void* print_even(void* arg) {
    (void)arg;
    while (1) {
        pthread_mutex_lock(&mutexFuel);
        if (num > MAX_LIMIT) {
            pthread_mutex_unlock(&mutexFuel);
            pthread_cond_broadcast(&condFuel);
            return (NULL);
        }
        if(num%2 == 0){
            printf("even num.. %d\n", num);
            num += 1;
        }
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_broadcast(&condFuel);
        sleep(1);
    }
    return (NULL);
}

void* print_odd(void* arg) {
    (void)arg;
    while (1) {
        pthread_mutex_lock(&mutexFuel);
        while (num%2 == 0) {
            printf("number if even Waiting...\n");
            pthread_cond_wait(&condFuel, &mutexFuel);
            // Equivalent to:
            // pthread_mutex_unlock(&mutexFuel);
            // wait for signal on condFuel
            // pthread_mutex_lock(&mutexFuel);
        }
	if (num > MAX_LIMIT) {
             pthread_mutex_unlock(&mutexFuel);
             return (NULL);
	}
        printf("odd num.. %d\n", num);
        num += 1;
        pthread_mutex_unlock(&mutexFuel);
    }
    return (NULL);
}

int main(void) {
    pthread_t th[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    for (int i = 0; i < 2; i++) {
        if (i == 1) {
            if (pthread_create(&th[i], NULL, &print_even, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &print_odd, NULL) != 0) {
                perror("Failed to create thread");
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return (EXIT_SUCCESS);
}
