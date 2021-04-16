// sample with opaque pointers 
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// pointer to function that given a certain data, displays it properly
typedef void (*fptrDisplay)(void*);
// pointer to function that allocate something
typedef void* (*fptrAllocate)();

// struct for a point
typedef struct _point {
  float x;
  float y;
} Point_t;

// struct for an employee
typedef struct _employee {
  char name[40];
  int age;
} Employee_t;

// function to create generic with function pointers
void* createGenericWithFunctionPointer(fptrAllocate allocateFunction);
// function to create a generic with amount of bytes
void* createGenericWithAmountOfBytes(size_t amountBytes);
// function to display whatever stuff
void displayStuff(void* data, fptrDisplay displayFunction);


// function to allocate an integer
int* createInteger();
// function to allocate a point
Point_t* createPoint();
// function to allocate a employee
Employee_t* createEmployee();

// functions to set values 
void setInt(int* integer, int value);
void setPoint(Point_t* pt, float x, float y);
void setEmployee(Employee_t* emp, char* name, int age);

// functions to display types
void displayInteger(int* num);
void displayPoint(Point_t* pt);
void displayEmployee(Employee_t* emp);


int main(void) {
  // create allocated integer variables
  int* num1 = (int*) createGenericWithFunctionPointer((fptrAllocate) createInteger);
  int* num2 = (int*) createGenericWithAmountOfBytes(sizeof(int));

  // setting values
  setInt(num1, 100);
  setInt(num2, 253);

  // displaying values
  printf("------- INTEGERS ------\n");
  printf("num1: ");
  displayStuff(num1, (fptrDisplay) displayInteger);
  printf("num2: ");
  displayStuff(num2, (fptrDisplay) displayInteger);


  // create allocated point variables
  Point_t* point1 = (Point_t*) createGenericWithFunctionPointer((fptrAllocate) createPoint);
  Point_t* point2 = (Point_t*) createGenericWithAmountOfBytes(sizeof(Point_t));

  // setting values
  setPoint(point1, 2.3, 5.5);
  setPoint(point2, 7.4, 9.1);

  // displaying values
  printf("\n\n------- POINTS ------\n");
  printf("point1: ");
  displayStuff(point1, (fptrDisplay) displayPoint);
  printf("point2: ");
  displayStuff(point2, (fptrDisplay) displayPoint);



  // create allocated employee variables
  Employee_t* emp1 = (Employee_t*) createGenericWithFunctionPointer((fptrAllocate) createEmployee);
  Employee_t* emp2 = (Employee_t*) createGenericWithAmountOfBytes(sizeof(Employee_t));

  // setting values
  setEmployee(emp1, "laura", 19);
  setEmployee(emp2, "karol", 23);

  // displaying values
  printf("\n\n------- EMPLOYEES ------\n");
  printf("employee1: ");
  displayStuff(emp1, (fptrDisplay) displayEmployee);
  printf("employee2: ");
  displayStuff(emp2, (fptrDisplay) displayEmployee);
  return 0;
}

void* createGenericWithFunctionPointer(fptrAllocate allocateFunction) {
  void* allocatedStuff = allocateFunction();
  return allocatedStuff;
}

void* createGenericWithAmountOfBytes(size_t amountBytes) {
  void* allocatedStuff = malloc(amountBytes);
  return allocatedStuff;
}

void displayStuff(void* data, fptrDisplay displayFunction) {
  displayFunction(data);
}

int* createInteger() {
  return (int*) malloc(sizeof(int));
}

Point_t* createPoint() {
  return (Point_t*) malloc(sizeof(Point_t));
}

Employee_t* createEmployee() {
  return (Employee_t*) malloc(sizeof(Employee_t));
}

void setInt(int* integer, int value) {
  *integer = value;
}

void setPoint(Point_t* pt, float x, float y) {
  pt->x = x;
  pt->y = y;
}

void setEmployee(Employee_t* emp, char* name, int age) {
  strcpy(emp->name, name);
  emp->age = age;
}

void displayInteger(int* num) {
  printf("%d\n", *num);
}

void displayPoint(Point_t* pt) {
  printf("(%.2f, %.2f)\n", pt->x, pt->y);
}

void displayEmployee(Employee_t* emp) {
  printf("name: %s\n", emp->name);
  printf("age: %d\n", emp->age);
}