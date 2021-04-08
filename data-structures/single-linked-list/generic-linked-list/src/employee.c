#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/employee.h"

struct _employee {
  char *name;
  unsigned int age;
};

Employee_t* createEmployee(char* name, unsigned int age) {
  Employee_t* allocatedEmployee = (Employee_t*) malloc(sizeof(Employee_t));

  if (allocatedEmployee == NULL) {
    printf("Insuficient space!");
    exit(1);
  }

  allocatedEmployee->name = strdup(name);
  allocatedEmployee->age = age;

  return allocatedEmployee;
}

char* getNameEmployee(Employee_t* employee) {
  return employee->name;
}

unsigned int getAgeEmployee(Employee_t* employee) {
  return employee->age;
}

void setNameEmployee(Employee_t* employee, char* newName) {
  strcpy(employee->name, newName);
}

void setAgeEmployee(Employee_t* employee, unsigned int newAge) {
  employee->age = newAge;
}

void displayEmployee(Employee_t* employee) {
  printf("name: %s\n", getNameEmployee(employee));
  printf("age: %d\n", getAgeEmployee(employee));
}

int compareEmployees(Employee_t* employee1, Employee_t* employee2) {
  return strcmp(getNameEmployee(employee1), getNameEmployee(employee2));
}

void freeEmployee(Employee_t* employee) {
  free(employee->name);
  free(employee);
}