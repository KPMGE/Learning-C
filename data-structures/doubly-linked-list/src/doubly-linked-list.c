#include <stdlib.h>
#include <stdio.h>
#include "../include/doubly-linked-list.h"

struct _node {
	int data;
	struct _node *previous;
	struct _node *next;
};

struct _doubly_linked_list {
	Node_t *head;
	Node_t *tail;
};

void _initializeLinkedList(DoublyLinkedList_t *list) {
	list->head = NULL;
	list->tail = NULL;
}

Node_t *createNewNode(int data) {
	Node_t *allocatedNode = (Node_t*) malloc(sizeof(Node_t));

	if (allocatedNode == NULL) {
		printf("Insuficient memory!");
		exit(1);
	}

	allocatedNode->data = data;

	return allocatedNode;
}

DoublyLinkedList_t *createEmptyDoublyLinkedList() {
	DoublyLinkedList_t *allocatedList = (DoublyLinkedList_t*) malloc(sizeof(DoublyLinkedList_t));

	if (allocatedList == NULL) {
		printf("Insuficient memory!");
		exit(1);
	}

	_initializeLinkedList(allocatedList);

	return allocatedList;
}

void insertAtTail(DoublyLinkedList_t *list, int newNumber) {
	Node_t *newNode = createNewNode(newNumber);
	newNode->next = NULL;

	Node_t *last = list->head;

	if (list->head == NULL) {
		newNode->previous = NULL;
		list->head = newNode;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
	newNode->previous = last;
	return;
}

void insertAtHead(DoublyLinkedList_t *list, int newNumber) {
	Node_t *newNode = createNewNode(newNumber);

	newNode->next = list->head;
	newNode->previous = NULL;

	if (list->head != NULL) {
		list->head->previous = newNode;
	}

	list->head = newNode;
}

void displayList(DoublyLinkedList_t *list) {
	Node_t *current = list->head;

	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
}

void freeLinkedList(DoublyLinkedList_t *list) {
	Node_t *current = list->head;

	while (current != NULL) {
		Node_t *aux = current;
		free(aux);
		current = current->next;
	}
	free(list);
}
