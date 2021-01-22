// program that calculates your gain given some products

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
  char name[30];
  int amount;
  float price;
} Product;

void displayProducts(Product products[], int amount);
void doOperations();
void displayResults(Product products[], int amountProducts, float totalExpenses, float bruteValue, char userChoice);
Product *readProducts(int amount);
float readExpenses(void);
float calculateSumOfProducts(Product products[], int amount);

int main(void)
{
  doOperations();

  return 0;
}

void doOperations()
{
  char userChoice, userChoice2, userChoice3;
  int amountOfBrute, amountExpenses;
  float bruteValue, totalExpenses;

  printf("-------------- Calculing brute value ------------\n\n");
  printf("How much products do you want to add? ");
  scanf("%d", &amountOfBrute);

  Product *userProducts = readProducts(amountOfBrute);
  bruteValue = calculateSumOfProducts(userProducts, amountOfBrute);

  printf("\n-------------- Calculing expenses --------------\n\n");
  totalExpenses = readExpenses();

  printf("do you want to save your results in a file? (S/N)? ");
  scanf(" %c", &userChoice);
  printf("do you want to see all your products and save them in a file? (S/N) ?");
  scanf(" %c", &userChoice2);

  // displaying results
  displayResults(userProducts, amountOfBrute, totalExpenses, bruteValue, userChoice);

  if (userChoice2 == 's' || userChoice2 == 'S') 
  {
    displayProducts(userProducts, amountOfBrute);
  }

  free(userProducts);
}

void displayResults(Product products[], int amountProducts, float totalExpenses, float bruteValue, char userChoice)
{
  float liquidValue = bruteValue - totalExpenses;

  printf("\n-------------- Resulsts ------------\n\n");
  printf("Your expenses are: %.2fR$\n", totalExpenses);
  printf("Your brute value is: %.2fR$\n", bruteValue);
  printf("Your gain was: %.2fR$\n", liquidValue);

  if (userChoice == 's' || userChoice == 'S')
  {
    FILE *resultsFile = fopen("results.txt", "w");
    fprintf(resultsFile, "\n-------------- Resulsts ------------\n\n");
    fprintf(resultsFile, "Your expenses are: %.2fR$\n", totalExpenses);
    fprintf(resultsFile, "Your brute value is: %.2fR$\n", bruteValue);
    fprintf(resultsFile, "Your gain was: %.2fR$\n", liquidValue);
    fclose(resultsFile);
  }
}

void displayProducts(Product products[], int amount)
{
  FILE *productsFile = fopen("products.txt", "w");

  printf("Your products are: \n");
  fprintf(productsFile, "Your products are: \n");
  for (int i = 0; i < amount; i++)
  {
    printf("\nProduct %d:\n", i + 1);
    printf("Name: %s\n", products[i].name);
    printf("Amount: %d\n", products[i].amount);
    printf("Price: %.2fR$\n\n", products[i].price);
    fprintf(productsFile, "\nProduct %d:\n", i + 1);
    fprintf(productsFile, "Name: %s\n", products[i].name);
    fprintf(productsFile, "Amount: %d\n", products[i].amount);
    fprintf(productsFile, "Price: %.2fR$\n\n", products[i].price);
  }

  fclose(productsFile);
}

Product *readProducts(int amount)
{
  Product *allocatedProducts = (Product *)malloc(amount * sizeof(Product));

  printf("Enter your products:\n\n");
  for (int i = 0; i < amount; i++)
  {
    printf("Enter product %d name: ", i + 1);
    scanf("%s", allocatedProducts[i].name);

    printf("Enter product %d amount: ", i + 1);
    scanf("%d", &allocatedProducts[i].amount);

    printf("Enter product %d price: ", i + 1);
    scanf("%f", &allocatedProducts[i].price);
    printf("\n");
  }

  return allocatedProducts;
}

float readExpenses(void)
{
  float sum = 0, value;

  printf("Enter your expense's price, 0 to stop: \n");

  while (TRUE)
  {
    scanf("%f", &value);
    if (value == 0)
    {
      break;
    }
    sum += value;
  }
  return sum;
}

float calculateSumOfProducts(Product products[], int amount)
{
  float sum = 0;

  for (int i = 0; i < amount; i++)
  {
    sum += (products[i].price * products[i].amount);
  }

  return sum;
}