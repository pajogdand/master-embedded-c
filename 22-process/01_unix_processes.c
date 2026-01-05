/*
 * File Name   : 01_unix_processes.c
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - Linux OS
 *   - GCC Compiler
 *   - gcc 01_unix_processes.c -o 01_unix_processes
 *
 * Author      : Pravin Jogdand
 * Date        : 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* Function Definition */
void unix_processes(void)
{
   int pid = fork();
   printf("pid = %d\n" , pid);
   printf("Hello world\n");
    
}

/* Main Function */
int main(void)
{
    unix_processes();
    return 0;
}
