/*
(BOCA: P2_2016_Q1) 

Problema: Faça um programa para dizer a quantidade de números pares ou ímpares de uma lista de números dependendo do tipo do primeiro item. Ou seja, se o primeiro item for par, imprimir a quantidade de pares, e se o primeiro item for ímpar, imprimir a quantidade de ímpares.

 Entrada: 1 número inteiro n > 0 informando a quantidade de números da lista seguido de n números inteiros. Todos os números serão separados por espaço.

 Saída: A mensagem “QTD PARES:” seguida da quantidade de pares se o primeiro número for par, e a mensagem ” QTD IMPARES:” seguida da quantidade de ímpares se o primeiro número for ímpar.
*/

//importaçao de bibliotecas
#include <stdio.h>


//funçao que descobre se o numero é par
int ehPar(int num)
{
    if(num%2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//funçao principal
int main()
{
    int size, i, cont=0;

    //definindo o tamanho do vetor lista
    scanf("%d", &size);
    int list[size];

    //lendo os dados da lista
    for(i=0; i<size; i++)
    {
        scanf("%d", &list[i]);
    }

    
    //caso o primeiro numero seja par
    if(ehPar(list[0]))
    {
        //percorrendo a lista
        for(i=0; i<size; i++)
        {
            if(ehPar(list[i]))
            {
                cont++;
            }
        }

        //mostrando a quantidade na tela
        printf("QTD PARES:%d", cont);
    }
    //caso o primeiro numero seja impar
    else
    {
        //percorrendo a lista
        for(i=0; i<size; i++)
        {
            if(!ehPar(list[i]))
            {
                cont++;
            }
        }

        //mostrando a quantidade na tela
        printf("QTD IMPARES:%d", cont);
    } 
    
    return 0;
}