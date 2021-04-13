#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

  typedef void (*fptrDisplay)(void*);
  typedef struct _node Node_t;
  typedef struct _linkedList LinkedList_t;

  Node_t* createNewNode(void* newData);
  LinkedList_t* createLinkedList(void);
  void addNewHead(LinkedList_t* list, void* newData);
  void addNewTail(LinkedList_t* list, void* newData);
  void displayLinkedList(LinkedList_t* list, fptrDisplay displayFunction);
  void freeLinkedList(LinkedList_t* list);

#endif