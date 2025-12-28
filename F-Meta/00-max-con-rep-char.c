/*Problem Definition: Find Maximum Consecutive Repeating Character Count in a String
Objective:
To find the maximum number of consecutive occurrences of the same character in a given string using two different approaches:

Without using additional memory (hashing)

Using a hash table (frequency count of characters)

Problem Statement:
Given an input string consisting of lowercase or uppercase English letters, your task is to determine the maximum number of times any character appears consecutively in the string.

Input:
A null-terminated character array (string) in_str of size n (where 1 ≤ n ≤ 10^5), for example:

cpp
Copy
Edit
char in_str[] = "aabbbccccc";
Output:
An integer representing the maximum count of any character appearing consecutively in the input string.

Examples:
Input String	Output
"aabbbccccc"	5
"aab"	        2
"abb"	        2
"abc"	        1
"aaAAaa"	    2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCCI_VALUES 256

int max_con_rep_char(char *in_str)
{
    int len = strlen(in_str);

    int result = 0;
    int uc_char_cnt = 0;
    char uc = in_str[0];
    
    for(int i = 0;i<len;i++)
    {
        printf("processing .. %c \n", in_str[i]);
        if(uc == in_str[i])
        {
            uc_char_cnt++;
            if(uc_char_cnt > result)
                result = uc_char_cnt;
        }
        else
        {
            uc = in_str[i];
            uc_char_cnt = 1;
            if(uc_char_cnt > result)
                result = uc_char_cnt;
        }
    }
    
    return result;
}

// char in_str[]="acb"
int max_con_rep_char_using_2_ptr(char *in_str)
{
    int len = strlen(in_str);

    int MaxCount = 0;
    int uc_char_cnt = 0;
    int left = 0;
    int right = 0;
    char left_char;
    char right_char;
    
    while(right < len)
    {
        left_char  = in_str[left];
        right_char = in_str[right];
        if(left_char == right_char)
        {
            right++;
            if(right == len)
            {
                uc_char_cnt = right-left;
            }
        }
        else if((left_char != right_char))
        {
            uc_char_cnt = right-left;
            left = right;
            right++;
        }

        if(uc_char_cnt > MaxCount)
            MaxCount = uc_char_cnt;
    }
    
    return MaxCount;
}


int max_con_rep_char_using_2_ptr_optimized(char *in_str)
{
    int len = strlen(in_str);

    int MaxCount = 0;
    int uc_char_cnt = 0;
    int left = 0;
    int right = 0;
    char left_char;
    char right_char;
    
    while(right < len)
    {
        left_char  = in_str[left];
        right_char = in_str[right];
        if(left_char == right_char)
        {
            right++;
        }
        else if((left_char != right_char))
        {
            left = right;
            right++;
        }

        uc_char_cnt = right-left;
        if(uc_char_cnt > MaxCount)
            MaxCount = uc_char_cnt;
    }
    
    return MaxCount;
}

int max_con_rep_char_using_2_ptr_optimized_with_char(char *in_str)
{
    int len = strlen(in_str);

    int MaxCount = 0;
    int uc_char_cnt = 0;
    int left = 0;
    int right = 0;
    char left_char;
    char right_char;
    
    while(right < len)
    {
        left_char  = in_str[left];
        right_char = in_str[right];
        if(left_char == right_char)
        {
            right++;
        }
        else if((left_char != right_char))
        {
            left = right;
            right++;
        }

        uc_char_cnt = right-left;
        if(uc_char_cnt > MaxCount)
            MaxCount = uc_char_cnt;
    }
    
    return MaxCount;
}

int max_con_rep_char_using_hash_key(char *in_str)
{
    int len = strlen(in_str);
    int hash[ASCCI_VALUES] = {0};
    int maxCount=0;
    int consecutive_count=1;
    char current_char = in_str[0];
    int MaxCount = 1;
    
    for(int i = 0;i<len;i++)
    {
        // printf("processing .. %c \n", in_str[i]);
        unsigned char ch = in_str[i];
        hash[ch]++;
        printf("processing .. %u \n", hash[ch]);

        if(in_str[i] == current_char)
        {
            MaxCount++;
            if(MaxCount < in_str[i])
                
                current_char = in_str[i];
        }
        else
        {
            
        }
        // if((in_str[i] == current_char) && (hash[ch] > consecutive_count))
        // {
        //     consecutive_count++;
        //     if(MaxCount < consecutive_count)
        //     {
        //         MaxCount = consecutive_count;
        //     }
        // }
        // else
        // {
        //     hash[ch] = 0;
        //     consecutive_count = 1;
        // }            
    }
    return consecutive_count;
}

int main()
{

    // char in_str[]="aabbbccaaa";
    // char in_str[]="";
    // char in_str[]="abbcccaa";
    // char in_str[] ="abb";
    char in_str[] ="aab";
    printf("max_con_rep_char = %d\n", max_con_rep_char_using_2_ptr_optimized(in_str));
    // printf("max_con_rep_char = %d\n", max_con_rep_char_using_hash_key(in_str));

    return 0;
}