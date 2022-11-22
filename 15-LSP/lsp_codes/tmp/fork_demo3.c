#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 

#define TRUE 1 

int main (void) 
{
	pid_t pid; 
	int ret; 

	pid = fork (); 
	if ((int)pid == -1) 
	{
		fprintf (stderr, "fork:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	} 

	if ((int)pid == 0) 
	{
		while (TRUE)
		{
			printf ("C:pid=%d ppid=%d\n", (int) getpid (), (int) getppid ()); 
			sleep (1); 
		}
	}
	else
	{
		/* This is parent's code */ 
		while (TRUE)
		{
			printf ("P:pid=%d ppid=%d\n", (int) getpid (), (int) getppid ()); 
			sleep (2); 
		}
	}

	return (EXIT_SUCCESS); 
}
