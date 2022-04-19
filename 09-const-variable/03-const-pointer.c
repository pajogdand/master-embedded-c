#include <stdlib.h>
#include <stdlib.h>

int main(void)
{
    int n =10;
    const int *p = &n;
    // p is a (read/write)pointer to const int
    int n1 = 100; 
    // *p = 123; this is not allowed
    p = &n1; // this is allowed

    int m=10;
    int *const p1 = &m;
    // p1 is const pointer (read/write) int
    *p1 =1000; // this is allowed 
    //p1 = &m; // this is not allowed



    exit(0);
}