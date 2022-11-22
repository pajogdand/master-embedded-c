#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h> 

int main (void)
{
	int n; 

	printf ("Enter an integer:");
	scanf ("%d", &n); 

	if (n < 0) 
		kill (getpid (), SIGABRT); 	//abort (); 

	exit (EXIT_SUCCESS); 
}
