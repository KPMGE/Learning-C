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

int verificaPrimo(int num){
    int primo=0, i=2;
    while(i < num){
        if(num%i == 0){
            primo++;
        }

        i++; 
    }

    if(primo == 0){
        printf("o numero e primo!");
        return 1;
    }else{
        printf("o numero nao e primo!!");
        return 0;
    }
}

float somaNumeros(int num){
    float soma;

    for(int i=0; i < num; i++){
        printf("digite o numero\n> ");
        scanf("%f", &n);
        soma += n;        
    }

    printf("A soma e :  %f", soma);
    return soma;
}

int main(){
    int escolha;
    printf("O que deseja fazer?\n1 - calcular baskara\n2 - verificar se um numero e primo\n3 - somar N numeros\n> ");
    scanf("%d", &escolha);

    switch(escolha)
    {
    case 1:
        float a, b, c;

        printf("digite o valor de A\n> ");
        scanf("%d", &a);

        printf("digite o valor de B\n> ");
        scanf("%d", &b);

        printf("digite o valor de C\n> ");
        scanf("%d", &c);

        calculaBaskara(a, b, c);
        break;

    case 2:
        int num;
        printf("digite o numero\n> ");
        scanf("%d", &num);

        verificaPrimo(num);

    case 3:
        int qtd;

        printf("digite a quantidade de numeros que deseja somar:  ");
        scanf("%d", &qtd);
        somaNumeros(qtd);
    
    default:
        printf("nenhuma opçao valida escolhida!!");
        break;
    }

    return 0;
}