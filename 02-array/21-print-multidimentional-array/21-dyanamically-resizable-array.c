#include <stdio.h>
#include <stdlib.h>

/* Dynamically resizable array is called as vector */ 

struct vector_of_integers
{ 
    int* p_arr; 
    long long int number_of_elements; 
}; 

struct vector_of_integers* create_vector_of_integers(void); 
int append_element_to_vector(struct vector_of_integers* p_vector, int element);
void show_vector(struct vector_of_integers* p_vector, const char* msg); 
void destroy_vector(struct vector_of_integers* p_vector);

int main()
{
    
    exit(-1);
}
struct vector_of_integers* create_vector_of_integers(void)
{
    struct vector_of_integers* p = malloc(sizeof(struct vector_of_integers));
    
    if(p != NULL)
    {
        p->number_of_elements = 0;
        p->p_arr = NULL;
        return p;
    }
    else
    {
        printf("allocation of memory failed\n");
        exit(-1);
    }
}

struct vector_of_integers* create_vector_of_integers(void)
{
    struct vector_of_integers* p = malloc(sizeof(struct vector_of_integers));
    
    if(p != NULL)
    {
        p->number_of_elements = 0;
        p->p_arr = NULL;
        return p;
    }
    else
    {
        printf("allocation of memory failed\n");
        exit(-1);
    }
}