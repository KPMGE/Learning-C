// exercise: L4_3
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct 
{
  int day;
  int month;
  int year;
} Date;

void displayDate(Date someDate);
int isLeapYear(int year);
int qtdDaysMonth(int month, int year);
Date readDate();

int main(void)
{
  int qtdDates, i, qtdDaysSomeDate;
  Date someDate;

  scanf("%d", &qtdDates);
  for (i = 0; i < qtdDates; i++)
  {
    someDate = readDate();
    
    // adjusting date
    qtdDaysSomeDate = qtdDaysMonth(someDate.month, someDate.year);
    if (someDate.day < 1)
      someDate.day = 1;
    if (someDate.day > qtdDaysSomeDate)
      someDate.day = qtdDaysSomeDate;
    if (someDate.month < 1)
      someDate.month = 1;
    if (someDate.month > 12)
      someDate.month = 12;

    // displaying results
    displayDate(someDate);
    if (isLeapYear(someDate.year))
      printf(":Bisexto\n");
    else
      printf(":Normal\n");
  }

  return 0;
}

Date readDate()
{
  Date someDate;
  scanf("%d %d %d", &someDate.day, &someDate.month, &someDate.year);
  return someDate;
}

void displayDate(Date someDate)
{
  if (someDate.day < 10 && someDate.month < 10)
    printf("'0%d/0%d/%d'", someDate.day, someDate.month, someDate.year);
  else if (someDate.day < 10)
    printf("'0%d/%d/%d'", someDate.day, someDate.month, someDate.year);
  else if (someDate.month < 10)
    printf("'%d/0%d/%d'", someDate.day, someDate.month, someDate.year);
  else 
    printf("'%d/%d/%d'", someDate.day, someDate.month, someDate.year);
}

int isLeapYear(int year)
{
  if (year % 4 == 0)
  {
    if (year % 100 == 0)
    {
      if (year % 400 == 0)
        return True;
      else
        return False;
    }
    else
      return True;
  }
  else
    return False;
}

int qtdDaysMonth(int month, int year)
{
  if (month == 2)
    return (isLeapYear(year)) ? 29 : 28;
  if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
    return 30;
  else
    return 31;
}