#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linkedList.h"

struct _node {
  void* data;
  struct _node* next;
};

struct _linkedList {
  Node_t* head;
  Node_t* current;
  Node_t* tail;
};

Node_t* createNewNode(void* newData) {
  Node_t* allocatedNode = (Node_t*) malloc(sizeof(Node_t));
  allocatedNode->data = newData;

  return allocatedNode;
}

LinkedList_t* createLinkedList(void) {
  LinkedList_t* allocatedList = (LinkedList_t*) malloc(sizeof(LinkedList_t));

  allocatedList->head = NULL;
  allocatedList->current = NULL;
  allocatedList->tail = NULL;

  return allocatedList;
}

void addNewHead(LinkedList_t* list, void* newData) {
  Node_t* newNode = createNewNode(newData);

  if (list->head == NULL) {
    newNode->next = NULL;
    list->tail = newNode;
  } else {
    newNode->next = list->head;
  }
  list->head = newNode;
}

void addNewTail(LinkedList_t* list, void* newData) {
  Node_t* newNode = createNewNode(newData);
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    list->tail->next = newNode;
  }
  list->tail = newNode;
}

void displayLinkedList(LinkedList_t* list, fptrDisplay displayFunction) {
  int count = 1;
  Node_t* current = list->head;

  while (current != NULL) {
    printf("\n\nStudent %d\n", count);
    count++;
    
    displayFunction(current->data);
    current = current->next;

    printf("\n");
  }
}

void freeLinkedList(LinkedList_t* list) {
  Node_t* current = list->head;

  while (current != NULL) {
    Node_t* aux = current;
    current = current->next;
    free(aux);
  }
  free(list);
}