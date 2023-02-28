#include <stdio.h>

int main() {
    int integer;
    float floatingPoint;
    char character;
    char string[100];

    // Read an integer
    printf("Enter an integer: ");
    scanf("%d", &integer);
    
    // Read a floating point number
    printf("Enter a floating point number: ");
    scanf("%f", &floatingPoint);
    
    // Read a single character
    printf("Enter a character: ");
    scanf(" %c", &character); // Note the space before %c to handle newline character

    // Clear the input buffer
    while (getchar() != '\n');

    // Read a line of text from the user
    printf("Enter a line of text: ");
    fgets(string, sizeof(string), stdin);

    // Output the inputted values
    printf("\nYou entered:\n");
    printf("Integer: %d\n", integer);
    printf("Floating point: %.2f\n", floatingPoint);
    printf("Character: %c\n", character);
    printf("Line of text: %s", string);

    return 0;
}
