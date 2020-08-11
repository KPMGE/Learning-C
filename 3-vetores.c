//importação de bibliotecas
#include <stdio.h>

//função que retorna a quantidade de numeros pares no vetor
int pares(int n, int *vet);

//função que retorna a quantidade de números negativos no vetor
int negativos(int n, int *vet);

//função que inverte a ordem dos elementos do vetor
void inverte(int n, int *vet);

//função principal
int main(void)
{
    //declaração de variáveis
    int n, i, qtdp, qtdn;

    //lendo o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    //declarando vetor do tamanho dado 
    int vet[n];

    //lendo vetor
    printf("Digite o vetor: ");
    for(i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    //calculando quantidade de pares, impares e invertendo
    qtdp = pares(n, vet);
    qtdn = negativos(n, vet);
    inverte(n, vet);

    //mostrando resultados
    printf("\nPares: %d\nNegativos: %d\n", qtdp, qtdn);
    printf("Vetor invertido: ");
    for(i = 0; i < n; i++)
        printf("%d ", vet[i]);

    return 0;
}

int pares(int n, int *vet)
{
    int i, qtd = 0;

    //percorrendo  o vetor
    for(i = 0; i < n; i++)
    {
        //caso o numero seja divisivel por 2, incrementamos a quantidade
        if(vet[i] % 2 == 0)
            qtd++;
    }

    return qtd;
}

int negativos(int n, int *vet)
{
    int i, qtd = 0;

    //percorrendo vetor
    for(i = 0; i < n; i++)
    {
        //caso o numero seja menor que 0, incrementamos a quantidade
        if(vet[i] < 0)
            qtd++;
    }

    return qtd;
}

void inverte(int n, int *vet)
{
    //declaração de variáveis
    int i, j, vet2[n];

    //índice do ultimo elemento do vetor
    j = n -1;

    //percorrendo vetor
    for(i = 0; i < n; i++, j--)
        //atribuindo os elementos em ordem contraria para o vetor2
        vet2[i] = vet[j];
    
    //percorrendo o vetor
    for(i = 0; i < n; i++)
        //atribuindo o conteudo do vetor2, que éo vetor1 invertido, ao vetor 1
        vet[i] = vet2[i];
}
