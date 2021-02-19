#include <stdio.h>
#include <stdlib.h>
#include "../header/product.h"
#include "../header/list-products.h"

typedef struct product {
  char name[50];
  int amount;
  float price;
} Product;


void readListProducts(Product *listProducts, int amountProducts) {
  printf("\n---------- Enter all your products ----------\n\n");

  for (int i = 0; i < amountProducts; i++) {
    printf("Product %d:\n", i + 1);
    readProduct(&listProducts[i]);
    printf("\n");
  }
}

void displayListProducts(Product *listProducts, int amountProducts) {
  printf("\n---------- Your products are ----------\n");

  for (int i = 0; i < amountProducts; i++) {
    printf("Product %d:\n", i + 1);
    displayProduct(&listProducts[i]);
    printf("\n");
  }
}

void saveOutcomeInAFile(FILE *file, Product *listProducts, int amountProducts, float bruteValue, float expenses) {
  if (file == NULL) {
    printf("You cannot open that file!");
    exit(1);
  }

  // displaying results
  fprintf(file, "---------- Results ----------\n\n");
  fprintf(file, "\nThe brute value is: R$%.2f\n", bruteValue);
  fprintf(file, "Your expenses were: R$%.2f\n", expenses);
  fprintf(file, "Your gain was: R$%.2f\n\n", bruteValue - expenses);

  // saving list of products
  fprintf(file, "---------- Your products are ----------\n\n");
  for (int i = 0; i < amountProducts; i++) {
    fprintf(file, "Product %d:\n", i + 1);
    fprintf(file, "name: %s\n", listProducts[i].name);
    fprintf(file, "amount: %d\n", listProducts[i].amount);
    fprintf(file, "price: R$%.2f\n", listProducts[i].price);
    fprintf(file, "\n");
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