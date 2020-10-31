// Exercise: L4_9
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define True 1
#define False 0

typedef struct
{
  char name;
  float height;
  float weight;
} Person;

float calculateImcPerson(Person person);
int isTallerThan(Person person1, Person person2);
int isShorterThan(Person person1, Person person2);
Person readPerson(void);
void displayPerson(Person person);

int main(void)
{
  int qtdPeople, i;
  Person person, tallestPerson, shortestPerson;

  scanf("%d", &qtdPeople);
  for (i = 0; i < qtdPeople; i++)
  {
    person = readPerson();
    if (i == 0)
    {
      tallestPerson = person;
      shortestPerson = person;
    }
    else if (isShorterThan(person, shortestPerson))
      shortestPerson = person;
    else if (isTallerThan(person, tallestPerson))
      tallestPerson = person;
  }

  printf("Alta: ");
  displayPerson(tallestPerson);
  printf("\nBaixa: ");
  displayPerson(shortestPerson);

  return 0;
}

float calculateImcPerson(Person person)
{
  return person.weight / pow(person.height, 2);
}

int isTallerThan(Person person1, Person person2)
{
  return (person1.height > person2.height) ? True : False;
}

int isShorterThan(Person person1, Person person2)
{
  return (person1.height < person2.height) ? True : False;
}

Person readPerson(void)
{
  Person person;
  scanf(" %c,%f,%f", &person.name, &person.height, &person.weight);
  return person;
}

void displayPerson(Person person)
{
  printf("N:%c A:%.2f P:%.2f I:%.2f", person.name, person.height, person.weight, calculateImcPerson(person));
}