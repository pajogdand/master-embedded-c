#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#ifndef STR_EQUAL
#define STR_EQUAL			0
#endif 

#ifndef NO_ARGUMENT
#define NO_ARGUMENT			0
#endif 

#ifndef REQUIRED_ARGUMENT
#define REQUIRED_ARGUMENT 	1
#endif 

#ifndef OPTIONAL_ARGUMENT
#define OPTIONAL_ARGUMENT	2
#endif 

#ifndef OFF			
#define OFF				0
#endif 

#ifndef ON
#define ON				1
#endif 

char *eg_option_arg; 

struct eg_options {
	char *str_name; 
	int  i_has_argument; 
}; 


void print_usage (void); 
void print_version (void); 
void *xcalloc (int i_nr_elements, int i_size_per_element); 
int x_getopt_long (int argc, char *argv[], const struct eg_options opt_arr [], int *pi_index); 

int main (int argc, char *argv[]) 
{
	int i_ret, i_index, i_while_flag=OFF; 

	struct eg_options opt_arr [] = 
	{
		{"help", 	NO_ARGUMENT}, 
		{"version",	NO_ARGUMENT}, 
		{"size", 	REQUIRED_ARGUMENT}, 
		{0,		0}
	}; 
	
	if (argc == 1) 
	{	
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	while ((i_ret = x_getopt_long (argc, argv, opt_arr, &i_index)) != -1)
	{
		i_while_flag = ON; 
		switch (i_ret)
		{
			case 0:
				if (strncmp (opt_arr [i_index].str_name, "help", strlen ("help")) == STR_EQUAL)
				{
					print_usage (); 
				}

				if (strncmp (opt_arr [i_index].str_name, "version", strlen ("version")) == STR_EQUAL)
				{
					print_version (); 
				}

				if (strncmp (opt_arr [i_index].str_name, "size", strlen ("size")) == STR_EQUAL)
				{	
					if (eg_option_arg != NULL)
					{
						printf ("arg=%s\n", eg_option_arg);
					}
				}
				break; 
			default:
				print_usage (); 
				exit (EXIT_FAILURE);
		}
	}

	if (i_while_flag == OFF)
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS); 
}

int x_getopt_long (int argc, char *argv[], const struct eg_options opt_arr [], int *pi_index)
{
	static int i_curr_index = 1; 
	int i_remaining_len, i_cnt, i_equal_found=OFF; 
	char *str_run, *str_opt_name; 
	/* Till there is one more command line option to be processed */
	while ((i_curr_index > 0) && (i_curr_index < argc)) 
	{ 
		/* Enter if not null */
		if (argv [i_curr_index] != '\0') 
		{
		       	/* Current command line argument is an option */
			if (strncmp (argv [i_curr_index], "--", 2) == STR_EQUAL)	
			{
			  /* Following for loop calculates the length of command line 
			   * option, omitting leading '--' If option takes an argument 
			   * then we treat equal to sign as the end of option name */ 
				for (i_remaining_len=0, str_run= (argv[i_curr_index] + 2); 
				     *str_run != '\0' && *str_run != '='; 
				      i_remaining_len++, str_run++)
					; 
				
				/* Allocate memory for option name and extract option 
				 * name from current command line argument */ 
				str_opt_name = (char*) xcalloc (1, i_remaining_len + 1); 
				strncpy (str_opt_name, (argv [i_curr_index] + 2), 
					 i_remaining_len); 
				*(str_opt_name + i_remaining_len) = '\0'; 

				/* Keep a note, whether = occured in command line option 
				 * or not */ 
				if (*str_run == '=' && *str_run != '\0')
				{
					i_equal_found = ON; 
				}
				
				/* Perform a linear seach through the array of option 
				 * list sent by the caller. 
				 * case 1. If an option name is found & does not take an 
				 * argument then i_equal_found should be OFF else throw 
				 * error 
				 * case 2. If an option name is found & takes an argument 
				 * then i_equal_found should be ON else throw error 
				 * case 3. If current command line is an option, 
				 * (that's we are here in the first place) and option name 
				 * is not found in the array provided by the caller then 
				 * it's an invalid option. Throw error and exit */ 

				for (i_cnt=0; opt_arr [i_cnt].str_name != NULL; i_cnt++)
				{
					if (strncmp (opt_arr [i_cnt].str_name, 
					    str_opt_name, i_remaining_len) == STR_EQUAL)
					{ 
					 /* Set parameterized return value to the 
					  * index into the option array */	
						*pi_index = i_cnt;
					     if (opt_arr [i_cnt].i_has_argument == REQUIRED_ARGUMENT)
						{
							if (i_equal_found == OFF)
							{
								printf ("%s:option %s expects argument\n", 
									    argv[0], str_opt_name); 
								exit (EXIT_FAILURE); 
							}
							eg_option_arg = (argv [i_curr_index] + i_remaining_len + 3); 
							i_curr_index++; 
							return (0); 
						} /* case 2 */ 
						else if (opt_arr [i_cnt].i_has_argument == NO_ARGUMENT)
						{
							if (i_equal_found == ON)
							{
								printf ("%s:option %s does not expect argument\n", 
									    argv[0], str_opt_name); 
								exit (EXIT_FAILURE); 
							}
							i_curr_index++; 
							return (0); 
						} /* case 1 */ 
					}
				}
 				/* Option name not in the array list provided */  
				printf ("%s:invalid option %s\n", argv[0], str_opt_name);
				exit (EXIT_FAILURE); /* case 3 */ 
			} 
			/* Current command line argument is not an option, hence continue */ 
			else
			{
				i_curr_index++; 
				continue; 
			}
		}
		/* Curiously command line argument is null. This is 'VERY UNLIKELY' */ 
		else 
		{
			printf ("Fatal Error\n"); 
			exit (EXIT_FAILURE); 
		}
	} 
 	/* Command line options exhausted */ 
	return (-1);
}

void *xcalloc (int i_nr_elements, int i_size_per_element)
{
	void *pv_tmp; 

	pv_tmp = calloc (i_nr_elements, i_size_per_element); 
	if (pv_tmp == NULL)
	{
		printf ("Fatal:Out of Memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (pv_tmp); 
}

void print_usage (void) 
{
	printf ("[COMMAND NAME] [OPTIONS]\n"); 
	printf ("--help:For printing help\n"); 
	printf ("--version:For printing version\n"); 
	printf ("--size=arg:For specifying a size\n"); 
}

void print_version (void) 
{
	printf ("0.1\n"); 
}
