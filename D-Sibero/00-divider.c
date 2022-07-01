#include <stdio.h>
#include <stdlib.h>

#define DENOMINATOR_ZERO_ERROR -1
#define MEMORY_ALLOCATION_FAILED -2
#define INVALID_ADDRESS -3

#define TEST_DIVIDER_FUNCTION
typedef struct {
unsigned quotient;
unsigned remainder;
} divider_s;
// Implement (with all possible error checks)
void divide(divider_s* answer, unsigned number, unsigned divide_by);
void print_result(unsigned number, unsigned divide_by , unsigned quotient ,unsigned remainder);

int main()
{
    divider_s *answer = (divider_s *)calloc(1 ,sizeof(divider_s));

    if(NULL == answer)
    {
        printf("ERROR:: MEMORY_ALLOCATION_FAILED :: Memory allocation to answer failed failed\n");
        exit(MEMORY_ALLOCATION_FAILED);
    }
    
    #ifdef TEST_DIVIDER_FUNCTION
        printf("============== TEST CASE 1 ============= \n");
        unsigned number    = 10;
        unsigned divide_by = 2;
        divide(answer,number,divide_by);
        print_result(number, divide_by , answer->quotient ,answer->remainder);

        printf("============== TEST CASE 2 ============= \n");
        number    = 2;
        divide_by = 0;
        divide(answer,number,divide_by);
        print_result(number, divide_by , answer->quotient ,answer->remainder);
    #endif

    if(NULL != answer)
    {
        free(answer);
    }

    exit(0);
}


void divide(divider_s* answer, unsigned number, unsigned divide_by)
{
    //Allocate the memory for ans dyanamically and Make sure that DENOMINATOR is not zero    
    if(NULL == answer)
    {
        printf("ERROR:: INVALID_ADDRESS :: answer should have valid address\n");
        exit(INVALID_ADDRESS);
    }

    //Make sure that DENOMINATOR is not zero
    if(0 == divide_by)
    {
        if(NULL != answer)
            free(answer);
        printf("ERROR:: DENOMINATOR_ZERO_ERROR :: divide_by number must not be 0\n");
        exit(DENOMINATOR_ZERO_ERROR);
    }

    // Perfrom operation to get quotient and remainder
    answer->quotient = number / divide_by;
    answer->remainder = number % divide_by; 
}

void print_result(unsigned number, unsigned divide_by , unsigned quotient ,unsigned remainder)
{
    printf("Result of %u/%u ::  quotient = %u and remainder = %u \n\n" , number,divide_by,
            quotient ,remainder );
}