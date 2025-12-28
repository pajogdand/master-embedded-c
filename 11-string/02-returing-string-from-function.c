#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Method 1: Return string using static memory
const char* getStaticMessage() 
{
    return "Hello, this message is from static memory!";
}

// Method 2: Return string using dynamic memory
char* getDynamicMessage() {
    char* message = (char*)malloc(50 * sizeof(char)); // Allocate memory
    if (message == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(message, "Hello, this message is dynamically allocated!");
    return message;
}

void getDynamicMessage1(char **PtrMessage)
{
    *PtrMessage = (char*)malloc(50 * sizeof(char)); // Allocate memory
    if (PtrMessage == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    strcpy(*PtrMessage, "Hello, this message is dynamically with other method.. allocated!");    
}

void getUsingArray(char *ptr)
{
    strcpy(ptr,"SomeString");
}

// char *NotWokringMethod()
// {    
//     char B[256];
//     strcpy(B ,"Something");
//     return B;
// }

int main() {
    // Static Memory Example
    const char* staticMessage = getStaticMessage();
    printf("Static Message: %s\n", staticMessage);

    // Dynamic Memory Example
    char* dynamicMessage = getDynamicMessage();
    if (dynamicMessage != NULL) {
        printf("Dynamic Message: %s\n", dynamicMessage);
        // Use it
        free(dynamicMessage); // Free dynamically allocated memory
    }

    // message @1000 [NULL];
    char  *message = NULL;
    getDynamicMessage1(&message);

    if (message != NULL) {
        printf("Dynamic Message with arg %s\n", message);
        // Use it
        free(message); // Free dynamically allocated memory
    }
    else{
        printf("Error in allocating the memory\n");
    }

    // Using Array
    char A[256];
    getUsingArray(A);
    printf("Array Message  %s\n", A);

    // char A[] = {};
    // getUsingArray(A);
    // printf("Array Message  %s\n", A);
    
    return 0;
}
