#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[30];
  int age;
} Person;

Person* createVectorToPeople(int qtd);
void readPeople(Person *vectorPeople, int qtdPeople);
void displayPeople(Person *vectorPeople, int qtdPeople);

int main(void) {
  int qtdPeople;

  printf("how many people do you want to add? ");
  scanf("%d", &qtdPeople);

  Person *setOfPeople = createVectorToPeople(qtdPeople);

  readPeople(setOfPeople, qtdPeople);
  displayPeople(setOfPeople, qtdPeople);

  free(setOfPeople);

  return 0;
}

Person* createVectorToPeople(int qtd) {
  Person *vectorToPeople;
  vectorToPeople = (Person *) malloc(qtd * sizeof(Person));
}

void readPeople(Person *vectorPeople, int qtdPeople) {
  for (int i = 0; i < qtdPeople; i++) {
    printf("Person: %d\n", i + 1);
    printf("Enter name: ");
    scanf("%s", vectorPeople[i].name);
    printf("Enter age: ");
    scanf("%d", &vectorPeople[i].age);
  }
}

void displayPeople(Person *vectorPeople, int qtdPeople) {
  printf("\n\nPeoples:\n");
  for (int i = 0; i < qtdPeople; i++) {
    printf("Person %d:\n", i + 1);
    printf("Name: %s\n", vectorPeople[i].name);
    printf("Age: %d\n\n", vectorPeople[i].age);
  }
}