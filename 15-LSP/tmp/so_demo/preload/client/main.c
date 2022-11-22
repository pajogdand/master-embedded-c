#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <my_math.h> 

int main (void) 
{
	static double pi = 3.14159; 
	double angle = pi / 3; 

	printf ("sin (angle) = %lf cos (angle) = %lf\n", 
			 sin (angle), cos (angle)); 
	printf ("my_sin (angle) = %lf my_cos (angle) = %lf\n", 
			my_sin (angle), my_cos (angle)); 

	exit (EXIT_SUCCESS); 
}
