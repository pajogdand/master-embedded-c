#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

int is_date_valid(int dd , int mm , int yy);
int get_day(struct Date *pData );
int get_month(struct Date *pData );
int get_year(struct Date *pData );
int set_day(struct Date *pData );
int set_month(struct Date *pData );
int set_year(struct Date *pData );
int set_date(struct Date *pData , int mew_data);



int main(void)
{
    int dd,mm,yy;

    int ret;

    struct Date *mydate = 0;
    mydate = malloc(sizeof(struct Date));

    mydate->day   = 20;
    mydate->month = 07;
    mydate->year  = 1987;
    
    
}

int set_date(struct Date *pData , int mew_data)
{

}

