#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const long int x_global =0x1112131415;

int main()
{
    
    //Method 1
    char str[] = "Hello";
    printf("str: %s\n", str);
    str[0] = 'M';
    printf("str: %s\n", str);

    //Method 2
    char *str2 = "Hello";
    printf("str2: %s\n", str2);
    // This will give issues, since char *str2 is poining to string which is readonly
    // str2[0] = 'M';
    printf("str2: %s\n", str2);
    // This will give issues, since char *str22 is poining to string which is readonly
    // char *str22 = str2;
    // str22[0] = 'M';
    // printf("str2: %s\n", str2);
    // This will work
    const long int x =0x1112131415;
    long int *xp = (long int*)&x;
    *xp = 2;    
    printf("x : %ld\n", x);

    // This will give issues, x_global is stored in in BSS read only segment same as that of str2
    long int *xp = (long int*)&x_global;
    *xp = 2;    
    printf("x : %ld\n", x);
    

    //Method 3
    char *str3 = (char *)malloc(sizeof(char) * 1000);
    if(str3 == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    strcpy(str3, "Hello");
    str3[0] = 'M';
    printf("str3: %s\n", str3);
    
    if(str3!= NULL) { free(str3); str3 = NULL;}
    
    return 0;
}