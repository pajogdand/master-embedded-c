#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <signal.h> 

// Step 1 - A: Declare signal handler 
void my_sigusr1_handler(int signum, siginfo_t *si, void *regs); 

int main(void) 
{
	int ret; 
	sigset_t sigset; 

	//	Step 2: Allocate & initialize 
	//	instances to struct sigaction 
	struct sigaction new_action, old_action; 
	memset(&new_action, 0, sizeof(struct sigaction)); 
	memset(&old_action, 0, sizeof(struct sigaction)); 

	//	Step 3: Build signal mask 
	sigemptyset(&sigset); 
	sigaddset(&sigset, SIGUSR1); 

	//	Step 4: Fill sigaction structure 
	new_action.sa_sigaction = my_sigusr1_handler; 
	new_action.sa_mask = sigset; 
	new_action.sa_flags = SA_SIGINFO; 

	//	Step 5: Register new signal handler 
	ret = sigaction(SIGUSR1, &new_action, NULL); 
	if(ret == -1){
		fprintf(stderr, "SIGUSR1 : %s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	while(1); 

	return EXIT_SUCCESS; 
}

// Step 1 - B: Define signal handler 

void my_sigusr1_handler(int signum, siginfo_t *si, void *regs)
{
	//	Write definition 
	//	Make use of siginfo_t struture instance 
	//	available through si. 
	printf("SIGUSR1 : I AM IN NEW SIGNAL HANDLER\n"); 
}
