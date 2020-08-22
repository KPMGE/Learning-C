/*
(BOCA: P1_2016_Q4)

Problema: Faça um programa para descobrir qual de 3 números possui o menor algarismo na casa das centenas.

 Entrada: 3 números inteiros positivos e menores que 999999.

 Saída: O programa deverá imprimir “N1” caso o primeiro número possua o menor algarismo, “N2” caso o segundo número possua o menor algarismo, “N3” caso o terceiro número possua o menor algarismo. Caso os referidos algarismos de dois números sejam iguais, o que aparecer primeiro terá precedência (ex. se o algarismo de segundo número for igual ao do terceiro e eles forem menores do que o primeiro, “N2” será impresso). Caso um número não possua algarismo das centenas, ele deverá ser desconsiderado, e se nenhum dos 3 números possuir algarismo das centenas, “Nenhum” deverá ser impresso.
*/


//imporntação de bibliotecas
#include <stdio.h>


//funçao que acha o algarismo das centenas em um numero
int achaAlgarismo(int num)
{
    //declaração de variáveis
    int dezena, centena, algarismoCentena;

    //para isolar a centena de um numero, basta tirar o resto da divisao por 1000
    centena = num%1000;
    //para isolar a dezena fazemos o resto da divisão por 100
    dezena = num%100;
    //para isolar o algarismo das centenas, fazemos centena - dezena e cortamos os 00. Dividindo por 100
    algarismoCentena = (centena - dezena)/100;

    //retornando  o algarismo
    return algarismoCentena;

}


//funçao que retorna o menor dentre 3 numeros
int menorNumero(int num1, int num2, int num3)
{
    //caso num1 seja o menor , o retornamos
    if(num1 < num2 && num1 < num3)
    {
        return num1;
    }
    //caso contrario
    else
    {
        //se o num2 for menor que num3, o retornamos
        if(num2 < num3)
        {
            return num2;
        }
        //caso contrario, retornamos num3
        else
        {
            return num3;
        }     
    } 
}


//funçao principal
int main()
{
    //declaração de variáveis
    int n1, n2, n3, a1, a2, a3, menor;

    //lendo os valores
    scanf("%d %d %d", &n1, &n2, &n3);

    //achando os algarismos de cada numero
    a1 = achaAlgarismo(n1);
    a2 = achaAlgarismo(n2);
    a3 = achaAlgarismo(n3);

    //caso algum dos numeros seja menor que 100, não há nesse algarismo nas centenas
    if(n1 < 100 || n2 < 100 ||n3 < 100)
    {
        //adicionando o valor 10 ao(s) numero(s) que possuir o valor menor que 100
        if(n1 < 100)
        {
            a1 = 10;
        }
        if(n2 < 100)
        {
            a2 = 10;
        }
        if(n3 < 100)
        {
            a3 = 10;
        }
    }

    //encontrando o menor dos algarismos
    menor = menorNumero(a1, a2, a3);

    //caso os 3 numeros sejam menores que 100, mostramos nenhum na tela
    if(n1 < 100 && n2 < 100 && n3 < 100)
    {
        printf("Nenhum");
    }
    //verificadando qual o menor e mostrando na tela
    else
    {
        if(menor == a1)
        {
            printf("N1");
        }
        else if(menor == a2)
        {
            printf("N2");
        }
        else
        {
            printf("N3");
        }
    }

    return 0;
}