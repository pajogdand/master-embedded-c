#include <stdio.h>
#include <stdlib.h>

// Data Type 
//  	Memory (bytes) 
//  	Range 
//  	Format Specifier 
 
// short int 
//  	2 
//  	-32,768 to 32,767 
//  	%hd 
 
// unsigned short int 
//  	2 
//  	0 to 65,535 
//  	%hu 
 
// unsigned int 
//  	4 
//  	0 to 4,294,967,295 
//  	%u 
 
// int 
//  	4 
//  	-2,147,483,648 to 2,147,483,647 
//  	%d 
 
// long int 
//  	4 
//  	-2,147,483,648 to 2,147,483,647 
//  	%ld 
 
// unsigned long int 
//  	4 
//  	0 to 4,294,967,295 
//  	%lu 
 
// long long int 
//  	8 
//  	-(2^63) to (2^63)-1 
//  	%lld 
 
// unsigned long long int 
//  	8 
//  	0 to 18,446,744,073,709,551,615 
//  	%llu 
 
// signed char 
//  	1 
//  	-128 to 127 
//  	%c 
 
// unsigned char 
//  	1 
//  	0 to 255 
//  	%c 
 
// float 
//  	4 
//  	 	%f 
 
// double 
//  	8 
//  	 	%lf 
 
// long double 
//  	16 
//  	 	%Lf 

int main()
{
    signed short int si;
    unsigned short int  usi;
    unsigned int ui;
    signed int i;
    signed long int li;
    unsigned long int uli;
    signed long long int lli;
    unsigned long long int ulli;
    
    signed char sc;
    unsigned char uc;

    float f;
    double d;
    long double ld;

    printf("size of si = %d \n", sizeof(si));
    printf("size of usi = %d \n", sizeof(usi));
    printf("size of ui = %d \n", sizeof(ui));
    printf("size of i = %d \n", sizeof(i));
    printf("size of li = %d \n", sizeof(li));
    printf("size of uli = %d \n", sizeof(uli));
    printf("size of lli = %d \n", sizeof(lli));
    printf("size of ulli = %d \n", sizeof(ulli));
     
    exit(0);
}

