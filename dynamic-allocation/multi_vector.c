#include <stdio.h>
#include <stdlib.h>

int* multiVector(int* vet, int size, int number);
void read_vector(int* vet, int size);

int main(void)
{
  int size, number;
  printf("Enter the size for vector: ");
  scanf("%d", &size);
  printf("Enter the number for multiplication: ");
  scanf("%d", &number);

  int vector[size], *vector2;

  read_vector(vector, size);
  vector2 = multiVector(vector, size, number);

  printf("your vector is: ");
  for(int i = 0; i < size; i++)
    printf("%d ", vector2[i]);

  free(vector2);

  return 0;
}

int* multiVector(int* vet, int size, int number)
{
  int* vetAllocated;

  //alocating vector
  vetAllocated = (int *) malloc(size * sizeof(int));

  for(int i = 0; i < size; i++)
    vetAllocated[i] = vet[i] * 2;

  return vetAllocated;
}

void read_vector(int* vet, int size)
{
  printf("Enter vector:");
  for(int i = 0; i < size; i++)
    scanf("%d", &vet[i]);
}
