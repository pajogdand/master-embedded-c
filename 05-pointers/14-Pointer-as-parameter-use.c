#include <stdio.h>
#include <stdlib.h>

int* get_array_1(int* p_arr_size);
void get_array_2(int** pp_arr, int* p_arr_size);
void output_array(int* p_arr, int size, const char* msg);
int main()
{
    int *p1 = NULL;
    int size1;

    size1 = 5;
    p1 = get_array_1(&size1);
    output_array(p1 ,size1, "Array 1:");
    free(p1);

    int* p_arr2 = NULL; 
    int size2;
    get_array_2(&p_arr2, &size2); 
    output_array(p_arr2, size2, "Array 2:"); 
    free(p_arr2); 
    p_arr2 = NULL;
    exit(0);
}

int * get_array_1(int * p_arr_size)
{
    if(p_arr_size < 0)
    {
        exit(-1);
    }
    int *p1 = (int*)malloc((*p_arr_size)*sizeof(int));

    for(int i =0;i<(*p_arr_size) ;i++)
    {
        *(p1+i) = rand();
    }

    return p1;

}

void output_array(int* p_arr, int size, const char* msg)
{
    if(msg != NULL)
    {
        puts(msg);
    }
    for(int i = 0; i <size ; i++)
    {
        printf("data[%d] = %d \n" , i , *(p_arr+i));
    }
}

void get_array_2(int** pp_arr, int* p_arr_size)
{
    int* p_arr = NULL; 
    int size = 0; 
    int i; 

    assert(pp_arr != NULL); 
    assert(p_arr_size != NULL); 

    printf("Enter size of array:"); 
    scanf("%d", &size); 
    assert(size > 0); 

    p_arr = malloc(size * sizeof(int)); 
    assert(p_arr != NULL); 

    for(i = 0; i < size; ++i)
        *(p_arr + i) = rand(); 

    *pp_arr = p_arr; 
    *p_arr_size = size; 
}