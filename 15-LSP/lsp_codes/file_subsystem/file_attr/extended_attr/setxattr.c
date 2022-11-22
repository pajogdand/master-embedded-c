#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/xattr.h> 
#include <sys/types.h> 

#define TRUE 1 
#define FALSE 0 

typedef int flag_t; 

void print_usage (void); 
void print_version (void); 

int main (int argc, char *argv[]) 
{
	int ret, i; 
	flag_t n_flag=FALSE, v_flag=FALSE, x_flag=FALSE, r_flag=FALSE, 
	       h_flag=FALSE, f_flag=FALSE; 
	char *attr_name, *attr_value, *path_name; 
	
	static const struct option opts [] = 
	{
		{"help", no_argument, 0, 'H'}, 
		{"version", no_argument, 0, 'V'}, 
		{"file", required_argument, 0, 'f'}, 
		{"name", required_argument, 0, 'n'},
		{"value", required_argument, 0, 'v'},
		{"remove", no_argument, 0, 'x'},
		{"no-dereference", no_argument, 0, 'h'},
		{0, 0, 0, 0},
	}; 

	while ((ret = getopt_long (argc, argv, "HVhxn:v:f:", opts, &i)) != -1)
	{
		switch ((char)ret)
		{
			case 'H': 
				print_usage (); 
				exit (EXIT_SUCCESS); 
			case 'V': 
				print_version (); 
				exit (EXIT_SUCCESS); 
			case 'f': 
				f_flag = TRUE; 
				path_name = optarg; 
				break; 
			case 'n': 
				n_flag = TRUE; 
				attr_name = optarg; 
				break; 
			case 'v': 
				v_flag = TRUE; 
				attr_value = optarg; 
				break; 
			case 'x': 
				r_flag = TRUE; 
				attr_name = optarg; 
				break; 
			case 'h': 
				h_flag = TRUE; 
				break; 
			default: 
				print_usage (); 
				exit (EXIT_FAILURE); 

		}
	}

	/* Usage error : If filename is missing */ 
	if (!f_flag) 
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	if (n_flag) 
	{
		/* File name and attribute name flags are on here */ 
		/* Usage Error : Value and remove flags on simultaneously */ 
		if (!(v_flag ^ r_flag))
		{
			print_usage (); 
			exit (EXIT_FAILURE); 
		}

		if (v_flag) 
		{
			/* Value flag is on */ 
			if (!h_flag) 
			{
				/* h_flag : OFF, Symbolic link to be
				 * dereferenced */ 
				ret = setxattr (path_name, attr_name, attr_value, 
						strlen (attr_value), XATTR_CREATE); 

				if (ret == -1)
				{
					/* If set setxattr fails because
					 * attribute exists already then try
					 * with XATTR_REPLACE */ 
					if (errno == EEXIST)
					{
						ret = setxattr (path_name, attr_name, attr_value, 
								strlen (attr_value), XATTR_REPLACE); 
						
					}
				}
			}
			else
			{
				/* h_flag is ON : Symbolic link NOT to be
				 * dereferenced */ 
				ret = lsetxattr (path_name, attr_name, attr_value, 
						 strlen (attr_value), XATTR_CREATE); 
				if (ret == -1) 
				{
					/* lsetxattr fails because attribute is
					 * already existing then trhy with
					 * XATTR_REPLACE */ 
					if (errno == EEXIST)
					{
						ret = lsetxattr (path_name, attr_name, attr_value, 
								 strlen (attr_value), XATTR_REPLACE); 
					}

				}
			}
			
			/* Common error handler for following cases :  
			 * (1) First calls to setxattr or lsetxatrr with
			 * XATTR_CREATE are failing for the reason other than EEXIT 
			 * (2) Second calls to setxattr or lsetxattr are with
			 * XATTR_REPPLACE are failing for ANY reason */ 
			if (ret == -1) 
			{
				fprintf (stderr, "setxattr:%s:%s\n", path_name, 
					 strerror (errno)); 
				exit (EXIT_FAILURE); 
			}

		}

		/* Remove flag is ON and value flag is OFF */ 	
		if (r_flag) 
		{
			/* h_flag is OFF : Dereference symbolic link */ 
			if (!h_flag) 
			{
				ret = removexattr (path_name, attr_name); 
			}
			/* h_flag is ON : Don't dereference symbolic link */
			else
			{
				ret = lremovexattr (path_name, attr_name); 
			}
			/* Common handler for removexattr and lremovexattr */ 
			if (ret == -1) 
			{
				fprintf (stderr, "removexattr:%s:%s\n", path_name, 
					 strerror (errno)); 
				exit (EXIT_FAILURE); 
			}

		}
	}
	else
	{
		/* Usage Error : If attribute name is missing */ 
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS); 
}

void print_usage (void) 
{
	static char *usage = "In print_usage:setxattr"; 
	puts (usage); 
}

void print_version (void)
{
	puts ("0.1"); 
}
