#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <signal.h> 
#include <sys/mman.h> 
#include <sys/types.h> 

#define PAGE_SIZE 4096

void signal_handler (int signum); 

int main (void) 
{
	int fd, ret, i; 
	char *addr; 
	
	signal (SIGBUS, signal_handler); 

	fd = open ("test.log", O_RDWR); 
	if (fd == -1) 
	{
		fprintf (stderr, "open:test.log:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	addr = (char*)mmap (NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
	if (!addr)
	{
		fprintf (stderr, "mmap:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	for (i=0; i < PAGE_SIZE; i++) 
		printf ("addr[%d]:%c\n", i, addr[i]); 

	memset (addr, (int)'A', PAGE_SIZE/2); 
	memset (addr + PAGE_SIZE/2, (int)'B', PAGE_SIZE/2); 

	ret = munmap (addr, PAGE_SIZE); 
	if (ret == -1) 
	{
		fprintf (stderr, "munmap:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	if (close (fd) == -1) 
	{
		fprintf (stderr, "close:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS); 
}

void signal_handler (int signum) 
{
	printf ("signum:%d\n", signum); 
}
