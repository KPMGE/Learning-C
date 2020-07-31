/*
(BOCA:L2_15) 
Problema: Faça um programa para imprimir a quantidade de números negativos, a quantidade de números positivos, a soma dos negativos e a soma dos positivos de uma sequência de números. O programa deverá ler números da entrada padrão (um por vez) enquanto ainda tiverem números para serem lidos. Considere que os números estão entre -100 e 100.

 Entrada: uma sequência números inteiros separados por espaço e terminada por um caractere diferente de white-space (ver ajuda do scanf).

 Saída: a quantidade de números negativos da sequência, a quantidade de números positivos da sequência, a soma dos números negativos da sequência e a soma dos números positivos da sequência.
*/

//importação de bibliotecas
#include <stdio.h>

//função que verifica o write-space
int verificaWriteSpace(char caractere)
{
    if (caractere == 'k')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//função que verifica se o numero é positivo
int verificaPositivo(int num)
{
    if (num > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//função principal
int main()
{
    //declaração de variaveis
    int i = -1, somaPositivos = 0, somaNegativos = 0, contNegativos = 0, contPositivos = 0, listaNumeros[100];

    //repetição até encontrar o caractere final
    do
    {
        //incremento na variavel i
        i++;

        //leitura dos dados
        scanf("%d", &listaNumeros[i]);

        //caso o numero seja positivo
        if (verificaPositivo(listaNumeros[i]))
        {
            //somaPositivos é incrementado com o numero e contPositivos incrementado em 1
            somaPositivos += listaNumeros[i];
            contPositivos++;
        }
        else
        {
            //somaNegativos é incrementado com o numero e contNegativos incrementado em 1
            somaNegativos += listaNumeros[i];
            contNegativos++;
        }
    } while (!verificaWriteSpace(listaNumeros[i]));

    //mostrando dados
    printf("qtd-positivos: %d   ,   somapositivos: %d\nqtd-negativos: %d    ,    somanegativos: %d", contPositivos, somaPositivos, contNegativos, somaNegativos);
    return 0;
}