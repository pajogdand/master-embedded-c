#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int len_of_string(char *a)
{
    return strlen(a);
}

bool is_contain_char(char *a , int len , char t)
{
    while(*a != '\0')
    {
        if(*a == t)
        {
            return true; 
        } 
        a++;
    }
    return false;
}

bool is_contain_number(char *a )
{
    int x;
    while(*a != '\0')
    {
        x = *a - '0';
        for(int i=0;i<10;i++)
        {
         if(x == i)
            return true;         
        } 
        a++;
    }
    return false;    
}

bool is_repeated_char(char *a ,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(a[i] == a[j])
            {
                return true;
            }
        }
    }
    return false;
}

char get_first_repeated_char(char *a ,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(a[i] == a[j])
            {
                return a[i];
            }
        }
    }
    return '0';
}

char num_of_repeated_char(char *a ,int len)
{
    // Assume one char is repeated only once
    int cnt = 0;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(a[i] == a[j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

char get_2nd_repeated_char(char *a ,int len)
{
    int cnt = 0;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(a[i] == a[j])
            {
                cnt++;
                if(cnt == 1) continue;
                if(cnt == 2) return a[i];
            }
        }
    }
    return '0';
}


bool check_if_sub_string_present(char *main_str, int len_main_str , char *sub_str ,int len_sub_str)
{
    int cnt = 0;
    for(int i=0;i<len_main_str;i++)
    {
        if(main_str[i] == sub_str[cnt])
        {
            cnt++;
            if(cnt == len_sub_str) return true;
        }
    }

    return false;
}


int num_of_times_str_repeated(char *main_str, int len_main_str , char *sub_str ,int len_sub_str)
{
    int sub_str_index = 0;
    int sub_str_repeat_cnt = 0;
    for(int i=0;i<len_main_str;i++)
    {
        if(main_str[i] == sub_str[sub_str_index])
        {
            sub_str_index++;
            if(sub_str_index == len_sub_str)
            {
                sub_str_index = 0;
                sub_str_repeat_cnt++;
            }
        }
    }
    return sub_str_repeat_cnt;
}

int main(void)
{
    char *a = "pravin";
    char *b = "pravi1";
    char *c = "pravap";

    printf("%s \n" , a);

    int l = len_of_string(a);
    printf("lengh of a string = %d\n" , l);

    printf("is_contain_char = %d \n" ,is_contain_char(a ,l, 'a'));
    printf("is_contain_char = %d \n" ,is_contain_char(a ,l, 'z'));

    printf("is_contain_number = %d \n" ,is_contain_number(a));
    printf("is_contain_number = %d \n" ,is_contain_number(b));

    printf("is_repeated_char = %d \n" ,is_repeated_char(a , l));
    printf("is_repeated_char = %d \n" ,is_repeated_char(c , l));

    printf("get_first_repeated_char = %c \n" ,get_first_repeated_char(a , l));
    printf("get_first_repeated_char = %c \n" ,get_first_repeated_char(c , l));

    printf("num_of_repeated_char = %d \n" ,num_of_repeated_char(a , l));
    printf("num_of_repeated_char = %d \n" ,num_of_repeated_char(c , l));

    printf("get_2nd_repeated_char = %c \n" ,get_2nd_repeated_char(a , l));
    printf("get_2nd_repeated_char = %c \n" ,get_2nd_repeated_char(c , l));

    
    
    //Finding sub_string within main_string
    char *main_str =  "jogpravinjogdandjog";
    char *sub_str = "jog";

    len_of_string(a);
    int  len_main_str = len_of_string(main_str);
    int len_sub_str   =  len_of_string(sub_str);
    printf("check_if_sub_string_present = %d \n" ,\
    check_if_sub_string_present(main_str,len_main_str,sub_str, len_sub_str));

    printf("num_of_times_str_repeated = %d \n" ,\
    num_of_times_str_repeated(main_str,len_main_str,sub_str, len_sub_str));      

    
    exit(0);
}