#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"

struct _student {
  char* name;
  unsigned int age;
  int registration;
  float p1;
  float p2;
  float p3;
};

Student_t* createStudent(char* name, unsigned int age, int registration, float p1, float p2, float p3) {
  Student_t* allocatedStudent = (Student_t*) malloc(sizeof(Student_t));

  allocatedStudent->name = strdup(name);
  allocatedStudent->age = age;
  allocatedStudent->registration = registration;
  allocatedStudent->p1 = p1;
  allocatedStudent->p2 = p2;
  allocatedStudent->p3 = p3;

  return allocatedStudent;
}

char* getNameStudent(Student_t* student) {
  return student->name;
}

unsigned int getAgeStudent(Student_t* student) {
  return student->age;
}

int getRegistrationStudent(Student_t* student) {
  return student->registration;
}

float getP1Student(Student_t* student) {
  return student->p1;
}

float getP2Student(Student_t* student) {
  return student->p2;
}

float getP3Student(Student_t* student) {
  return student->p3;
}

float calculateAverageStudent(Student_t* student) {
  float sum = getP1Student(student) + getP2Student(student) + getP3Student(student);
  return sum / 3;
}

void displayStudent(Student_t* student) {
  printf("\nName: %s\n", getNameStudent(student));
  printf("Age: %d\n", getAgeStudent(student));
  printf("Registration: %d\n", getRegistrationStudent(student));
  printf("P1: %.3f\n", getP1Student(student));
  printf("P2: %.3f\n", getP2Student(student));
  printf("P3: %.3f\n", getP3Student(student));
  printf("Average: %.3f", calculateAverageStudent(student));
}

void freeStudent(Student_t* student) {
  free(student->name);
  student->name = NULL;
  free(student);
  student = NULL;
}
