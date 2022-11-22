#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <pthread.h> 
#include <sys/types.h> 

typedef struct in{
	int i_num; 
	float f_num; 
}in_t; 

typedef struct out {
	long long int ll_num; 
	double d_num; 
}out_t; 

void *thread_entry (void* args); 
void *xcalloc (int, int); 

int main (void) 
{
	pthread_t th1; 
	out_t *out; 
	in_t *in = xcalloc (1, sizeof (in_t)); 
	
	in->i_num = 10; 
	in->f_num = 3.14; 

	pthread_create(&th1, NULL, thread_entry, (void*)in);  
	pthread_join(th1, (void**) &out); 
	
	printf ("thread died value : ll_num : %lld d_num : %lf\n", 
		out->ll_num, out->d_num); 

	free (in); 
	free (out); 

	exit (EXIT_SUCCESS); 
}

void *thread_entry (void *args) 
{
	struct out *out; 
	in_t *in = (in_t*)args; 
	out_t *out_val = (out_t*) xcalloc (1, sizeof (out_t)); 
	out_val->ll_num = in->i_num * 10000; 
	out_val->d_num = in->f_num * 100.5; 
	printf ("I am in thread 1 .. about to exit ...\n"); 
	return (out_val); 
}

void *xcalloc (int nr_elements, int size_per_element) 
{
	void *ptr = calloc (nr_elements, size_per_element); 
	if (!ptr) 
	{
		fprintf (stderr, "calloc:out of memory\n"); 
		exit (EXIT_FAILURE); 
	}

	return (ptr); 
}
