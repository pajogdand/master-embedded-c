#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 8
int main()
{
   int A[] = {1,2,3,60,61,62,63,12,1};

   int sub_len = 1;
   int final_len = 1;

   for(int i=0 ;i<SIZE;)
   {
     for(int j=i;j<SIZE;j++)
     {
        if( (A[j]+1) == A[j+1])
        {
            sub_len++;
        }
        else
        {
            i = j+1;
            if(sub_len > final_len)
            {
                printf("found sub_len = %d\n" , sub_len);
                final_len = sub_len;
            }
            sub_len=1;
            break;
        }        
     }

   }
   
   printf("final_len = %d\n" , final_len);
   exit(0);
}

