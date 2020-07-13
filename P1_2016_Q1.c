/*
(BOCA: P1_2016_Q1) Problema: Faça um programa para dizer o dia da semana de acordo com o número informado, sendo Domingo para 1, Segunda para 2, ..., Sabado para 7 e Invalido para qualquer outra coisa.
 Entrada: 1 número inteiro.
 Saída: Dia da semana correspondente {Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado, ou Invalido}.
*/

#include <stdio.h>

int main()
{
    int num;

    scanf("%d", &num);

    switch(num)
    {
        case 1:
            printf("Domingo");
            break;

        case 2:
            printf("Segunda");
            break;

        case 3:
            printf("Terca");
            break;
        
        case 4:
            printf("Quarta");
            break;

        case 5:
            printf("Quinta");
            break;

        case 6:
            printf("Sexta");
            break;

        case 7:
            printf("Sabado");
            break;

        default:
            printf("Invalido");
    }

    return 0;
}