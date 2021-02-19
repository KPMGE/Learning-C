#include "product.h"
// exported type
typedef struct product Product;
// function that read a list of products
void readListProducts(Product *listProducts, int amountProducts);
// function that displays the list of products
void displayListProducts(Product *listProducts, int amountProducts);
// function that saves the outcomes in a file
void saveOutcomeInAFile(FILE *file, Product *listProducts, int amountProducts, float bruteValue, float expenses);
// function that releases an allocated list of products
void freeListProducts(Product *listProducts);
// function that calculates the brute products value
float getBruteValue(Product *listProducts, int amountProducts);
// function that creates a vector to products
Product* createListProducts(int amountProducts);