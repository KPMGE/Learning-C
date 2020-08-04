//programa que cria e acessa uma matriz simétrica, ou seja, do tipo matriz[n][n]

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função que cria a matriz
float* cria_matriz(int n);

//função principal
int main(void)
{
    //declaração de variáveis
    int n, i, j;

    //ponteiro para receber a matriz gerada
    float *matriz;

    //lendo tamanho da matriz
    printf("Digite o tamanho da matriz simétrica\n> ");
    scanf("%d", &n);

    matriz = cria_matriz(n);

    //lendo matriz
    printf("Digite a matriz:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%f", &matriz[i * n + j]);

    //mostrando matriz
    printf("Sua matriz e:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%.2f ", matriz[i * n + j]);
        }
        //mostrando quebra de linha
        printf("\n");
    }

    //liberando memoria alocada
    free(matriz);

    return 0;
}

float* cria_matriz(int n)
{
    //variável contendo o tamanho para o vetor-matriz
    int s = n * (n+1) / 2;

    //criando ponteiro para area de memoria a ser alocada dinâmicamente
    float *matriz;

    //alocando o vetor-matriz dinâmicamente
    matriz = (float *) malloc(s * sizeof(float));
    
    //retornando ponteiro para o primeiro elemento da matriz criada
    return matriz;
}

