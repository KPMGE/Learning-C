/*(BOCA:L3_6) 
Problema: Alguns números tem uma propriedade curiosa.
Caso você inverta a ordem dos algarismos desse número ele continuará
tendo o mesmo valor. A esses números, damos o nome de Palíndromos.
Você deverá implementar um programa que identifica se um dado número
é Palíndromo ou não.
a) A identificação do número palíndromo deverá ser feita por uma
função (a ser implementada) que receberá um número num e
retornará verdadeiro se o número for palíndromo e falso caso
contrário. A função deverá ter o seguinte cabeçalho: 

int EhPalíndromo(int num);

Entrada: uma sequencia de inteiros, cada um separados por uma quebra
de linha.
Saída: caso o número seja palíndromo, exibe 'S'. Caso não seja, exibe 'N'.
Todas as saídas apresentam uma quebra de linha entre si.
*/

#include <stdio.h>
#include <stdlib.h>

#define False 0
#define True 1

int EhPalindromo(int num);

int main(void)
{
  int num;

  while (scanf("%d", &num) == 1)
  {
    if (EhPalindromo(num) == 1)
      printf("S\n");
    else
      printf("N\n");
  }

  return 0;
}

int EhPalindromo(int num)
{
  int numOriginal, palindromo, resto;

  numOriginal = num;
  palindromo = 0;

  while (num != 0)
  {
    resto = num % 10;
    palindromo = palindromo + resto;
    num = num / 10;

    if (num != 0)
      palindromo = palindromo * 10;
  }

  if (palindromo == numOriginal)
    return True; 
  else
    return False;
}