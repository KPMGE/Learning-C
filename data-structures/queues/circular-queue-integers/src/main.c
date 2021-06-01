// Circular Queue implementation in C
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include "../include/circular-queue.h"

int main(void) {
  CircularQueue_t *myCircularQueue = createEmptyCircularQueue(6);

  enQueue(myCircularQueue, 32);
  enQueue(myCircularQueue, 2);
  enQueue(myCircularQueue, 5);
  enQueue(myCircularQueue, 45);

  printf("Original circular queue: \n");
  displayCircularQueue(myCircularQueue);

  printf("\n\nenQueue(68)...\n");
  enQueue(myCircularQueue, 68);
  displayCircularQueue(myCircularQueue);

  printf("\n\ndeQueue()...\n");
  deQueue(myCircularQueue);
  displayCircularQueue(myCircularQueue);

  freeCircularQueue(myCircularQueue);

  return 0;
}
