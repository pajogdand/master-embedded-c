#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
	while(1){
		switch(rand() % 4){
			case 0: 
					printf("Message 1 ......\n"); 
					break; 
			case 1: 
					printf("Message 2 ... FUN...\n"); 
					break; 
			case 2: 
					printf("FOOOOOOOO\n"); 
					break; 
			case 3: 
					printf("BARRRRRR....\n"); 
					break; 
		}	
	}
	
	return 0; 
}
