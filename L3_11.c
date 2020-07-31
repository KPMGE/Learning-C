/*(BOCA:L3_11) Problema: Implemente um programa que dado a relação de números par ou
impar, retorne os N primeiros números desse tipo. Para isso, crie funções que dizem se o
número é par ou ímpar, uma função para printar os N primeiros pares a partir do 2 e uma
função para printar os N primeiros números ímpares a partir do 1.
As funções deverão ter os seguintes cabeçalhos:
a) int EhPar (int x)
b) void PrintaPares (int N)
c) void PrintaImpares (int N)
Obs: Cada numero na saída é separado por um único espaço.

Entrada: A entrada é dada por TIPO, sendo 0 para PAR e 1 para IMPAR, e N, onde N está
entre 1<=N<=99999.
Saída: Os N primeiros números do tipo pedido (par/ímpar).*/


//importação de bibliotecas
#include <stdio.h>

//função que verifica se o numero é par ou impar
int EhPar(int x);

//função que printa os pares 
void PrintaPares (int N);

//função que printa os impares
void PrintaImpares (int N);

//função principal
int main(void)
{
    unsigned int N;
    int tipo;

    //leitura de dados
    scanf("%d %d", &tipo, &N);

    //analisando o tipo escolhido
    switch(tipo)
    {
        case 0:
            PrintaPares(N);
            break;

        case 1:
           PrintaImpares(N);
            break;

        default: 
            break;
    }

    return 0;
}

//função que verifica se o numero é par ou impar
int EhPar(int num)
{
    //caso o resto da divisão do numero por 2 for 0, o numero é par
    return (num % 2 == 0) ? 1 : 0;
}

//função que printa os pares 
void PrintaPares (int N)
{
    int i = 2, cont = 0;
    do
    {
        if(EhPar(i))
        {
            printf("%d ", i);
            cont++;
        }

        i++;
    }while(cont != N);
}

//função que printa os impares
void PrintaImpares (int N)
{
    int i = 1, cont = 0;
    do
    {
        if(!EhPar(i))
        {
            printf("%d ", i);
            cont++;
        }

        i++;
    }while(cont != N);
}
