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

int main(void){
	key_t key; 
	int shmid; 	
	int* p_shared_area = NULL; 
	int i; 
	pid_t writer_pid;

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
		printf("p_shared_area[%d]:%d\n", i, p_shared_area[i]); 
	
	writer_pid = p_shared_area[1023]; 
	
	if(shmdt(p_shared_area) == -1){
		fprintf(stderr, "shmdt:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}
	
	
	if(kill(writer_pid, SIGUSR1)  == -1){
		fprintf(stderr, "shmctl:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}


	if(shmctl(shmid, IPC_RMID, NULL) == -1){
		fprintf(stderr, "shmctl:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	exit(EXIT_SUCCESS); 
}

