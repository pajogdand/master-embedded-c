#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 

#define BUFFER_SIZE 4096 
char buffer[BUFFER_SIZE]; 


int main(int argc, char *argv[])
{
	long int ret; 
	int fd, wb; 

	if(argc != 2){
		fprintf(stderr, "%s file_name\n", argv[0]); 
		exit(EXIT_FAILURE); 
	}

	fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if(fd == -1){
		fprintf(stderr,"open:%s\n", argv[1]); 
		exit(EXIT_FAILURE); 
	}

	memset(buffer, (int)'A', BUFFER_SIZE); 

	ret = write(fd, buffer, BUFFER_SIZE); 
	if(ret != BUFFER_SIZE){
		fprintf(stderr, "write:%s:%s\n", argv[1], strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	ret = lseek(fd, 0, SEEK_END); 
	if(ret == -1){
		fprintf(stderr, "lseek:%s:%s\n", argv[1], strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	printf("END:%ld\n", (long int)ret); 

	ret = lseek(fd, 4096, SEEK_END); 
	if(ret == -1){
		fprintf(stderr, "lseek:%s:%s\n", argv[1], strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	wb = write(fd, "\n", 1); 
	if(wb != 1){
		fprintf(stderr, "write:%s:%s\n", argv[1], strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	if(close(fd) == -1){
		fprintf(stderr, "close:%s:%s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE); 
	}

	return(EXIT_SUCCESS); 
}