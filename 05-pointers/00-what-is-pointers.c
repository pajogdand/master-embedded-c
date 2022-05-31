#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x = 10;

  int *p  = NULL;

  p = &x;

  printf("*p = %d\n" , *p);
  printf("*p = %llu\n" , p);

}