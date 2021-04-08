#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linked-list.h"

struct _node {
  void* data;
  struct _node* next;
};

struct _linkedList {
  Node_t* head;
  Node_t* current;
  Node_t* tail;
};

LinkedList_t* createLinkedList() {
  LinkedList_t* allocatedLinkedList = (LinkedList_t*) malloc(sizeof(LinkedList_t));

  if (allocatedLinkedList == NULL) {
    printf("Insuficient space!");
    exit(1);
  }

  allocatedLinkedList->head = NULL;
  allocatedLinkedList->current = NULL;
  allocatedLinkedList->tail = NULL;

  return allocatedLinkedList;
}

void addNewHead(LinkedList_t* list, void* newData) {
  Node_t* newNode = (Node_t*) malloc(sizeof(Node_t));
  newNode->data = newData;

  if (list->head == NULL) {
    list->tail = newNode;
    newNode->next = NULL;
  } else {
    newNode->next = list->head;
  }
  list->head = newNode;
}

void addNewTail(LinkedList_t* list, void* newData) {
  Node_t* newNode = (Node_t*) malloc(sizeof(Node_t));
  newNode->data = newData;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    list->tail->next = newNode;
  }
  list->tail = newNode;
}

void displayLinkedList(LinkedList_t* list, fptrDisplay displayFunction) {
  Node_t* current = list->head;

  while (current != NULL) {
    displayFunction(current->data);
    printf("\n");
    current = current->next;
  }
}

Node_t* getNodeLinkedList(LinkedList_t* list, fptrCompare compareFunction, void* data) {
  Node_t* current = list->head;

  while (current != NULL) {
    if (compareFunction(current->data, data) == 0) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

void deleteNode(LinkedList_t* list, Node_t* node) {
  if (node == list->head) {
    if (list->head->next == NULL) {
      list->head = list->tail;
    } else {
      list->head = list->head->next;
    }
  } else {
    Node_t* temporary = list->head;

    while (temporary != NULL && temporary->next != node) {
      temporary = temporary->next;
    }

    if (temporary != NULL){
      temporary->next = node->next;
    }
  }
  free(node);
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