/*
 * File Name   : 03_wait_function.c
 *
 * Description :
 *   Demonstrates use of wait() system call.
 *   Parent process waits for child process to terminate
 *   and collects child's exit status.
 *
 * Requirement :
 *   - Linux OS
 *   - GCC Compiler
 *   - gcc 03_wait_function.c -o 03_wait_function
 *
 * Author      : Pravin Jogdand
 * Date        : 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function Definition */
void wait_function(void)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Child Process */
        printf("Child Process:\n");
        printf("  PID  : %d\n", getpid());
        printf("  PPID : %d\n", getppid());

        sleep(3);  // simulate some work

        printf("Child exiting with status 10\n");
        exit(10);
    }
    else
    {
        /* Parent Process */
        printf("Parent Process:\n");
        printf("  PID  : %d\n", getpid());
        printf("Waiting for child to finish...\n");

        wait(&status);   // parent waits here

        if (WIFEXITED(status))
        {
            printf("Child exited normally\n");
            printf("Exit status = %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Child terminated abnormally\n");
        }
    }
}

/* Main Function */
int main(void)
{
    wait_function();
    return 0;
}
