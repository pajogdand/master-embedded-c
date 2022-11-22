#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 

#include <unistd.h> 

#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>

#include <signal.h> 

#define FILE_NAME 	"common.txt" 
#define PROJECT_ID 	5 
#define PAGE_SIZE 	4096
#define TRUE 		1 

void sigusr1_handler(int); 

int main(void){
	key_t key; 
	int shmid; 	
	int* p_shared_area = NULL; 
	int i; 
	
	signal(SIGUSR1, sigusr1_handler); 

	key = ftok(FILE_NAME, PROJECT_ID); 
	shmid = shmget(key, PAGE_SIZE, IPC_CREAT); 
	if(shmid == -1){
		fprintf(stderr, "shmget:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	p_shared_area = shmat(shmid, NULL, 0); 
	if(p_shared_area == NULL){
		fprintf(stderr, "shmat:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	for(i = 0; i < 1023; ++i)
		p_shared_area[i] = (i+1) * 10; 
	
	p_shared_area[1023] = getpid(); 
	
	if(shmdt(p_shared_area) == -1){
		fprintf(stderr, "shmdt:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	puts("Done writing on shared area....Pausing now ..."); 
	pause(); 

	exit(EXIT_SUCCESS); 
}

void sigusr1_handler(int signum){
	puts("exiting...."); 
	exit(EXIT_SUCCESS); 
}
