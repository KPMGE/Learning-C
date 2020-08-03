//questão B da maratona de programação - 2019


//importação de bibliotecas
#include <stdio.h>

//função que encontra o mais votado, retornando sua posição
int maisVotado(int n, unsigned int *v);

//função principal
int main(void)
{
    //declaração de variáveis
    unsigned int n;
    int i, vencedor;

    //lendo quantidade de votos
    scanf("%d", &n);

    //vetor para armazenar os votos
    unsigned int v[n];

    //lendo cada voto
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    //calculando a posição do vencedor
    vencedor = maisVotado(n, v);

    //caso o vencedor esteja na posição 0(FALSO), ele é Arthur, logo transformamos 0 em 1(VERDADEIRO)
    if(!vencedor) 
        printf("S");
    //caso contrário, verificamos se Arthur empatou com o 'vencedor', se sim, Arthur eleito
    else if(v[0] == v[vencedor])
        printf("S");
    //caso contrário, ele não é eleito
    else
        printf("N");

    return 0;
}

int maisVotado(int n, unsigned int *v)
{
    //declaração de variáveis
    int i, maisVotado = 0;

    //percorrendo vetor
    for(i = 0; i < n; i++)
        //encontrando o mais votado e armazenando sua posição
        if(v[i] > maisVotado)
            maisVotado = i;

    //retornando a posição do mais votado
    return maisVotado;
}
