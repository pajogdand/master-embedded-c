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

struct chandu
{
    short int a;
    char b[5];
}C;


int main()
{
    printf("size of I = %d \n", sizeof(I));
    printf("size of I1 = %d \n", sizeof(I1));
    printf("size of I2 = %d \n", sizeof(I2));
    printf("size of I3 = %d \n", sizeof(I3));
    printf("size , a =%d, b =%d  C = %d \n" , sizeof(C.a) , sizeof(C.b) , sizeof(C));
    exit(0);
}