#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main (void) 
{
	int ret; 
	ret = printf ("Hello\n"); 
	_exit (ret); 
}

