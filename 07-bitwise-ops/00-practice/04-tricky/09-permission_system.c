/*
 * File Name   : 09-permission_system.c
 * Folder      : 04-tricky
 *
 * Description :
 *  Implement 'permission_system' using bitwise operators in C.
 *
 * Requirement :
 *  - Use bitwise operators
 *  - Avoid arithmetic operators where applicable
 *  - Follow embedded C coding standards
 *
 * Sample Input :
 *  (Provide input via terminal or hardcoded values)
 *
 * Sample Output :
 *  (Expected output based on input)
 */

#include <stdio.h>
#include <stdint.h>

#define READ_PERMISSION    0x4  // 100
#define WRITE_PERMISSION   0x2  // 010
#define EXECUTE_PERMISSION 0x1  // 001
int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "permission_system");

    uint8_t user_permissions = 0;  // No permissions initially
    // Grant read and write permissions
    user_permissions |= READ_PERMISSION;
    user_permissions |= WRITE_PERMISSION;
    printf("User Permissions after granting READ and WRITE: 0x%X\n", user_permissions); 
    return 0;
}
