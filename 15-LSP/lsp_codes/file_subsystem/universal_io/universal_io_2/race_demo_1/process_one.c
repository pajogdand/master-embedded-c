#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <getopt.h> 
#include <string.h> 
#include <fcntl.h> 
#include <unistd.h> 

int main (int argc, char *argv[]) 
{
	int fd;
	char *f_name="abc.txt"; 

	fd = open (f_name, O_WRONLY); 
	if (fd != -1)
	{
		printf ("open:%d: file %s already exists\n", 
			(int)getpid (), argv[1]); 
		close (fd); 
	}
	else 
	{
		printf ("Going to sleep .....\n"); 
		sleep (15);
		fd = open (f_name, O_RDONLY | O_CREAT, 
			   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
		
		if (fd < 0)
		{
			printf ("open:%s:%s\n", 
			f_name, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}		
	}

	printf ("fd = %d\n", fd); 

	if (close (fd) == -1) 
	{
		printf ("close:%s:%s\n", 
		f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS); 
}


