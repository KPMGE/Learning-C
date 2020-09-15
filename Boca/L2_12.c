/*
(BOCA:L2_12) 
Problema: Faça um programa para substituir caracteres espaço ‘ ‘ por caracteres underline ‘_’ de uma phrase. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: “RESP:” seguido da sequência de caracteres modificada.
*/

#include <stdio.h>

//function that checks if the entered character is a space
int isSpace(char c)
{
    return (c == ' ') ? 1 : 0;
}

//function that checks the condition to stop loop 
int endingPhrase(char c)
{
    return ((c == '.') || (c == '!') || (c == '?')) ? 1 : 0;
}

int main(void)
{
    char phrase[1000];

    int i = -1;
    do
    {
        i++;
        
        //reading a character
        scanf("%c", &phrase[i]);

        //swapping character ' ' to '_'
        if(isSpace(phrase[i]))
            phrase[i] = '_';
    }while(!endingPhrase(phrase[i]));

    //showing modificated phrase
    printf("RESP:%s", phrase);

    return 0;
}  

