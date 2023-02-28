#include <stdio.h>


#define PI 3.14
#define MAX(x,y) ((x) < (y) ? (y) : (x))

#define inc(x) (x++)

#define print_string(str) ({printf("string = %s\n", str);})

#define print_two_string(s1 ,s2) ({printf( #s1 " sec = %s " , s2);})

#define find_large_in_array(num, array) ({ \
    int i; \
    for(i=0; i<num; i++) \
    {   \
        if(array[i] > array[i+1]) \
        { \
            return array[i]; \
        } \
    } \
} )\

int add(int x, int y)
{
    return x+y;
}
int mul(int x, int y)
{
    return x*y;
}
typedef int(*add_ptr)(int x , int y); 
typedef int(*mul_ptr)(int x, int y);

#define CAL(FUN, X,Y) ((FUN)((X),(Y)))

int main(int argc, char *argv[])
{
    printf("PI = %d\n", PI);

    int a=0, b=8, c=8;
        
    printf("MAX = %d\n", MAX(a, b));
    
    double l =20.5 , m=876.9;
    printf("MAX = %f\n", MAX(l, m));

    printf("inc(x) \n" , inc(a));

    print_string("Pravin");

    print_two_string(pravin , "CProgram");
    
    add_ptr ap = add;
    mul_ptr mp = &mul;
    

    printf("output =%d" ,CAL(ap,4,5));
    
    return 0;
}