#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 

#define TRUE  1 
#define FALSE 0 

typedef int flag_t; 

void print_usage   (void); 
void print_version (void); 

int main (int argc, char *argv[]) 
{
	pid_t  pid; 
	int    fd, ret, i; 
	flag_t r_flag = FALSE; 
	char   *redirect_file = NULL; 
	static char *args[] = {"gcc", "-v", "-o", "hello", "hello.c", (char*)0}; 

	static const struct option opts [] = 
	{
		{"help",     no_argument,       0, 'h'}, 
		{"version",  no_argument, 	0, 'v'}, 
		{"redirect", required_argument, 0, 'r'}, 
		{0,	     0,			0,  0 } 
	}; 

	if (argc == 1) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	while ((ret = getopt_long (argc, argv, "hvr:", opts, &i)) != -1)
	{
		switch ((char)ret)
		{
			case 'h': 
				print_usage (); 
				exit(EXIT_SUCCESS); 
			case 'v': 
				print_version (); 
				exit (EXIT_SUCCESS); 
			case 'r':
				r_flag = TRUE; 
				redirect_file = optarg; 
				break; 
			default:
				print_usage (); 
				exit (EXIT_FAILURE); 
		}
	}

	if (!r_flag)
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	pid = fork (); 
	if ((int)pid == -1) 
	{
		fprintf (stderr, "fork:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	} 

	if ((int)pid == 0) 
	{
		fd = open (redirect_file, O_RDWR | O_CREAT | O_TRUNC, 
			   S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
		if (fd == -1) 
		{
			fprintf (stderr, "open:%s:%s\n", redirect_file, strerror (errno)); 
			exit (EXIT_FAILURE); 
		}

		ret = dup2 (fd, STDERR_FILENO); 
		if (ret == -1) 
		{
			fprintf (stderr, "dup2:%s\n", strerror (errno)); 
			exit (EXIT_FAILURE); 
		}	

		execvp (args[0], args); 
		fprintf (stderr, "exec:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 

	}
	else
	{
		wait (&ret); 
	}

	return (EXIT_SUCCESS); 
}

void print_usage (void) 
{
	static const char *usage = "redirect -h : for help\n-v : for version\
\n-r <redirect file>"; 
	puts (usage); 
}

void print_version (void) 
{
	puts("0.1"); 
}
