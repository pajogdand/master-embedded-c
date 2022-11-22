#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h>
#include <unistd.h> 
#include <fcntl.h> 

void *xcalloc (int, int); 
void print_usage (void); 
void print_version (void);
off_t get_curr_offset (char*, int); 

#define STR_EQ		0
#define LONG_OPT	0 
#define TRUE		1
#define FALSE		0
#define BUFFER_SIZE	4096 

char buffer [BUFFER_SIZE]; 


int main (int argc, char *argv[]) 
{
	int ret, i; 
	int len; 
	int name_flag=FALSE, p_flag=FALSE; 
	int fd, rb, wb; 
	off_t off; 
	char *f_name; 

	struct option opts [] = 
	{
		{"help", no_argument, 0, 'h'}, 
		{"version", no_argument, 0, 'v'}, 
		{"name", required_argument, 0, 'n'}, 
		{"p", no_argument, 0, 'p'}, 
		{0, 0, 0, 0}
	};

	if (argc == 1)
	{
		print_usage (); 
		exit (EXIT_SUCCESS);
	}
		
	while ((ret = getopt_long (argc, argv, "hvn:p", opts, &i)) != -1)
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
			case 'n': 
				name_flag = TRUE; 
				len = strlen (optarg); 
				f_name = (char*)xcalloc (1, len+1); 
				strncpy (f_name, optarg, len); 
				break; 
			case 'p':
				p_flag = TRUE; 
				break; 
			default:
				print_usage (); 
				exit (EXIT_FAILURE);
		}
	}	

	printf ("opening file specified to -n/--name...\n"); 
	fd = open (f_name, O_RDWR); 
	if (fd < 0)
	{
		printf ("open:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	printf ("calculating and printing the offset...\n"); 
	off = lseek (fd, 0, SEEK_CUR); 
	if (off == -1) 
	{
		printf ("lseek:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	printf ("current offset = %d\n", (int)off); 

	if (p_flag == TRUE)
	{
		printf ("Reading 4096 bytes using pread from current offset...\n"); 
		rb = pread (fd, buffer, BUFFER_SIZE, SEEK_SET); 
		if (rb == -1) 
		{
			printf ("pread:%s:%s\n", f_name, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
		printf ("Calculating and printing offset after pread...\n"); 
		off = get_curr_offset (f_name, fd);  
		printf ("Current offset (after pread) = %d\n", (int)off); 
	}
	else 
	{
		printf ("Reading 4096 bytes using read from current offset...\n"); 
		rb = read (fd, buffer, BUFFER_SIZE); 
		if (rb == -1) 
		{
			printf ("read:%s:%s\n", f_name, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
		printf ("Calculating and printing offset after read...\n"); 
		off = get_curr_offset (f_name, fd); 			
		printf ("Current offset (after read) = %d\n", (int)off); 
	}

	memset (buffer, 'C', BUFFER_SIZE); 
	if (p_flag == TRUE)
	{
		off = get_curr_offset (f_name,fd); 
		wb = pwrite (fd, buffer, BUFFER_SIZE, off); 
		if (wb != BUFFER_SIZE) 
		{
			fprintf (stderr, "%s:%s\n", f_name, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}	
		printf ("Calculating and printing current offset ...\n"); 
		off = get_curr_offset (f_name, fd); 
		printf ("Offset after pwrite = %d\n", (int)off); 
	}
	else 
	{
		wb = write (fd, buffer, BUFFER_SIZE); 
		if (wb != BUFFER_SIZE) 
		{
			fprintf (stderr, "%s:%s\n", f_name, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}	
		printf ("Calculating and printing current offset ...\n"); 
		off = get_curr_offset (f_name, fd); 
		printf ("Offset after write = %d\n", (int)off); 

	}

	if (close (fd) == -1)
	{
		fprintf (stderr, "%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS);
}

off_t get_curr_offset (char *f_name, int fd) 
{
	off_t off; 

	off = lseek (fd, 0, SEEK_CUR); 
	if (off == -1) 
	{
		fprintf (stderr, "%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	return (off); 
}
void print_usage (void) 
{
	printf ("	[Option]\n--help:Prints help\n--version:Prints version\n"); 
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
		fprintf (stderr, "xcalloc:fatal:ouf of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (ptr);
}
