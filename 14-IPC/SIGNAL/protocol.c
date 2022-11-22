#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <signal.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

void chld_sig_handler1(int signum); 
void chld_sig_handler2(int signum);
void parent_sig_handler1(int signum); 
void parent_sig_handler2(int signum); 

int main(void) 
{
	pid_t pid; 

	signal(SIGUSR1, parent_sig_handler1); 
	signal(SIGUSR2, parent_sig_handler2); 

	pid = fork(); 
	if(pid == 0) {
		sleep(1); 
		signal(SIGUSR1, chld_sig_handler1);  
		signal(SIGUSR2, chld_sig_handler2); 
		kill(getppid(), SIGUSR1); 
		while(1) 
				pause(); 
	}
	else {
		//pause(); 
		kill(pid, SIGUSR1); 
		while(1){
				kill(pid, SIGUSR2); 
				sleep(2); 
		}
	}

	return (EXIT_SUCCESS); 
}

void chld_sig_handler1(int signum)
{
	printf("HERE\n");
}


void chld_sig_handler2(int signum)
{
	printf("HERE2\n"); 
}

void parent_sig_handler1(int signum)
{

}

void parent_sig_handler2(int signum)
{

}
