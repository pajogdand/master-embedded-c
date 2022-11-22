#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 
#include <unistd.h> 
#include <fcntl.h> 

void print_usage (void); 
void print_version (void);
void *xcalloc (int, int); 
void perform_copy (char*, char*); 

#define STR_EQ		0
#define LONG_OPT	0 
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE	4096
#endif 

char buffer [BUFFER_SIZE]; 

int main (int argc, char *argv[]) 
{
	int ret, i; 
	int len_s, len_d; 
	char *f_src, *f_dest; 
	int flag_src=0, flag_dest=0;
	struct option opts [] = 
	{
		{"help", no_argument, 0, 'h'}, 
		{"version", no_argument, 0, 'v'}, 
		{"src", required_argument, 0, 's'}, 
		{"dest", required_argument, 0, 'd'}, 
		{0, 0, 0, 0}
	};

	if (argc == 1)
	{
		print_usage (); 
		exit (EXIT_SUCCESS);
	}
		
	while ((ret = getopt_long (argc, argv, "hvs:d:", opts, &i)) != -1)
	{
		switch ((char)ret)
		{	

			case 'h':
				print_usage (); 
				exit (EXIT_SUCCESS); 
				break; 
			case 'v':
				print_version (); 
				exit (EXIT_SUCCESS);
			case 's':
				flag_src = 1; 
				len_s = strlen (optarg); 
				f_src = (char*)xcalloc (1,len_s+1); 
				strncpy (f_src, optarg, len_s);
				break; 
			case 'd':
				flag_dest = 1; 
				len_d = strlen (optarg); 
				f_dest = (char*)xcalloc (1, len_d+1); 
				strncpy (f_dest, optarg, len_d); 
				break; 
			default:
				print_usage (); 
				exit (EXIT_FAILURE);
		}
	}	
	
	if (!(flag_src == 1 && flag_dest == 1))
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}
	perform_copy (f_src, f_dest); 

	exit (EXIT_SUCCESS);
}

void print_usage (void) 
{
	printf ("./mycp	--src=/-s src_file_name --dest=/-d dest_file_name\n--help:Prints help\n--version:Prints version\n"); 
}

void print_version (void) 
{
	printf ("0.1\n"); 
}

void *xcalloc (int nr, int spe)
{
	void *ptr; 

	ptr = calloc (nr, spe); 
	if (ptr == NULL) 
	{
		fprintf (stderr, "xcalloc:fatal:out of memory\n");
		exit (EXIT_FAILURE); 
	}
	
	return (ptr); 
}

void perform_copy (char *f_src, char *f_dest) 
{
	int fd_s, fd_d; 
	int rb, wb; 
	fd_s = open (f_src, O_RDONLY); 
	if (fd_s < 0)
	{
		fprintf (stderr, "%s:%s\n", f_src, strerror (errno));
		exit (EXIT_FAILURE); 
	}
	fd_d = open (f_dest, O_RDWR | O_TRUNC | O_CREAT, 
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
	if (fd_d < 0) 
	{
		fprintf (stderr, "%s:%s\n", f_dest, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	while ((rb = read (fd_s, buffer, BUFFER_SIZE)) > 0)
	{
		if (rb == -1) 
		{
			fprintf (stderr, "%s:%s\n", f_src, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}

		wb = write (fd_d, buffer, rb); 
		if (rb != wb) 
		{
			fprintf (stderr,"%s:%s\n", f_dest, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
	}	
	if (close (fd_s) == -1) 
	{
		fprintf (stderr, "%s:%s\n", f_src, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	if (close (fd_d) == -1) 
	{
		fprintf (stderr, "%s:%s\n", f_dest, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
}
