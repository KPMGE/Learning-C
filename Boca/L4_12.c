// Exercise: L4_12
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  int registration;
  float p1, p2, p3;
} Student;

float calculateAverageStudent(Student someStudent);
Student readStudent();
void displayStudent(Student someStudent);

int main(void)
{
  int qtdStudents, i;
  Student student, studentWithGreaterAverage;
  float generalAverage = 0, greaterAverage;

  scanf("%d", &qtdStudents);

  for (i = 0; i < qtdStudents; i++)
  {
    student = readStudent();

    generalAverage += calculateAverageStudent(student);

    if (i == 0)
    {
      greaterAverage = calculateAverageStudent(student);
      studentWithGreaterAverage = student;
    }
    else if (calculateAverageStudent(student) > greaterAverage)
    {
      greaterAverage = calculateAverageStudent(student);
      studentWithGreaterAverage = student;
    }
  }

  generalAverage /= qtdStudents;

  printf("Maior media: ");
  displayStudent(studentWithGreaterAverage);
  printf("Media geral: %.2f", generalAverage);

  return 0;
}

float calculateAverageStudent(Student someStudent)
{
  return (someStudent.p1 + someStudent.p2 + someStudent.p3) / 3.0;
}

Student readStudent()
{
  Student student;
  scanf("%d %f %f %f", &student.registration, &student.p1, &student.p2, &student.p3);
  return student;
}

void displayStudent(Student someStudent)
{
  printf("mat:%d n1:%.2f n2:%.2f n3:%.2f\n", someStudent.registration, someStudent.p1, someStudent.p2, someStudent.p3);
}