/*
 * File Name   : 02_fork_function.c
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - Linux OS
 *   - GCC Compiler
 *   - gcc 02_fork_function.c -o 02_fork_function
 *
 * Author      : Pravin Jogdand
 * Date        : 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

// | Condition  | Who is executing   | Explanation                    |
// | ---------- | ------------------ | ------------------------------ |
// | `pid == 0` | **Child process**  | Child gets **0** from `fork()` |
// | `pid > 0`  | **Parent process** | Parent gets **child’s PID**    |
// | `pid < 0`  | **Error**          | `fork()` failed                |

/* Function Definition */
void fork_function(void)
{
    int pid = fork();
    if (pid == 0)
    {
        /* Child process */
        printf("Child: PID = %d, Parent PID = %d\n",
            getpid(), getppid());
    }
    else if (pid > 0)
    {
        /* Parent process */
        printf("Parent: PID = %d, Child PID = %d\n",
            getpid(), pid);
    }
    else
    {
        /* Error */
        perror("fork failed");
    }
}

/* Main Function */
int main(void)
{
    fork_function();
    return 0;
}
