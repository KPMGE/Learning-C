/**
Ocorrencias de palavras
Esse código base implementa uma função que lê palavra por palavra em um dado arquivo texto.
O Codigo ignora caracteres especiais e acentuação.

Lembre-se de alterar o nome do arquivo antes de submetê-lo.
Você pode testar e entender o funcionamento usando os arquivos de texto de exemplo.

*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define TAMPALAVRA 30

typedef struct
{
  char palavra[TAMPALAVRA];
  int quantidadeDeOcorrencias;
} tPalavra;

typedef struct
{
  tPalavra palavras[1000];
  int quantidadePalavras;
} tDicionario;

/**
 * Lê todos os caracteres de uma palavra em um arquivo texto.
 * 
 * @param fp  Arquivo a ser lido
 * @param s  Array de caracteres no qual será armazenado a palavra.
 * @return int zero se ocorrer erro ou chegar no final do arquivo;
 */
int le_palavra( FILE *fp, char *s ){
  int i = 0;
  int c;
  while ((c = fgetc( fp )) != EOF){
    if (isalpha(c)||isdigit(c))
    break;
  }
  if (c == EOF)
    return 0;
  else
    s[i++] = c;
  while (i<TAMPALAVRA-1 && (c = fgetc(fp))!= EOF && (isalpha(c)||isdigit(c)))
    s[i++] = c;
  s[i] = '\0';
  return 1;
}

int pesquisaPalavra(tDicionario l, char p[]);
void imprimeDicionario(tDicionario d);
int ehPalavraUnica(tDicionario dicionario, char palavra[]);
int contaOcorrencias(tDicionario, char palavra[]);

int main()
{
  FILE* fp;
  char file[TAMPALAVRA];
  //Lê o nome do arquivo
  scanf("%[^\n]", file);
  //printf("%s", file);
  fp = fopen (file, "rt");
  if (fp == NULL) {
    printf ("Erro na abertura do arquivo!\n");
    exit(1);
  }

   char palavra[TAMPALAVRA];  
  /***
  Função LePalavra já colocando-a em um array de caracteres. 
  o loop termina no final do arquivo.
  Ignore as palavras com menos de 3 caracteres.

   */
   tDicionario dicionario;
   dicionario.quantidadePalavras = 0;
   int i = 0;
   while (le_palavra(fp, palavra))
   {
     dicionario.palavras[i].quantidadeDeOcorrencias = 0;
     if (strlen(palavra) > 2)
     {
       strcpy(dicionario.palavras[i].palavra, palavra);  // passando palavra lida para o dicionario
       dicionario.palavras[i].quantidadeDeOcorrencias++; // aumentando a quantidade de ocorrencias da palavra
       dicionario.quantidadePalavras++; // aumentando total de palavras no dicionario
     }
     i++;
   }

   imprimeDicionario(dicionario);

   return 0;
}

int pesquisaPalavra(tDicionario l, char p[])
{
  int i;
  for (i = 0; i < l.quantidadePalavras; i++)
  {
    if (strcmp(l.palavras[i].palavra, p) == 0)
    {
      return i;
    }
  }
}

void imprimeDicionario(tDicionario d)
{
  int i, palavrasUnicas = 0;

  for (i = 0; i < d.quantidadePalavras; i++)
  {
    printf("%s\n", d.palavras[i].palavra);
    if (contaOcorrencias(d, d.palavras[i.palavra]) < 2)
    {
      palavrasUnicas++;
    }
  }

  printf("\n%d", palavrasUnicas);
}


int contaOcorrencias(tDicionario dicionario, char palavra[])
{
  int i, ocorrencias = 0;
  for (i = 0; i < dicionario.quantidadePalavras; i++)
  {
    if (strcmp(dicionario.palavras[i].palavra, palavra) == 0)
    {
      ocorrencias++;
    }
  }
  return ocorrencias;
}