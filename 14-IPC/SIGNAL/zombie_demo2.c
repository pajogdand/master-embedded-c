#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h>
#include <signal.h> 
#include <sys/types.h> 

void sigchld_handler (int); 

int main (void) 
{
	pid_t pid; 

	signal (SIGCHLD, SIG_IGN); 

	pid = fork (); 

	if ((int)pid == -1) 
	{
		fprintf (stderr, "fork:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	if (pid == 0) 
	{
			exit (EXIT_SUCCESS); 
	}
	else
	{
		while (1); 		
	}

	exit (EXIT_SUCCESS); 
}

void sigchld_handler (int signum) 
{
	printf ("I am here\n"); 
	while (1); 	
}
