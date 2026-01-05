/*
 * File Name   : 41_driver_config.c
 * Folder      : 04_embedded
 *
 * Program Name:
 *   Driver Configuration using Structure
 *
 * Description :
 *   Demonstrates how driver configuration parameters
 *   are grouped using a structure and passed to driver init.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 41_driver_config.c -o 41_driver_config
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - driver configuration
 *   - embedded systems
 */

#include <stdio.h>

/* Driver configuration structure */
typedef struct
{
    int   baud_rate;     /* Communication speed */
    char  parity;        /* Parity: N/E/O */
    float timeout;       /* Timeout in seconds */
} driver_config_t;

/* Pointer to configuration structure */
driver_config_t *p_driver_cfg;

/* Function Prototypes */
void driver_init(driver_config_t *cfg);
void driver_config(void);

/* Main Function */
int main(void)
{
    driver_config();
    return 0;
}

/* Function Definition */
void driver_config(void)
{
    driver_config_t config;

    /* Configure driver parameters */
    config.baud_rate = 115200;
    config.parity    = 'N';
    config.timeout   = 1.5f;

    /* Pass configuration to driver */
    driver_init(&config);
}

/* Driver initialization using config structure */
void driver_init(driver_config_t *cfg)
{
    p_driver_cfg = cfg;

    printf("Driver Initialized with:\n");
    printf("Baud Rate : %d\n", p_driver_cfg->baud_rate);
    printf("Parity    : %c\n", p_driver_cfg->parity);
    printf("Timeout   : %.2f sec\n", p_driver_cfg->timeout);
}
