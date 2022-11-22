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

	static char *args[] = {"ls", "-l", "/", (char*)0}; 

	pid = fork (); 
	if ((int)pid == -1) 
	{
		fprintf (stderr, "fork:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	} 

	if ((int)pid == 0) 
	{
		execv ("/bin/ls", args); 
		fprintf (stderr, "exec:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	else
	{
		wait (&ret); 
	}

	return (EXIT_SUCCESS); 
}
