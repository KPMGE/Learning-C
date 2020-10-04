/*
(BOCA:L2_17) 
Problema: Ana queria codificar seus textos para que mais ninguém lesse, e decodificá-los para quando ela quisesse ler. Para isso, faça um programa que contenha essas duas opções. Serão dados dois números inteiros e um texto terminado em ponto. O primeiro número é referente a opção (1 para codificar ou 2 para decodificar) que a pessoa quer e o segundo número será um número n referente ao código da codificação, ou seja, dada a opção 1, codifique o texto “somando” as letras minúsculas do texto a esse valor n para que o texto fique codificado. Exemplo: se n = 2, a letra a vira c, a letra n vira p, a letra z vira b, e assim sucessivamente. Dada a opção 2 com n = 1, o programa deve decodificar o texto revertendo o texto para o original, ou seja, a letra c vira b, a letra a vira z, e assim sucessivamente. Se for dada uma opção diferente das opções acima o programa deverá imprimir: “Operacao invalida.”. 

Atenção: Não deverão ser codificadas as letras maiúsculas. Números e outros caracteres que por ventura apareçam no texto não deverão ser codificados. Serão testados no BOCA outras entradas além das apresentadas nos exemplos.

• Entrada: dois números inteiros representando o modo codificador ou decodificador e a chave de codificação seguido do texto que será sempre terminado com um ponto, i.e., “.”.

• Saída: o texto codificado ou decodificado.
*/

#include <stdio.h>
#include <ctype.h>

#define True 1
#define False 0

char codifica(char c, int chave);
char decodifica(char c, int chave);

int main(void)
{
  int modo, chave;
  char letra;

  scanf("%d %d", &modo, &chave);

  switch(modo)
  {
    case 1:
      while(True)
      {
        scanf("%c", &letra);
        printf("%c", codifica(letra, chave));
        if(letra == '.')
          break;
      }
    break;

    case 2:
      while(True)
      {
        scanf("%c", &letra);
        printf("%c", decodifica(letra,chave));
        if(letra == '.')
          break;
      }
    break;
    
    default:
      printf("Operacao invalida.");
  }

  return 0;
}

char codifica(char c, int chave)
{
  if(islower(c))
    c += chave;
  return c;
}

char decodifica(char c, int chave)
{
  if(islower(c))
    c -= chave;
  return c;
}
