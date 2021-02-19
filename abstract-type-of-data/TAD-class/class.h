#include "student.h"
// function that read class students
void readClass(Student *classStudents, int amountStudents);
// function that displays the class 
void displayClass(Student *classStudents, int amountStudents);
// function that releases a class
void freeClass(Student *classStudents);
// function that calculates the average of the class
float calculateAverageClass(Student *classStudents, int amountStudents);
// function that finds the best student of the class
Student* findBestStudent(Student *classStudents,int amountStudents);
// function that creates a class
Student* createClass(int amountStudents);