#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(void) {
  // creating a student
  Student *student1 = createStudent();

  // reading student's data
  readStudent(student1);
  printf("\n");

  // displaying results
  displayStudent(student1);
  printf("student average: %.2f", calculateAverageStudent(student1));
  
  // releasing memory
  freeStudent(student1);

  return 0;
}