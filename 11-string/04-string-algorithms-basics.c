#include <stdio.h>
#include <stdlib.h>


int string_ncompare_cs(const char* p_str_1, const char* p_str_2, long long int n)
{
    // N = min( min(len(str1), len(str2)), n))
    // for(i = 0; i < N; ++i)
    //  compare p_str_1[i] and p_str_2[i]
    //  if the above comparison fails even once then return false 
    //  if the above comparison holds true for all then return true 
}

int string_ncompare_ncs(const char* p_str_1, const char* p_str_2, long long int n)
{
    // N = min( min(len(str1), len(str2)), n))
    // for(i = 0; i < N; ++i)
    //      compare p_str_1[i] and p_str_2[i] (NON-CASE-SENSETIVE COMPARISON)
    //  if(isalpha(p_str_1[i])) 
    //      if(isupper(p_str_1[i]))
    //          p_str_1[i] == toupper(p_str_2[i])
    //      else 
    //          p_str_1[i] == tolower(p_str_2[i])
    //  if the above comparison fails even once then return false 
    //  if the above comparison holds true for all then return true 
}

int string_compare_cs(const char* p_str_1, const char* p_str_2)
{
    //  N = min(len_1, len_2) where len_1 = cpa_strlen(p_str_1)
    //                              len_2 = cpa_strlen(p_str_2)

    //  ret = string_ncompare_cs(p_str_1, p_str_2, N); 
    //  if(ret != 0)  
    //      return ret; 

    //  if(len1 == len2)
    //      return 0; 
    //  else if(len1 > len2)
    //      return 1; 
    //  else 
    //      return -1; 
}

int stirng_compare_ncs(const char* p_str_1, const char* p_str_2)
{
    // same cs version, only, use ncs version of string_ncompare
    //  viz string_ncompare_ncs()
}

int get_concatenated_string(const char* p_str_1, const char* p_str_2, char** pp_str, 
                            long long int* p_cat_length); 
char* string_append(char* p_str, const char* p_append_str, long long int n); 

int string_multiply(char* p_str, long long int n, char** pp_str)
{
    // len = cpa_strlen(p_str)
    //  size = n * len;  
    //  char* p_new_str = malloc(size + 1);
    //  memset(p_new_str, 0, size+1);  
    //  for(i = 0; i < size; i = i + len)
    //      string_ncopy(p_new_str + i * len, p_str, len); 
    //  **pp_str = p_new_str; 
    //  return 1; 
}

int make_string_reverse(char* p_str)
{
    //  N = cpa_strlen(p_str); 
    //  for(i = 0; i < N/2; ++i)
    //      swap -> p_str[i] <-> p_str[N-1-i]; 
}

int get_reversed_string(char* p_str, char** pp_str)
{
    //  N = cpa_strlen(p_str); 
    //  char* p_new_str = (char*)malloc(N+1); 
    //  memset(p_new_str, 0, N+1); 
    //  for(i = N-1; i > -1; i--)
    //      p_new_str[i - N + 1] = p_str[i]
    //  **p_str =  p_new_str; 
}

int string_copy(char* p_destination_str, const char* p_source_string, long long int n)
{
    //  src_len = cpa_strlen(p_source_string); 
    //  N = min(src_len, n) 
    //  for(i = 0; i < N; ++i)
    //      p_destination_str[i] = p_source_string[i]; 
    //  p_destination_str[N] = '\0'; 
    //  return 1 
}

char* clone_string(char* p_str)
{
    //  len_1 = cpa_strlen(p_str); 
    //  char* p_new_string = malloc(len_1 + 1); 
    //  memset(p_new_string, 0, len_1 + 1); 
    //  string_ncopy(p_new_string, p_str, len_1); 
    //  return p_new_string
}

char* get_upper_string(const char* p_str)
{
    // TODO
}

int make_string_upper(char* p_str)
{
    // TODO
}

char* get_lower_string(const char* p_str)
{
    // TODO
}

int make_string_lower(char* p_str)
{
    // TODO
}

char* get_title_case_string(const char* p_str)
{
    // core programming academy 
    //  Core Programming Academy 
    //  core                    programming                      Academy
    //  Core                    Programming                      Academy
}

int make_string_title_case(char* p_str)
{
    int IN = 1; 
    int OUT = 2; 
    int state; 
    long long int i; 
    
    state = OUT; 
    for(i = 0; p_str[i] != '\0'; ++i)
    {
        if(state == OUT && !isspace(p_str[i]))
        {
            state = IN; 
            if(islower(p_str[i]))
                p_str[i] = toupper(p_str[i]); 
        }
        else if(state == IN && isspace(p_str[i]))
        {
            state = OUT; 
        }
    }
}

char* get_lstripped_string(const char* p_str)
{
    //  Start traversing the string from index 0 
    //  Find out the index of first non-white space character 
    //  say N, and let legnth of the string be L 
    //  from Index N to Index L-1, there are L-1 - N + 1 = L - N 
    //  And counting one of \0, total size of dynamic memory allocation 
    //  is L - N + 1 
    //  strncpy(p_new_string, p_str[N], L-N); 
    //  write \0 to index L-N 
    //  return p_new_string  
}

int make_lstripped_string(char* p_str)
{
    //  Start traversing the string from index 0 
    //  Find out the index of first non-white space character 
    //  say N, and let legnth of the string be L  
    //  You shift all characters from from N to L-1 
    //  to 0 to (L-N-1) indices 
    //  realloc(p_str, L-N+1)
    //  write \0 to index L-N 
    //  return SUCCESS 
}

char* get_rstripped_string(const char* p_str)
{
    //  Start traversing the string in the reverse direction 
    //  Find out the index of last non-white-space character 
    //  say N 
    //  Index 0 to Index N is the exepected output 
    //  length of the string is N+1 
    //  Dynamic memory allocation is N+2 (one for \0)
    //  Allocate string of N+2 chars 
    //  strncpy(p_new_string, p_str, N+1); 
    //  *(p_new_string + N + 1) = '\0'; 
    //  return p_new_string  
}

int make_rstripped_string(char* p_str)
{
    //  Start traversing the string in the reverse direction 
    //  Find out the index of last non-white-space character 
    //  say N 
    //  realloc(p_str, N+2); 
    //  If last non-white space character is at index N 
    //  then length of the string (ommitting \0) is N+1 
    //  Counting one extra character for \0 
    //  the length becomes N+2 
    //  realloc to N+2 and write \0 to the last char 
    //  i.e. at index N+1 
}

char* get_stripped_string(const char* p_str)
{
    //  start_index : Position it to the first non white space character from start 
    //  end_index : Position it to the first nonwhite space character from end 
    //  L = end_index - start_index + 1 
    //  if L == 0: return NULL 
    //  p_new_str = malloc(L+1)
    //  strncpy(p_new_str, p_str[start_index], L)
    //  p_new_str[L] = '\0' 
    //  return p_new_str; 
}

int make_stripped_string(char* p_str)
{
    //  make_rstripped_string(p_str)
    //  make_lstripped_string(p_str)
    //  return success 
}

char* get_case_swapped_string(const char* p_str)
{
    // refer the following strategy of make_string_case_swapped() 
    //  use the same strategy, only deploy the output in new string 
    //  characters in p_str which are not alphabets should be copied 
    //  to new string 

}

int make_string_case_swapped(char* p_str)
{
    //  L = cpa_strlen(p_str)
    //  for(i = 0; i < L; ++i)
    //  {
    //      if(islower(p_str[i]))
    //          p_str[i] = toupper(p_str[i]); 
    //      else if(isupper(p_str[i]))
    //          p_str[i] = tolower(p_str[i])
    //  } 
}

int join(const char** pp_strings, long long int nr_of_strings, const char* p_sep,  char** pp_joined_str) 
{
    //  Let there be N (= number of strings) in pp_strings 
    //  for first N-1 strings 
    //      p_str = pp_strings[i] + p_sep // use string builder 
    //  append pp_strings[N-1] at the end 
    //  puts \0 at last 
    //  *pp_joined_str = p_str 
    //  return 1 
}

int startswith(const char* p_str, const char* p_prefix_str)
{
    // check if p_prefix_str is substring of p_str at index 0 
    //  if yes then return success (True)
    //  if no then return (False)   
}

int endswith(const char* p_str, const char* p_suffix_str)
{
    //  Let L be the length of p_str 
    //  Ls be the length of the suffix string 
    //  I = L-1-Ls 
    //  check if p_suffix_str is a substring of p_str at index 'I'
    //  if yes then return True 
    //  else return False 
}

int remove_prefix(char* p_str, char* p_prefix)
{
    //  Check if p_prefix is a prefix of p_str (by using startswith() function)
    //  if No then return invalid prefix error 
    //  if yes then 
    //  Let L be the length of p_str 
    //  Let Lp be a length of the prefix. 
    //  MOVE Characters from index Lp to L-1, to 0 to L-1-Lp 
    //  realloc(p_str, L-Lp+1)
    //  put '\0' at end 
    //  return SUCCESS 
}

int remove_suffix(char* p_str, char* p_suffix)
{
    //  Check if p_suffix is a suffix of p_str using endswith() function 
    //  if No then return invalid suffix error 
    //  Let L be the length of the string 
    //  Let Ls be the length of the suffix 
    //  realloc(p_str, L-Ls+1)
    //  p_str[L-Ls] = '\0'
    //  return True 

}

int is_string_alpha(const char* p_str);         //  check if all are alphabets 
int is_string_digit(const char* p_str);         //  check if all are digits 
int is_string_alnum(const char* p_str);         //  check if all are alphabets or digits 
int is_string_decimal(const char* p_str);       //  check if all are between '0' to '9'(first digit cannot be '0')
int is_string_identifier(const char* p_str);    //  Check if the first character is alphabet or _ 
                                                //  abd the rest of chars must be alnum or _ 
int is_string_lower(const char* p_str);         //  check if all alphabets in p_str are lower case 
int is_string_upper(const char* p_str);         //  check if all alphabets in p_str are upper case 
int is_string_title(const char* p_str);         //  Make sure that whie transiting from outside word to inside 
                                                //  word, the first character encountered if alphabet is an uppercase 
                                                //  alphabet 
int is_string_printable(const char* p_str);     //  Make sure that all are printable


int main()
{
    char *p_str = "pravin10123P" 
    is_string_alpha(p_str);         //  check if all are alphabets 
    exit(0);
}

int is_string_alpha(const char* p_str)
{
    int i=0;
    while (p_str[i] != 0 )
    {
        if(p_str[i] = 
        i = i+1;
    }
        
}

