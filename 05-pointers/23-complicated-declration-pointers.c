#include <stdio.h> 
#include <stdlib.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
};

void ptr_to_built_in(void); 
void ptr_to_struct(void); 
void ptr_to_arr(void); 
void ptr_to_fun(void); 
void ptr_to_ptr(void); 
void insertion_sort(int* p_arr, int size); 

void ptr_to_built_in(void)
{
    int* p; 
    int n; 
    int m; 
    p = &n; 
    *p = 100; 
    m = *p; 
}

void ptr_to_arr(void)
{
    int (*p)[5]; 
    int arr[5]; 
    int i; 
    p = &arr; 

    for(i = 0; i < 5; ++i)
    {
        (*p)[i] = (i+1) * 10; 
    }
}

void ptr_to_fun(void)
{
    void (*pfn)(int*, int); 
    pfn = insertion_sort; 
    pfn(NULL, 0); 
}

void insertion_sort(int* p_arr, int size)
{
    puts("Insertion sort"); 
}

void ptr_to_struct(void)
{
    struct Date* p_date = NULL; 

    p_date = (struct Date*)malloc(sizeof(struct Date)); 
    p_date->day = 10; 
    p_date->month = 1; 
    p_date->year = 2020; 
    free(p_date); 
    p_date = NULL; 
}

void ptr_to_ptr(void)
{
    int n = 10; 
    int m; 
    int* p = NULL; 
    int** pp = NULL; 

    p = &n; 
    *p = 100; // n = 100 
    pp = &p; 
    **pp = 200; //n = 200 
    *pp = &m;   // p will start pointing to m 
    *p = 2000;  // m = 2000 
    **pp = 20000; // m = 20000 
}