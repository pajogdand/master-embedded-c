#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <signal.h> 
#include <sys/types.h> 

void sighandler (int signum); 
void signewhandler (int signum, siginfo_t *si, void *ptr); 

int main (void) 
{
	pid_t pid; 
	int ret; 
	static struct sigaction old, new; 
	sigset_t sigset; 
	int flags = 0; 	
	/* Build sigmask */ 
	sigemptyset (&sigset); 
	sigaddset (&sigset, SIGCHLD); 
	/* Build flags */ 
	flags = SA_SIGINFO | SA_NOCLDSTOP; 	
	/* Fill sigaction */ 
	new.sa_sigaction = signewhandler; 
	new.sa_mask = sigset; 
	new.sa_flags = flags; 
	sigaction (SIGCHLD, &new, &old); 
	pid = fork (); 
	if (pid == -1) {
		fprintf (stderr, "fork:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	if (pid == 0) {
		while (1) {
			printf ("Hello\n"); 
		}
	}
	else{
		while (1); 
	}
	
	exit (EXIT_SUCCESS); 
}

void sighandler (int signum) 
{
	printf ("signum:%d\n", signum); 
}

void signewhandler (int signum, siginfo_t *si, void *ptr) 
{
	printf ("I am here\n"); 	
}
