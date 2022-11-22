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
		printf ("I am child and my pid is %d\n", 
			(int) getpid ()); 
	}
	else
	{
		/* This is parent's code */ 
		printf ("I am parent and my pid is %d\n", 
			(int) getpid ()); 
	}

	/* This will be executed by both */ 
	printf ("This will be executed twice : %d\n", (int)getpid ()); 
	return (EXIT_SUCCESS); 
}
