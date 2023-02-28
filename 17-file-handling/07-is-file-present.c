#include <stdio.h>
#include <stdbool.h>

bool check_file_exists(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp) {
        fclose(fp);
        return true;
    } else {
        return false;
    }
}

int main()
{
    const char* filename = "/sys/module/qcserial/version";

    if (check_file_exists(filename)) {
        printf("File %s exists.\n", filename);
    } else {
        printf("File %s does not exist.\n", filename);
    }

    return 0;
}