#include <stdio.h> 
#include <stdlib.h>
#include <stdarg.h> 

int getoredflags (int nr_elements, ...); 
int getoredflags_arr (int arr[], int nr_elements); 

#define O_RDONLY 00
#define O_WRONLY 010 
#define O_RDWR	 0100 

int main (void) 
{	
	int rs = getoredflags (3, O_RDONLY, O_WRONLY, O_RDWR); 
	printf ("rs:%d\n", rs); 

	static int flags_arr [] = {O_RDONLY, O_WRONLY, O_RDWR}; 
	printf ("rs:%d\n", getoredflags_arr (flags_arr, sizeof (flags_arr) / sizeof (int))); 
	exit (EXIT_SUCCESS); 
}

int getoredflags (int nr_elements, ...) 
{
	va_list ap; 
	int i, rs=0; 

	va_start (ap, nr_elements); 

	for (i = 0; i < nr_elements; ++i) 
	{
		rs = rs | va_arg (ap, int); 	
	}

	va_end (ap); 
	
	return (rs); 
}

int getoredflags_arr (int arr[], int nr_elements)
{
	int i, rs=0; 

	for (i = 0; i < nr_elements; ++i) 
	{
		rs |= arr[i]; 
	}

	
	return (rs); 
}
