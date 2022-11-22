#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <time.h> 
#include <sys/types.h> 

#define TRUE 				 1 
#define CHILD_SLEEP_DURATION 2 
#define BUFFER_SIZE			 32 
#define SMALL_ASCII_START	 97
#define NR_SMALL_ALPHABETS	 26

char r_buffer[BUFFER_SIZE/4], w_buffer[BUFFER_SIZE]; 

int main(void)
{
	int fd[2], ret, rb, wb;  
	pid_t pid; 

	srand(time(0));

	ret = pipe(fd); 
	if(ret == -1){
		fprintf(stderr, "pipe:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	pid = fork(); 
	if((int)pid == -1){
		fprintf(stderr,"fork:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	if((int)pid == 0){
		if(close(fd[1]) == -1){
			fprintf(stderr, "close:%s\n", strerror(errno)); 
			exit(EXIT_FAILURE);
		}

		while(TRUE){
			sleep(CHILD_SLEEP_DURATION);
			memset(r_buffer, (int)'\0', BUFFER_SIZE/4); 
			rb = read(fd[0], r_buffer, BUFFER_SIZE/4); 
			if(rb == -1){
				fprintf(stderr, "read:%s\n", strerror(errno));
				exit(EXIT_FAILURE); 
			}
			printf("CHILD_READER:%s\n", r_buffer);
		}
	}
	else{
		if(close(fd[0]) == -1){
			fprintf(stderr, "close:%s\n", strerror(errno));
			exit(EXIT_FAILURE); 
		}

		while(TRUE){
			memset(w_buffer, SMALL_ASCII_START + (rand() % NR_SMALL_ALPHABETS), 
				  	BUFFER_SIZE); 

			wb = write(fd[1], w_buffer, BUFFER_SIZE);
			if(wb == -1){
				fprintf(stderr, "write:%s\n", strerror(errno)); 
				exit(EXIT_FAILURE); 
			}
		}
	}

	return(EXIT_SUCCESS); 
}