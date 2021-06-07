#include <stdio.h>
#include <stdlib.h>
#include "../include/doubly-linked-list.h"

int main(void) {
	DoublyLinkedList_t *myDoublyLinkedList = createEmptyDoublyLinkedList();

	insertAtHead(myDoublyLinkedList, 10);
	insertAtHead(myDoublyLinkedList, 34);
	insertAtHead(myDoublyLinkedList, 52);

	printf("Original linked list: ");
	displayList(myDoublyLinkedList);

	printf("\nInserting at tail 94: ");
	insertAtTail(myDoublyLinkedList, 94);
	displayList(myDoublyLinkedList);

	printf("\nInserting at head 45: ");
	insertAtHead(myDoublyLinkedList, 45);
	displayList(myDoublyLinkedList);

	freeLinkedList(myDoublyLinkedList);

	return 0;
}
