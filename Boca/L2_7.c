#include <stdio.h>

/*(BOCA:L2_7) Problema: Faça um programa para informar se um número é primo*/

int main(){
    //declaração de variaveis
    int n, i=2;

    //leitura dos dados
    scanf("%d", &n);

    //se o valor de de i for um primo no intervalo de 2 a 7
    if(n == 2 || n == 3 || n == 5 || n == 7){
        printf("Primo");
    }

    //quando i fica maior q 7, temos q se ele não for multiplo de nenhum dos numeros abaixo, logo ele é primo
    else if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0){
        printf("Nao primo");
    }

    //se o numero não e multiplo dos anteriores, logo ele é primo
    else{
        printf("Primo");
    }

	return 0;
}

