#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <time.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

#define SMALL_ASCII_START	 97
#define NR_SMALL_ALPHABETS	 26
#define BUFFER_SIZE 		 32
#define TRUE 				 1 

char buffer[BUFFER_SIZE]; 

int main(int argc, char *argv[])
{
	int ret, fd_w, wb;

	if(argc != 2){
		fprintf(stderr, "usage error:%s fifo_name\n", argv[0]); 
		exit(EXIT_FAILURE); 
	}

	ret = mkfifo(argv[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
	if(ret == -1){
		fprintf(stderr, "open:%s:%s\n", argv[1], strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	fd_w = open(argv[1], O_RDWR); 
	if(fd_w == -1){
		fprintf(stderr, "open:%s:%s\n", argv[1], strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	while(TRUE){
		memset(buffer, SMALL_ASCII_START + (rand() % NR_SMALL_ALPHABETS), 
				  	BUFFER_SIZE); 
		wb = write(fd_w, buffer, BUFFER_SIZE);
			if(wb == -1){
				fprintf(stderr, "write:%s\n", strerror(errno)); 
				exit(EXIT_FAILURE); 
			}
		sleep(3);
	}

	return(EXIT_SUCCESS); 
}
