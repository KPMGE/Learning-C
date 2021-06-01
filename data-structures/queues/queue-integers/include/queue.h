#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stddef.h>
#include <stdbool.h>

typedef struct _queue Queue_t;

Queue_t *createEmptyQueue(size_t capacity);
void enQueue(Queue_t* queue, int value);
void displayQueue(Queue_t *queue);
void deQueue(Queue_t *queue);
int getFront(Queue_t *queue);
int getRear(Queue_t *queue);
bool isFull(Queue_t *queue);
bool isEmpty(Queue_t *queue);
void freeQueue(Queue_t *queue);

#endif
