// Exercise: L4_1
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct
{
  int code;
  float price;
  int qtdInStock;
} Product;

Product readProduct();
int isGreaterProduct1(Product product1, Product product2);
int isSmallerProduct1(Product product1, Product product2);
int thereIsProductInStock(Product product);
void displayProduct(Product product);

int main(void)
{
  int n, i;
  Product product, smallestProdutc, greatestProduct;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    product = readProduct();

    if (i == 0)
      smallestProdutc = greatestProduct = product;
     
    if (product.qtdInStock == 0)
    {
      printf("FALTA:");
      displayProduct(product);
    }

    if (product.price < smallestProdutc.price)
      smallestProdutc = product;

    if (product.price > greatestProduct.price)
      greatestProduct = product;
  }

  printf("MAIOR:");
  displayProduct(greatestProduct);
  printf("MENOR:");
  displayProduct(smallestProdutc);

  return 0;
}

Product readProduct()
{
  Product product;
  scanf("%d;%f;%d", &product.code, &product.price, &product.qtdInStock);
  return product;
}

int isGreaterProduct1(Product product1, Product product2)
{
  if (product1.price > product2.price)
    return True;
  else
    return False;
}

int isSmallerProduct1(Product product1, Product product2)
{
  if (product1.price < product2.price)
    return True;
  else
    return False;
}

void displayProduct(Product product)
{
  printf("COD %d, PRE %.2f, QTD %d\n", product.code, product.price, product.qtdInStock);
}