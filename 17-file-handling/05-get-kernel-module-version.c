#include <stdio.h>
#include <stdlib.h>

/* Goal:
    For given string for example mod_version, write functions write the data and read back from the file
    char *mod_version ="1.1.0"
*/

// #define MODULE_VERSION("1.1.0")

// const char* get_module_version(void)
// {
//     return MODULE_VERSION;
// }

void write_module_version_to_file(const char* mod_version , const char *filename)
{   
    FILE* file = fopen(filename, "w");  // open file for writing
    if (file == NULL) {  // check for errors
        printf("Error: could not open file '%s'\n", filename);        
    }else{
        printf("%s file opend scuccefully \n", filename);
    }

    int result = fprintf(file, "%s\n", mod_version);  // write string to file
    if (result < 0) {  // check for errors
        printf("Error: could not write to file '%s'\n", filename);
        fclose(file);  // close file
    }else{
        printf("%d bytes of %s written in the file\n" , result , mod_version);
    }
}

void read_module_version_to_file(const char* mod_version , const char *filename)
{   
    FILE *fp;
    long length;
    char *content;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for file content
    content = malloc(length + 1);
    if (content == NULL) {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    // Read file content into buffer
    fread(content, 1, length, fp);
    content[length] = '\0';  // Add null terminator

    // Close file
    fclose(fp);

    printf("File content:\n%s\n", content);

    free(content);  // Free allocated memory
}


int main()
{    
    static char *mod_version = "1.1.1";
    static char *filename="module_version.txt";
    printf("module version = %s " ,mod_version);

    write_module_version_to_file(mod_version , filename);
    read_module_version_to_file(mod_version , filename);
    
    exit(0);
}