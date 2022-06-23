#include <stdio.h>
#include <stdlib.h>

#define N  8
void *xmalloc(int size_in_bytes);
void *xcalloc(int num_of_elements,int size_in_bytes);
void *xrealloc(int *p_for_realloc , int size_in_bytes);


void dyn_allocate_int();
void dyn_allocate_int_array();
void dyn_allocate_pointer_to_int_array();


void dyn_allocate_struct();
void dyn_allocate_sturct_array();
void dyn_allocate_pointer_to_struct_array();


struct date
{
    int day;
    int month;
    int year;
};

int main(void)
{
    
    dyn_allocate_pointer_to_int_array();
    dyn_allocate_pointer_to_struct_array();
    exit(0);
}

void *xmalloc(int size_in_bytes)
{
    int *p = (int *)malloc(sizeof(size_in_bytes));
    if(!p)
    {
        printf("could not allocate the memory using malloc");
        exit(-1);       
    }
    return p;
}

void *xcalloc(int num_of_elements,int size_in_bytes)
{
    int *p = (int *)calloc(num_of_elements , sizeof(size_in_bytes));
    if(!p)
    {
        printf("could not allocate the memory using malloc");
        exit(-1);       
    }
    return p;
}

void *xrealloc(int *p_for_realloc , int size_in_bytes)
{
    int *p = (int *)realloc(p_for_realloc , size_in_bytes);
    if(!p)
    {
        printf("could not allocate the memory using malloc");
        exit(-1);       
    }
    return p;
}

void dyn_allocate_int()
{
    int *p = NULL;
    int  n = 1;
    p =  (int *)xcalloc(1, sizeof(int));

    *p = 1;
    n = *p;

    free(p);    
    
}

void dyn_allocate_int_array()
{
    int *p = (int *)xcalloc(N , sizeof(int));

    for(int i=0; i<N ; i++)
    {
        *(p+i) = i*10;
    }

    for(int i=0;i<N;i++)
    {
        printf("value of an array element = %d \n" , p[i]);
    }

    free(p);

    p = NULL;
}


void dyn_allocate_pointer_to_int_array()
{
    int **p = (int **)xcalloc(N , sizeof(int *));
        
    for(int i=0;i<N ; i++)
    {
        p[i] = (int *)xcalloc(1 , sizeof(int)); 
    }

    for(int i=0;i<N ; i++)
    {
        *p[i] = i+10 ; 
    }

    for(int i=0;i<N ; i++)
    {
        printf("value of an array element = %d \n" , *p[i]);
   }   

}
void print_date(struct date *s_p)
{
    printf("%d:%d:%d \n" , s_p->day,s_p->month, s_p->year);
}
void dyn_allocate_struct()
{
    struct date *s_p = (struct date *)xcalloc(1, sizeof(struct date));

    s_p->day   = 20;
    s_p->month = 07;
    s_p->year  = 1987;

    print_date(s_p);
}

void dyn_allocate_sturct_array()
{
    struct date *s_p = (struct date *)xcalloc(N, sizeof(struct date));

    s_p->day   = 20;
    s_p->month = 07;
    s_p->year  = 1987;

    for(int i=0;i<N ;i++)
    {
        print_date(&s_p[i]);
    }
}

void dyn_allocate_pointer_to_struct_array()
{
    struct date **s_p = (struct date **)xcalloc(N, sizeof(struct date *));


    for(int i=0;i<N ;i++)
    {
        s_p[i] = (struct date *)xcalloc(1,sizeof(struct date));
    }

    for(int i=0;i<N ;i++)
    {
        s_p[i]->day   = 20;
        s_p[i]->month = 07;
        s_p[i]->year  = 1987;
    }

    for(int i=0;i<N ;i++)
    {
        print_date(s_p[i]);
    }
}