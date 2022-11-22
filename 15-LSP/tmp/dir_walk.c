#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h>
#include <unistd.h>  
#include <fcntl.h> 
#include <dirent.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

#define TRUE    		1 
#define FALSE   		0
#define SUCCESS 		1 
#define FAILURE 		0 

typedef int flag_t; 
typedef int result_t; 
typedef int len_t; 
typedef int bool; 

void 		*xcalloc		(int nr_element, int size_per_element); 
void 		print_usage 	(void);
void 		print_version 	(void); 
result_t 	walk 			(char *path); 
bool 		is_dir 			(const char *path); 
char 		*join 			(const char *dir_name, const char *base_name); 

int main (int argc, char *argv[])
{
	int 		ret; 
	char 		*path; 
	flag_t 		n_flag=FALSE; 
	result_t 	rs; 

	while ((ret = getopt (argc, argv, "hvn:")) != -1)
	{
		switch ((char)ret)
		{
			case 'h': 
				print_usage (); 
				exit (EXIT_SUCCESS); 
			case 'v': 
				print_version (); 
				exit (EXIT_SUCCESS); 
			case 'n': 
				n_flag = TRUE; 
				path = optarg; 
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

	if (!is_dir (path))
	{
		printf ("%s\n", path); 
		return (SUCCESS); 
	}

	rs = walk (path); 

	return (EXIT_SUCCESS); 
}

result_t walk (char *path)
{
	DIR 			*dirp; 
	struct dirent 	*dentry; 
	char 			*next_path; 
	int 			i; 

	dirp = opendir (path); 
	printf ("%s\n", path); 

	while ((dentry = readdir (dirp)) != NULL)
	{
		if ((( strncmp (dentry->d_name, ".", 1) == 0) && 
			 ( strlen (dentry->d_name) == 1)) || 
			   strncmp (dentry->d_name, "..", 2) == 0 &&
			   strlen(dentry->d_name) == 2)
				continue; 

		next_path = join (path, dentry->d_name); 

		if (is_dir (next_path))
		{
			walk (next_path); 

		}
		else
		{
			printf ("%s\n", next_path); 
		}
		
		free (next_path); 
		next_path = NULL; 
	}

	closedir (dirp);
	dirp = NULL; 

	return (SUCCESS);
}

bool is_dir (const char *path)
{
	static struct stat stat_buffer; 
	int ret; 

	memset (&stat_buffer, (int)'\0', sizeof (struct stat));
	
	ret = stat (path, &stat_buffer); 
	if (ret == -1)
	{
		fprintf (stderr, "stat:%s:%s\n", path, strerror (errno)); 
		return (FALSE);
		//exit (EXIT_FAILURE); 
	}

	return (S_ISDIR (stat_buffer.st_mode) ? TRUE : FALSE); 
}

char *join (const char *dir_name, const char *base_name)
{
	char *rs_path; 
	len_t len1, len2; 
	int i; 
	
	len1 = strlen (dir_name); 
	len2 = strlen (base_name); 

	rs_path = (char*) xcalloc (len1+len2+2, sizeof (char)); 
	
	for (i=0; i < len1; i++)
	{
		rs_path[i] = dir_name[i]; 
	}

	rs_path[i] = '/'; 

	for (i=0; i < len2; i++)
	{
		rs_path[len1+1+i] = base_name[i];
	}

	return (rs_path);
}

void *xcalloc (int nr_element, int size_per_element)
{
	void *ptr; 

	ptr = calloc (nr_element, size_per_element); 
	if (!ptr)
	{
		fprintf (stderr, "calloc:fatal:out of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (ptr); 
}

void print_usage (void)
{
	static char *help_str = "dir_walk -n dir_name"; 
	puts (help_str);
}

void print_version (void)
{
	puts ("0.1"); 
}