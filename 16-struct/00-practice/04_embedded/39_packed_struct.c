/*
 * File Name   : 39_packed_struct.c
 * Folder      : 04_embedded
 *
 * Program Name:
 *   Packed Structure
 *
 * Description :
 *   Demonstrates structure packing to remove padding bytes
 *   and control memory layout.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 39_packed_struct.c -o 39_packed_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - packed struct
 *   - embedded systems
 */

#include <stdio.h>

/* Normal structure (with padding) */
typedef struct
{
    int   i;
    char  c;
    float f;
} normal_struct_t;

/* Packed structure (no padding) */
typedef struct __attribute__((packed))
{
    int   i;
    char  c;
    float f;
} packed_struct_t;

/* Function Prototype */
void packed_struct(void);

/* Main Function */
int main(void)
{
    packed_struct();
    return 0;
}

/* Function Definition */
void packed_struct(void)
{
    normal_struct_t normal;
    packed_struct_t packed;

    printf("Size of normal struct : %lu bytes\n", sizeof(normal));
    printf("Size of packed struct : %lu bytes\n", sizeof(packed));
}
