#define _GNU_SOURCE
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <signal.h> 
#include <fenv.h> 
#include <setjmp.h> 

void fpe_handler(int signum); 

jmp_buf buffer; 

int main(void) 
{
	double rs; 
	int ret; 

	signal(SIGFPE, fpe_handler); 
	feenableexcept(FE_DIVBYZERO); 
	
	ret = setjmp(buffer); 
	switch(ret)
	{
		case 1:
				goto skip; 
	}
	rs = 10.0 / 0.0; 

skip:
	printf("rs:%lf\n", rs); 
	printf("SURVIVED DIVIDE BY ZERO\n"); 
	exit(EXIT_SUCCESS); 
}

void fpe_handler(int signum)
{
	printf("IN SIGFPE\n"); 
	longjmp (buffer, 1); 
}
