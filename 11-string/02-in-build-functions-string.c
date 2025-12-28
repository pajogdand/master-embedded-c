#include <stdio.h>
#include <string.h>

// ReverseMe
 // R <--> e
 // e <--> M
 // len = 9
 // len-1 = 8
 //         7...
// void reverseString(char *str) {
//     int len = strlen(str);
//     int last = len - 1;
//     for (int i = 0; i < len / 2; i++) {
//         char temp = str[i];
//         str[i] = str[last - i];
//         str[last - i] = temp;
//     }
// }

void reverseString(char *str) {
    int len = strlen(str);
    int right = len;
    int left = 0;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right - 1];
        str[right - 1] = temp;
        left++;
        right--;
    }
}

int main() {
    char str1[50] = "WorldHelloThere";
    char str2[50] = "World!";
    char dest[50];
    char src[50] = "Example";
    char *psrc = "Example";
    
    // 1. String Copying
    // strcpy(dest, str1);
    // printf("Copied String: %s\n", dest);

    // // 2. String Concatenation
    // strcat(str1, " ");
    // strcat(str1, str2);
    // printf("Concatenated String: %s\n", str1);

    // // 3. String Length
    // printf("Length of src: %zu\n", strlen(src));

    // // 4. String Comparison
    // int cmpResult = strcmp("apple", "apple");
    // if (cmpResult < 0) {
    //     printf("\"apple\" is less than \"banana\"\n");
    // } else if (cmpResult > 0) {
    //     printf("\"apple\" is greater than \"banana\"\n");
    // } else {
    //     printf("\"apple\" is equal to \"apple\"\n");
    // }

    // // 5. Copying Limited Characters
    // strncpy(dest, src, 3); // 0 1 2 3
    // dest[3] = '\0'; // Add null terminator
    // printf("Copied first 3 characters of src: %s\n", dest);

    // // // 6. Concatenating Limited Characters
    // strncat(str1, "!World", 1);
    // printf("Concatenated Limited Characters: %s\n", str1);

    // // 7. String Search (Character)
    // char *ptr = strchr(str1, 'T');
    // if (ptr) {
    //     printf("First occurrence of 'H': %s\n", ptr);
    // }

    // // 8. String Search (Substring)
    // char substr[] = "He";
    // char *ptr = strstr(str1, substr);
    // if (ptr) {
    //     printf("First occurrence of \"World\": %s\n", ptr);
    //     printf("First occurrence of \"World\": %c,%c\n", ptr[0], ptr[1]);
    // }

    // // 9. String Tokenization
    // char str3[] = "Token1,Token2,Token3";
    // printf("Tokens:\n");
    // char *token = strtok(str3, ",");
    // while (token != NULL) {
    //     printf("%s\n", token);
    //     token = strtok(NULL, ",");
    // }

    // // 10. String Reverse
    char str4[] = "ReverseMe";
    reverseString(str4);
    printf("Reversed String: %s\n", str4);

    return 0;
}
