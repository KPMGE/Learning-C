// simple program for a class of students
// author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "class.h"

int main(void) {
  // cleaning screen
  system("clear");

  char choice;
  int amountStudents;
  float averageClass;

  printf("how many students do you want to add? ");
  scanf("%d", &amountStudents);

  // creating vector to class of students
  Student *classStudents = createClass(amountStudents);
  Student *bestStudent;
  readClass(classStudents, amountStudents);

  // cleaning screen
  system("clear");

  // calculating average of the class and displaying it
  averageClass = calculateAverageClass(classStudents, amountStudents);
  printf("\nthe average of that class is: %.2f\n", averageClass);

  // finding the best student and displayng his
  printf("the best student is: \n\n");
  bestStudent = findBestStudent(classStudents, amountStudents);
  displayStudent(bestStudent);
  printf("average: %.2f", calculateAverageStudent(bestStudent));

  // asking for user if he want to see the whole class
  printf("\n\ndo you want to see all your class? (Y/N) ");
  scanf(" %c", &choice);
  if (choice == 'y' || choice == 'Y') {
    displayClass(classStudents, amountStudents);
  }

  // cleaning allocated vector
  freeClass(classStudents);

  return 0;
}