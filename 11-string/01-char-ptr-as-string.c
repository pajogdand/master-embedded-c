#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 7
int main(void)
{
    char A[] = "Nothing";
    A[0] = 'S';
    printf("%s \n" , A);

    char *B = "Something";
    // B[0] = 'N';

    for(int i=0;i<size ; i++)
    {
        printf("%c \n" , B[i]);
    }

    printf("%s \n" , B);
    
    exit(0);
}