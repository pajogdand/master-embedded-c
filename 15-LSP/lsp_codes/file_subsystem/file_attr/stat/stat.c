#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <grp.h> 
#include <sys/stat.h> 
#include <sys/statvfs.h> 

#define TRUE 1
#define FALSE 0 
#define ST_OCTAL_PERM_FLAG	0x000001FF
#define LNK_BUFFER_SIZE		1024
typedef int flag_t; 

void print_usage (void); 
void print_version (void); 
void print_vfs_info (const struct statvfs *p_statvfs, char *format, flag_t t_flag); 
void print_stat_info (const struct stat *p_stat, char *f_name, char *format, flag_t t_flag); 
struct statvfs *x_statvfs (const char *f_name); 
struct stat    *x_stat (const char *f_name, flag_t L_flag); 
void *xcalloc (int nr_elements, int size_per_element); 

int main (int argc, char *argv[]) 
{
	int ret, i; 
	char *f_name, *format=NULL; 
	flag_t n_flag=FALSE, L_flag=FALSE, f_flag=FALSE, t_flag=FALSE;  
	struct stat *p_stat; 
	struct statvfs *p_statvfs; 
	
	static const struct option op [] = 
	{
		{"help", no_argument, 0, 'h'}, 
		{"version", no_argument, 0, 'v'}, 
		{"name", required_argument, 0, 'n'}, 
		{"dereference", no_argument, 0, 'L'}, 
		{"file-system", no_argument, 0, 'f'}, 
		{"format", required_argument, 0, 'c'}, 
		{"terse", no_argument, 0, 't'},
		{0, 0, 0, 0}
	}; 

	if (argc == 1) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	while ((ret = getopt_long (argc, argv, "hvLfn:c:", op, &i)) != -1)
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
					break; 
			case 'n':
					n_flag = TRUE; 
					i = strlen (optarg); 
					f_name = xcalloc (1, i+1); 
					strncpy (f_name, optarg, i); 		
					break; 
			case 'L': 
					L_flag = TRUE; 
					break; 
			case 'f': 
					f_flag = TRUE; 
					break; 
			case 't':
					t_flag = TRUE; 
					break; 
			case 'c':
					i = strlen (optarg); 
					format = xcalloc (1, i+1); 
					strncpy (format, optarg, i); 
					break; 
			default: 
					print_usage (); 
					exit (EXIT_FAILURE); 
		}
	
	}	
	
	if (n_flag != TRUE) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}
	
	if (f_flag == TRUE)
	{
		p_statvfs = x_statvfs (f_name); 	
		print_vfs_info (p_statvfs, format, t_flag); 
	}
	else 
	{
		p_stat = x_stat (f_name, L_flag); 	
		print_stat_info (p_stat, f_name, format, t_flag); 
	}

	free (f_name); 
	free (format); 

	exit (EXIT_SUCCESS); 
}

void print_vfs_info (const struct statvfs *p_statvfs, char *format, flag_t t_flag) 
{
	if (format != NULL) 
	{
		if (*format != '%' || strlen (format) != 2) 
		{
			puts ("-c:Bad format specifier"); 
			exit (EXIT_FAILURE); 
		}		

		switch (*(format+1))
		{
			case 'a':

				break; 
			case 'b':

				break; 
			case 'c':

				break; 
			case 'f':

				break; 
			case 'i':

				break; 
			case 'l':

				break; 
			case 'n':

				break; 
			case 's':

				break; 
			case 'S':

				break; 
			case 't':

				break; 
			case 'T':

				break; 
			default:
				puts ("-c:Bad format option"); 
				exit (EXIT_FAILURE); 
		}
	
	}
	else
	{
		if (t_flag == TRUE) 
		{
			/* print terse statvfs info */ 	
		}

		/* print full statvfs info */ 


	}	
}

void print_stat_info (const struct stat *p_stat, char *f_name, char *format, flag_t t_flag) 
{
	typedef enum {REGULAR, DIRECTORY, CHARACTER_SPECIAL, BLOCK_SPECIAL, FIFO, LINK, SOCKET} FILE_TYPE;
	static const char *f_type_names [] = {"regular f", "directory", "character special file", 
					       "block special file", "fifo", "symbolic Link", "socket"}; 
	static char perm_string [] = "----------";
	static char lnk_buffer [LNK_BUFFER_SIZE]; 
	struct group *gr; 
	FILE_TYPE f_type; 
	flag_t uid_flag=FALSE, gid_flag=FALSE, vtx_flag=FALSE; 
	ssize_t size; 

	switch (p_stat->st_mode & S_IFMT) 
	{
		case S_IFREG:
			f_type = REGULAR; 
			break; 
		case S_IFDIR:
			f_type = DIRECTORY; 
			perm_string[0] = 'd'; 
			break; 
		case S_IFCHR:
			f_type = CHARACTER_SPECIAL; 
			perm_string[0] = 'c'; 
			break; 
		case S_IFBLK:
			f_type = BLOCK_SPECIAL; 
			perm_string[0] = 'b'; 
			break; 
		case S_IFIFO:
			f_type = FIFO; 
			perm_string[0] = 'p'; 
			break; 
		case S_IFLNK:
			f_type = LINK; 
			perm_string[0] = 'l'; 
			break; 
		case S_IFSOCK:
			f_type = SOCKET; 
			perm_string[0] = 's'; 
		default:
			puts ("Invalid file type"); 
			exit (EXIT_FAILURE); 
	}

	if (p_stat->st_mode & S_IRUSR) 
	{
		perm_string[1] = 'r'; 	
	}

	if (p_stat->st_mode & S_IWUSR) 
	{
		perm_string[2] = 'w'; 
	}

	if (p_stat->st_mode & S_IXOTH) 
	{
		perm_string[3] = 'x'; 
	}

	if (p_stat->st_mode & S_IRGRP) 
	{
		perm_string[4] = 'r'; 
	}

	if (p_stat->st_mode & S_IWGRP) 
	{
		perm_string[5] = 'w'; 
	}

	if (p_stat->st_mode & S_IXGRP) 
	{
		perm_string[6] = 'x'; 
	}

	if (p_stat->st_mode & S_IROTH) 
	{
		perm_string[7] = 'r'; 
	}

	if (p_stat->st_mode & S_IWOTH) 
	{
		perm_string[8] = 'w'; 
	}

	if (p_stat->st_mode & S_IXOTH) 
	{
		perm_string[9] = 'x'; 
	}

	if (p_stat->st_mode & S_ISUID) 
	{
		perm_string[3] = 's'; 
	}

	if (p_stat->st_mode  & S_ISGID)
	{
		perm_string[6] = 's'; 		
	}

	if (p_stat->st_mode & S_ISVTX == S_ISVTX)
	{
	
	}

	
	if (format != NULL) 
	{
		if (*format != '%' || strlen (format) != 2) 
		{
			puts ("-c:Bad format specifier"); 
			exit (EXIT_FAILURE); 
		}
		
		switch (*(format+1)) 
		{
			case 'a':
				fprintf (stdout, "%o\n", (unsigned int) p_stat->st_mode & ST_OCTAL_PERM_FLAG); 	
				return; 
			case 'A':
				fprintf (stdout, "%s\n", perm_string); 
				return ; 
			case 'b':
				fprintf (stdout, "%u\n", (unsigned int)p_stat->st_blocks); 
				return; 
			case 'B':
				fprintf (stdout, "%u\n", (unsigned int)512); 
				return; 
			case 'd':
				fprintf (stdout, "%u\n", (unsigned int)p_stat->st_dev); 
				return; 
			case 'D':
				fprintf (stdout, "%x\n", (unsigned int)p_stat->st_dev); 
				return; 
			case 'f':
				fprintf (stdout, "%x\n", (unsigned int)p_stat->st_mode); 
				return; 
			case 'F':
				fprintf (stdout, "%s\n", f_type_names [f_type]); 
				return; 
			case 'g':
				fprintf (stdout, "%u\n", (unsigned int)p_stat->st_gid); 
				return; 
			case 'G':
				gr = getgrgid (p_stat->st_gid); 
				fprintf (stdout, "%s\n", gr->gr_name); 
				return; 
			case 'h':
				fprintf (stdout, "%u\n", (unsigned int)p_stat->st_nlink); 
				return; 
			case 'i':
				fprintf (stdout, "%u\n", (unsigned int)p_stat->st_ino); 
				return; 
			case 'n':
				fprintf (stdout, "%s\n", f_name); 
				return; 
			case 'N':
				if (f_type == LINK)
				{
					size = readlink (f_name, lnk_buffer, LNK_BUFFER_SIZE); 
					if (size == -1) 
					{
						fprintf (stderr, "readlink:%s:%s\n", f_name, strerror (errno)); 
						exit (EXIT_FAILURE); 
					}
					fprintf (stdout, "\'%s\' -> \'%s\'\n", f_name, lnk_buffer); 
				}
				else
				{
					fprintf (stdout, "\'%s\'\n", f_name); 
				}
				return; 
			case 'o':
				fprintf (stdout, "%u\n", (unsigned int)p_stat->st_blksize); 
				return; 
			case 's':
				fprintf (stdout, "%u\n", (unsigned int)p_stat->st_size); 
					return; 
			case 't':
				fprintf (stdout, "%u\n", (unsigned int)p_stat->st_rdev); 	
				break; 
			case 'T':

				break; 
			case 'u':

				break; 
			case 'U':

				break; 
			case 'x':

				break; 
			case 'X':

				break; 
			case 'y':

				break; 
			case 'Y':

				break; 
			case 'z':

				break; 
			case 'Z':

				break; 
			default:
				puts ("-c:Bad format option"); 
				exit (EXIT_FAILURE); 
		}
	}
	else
	{
		if (t_flag == TRUE)
		{
		
		}
		else
		{
		
		}
	}	
}

struct statvfs *x_statvfs (const char *f_name) 
{
	int ret; 
	struct statvfs *p_statvfs; 

	p_statvfs = (struct statvfs*) xcalloc (1, sizeof (struct statvfs)); 

	ret = statvfs (f_name, p_statvfs); 
	if (ret == -1) 
	{
		fprintf (stderr, "statvfs:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}
	
	return (p_statvfs); 	
}

struct stat *x_stat (const char *f_name, flag_t L_flag) 
{
	int ret; 
	struct stat *p_stat; 

	p_stat = (struct stat*) xcalloc (1, sizeof (struct stat)); 

	if (L_flag == TRUE) 
	{
		ret = stat (f_name, p_stat); 
	}
	else
	{
		ret = lstat (f_name, p_stat); 	
	}

	if (ret == -1) 
	{
		fprintf (stderr, "stat:%s:%s\n", f_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	return (p_stat); 
}


void print_usage (void) 
{
	static const char usage[] = "--help/-h : prints help\n\
--version/v : prints version\n\
--name/-n f_name  : stat file name"; 
	puts (usage); 
}

void print_version (void) 
{
	puts ("0.1"); 
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
