#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n = 100;
    const int *const p = &n;
    int m = 10;

    // *p  = 100; not allowed
    // p = &m;    not allowed

    exit(0);
}