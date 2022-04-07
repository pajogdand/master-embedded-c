#include <stdio.h>
#include <conio.h>

struct employee
{
 double hourlySalary;
 unsigned int age;
 union
 {
  char eid[20];
  unsigned int enm;
 }eid;
 struct employee person;
};

int main(void)
{
    return  0;

    printf("size of struct = %d  " ,sizeof(struct employee));

}