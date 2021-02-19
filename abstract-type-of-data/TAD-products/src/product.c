#include <stdio.h>
#include <stdlib.h>
#include "../header/product.h"

typedef struct product {
  char name[50];
  int amount;
  float price;
} Product;

void readProduct(Product *product) {
  printf("name: ");
  scanf(" %[^\n]%*c", product->name);

  printf("amount: ");
  scanf("%d", &product->amount);

  printf("price: ");
  scanf("%f", &product->price);
}

void displayProduct(Product *product) {
  printf("name: %s\n", product->name);
  printf("amount: %d\n", product->amount);
  printf("price: R$%.2f\n", product->price);
}

void freeProduct(Product *product) {
  free(product);
}

Product *createProduct() {
  Product *allocatedProduct = (Product *)malloc(sizeof(Product));

  if (allocatedProduct == NULL) {
    printf("Invalid Pointer");
    exit(1);
  }

  return allocatedProduct;
}