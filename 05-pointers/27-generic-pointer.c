#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emp
{
    int id;
    char name[50];
} emp_t;

void set_emp(emp_t *e)
{
    e->id = 1;
    strcpy(e->name, "John Doe");
}

emp_t* create_emp()
{   
    emp_t* e = (emp_t*)malloc(sizeof(emp_t));
    return e;
}

void print_emp(emp_t *e)
{
    printf("ID: %d\nName: %s\n", e->id, e->name);
}

void set_gen_emp(unsigned char *e)
{
    emp_t *e_g = (emp_t *)e;  // Correctly cast the buffer
    e_g->id = 1;
    strcpy(e_g->name, "John Doe");
}

void print_buffer(unsigned char *buffer, size_t size)
{
    emp_t *e_from_buffer = (emp_t *)buffer;
    printf("ID: %d\nName: %s\n", e_from_buffer->id, e_from_buffer->name);
    printf("\n");
}

int main()
{
    emp_t *e = create_emp();
    if (e == NULL) {
        printf("Error in creating emp");
        return -1;
    }
    set_emp(e);
    print_emp(e);
    if (e != NULL) {
        free(e);
    }

    unsigned char buffer[sizeof(emp_t)];
    set_gen_emp(buffer);
    print_buffer(buffer, sizeof(emp_t));

    return 0;
}

