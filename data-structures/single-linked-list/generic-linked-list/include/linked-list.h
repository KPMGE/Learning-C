#ifndef LINKED_LIST_H_INCLUDED 
#define LINKED_LIST_H_INCLUDED 

// function pointer to display data
typedef void (*fptrDisplay)(void*);
// function pointer to compare data
typedef int (*fptrCompare)(void*, void*);

// structure for a node
typedef struct _node Node_t;
// structure for a linked list
typedef struct _linkedList LinkedList_t;

// function to create a linked list
LinkedList_t* createLinkedList();
// function to add a new node at the beginning of a linked list
void addNewHead(LinkedList_t* list, void* newData);
// function to add a new node at the end of a linked list
void addNewTail(LinkedList_t* list, void* newData);
// function to display linked list
void displayLinkedList(LinkedList_t* list, fptrDisplay displayFunction);
// function to free linked list
void freeLinkedList(LinkedList_t* list);
// function to delete a given node
void deleteNode(LinkedList_t* list, Node_t* node);
// function to get a node
Node_t* getNodeLinkedList(LinkedList_t* list, fptrCompare compareFunction, void* data);
 
#endif 
