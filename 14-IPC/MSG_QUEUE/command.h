#ifndef _COMMAND_H
#define _COMMAND_H

#define CMD_FILE_CREATE 	1 
#define CMD_FILE_READ 		2 
#define CMD_FILE_WRITE 		3 
#define CMD_TERMINATE		4 
#define MAX_PATH_LENGTH 	32

struct command{
	int cmd_type; 
	char path_name[MAX_PATH_LENGTH]; 
	
	/* create command */ 
	int open_flag; 
	int permissions; 

	/* read/write command */ 
	long offset; 
	unsigned long size; 
}; 

#endif /* _COMMAND_H */ 
