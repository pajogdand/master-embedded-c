/*
 * File Name   : 06_multiple_fork_calls.c
 *
 * Description :
 *   Demonstrates multiple fork() calls and
 *   how number of processes increases.
 *
 * Requirement :
 *   - Linux OS
 *   - GCC Compiler
 *   - gcc 06_multiple_fork_calls.c -o 06_multiple_fork_calls
 *
 * Author      : Pravin Jogdand
 * Date        : 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* Function Definition */
void multiple_fork_calls(void)
{
    printf("Start: PID = %d\n", getpid());

    fork();   // 1st fork
    fork();   // 2nd fork

    printf("Hello from PID = %d, PPID = %d\n",
           getpid(), getppid());
}

/* Main Function */
int main(void)
{
    multiple_fork_calls();
    return 0;
}
