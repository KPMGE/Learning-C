// sample with void pointers
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// type point
typedef struct _point {
  float x;
  float y;
} Point_t;

// type circle
typedef struct _circle {
  Point_t center;
  float radius;
} Circle_t;

// type student
typedef struct _student {
  char name[50];
  int age;
  int registration;
} Student_t;

// type employee
typedef struct _employee {
  char name[50];
  int age;
} Employee_t;


// function pointer to display data
typedef void (*fptrDisplay)(void*);

// function to display an integer
void displayInt(int* num);
// function to display a float
void displayFloat(float* num);
// function to display a point
void displayPoint(Point_t* point);
// function to display a circle
void displayCircle(Circle_t* circle);
// function to display a student
void displayStudent(Student_t* student);
// function to display an employee
void displayEmployee(Employee_t* employee);
// generic function to display all data types
void displayAllTypes(void* data, fptrDisplay displayFunc);

int main(void) {
  // create simple types
  int IntNum = 100;
  float FloatNum = 30.23;

  // create a local point
  Point_t point;
  point.x = 3.3;
  point.y = 6.7;

  // create a local circle
  Circle_t circle;
  circle.center.x = 5.23;
  circle.center.y = 34.3;
  circle.radius = 24.5;

  // create a local employee
  Employee_t employee;
  strcpy(employee.name, "Ricardo");
  employee.age = 35;

  // create a local student
  Student_t student;
  strcpy(student.name, "Kevin");
  student.age = 19;
  student.registration = 351234;


  // display all data by using function pointers
  printf("Integer: ");
  displayAllTypes(&IntNum, (fptrDisplay) displayInt);
  printf("\n");

  printf("float: ");
  displayAllTypes(&FloatNum, (fptrDisplay) displayFloat);
  printf("\n");

  printf("point: ");
  displayAllTypes(&point, (fptrDisplay) displayPoint);
  printf("\n");

  printf("circle: ");
  displayAllTypes(&circle, (fptrDisplay) displayCircle);
  printf("\n");

  printf("employee: ");
  displayAllTypes(&employee, (fptrDisplay) displayEmployee);
  printf("\n");

  printf("student: ");
  displayAllTypes(&student, (fptrDisplay) displayStudent);

  return 0;
}

void displayInt(int* num) {
  printf("%d\n", *num);
}

void displayFloat(float* num) {
  printf("%f\n", *num);
}

void displayPoint(Point_t* point) {
  printf("(%.2f, %.2f)\n", point->x, point->y);
}

void displayCircle(Circle_t* circle) {
  displayPoint(&circle->center);
  printf("r: %.3f\n", circle->radius);
}

void displayStudent(Student_t* student) {
  printf("\nname: %s\n", student->name);
  printf("age: %d\n", student->age);
  printf("registration: %d\n", student->registration);
}

void displayEmployee(Employee_t* employee) {
  printf("\nname: %s\n", employee->name);
  printf("age: %d\n", employee->age);
}

void displayAllTypes(void* data, fptrDisplay displayFunc) {
  displayFunc(data);
}
