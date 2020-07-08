#include <stdio.h>
#include <math.h>


int distanciaEntreDoisPontos(int x1, int x2, int y1, int y2){
    int distancia, deltax, deltay;

    deltax = x2 - x1;
    deltay = y2 - y1;


    distancia = sqrt(pow(deltax, 2) - pow(deltay, 2));

    printf("Distancia: %d", distancia);

    return distancia;
}


float calculaBaskara(int a, int b, int c){
    float delta, raiz1, raiz2;

    //calculando o valor de delta
    delta = pow(b, 2) - 4*a*c;

    //caso delta seja menor que 0, nao ha raizes reis
    if(delta < 0){
        printf("nao ha raizes reais!!");
        return 0;
    }

    //do contrario, calculamos as raizes
    else{
        raiz1 = (-b + sqrt(delta))/2*a;
        raiz2 = (-b - sqrt(delta))/2*a;

        printf("R1: %f", raiz1);
        printf("R2: %f", raiz2);
       
        return 1;
    }
}


int verificaPrimo(int num){
    //variaveis declaradas
    int primo=0, i=2;

    //dividindo o numero por todos os numeros menores que ele começando por 2
    while(i < num){
        if(num%i == 0){
            //caso divisivel por algum numero , variavel primo incrementada
            primo++;
        }
        //incremento a variavel i
        i++; 
    }

    //caso nao divisivel por nenhum dos numeros, primo
    if(primo == 0){
        printf("o numero e primo!");
        return 1;
    }else{
        printf("o numero nao e primo!!");
        return 0;
    }
}


float somaNumeros(int num){
    float soma, n;

    //loop for ate o num especificado
    for(int i=0; i < num; i++){
        //lendo o valor a ser somado
        printf("digite o numero\n> ");
        scanf("%f", &n);
        
        //valor incrementado a soma
        soma += n;        
    }

    //mostrando a soma e retornando-a
    printf("A soma e :  %f", soma);
    return soma;
}


int main(){
    int escolha;

    //escolha do usuario
    printf("O que deseja fazer?\n1 - calcular baskara\n2 - verificar se um numero e primo\n3 - somar N numeros\n4 - calcular a distancia entre dois pontos\n> ");
    scanf("%d", &escolha);

    int num, qtd, x1, x2, y1, y2;
    float a, b, c;

    //menu dada a opçao escolhida
    switch(escolha)
    {
    
    //caso opçao 1 escolhida
    case 1:
        printf("digite o valor de A\n> ");
        scanf("%f", &a);

        printf("digite o valor de B\n> ");
        scanf("%f", &b);

        printf("digite o valor de C\n> ");
        scanf("%f", &c);

        calculaBaskara(a, b, c);

        break;

    //caso opçao 2 escolhida
    case 2:
        printf("digite o numero\n> ");
        scanf("%d", &num);

        verificaPrimo(num);
        
        break;

    //caso opçao 3 escolhida
    case 3:
        printf("digite a quantidade de numeros que deseja somar:  ");
        scanf("%d", &qtd);
        somaNumeros(qtd);

        break;

    //caso opçao 4 escolhida    
    case 4:
        printf("digite os valores de x1, x2, y1, y2. Respectivamente\n> ");
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2); 

        distanciaEntreDoisPontos(x1, x2, y1, y2);

        break;
    
    //caso nenhuma das anteriores
    default:
        printf("nenhuma opçao valida escolhida!!");
        break;
    }

    return 0;
}
