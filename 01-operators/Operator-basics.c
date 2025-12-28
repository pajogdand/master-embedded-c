#include <stdio.h>

int main() {
    int a = 10;
    int b = 3;

    // Arithmetic Operators
    printf("Arithmetic Operators:\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);

    // Relational Operators
    printf("\nRelational Operators:\n");
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);

    // Logical Operators
    printf("\nLogical Operators:\n");
    printf("(a > 5) && (b < 5): %d\n", (a > 5) && (b < 5)); // AND both true : true ; else false
    printf("(a > 5) || (b > 5): %d\n", (a > 5) || (b > 5)); // OR one true : true ; else false
    printf("!(a > 5): %d\n", !(a > 5));

    // True and Flase
    printf("\nTrue and False:\n");
    int x = 0;
    int y = 500000000;
    printf("x (0) is considered: %s\n", x ? "True" : "False");
    printf("y (5) is considered: %s\n", y ? "True" : "False");    


    return 0;
}


///
//<-- T -->   T <-- F -->
// -100 ....-1 0 1 2 ....100

//0 ==> F
//non-0 ==> T