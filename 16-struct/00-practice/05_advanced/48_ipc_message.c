/*
 * File Name   : 48_ipc_message.c
 * Folder      : 05_advanced
 *
 * Program Name:
 *   IPC Message using Structure
 *
 * Description :
 *   Demonstrates how a structure can be used
 *   as an IPC message format between processes
 *   or threads.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 48_ipc_message.c -o 48_ipc_message
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - IPC
 *   - embedded systems
 */

#include <stdio.h>
#include <string.h>

/* IPC Message Structure */
typedef struct
{
    int   msg_id;          /* Message identifier */
    char  payload[32];    /* Message data */
    float value;           /* Additional data */
} ipc_msg_t;

/* Function Prototype */
void ipc_message(void);

/* Main Function */
int main(void)
{
    ipc_message();
    return 0;
}

/* Function Definition */
void ipc_message(void)
{
    ipc_msg_t tx_msg;  /* Transmit message */
    ipc_msg_t rx_msg;  /* Receive message */

    /* Fill transmit message */
    tx_msg.msg_id = 1;
    strcpy(tx_msg.payload, "Sensor Data");
    tx_msg.value = 25.5f;

    /* -------- IPC Transfer (simulated copy) -------- */
    rx_msg = tx_msg;   /* This mimics IPC transfer */
    /* ----------------------------------------------- */

    /* Receive and process message */
    printf("Received IPC Message:\n");
    printf("Message ID : %d\n", rx_msg.msg_id);
    printf("Payload    : %s\n", rx_msg.payload);
    printf("Value      : %.2f\n", rx_msg.value);
}
