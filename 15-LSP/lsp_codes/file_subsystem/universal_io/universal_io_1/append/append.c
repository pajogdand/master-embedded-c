#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 

#define TRUE		1
#define FALSE		0
#define STR_EQ		0	
#define BUFFER_SIZE	4096

void *xcalloc (int nr_elements, int size_per_element); 
void print_usage (void); 
void print_version (void); 
void append (char **src_files, int *hole_sizes_f, int nr_src_files, int hole_flag, 
			 char *dest_file); 
void clean (char **src_files, int *hole_sizes_f, int nr_src_files); 

char buffer [BUFFER_SIZE]; 

int main (int argc, char *argv[]) 
{
	int i, ret, len; 
	int nr_src_files=0, nr_holes=0;  
	int input_flag=FALSE, output_flag=FALSE, hole_flag=FALSE; 
	int  *hole_sizes_i, *hole_sizes_f; 
	char *dest_file="append.out"; 
	char **src_files; 

	while ((ret = getopt (argc, argv, "i:o:h:")) != -1) 
	{
		switch (ret) 
		{
			case 'i':
			    input_flag = TRUE; 	
				for (i=optind-1; i < argc && *(argv [i] + 0) != '-'; 
				     i++, nr_src_files++); 
				src_files = (char**)calloc (nr_src_files, sizeof (char*)); 
				for (i=0; i < nr_src_files;  i++) 
				{
					len = strlen (argv[optind+i-1]); 
					src_files [i] = (char*)xcalloc (1, len+1); 
					strncpy (src_files [i], argv[optind+i-1], len); 
				}
				break; 
			case 'o':
				output_flag = TRUE; 
				len = strlen (optarg); 
				dest_file = (char*)xcalloc (1, len+1);
				strncpy (dest_file, optarg, len); 
				break; 		
			case 'h': 
				hole_flag = TRUE; 
				for (i=optind-1; i < argc && *(argv[i]+0) != '-'; 
				     i++, nr_holes++); 
				hole_sizes_i = (int*) xcalloc (nr_holes, sizeof (int)); 
				for (i=0; i < nr_holes; i++) 
				{
					hole_sizes_i[i] = atol (argv [optind+i-1]); 
				}
				break; 
			default: 
				print_usage (); 
				exit (EXIT_FAILURE); 
		}
	}	

	if ((input_flag == FALSE) || (nr_holes > nr_src_files)) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}
	
	if (hole_flag == FALSE)
	{
		hole_sizes_f = (int*) xcalloc (nr_src_files, sizeof (int)); 	
	}
	else if (hole_flag == TRUE)
	{
		hole_sizes_f = (int*)xcalloc (nr_src_files, sizeof (int)); 
		memcpy (hole_sizes_f, hole_sizes_i, nr_holes * sizeof (int)); 
		free (hole_sizes_i); 
	}

	append (src_files, hole_sizes_f, nr_src_files, hole_flag, dest_file); 
	clean (src_files, hole_sizes_f, nr_src_files); 

	exit (EXIT_SUCCESS);
}

void append (char **src_files, int *hole_sizes_f, int nr_src_files, int hole_flag, char *dest_file)
{
	int *src_fds; 
	int dest_fd, rb, wb, i;
	off_t curr_off; 

	
	src_fds = (int*) xcalloc (nr_src_files, sizeof (int)); 

	for (i=0; i < nr_src_files; i++) 
	{
		src_fds [i] = open (src_files [i], O_RDONLY); 
		if (src_fds[i] < 0) 
		{
			fprintf (stderr, "cannot open %s:%s\n", src_files[i], strerror (errno));   
		}		
	}	

	dest_fd = open (dest_file, O_RDWR | O_CREAT | O_TRUNC, 
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (dest_fd < 0)
	{
		fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	
	for (i=0; i < nr_src_files; i++) 
	{
		if (src_fds [i] > 0)
		{
			memset (buffer, '\0', BUFFER_SIZE); 
			while ((rb = read (src_fds [i], buffer, BUFFER_SIZE)) > 0)
			{
				if (rb < 0) 
				{
					fprintf (stderr, "%s:%s\n", src_files [i], strerror (errno)); 
					exit (EXIT_FAILURE); 
				}
				wb = write (dest_fd, buffer, rb); 
				if (rb != wb) 
				{
					fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
					exit (EXIT_FAILURE); 
				}
			}

			if (close (src_fds [i]) == -1) 
			{
				fprintf (stderr, "%s:%s\n", src_files [i], strerror (errno)); 
				exit (EXIT_FAILURE); 
			}
		}			

		if (hole_sizes_f [i] > 0)
		{
			curr_off = lseek (dest_fd, hole_sizes_f [i], SEEK_END); 
			if (curr_off == -1) 
			{
				fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
				exit (EXIT_FAILURE); 
			}
		}
	}	

	if (hole_flag == TRUE) 
	{
		wb = write (dest_fd, "\0", 1); 
		if (wb != 1) 
		{
			fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
	}

	if (close (dest_fd) == -1) 
	{
		fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
}

void clean (char **src_files, int *hole_sizes_f, int nr_src_files) 
{
	int i; 

	for (i=0; i < nr_src_files; i++) 
	{
		if (src_files [i] != NULL) 
		{
			free (src_files [i]); 
		}
	}

	if (src_files != NULL) 
	{
		free (src_files); 
	}

	if (hole_sizes_f != NULL) 
	{
		free (hole_sizes_f); 
	}
}

void *xcalloc (int nr_elements, int size_per_element) 
{
	void *ptr; 

	ptr = calloc (nr_elements, size_per_element); 
	if (ptr == NULL) 
	{
		fprintf (stderr,"xcalloc:fatal:out of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (ptr); 
}

void print_usage (void) 
{
	printf ("f_hole -i ip_file [list] -h hole_size [list] -o op_file\n"); 
	printf ("holes list must not exceed ip_file list. if holes list\n"); 
	printf ("is less than ip_list then all subsequent files will be\n"); 
	printf ("appended without any hole i.e. default 0 will be considered\n"); 
	printf ("If -h option is omitted all together, all files in the input list\n"); 
	printf ("will be appended and output file will be produced\n"); 
}

void print_version (void) 
{
	printf ("0.1\n"); 
}
