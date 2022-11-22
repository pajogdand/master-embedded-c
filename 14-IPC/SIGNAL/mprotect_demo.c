#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <signal.h> 
#include <setjmp.h> 
#include <sys/mman.h> 

#ifdef PAGE_SIZE
#undef PAGE_SIZE 
#define PAGE_SIZE 4096
#else
#define PAGE_SIZE 4096
#endif 

typedef int (*function_t)(void); 
jmp_buf buffer; 
unsigned char code[] = {0x90, 0x48, 0x89, 0xe5, 0xb8, 0x64, 0x1, 0x2, 0x3, 
						0x4d, 0xc3}; 

void sigill_handler(int signum)
{
	printf("I am in sigill handler\n"); 
}

void sigsegv_handler(int signum)
{
	printf("I am in sigsegv_handler\n"); 
	longjmp(buffer, 1); 
}

int main(void) 
{
	void *page; 
	int i; 
	function_t ptr; 
	int ret, setjmp_ret; 

	signal(SIGSEGV, sigsegv_handler); 
	signal(SIGILL, sigill_handler); 

	page = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, 
				MAP_PRIVATE | MAP_ANONYMOUS, -1, 0); 
	if(page == NULL){
		fprintf(stderr, "mmap:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	for(i=0; i < 11; i++)
		*((char*)page + i) = code[i]; 
	
	setjmp_ret = setjmp(buffer); 
	if(setjmp_ret == 1) 
			goto skip; 

	ptr = (function_t)page; 
	ret = ptr(); 
	printf("ret:%d\n", ret); 
skip:
	ret = munmap(page, PAGE_SIZE); 
	if(ret == -1)
	{
		fprintf(stderr, "munmap:%s\n", strerror(errno)); 
		exit(EXIT_FAILURE); 
	}

	exit(EXIT_SUCCESS); 
}
