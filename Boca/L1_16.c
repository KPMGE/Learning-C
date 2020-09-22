/*(BOCA:L1_16) 
 * Problema: No banco imobiliário, tem-se as seguintes
cédulas: 500, 100, 50, 10, 5, 1. Calcule a menor quantidade de
cédulas a serem fornecidas para pagar uma determinada quantia que
represente os seguintes valores:

i) Uma dívida a ser paga de 2343 unidades monetárias (U.M) do jogo;
ii) Um aluguel de 1325 U.M
iii) Uma aquisição de imóveis no valor de 3456 U.M

Entrada: Um número inteiro q (0 ≤ q ≤ 99999).
Saída: O número total e por tipo de cédulas.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number, currentQtd, total = 0;

    scanf("%d", &number);

    if(number >= 500)
    {
         currentQtd = number / 500;
         number = number - currentQtd * 500;
         total += currentQtd;
         printf("%d (500), ", currentQtd);
    }
    if(number >= 100)
    {
         currentQtd = number / 100;
         number = number - currentQtd * 100;
         total += currentQtd;
         printf("%d (100), ", currentQtd);
    }
    if(number >= 50)
    {
         currentQtd = number / 50;
         number = number - currentQtd * 50;
         total += currentQtd;
         printf("%d (50), ", currentQtd);
    }
    if(number >= 10)
    {
         currentQtd = number / 10;
         number = number - currentQtd * 10;
         total += currentQtd;
         printf("%d (10), ", currentQtd);
    } 
    if(number >= 5)
    {
         currentQtd = number / 5;
         number = number - currentQtd * 5;
         total += currentQtd;
         printf("%d(5)", currentQtd);
    }
    if(number >= 1)
    {
        total += number;
        printf("%d(1)", number);
    }

    printf(". Total: %d cedulas.", total);

    return 0; 
}




