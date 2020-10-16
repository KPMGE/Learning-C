#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define True 1
#define False 0

void parImpar(int n);
int verificaPrimo(int n);
void valorPrimo(int n);
int tamanhoNum(int n);
int algarismoNum(int n, int posicao);
int algarismoNum(int n, int posicao);
int somadosdigitos(int n);

int main(void)
{
  int valor, soma = 0;

  scanf("%d", &valor);

  do
  {
    soma = somadosdigitos(valor);
    //mostrando dados
    printf("%d ", soma);
    parImpar(soma);
    valorPrimo(soma);
    valor = soma;
  } while (soma > 9);

  return 0;
}

void parImpar(int n)
{
  if (n % 2 == 0)
    printf("Par ");
  else
    printf("Impar ");
}

int verificaPrimo(int n)
{
  int i;

  for (i = 2; i < n / 2; i++)
  {
    if (n % i == 0)
      return False;
  }
  return True;
}

void valorPrimo(int n)
{
  if (verificaPrimo(n))
    printf("Primo\n");
  else
    printf("Nao e primo\n");
}

int tamanhoNum(int n)
{
  int tamanho = 0, resto = 0, i = 1;

  //enquanto o resto da divisão for diferente do próprio numero
  while (resto != n)
  {
    //resto é dado por 10^i
    resto = n % (int)pow(10, i);
    //incrementando tamanho e i
    tamanho++;
    i++;
  }
  return tamanho;
}

int algarismoNum(int n, int posicao)
{
  int algarismo, n2, n3;

  //n2 recebe o numero cortando ate o algarismo que queremos
  n2 = n % (int)pow(10, posicao);
  //n3 recebe os numero depois desse algarismo
  n3 = n % (int)pow(10, posicao - 1);
  //algarismo recebe o numero com o algarismo e 000.. depois
  algarismo = n2 - n3;
  //eliminando os zeros, por divisão
  algarismo /= (int)pow(10, posicao - 1);

  return algarismo;
}

int somadosdigitos(int n)
{
  int i, tamanho, algarismo = 0, soma = 0;
  //achando o tamanho do numero em casas decimas
  tamanho = tamanhoNum(n);

  for (i = 1; i <= tamanho; i++)
  {
    //algarismo recebe o retorno da função algarismoNum
    algarismo = algarismoNum(n, i);
    //soma incrementada com o algarismo
    soma += algarismo;
    //resetando algarismo
    algarismo = 0;
  }

  return soma;
}
