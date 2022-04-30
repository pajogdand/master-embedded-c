#include <stdio.h>
#include <stdlib.h>

// extern void get_size(int *size);
extern void get_array(int *p_array , int size);
extern void input_array(int *p_array , int size);
extern void output_array(int *p_array , int size); 
int main(void)
{
    int size =5;
    int *p_array = NULL;
    
    // get_size(&size);
    get_array(p_array , size);
    //sort_array(p_array , size);
    input_array(p_array , size);
    output_array(p_array , size);
    exit(0);
}