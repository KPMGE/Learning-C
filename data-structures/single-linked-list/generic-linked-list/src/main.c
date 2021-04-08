// Simple implementation of a linked list
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/employee.h"
#include "../include/linked-list.h"

int main(void) {
  // creating employees
  Employee_t* kevin = createEmployee("Kevin", 20);
  Employee_t* laura = createEmployee("Laura", 19);
  Employee_t* luana = createEmployee("Luana", 39);
  Employee_t* karol = createEmployee("karol", 23);

  // create a blank linked list
  LinkedList_t* listEmployees = createLinkedList();

  // adding some employees
  addNewHead(listEmployees, kevin);
  addNewHead(listEmployees, laura);
  addNewHead(listEmployees, luana);

  // displaying original linked list
  printf("---------- ORIGINAL LINKED LIST ----------\n\n");
  displayLinkedList(listEmployees, (fptrDisplay) displayEmployee);

  // adding new employee at the end of list
  printf("\n\n---------- ADDING NEW TAIL ----------\n\n");
  addNewTail(listEmployees, karol);
  displayLinkedList(listEmployees, (fptrDisplay) displayEmployee);

  // deleting an employee
  printf("\n\n---------- DELETING A NODE ----------\n\n");
  Node_t* employeeToDelete = getNodeLinkedList(listEmployees, (fptrCompare) compareEmployees,luana);
  deleteNode(listEmployees, employeeToDelete);
  displayLinkedList(listEmployees, (fptrDisplay) displayEmployee);

  // freeing allocated memory
  freeLinkedList(listEmployees);
  freeEmployee(kevin);
  freeEmployee(laura);
  freeEmployee(luana);
  freeEmployee(karol);

  return 0;
}