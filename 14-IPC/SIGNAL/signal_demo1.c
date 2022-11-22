#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

void sig_handler(int); 

int main(void) 
{
	signal(SIGUSR1, sig_handler); 

	while(1){
			kill(getpid(), SIGUSR1); 
			sleep(2); 
	}

	exit(EXIT_SUCCESS); 

}

void sig_handler(int sig_num) 
{
	printf("I am in signal handler : sig_num:%d\n", sig_num); 
}
