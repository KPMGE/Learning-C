/*
(BOCA: P2_2018_Q1_a) 
Faça um programa para somar as ocorrências de números pares que estiverem em posições pares e as ocorrências de números ímpares que estiverem em posição ímpar de uma lista de números. Assuma que a lista de números começa da posição 0 (par), e continua com as posições 1 (ímpar), 2 (par), etc.

• Entrada: 1 número inteiro n > 0 informando a quantidade de números da lista seguido de n números inteiros n > 0. Todos os números serão separados por espaço.

• Saída: A mensagem “SOMA:” seguida da soma total dos números pares que ocorreram em posições pares e números ímpares que ocorreram em posição ímpar. Considere que o primeiro item da lista está na posição 1, o segundo na 2, e assim por diante.
*/

#include <stdio.h>


//funçao que descobre se o numero e par
int ehPar(int num)
{
    if(num%2 == 0)
    {
        return 1;
    }else
    {
        return 0;
    }    
}


//funçaoo que descobre se ambos os numeros sao pares
int ambosPares(int num1, int num2)
{
    if(ehPar(num1) && ehPar(num2))
    {
        return 1;
    }else
    {
        return 0;
    }  
}


int main()
{
    int qtd, i, j=1, par=0, impar=0;

    scanf("%d", &qtd);

    int lista[qtd];

    for(i=0; i<qtd; i++, j++)
    {
        scanf("%d", &lista[i]);


        if(ambosPares(lista[i], j))
        {
            par++;
        }
        if(!ambosPares(lista[i], j))
        {
            impar++;
        }
    }

    printf("SOMA:%d%d", par, impar);

    return 0;
}