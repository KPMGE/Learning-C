// simple linked list for integers
// author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

// function pointer to compare numbers
typedef int (*fptrCompare)(int, int);

// struct for a node
typedef struct _node {
  int number;
  struct _node* next;
} Node_t;

// struct for a linked list
typedef struct _linkedList {
  Node_t* head;
  Node_t* current;
  Node_t* tail;
} LinkedList_t;

// functions to deal with a linked list
void initializeLinkedList(LinkedList_t* list);
void addNewHead(LinkedList_t *list, int value);
void addNewTail(LinkedList_t *list, int value);
void displayLinkedList(LinkedList_t *list);
void deleteNode(LinkedList_t *list, Node_t* node);
Node_t* getNode(LinkedList_t* list, fptrCompare compareFunction, int number);

// comparison function
int compareNumbers(int num1, int num2); 

int main(void) {
  LinkedList_t testList;

  initializeLinkedList(&testList);

  printf("original linked lis: ");
  addNewHead(&testList, 10);
  addNewHead(&testList, 42);
  addNewHead(&testList, 34);
  displayLinkedList(&testList);


  printf("\n\nadding new head: ");
  addNewHead(&testList, 372);
  displayLinkedList(&testList);

  printf("\n\nadding new tail: ");
  addNewTail(&testList, 200);
  displayLinkedList(&testList);

  printf("\n\ndeleting node 10: ");
  // get ten
  Node_t* ten = getNode(&testList, (fptrCompare)compareNumbers, 10);
  // delet it
  deleteNode(&testList, ten);
  displayLinkedList(&testList);

  return 0;
}

void initializeLinkedList(LinkedList_t* list) {
  list->head = NULL;
  list->current = NULL;
  list->tail = NULL;
}

void addNewHead(LinkedList_t *list, int value) {
  Node_t* node = (Node_t*) malloc(sizeof(Node_t));
  node->number = value;

  if (list->head == NULL) {
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head;
  }
  list->head = node;
}

void addNewTail(LinkedList_t *list, int value) {
  Node_t* node = (Node_t*) malloc(sizeof(Node_t));
  node->number = value;
  node->next = NULL;

  if (list->head == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

void displayLinkedList(LinkedList_t *list) {
  Node_t* current = list->head;

  while (current != NULL) {
    printf("%d - ", current->number);
    current = current->next;
  }
}

void deleteNode(LinkedList_t *list, Node_t* node) {
  if (node == list->head) {
    if (list->head->next == NULL) {
      list->head = list->tail;
    } else {
      list->head = list->head->next;
    }
  } else {
    Node_t* current = list->head;

    // go throught the list
    while (current != NULL && current->next != node) {
      current = current->next;
    }

    if (current != NULL) {
      current->next = node->next;
    }
  }
  free(node);
}

Node_t* getNode(LinkedList_t* list, fptrCompare compareFunction, int number) {
  Node_t* current = list->head;

  while (current != NULL) {
    if (compareFunction(current->number, number) == 0) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

int compareNumbers(int num1, int num2) {
  if (num1 == num2) {
    return 0;
  } else if (num2 > num1) {
    return 1;
  } else {
    return -1;
  }
}
