#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 1. declare pointer to an int
    int *p;

    // 2. declare an array  5 of int
    int ap[5];

    //3. declare the array 5 of pointer to int
    int *arr[5];    

    //  declare an array 5 of pointers to function accepting two ints and returning int 

/*
1.  Declare an array 5 of:    arr[5]; 
2.  Declare an array 5 of pointers:     *arr[5] 
3.  Declare an array 5 of pointer to function:      (*arr[5])()
4.  Declare an array 5 of pointer to function accepting two ints 
    (*arr[5])(int, int)
5.  Declare an array 5 of pointer to function accepting two ints and returning int 

    int (*arr[5])(int, int); 
*/ 
// #--------------------------------------------------

/* 
    Declare a pointer to array of pointer to function accepting two ints 
    and returning an integer 
            int (*(*p)[5])(int, int); 
*/ 

/* 
    Signal is a function which accepts 
        1) int 
        2) pointer to a function 
                which accepts 
                    i) an integer 
                returns 
                    nothing 
    returns 
        pointer to a function 
            which accepts 
                int 
            returns 
                nothing 
*/ 

// void(*)(int) signal (int, void(*)(int));

// signal()
// signal(int, )
// signal(int, *)
// signal(int, (*)() )
// signal(int, void(*)(int)); 

//  *signal(int, void(*)(int)); 
//  void (*   signal  (int,   void(*)(int)))(int); 

/* 
void(*  signal( int, void(*)(int)    )   )(int)

T1 -> int 
T2 -> void (*)(int)

T2 signal(T1, T2)
void (*signal(int, void(*)(int)))(int); 
*/ 


    exit(0);
}