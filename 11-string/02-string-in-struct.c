#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fixed-size Character Array
typedef struct {
    char name[50];  // Fixed-size string
} FixedStringStruct;

// Pointer to a String (Dynamically Allocated)
typedef struct {
    char *name;  // Pointer to a dynamically allocated string
} PointerStringStruct;

// Pointer to a Constant String
typedef struct {
    const char *name;  // Pointer to a string literal or constant string
} ConstPointerStringStruct;

// Flexible Array Member
typedef struct {
    size_t length;  // Length of the string
    char name[];    // Flexible array member for variable-length strings
} FlexibleStringStruct;

// External Buffer String
typedef struct {
    char *name;  // Pointer to an external buffer
} ExternalBufferStruct;

int main() {
    // 1. Fixed-size Character Array
    FixedStringStruct fixedStr = { "Fixed-size String" };
    printf("Fixed-size Character Array: %s\n", fixedStr.name);

    // 2. Pointer to a String (Dynamically Allocated)
    PointerStringStruct dynamicStr;
    dynamicStr.name = malloc(100 * sizeof(char));  // Allocate memory for the string
    if (!dynamicStr.name) {
        perror("Failed to allocate memory");
        return 1;
    }
    strcpy(dynamicStr.name, "Dynamically Allocated String");
    printf("Pointer to a String: %s\n", dynamicStr.name);
    free(dynamicStr.name);  // Free allocated memory

    // 3. Pointer to a Constant String
    ConstPointerStringStruct constStr = { "Constant String" };
    printf("Pointer to a Constant String: %s\n", constStr.name);

    // 4. Flexible Array Member
    const char *flexibleContent = "Flexible Array String";
    size_t flexLength = strlen(flexibleContent);
    FlexibleStringStruct *flexStr = malloc(sizeof(FlexibleStringStruct) + flexLength + 1);
    if (!flexStr) {
        perror("Failed to allocate memory");
        return 1;
    }
    flexStr->length = flexLength;
    strcpy(flexStr->name, flexibleContent);
    printf("Flexible Array Member: %s (Length: %zu)\n", flexStr->name, flexStr->length);
    free(flexStr);  // Free allocated memory

    // 5. External Buffer String
    char externalBuffer[] = "String in External Buffer";
    ExternalBufferStruct externalStr = { externalBuffer };
    printf("External Buffer String: %s\n", externalStr.name);

    // Modify the external buffer to show it's shared
    strcpy(externalBuffer, "Modified External String");
    printf("Modified External Buffer String: %s\n", externalStr.name);

    return 0;
}

