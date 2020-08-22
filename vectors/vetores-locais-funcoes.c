//programa que acessa um vetor de uma função chamada dentro da função que chama
//OBS:podemos fazer isso definindo alocação dinâmica, pois assim o ponteito para o nosso vetor não deicará de
//existir depois que a função terminar a execução

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//função que retorna um vetor ao contrario de tamanho n
int* vetorContrario(int n);

int main()
{
    //declaracão de variaveis
    int n, *vetorC;

    //lendo dados
    printf("Digite a quantidade: ");
    scanf("%d", &n);

    //variavel vetorc recebe o endereço inicical do vetor alocado dinamicamente na função
    vetorC = vetorContrario(n);

    //percorrendo vetor mostrando resultado
    for(int i = 0; i < n; i++)
        printf("vetorImpares[%d] = %d\n", i, vetorC[i]);

    //liberando memoria
    free(vetorC);
    return 0;
}

int* vetorContrario(int n)
{
    //ponteiro para a area que sera alocada
    int *vetor, k = n;

    //vetor recebe o endreço inicial da area alocada dinamicamente
    vetor = (int *)malloc(n*sizeof(int));

    //criando vetor ao contrario
    for(int i = 0; i < n; i++, k--)
        vetor[i] = k;

    //retornando endereço da primeira posição do vetor
    return vetor;
}
