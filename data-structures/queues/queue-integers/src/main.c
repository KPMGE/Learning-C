// Queue implementation in C
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

int main(void) {
  Queue_t *myQueue = createEmptyQueue(10);

  enQueue(myQueue, 1);
  enQueue(myQueue, 3);
  enQueue(myQueue, 54);
  enQueue(myQueue, 42);
  enQueue(myQueue, 31);

  printf("Orignal queue: ");
  displayQueue(myQueue);

  printf("\nAfter dequeue: ");
  deQueue(myQueue);
  displayQueue(myQueue);

  printf("\nAfter dequeue again: ");
  deQueue(myQueue);
  displayQueue(myQueue);

  freeQueue(myQueue);

  return 0;
}
