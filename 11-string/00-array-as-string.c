#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 7
int main(void)
{
    // char a[size]={'p', 'r' , 'a' , 'n' , 'i' , 'n', '\0'};
    // char a[size]= "pravin";
    // a = "Nothing";
    // char a[30]= "pravin";
    // printf("%s \n" , a);    
    // a[0] = 'P';
    // printf("%s \n" , a);
    
    // for(int i=0;i<30 ; i++)
    // {
    //     printf("a[%d] = %c\n" , i,  a[i]);
    // }

    // printf("%s \n" , a);
    // char a[30]= "pravin";   
    // printf("%s \n" , a);

    
    // char *ch = "Something";
    // char *ch_ptr = ch;
    // while(*ch_ptr != '\0')
    // {
    //     printf("%c\n" ,*ch_ptr);
    //     ch_ptr++;
    // }
    // printf("%s \n" , ch);
    // ch[0] = 'N';
    // printf("%s \n" , ch);

    // ch = "Nothing";
    // printf("%s \n" , ch);

    // // printf("%s \n" , cp);

    // cp++;
    // // a++;

    // printf("%s \n" , cp);


    // char *sp = "Something";
    // sp = "SomeotherSting";
    // printf("%s \n" , sp);

    char *dps = (char *)malloc(sizeof(char)*10);    
    // dps = "Some";
    strncpy(dps, "SomeotherStingAndnothing",10);
    printf("dps = %s \n", dps);
    
    free(dps);


    exit(0);
}