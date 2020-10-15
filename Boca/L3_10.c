// Exercício: L3_10
// Autor: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int EhLetra(char c);
int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);
char Codifica(char letra, int n);
char Decodifica(char letra, int n);

int main(void)
{
  int modo, chave;
  char letra;

  scanf("%d %d ", &modo, &chave);

  switch (modo)
  {
    case 1:
      do
      {
        scanf("%c", &letra);
        printf("%c", Codifica(letra, chave));
      } while (letra != '.');
      printf("\n");
    break;

    case 2:
      do
      {
        scanf("%c", &letra);
        printf("%c", Decodifica(letra, chave));
      } while (letra != '.');
    break;

    default:
      printf("Operacao invalida.");
    break;
  }

  return 0;
}

int EhLetra(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? True : False;
}

int EhLetraMaiuscula(char c)
{
  return (c >= 'A' && c <= 'Z') ? True : False;
}

int EhLetraMinuscula(char c)
{
 return (c >= 'a' && c <= 'z') ? True : False;
}

char Codifica(char letra, int n)
{
  if (EhLetraMinuscula(letra))
  {
    letra = n + letra;
    while (letra > 'z')
    {
      letra = (letra - 'z') + ('a' - 1);
    }
    return letra;
  }
  if (EhLetraMaiuscula(letra))
  {
    letra = (2 * n) + letra;
    while (letra > 'Z')
    {
      letra = (letra - 'Z') + ('A' - 1);
    }
    return letra;
  }
  return letra;
}

char Decodifica(char letra, int n)
{
  if (EhLetraMinuscula(letra))
  {
    letra = letra - n;
    while (letra < 'a')
    {
      letra = 'z' - ('a' - letra) + 1;
    }
    return letra;
  }
  if (EhLetraMaiuscula(letra))
  {
    letra = letra - 2 * n;
    while (letra < 'A')
    {
      letra = 'Z' - ('A' - letra) + 1;
    }
    return letra;
  }
  return letra;
}
