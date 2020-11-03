// Exercise: L3_13
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int pessoas, itens, itens2;

  scanf("%d %d", &pessoas, &itens);

  //se o numero de pessoas for superior ao de itens, logo a ultima pessoa a receber sera a que pegar o ultimo item
  if (pessoas > itens)
    printf("RESP:%d", itens);

  else if (pessoas == itens)
    printf("RESP:%d", itens);

  //se o numero de itens for superior ao de pessoas
  else
  {
    //se o numero de itens for divisível pelo de pessoas
    if (itens % pessoas == 0)
      printf("RESP:%d", pessoas);

    else
    {
      itens2 = itens % pessoas;
      printf("RESP:%d", itens2);
    }
  }

  return 0;
}
