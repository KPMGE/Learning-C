#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "class.h"

typedef struct student {
  char name[50];
  int age;
  int registration;
  float p1, p2, p3;
} Student;

void readClass(Student *classStudents, int amountStudents) {
  printf("\nEnter your class: \n\n");
  for (int i = 0; i < amountStudents; i++) {
    readStudent(&classStudents[i]);
  }
}

void displayClass(Student *classStudents, int amountStudents) {
  printf("\nYour class is:\n\n");
  for (int i = 0; i < amountStudents; i++) {
    displayStudent(&classStudents[i]);
    printf("\n");
  }
}

void freeClass(Student *classStudents) {
  free(classStudents);
}

float calculateAverageClass(Student *classStudents, int amountStudents) {
  float sum = 0;

  for (int i = 0; i < amountStudents; i++) {
    sum += calculateAverageStudent(&classStudents[i]);
  }

  return sum / amountStudents;
}

Student* findBestStudent(Student *classStudents, int amountStudents) {
  int position = 0;
  float averageSomeStudent, averageBestStudent;
  averageBestStudent = calculateAverageStudent(&classStudents[0]);
  
  for (int i = 1; i < amountStudents; i++) {
    averageSomeStudent = calculateAverageStudent(&classStudents[i]);
    
    if (averageSomeStudent > averageBestStudent) {
      averageBestStudent = averageSomeStudent;
      position = i;
    }
  }

  return &classStudents[position];
}

Student* createClass(int amountStudents) {
  Student *class = (Student *)malloc(amountStudents * sizeof(Student));
  if (class == NULL) {
    printf("Invalid Pointer!");
    exit(1);
  }
}