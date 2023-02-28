#include <stdlib.h>

int main()
{
    int* p = malloc(2 * sizeof(int));
    p[2] = 5;
    free(p);
    return 0;
}
