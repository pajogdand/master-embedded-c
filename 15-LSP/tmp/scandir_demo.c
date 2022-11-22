#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <errno.h> 
#include <getopt.h> 
#include <dirent.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

#define TRUE  1  
#define FALSE 0

void print_usage (void); 
void print_version (void); 
void *xcalloc (int, int); 
int c_filter (const struct dirent *); 
int len_comparator (const struct dirent **pp_dentry1, 
					const struct dirent **pp_dentry2); 

typedef int flag_t; 

int main (int argc, char *argv[]) 
{
	int ret, i; 
	char *dir_name; 
	struct stat *st_ptr; 
	flag_t n_flag=FALSE; 
	struct dirent **namelist; 

	while ((ret = getopt (argc, argv, "hvn:")) != -1) 
	{
		switch ((char)ret)
		{
			case 'h': 
				print_usage (); 
				exit (EXIT_FAILURE); 
			case 'v': 
				print_version (); 
				exit (EXIT_FAILURE); 
			case 'n': 
				n_flag = TRUE; 
				dir_name = optarg; 
				st_ptr = (struct stat*) xcalloc (1, sizeof (struct stat)); 
				ret = stat (dir_name, st_ptr); 
				if (ret == -1) 
				{
					fprintf (stderr, "stat:%s:%s\n", dir_name, 
							 strerror (errno)); 
					exit (EXIT_FAILURE); 
				}
				if (!S_ISDIR(st_ptr->st_mode))
				{
					print_usage (); 
					free(st_ptr); 
					st_ptr = NULL; 
					exit (EXIT_FAILURE); 
				}
				free (st_ptr); 
				break; 
			default:
				print_usage (); 
				exit (EXIT_FAILURE); 
		}
	}

	if (!n_flag) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	ret = scandir (dir_name, &namelist, c_filter, len_comparator); 
	if (ret == -1) 
	{
		fprintf (stderr, "scandir:Error in %s\n", dir_name); 
		exit (EXIT_FAILURE); 
	}

	for (i=0; namelist[i]; i++) 
	{
		puts (namelist[i]->d_name); 	
	}

	for (i=0; namelist[i]; i++) 
	{
		free (namelist[i]); 
	}

	free (namelist); 
	namelist = NULL; 

	exit (EXIT_SUCCESS); 
}

void *xcalloc (int nr_elements, int size_per_element) 
{
	void *ptr; 

	ptr = calloc (nr_elements, size_per_element); 

	if (!ptr) 
	{
		fprintf (stderr, "calloc:out of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (ptr); 
}

int c_filter (const struct dirent *dentry_ptr)
{
	if (strncmp (".c", &dentry_ptr->d_name[strlen (dentry_ptr->d_name) - 2]
				 , 2) == 0)
		return (TRUE); 
	else
		return (FALSE); 
}

int len_comparator (const struct dirent **pp_dentry1, 
					const struct dirent **pp_dentry2) 
{
	int len1=strlen ((*pp_dentry1)->d_name), len2= strlen ((*pp_dentry2)->d_name); 

	if (len1 < len2)
		return (-1); 
	else if (len1 > len2) 
		return (1); 
	else
		return (0); 
}

void print_usage (void) 
{
	puts ("command dir_name"); 
}

void print_version (void) 
{
	puts ("0.1"); 
}


