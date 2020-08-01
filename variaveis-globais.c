//calculando soma, produto, adição e subração com variáveis globais

#include <stdio.h>

//variáves globais declaradas
int soma, subtracao, multiplicacao;
float divisao;

void operacoesFundamentais(int a, int b)
{
    //realizando operações com as variáveis globais definidas
    soma = a + b;
    subtracao = a - b;
    multiplicacao = a * b;
    divisao = (float)a / b;
}

//função principal
int main(void)
{
    int a, b;

    //lendo dados
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    //chamando a função que modifica as variáveis globais
    operacoesFundamentais(a, b);

    //mostrando os dados
    printf("soma: %d\nsubtracao: %d\nmultiplicacao: %d\ndivisao: %f", soma, subtracao, multiplicacao, divisao);
    return 0;
}
