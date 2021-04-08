#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

// structure for an employee
typedef struct _employee Employee_t;

// function to create a new employee
Employee_t* createEmployee(char* name, unsigned int age);
// function to get the name of an employee
char* getNameEmployee(Employee_t* employee);
// function to get the age of an employee
unsigned int getAgeEmployee(Employee_t* employee);
// function to set a new name for an employee
void setNameEmployee(Employee_t* employee, char* newName);
// function to set a new age for an employee
void setAgeEmployee(Employee_t* employee, unsigned int newAge);
// function to display an employee
void displayEmployee(Employee_t* employee);
// funtion to free a given employee
void freeEmployee(Employee_t* employee);
// function to compare two employees
int compareEmployees(Employee_t* employee1, Employee_t* employee2);

#endif