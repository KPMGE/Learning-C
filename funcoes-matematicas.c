#include <stdio.h>
#include <math.h>

float calculaBaskara(int a, int b, int c){
    float delta, raiz1, raiz2;

    delta = pow(b, 2) - 4*a*c;

    if(delta < 0){
        printf("nao ha raizes reais!!");
        return 0;
    }

    else{
        raiz1 = (-b + sqrt(delta))/2*a;
        raiz2 = (-b - sqrt(delta))/2*a;

        printf("R1: %f", raiz1);
        printf("R2: %f", raiz2);
       
        return 1;
    }
}

int main(){

    return 0;
}