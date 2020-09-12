/*
(BOCA:L2_14) 
Problema: Faça um programa para eliminar os caracteres espaço ‘ ‘ de uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: “RESP:” seguido da sequência de caracteres modificada.
*/

#include <stdio.h>

int main(void)
{
    int i = 0;
    char phrase[101];

    for(i; i < 100; i++)
    {
        scanf(" %c", &phrase[i]);
        if((phrase[i] == '.') || (phrase[i] == '?') || (phrase[i] == '!'))
            break;
    }

    printf("%s", phrase);
    return 0; 
}

