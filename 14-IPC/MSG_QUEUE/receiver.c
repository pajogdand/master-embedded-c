#include <stdio.h> 
#include <stdlib.h> 

#include <errno.h> 
#include <string.h> 

#include <unistd.h> 
#include <fcntl.h> 

#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

#include "command.h" 

#define FILE_NAME 		"common.txt" 
#define PROJECT_ID 		5 
#define READ_WRITE_SIZE 32 
#define TRUE 1 

struct command cmd; 

char msg[READ_WRITE_SIZE] = "AAAAAAAABBBBBBBBCCCCCCCCDDDDDDDD"; 
char r_buffer[READ_WRITE_SIZE]; 

int main(void){
	key_t key; 			/* output of ftok */ 
	int msgid; 			/* message queue descriptor */ 
	int ret_recv;		/* status of msgrvc() */ 
	int fd; 			/* file descriptor for new file */ 
	long offset; 		/* return value of lseek() */ 
	ssize_t wb, rb; 	/* return values of read()/write() */ 

	key = ftok(FILE_NAME, PROJECT_ID); 
	msgid = msgget(key, IPC_CREAT); 
	if(msgid == -1){
		fprintf(stderr, "msgget:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}


	while(TRUE){
		memset(&cmd, 0, sizeof(struct command)); 
		ret_recv = msgrcv(msgid, (void*)&cmd, sizeof(struct command), 0, 0); 
		if(ret_recv == -1){
			fprintf(stderr, "msgrcv:%s\n", strerror(errno)); 
			exit(EXIT_FAILURE); 
		}
	
		switch(cmd.cmd_type){
		
			case CMD_FILE_CREATE: 
				
					fd = open(cmd.path_name, cmd.open_flag, cmd.permissions); 
					if(fd == -1){
						fprintf(stderr, "open:%s:%s\n", cmd.path_name, 
										strerror(errno)); 
						exit(EXIT_FAILURE); 
					}

					if(close(fd) == -1){
						fprintf(stderr, "close:%s:%s\n", cmd.path_name, 
								strerror(errno)); 
						exit(EXIT_FAILURE); 
					}
				
					break; 

			case CMD_FILE_READ: 
					
					fd = open(cmd.path_name, O_RDONLY);
					if(fd == -1){
						fprintf(stderr, "open:%s:%s\n", cmd.path_name, strerror(errno)); 
						exit(EXIT_FAILURE); 
					}
					
					offset = lseek(fd, SEEK_SET, cmd.offset); 
					if(offset == -1){
						fprintf(stderr, "lseek:%s:%s\n", cmd.path_name, strerror(errno)); 
						exit(EXIT_FAILURE); 
					}

					memset(r_buffer, 0, READ_WRITE_SIZE); 
					rb = read(fd, r_buffer, READ_WRITE_SIZE); 	
					if(rb == -1){
						fprintf(stderr, "read:%s:%s\n", cmd.path_name, strerror(errno)); 
						exit(EXIT_FAILURE); 
					}
	
					puts("Read portion of file:"); 
					write(STDOUT_FILENO, r_buffer, READ_WRITE_SIZE); 

					if(close(fd) == -1){
						fprintf(stderr, "close:%s:%s\n", cmd.path_name, strerror(errno));
						exit(EXIT_FAILURE); 
					}

					break; 

			case CMD_FILE_WRITE: 

					fd = open(cmd.path_name, O_RDWR); 
					if(fd == -1){
						fprintf(stderr, "write:%s:%s\n", cmd.path_name, 
										strerror(errno)); 
						exit(EXIT_FAILURE); 
					}

					offset = lseek(fd, SEEK_SET, cmd.offset); 
					if(offset == -1){
						fprintf(stderr, "lseek:%s:%s\n", cmd.path_name, 
										strerror(errno)); 
						exit(EXIT_FAILURE); 
					}

					wb = write(fd, msg, cmd.size); 
					if(wb != cmd.size){
						fprintf(stderr, "write:%s:%s\n", cmd.path_name, 
										strerror(errno)); 
						exit(EXIT_FAILURE); 
					}

					if(close(fd) == -1){
						fprintf(stderr, "close:%s:%s\n", cmd.path_name,
										strerror(errno)); 
						exit(EXIT_FAILURE); 
					}

					break; 

			case CMD_TERMINATE:
					puts("exiting..."); 
					exit(EXIT_SUCCESS); 
			default: 

					break; 
		}
	}
	
	exit(EXIT_SUCCESS); 
}
