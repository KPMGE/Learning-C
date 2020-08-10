//Programa que calcula a sequecia de Fibonacci

//importação de bibliotecas
#include <stdio.h>

//função que imprime todos os numeros da sequencia de fibonacci até n
void imprime_fibonacci(int n);

//função principal
int main(void)
{
    int n;

    printf("Digite a quantidade de numeros da sequencia que deseja calcular: ");
    scanf("%d", &n);

    //imprimindo sequência na quantidade especificada
    imprime_fibonacci(n);

    return 0;
}

void imprime_fibonacci(int n)
{
    //declaração de variáveis
    int i, soma = 0, anterior = 0, proximo = 1;

    //mostrando o primeiro 1 da sequencia
    printf("%d ", 1);

    //loop até o valor dado
    for(i = 0; i < n; i++)
    {
        //calculando a soma como o resultado do numero anterior e do proximo
        soma = anterior + proximo;

        //o anterior agora se torna o proximo
        anterior = proximo;

        //o proximo agora recebe a soma
        proximo = soma;

        //mostrando resultado
        printf("%d ", soma);

        //resetando a variável soma
        soma = 0;
    }
}
