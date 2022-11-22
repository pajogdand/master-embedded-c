#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <getopt.h> 
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 

#define TRUE		1
#define FALSE 		0
#define STR_EQ		0
#define LONG_OPTION	0
#define BUFFER_SIZE	4096

void *xcalloc (int nr_elements, int size_per_element); 
void print_usage (void); 
void print_version (void); 

char buffer [BUFFER_SIZE]; 

int main (int argc, char *argv[]) 
{
	int ret, i; 
	int len; 
	int append_flag=FALSE, src_flag=FALSE;  
	int fd, open_flag, fd_src=STDIN_FILENO; 	
	int rb, wb;	
	char *dest_file="tee.out", *src_file=NULL; 

	static struct option opts [] = 
	{
		{"help", no_argument, 0, 0}, 
		{"version", no_argument, 0, 0}, 
		{"append", no_argument, 0, 'a'}, 
		{"input", required_argument, 0, 'i'}, 
		{"output", required_argument, 0, 'o'}
	};

	while ((ret = getopt_long (argc, argv, "hvao:i:", opts, &i)) != -1) 
	{
		switch ((char)ret)
		{
			case 'a':
				append_flag = TRUE; 
				break; 
			case 'i': 
				src_file = optarg; 
				src_flag = TRUE; 
				break; 
			case 'o': 
				len = strlen (optarg); 
				dest_file = (char*)xcalloc (1, len+1); 
				strncpy (dest_file, optarg, len); 
				break; 
			case 'h': 
				print_usage (); 
				exit (EXIT_SUCCESS); 
			case 'v': 
				print_version (); 
				exit (EXIT_SUCCESS); 
			default: 
				print_usage (); 
				exit (EXIT_FAILURE); 
		}
	}

	if (append_flag == TRUE)
	{
		open_flag = O_RDWR | O_CREAT | O_APPEND; 
	}
	else 
	{
		open_flag = O_RDWR | O_CREAT | O_TRUNC; 
	}

	if (src_flag == TRUE) 
	{
		fd_src = open (src_file, O_RDONLY | O_SYNC); 
		if (fd_src == -1) 
		{
			fprintf (stderr, "open:%s:%s\n", src_file, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
	}
	
	fd = open (dest_file, open_flag, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
	if (fd < 0) 
	{
		fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
		
	while ((rb = read (fd_src, buffer, BUFFER_SIZE)) > 0)
	{
		if (rb == -1) 
		{
			fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
		
		wb = write (STDOUT_FILENO, buffer, rb);
		if (rb != wb) 
		{
			fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}

		wb = write (fd, buffer, rb); 
		if (wb != rb)
		{
			fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
	}

	if (close (fd) == -1) 
	{
		fprintf (stderr, "%s:%s\n", dest_file, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS); 
}

void print_usage (void) 
{
	printf ("tee [--append/a] [--output/o output_file_name]\n"); 
	printf ("Copies contents from standard output to file named in -o\n"); 
	printf ("if output file name is not specified then tee.out file is created\n"); 
	printf ("--append or -a causes write to be appended should the file already exist\n"); 
	printf ("in the absence of --append/-a file is truncated\n"); 
}

void print_version (void) 
{
	printf ("0.1\n"); 
}

void *xcalloc (int nr_elements, int size_per_element) 
{
	void *ptr; 

	ptr = calloc (nr_elements, size_per_element); 
	if (ptr == NULL) 
	{
		fprintf (stderr, "xcalloc:fatal:out of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (ptr); 
}
