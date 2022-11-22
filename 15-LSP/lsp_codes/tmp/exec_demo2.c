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
		execlp ("ls", "ls", "-l", "/", (char*)0); 
	}
	else
	{
		wait (&ret); 
	}

	return (EXIT_SUCCESS); 
}
