//Programa que lê uma dada quantidade de nomes de alunos em uma tabela
//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função que recebe uma cadeia de caracteres e fonece uma cópia, alocada dinâmicamente
char* duplica(char *s);

//função que lê uma linha da tabela
char* le_linha(void);

//função que lê todos os alunos
void le_alunos(char **tabela, int qtd_alunos);

//função que libera memória alocada
void libera_memoria(int n, char **tabela);

//função que imprime a tabela
void imprime(char **tabela, int n);

//função principal
int main(void)
{
    int qtd_alunos;
    char **tabela;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &qtd_alunos);

    //alocando a tabela dinamicamente
    tabela = (char **) malloc(qtd_alunos * sizeof(char *));
    
    //lendo os alunos
    le_alunos(tabela, qtd_alunos);
    
    //imprimindo a tabela
    imprime(tabela, qtd_alunos);

    //liberando a memoria alocada
    libera_memoria(qtd_alunos, tabela);
    return 0;
}

char* duplica(char *s)
{
    //calculando tamanho da cadeia
    int n = strlen(s);

    //vetor para armazenar a cadeia de caracteres
    char *copia;

    //alocando o vetor dinâmicamente
    copia = (char *) malloc((n + 1) * sizeof(char));

    //copiando os dados de s para copia
    strcpy(copia, s);

    //retornando cadeia alocada
    return copia;
}

char* le_linha(void)
{
    //definindo tamanho maximo para linha
    char linha[101];

    //lendo dados
    printf("Digite o nome do aluno: ");
    scanf(" %100[^\n]", linha);

    //retornando a linha lida alocada dinâmicamente com a função
    return duplica(linha);
}

void le_alunos(char **tabela, int qtd_alunos)
{
    int i;

    //loop na quantidade dada
    for(i = 0; i < qtd_alunos; i++)
        //lendo cada linha
        tabela[i] = le_linha();
}

void libera_memoria(int n, char **tabela)
{
    int i;

    //liberando linha a linha
    for(i = 0; i < n; i++)
        free(tabela[i]);
}

void imprime(char **tabela, int n)
{
    int i;

    printf("Temos os nomes:\n");
    for(i = 0; i < n; i++)
        printf("%s\n", tabela[i]);

}
