#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

void _checkAllocation(void *pointer) {
  if (pointer == NULL) {
    printf("Insuficient Space!");
    exit(1);
  }
}

struct _queue {
  size_t capacity;
  int front;
  int rear;
  int *elements;
};

Queue_t *createEmptyQueue(size_t capacity) {
  Queue_t *queue = (Queue_t*) malloc(capacity * sizeof(Queue_t));
  _checkAllocation(queue);

  queue->elements = (int*) malloc(sizeof(int));
  _checkAllocation(queue->elements);

  queue->capacity = capacity;
  queue->front = -1;
  queue->rear = -1;

  return queue;
}

int getFront(Queue_t *queue) {
  return queue->front;
}

int getRear(Queue_t *queue) {
  return queue->rear;
}

void enQueue(Queue_t* queue, int value) {
  if (isFull(queue)) {
    printf("The queue is full!");
    return;
  }

  if (getFront(queue) == -1) {
    queue->front = 0;
  }

  queue->rear++;
  queue->elements[getRear(queue)] = value; 
}


void deQueue(Queue_t *queue) {
  if (isEmpty(queue)) {
    printf("The queue is empty");
  } else {

    queue->front++;
    if (getFront(queue) > getRear(queue)) {
      queue->front = queue->rear = -1;
    }
  }
}

void displayQueue(Queue_t *queue) {
  if (isEmpty(queue)) {
    printf("The queue is empty");
    return;
  }

  for (int i = getFront(queue); i <= getRear(queue); i++) {
    printf("%d ", queue->elements[i]);
  }
}

bool isFull(Queue_t *queue) {
  return (queue->rear == (queue->capacity - 1));
}

bool isEmpty(Queue_t *queue) {
  return (queue->front == -1);
}

void freeQueue(Queue_t *queue) {
  if (queue != NULL && queue->elements != NULL) {
    free(queue->elements);
    free(queue);
  }
}
