#include <stdio.h> 
#include <stdlib.h>
#include <stdarg.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 
#include <unistd.h> 
#include <sys/mount.h> 
#define TRUE	1
#define FALSE	0 
typedef int 	flag_t;

void xmount (const char *source, const char *target, const char *fs_type, 
	     unsigned long mount_flags, void *data); 
void dup_string (char **target, char *source); 
void print_usage (void); 
void print_version (void); 
void *xcalloc (int nr_elements, int size_per_element); 
void xfree (void *ptr); 

int main (int argc, char *argv[]) 
{
	int ret_gopt, i, len; 
	flag_t src_flag, target_flag, f_flag, data_flag, type_flag;  
	char *src, *target, *fs_type, *data; 
	unsigned long mount_flags; 

	src_flag = target_flag = f_flag = data_flag = type_flag = FALSE; 
	src = target = fs_type = data = NULL; 
	mount_flags = 0; 

	struct option opts [] = 
	{
		{"source",  required_argument, 0, 's'}, 
		{"target",  required_argument, 0, 't'}, 
		{"type",    required_argument, 0, 'T'}, 
		{"flag",    required_argument, 0, 'f'}, 
		{"data",    required_argument, 0, 'd'},
		{"help",    no_argument,       0, 'h'}, 
		{"version", no_argument,       0, 'v'}, 
		{0,	    0,	               0,  0 }
	}; 

	while ((ret_gopt = getopt_long (argc, argv, "hvs:t:T:f:d:", opts, &i)) != -1) 
	{
		switch (ret_gopt)
		{
			case 's':
				src_flag = TRUE; 
				dup_string (&src, optarg); 
				break; 
			case 't':
				target_flag = TRUE; 
				dup_string (&target, optarg); 
				break; 
			case 'T': 
				type_flag = TRUE; 
				dup_string (&fs_type, optarg); 
				break; 
			case 'f': 
				f_flag = TRUE; 
				len = strlen (optarg); 
				for (i=0; i < len; i++) 
				{
					switch (optarg[i])
					{
						case 'b': 
							mount_flags |= MS_BIND;
							break; 
						case 'd': 
							mount_flags |= MS_DIRSYNC;
							break;
						case 'l': 
							mount_flags |= MS_MANDLOCK;
							break;
						case 'm': 
							mount_flags |= MS_MOVE;
							break;
						case 'A': 
							mount_flags |= MS_NOATIME;
							break;
						case 'V': 
							mount_flags |= MS_NODEV;
							break; 
						case 'D': 
							mount_flags |= MS_NODIRATIME;
							break; 
						case 'E': 
							mount_flags |= MS_NOEXEC;
							break; 
						case 'S': 
							mount_flags |= MS_NOSUID;
							break;
						case 'r': 
							mount_flags |= MS_RDONLY;
							break;
						case 'c': 
							mount_flags |= MS_REC;
							break; 
						case 'R': 
							mount_flags |= MS_REMOUNT;
							break; 
						case 's': 
						       mount_flags |= MS_SYNCHRONOUS;
						        break; 
						default:
							print_usage (); 
							exit (EXIT_FAILURE); 	
					}
				}	
				break; 
			case 'd': 
				data_flag = TRUE; 
				dup_string (&data, optarg); 
				break; 
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
	
	if (! (src_flag == TRUE && target_flag == TRUE && type_flag == TRUE))
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}
	
	xmount (src, target, fs_type, mount_flags, data); 
	xfree (src); 
	xfree (target); 
	xfree (fs_type); 
	xfree (data); 
	exit (EXIT_SUCCESS); 
}

void xmount (const char *source, const char *target, const char *fs_type, 
	     unsigned long mount_flags, void *data) 
{
	int sys_ret; 

	sys_ret = mount (source, target, fs_type, mount_flags, data); 
	if (sys_ret == -1) 
	{
		fprintf (stderr, "mount:%s:%s:%s\n", 
			 source, target, strerror (errno)); 
		exit (EXIT_FAILURE); 

	}
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

void dup_string (char **target, char *source)
{
	int len; 
	len = strlen (source); 
	*target = (char*) xcalloc (1, len+1); 
	strncpy (*target, source, len); 
}

void *xcalloc (int nr_elements, int size_per_element) 
{
	void *ptr; 

	ptr = calloc (nr_elements, size_per_element); 
	if (ptr == NULL) 
	{
		fprintf (stderr, "xcalloc:fatal:out of memory\n"); 
		exit (EXIT_SUCCESS); 
	}

	return (ptr); 
}

void xfree (void *ptr) 
{
	if (ptr != NULL) 
	{
		free (ptr); 
	}
}
