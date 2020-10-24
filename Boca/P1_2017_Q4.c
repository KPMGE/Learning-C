// Exercise: P1_2017_Q4
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int isEqual(int hour1, int minute1, int second1, int hour2, int minute2, int second2);
int greaterTimeSum(int hour1, int minute1, int second1, int hour2, int minute2, int second2);
int algarismDozen(int sum);

int main(void)
{
  int hour1, minute1, second1, hour2, minute2, second2;
  int sum;

  scanf("%d %d %d %d %d %d", &hour1, &minute1, &second1, &hour2, &minute2, &second2);

  if(isEqual(hour1, minute1, second1, hour2, minute2, second2))
    printf("IGUAIS");
  else
  {
    sum = greaterTimeSum(hour1, minute1, second1, hour2, minute2, second2);
    printf("RESP:%d", algarismDozen(sum));
  }

  return 0;
}

int isEqual(int hour1, int minute1, int second1, int hour2, int minute2, int second2)
{
  return ((hour1 == hour2) && (minute1 == minute2) && (second1 == second2)) ? True : False;
}

int greaterTimeSum(int hour1, int minute1, int second1, int hour2, int minute2, int second2)
{
  int sum1 = hour1 + minute1 + second1;
  int sum2 = hour2 + minute2 + second2;

  if (hour1 > hour2)
    return sum1;
  if (minute1 > minute2)
    return sum1;
  else if(minute1 < minute2)
    return sum2;
  else if (second1 > second2)
    return sum1;
  else
    return sum2;
}

int algarismDozen(int sum)
{
  int algarism;

  if(sum < 10)
    return 0;

  algarism = sum % 100;
  algarism /= 10;
  return algarism;
}