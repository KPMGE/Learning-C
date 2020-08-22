//programa que calcula o produto de dois numeros usando macros

//importação de variáveis
#include <stdio.h>

//definindo macro que realiza o produto entre dois numeros
//OBS: sempre definir todos os parâmetros da macro e a macro entre ()
#define PRODUTO(a, b) ((a) * (b))

//função principal
int main()
{
    //declaração de variaveis
    int num1, num2, resultado;

    //leitura de dados
    printf("Digite dois numeros: ");
    scanf("%d %d", &num1, &num2);

    //variável resultado recebe o resultado da macro produto
    resultado = PRODUTO(num1, num2);

    //mostrando dados finais na tela
    printf("O produto desses numeros e: %d", resultado);
    return 0;
}
