#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

char* allocate_string(long long int size); 
int cpa_strcpy(char* p_dest, const char* p_src); 
long long int cpa_strlen(const char* p); 
int cpa_strcat(const char* p_str_1, const char* p_str_2, char** pp_str, long long int* p_size);

// reverse the chars from i to j 
int make_string_range_reverse(char* p_str, long long int len, long long int i, long long int j);

// clone a string range from i to j - 1 and return it via pp_str
int get_substring_by_range(const char* p_str, long long int i, long long int j, char** pp_str, 
                            long long int* p_size); 
int get_substring_by_slice(const char* p_str, long long int i, long long int j, long long int k, 
                            char** pp_str, long long int* p_size); 
int is_substring(char* p_str, const char* substr); 

int count_substring_occurrences(const char* p_str, const char* p_substr); 



void test_strcat(void); 
void test_make_string_range_reverse(void); 
void test_get_substring_by_range(void); 
void test_is_subtring(void); 

int main(void)
{
    char* p_src = "Core Programming Academy"; 
    char* p_dest = NULL; 
    long long int src_len = 0; 
    int ret; 

    src_len = cpa_strlen(p_src); 
    printf("src_len = %lld\n", src_len); 

    p_dest = calloc(1, src_len+1); 
    assert(p_dest); 

    ret = cpa_strcpy(p_dest, p_src); 
    assert(ret == 1); 
    printf("p_dest = %s\n", p_dest); 

    free(p_dest); 
    p_dest = NULL; 

    test_strcat(); 
    test_make_string_range_reverse(); 
    test_get_substring_by_range(); 
    test_is_subtring(); 

    return (0); 
}

char* allocate_string(long long int size)
{
    assert(size > 0); 
    return ((char*)calloc(1, size)); 
}

int cpa_strcpy(char* p_dest, const char* p_src)
{   
    // assumption: p_dest contains a valid address 
    // of array whose length is at least as long as 
    // len(p_src) + 1
    long long int i; 

    for(i = 0; *(p_src + i) != '\0'; ++i)
        p_dest[i] = p_src[i]; 

    p_dest[i] = '\0'; 

    return (1); 
}

long long int cpa_strlen(const char* p)
{
    long long int i = 0; 

    while(*(p+i) != '\0')
        i = i + 1; 

    return (i); 
}

int cpa_strcat(const char* p1, const char* p2, char** pp_str, long long int* p_size)
{
    long long int len_1, len_2, len_total; 
    int ret; 
    char* p_cat = NULL; 

    len_1 = cpa_strlen(p1); 
    len_2 = cpa_strlen(p2); 
    len_total = len_1 + len_2 + 1; 

    p_cat = (char*)calloc(1, len_total); 
    assert(p_cat != NULL); 

    ret = cpa_strcpy(p_cat, p1); 
    assert(ret); 
    ret = cpa_strcpy(p_cat + len_1, p2); 
    assert(ret); 

    *(p_cat + len_total - 1) = '\0'; 

    *pp_str = p_cat; 
    *p_size = len_total - 1; 

    return (1); 
}

int make_string_range_reverse(char* p_str, long long int len, long long int i, long long int j)
{
    long long int mid;
    long long int cnt; 
    char tmp; 

    assert(0 <= i && i < len && 0 <= j && j < len && i < j);
    mid = (j-i+1)/2; 
    for(cnt = 0; cnt < mid; ++cnt)
    {
        tmp = p_str[i+cnt]; 
        p_str[i+cnt] = p_str[j-cnt]; 
        p_str[j-cnt] = tmp; 
    }
    
    return (1); 
}

int get_substring_by_range(const char* p_str, long long int i, long long int j, 
                            char** pp_str, long long int* p_size)
{
    long long int range_len; 
    long long int len; 
    long long int k; 
    char* p_range_str= NULL; 

    len = cpa_strlen(p_str); 
    assert(0 <= i && i < len && 0 <= j && j < len && i < j);

    range_len = j - i; 
    p_range_str = (char*)calloc(1, range_len + 1); 
    assert(p_range_str != NULL); 

    for(k = 0; k < range_len; ++k)
        p_range_str[k] = p_str[i + k]; 
    *(p_range_str+k) = '\0'; 

    *pp_str = p_range_str; 
    *p_size = range_len; 

    return (1); 
}

int is_substring(char* p_str, const char* substr)
{ 
    long long int i, j;
    long long int len_substr, len_str; 
    int flag; 

    len_str = cpa_strlen(p_str); 
    len_substr = cpa_strlen(substr); 

    for(j = 0; j < len_str - len_substr; ++j)
    {
        flag = 1; 
        
        for(i = 0; substr[i] != '\0'; ++i)
        {
            if(p_str[j+i] != substr[i])
            {
                flag = 0; 
                break; 
            }
        }

        if(flag)
            return (1); 
    } 

    return (0); 


}

void test_strcat(void)
{
    char* p1 = "Hello"; 
    char* p2 = "World"; 
    char* p3 = NULL; 
    long long int len; 
    int ret; 
    long long int i; 

    ret = cpa_strcat(p1, p2, &p3, &len);
    assert(ret == 1); 
    puts("-------------------------------------"); 
    for(i = 0; i < len; ++i)
        printf("p3[%lld]:%c\n", i, p3[i]); 
    puts("-------------------------------------"); 
    free(p3); 
    p3 = NULL; 
}

void test_make_string_range_reverse(void)
{
    char* p = "Core Programming Academy"; 

    printf("p = %s\n", p); 
    make_string_range_reverse(p, cpa_strlen(p), 5, 15); 
    printf("p = %s\n", p); // output: Core gnimmargorP Academy 
    make_string_range_reverse(p, cpa_strlen(p), 5, 15); 
    printf("p = %s\n", p); // output: Core Programming Academy
}

// [a, b] | a <= n <= b. How many n's are there? b-a+1
// (a, b] | a < n <= b. How many n's are thre? b - a 
// [a, b) | a <= n < b. How many n's are there? b - a 
// (a, b) | a < n < b. How many n's are there? b - a - 1 

void test_get_substring_by_range(void)
{
    char* p = "Core Programming Academy"; 
    long long int len; 
    char* p_str = NULL; 
    int ret; 

    puts("In test_get_substring_by_range():"); 
    ret = get_substring_by_range(p, 5, 16, &p_str, &len); 
    assert(ret); 
    printf("p_str = %s\n", p_str); 
    
    free(p_str);    
    p_str = NULL; 
}

void test_is_subtring(void)
{
    int ret; 
    char* p_str = "Core Programming Academy"; 
    char* p_substr_1 = "Programming"; 
    char* p_substr_2 = "mm"; 
    char* p_substr_3 = "Acad"; 
    char* p_substr_4 = "XYZ"; 
    char* p_substr_5 = "P"; 

    printf("p_str:Core Programming Academy\n"); 
    ret = is_substring(p_str, p_substr_1); 
    assert(ret == 1); 
    puts("1:Programming:YES"); 

    ret = is_substring(p_str, p_substr_2); 
    assert(ret == 1); 
    puts("2:mm:YES"); 

    ret = is_substring(p_str, p_substr_3); 
    assert(ret == 1); 
    puts("3:Acad:YES"); 

    ret = is_substring(p_str, p_substr_4); 
    assert(ret == 0); 
    puts("4:XYZ:NO"); 

    ret = is_substring(p_str, p_substr_5); 
    assert(ret == 1); 
    puts("5:P:YES"); 
}