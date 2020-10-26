// exercise1
// author: Kevin Carvalho de jesus

#include <stdio.h>
#include <stdlib.h>

char concept(float grade, int absences);

int main(void)
{
  float grade;
  int absences;

  scanf("%f %d", &grade, &absences);

  printf("%c", concept(grade, absences));

  return 0;
}

char concept(float grade, int absences)
{
  if (absences <= 20)
  {
    if (grade >= 0.0 && grade <= 3.9)
      return 'E';
    if (grade >= 4.0 && grade <= 4.9)
      return 'D';
    if (grade >= 5.0 && grade <= 7.4)
      return 'C';
    if (grade >= 7.5 && grade <= 8.9)
      return 'B';
    if (grade >= 9.0 && grade <= 10.0)
      return 'A';
  }
  else
  {
    if (grade >= 0.0 && grade <= 3.9)
      return 'E';
    if (grade >= 4.0 && grade <= 4.9)
      return 'E';
    if (grade >= 5.0 && grade <= 7.4)
      return 'D';
    if (grade >= 7.5 && grade <= 8.9)
      return 'C';
    if (grade >= 9.0 && grade <= 10.0)
      return 'B';
  }
}