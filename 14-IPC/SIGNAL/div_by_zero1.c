#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <signal.h> 
#include <setjmp.h> 
#include <fenv.h> 

void sigfpe_handler(int signum); 

jmp_buf jmp_buffer; 

int main(void) 
{
	int ret; 

	feenableexcept(FE_DIVBYZERO); 
	signal(SIGFPE, sigfpe_handler); 
	
	ret = setjmp(jmp_buffer); 
	if(ret == 1)
			goto L1;

	double rs = 1.0 / 0.0; 
L1: 
	printf("Out of danger .. into infinite loop now...\n"); 
	while(1); 
	
	return (0); 
}

void sigfpe_handler(int signum) 
{
	printf("In SIGFPE handler\n"); 
	longjmp(jmp_buffer, 1); 
}
