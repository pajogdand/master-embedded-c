#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/mman.h> 

#ifndef PAGE_SIZE 
#define PAGE_SIZE 4096
#endif 

unsigned char code[11] = {0x55, 0x48, 0x89, 0xe5, 0xb8, 0x14, 0x0, 0x0, 0x0, 0xc9, 0xc3}; 
typedef int (*ptr_fn_t)(void); 

int main (void) 
{
	int ret; 
	void *ptr;  
	ptr_fn_t ptr_fn; 

	ptr = (void*)((unsigned long int)code & 0xFFFFFFFFFF000); 
	printf ("ptr=%p\n", ptr); 
	
	ret = mprotect(ptr, 11, PROT_READ | PROT_EXEC); 
	if (ret == -1){
		fprintf(stderr, "mprotect:%s\n", strerror(errno)); 
		exit (EXIT_FAILURE); 
	}

	ptr_fn = (ptr_fn_t)code; 	
	ret = ptr_fn(); 
	printf("ret=%d\n", ret); 

	exit (EXIT_SUCCESS); 
}
