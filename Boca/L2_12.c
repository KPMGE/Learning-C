/*
(BOCA:L2_12) 
Problema: Faça um programa para substituir caracteres espaço ‘ ‘ por caracteres underline ‘_’ de uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: “RESP:” seguido da sequência de caracteres modificada.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int i;
    char frase[100];

    for(i = 0; i < 100; i++)
    {
        scanf("%c", &frase[i]);
        if(isspace(frase[i]))
            frase[i] = '_';
        else if((frase[i] == '.') || (frase[i] == '?') || (frase[i] == '!'))
            break;
    }
    
    printf("RESP:%s", frase);

    return 0;
}  


