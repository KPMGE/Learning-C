/*
(BOCA: P1_2016_Q2) Problema: Faça um programa para dizer se um grupo de pontos está ou não em uma reta definida por:
𝑎𝑥+𝑏=𝑦

 Entrada: 8 números inteiros. Os dois primeiros definindo a e b respectivamente. Os 6 últimos definindo os x e y de 3 pontos na sequência: x1, y1, x2, y2, x3 e y3.

 Saída: O programa deverá imprimir “Nenhum” se nenhum dos três pontos estiverem na reta, “Um” se apenas um dos pontos estiver na reta, “Dois” se apenas dois dos pontos estiverem na reta, “Todos” se os três pontos estiverem na reta.
*/

#include <stdio.h>

int calculaImagemFuncao(int a, int b, int x){
    int y;
    
    y = a*x + b;

    return y;
}


int main(){
    int a, b, x1, y1, x2, y2, x3, y3, contador=0; 
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);

    if(calculaImagemFuncao(a, b, x1) == y1){
        contador++;
    }

    if(calculaImagemFuncao(a, b, x2) == y2){
        contador++;
    }

    if(calculaImagemFuncao(a, b, x3) == y3){
        contador++;
    }

    switch(contador){
        case 1:
            printf("Um");
            break;

        case 2:
            printf("Dois");
            break;

        case 3:
            printf("Todos");
            break;

        default:
            printf("Nenhum");
    }

    return 0;
}