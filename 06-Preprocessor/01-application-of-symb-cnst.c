#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define SIZE_OF_ARRAY 5
#define DATA_FOUND TRUE
#define DATA_NOT_FOUND FALSE

int is_even(int);
int is_element_in_array(int *p, int  );
int main(void)
{
    
    if(is_even(21))
    {
        printf("Numbeer is even \n");
    }
    else
    {
        printf("number is odd \n");
    }

    //=====================
    exit(0);
}

int is_even(int x)
{
    
    if(x % 2 == 0)
    {
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int is_element_in_array(int *p , int size)
{


}