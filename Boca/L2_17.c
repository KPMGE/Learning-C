/*
(BOCA:L2_17) 
Problema: Ana queria codificar seus textos para que mais ninguém lesse, e decodificá-los para quando ela quisesse ler. Para isso, faça um programa que contenha essas duas opções. Serão dados dois números inteiros e um texto terminado em ponto. O primeiro número é referente a opção (1 para codificar ou 2 para decodificar) que a pessoa quer e o segundo número será um número n referente ao código da codificação, ou seja, dada a opção 1, codifique o texto “somando” as letters minúsculas do texto a esse valor n para que o texto fique codificado. Exemplo: se n = 2, a letter a vira c, a letra n vira p, a letra z vira b, e assim sucessivamente. Dada a opção 2 com n = 1, o programa deve decodificar o texto revertendo o texto para o original, ou seja, a letra c vira b, a letra a vira z, e assim sucessivamente. Se for dada uma opção diferente das opções acima o programa deverá imprimir: “Operacao invalida.”. 

Atenção: Não deverão ser codificadas as letters maiúsculas. Números e outros caracteres que por ventura apareçam no texto não deverão ser codificados. Serão testados no BOCA outras entradas além das apresentadas nos exemplos.

• Entrada: dois números inteiros representando o modo codificador ou decodificador e a chave de codificação seguido do texto que será sempre terminado com um ponto, i.e., “.”.

• Saída: o texto codificado ou decodificado.
*/

#include <stdio.h>

void encodePhrase(int num, int letter);
void decodePhrase(int num, int letter);

int main(void)
{
  int num;
  char letter;

  letter = '\0';

  scanf("%d", &num);

  if (num > 2)
    printf("Operacao invalida.");
  if (num < 1)
    printf("Operacao invalida.");

  switch (num)
  {
  case 1:
    scanf("%d", &num);
    scanf("%*c");
    while (letter != '.')
    {
      scanf("%c", &letter);
      encodePhrase(num, letter);
    }
    break;

  case 2:
    scanf("%d", &num);
    scanf("%*c");
    while (letter != '.')
    {
      scanf("%c", &letter);
      decodePhrase(num, letter);
    }
    break;
  }

  return 0;
}

void encodePhrase(int num, int letter)
{
  if (letter >= 'a' && letter <= 'z')
  {
    letter = num + letter;
    while (letter > 'z')
    {
      letter = (letter - 'z') + ('a' - 1);
    }
    printf("%c", letter);
  }
  else
    printf("%c", letter);
}

void decodePhrase(int num, int letter)
{
  if (letter >= 'a' && letter <= 'z')
  {
    letter = letter - num;
    while (letter < 'a')
    {
      letter = 'z' - ('a' - letter) + 1;
    }
    printf("%c", letter);
  }
  else
    printf("%c", letter);
}