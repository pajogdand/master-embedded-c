#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

#define MAX_SIZE 256 
#define TRUE  1 
#define FALSE 0 

typedef int bool; 
bool is_identifier(char *identifier); 

int main(void) 
{
	char *line_ptr=NULL; 
	size_t max_size=MAX_SIZE; 
	int ans; 
	bool ret; 

	while(TRUE) 
	{
		printf("Enter an identifier:"); 
		getline(&line_ptr, &max_size, stdin); 

		ret = is_identifier(line_ptr); 
		
		if (ret)
			printf("%s is valid variable name\n", line_ptr); 
		else
			printf("%s is invalid variable name\n", line_ptr); 
		
		printf("Do you want to continue?:"); 
		scanf("%c", &ans); 
		getc(stdin); 
		if (ans != 'y' && ans != 'Y')
			break; 
	}

	exit(EXIT_SUCCESS); 
}

bool is_identifier(char *identifier)
{
	typedef enum {START, VALID, INVALID} state_t; 
	state_t state = START;  
	int i; 

	for(i=0; i < strlen(identifier); ++i)
	{
		switch(state)
		{
			case START: 
					if (isalpha(identifier[i]) || identifier[0] == '_')
						state= VALID; 
					else 
						state = INVALID; 
					break; 
			case VALID: 
					if (!isalpha(identifier[i]) && !isdigit(identifier[i]) &&
						identifier[i] != '_')
						state = INVALID; 
					break;
			case INVALID:
					return (FALSE); 
			default:
					fprintf(stderr, "State machine is corrupted\n"); 
		}
	}
	
	if(state== VALID)
		return TRUE; 
}
