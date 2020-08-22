//programa que calculca o produto de dois vetores

//importação de bibliotecas
#include <stdio.h>

//função que calcula a soma entre dois vetores
void somaVetores(int *v1, int *v2, int *vResultado, int tamanho);

//função que calcula a subtração entre dois vetores
void subtracaoVetores(int *v1, int *v2, int *vResultado, int tamanho);

//função principal
int main(void)
{
    int tamanho;

    //lendo o tamanho dos vetores
    printf("Digite o tamanho dos vetores que deseja calcular: ");
    scanf("%d", &tamanho);

    //declarando os vetores do tamanho especificado
    int v1[tamanho], v2[tamanho], vetorResultado[tamanho], i, escolha;

    //lendo vetor 1
    printf("Digite o vetor 1\n");
    for(i = 0; i < tamanho; i++)
        scanf("%d", &v1[i]);

    //lendo vetor 2
    printf("Digite o vetor 2\n");
    for(i = 0; i < tamanho; i++)
        scanf("%d", &v2[i]);   

    //capturando escolha do usuario
    printf("O que deseja calcular?\n1 - soma dos vetores\n2 - subtracao dos vetores\n");
    scanf("%d", &escolha);
    
    //definindo ação com base na escolha
    switch(escolha)
    {
        case 1:
            //calculando soma dos vetores com a função
            somaVetores(v1, v2, vetorResultado, tamanho);

            //mostrando o vetor resultante
            printf("A soma dos vetores e:");
            for(i = 0; i < tamanho; i++)
                printf("%d, ", vetorResultado[i]);

            break;

        case 2:
            //calculando soma dos vetores com a função
            subtracaoVetores(v1, v2, vetorResultado, tamanho);

            //mostrando o vetor resultante
            printf("A subtracao dos vetores e:");
            for(i = 0; i < tamanho; i++)
                printf("%d, ", vetorResultado[i]);

            break;
    }
    
    return 0;
}

void somaVetores(int *v1, int *v2, int *vResultado, int tamanho)
{
    int i;

    for(i = 0; i < tamanho; i++)
        vResultado[i] = v1[i] + v2[i];
}

void subtracaoVetores(int *v1, int *v2, int *vResultado, int tamanho)
{
    int i;

    for(i = 0; i < tamanho; i++)
        vResultado[i] = v1[i] + v2[i];
}
