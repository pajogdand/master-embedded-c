#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <time.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

#define BUFFER_SIZE 8 
#define TRUE 		1 

char buffer[BUFFER_SIZE]; 

int main(int argc, char *argv[])
{
	int fd_r, rb; 

	if(argc != 2){
		fprintf(stderr, "usage error:%s fifo_name\n", argv[0]); 
		exit(EXIT_FAILURE); 
	}

	fd_r = open(argv[1], O_RDONLY); 
	if(fd_r == -1){
		fprintf(stderr, "open:%s:%s\n", argv[1], strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	while(TRUE){
		rb = read(fd_r, buffer, BUFFER_SIZE);
		if(rb == -1){
			fprintf(stderr, "read:%s:%s\n", argv[1], strerror(errno)); 
			exit(EXIT_FAILURE);
		}

		printf("READER:%s\n", buffer); 
	}

	return(EXIT_SUCCESS); 
}
