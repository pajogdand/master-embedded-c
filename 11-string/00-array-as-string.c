#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 255
int main(void)
{
    
    // char a[size]={'p', 'r' , 'a' , 'n' , 'i' , 'n', '\0'};
     // char a[size]={'p', 'r' , '\0' , 'n' , 'i' , 'n', '\0'};
    // printf("%s \n" , a);

    // char a[size]= "pra";
    // printf("%s \n" , a);
    // a[0] = 'P';
    // printf("%s \n" , a);

    // printf("Length of string a = %lu \n" , strlen(a));
    // printf("size of array a = %lu \n" , sizeof(a));

    // char a[] = "pravin";
    // printf("%s \n" , a);
    // a[0] = 'P';
    // printf("%s \n" , a);

    // printf("Length of string a = %lu \n" , strlen(a));
    // printf("size of array a = %lu \n" , sizeof(a));

    // for(int i=0;i<30 ; i++)
    // {   
    //     if(a[i] == '\0')
    //     {
    //         break;
    //     }
    //     printf("a[%d] = %c\n" , i,  a[i]);

    // }

    // for(int i=0; a[i]!='\0' ; i++)
    // {   
    //     printf("a[%d] = %c\n" , i,  a[i]);

    // }
    
    // int i=0;
    // while(a[i] != '\0')
    // {
    //     printf("a[%d] = %c\n" , i,  a[i]);
    //     i++;
    // }

    // a = "Nothing";
    // char a[30]= "pravin";
    // printf("%s \n" , a);    
    // a[0] = 'P';
    // printf("%s \n" , a);
    


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
    // dps = "SomeOtherSting";
    strncpy(dps, "SomeotherStingAndnothing",10);
    printf("dps = %s \n", dps);

    printf("sizeof dps = %lu \n", sizeof(dps));
    printf("len dps = %u \n", strlen(dps));
    
    free(dps);


    exit(0);
}