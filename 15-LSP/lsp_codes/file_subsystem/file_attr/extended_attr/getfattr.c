#define _XOPEN_SOURCE 500 /*Required for nftw function, check man nftw and ftw.h */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <ftw.h> 
#include <sys/xattr.h> 
#include <sys/types.h> 

#define TRUE 			1 
#define FALSE 			0 
#define MAX_ATTR_VALUE_SIZE 	1024
#define MAX_ATTR_NAME_SIZE 	1024
#define MAX_NR_ATTR 		1024 
#define MAX_ENTRY_SIZE 		(MAX_ATTR_VALUE_SIZE * 2)
#define MAX_NR_NFTW_OPEN_FDS	10

typedef int flag_t; 

void print_usage 	   (void); 
void print_version 	   (void); 
void print_named_attribute (const char *path_name, const char *attr_name); 
void print_all_attributes  (const char *path_name); 
int  nftw_callback	   (const char *path_name, const struct stat *sb, 
			    int typeflag, struct FTW *ftw); 
/* Modified in main, only. Read by call-back of nftw handlers. 
 * Unfortunately, these flags have to be global because we cannot 
 * send arguments to call-back registered with nftw. Alternative 
 * would be to keep these variables local and call as many nftw 
 * functions as the combinations of flags with difference call-back 
 * handlers, which is time as well as space intensive. */ 
flag_t n_flag=FALSE, d_flag=FALSE, v_flag=FALSE, h_flag=FALSE; 
char *attr_name; 

int main (int argc, char *argv[])
{
	int ret, i, nftw_flag; 
	flag_t R_flag=FALSE, L_flag=FALSE, P_flag=FALSE, f_flag=FALSE, h_flag=FALSE; 
	char *path_name; 

	static const struct option opts [] = 
	{
		{"help", 	   		no_argument,       0, 'H'}, 
		{"version", 	 	no_argument,       0, 'V'}, 
		{"dump", 	   		no_argument,       0, 'd'}, 
		{"only-values",     no_argument,       0, 'v'},
		{"no-dereference",  no_argument,       0, 'h'}, 	
		{"name", 	   		required_argument, 0, 'n'}, 
		{"recursive", 	   	no_argument,       0, 'R'}, 
		{"logical", 	  	no_argument,       0, 'L'}, 
		{"physical", 	   	no_argument,       0, 'P'}, 
		{"file", 	   	   	required_argument, 0, 'f'}, 
		{0, 		   		0, 		      	   0,  0} 
	}; 

	if (argc == 1) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	while ((ret = getopt_long (argc, argv, "HVRLPhdvn:f:", opts, &i)) != -1) 
	{
		switch ((char)ret)
		{
			case 'H': 
				print_usage ();
				exit (EXIT_SUCCESS); 
			case 'V': 
				print_version (); 
				exit (EXIT_SUCCESS); 
			case 'd': 
				d_flag = TRUE; 
				break; 
			case 'v': 
				v_flag = TRUE; 
				break; 
			case 'h': 
				h_flag = TRUE; 
				break; 
			case 'n': 
				n_flag = TRUE; 
				attr_name = optarg; 
				break; 
			case 'R': 
				R_flag = TRUE; 
				break; 
			case 'L': 
				L_flag = TRUE; 
				break; 
			case 'P':
				P_flag = TRUE; 
				break; 
			case 'f': 
				f_flag = TRUE; 
				path_name = optarg; 
				break; 
			default: 
				print_usage (); 
				exit (EXIT_FAILURE); 
		}
	}
	
	/* Cannot skip path name */ 
	if (!f_flag) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	/* Dump all attributeis and dump only named attribute can't be together*/
	if (d_flag ==  n_flag)
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	/* -L or -P can be used only in conjunction with -R */ 
	if ((!R_flag && L_flag) || (!R_flag && P_flag))
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	if (!R_flag) 
	{
		printf ("#file: %s\n", path_name); 
		if (n_flag) 
		{
			print_named_attribute (path_name, attr_name); 
		}	
		else if (d_flag)
		{
			print_all_attributes (path_name); 
		}
	}
	/* Handler recursive case */ 
	else 
	{	
		nftw_flag = FTW_MOUNT | (P_flag ? FTW_PHYS : 0);
		h_flag = P_flag; 

		if (nftw (path_name, nftw_callback, MAX_NR_NFTW_OPEN_FDS, 
			  nftw_flag) != 0)
		{
			fprintf (stderr, "nftw:Error in traversing %s\n", 
				 path_name); 
			exit (EXIT_FAILURE); 
		}
	}

	exit (EXIT_SUCCESS); 
}

void print_named_attribute (const char *path_name, const char *attr_name)
{
	ssize_t ret, len_attr_name, len_attr_value; 
	static char attr_value_buffer[MAX_ATTR_VALUE_SIZE]; 	
	static char attr_entry_buffer[MAX_ENTRY_SIZE]; 

	/* Dereference symbolic link */ 
	if (!h_flag) 
	{
		ret = getxattr (path_name, attr_name, attr_value_buffer, 
				MAX_ATTR_VALUE_SIZE); 	
	}
	/* Don't dereference symbolic link */ 
	else 
	{
		ret = lgetxattr (path_name, attr_name, attr_value_buffer, 
				 MAX_ATTR_VALUE_SIZE); 
	}

	if (ret == -1) 
	{
		fprintf (stderr, "getxattr:%s:%s\n", path_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	if (v_flag)
	{
		puts (attr_value_buffer); 
	}
	else
	{
		strncpy (attr_entry_buffer, attr_name, strlen (attr_name)); 
		strncat (attr_entry_buffer, "=", strlen (attr_entry_buffer)+2); 
		strncat (attr_entry_buffer, attr_value_buffer, 
			 strlen (attr_entry_buffer) + strlen (attr_value_buffer) + 1); 
		puts (attr_entry_buffer); 
	}

	memset (attr_value_buffer, (int)'\0', strlen (attr_value_buffer)+1); 
	memset (attr_entry_buffer, (int)'\0', strlen (attr_entry_buffer)+1); 
}

void print_all_attributes (const char *path_name) 
{
	ssize_t ret; 
	static char attr_all_name_buffer[MAX_NR_ATTR * MAX_ATTR_NAME_SIZE]; 	
	int i; 

	/* Dereference symbolic link */ 
	if (!h_flag) 
	{
		ret = listxattr (path_name, attr_all_name_buffer, 
				 MAX_NR_ATTR * MAX_ATTR_NAME_SIZE); 
	}
	/* Do not dereference symbolic link */ 
	else 
	{
		ret = llistxattr (path_name, attr_all_name_buffer, 
				  MAX_NR_ATTR * MAX_ATTR_NAME_SIZE); 
	}
	
	if (ret == -1) 
	{
		fprintf (stderr, "listxattr:%s:%s\n", path_name, strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	for (i=0; attr_all_name_buffer[i]; i+=strlen (&attr_all_name_buffer[i])+1)
	{
		print_named_attribute (path_name, &attr_all_name_buffer[i]); 
	}

	memset (attr_all_name_buffer, (int)'\0', ret+1); 
}

int nftw_callback (const char *path_name, const struct stat *sb, int typeflag, 
		   struct FTW *ftw) 
{
	printf ("#File:%s\n", path_name); 
	if (n_flag) 
	{
		print_named_attribute (path_name, attr_name); 
	}	
	else if (d_flag)
	{
		print_all_attributes (path_name); 
	}

	putchar ((int)'\n'); 
	return (0); 
}

void print_usage (void) 
{
	static const char *usage = "getfattr:Help"; 
	puts (usage); 
}

void print_version (void) 
{
	puts ("0.1"); 
}
