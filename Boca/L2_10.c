#include <stdio.h>

int main(){
    //declaração de variaveis
    int n, m, i=1, tab;

    //leitura dos dados
    scanf("%d%d", &n, &m);

    //loop for de n ate m
    for(n; n <= m; n++){
        //loop for de 1 ate 10
        for(i=1; i <= 10; i++){
            //variavel tab recebe a multiplicação de n por i
            tab = n*i;
            //impressão dos valores da multiplicação 
            printf("%d x %d = %d\n", n, i, tab);
        }
    }

    return 0;
}
