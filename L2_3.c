#include <stdio.h>
#include <stdlib.h>

/*(BOCA:L2_3) Problema: Faça um programa que leia n números positivos e retorne o maior e o menor destes,
 a quantidades de pares, a quantidade de ímpares, e a média deles.*/

int main(){
    int n, qtd, c=0, maior=0, menor=0, cont=0, pares=0, impares=0;
    float media=0, mediaf;

    scanf("%d", &qtd);
    

    for(c; c<qtd; c++){
        scanf("%d", &n);

        if(c == 0){
            menor = n;
        }

        if(n > maior){
            maior = n;
        }
        if(n < menor){
            menor = n;
        }

        if(n % 2 == 0){
            pares++;
        }
        else{
            impares++;
        }

        media += n;
        cont++;

        mediaf = media / cont;
    }

    printf("%d %d %d %d %f", maior, menor, pares, impares, mediaf);

    return 0;
}