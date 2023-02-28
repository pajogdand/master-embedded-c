#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp
{
    int id;
    char name[50];
    float salary;
};

// Anonymous struct declaration with a variable emp1
struct 
{
    int id;
    char name[50];
    float salary;
} emp1;

// Typedef for a struct named emp2
typedef struct
{
    int id;
    char name[50];
    float salary;
} emp2;

void set_emp(struct emp *e)
{
    printf("Enter employee ID: ");
    scanf("%d", &(e->id)); // Use & to get the address of id
    printf("Enter employee name: ");
    scanf("%s", e->name);
    printf("Enter employee salary: ");
    scanf("%f", &(e->salary)); // Use & to get the address of salary
}

void print_emp(struct emp *e)
{
    printf("Employee ID: %d\n", e->id);
    printf("Employee Name: %s\n", e->name);
    printf("Employee Salary: %.2f\n", e->salary);
}

int main()
{
    struct emp e;
    set_emp(&e);
    print_emp(&e);

    return 0;
}
