#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <getopt.h> 
#include <errno.h> 
#include <unistd.h> 
#include <fcntl.h> 

void *xcalloc (int nr_elements, int size_per_element); 
void print_usage (void); 
void print_version (void);

#define STR_EQ		0
#define LONG_OPT	0 
#define TRUE		1
#define FALSE		0 
#define BUFFER_SIZE	32

char buffer [BUFFER_SIZE]; 

int main (int argc, char *argv[]) 
{
	int ret, i; 
	int len, wb; 
	int name_flag = FALSE; 
	int fd; 
	off_t off; 
	char *f_name; 

	struct option opts [] = 
	{
		{"help", no_argument, 0, 0}, 
		{"version", no_argument, 0, 0}, 
		{"name", required_argument, 0, 0}, 
		{0, 0, 0, 0}
	};

	if (argc == 1)
	{
		print_usage (); 
		exit (EXIT_SUCCESS);
	}
		
	while ((ret = getopt_long (argc, argv, "hvn:", opts, &i)) != -1)
	{
		switch (ret)
		{
			case LONG_OPT:				
				if (strncmp (opts[i].name, "help", strlen ("help")) == STR_EQ)
				{
					print_usage (); 
					exit (EXIT_SUCCESS); 
				}
				if (strncmp (opts[i].name, "version", strlen ("version")) == STR_EQ)
				{
					print_version (); 
					exit (EXIT_SUCCESS);
				}
				if (strncmp (opts[i].name, "name", strlen ("name")) == STR_EQ)
				{
					name_flag = TRUE; 
					len = strlen (optarg); 
					f_name = (char*)xcalloc (1, len+1); 
					strncpy (f_name, optarg, len); 
				}
				break; 			
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
			default:
				print_usage (); 
				exit (EXIT_FAILURE);
		}
	}	

	fd = open (f_name, O_RDWR | O_APPEND); 
	if (fd < 0) 
	{
		printf ("open:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	sleep (3); 
	memset (buffer, 'A', BUFFER_SIZE); 
	wb = write (fd, buffer, BUFFER_SIZE); 
	if (wb != BUFFER_SIZE) 
	{
		printf ("write:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	
	if (close (fd) == -1) 
	{
		printf ("close:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS);
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
		fprintf (stderr, "xcalloc:fatal:out of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (ptr);
}
