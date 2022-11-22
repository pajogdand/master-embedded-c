#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <getopt.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <ctype.h> 
#include <time.h>

void *xcalloc (int nr_elements, int size_per_element); 
void print_usage (void); 
void print_version (void); 

unsigned int get_file_size_in_bytes (char *f_name); 
void genfile (char *f_name, unsigned int f_size); 

#define TRUE		1
#define FALSE		0 
#define LONG_OPTION	0
#define STR_EQ		0
#define START_CAP	65
#define START_SMALL	97
#define START_DIGIT	48
#define NR_CAP		26
#define NR_SMALL	26
#define NR_DIGIT	10
#define NR_SPECIAL	31
#define BUFFER_SIZE	4096 
#define MAX_SIZE	2147483647

char buffer [BUFFER_SIZE]; 

int main (int argc, char *argv[]) 
{
	int ret, i; 
	int len_arg; 
	int size_flag=FALSE, name_flag=FALSE; 
	unsigned int f_size; 
	char *f_name="t_file.txt", *size_string; 

	static struct option opts [] = 
	{
		{"help", no_argument, 0, 'h'}, 
		{"version", no_argument, 0, 'v'}, 
		{"size", required_argument, 0, 's'}, 
		{"name", required_argument, 0, 'n'}, 
		{0, 0, 0, 0}
	}; 
	
	if (argc == 1) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	while ((ret = getopt_long (argc, argv, "hvs:n:", opts, &i)) != -1) 
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
				break; 
			case 's': 
				size_flag = TRUE; 
				len_arg = strlen (optarg); 
				size_string = (char*)xcalloc (1, len_arg+1); 
				strncpy (size_string, optarg, len_arg); 	
				break; 
			case 'n': 
				name_flag = TRUE; 
				len_arg = strlen (optarg); 
				f_name = (char*)xcalloc (1, len_arg+1); 
				strncpy (f_name, optarg, len_arg); 
				break; 
			default: 
				print_usage (); 
				exit (EXIT_FAILURE); 
		}
	
	}
	
	if (size_flag == FALSE) 
	{
		print_usage ();
		exit (EXIT_FAILURE); 
	}

	f_size = get_file_size_in_bytes (size_string); 
	genfile (f_name, f_size); 

	exit (EXIT_SUCCESS); 
}

void genfile (char *f_name, unsigned int f_size) 
{
	int fd, wb; 
	int i, j; 
	int iter = f_size / BUFFER_SIZE; 
	int remainder = f_size % BUFFER_SIZE; 

	static char special_char [] = 
	{'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', 
	'\n', '[', ']', '{', '}', ':', '\t', ';', ',', '<', '.', '>', '?','/', '\0'}; 
	
	srand (time (0)); 

	fd = open (f_name, O_RDWR | O_CREAT | O_TRUNC, 
		   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
	if (fd < 0) 
	{
		fprintf (stderr, "open:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	for (i=0; i < iter; i++) 
	{
		for (j=0; j < BUFFER_SIZE; j++) 
		{
			switch (rand () % 4) 
			{
				case 0:
					buffer [j] = (char)(START_CAP + (rand () % NR_CAP)); 
					break; 
				case 1:
					buffer [j] = (char)(START_DIGIT + (rand () % NR_DIGIT)); 
					break; 
				case 2: 
					buffer [j] = (char)(START_SMALL + (rand () % NR_SMALL)); 
					break; 
				case 3: 
					buffer [j] = special_char [rand () % NR_SPECIAL]; 
					break; 		
			}
		}

		wb = write (fd, buffer, BUFFER_SIZE); 
		if (wb != BUFFER_SIZE) 
		{
			fprintf (stderr, "write:%s:%s\n", f_name, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}
		memset (buffer, '\0', BUFFER_SIZE); 
	}
	
	for (j=0; j < remainder; j++) 
	{
		switch (rand () % 4) 
		{
			case 0:
				buffer [j] = (char)(START_CAP + (rand () % NR_CAP)); 
				break; 
			case 1:
				buffer [j] = (char)(START_DIGIT + (rand () % NR_DIGIT)); 
				break; 
			case 2: 
				buffer [j] = (char)(START_SMALL + (rand () % NR_SMALL)); 
				break; 
			case 3: 
				buffer [j] = special_char [rand () % NR_SPECIAL]; 
				break; 		
		}
	}

	wb = write (fd, buffer, remainder); 
	if (wb != remainder) 
	{
		fprintf (stderr, "write:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	if (close (fd) == -1) 
	{
		fprintf (stderr, "close:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE);  
	}
}

unsigned int get_file_size_in_bytes (char *size_string) 
{
	int len_str; 
	int i; 
	char *p=size_string, *prefix_string; 
	unsigned int f_size=0, prefix_num; 
	
	len_str = strlen (size_string); 
	for (i=0; i < len_str-1; i++) 
	{
		if (!isdigit (*(p+i)))
		{
			print_usage (); 
			exit (EXIT_FAILURE); 
		}
	}

	if (isdigit(*(p+len_str-1)))
	{
		f_size = atol (size_string); 
		if (f_size > (unsigned int)MAX_SIZE+1) 
		{
			print_usage (); 
			exit (EXIT_FAILURE); 
		}
		else if (f_size == (unsigned int)MAX_SIZE+1)
		{
			printf ("Clipping 2G size to 2G-1\n"); 
			f_size = MAX_SIZE; 
		}

		return (f_size); 
	}
	
	prefix_string = (char*) xcalloc (1, len_str); 
	strncpy (prefix_string, size_string, len_str-1); 
	prefix_num = atol (prefix_string); 

	switch (*(p+len_str-1))
	{
		case 'K':
		case 'k':
			f_size = (unsigned int)prefix_num * 1024; 
			break; 
		case 'M':
		case 'm': 
			f_size = (unsigned int)prefix_num * 1024 * 1024; 
			break; 
		case 'G':
		case 'g': 
			f_size = (unsigned int)prefix_num * 1024 * 1024 * 1024; 	
			break; 
	}

	free (prefix_string); 

	if (f_size > (unsigned int)MAX_SIZE + 1)
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}
	else if (f_size == (unsigned int)MAX_SIZE + 1) 
	{
		printf ("Clipping 2Gib file to 2Gib-1 bytes\n"); 
		f_size = (unsigned int) MAX_SIZE; 
	}

	return (f_size); 
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
	printf ("./genfile --name=/n file_name --size=/-s size[suffix]\n"); 
	printf ("suffix can be K/k(Kib), M/m(Mib) or G/g(Gib), no suffix for specifying size in bytes\n"); 
	printf ("File size cannot exceed 1G\n"); 
}

void print_version (void) 
{
	printf ("0.1\n"); 
}
