#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

void exit_handler_one (void); 
void exit_handler_two (void); 

int main (void) 
{
	atexit (exit_handler_one); 
	atexit (exit_handler_two); 
	exit (EXIT_SUCCESS); 
}

void exit_handler_one (void) 
{
	printf ("Exit handler one\n"); 
}

void exit_handler_two (void)
{
	printf ("Exit handler two\n"); 
}
