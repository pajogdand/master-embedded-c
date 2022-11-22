#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <sys/types.h> 

int main(void) 
{
	pid_t pid; 

	pid = fork(); 
	if(pid == 0){
		sleep(3); 
		printf("I am about to exit...\n"); 
		exit(0); 
	}
	else{
		while(1); 
	}

	exit(0); 

}
