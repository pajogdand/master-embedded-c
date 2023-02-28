#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *MODULE = argv[1];
    char command[1000], output[1000], *MOD_VERSION;
    FILE *fp;

    if (MODULE == NULL) {
        printf("Module name not specified\n");
        exit(1);
    }

    sprintf(command, "/sys/module/%s/version", MODULE);
    fp = fopen(command, "r");
    if (fp != NULL) {
        printf("Driver is loaded using insmod or modprobe\n");
        fgets(output, 1000, fp);
        fclose(fp);
        MOD_VERSION = output;
    }
    else {
        sprintf(command, "sudo modinfo %s | awk '/^version:/ {print $2}'", MODULE);
        fp = popen(command, "r");
        if (fp != NULL && fgets(output, 1000, fp) != NULL) {
            printf("Driver is loaded using depmod\n");
            MOD_VERSION = strtok(output, "\n");
        }
        else {
            printf("Driver is not loaded\n");
            MOD_VERSION = "unknown";
        }
        if (fp != NULL) {
            pclose(fp);
        }
    }

    printf("Driver version: %s\n", MOD_VERSION);
    return 0;
}
