#define _GNU_SOURCE
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <signal.h> 
#include <unistd.h> 

int main(void)
{
	sigset_t sig_mask; 
	int i; 

	sigemptyset(&sig_mask); 
	for(i=0; i < 32; ++i)
		printf("sig_mask.__val[%u]:%lu\n", i, sig_mask.__val[i]); 
	sigaddset(&sig_mask, SIGUSR1); 

	for(i=0; i < 32; ++i)
		printf("sig_mask.__val[%u]:%lu\n", i, sig_mask.__val[i]); 

	sigaddset(&sig_mask, SIGUSR2); 
	for(i=0; i < 32; ++i)
		printf("sig_mask.__val[%u]:%lu\n", i, sig_mask.__val[i]); 

	return (EXIT_SUCCESS); 
}