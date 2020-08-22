/*
(BOCA:L2_18)
 Problema: Com dificuldade para estudar Álgebra Linear,
Padi decidiu fixar os conceitos da disciplina fazendo programas de
computador com a matéria. Para começar, quis fazer um programa
que, dado o tamanho da matriz e seus valores, que nunca são iguais,
calculasse o maior valor e imprimisse a posição dele na matriz.
Também com dúvidas em Programação, Padi agora pede sua ajuda e
você deve implementar o código para depois tirar as dúvidas do código
dele.

Entrada: uma linha com os valores L (1 <= L <= 100) e C (1 <= C <=
100), representando o tamanho da matriz em linhas e colunas,
respectivamente. Depois, L linhas com C valores V (-32767 <= V <=
32767) cada.

Saída: o maior valor V da matriz, seguido
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função que retorna um vetor com o valor do maior elemento e os valores da linha e coluna, respectivamente
int* maior_valor(int **matriz, int l, int c);

//função principal
int main(void)
{
    //declaração de variaveis
    int l, c, i, j, *maior;

    //leitura das dimensões da matriz
    scanf(" %d %d", &l, &c);

    //variável para conter o vetor de ponteiros
    int **matriz;

    //alocando matriz dinamicamente
    matriz = (int **) malloc(l * sizeof(int *));
    for(i = 0; i < l; i++)
        matriz[i] = (int *) malloc(c * sizeof(int));

    //lendo matriz
    for(i=0; i < l; i++)
        for(j=0; j < c; j++)
            //leitura do elemento da matriz na posição i, j
            scanf(" %d", &matriz[i][j]);
            
    //encontrando o maior valor
    maior = maior_valor(matriz, l, c);

    //mostrando resultados
    printf("%d (%d, %d)", maior[0], maior[1], maior[2]);
    
    //liberando memória alocada em cada vetor
    for(i = 0; i < l; i++)
        free(matriz[i]);

    //liberando vetor de ponteiros e vetor para maior
    free(matriz);
    free(maior);
    
    return 0;
}

int* maior_valor(int **matriz, int l, int c)
{
    //declaração de variáveis
    int i, j;

    //ponteiro para o vetor que armazena o maior valor e suas coordenadas
    int *maior;

    //alocando vetor dinâmicamente
    maior = (int *) malloc(3 * sizeof(int));

    //inicializando com o valor 0 na primeira posição
    maior[0] = 0;

    //percorrendo matriz
    for(i = 0; i < l; i++)
        for(j = 0; j < c; j++)
        {
            //capturando o endereço do maior elemento
            if(matriz[i][j] > maior[0])
            {
                maior[0] = matriz[i][j];
                maior[1] = i + 1;
                maior[2] = j + 1;
            }
        }

    //retornando maior elemento
    return maior;
}
