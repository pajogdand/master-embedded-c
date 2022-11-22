#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 

void sigalrm_handler (int signum) 
{
	static int cnt=0; 
	++cnt; 
	printf ("Alarm expired %d time\n", cnt); 
}

int main (void) 
{
	signal (SIGALRM, sigalrm_handler); 
	alarm (2); 
	while (1) 
	{
			pause (); 
			alarm (2); 
	}

	exit (EXIT_SUCCESS); 
}
