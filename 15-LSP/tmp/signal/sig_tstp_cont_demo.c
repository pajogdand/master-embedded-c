#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <signal.h> 
#include <unistd.h> 
#include <sys/types.h> 

void sigalrm_handler (int signum); 
void sigusr1_handler (int signum); 

pid_t pid; 

int main (void) 
{

	signal (SIGALRM, sigalrm_handler); 

	pid = fork (); 
	if ((int)pid == -1) 
	{
		fprintf (stderr, "fork:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	if ((int)pid == 0)
	{
		signal (SIGALRM, SIG_IGN); 
		while (1)
			printf ("C:Doing work...\n"); 
	}
	else
	{
		while (1) 
		{
			kill (pid, SIGTSTP); 
			alarm (2);
			pause (); 
		}
	}

	exit (EXIT_SUCCESS); 
}

void sigalrm_handler (int signum) 
{
	kill (pid, SIGCONT);
	sleep (3); 
	raise (SIGUSR1); 
}

void sigusr1_handler (int signum) 
{

}
