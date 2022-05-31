#include <stdio.h>
#include <stdlib.h>

int my_fun(int, int);
void insertion_sort(int* p_arr, int size)
{
    puts("Insertion sort"); 
}


void ptr_to_fun(void)
{
    void (*pfn)(int*, int); 
    pfn = insertion_sort; 
    pfn(NULL, 0); 
}


int main()
{

    // int (*p_my_fun)(int , int);

    // p_my_fun = &my_fun;

    // int z = p_my_fun(2,4);

    // printf("result = %d" , z);

    // declare an array of 5 of pointers to function accepting 2 ints and returning int

    // declare an array of 5 : arr[5]
    // declare an array of 5 of pointes  : *arr[5]
    //  declare an array of 5 of pointes an function : (*arr[5])()
    // declare an array of 5 of pointers to function accepting 2 ints and returning int :
    // int (*arr[5])(int, int)

    (*ptr_to_fun)();
    exit(0);   

}

int my_fun(int x, int y)
{
    return (x+y);
}