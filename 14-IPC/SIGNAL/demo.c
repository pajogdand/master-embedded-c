#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <signal.h> 

void handle_sigcont(int n){} 
void handle_sigtstp(int n){} 


int main(void) 
{
	pid_t pid; 
	static unsigned int stop=1; 

	pid = fork(); 

	if((int)pid == 0){
		//signal(SIGCONT, handle_sigcont); 
		//signal(SIGTSTP, handle_sigtstp); 
		while(1){
		printf("hello\n"); 
		}
	} 
	else
	{
		sleep(3); 
		while(1)
		{
			if(stop){
				kill(pid, SIGTSTP); 
				sleep(2); 
				stop = 0; 
			}
			else{
				kill(pid, SIGCONT); 
				stop = 1; 
				sleep(2); 
			} 
		}

	}
	

	return (0); 
}
