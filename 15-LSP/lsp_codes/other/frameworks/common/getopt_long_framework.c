#include <stdio.h> 
#include <stdlib.h>
#include <stdarg.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 

#define TRUE	1
#define FALSE	0 
typedef int 	flag_t;

void print_usage (void); 
void print_version (void); 

int main (int argc, char *argv[]) 
{
	int ret_gopt, i; 

	struct option opts [] = 
	{
		{"help",    no_argument, 0, 'h'}, 
		{"version", no_argument, 0,  'v'}, 
		{0,	0,	0,	0}
	}; 

	if (argc == 1) 
	{
		print_usage (); 
		exit (EXIT_FAILURE);
	}

	while ((ret_gopt = getopt_long (argc, argv, "hv", opts, &i)) != -1) 
	{
		switch (ret_gopt)
		{
			case 'h': 
				print_usage (); 
				exit (EXIT_SUCCESS); 
				break; 	
			case 'v':
				print_version (); 
				exit (EXIT_SUCCESS); 
				break; 
			default:
				print_usage (); 
				exit (EXIT_FAILURE); 
		}
	}
	

	exit (EXIT_SUCCESS); 
}

void print_usage (void) 
{
	printf ("COMMAND_NAME	[OPTIONS]\n--help/h:prints help\n"); 
	printf ("--version/v:prints version\n"); 
}

void print_version (void) 
{
	printf ("1.0\n");
}
