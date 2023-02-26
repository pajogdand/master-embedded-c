#include <stdio.h>
#include <stdlib.h>

#define READ "r"
int main()
{
    char *p = "Linux System Programming";

    int *fd = fopen("00-write.txt" , READ);

    if(fd == NULL)
    {
        printf("could not open the file");
    }

    while(*p!=NULL)
    {
        putc(fd)
        
    }
    
}