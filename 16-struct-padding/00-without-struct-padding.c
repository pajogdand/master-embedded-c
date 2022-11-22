#include <stdio.h>
#include <stdlib.h>

struct Info
{
    /* data */
    int a;
    char b;
    char c;    
}I;

struct Info1
{
    /* data */
    double a;
    char b;
    char c;    
}I1;


struct Info2
{
    /* data */
    char a;
    char b;
    int c;    
}I2;

struct Info3
{
    /* data */
    char a;
    int c;
    char b;        
}I3;


int main()
{
    printf("suze of I = %d \n", sizeof(I));
    printf("suze of I1 = %d \n", sizeof(I1));
    printf("suze of I1 = %d \n", sizeof(I2));
    printf("suze of I1 = %d \n", sizeof(I3));
    exit(0);
}