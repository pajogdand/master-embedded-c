#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //array which is going to hold the 3 variables int *
    int *p_arr[3];    

    int n1 = 10;
    int n2 = 20;
    int n3 = 30;

    printf("Before : n1 = %d , n2 = %d , n3 =%d \n");
    p_arr[0] = &n1;
    p_arr[1] = &n2;
    p_arr[2] = &n3;

    *p_arr[0] = 100 , *p_arr[0] =200 ; *p_arr[0] =300;
    printf("Before : n1 = %d , n2 = %d , n3 =%d \n");

    // pointer to an array
    int arr[3] = {1,3,5};
    int (*p)[3];

    p =  &arr;
    
    for(int i=0;i<3;i++)
    {
        printf("arr[%d] = %d" , i,arr[i]);
    }
    
    printf("\n");
    for(int i=0;i<3;i++)
    {
        (*p)[i] = arr[i]*10;
    }
    printf("\n");
    for(int i=0;i<3;i++)
    {
        printf("arr[%d] = %d" , i,arr[i]);
    }

    exit(0);

}