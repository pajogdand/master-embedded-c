#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <getopt.h> 
#include <unistd.h> 
#include <signal.h> 

void print_usage (void); 
void print_version (void); 

typedef int flag_t; 
#define TRUE  1
#define FALSE 0 

struct sig_entry {
	char *sig_name; 
	int sig_num; 
}; 

static const struct sig_entry sig_list [] = 
{
	{"SIGHUP", 1}, 
	{"SIGINT", 2}, 
	{"SIGQUIT", 3}, 
	{"SIGILL", 4}, 
	{"SIGTRAP", 5}, 
	{"SIGABRT", 6}, 
	{"SIGIOT", 6}, 
	{"SIGBUS", 7}, 
	{"SIGFPE", 8}, 
	{"SIGKILL", 9}, 
	{"SIGUSR1", 10}, 
	{"SIGSEGV", 11}, 
	{"SIGUSR2", 12}, 
	{"SIGPIPE", 13}, 
	{"SIGALRM", 14}, 
	{"SIGTERM", 15}, 
	{"SIGSTKFLT", 16}, 
	{"SIGCHLD", 17}, 
	{"SIGCLD", 17}, 
	{"SIGCONT", 18}, 
	{"SIGSTOP", 19}, 
	{"SIGTSTP", 20}, 
	{"SIGTTIN", 21}, 
	{"SIGTTOU", 22}, 
	{"SIGURG", 23}, 
	{"SIGXCPU", 24}, 
	{"SIGXFSZ", 25}, 
	{"SIGVTALRM", 26}, 
	{"SIGPROF", 27}, 
	{"SIGWINCH", 28}, 
	{"SIGIO", 29}, 
	{"SIGPOLL", 29}, 
	{"SIGPWR", 30}, 
	{"SIGSYS", 31}, 
	{"SIGUNUSED", 31}, 
	{"_NSIG", 65}, 
	{NULL, 0}
}; 

int main (int argc, char *argv[]) 
{
	int ret, i, signum, n; 
	pid_t pid; 
	flag_t p_flag=FALSE, s_flag=FALSE, n_flag=FALSE, 
		   found_flag=FALSE; 

	static const struct option op [] = 
	{
		{"help", no_argument, 0, 'h'}, 
		{"version", no_argument, 0, 'v'}, 
		{"signame", required_argument, 0, 's'}, 
		{"pid", required_argument, 0, 'p'}, 
		{"signum", required_argument, 0, 'n'}, 
		{0, 0, 0, 0}
	}; 

	if (argc < 3)
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	while ((ret = getopt_long (argc, argv, "hvs:p:n:", op, &i)) != -1)
	{
		switch ((char)ret)
		{
			case 'p':
					if (optarg)
					{
						p_flag = TRUE; 
						pid = (pid_t) atoi (optarg); 						  
					}
					if (pid < 0) 
					{
						puts ("Invalid pid"); 
						exit (EXIT_FAILURE); 
					}
					break; 
			case 's':
					if (optarg)
					{
						s_flag = TRUE; 
						for (i=0; (sig_list[i].sig_name) != NULL; i++)
						{
							if ((strncmp (sig_list[i].sig_name, optarg, 
							     strlen (sig_list[i].sig_name))) == 0)
							{
									found_flag = TRUE; 
									signum = sig_list[i].sig_num; 
							}
						}
					}

					if (found_flag == FALSE)
					{
						puts ("Invalid signal name"); 
						exit (EXIT_FAILURE); 
					}
					
					break; 
			case 'n':
					if (optarg)
					{
						n_flag = TRUE; 
						signum = atoi (optarg); 
						if (signum <= 0) 
						{
							puts ("Invalid signal"); 
							exit (EXIT_FAILURE); 
						}
					}	
					break; 
			case 'h':
					print_usage ();
					exit (EXIT_FAILURE); 
					break; 
			case 'v':
					print_version ();
					exit (EXIT_FAILURE); 
					break; 
			default:
					print_usage (); 
					exit (EXIT_FAILURE); 
		}
	
	}
	
	if (p_flag == TRUE) 
	{
		if ((n_flag == TRUE && s_flag == TRUE) || 
		    (n_flag == FALSE && s_flag == FALSE))
		{
			print_usage (); 
			exit (EXIT_FAILURE); 
		}	
	}
	else
	{
		print_usage (); 
		exit (EXIT_FAILURE); 
	}

	if ((signum <= 0) || (signum > 31))
	{
		puts ("Invalid signal specification"); 
		exit (EXIT_FAILURE); 
	}

	ret = kill (pid, signum); 
	if (ret == -1) 
	{
		fprintf (stderr, "kill:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS); 
}

void print_usage (void) 
{
	static const char usage [] = 
"--help/-h    : prints usage\n\
--version/-v : prints version\n\
--signame/-s : signal name\n\
--signum/-n  : signal number\n\
--pid/-p     : process id\n\
usage        : kill process_id signal_name|signal_num"; 
	puts (usage); 
}

void print_version (void) 
{
	puts ("0.1"); 
}
