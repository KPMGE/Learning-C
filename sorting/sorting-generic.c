// implementation of a generic sorting function
// Author: Kevin Carvalho de Jesus

#include <stdio.h>

// pointer to comparison function
typedef int (*COMPARE_FUNC)(int num1, int num2);

// prototypes
int isGreaterThan(int num1, int num2);
int isSmallerThan(int num1, int num2);
void swap(int* val1, int* val2);
void sortGeneric(int* vector, int size, COMPARE_FUNC compare);
void displayVector(int* vect, int size);

int main(void) {
  int vect[] = { 3, 53, 2, 6, 1, 0 };
  
  printf("Original vector: ");
  displayVector(vect, 6);

  // sorting with greatestValue function
  sortGeneric(vect, 6, isGreaterThan);
  printf("\nSorted vector with isGreaterThan(): "); 
  displayVector(vect, 6);

  // sorting with smallestValue function
  sortGeneric(vect, 6, isSmallerThan);
  printf("\nSorted vector with isSmallerThan(): "); 
  displayVector(vect, 6);

  return 0;
}

int isGreaterThan(int num1, int num2) {
  return (num1 > num2);
}

int isSmallerThan(int num1, int num2) {
  return (num1 < num2);
}

void swap(int* val1, int* val2) {
  int aux = *val1;
  *val1 = *val2;
  *val2 = aux;
}

void sortGeneric(int* vector, int size, COMPARE_FUNC compare) {
  for (int i = 0; i < (size - 1); i++) {
    for (int j = 0; j < (size - i - 1); j++) {
      if (compare(vector[j], vector[j + 1])) {
        swap(&vector[j], &vector[j + 1]);
      }
    }
  }
}

void displayVector(int* vect, int size) {
  printf("[ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", vect[i]);
  }
  printf("]");
}
