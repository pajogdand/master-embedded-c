#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i, j, k;
    int flag1, flag2; 

    for(i = 1; i <= 10; ++i)
    {
        flag1 = 1; 
        for(k = 2; k < i; ++k)
            if(i % k == 0)
                flag1 = 0; 
        
        if(flag1 == 1)
        {
            for(j = 1; j <= 10; ++j)
            {
                flag2 = 1; 
                for(k=2; k < j; ++j)
                    if(j % k == 0)
                    {
                        flag2 = 0; 
                        break; 
                    }
                if(flag2 == 0)
                    printf("Prime(i=%d), Composite(j=%d)\n", i, j); 
            }
        }
    }
    exit(0); 
}