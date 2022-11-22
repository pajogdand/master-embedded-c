#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h> 
#include <dirent.h> 
#include <sys/types.h> 


int main (int argc, char *argv[]) 
{
	
	if (argc != 2) 
	{
		fprintf (stderr, "Usage error : %s dir_name\n", argv[0]); 
		exit (EXIT_FAILURE); 
	}
	


	exit (EXIT_SUCCESS); 
}

