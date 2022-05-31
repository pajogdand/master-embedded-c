#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

char *get_power_array(int k , int po)
{

    int len =  k*po;
    char *ret_arr = (char *)malloc(sizeof(char) * (len) +1 );
    
    for(int i=0;i<(len);i++)
    {
        ret_arr[i] = '0';
    }

    for(int i = 0 ; i<po ; i++)
    {
        for(int j=k-1; j>=0 ; j--)
        {
            if (i & (1<<((k-1)-j)) )
            {
                ret_arr[i+j+(i*(k-1))] = '1';
            }
            else{
                ret_arr[i+j+(i*(k-1))] = '0';
            }
        }        
    }
    ret_arr[len] = '\0';
    return ret_arr;
}

bool is_str_equal(char *st , char *ct)
{
    while((*st) != '\0')
    {
        if(*st != *ct)
        {
            return false;
        }
        st++;
        ct++;
    }
    return true;
}

bool hasAllCodes(char * s, int k){

    int po = pow(2 , k);
    char *code_str = get_power_array(k , po);
    if(code_str == NULL) exit(-1);
    int len = k*po;
    
    char *p = s;
    int s_len = 0;
    while(*(p) != '\0')
    {
        s_len++;
        p++;
    }
    int found_count = 0;
    bool ret = false;
    for(int i=0;i<s_len;i=i+2)
    {
        char *st = (char *)malloc(sizeof(char)*(k+1));
        memcpy(st ,s ,sizeof(st));
        st[k] = '\0';
        for(int j=0 ; j<len ; j=j+2)
        {
            char *ct = (char *)malloc(sizeof(char)*(k+1));
            memcpy(ct ,code_str ,sizeof(ct));
            ct[k] = '\0';                   
            int ret = is_str_equal(st , ct);
            if (ret == true)
            {
                found_count++;
            }
            if(found_count == po)
            {               
                ret = true;
                return ret;                
            }
            free(ct);
        }

    }
    return ret;
    // free(code_str);
}

int main(void)
{
    int k= 2;
    int po = pow(2 , k);
    // char *p_arr = get_power_array(k , po);
    // for(int i=0;i<po*k;i++)
    // {
    //     printf("%c" , p_arr[i]);
    // }
    char* s = "00110110";

    printf("hasAllCodes = %d" , hasAllCodes(s, k));
    exit(0);
};