/*
(BOCA:L2_13)
Problema: Faça um programa para substituir letras minúsculas de uma phrase por letras maiúsculas. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

OBS: “YES - Presentation diferences” não é uma resposta válida para essa questão.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: a sequência de caracteres modificada.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char phrase[1000];
    
    int i = 0;
    for(i; i < 1000; i++)
    {
        scanf("%c", &phrase[i]);
        if((phrase[i] == '.') || (phrase[i] == '?') || (phrase[i] == '!'))
            break;
        else
            phrase[i] = toupper(phrase[i]);
    }

    printf("%s", phrase);

    return 0;
}

