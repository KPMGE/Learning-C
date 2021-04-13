#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"
#include "../include/linkedList.h"

int main(void) {
  // create some students
  Student_t* kevin = createStudent("Kevin", 18, 43124, 7.0, 8.5, 7.89);
  Student_t* laura = createStudent("Laura", 19, 51233, 5.0, 9.3, 6.89);
  Student_t* luana = createStudent("Luana", 25, 99343, 5.7, 6.5, 4.73);
  Student_t* karol = createStudent("Karol", 22, 75483, 9.2, 4.5, 5.33);

  // create a list of students
  LinkedList_t* listStudents = createLinkedList();

  // adding students to the list
  addNewHead(listStudents, laura);
  addNewHead(listStudents, kevin);

  // displaying students
  printf("----- ADDING STUDENTS WITH ADD HEAD ----\n\n");
  displayLinkedList(listStudents, (fptrDisplay)displayStudent);

  printf("\n\n----- ADDING MORE STUDENTS WITH ADD TAIL ----\n");
  addNewTail(listStudents, luana);
  addNewTail(listStudents, karol);
  displayLinkedList(listStudents, (fptrDisplay)displayStudent);

  // free allocated memory
  freeStudent(kevin);
  freeStudent(laura);
  freeStudent(luana);
  freeStudent(karol);
  freeLinkedList(listStudents);

  return 0;
}