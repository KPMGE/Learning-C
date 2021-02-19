#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "list-products.h"

typedef struct product {
  char name[50];
  int amount;
  float price;
} Product;


void readListProducts(Product *listProducts, int amountProducts) {
  printf("Enter all your products:\n\n");

  for (int i = 0; i < amountProducts; i++) {
    printf("Product %d:\n", i + 1);
    readProduct(&listProducts[i]);
    printf("\n");
  }
}

void displayListProducts(Product *listProducts, int amountProducts) {
  printf("\nYour products are: \n");

  for (int i = 0; i < amountProducts; i++) {
    printf("Product %d:\n", i + 1);
    displayProduct(&listProducts[i]);
    printf("\n");
  }
}

void freeListProducts(Product listProducts[]) {
  free(listProducts);
}

float getBruteValue(Product *listProducts, int amountProducts) {
  float bruteValue = 0;

  for (int i = 0; i < amountProducts; i++) {
    bruteValue += listProducts[i].price * listProducts[i].amount;
  }

  return bruteValue;
}

Product* createListProducts(int amountProducts) {
  Product *allocatedList = (Product *)malloc(amountProducts * sizeof(Product));

  if (allocatedList == NULL) {
    printf("Invalid Pointer!");
    exit(1);
  }

  return allocatedList;
}