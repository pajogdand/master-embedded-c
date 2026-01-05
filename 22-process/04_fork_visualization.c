/*
 * File Name   : 04_fork_visualization.c
 *
 * Description :
 *   Visualizes how fork() creates parent and child processes
 *   and how execution continues in both.
 *
 * Requirement :
 *   - Linux OS
 *   - GCC Compiler
 *   - gcc 04_fork_visualization.c -o 04_fork_visualization
 *
 * Author      : Pravin Jogdand
 * Date        : 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* Function Definition */
void fork_visualization(void)
{
    printf("Before fork()\n");

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        /* Child process */
        printf("Child Process\n");
        printf("  PID  : %d\n", getpid());
        printf("  PPID : %d\n", getppid());
    }
    else
    {
        /* Parent process */
        printf("Parent Process\n");
        printf("  PID  : %d\n", getpid());
        printf("  Child PID : %d\n", pid);
    }

    printf("After fork() - PID %d\n", getpid());
}

/* Main Function */
int main(void)
{
    fork_visualization();
    return 0;
}
