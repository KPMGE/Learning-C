// simple implementation of a class 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int age;
  int registration;
  float p1, p2, p3;
  float average;
} Student;

void readClass(Student students[], int amountstudents);
void displayStudent(Student someStudent);
void displayClass(Student students[], int amountstudents);
void calculateAverageStudents(Student students[], int amountStudents);
float calculateAverageClass(Student students[], int amountstudents);
Student findBestStudent(Student students[], int amountStudents);
Student* createClass(int amountStudent);

int main(void) {
  system("clear");
  char choice;
  int amount;
  float averageClass;

  printf("How many students do you want to add? ");
  scanf("%d", &amount);

  Student *class = createClass(amount);

  readClass(class, amount);
  calculateAverageStudents(class, amount);

  averageClass = calculateAverageClass(class, amount);
  printf("your class average is: %.3f\n", averageClass);
  printf("The best student is:\n");
  displayStudent(findBestStudent(class, amount));

  printf("\ndo you want to see all your class? (Y/N) ");
  scanf(" %c", &choice);
  if (choice == 'y' || choice == 'Y') {
    displayClass(class, amount);
  }
  free(class);

  system("figlet thank you!");

  return 0;
}

void readClass(Student students[], int amountstudents) {
  printf("Enter data:\n\n");
  for (int i = 0; i < amountstudents; i++) {
    printf("student%d:\n", i + 1);
    printf("name: ");
    scanf(" %[^\n]%*c", students[i].name);
    
    printf("age: ");
    scanf("%d", &students[i].age);

    printf("registration: ");
    scanf("%d", &students[i].registration);

    printf("p1: ");
    scanf("%f", &students[i].p1);
    printf("p2: ");
    scanf("%f", &students[i].p2);
    printf("p3: ");
    scanf("%f", &students[i].p3);
    printf("\n");
  }
}

void displayStudent(Student someStudent) {
  printf("name: %s\n", someStudent.name);
  printf("age: %d\n", someStudent.age);
  printf("registration: %d\n", someStudent.registration);
  printf("test results:\n");
  printf("p1: %.3f\np2: %.3f\np3: %.3f\n", someStudent.p1, someStudent.p2, someStudent.p3);
  printf("average: %.3f\n", someStudent.average);
}

void displayClass(Student students[], int amountstudents) {
  printf("\nYour students class is:\n");
  for (int i = 0; i < amountstudents; i++) {
    printf("Student%d:\n", i + 1);
    displayStudent(students[i]);
    printf("\n");
  }
}

void calculateAverageStudents(Student students[], int amountStudents) {
  float sum = 0;
  for (int i = 0; i < amountStudents; i++) {
    sum = students[i].p1 + students[i].p2 + students[i].p3;
    students[i].average = sum / 3;
  }
}

float calculateAverageClass(Student students[], int amountstudents) {
  float sum = 0;
  for (int i = 0; i < amountstudents; i++) {
    sum += students[i].average;
  }
  return sum / amountstudents;
}

Student findBestStudent(Student students[], int amountStudents) {
  int bestStudentPosition = 0;
  for (int i = 1; i < amountStudents; i++) {
    if (students[i].average > students[bestStudentPosition].average) {
      bestStudentPosition = i;
    }
  }
  return students[bestStudentPosition];
}

Student* createClass(int amountStudent) {
  Student *students = (Student *)malloc(amountStudent * sizeof(Student));

  return students;
}