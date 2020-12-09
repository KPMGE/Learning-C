// Program with a simple example about bubble sort ordenation method
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

void readVector(int vector[], int size);
void displayVector(int vector[], int size);
void bubbleSortAscendingOrder(int vector[], int size);
void bubbleSortDecrescendingOrder(int vector[], int size);

int main(void)
{
  int size, choiceUser; 

  printf("Enter size to vector: ");
  scanf("%d", &size);

  int vector[size];

  readVector(vector, size);

  printf("which mode do you want sorting your vector?\n");
  printf("1 - Ascending Order\n");
  printf("2 - Decrescending Order\n> ");
  scanf("%d", &choiceUser);

  switch(choiceUser)
  {
    case 1:
      bubbleSortAscendingOrder(vector, size);
      break;

    case 2:
      bubbleSortDecrescendingOrder(vector, size);
      break;

    default: 
      printf("Invalid choice!");
      exit(1);
  }

  displayVector(vector, size);

  return 0;
}

void readVector(int vector[], int size)
{
  int i;

  printf("Enter your vector:");

  for (i = 0; i < size; i++)
    scanf("%d", &vector[i]);
}

void displayVector(int vector[], int size)
{
  int i;

  for (i = 0; i < size; i++)
    printf("%d ", vector[i]);
  
}

void bubbleSortAscendingOrder(int vector[], int size)
{
  int i, j, aux;

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < (size - 1); j++)
    {
      if (vector[j] > vector[j + 1])
      {
        aux = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = aux;
      }
    }
  }
}

void bubbleSortDecrescendingOrder(int vector[], int size)
{
  int i, j, aux;

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < (size - 1); j++)
    {
      if (vector[j] < vector[j + 1])
      {
        aux = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = aux;
      }
    }
  }
}
