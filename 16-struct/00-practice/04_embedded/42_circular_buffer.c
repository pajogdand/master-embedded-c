/*
 * File Name   : 42_circular_buffer.c
 * Folder      : 04_embedded
 *
 * Program Name:
 *   Circular Buffer
 *
 * Description :
 *   Demonstrates implementation of a circular (ring) buffer
 *   using structure for embedded systems.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 42_circular_buffer.c -o 42_circular_buffer
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - circular buffer
 *   - embedded systems
 */

#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 5

/* Circular buffer structure */
typedef struct
{
    int buffer[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
} circular_buffer_t;

/* Function Prototypes */
void circular_buffer(void);
void cb_init(circular_buffer_t *cb);
int  cb_push(circular_buffer_t *cb, int data);
int  cb_pop(circular_buffer_t *cb, int *data);

/* Main Function */
int main(void)
{
    circular_buffer();
    return 0;
}

/* Function Definition */
void circular_buffer(void)
{
    circular_buffer_t cb;
    int value;

    cb_init(&cb);

    /* Push data */
    cb_push(&cb, 10);
    cb_push(&cb, 20);
    cb_push(&cb, 30);
    cb_push(&cb, 40);
    cb_push(&cb, 50);

    /* Pop data */
    while (cb_pop(&cb, &value) == 0)
    {
        printf("Popped: %d\n", value);
    }
}

/* Initialize circular buffer */
void cb_init(circular_buffer_t *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

/* Push data into buffer */
int cb_push(circular_buffer_t *cb, int data)
{
    if (cb->count == BUFFER_SIZE)
    {
        printf("Buffer Full\n");
        return -1;
    }

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;

    return 0;
}

/* Pop data from buffer */
int cb_pop(circular_buffer_t *cb, int *data)
{
    if (cb->count == 0)
    {
        return -1;
    }

    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;

    return 0;
}
