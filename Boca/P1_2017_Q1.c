/*
(BOCA: P1_2017_Q1)
Problema: Faça um programa para dizer o resultado de uma operação (soma, adição, multiplicação e divisão) entre dois números inteiros. Atentar para o fato de todas as operações serem inteiras.

• Entrada: 2 números inteiros e um caractere (‘+’, ‘-’, ‘*’ e ‘/’) representando as operações (soma, adição, multiplicação e divisão respectivamente). Os números e o caractere estarão separados por um espaço.

• Saída: Resposta da operação correspondente no formato “RESP:#”, em que # representa o número com a resposta. Caso a operação não seja nenhuma das permitidas, imprimir “Invalido”.
*/

#include <stdio.h>

int main()
{
    int num1, num2, resultado;
    char operacao;

    scanf("%d %d %c", &num1, &num2, &operacao);

    switch(operacao)
    {
        case '+':
            resultado = num1+num2;
            printf("RESP:%d", resultado);
            break;
        
        case '-':
            resultado = num1-num2;
            printf("RESP:%d", resultado);
            break;

        case '/':
            resultado = num1/num2;
            printf("RESP:%d", resultado);
            break;

        case '*':
            resultado = num1*num2;
            printf("RESP:%d", resultado);
            break;
        
        default:
            printf("Invalido");      
    }

    return 0;
}