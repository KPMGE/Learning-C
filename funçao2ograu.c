#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, b, c;
    float delta, raiz1, raiz2;

    printf("digite os valores de A, B, C");
    scanf("%d%d%d", &a, &b, &c);

    delta = pow(b, 2) - 4*a*c;

    if(delta < 0){
        printf("A funcao nao tem raizes reais!!");
    }

    else{
        raiz1 = (-b + sqrt(delta)) / 2*a;
        raiz2 = (-b - sqrt(delta)) / 2*a;
        printf("As raizes da funcao sao : R1 = %f\n R2 = %f", raiz1, raiz2);
    }
    return 0;
}