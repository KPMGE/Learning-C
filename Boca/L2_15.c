/*
(BOCA:L2_15) 
Problema: Faça um programa para imprimir a quantidade de números negativos, a quantidade de números positivos, a soma dos negativos e a soma dos positivos de uma sequência de números. O programa deverá ler números da entrada padrão (um por vez) enquanto ainda tiverem números para serem lidos. Considere que os números estão entre -100 e 100.

Entrada: uma sequência números inteiros separados por espaço e terminada por um caractere diferente de white-space (ver ajuda do scanf).

Saída: a quantidade de números negativos da sequência, a quantidade de números positivos da sequência, a soma dos números negativos da sequência e a soma dos números positivos da sequência.
*/

//importação de bibliotecas
#include <stdio.h>

//funçãoe que verifica se o caractere é um \a, \n, ' ', \b, \0
int verificaWritespace(char c);

//função principal
int main(void)
{

    //declaração de variaveis
    int i = -1, sp = 0, sn = 0, qtdn = 0, qtdp = 0, numeros[101];

    //lendo dados
    do
    {
        //incremento em i
        i++;

        scanf("%d", &numeros[i]);

        //caso o numero seja positivo
        if(numeros[i] > 0)
        {
            //incrementando quantidade de positivos
            qtdp++;
            //somando o numero a sp
            sp += numeros[i];
        }
        else 
        {
            //incrementando quantidade de negativos
            qtdn++;
            //somando o numero a sn
            sn += numeros[i];
        }

    } while(!verificaWritespace(numeros[i]));

    printf("%d %d %d %d", qtdn, qtdp, sn, sp);
    
    return 0;
}

int verificaWritespace(char c)
{
    return (c >= '-100' && c <= '100' && c != ' ') ? 1 : 0;
}

