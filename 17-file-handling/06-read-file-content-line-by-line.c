#include <stdio.h>

int main() {
    FILE *fp;
    char output[1000];

    fp = fopen("example.txt", "r"); // open file for reading
    if (fp != NULL) {
        fgets(output, 1000, fp);    // read a line of text from file
        printf("%s", output);       // print the contents of output
        fclose(fp);                 // close the file
    }

    return 0;
}
