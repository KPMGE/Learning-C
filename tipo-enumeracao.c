//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//criando um tipo enumeração para definir um booleano
enum bool
{
    FALSE,
    TRUE
};

//definindo um pseudônimo para o tipo enumerado
typedef enum bool Bool;

//função principal
int main(void)
{
    //definindo variável do tipo booleano, só podemos atribuir 0 ou 1
    Bool resultado;
    int num;

    //lendo um número qualquer
    printf("Digite um numero: ");
    scanf("%d", &num);

    //descobrindo se o numero é par
    if(num % 2 == 0)
        resultado = 1;
    else 
        resultado = 0;

    //mostrando resultados
    if(resultado)
        printf("Numero par!");
    else
        printf("Numero impar!!");

    return 0;
}
