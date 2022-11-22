#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <time.h> 

#define MAX_SLEEP_DURATION 4 
#define TRUE 1 

void *thread_fun(void *args); 

int global; 

int main(void) 
{
	pthread_t th1, th2, th3, th4; 

	srand(time(0)); 
	
	pthread_create(&th1, NULL, thread_fun, NULL); 
	pthread_create(&th2, NULL, thread_fun, NULL); 
	pthread_create(&th3, NULL, thread_fun, NULL); 
	pthread_create(&th4, NULL, thread_fun, NULL); 

	pthread_join(th1, NULL); 
	pthread_join(th2, NULL); 
	pthread_join(th3, NULL); 
	pthread_join(th4, NULL); 

	exit (EXIT_SUCCESS); 
}

void *thread_fun(void *args) 
{
	while(TRUE)
	{
		printf("thread:%lx:%d\n", (long int)pthread_self(), global++); 
		sleep(rand() % MAX_SLEEP_DURATION); 
	}

	return(NULL); 
}
