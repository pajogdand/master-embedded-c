/*
 * You are given an incoming bit stream/data and the size in number of bits
 * (which may not be multiple of 8, eg. it could be 11 bits, 31 bits etc),
 * you are also given a bit pattern and size in bits (which also may not
 * be multiple of 8, eg 5 bits).
 *
 * Implement:
 * int found(void *in_data, int data_size,
 *           void *pattern, int pattern_size)
 *
 * Expectations:
 * 1. The API returns 1 if the pattern is found and 0 if the pattern is not found.
 */

#include <stdio.h>
#include <stdlib.h>

 int found(void *in_data, int data_size, void *pattern, int pattern_size);

int main(void)
{
	// int x = 8;
	// int mask = 1;
	// int A[32] = {0};
	// for(int i=31;i>=0;i--)
	// {
	// 	if((mask & x) != 0)
	// 	{
	// 		A[i] = 1;
	// 	}	
	// 	mask =  mask << 1;
	// }

	// for(int i=0;i<32;i++)
	// {
	// 	printf("A[%d] = %d \n" , i ,A[i]);
	// }

	int in_data   = 10;
	int data_szie = 5;
	int patten    = 3;
	int size 	  = 3; 

	found(&in_data , data_szie , &patten, size);
	exit(0);
}

int found(void *in_data, int data_size, void *pattern, int pattern_size)
{
	int data  = *(int *)in_data;
	int pat   = *(int *)pattern;
	int mask = 01;
	int id[32] = {0};
	int p[32] = {0};
	for(int i=31;i>=0;i--)
	{
		if((mask & data) != 0)
		{
			id[i] = 1;
		}
		if((mask & pat) != 0)
		{
			p[i] = 1;
		}
			
		mask =  mask << 1;
	}

	for(int i=0; i<32-pat ; i++)
	{

		if( (data & pat) == pat)
		{
			printf("found");
			break;
		}
		pat <<= pat;
	}

	// for(int i=0;i<32;i++)
	// {
	// 	printf("A[%d] = %d \n" , i ,A[i]);
	// }
	
}