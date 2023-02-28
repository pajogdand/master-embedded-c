#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

int main(void) {
    FILE *fp;
    char cmd[MAXLINE], line[MAXLINE];

    // Build the shell command to be executed
    snprintf(cmd, MAXLINE, "ls  -lrt");

    // Open a pipe to the shell command
    if ((fp = popen(cmd, "r")) == NULL) {
        perror("popen error");
        exit(1);
    }

    // Read the output of the command line by line
    while (fgets(line, MAXLINE, fp) != NULL) {
        printf("%s", line);
    }

    // Close the pipe and free any resources used by it
    if (pclose(fp) < 0) {
        perror("pclose error");
        exit(1);
    }

    return 0;
}