#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 

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
		/* This is child's code */ 
		printf ("C:I am child and my pid is %d\n", 
			(int) getpid ()); 
		sleep (5); 
		printf ("C:I am about to be dead\n"); 
		exit (300); 
	}
	else
	{
		/* This is parent's code */ 
		printf ("P:I am parent and my pid is %d\n", 
			(int) getpid ()); 
		wait (&ret); 
		printf ("P:One of my children dead, it's return status is %d\n", 
			(int)(*(char*)((char*)&ret+1))); 
	}

	return (EXIT_SUCCESS); 
}
