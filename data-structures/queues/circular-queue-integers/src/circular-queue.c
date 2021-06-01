#include <stdio.h>
#include <stdlib.h>
#include "../include/circular-queue.h"

struct _circularQueue {
  size_t capacity;
  int front;
  int rear;
  int *elements;
};

void _checkAllocation(void *pointer) {
  if (pointer == NULL) {
    printf("Insuficient memory!");
    exit(1);
  }
}

void _setFront(CircularQueue_t* circularQueue, int value) {
  circularQueue->front = value;
}

void _setRear(CircularQueue_t* circularQueue, int value) {
  circularQueue->rear = value;
}


CircularQueue_t *createEmptyCircularQueue(size_t capacity) {
  CircularQueue_t *circularQueue = (CircularQueue_t*) malloc(sizeof(CircularQueue_t));
  _checkAllocation(circularQueue);

  circularQueue->elements = (int*) malloc(capacity * sizeof(int));
  _checkAllocation(circularQueue->elements);

  circularQueue->capacity = capacity;
  circularQueue->front = -1;
  circularQueue->rear = -1;

  return circularQueue;
}

int getFront(CircularQueue_t* circularQueue) {
  return circularQueue->front;
}

int getRear(CircularQueue_t* circularQueue) {
  return circularQueue->rear;
}

size_t getCapacity(CircularQueue_t* circularQueue) {
  return circularQueue->capacity;
}

bool isEmpty(CircularQueue_t* circularQueue) {
  return (getFront(circularQueue) == -1);
}

bool isFull(CircularQueue_t* circularQueue) {
  if (getFront(circularQueue) == (getRear(circularQueue) + 1)) {
    return true;
  }
  if (getFront(circularQueue) == 0 && getRear(circularQueue) == (getCapacity(circularQueue) - 1)) {
    return true;
  }

  return false;
}

void enQueue(CircularQueue_t* circularQueue, int value) {
  if (isFull(circularQueue)) {
    printf("The queue is full!");
    return;
  }

  if (getFront(circularQueue) == -1) {
    _setFront(circularQueue, 0);
  }

  int position = (getRear(circularQueue) + 1) % getCapacity(circularQueue);
  _setRear(circularQueue, position);
  circularQueue->elements[position] = value;
}

void deQueue(CircularQueue_t* circularQueue) {
  if (isEmpty(circularQueue)) {
    printf("The queue is empty!");
    return;
  }

  if (getFront(circularQueue) == getRear(circularQueue)) {
    _setFront(circularQueue, -1);
    _setRear(circularQueue, -1);
    return;
  }

  int position = (getFront(circularQueue) + 1) % getCapacity(circularQueue);
  _setFront(circularQueue, position);
}

void displayCircularQueue(CircularQueue_t* circularQueue) {
  if (isEmpty(circularQueue)) {
    printf("The queue is empty!");
    return;
  }

  int i;
  printf("Items: ");
  for (i = getFront(circularQueue); i != getRear(circularQueue); i = (i + 1) % getCapacity(circularQueue)) {
    printf("%d ", circularQueue->elements[i]);
  }
  printf("%d ", circularQueue->elements[i]);
}

void freeCircularQueue(CircularQueue_t* circularQueue) {
  free(circularQueue->elements);
  free(circularQueue);
}
