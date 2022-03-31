#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Date * create_date(int init_day, int init_mon , int int_year);
int is_date_valid(int dd , int mm , int yy);
int get_day(struct Date *pData );
int get_month(struct Date *pData );
int get_year(struct Date *pData );
int set_day(struct Date *pData , int new_day );
int set_month(struct Date *pData , int new_month);
int set_year(struct Date *pData , int new_year);
int set_date(struct Date *pData , int mew_data);
int print_date(struct Date * pData);
int is_leap_year(int year);
void destroy_date(struct Date** ppdate);

int main(void)
{
    int dd,mm,yy;

    int ret;

    struct Date *mydate = create_date(30 ,3,2022);
    print_date(mydate);
    mydate->day   = 31;
    mydate->month = 1;
    mydate->year  = 2022;
    print_date(mydate);
    destroy_date(&mydate); 
    if(mydate == 0)
    {
        puts("mydate has allready been destroyed");
    }
    
}

void destroy_date(struct Date **ppdate)
{
    // struct Date *pdate_to_dst = *pdate;
    // free(pdate_to_dst);
    // pdate_to_dst = 0;
    // *pdate = 0;
    free(*ppdate);
    *ppdate = 0;

}

int is_leap_year(int year)
{
    if ( (year%4) !=0  )
    {
        return (0);
    }
    if ( (year%100 == 0 ) && (year% 400 != 0) )
    {
        return (0);
    }
    return (1);

}

int get_day(struct Date *pData)
{
    return pData->day;
}
int get_month(struct Date *pData)
{
    return pData->month;
}

int get_year(struct Date *pData)
{
    return pData->year;
}

int set_day(struct Date *pData , int new_date)
{
    if (is_date_valid(pData->day , pData->month , pData->year) == 1)
    {
        return 0;
    }
    pData->day = new_date;
}

int set_month(struct Date *pData , int new_month)
{
    if (is_date_valid(pData->day , pData->month , pData->year) == 1)
    {
        return 0;
    }
    pData->month = new_month;
}

int set_year(struct Date *pData , int new_year)
{
    if (is_date_valid(pData->day , pData->month , pData->year) == 1)
    {
        return 0;
    }
    pData->year = new_year;
}

int print_date(struct Date *pdate)
{
    printf("%d::%d::%d",pdate->day , pdate->month , pdate->year );
    printf("\n");    
}

int is_date_valid(int dd , int mm , int yy)
{
    return 1;
}

struct Date * create_date(int init_day , int init_mon , int int_year)
{
    struct Date * p_new_date = 0;
    int ret;

    ret = is_date_valid(init_day, init_mon ,int_year );

    if (ret == 0)
    {
        return (0);
    }
    
    p_new_date = (struct Date *)malloc(sizeof(struct Date));
    if (p_new_date == 0)
    {
        printf("unable to allocate memory\n");
        exit(-1);
    }

    p_new_date->day   = init_day;
    p_new_date->month = init_mon;
    p_new_date->year  = int_year;

    return p_new_date;
    
}

int set_date(struct Date *pData , int mew_data)
{

}

