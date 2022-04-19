#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

// here const struct date *d_p = &dp;
void show_date(const struct Date *d_p)
{
    //d_p->day = 10;
    // this will not work since data type of d_p is const struct Date and not struct Date
    // in short it is just read only

    printf("day = %d" , d_p->day);
}

int main(void)
{

    struct Date d = {20, 07 , 1987};
    show_date(&d);
    exit(0);
}