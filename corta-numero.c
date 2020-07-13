#include <stdio.h>

int main(){
    //OBS: numero deve ter 4 casas decimais do tipo abcd
    int num, ab, cd;

    printf("Digite um numero de 4 casas decimais\n> ");
    scanf("%d", &num);

    //os dois ultimos numeros sao dados pelo resto da divisao de numero por 100
    cd = num%100;

    //atualizamos o valor de numero, subtraindo os dois ultimos numeros, logo ficaremos com 00 ao final
    num -= cd;

    //como temos 00 ao final, podemos dividir por 100, de modo a corta-los
    ab = num/100;

    //mostrando as partes
    printf("ab = %d\ncd = %d", ab, cd);
    return 0;
}