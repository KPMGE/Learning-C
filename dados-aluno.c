//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo estrutura para um aluno e definindo-a como um tipo 'Aluno'
typedef struct aluno
{
    char nome[51];
    char sexo[21];
    int idade;
    float nota;
} Aluno;

//função que lê os dados de um aluno apenas
void le_aluno(Aluno *aluno);

//função que lê os dados dos alunos
void le_dados_alunos(Aluno *alunos, int n);

//função que calcula a media das notas dos alunos
float media_notas(Aluno *alunos, int n);

//função que verifica se o aluno foi ou não aprovado, media 7
int aprovado(Aluno *aluno);

//função que imprime os dados na tela
void imprime(Aluno *alunos, int n);

//função principal
int main(void)
{
    int n;

    //lendo a quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    //definindo um vetor de alunos
    Aluno alunos[n];

    //pulando uma linha
    printf("\n");

    //lendo os dados de todos os alunos
    le_dados_alunos(alunos, n);

    //mostrando os dados na tela
    imprime(alunos, n);

    return 0;
}

void le_aluno(Aluno *aluno)
{
    //lendo nome do aluno
    printf("Digite o nome do aluno: ");
    scanf(" %50[^\n]", aluno->nome);

    //lendo sexo do aluno
    printf("Digite o sexo do aluno: ");
    scanf(" %20[^\n]", aluno->sexo);

    //lendo idade do aluno
    printf("Digite a idade do aluno: ");
    scanf(" %d", &aluno->idade);
    
    //lendo nota do aluno
    printf("Digite a nota do aluno: ");
    scanf(" %f", &aluno->nota);
}

void le_dados_alunos(Aluno *alunos, int n)
{
    int i;

    //lendo todos os alunos
    for(i = 0; i < n; i++)
    {
        //aluno em questão
        printf("Aluno %d\n", i+1);

        //lendo dados do aluno na posição de i
        le_aluno(&alunos[i]);

        //mostrando espaço para ler o proximo aluno
        printf("\n");
    }
}


float media_notas(Aluno *alunos, int n)
{
    int i;
    float soma = 0, media;

    //calculando a soma das notas
    for(i = 0; i < n; i++)
        soma += alunos[i].nota;

    //calculando media
    media = soma / n;

    //retornando media
    return media;
}

int aprovado(Aluno *aluno)
{
    return (aluno->nota >= 7) ? 1 : 0;
}

void imprime(Aluno *alunos, int n)
{
    int i;
    float media;

    //calculando a media das notas
    media = media_notas(alunos, n);

    printf("\n---------------------------------------Resultados-----------------------------------------------------\n\n");
    //mostrando media
    printf("A media das notas da turma foi: %.2f\n\n", media);

    //mostrando dados de cada aluno e sua situação
    printf("A situaçao de cada aluno e:\n\n");
    for(i = 0; i < n; i++)
    {
        printf("Aluno(a) %s:\n", alunos[i].nome);
        printf("Sexo: %s\n", alunos[i].sexo);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);

        if(aprovado(&alunos[i]))
            printf("Situaçao: Aprovado(a)\n");
        else
            printf("Situaçao: Reprovado(a)\n");

        //pulando uma linha para o proximo aluno
        printf("\n");
    }
}
