#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 
#include <time.h> 

void sigalrm_handler (int signum) 
{
	static int cnt=0; 
	time_t current_time = time(0); 
	++cnt; 
	printf ("Alarm expired %d time stamp : %s\n", cnt, ctime(&current_time)); 
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
