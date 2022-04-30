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

#define SUCCESS 1
#define FAIL 0
#define ERROR -1
 int found(void *in_data, int data_size, void *pattern, int pattern_size);
 int found_ys(void *in_data, int data_size, void *pattern, int pattern_size);

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

	int in_data   = 1;
	int data_szie = 16;
	int patten    = 2;
	int size 	  = 8;
	int ret = found_ys(&in_data , data_szie , &patten, size);
	printf("ret = %d" , ret);
	if( ret == SUCCESS)
	{
		printf("found \n");
	}
	else if(ret == FAIL)
	{
		printf(" not found \n");
	}
	else if(ret == ERROR)
	{
		printf("Exting with error\n");
	}
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

int is_kth_bit_set(int num , int k)
{
	// here k =0,1,2,3...

	if( (1 & (1<<k)) !=0) 
	{
		return 1;
	}
	else{
		return 0;
	}

}
int found_ys(void *in_data, int data_size, void *pattern, int pattern_size)
{
	
	int soruce = *(int *)in_data;
	int pat    = *(int *)pattern;

	if(data_size == 0 || pattern_size == 0 || (pattern_size > data_size))
	{
		return ERROR;
	}
	
	int size_delta = data_size - pattern_size;

	int i , j;
	int flag;

	for(int i=0;i<size_delta;++i)
	{
		flag = SUCCESS;
		for(int j=0; j<pattern_size ; ++j)
		{
			// extract (i+j)th bit from soruce
			int data_bit = is_kth_bit_set(soruce , (i+j));
			int pat_bit = is_kth_bit_set(pat , j);
			if(data_bit != pat_bit)
			{
				flag = FAIL;	
				break;
			}
		}
		if(flag == SUCCESS)
		{
			return flag;
		}
	}

	return FAIL;
	
}