#include <stdio.h>
#include <stdlib.h>
#include "student.h"

struct student {
  char name[50];
  int age;
  int registration;
  float p1, p2, p3;
};

void readStudent(Student *student) {
  printf("Enter student data:\n");
  printf("name: ");
  scanf("%[^\n]%*c", student->name);
  printf("age: ");
  scanf("%d", &student->age);
  printf("registration: ");
  scanf("%d", &student->registration);
  printf("p1: ");
  scanf("%f", &student->p1);
  printf("p2: ");
  scanf("%f", &student->p2);
  printf("p3: ");
  scanf("%f", &student->p3);
}

void displayStudent(Student *student) {
  printf("Student's data:\n");
  printf("name: %s\n", student->name);
  printf("age: %d\n", student->age);
  printf("registration: %d\n", student->registration);
  printf("p1: %.2f\n", student->p1);
  printf("p2: %.2f\n", student->p2);
  printf("p3: %.2f\n", student->p3);
}

void freeStudent(Student *student) {
  free(student);
}

float calculateAverageStudent(Student *student) {
  return (student->p1 + student->p2 + student->p3) / 3;
}

Student* createStudent() {
  Student *allocatedStudent = (Student *)malloc(sizeof(Student));

  if (allocatedStudent == NULL) {
    printf("Invalid Pointer!");
    exit(1);
  }
  return allocatedStudent;
}

