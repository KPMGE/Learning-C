//programa que calcula a media de uma dada quantidade de notas usando uma função separada
//OBS: nome do vetor sozinho representa a posição do primeiro elemento do vetor, é semelhante a &vetor[0]
//OBS2: vetor[i] éo mesmo que *(vetor + i)
#include <stdio.h>

//função que calcuala a media das notas passadas
float media(int *notas, int qtd);

int main(void)
{
    int qtd;
    float mediaNotas;

    //lendo a o tamanho do vetor
    printf("Digite a quantidade de notas: ");
    scanf("%d", &qtd);

    //declarando um vetor local com o tamanho especificado
    int notas[qtd];

    //lendo dados
    for(int i = 0; i < qtd; i++)
    {
        printf("Digite a nota %d: ", i+1);
        scanf("%d", &notas[i]);
    }

    //calculando media com a função auxiliar, passando o endereço do primeiro elemento do vetor e seu tamanho
    mediaNotas = media(notas, qtd);
    
    //mostrando resultado
    printf("A media das notas e: %f", mediaNotas);

    return 0;
}

float media(int *notas, int qtd)
{
    int soma = 0;

    //percorrendo vetor
    for(int i = 0; i < qtd; i++)
        //incrementando soma
        soma += notas[i];

    //retornando a media
    return soma / (float)qtd;
}
