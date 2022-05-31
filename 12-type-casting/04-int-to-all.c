#include <stdio.h> 
#include <stdlib.h> 

unsigned int num = 0xa0b0c0d0;

/* 
x   x+1     x+2     x+3 
d0  c0      b0      a0
*/

int main(void)
{
    unsigned int i; 
    unsigned char uc;

    printf("&num = %p " , &num);
    printf("&num + 1  = %p" , ((char*)&num)+1);

    puts("with for loop");
    for(int i =0; i< sizeof(unsigned int) ; i++)
        printf("&num + %d = %p", ((char *)&num) + i );
   

    for(i = 0; i < sizeof(unsigned int); ++i)
        printf("&num + %d = %p\n", i, ((char*)&num) + i); 

    for(i = 0; i < sizeof(unsigned int); ++i)
    {
        uc = *(unsigned char*)(((char*)&num) + i); 
        printf("uc = %hhx\n", uc); 
    }

    for(i = 0 ; i<sizeof(unsigned int) ; ++i)
    {
        printf("address(%p) = %hhx \n" , (unsigned char *)&num + i , *(unsigned char*)((unsigned char *)&num + i));
    }

                
    return (0); 
}

/*  
    unsigned int num = 0xa0b0c0d0; 
(num)
    x   x+1     x+2     x+3 
    d0  c0      b0      a0 

    &num == x 
    type(&num) = int* 
    addr(x)  int* 

    ((char*)&num) + i

    i == 0  x+0
    i == 1  x+1
    i == 2  x+2
    i == 3  x+3

    %hx *(short*)((char*)&num + 1)

    Exercise (unsigned int : user input)

    [   ] -> bit pattern 
    [   ] -> bit pattern 
    [   ] -> bit pattern 
    [   ] -> bit pattern 


    pid_t pid; 
    int ret; 
    int status; 

    pid = fork(); 
    if(pid == 0)
    {
        child process
    }
    else 
    {
        wait(&ret); 
    }

    status = WEXITSTATUS(ret); 

    [   ][  ][  ][  ]

    (int)(*(unsigned char*)((char*)&ret + 1))

#define WEXISTSTATUS(X)  ((int)(*(unsigned char*)((char*)&X + 1)))
*/ 
