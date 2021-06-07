#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct _node Node_t;
typedef struct _doubly_linked_list DoublyLinkedList_t;

DoublyLinkedList_t *createEmptyDoublyLinkedList();
void insertAtHead(DoublyLinkedList_t *list, int newNumber);
void insertAtTail(DoublyLinkedList_t *list, int newNumber);
void insertAfter(DoublyLinkedList_t *list, int newNumber);
void displayList(DoublyLinkedList_t *list);
void freeLinkedList(DoublyLinkedList_t *list);

#endif
