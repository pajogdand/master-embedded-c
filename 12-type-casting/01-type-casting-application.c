#include <stdio.h> 
#include <stdlib.h> 

int a = 7; 
int b = 4; 

int div_1; 
float div_2; 

int main(void)
{
    div_1 = a / b; 
    div_2 = ((float)a)/b; 
    printf("div_1=%d, div_2=%.4f\n", div_1, div_2); 
    exit(0); 
}