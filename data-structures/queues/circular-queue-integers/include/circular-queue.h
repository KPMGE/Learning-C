#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include <stdbool.h>
#include <stddef.h>

typedef struct _circularQueue CircularQueue_t;

CircularQueue_t *createEmptyCircularQueue(size_t capacity);
int getFront(CircularQueue_t* circularQueue);
int getRear(CircularQueue_t* circularQueue);
size_t getCapacity(CircularQueue_t* circularQueue);
bool isEmpty(CircularQueue_t* circularQueue);
bool isFull(CircularQueue_t* circularQueue);
void enQueue(CircularQueue_t* circularQueue, int value);
void deQueue(CircularQueue_t* circularQueue);
void displayCircularQueue(CircularQueue_t* circularQueue);
void freeCircularQueue(CircularQueue_t* circularQueue);

#endif
