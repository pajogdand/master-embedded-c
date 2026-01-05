/*
 * File Name   : 05_process_ids.c
 *
 * Description :
 *   Demonstrates various process identifiers in Linux:
 *   PID, PPID, UID, GID for parent and child processes.
 *
 * Requirement :
 *   - Linux OS
 *   - GCC Compiler
 *   - gcc 05_process_ids.c -o 05_process_ids
 *
 * Author      : Pravin Jogdand
 * Date        : 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* Function Definition */
void process_ids(void)
{
    pid_t pid;

    printf("Before fork()\n");
    printf("Process PID  : %d\n", getpid());
    printf("Parent PID   : %d\n", getppid());
    printf("User ID      : %d\n", getuid());
    printf("Group ID     : %d\n", getgid());
    printf("---------------------------------\n");

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
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());
        printf("UID  : %d\n", getuid());
        printf("GID  : %d\n", getgid());
    }
    else
    {
        /* Parent Process */
        printf("Parent Process:\n");
        printf("PID  : %d\n", getpid());
        printf("Child PID : %d\n", pid);
        printf("UID  : %d\n", getuid());
        printf("GID  : %d\n", getgid());
    }
}

/* Main Function */
int main(void)
{
    process_ids();
    return 0;
}
