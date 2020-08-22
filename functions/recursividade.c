//programa que calcula fatorial usando recursividade
#include <stdio.h>

//função que calcula o fatorial do numero dado
int calculaFatorial(int n);

//função principal
int main()
{
    int n, fatorial;

    //lendo dados
    printf("Digite o numero: ");
    scanf("%d", &n);

    //calculando o fatorial atraves da função
    fatorial = calculaFatorial(n);

    //mostrando o valor
    printf("fatorial: %d", fatorial);

    return 0;
}

int calculaFatorial(int n)
{
    //caso o número que recebemos seja 0, retornamos 1
    if(n == 0)
        return 1;
    //caso contrário, retornamos a própria função em (n-1) vezes n
    else
        return calculaFatorial(n - 1) * n;
}
