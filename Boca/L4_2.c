// exercise: L4_2
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
int isSameYear(Date date1, Date date2);
int qtdDaysMonth(int month, int year);
Date readDate();
Date adjustDate(Date someDate);
Date nextDate(Date someDate);

int main(void)
{
  Date firstDate, lastDate;

  firstDate = readDate();
  lastDate = readDate();
  firstDate = adjustDate(firstDate);
  lastDate = adjustDate(lastDate);

  do 
  {
    displayDate(firstDate);
    firstDate = nextDate(firstDate);
  } while (!isSameYear(firstDate, lastDate));

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
    printf("'0%d/0%d/%d'\n", someDate.day, someDate.month, someDate.year);
  else if (someDate.day < 10)
    printf("'0%d/%d/%d'\n", someDate.day, someDate.month, someDate.year);
  else if (someDate.month < 10)
    printf("'%d/0%d/%d'\n", someDate.day, someDate.month, someDate.year);
  else 
    printf("'%d/%d/%d'\n", someDate.day, someDate.month, someDate.year);
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

int isSameYear(Date date1, Date date2)
{
  return ((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year));
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

Date adjustDate(Date someDate)
{
  int qtdDaysSomeDate = qtdDaysMonth(someDate.month, someDate.year);

  if (someDate.day > qtdDaysSomeDate)
    someDate.day = qtdDaysSomeDate;
  else if (someDate.day < 1)
    someDate.day = 1;
  if (someDate.month > 12)
    someDate.month = 12;
  else if (someDate.month < 1)
    someDate.month = 1;

  return someDate;
}

Date nextDate(Date someDate)
{
  int qtdDaysSomeDate = qtdDaysMonth(someDate.month, someDate.year);

  if (someDate.month == 12 && qtdDaysSomeDate == someDate.day)
  {
    someDate.day = 1;
    someDate.month = 1;
    someDate.year++;
  }
  else if (someDate.day == qtdDaysSomeDate)
  {
    someDate.day = 1;
    someDate.month++;
  }
  else if (someDate.day < qtdDaysSomeDate)
    someDate.day++;
  
  else if (someDate.month < 12)
    someDate.month++;

  return someDate;
}