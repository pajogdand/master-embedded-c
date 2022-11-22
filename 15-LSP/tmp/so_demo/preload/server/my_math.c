#include "my_math.h" 

static int 		factorial 	(int n); 
static double 	power 		(double base, int power); 

double my_sin (double angle)
{
	return (angle -  power (angle, 3)/factorial (3) + 
			power (angle, 5) / factorial (5) - 
			power (angle, 7)/factorial (7)); 
}

double my_cos (double angle) 
{
	return (1 - power (angle, 2) / factorial (2) + 
			power (angle, 4) / factorial (4) - 
			power (angle, 6) / factorial (6)); 
}

static int factorial (int n) 
{
	if (n == 1) 
		return (1); 
	else
		return (n * factorial (n-1));
}

static double power (double base, int power) 
{
	int rs = 1, i = 0; 
	for (; i < power; ++i) 
		rs *= base; 

	return (rs); 
}
