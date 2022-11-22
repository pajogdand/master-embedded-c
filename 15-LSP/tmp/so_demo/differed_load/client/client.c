#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <dlfcn.h> 

char *lib_path = "/usr/lib64/libxyz.so"; 

int main (void) 
{
	void *ptr = dlopen(lib_path, RTLD_LAZY); 
	int (*ptrfn)(int, int); 

	if(!ptr){
		fprintf(stderr, "dlopen:%s\n", dlerror()); 
		exit (EXIT_SUCCESS); 
	}

	ptrfn = dlsym(ptr, "my_add"); 
	printf ("sum=%d\n", ptrfn(10, 20)); 
	exit (EXIT_SUCCESS); 
}
