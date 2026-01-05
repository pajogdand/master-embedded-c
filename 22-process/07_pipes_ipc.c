/*
 * File Name   : 07_pipes_ipc.c
 *
 * Description :
 *   Demonstrates Inter-Process Communication (IPC)
 *   using pipe() between parent and child process.
 *
 * Requirement :
 *   - Linux OS
 *   - GCC Compiler
 *   - gcc 07_pipes_ipc.c -o 07_pipes_ipc
 *
 * Author      : Pravin Jogdand
 * Date        : 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/* Function Definition */
void pipes_ipc(void)
{
    int fd[2];          // fd[0] -> read end, fd[1] -> write end
    pid_t pid;
    char buffer[100];

    if (pipe(fd) == -1)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Child Process: Reads data */
        close(fd[1]);   // Close unused write end

        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(fd[0]);
    }
    else
    {
        /* Parent Process: Writes data */
        close(fd[0]);   // Close unused read end

        char message[] = "Hello from Parent process!";
        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);
    }
}

/* Main Function */
int main(void)
{
    pipes_ipc();
    return 0;
}
