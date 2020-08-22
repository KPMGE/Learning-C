/*(BOCA: P2_2015_Q1) Elabore um programa que leia do teclado para um vetor de
dimensão 80, uma frase qualquer de até 80 caracteres. A frase digitada termina com um
ponto final. Imprima a frequência com que aparece cada uma das letras do alfabeto nesta
frase. Considere a frase sem acentuação e ocorrências minúsculas e maiúsculas devem
ser contabilizadas como sendo da mesma letra.
• Entrada: Uma frase até 80 caracteres sem acentuação.
• Saída: A lista de pares contendo cada letra que ocorre na frase, sem repetição, e o
número de vezes que ocorreu na frase.*/

//import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//function that creates a vector with the letters from phrase, without repetion
char isolateLetters(char* phrase, char* phase_letters);

//function that returns the number of letters in the phrase
int countLetter(char letter, char* phrase);

int main(void)
{
    //declaring vector for phrase
    char phrase[81], phase_letters[81];

    //reading phrase
    scanf(" %80[^.]", phrase);

    return 0;
}

char isolateLetters(char* phrase, char* phase_letters)
{
    int i = 0;

    do
    {
        if(phrase[i])


    } while(phrase[i] != '.');

}

int countLetter(char letter, char* phrase)
{
    int i, qtd;

    for(i = 0; i < strlen(phrase); i++)
        if(phrase[i] == letter)
            qtd++;

    return qtd;
}
