#include <stdio.h>
#include <stdlib.h>

void main(void){
    int x; //declarando variavel x
    int *p1, **p2;  //temos q p1 é um ponteiro do tipo int e p2 é um ponteiro que aponta para outro ponteiro do tipo int

    x = 10; //x recebe 10
    p1 = &x; //p1 recebe o endereço de x
    p2 = &p1;  //p2 recebe o endereço de p1

    printf("O valor de x e: %d", **p2);  //mostramos o valor de x a partir de p2, que aponta para p1, que aponta para o valor de x
}