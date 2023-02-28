#include <stdio.h>
#include <stdlib.h>

void some_alloc()
{
    int* ptr = malloc(sizeof(int));
    if (*ptr == 42)
    {
        printf("The value is 42.\n");
    }
    else
    {
        printf("The value is not 42.\n");
    }

    free(ptr);

}

int main(void)
{
    some_alloc();
    return 0;
}
