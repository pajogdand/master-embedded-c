#define _GNU_SOURCE
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <fenv.h> 
#include <setjmp.h> 
#include <unistd.h> 
#include <signal.h> 
#include <sys/types.h> 

void sigaction_handler(int signum, siginfo_t *si, void *regs); 
jmp_buf jump_buffer; 


int main(void) 
{
	int except = 0, ret; 
	double rs; 
	
	sigset_t sigmask; 
	struct sigaction sa_new, sa_old; 
	
	memset(&sa_new, (int)'\0', sizeof(struct sigaction)); 
	memset(&sa_old, (int)'\0', sizeof(struct sigaction)); 

	sigemptyset(&sigmask); 
	sigaddset(&sigmask, SIGFPE); 

	sa_new.sa_sigaction = sigaction_handler; 
	sa_new.sa_mask = sigmask; 
	sa_new.sa_flags = SA_SIGINFO; 

	ret = sigaction(SIGFPE, &sa_new, &sa_old); 
	if (ret != 0) 
	{
		fprintf(stderr, "sigaction:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	except |= FE_DIVBYZERO; 
	
	ret = feenableexcept(except); 
	if(ret == -1) 
	{
		printf("Error in enabling exception\n"); 
		exit(EXIT_FAILURE); 
	} 

	ret = setjmp(jump_buffer); 
	if(ret == 0) 
	{
		printf("Jump has been set successfully\n"); 
	}
	else if(ret == 1) 
	{
		goto skip; 
	}

	rs = 10.0/0.0; 
skip: 
	printf("I have been successfull in attempting divide by zero and yet surviving\n"); 

	exit(EXIT_SUCCESS); 
}

void sigaction_handler(int signum, siginfo_t *si, void *regs) 
{
		if (si->si_code == FPE_FLTDIV){
			printf("attempt has been made to divide by floating 0\n"); 
			longjmp(jump_buffer, 1); 
		}
}
