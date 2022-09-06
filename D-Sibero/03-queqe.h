// queqe.h 
#ifndef QUEUE_H
#define QUEUE_H

struct queue
{
    void * data_buf;
    void * front;
    const uint16_t max_elements;
    const uint16_t size_of_elements;
    uint16_t elements;
};


void queue_init(struct queue * queue);
bool en_queue(struct queue * queue, void * data);
bool dq_queue(struct queue * queue, void * data);


#endif









