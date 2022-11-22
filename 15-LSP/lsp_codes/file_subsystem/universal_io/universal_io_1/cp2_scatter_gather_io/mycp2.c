#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/uio.h> 

void perform_copy (char*,char*); 
void process_string_option (char **pf_name, char *optarg, int *p_flag); 
void *xcalloc (int nr_elements, int size_per_element); 
void print_usage (void); 
void print_version (void);

#define STR_EQ		0
#define LONG_OPT	0 
#define TRUE		1
#define FALSE		0
#define BUFFER_SIZE	4096

char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE], buffer3[BUFFER_SIZE], buffer4[BUFFER_SIZE]; 
char *buff_vec[] = {buffer1, buffer2, buffer3, buffer4}; 

int main (int argc, char *argv[]) 
{
	int ret, i; 
	int src_flag=FALSE, dest_flag=FALSE; 
	char *f_src, *f_dest; 

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
		switch (ret)
		{
			case 'h':
				print_usage (); 
				exit (EXIT_SUCCESS); 
				break; 
			case 'v':
				print_version (); 
				exit (EXIT_SUCCESS);
			case 's': 
				process_string_option (&f_src, optarg, &src_flag);  
				break; 
			case 'd': 
				process_string_option (&f_dest, optarg, &dest_flag); 
				break; 
			default:
				print_usage (); 
				exit (EXIT_FAILURE);
		}
	}	
	
	if (! (src_flag == TRUE && dest_flag == TRUE))
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}
	
	perform_copy (f_src, f_dest); 

	exit (EXIT_SUCCESS);
}

void perform_copy (char *f_src, char *f_dest)
{
	int fd_s, fd_d; 
	int i, rb, wb; 
	int q, r; 
	static struct iovec io[4];
	
	for (i=0; i < 4; i++) 
	{
		io[i].iov_base = buff_vec [i]; 
		io[i].iov_len  = BUFFER_SIZE; 
	}

	fd_s = open (f_src, O_RDONLY); 
	if (fd_s < 0) 
	{
		fprintf (stderr, "%s:%s\n", f_src, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	fd_d = open (f_dest, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
	if (fd_d < 0) 
	{
		fprintf (stderr, "%s:%s\n", f_dest, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}


	while ((rb = readv (fd_s, io, 4)) == 4 * BUFFER_SIZE)
	{
		wb = writev (fd_d, io, 4); 
		if (wb != 4 * BUFFER_SIZE)
		{
			fprintf (stderr, "%s:%s\n", f_dest, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
	}

	if (rb == -1) 
	{
			fprintf (stderr, "%s:%s\n", f_src, strerror (errno)); 
			exit (EXIT_FAILURE); 
	}

	if (rb > 0 && rb < 4*BUFFER_SIZE)
	{
		q = rb / BUFFER_SIZE; 
		r = rb % BUFFER_SIZE; 	

		wb = writev (fd_d, io, q); 
		if (wb != q * BUFFER_SIZE)
		{
			fprintf (stderr, "%s:%s\n", f_dest, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}

		/* q+1st buffer is at index q */ 
		wb = write (fd_d, io[q].iov_base, r); 
		if (wb != r) 
		{
			fprintf (stderr, "%s:%s\n", f_dest, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
	}

	if (close (fd_s) == -1) 
	{
		fprintf (stderr, "%s:%s\n", f_dest, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	if (close (fd_d) == -1) 
	{
		fprintf (stderr, "%s:%s\n", f_src, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
}

void process_string_option (char **pf_name, char *optarg, int *p_flag) 
{
	int len  = strlen (optarg); 
	*pf_name = (char*) xcalloc (1, len+1); 
	strncpy (*pf_name, optarg, len); 
	*p_flag = TRUE; 
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

void print_usage (void) 
{
	printf ("	[Option]\n--help:Prints help\n--version:Prints version\n"); 
}

void print_version (void) 
{
	printf ("0.1\n"); 
}
