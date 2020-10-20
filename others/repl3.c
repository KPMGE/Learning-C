// Exercise: third repl.it
// Author: Kevin Carvalho De Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int isLeapYear(int year);
int centuryCode(int year);
int yearCode(int year);
int monthCode(int month);
int dayCode(int year, int month, int day);
void displayDay(int dayCode);

int main(void)
{
  int year, month, day, weekDay;
  char a, finalCharacter;

  scanf(" %d-%d-%d ", &day, &month, &year);
  weekDay = dayCode(year, month, day);
  displayDay(weekDay);

  while(scanf("%d-%d-%d ", &day, &month, &year) == 3)
  {
    printf(", ");
    weekDay = dayCode(year, month, day);
    displayDay(weekDay);
  }

  return 0;
}

int isLeapYear(int year)
{
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? True : False;
}

int centuryCode(int year)
{
  if(year >= 2000 && year < 2100)
    return 6;
  if((year >= 1700 && year < 1800) || (year >= 2100 && year < 2200))
    return 4;
  if((year >= 1800 && year < 1900) || (year >= 2200 && year < 2300))
    return 2;
  if((year >= 1900 && year < 2000) || (year >= 2300))
    return 0;
  else
    return 1000;
}

int yearCode(int year)
{
  int twoLastDigits, sum;
  twoLastDigits = year % 100;
  sum = twoLastDigits + (twoLastDigits / 4);
  return sum % 7;
}

int monthCode(int month)
{
  if(month == 1 || month == 10)
    return 0;
  if(month == 2|| month == 11 || month == 3)
    return 3;
  if(month == 4 || month == 7)
    return 6;
  if(month == 5)
    return 1;
  if(month == 6)
    return 4;
  if(month == 8)
    return 2;
  if(month == 9 || month == 12)
    return 5;
  else
    return 1000;
}

int dayCode(int year, int month, int day)
{
  int day_aux = yearCode(year) + monthCode(month) + centuryCode(year) + day;

  if (isLeapYear(year) && (month == 2 || month == 1))
    day_aux--;

  return day_aux % 7;
}

void displayDay(int dayCode)
{
  switch (dayCode)
  {
    case 0:
      printf("DOMINGO");
      break;

    case 1:
      printf("SEGUNDA");
      break;

    case 2:
      printf("TERCA");
      break;

    case 3:
      printf("QUARTA");
      break;

    case 4:
      printf("QUINTA");
      break;

    case 5:
      printf("SEXTA");
      break;

    case 6:
      printf("SABADO");
      break;
  }
}