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

char* remove_repeated_char(char *main_str, int len_main_str)
{
    char *ret_str = malloc(sizeof(char)*(len_main_str+1)) ;
    for(int i=0;i<len_main_str;i++)
    {
        ret_str[i] = main_str[i];
    }
    for(int i=0;i<len_main_str;i++)
    {
        for(int j=i+1 ;j<len_main_str ; j++)
        {
            if(ret_str[i] == ret_str[j])
            {
                for(int k=j ; k<len_main_str-1 ; k++)
                {
                    ret_str[k] = ret_str[k+1];
                }
                len_main_str--;
            }
        }
    }
    ret_str[len_main_str] = '\0';
    return ret_str;
}

char *reverse_string(char *main_str, int len_main_str)
{
    
    char *rev_str = (char *)malloc((len_main_str+1)*sizeof(char));

    for(int i=len_main_str-1;i>0;i--)
    {
        rev_str[i] = main_str[i];
    }

    return rev_str;
}

char * left_shift_str_char(char* main_str ,int len_main_str)
{
    char *ret_str = (char *)malloc(sizeof(char)*len_main_str);
    int i;
    for(i=0; i<len_main_str ; i++)
    {
        ret_str[i] = main_str[i+1]; 
    }    
    return ret_str;
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
    char *main_str =  "pravinpnz";
    char *sub_str = "jog";

    len_of_string(a);
    int  len_main_str = len_of_string(main_str);
    int len_sub_str   =  len_of_string(sub_str);
    printf("check_if_sub_string_present = %d \n" ,\
    check_if_sub_string_present(main_str,len_main_str,sub_str, len_sub_str));

    printf("num_of_times_str_repeated = %d \n" ,\
    num_of_times_str_repeated(main_str,len_main_str,sub_str, len_sub_str));

    char *left_shifted_str = left_shift_str_char(main_str , len_main_str);
    if(left_shifted_str != NULL)
    {
        printf("check_if_sub_string_present = %s \n" ,left_shifted_str);
        free(left_shifted_str);
    }

    char *repeated_char_removed_str = remove_repeated_char(main_str , len_main_str);
    if(repeated_char_removed_str != NULL)
    {
        printf("remove_repeated_char = %s \n" ,repeated_char_removed_str);
        free(left_shifted_str);
    }
    
    exit(0);
}