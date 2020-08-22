#include <stdio.h>
#include <stdlib.h>

int main(){
    int x=10, y;  //x recebe o valor 10
    int *p1;  //temos 1 ponteiro

    p1 = &x; //p1 recebe o endereço na memoria de x
    y = *p1;  //y recebe o valor contido no endereço da memoria de x, que agora esta na variavel p1

    //mostramos o endereço eo valor de x na tela
    printf("O endereço da memoria de x e: %p\no valor de x na posicao e: %d\n", p1, y);
    return 0;
}
