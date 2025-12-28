#include <stdio.h>
#include <stdlib.h>

// typedef is used for readiability
struct Date
{
    int day;
    int month;
    int year;    
};

struct Date my_birth_date;
typedef int day_t;
typedef int month_t;
typedef int year_t;
typedef int status_t;

typedef struct Date Date_t;

Date_t *create_date(day_t day , month_t month ,year_t year);
day_t get_day(Date_t date);
status_t is_date_valid(Date_t date);

int main(void)
{
     Date_t my_date;

    my_date.day   = 20;
    my_date.month = 07;
    my_date.year  = 1987;

    day_t d;
    month_t m;
    year_t y;

    //DATE_ptr d_p;

    exit(0);
}