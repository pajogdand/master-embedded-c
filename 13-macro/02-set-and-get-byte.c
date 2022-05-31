#include <stdio.h>
#include <stdlib.h>
// set the byte 
// get the byte 


// Macro 1 input 
// integer, size in bytes, byte number to get

// Macro 2 input 
// integer, size int bytes, byte number to set, byte val
#define GET_BYTE(n , N ,k)  ((int)(*(unsigned char*)((char*)&n + ((k)-1))))
#define SET_BYTE(n,N,k)     (((unsigned char*)(char *)&n + ((k) -1))) = v
int main(void)
{
    

}
