//Programa que calcula uma aproximação para PI, usando a fórmula de Leibniz

//importação de bibliotecas
#include <stdio.h>
#include <math.h>

//função que calcula uma aproximação para Pi
double pi(int n);

//função principal
int main(void)
{
    //declaração de variáveis
    int n;
    double apxPI;

    //lendo o valor para a aproximação
    printf("Digite o numero para a aproximacao: ");
    scanf("%d", &n);

    //calculando uma aproximação para PI com a função
    apxPI = pi(n);

    //mostrando resultados
    printf("A aproximacao e: %.10g", apxPI);

    return 0;
}

double pi(int n)
{
    //declaração de variáveis
    int i;
    double Pi, somatorio = 0;

    //calculando somatório
    for(i = 0; i < n; i++)
        somatorio += pow(-1, i) / (2 * i + 1);

    //calculando aproximação para o PI
    Pi = 4 * somatorio;

    //retornando resultados
    return Pi;
}
