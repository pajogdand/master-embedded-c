#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h> 

void signal_handler (int sig_num) 
{
	static int i=0; 
	++i; 
	printf ("signal:%d received %dth time\n", sig_num, i); 
}

int main (void) 
{
//	signal (SIGUSR1, signal_handler); 
	printf ("process with pid:%d running\n", getpid ()); 
	while (1) 
	; 
	exit (EXIT_SUCCESS); 
}
