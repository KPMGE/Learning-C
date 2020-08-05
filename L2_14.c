/*
(BOCA:L2_14) 
Problema: Faça um programa para eliminar os caracteres espaço ‘ ‘ de uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Entrada: uma sequência de caracteres terminada com um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.

• Saída: “RESP:” seguido da sequência de caracteres modificada.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//função que retorna 1(verdadeiro), caso o caractere seja um espaço e 0(falso) caso contrário
int ehEspaco(char caractere);

//funçao principal
int main(void)
{
    //declaração de variaveis
    int i, j = 0;
    char frase[50], frase2[50];

    //leitura dos dados enquanto não achamos um . ? ou !
    scanf("%[^.?!]", frase);

    //percorrendo string
    for(i = 0; i < strlen(frase); i++)
        //caso o caractere não seja um espaço
        if(!ehEspaco(frase[i]))
        {
            //transcrevendo para frase2 na posição de j
            frase2[j] = frase[i];
            //incremento em j
            j++;
        }

    //mostrando frase final na tela 
    printf("RESP:%s", frase2);

    return 0; 
}

//função que retorna 1(verdadeiro), caso o caractere seja um espaço e 0(falso) caso contrário
int ehEspaco(char caractere)
{
    return (caractere == ' ') ? 1 : 0;
}
