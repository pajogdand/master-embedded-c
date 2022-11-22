#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <dirent.h> 
#include <sys/types.h> 


int main (int argc, char *argv[]) 
{
	DIR *dirp = NULL; 
	struct dirent *dir = NULL; 

	if (argc != 2) 
	{
		fprintf (stderr, "Usage error : %s dir_name\n", 
			 argv[0]); 
		exit (EXIT_FAILURE); 
	}

	dirp = opendir (argv[1]); 
	if (!dirp) 
	{
		fprintf (stderr, "Error in opening directory %s\n", 
			 argv[1]); 
		exit (EXIT_FAILURE); 
	}
	
	while ((dir = readdir (dirp)) != NULL) 
	{
		printf ("%s\n", dir->d_name); 
	}
	
	if (closedir (dirp) == -1) 
	{
		fprintf (stderr, "Error in closing directory %s\n", 
			 argv[1]); 
		exit (EXIT_FAILURE); 
	}
	dirp = NULL; 

	exit (EXIT_SUCCESS); 
}
