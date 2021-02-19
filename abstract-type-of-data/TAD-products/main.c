#include <stdio.h>
#include <stdlib.h>
#include "./header/product.h" 
#include "./header/list-products.h"

float readExpenses();
 
int main(void) {
  // clear screen
  system("clear");

  char choiceUser;
  int amountProducts;
  float totalExpenses, bruteValue;

  printf("how many products do you want to add? ");
  scanf("%d", &amountProducts);

  // creating allocated list
  Product *listProducts = createListProducts(amountProducts);

  // reading list
  readListProducts(listProducts, amountProducts);

  // reading expenses
  totalExpenses = readExpenses();
  bruteValue = getBruteValue(listProducts, amountProducts);

  // clear screen
  system("clear");

  // displaying results
  printf("\nThe brute value is: R$%.2f\n", bruteValue);
  printf("Your expenses were: R$%.2f\n", totalExpenses);
  printf("Your gain was: R$%.2f\n\n", bruteValue - totalExpenses);

  printf("do you want to see all your list: (Y/N) ");
  scanf(" %c", &choiceUser);

  if (choiceUser == 'y' || choiceUser == 'Y') {
    displayListProducts(listProducts, amountProducts);
  }

  printf("do you want to save your results in a file? (Y/N) ");
  scanf(" %c", &choiceUser);

  if (choiceUser == 'y' || choiceUser == 'Y') {
    FILE *products = fopen("results.txt", "w");
  
    saveOutcomeInAFile(products, listProducts, amountProducts, bruteValue, totalExpenses);

    fclose(products);
  }

  system("clear && figlet Thank you!");

  // releasing allocated memory
  freeListProducts(listProducts);

  return 0;
}

float readExpenses() {
  float sum = 0, value;
  printf("Enter your expenses:\n(Enter 0 to stop)\n");

  do {
    scanf("%f", &value);
    sum += value;
  } while(value != 0);

  return sum;
}