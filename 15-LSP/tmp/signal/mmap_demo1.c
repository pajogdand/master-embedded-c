#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <signal.h> 
#include <sys/mman.h> 

#define PAGE_SIZE 4096 

int main (void) 
{
	char *ptr; 
	int i, ret; 

	ptr = (char*)mmap (NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, 
					   MAP_ANONYMOUS | MAP_PRIVATE, -1, 0); 
	if (!ptr) 
	{
		fprintf (stderr, "mmap:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	memset (ptr, (int)'A', PAGE_SIZE/2);
	memset (ptr+PAGE_SIZE/2, (int)'B', PAGE_SIZE/2); 

	for (i=0; i < PAGE_SIZE; i++)
		putchar (ptr[i]); 

	ret = munmap (ptr, PAGE_SIZE); 
	if (ret == -1)
	{
		fprintf (stderr, "munmap:%s\n", strerror (errno)); 
		exit (EXIT_FAILURE); 
	}

	exit (EXIT_SUCCESS); 
}
