// Exercise: L4_8 
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  float weight;
  float numberOfAnimals;
  float valueFeed;
  float percentageFeed;
} Animal;

Animal readAnimal(void);
float amountFeed(Animal animal);
float calculatePriceAnimal(Animal animal);

int main(void)
{
  float totalPrice = 0; 
  Animal animal;
  int i, qtdAnimals;

  scanf("%d", &qtdAnimals);

  for (i = 0; i < qtdAnimals; i++)
  {
    animal = readAnimal();
    totalPrice += calculatePriceAnimal(animal);
  }

  printf("Valor total: %.2f reais", totalPrice);

  return 0;
}

Animal readAnimal(void)
{
  Animal animal;
  scanf("%f %f %f %f", &animal.numberOfAnimals, &animal.percentageFeed, &animal.weight, &animal.valueFeed);
  return animal;
}

float amountFeed(Animal animal)
{
  return (animal.percentageFeed * animal.weight) / 100.0;
}

float calculatePriceAnimal(Animal animal)
{
  return amountFeed(animal) * animal.valueFeed * animal.numberOfAnimals;
}