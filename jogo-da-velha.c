//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//definindo estrutura para um tipo ponto
typedef struct ponto
{
    int x;
    int y;
} Ponto;

//função que imprime o jogo
void imprime(char matriz[][5], Ponto* p, char c);

//função que lê a jogada
void le_jogada(Ponto* p, char* c);

//função que verifica se uma linha tem uma sequencia de mesmos caracteres
int verifica_linha(char velha[][5], int i);

//função que verifica se uma coluna tem uma sequencia de mesmos caracteres
int verifica_coluna(char velha[][5], int j);

//função que verifica se há alguma diagonal com uma sequencia de mesmos caracteres
int verifica_diagonais(char velha[][5]);

//função que verifica se o jogo terminou
int final_jogo(char velha[][5]);

//função principal
int main(void)
{
    //declaração de variáveis
    int i, j, cont = 0;
    Ponto p;
    char c, velha[3][5];

    //criando estrutura gráfica do do jogo
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            //caso a coluna do elemento seja par, adicionamos o caractere '-'
            if(j % 2 == 0)
                velha[i][j] = '-';
            //caso contrário, adicionamos '|'
            else
                velha[i][j] = '|';
        }
    }

    //lendo jogadas até alguém vencer ou até completar 9 jogadas
    do
    {
        //lendo jogada
        le_jogada(&p, &c);

        //imprimindo resultado
        imprime(velha, &p, c);

        //incrementando contador
        cont++;

        //caso forem feitas 9 jogadas, printamos velha
        if(cont == 9)
        {
            printf("Velha!!");
            return 0;
        }
    } while(!final_jogo(velha));

    //caso o jogo seja interrompido
    printf("Final do jogo!!");

    return 0;
}

void imprime(char velha[][5], Ponto* p, char c)
{
    //declaração de variáveis
    int i, j;

    //o elemento na posição especificada recebe o caractere
    velha[p->x][p->y] = c;

    //mostrando matriz
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%c ", velha[i][j]);
        }
        printf("\n");
    }
}

void le_jogada(Ponto* p, char* c)
{        
    //repetindo até o usuario digitar um valor válido
    do
    {
        printf("Digite um ponto e um valor: ");
        scanf("%d %d %c", &p->x, &p->y, c);

    } while((p->x > 3) || (p->y > 3));

    //ajustando o valor do ponto em x
    p->x -= 1;
    //caso o valor seja 1, transformamos em 0
    if(p->y == 1)
        p->y -= 1;
    //caso seja 3, transformamos em 4
    if(p->y == 3)
        p->y += 1;
}

int verifica_linha(char velha[][5], int i)
{
    //caso uma linha seja toda de 'o' ou de 'x'
    if((velha[i][0] == 'o' && velha[i][2] == 'o' && velha[i][4] == 'o' ) || (velha[i][0] == 'x' && velha[i][2] == 'x' && velha[i][4] == 'x'))
        return 1;
    else
        return 0;
}

int verifica_coluna(char velha[][5], int j)
{
    //caso uma coluna seja toda de 'o' ou de 'x'
    if((velha[0][j] == 'o' && velha[1][j] == 'o' && velha[2][j] == 'o') || (velha[0][j] == 'x' && velha[1][j] == 'x' && velha[2][j] == 'x'))
        return 1;
    else 
        return 0;
}

int verifica_diagonais(char velha[][5])
{
    //caso uma diagoal seja toda de 'o' ou de 'x'
    if((velha[0][0] == 'o' && velha[1][2] == 'o' && velha[2][4] == 'o') || ( velha[0][0] == 'x' && velha[1][2] == 'x' && velha[2][4] == 'x'))
        return 1;
    else
        return 0;
}

int final_jogo(char velha[][5])
{
    //indices da matriz
    int i, j;

    //percorrendo a matriz
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            //caso alguma linha ou coluna ou ainda diagonal seja encontrada, retornamos 1, se não 0
            if(verifica_linha(velha, i) || verifica_coluna(velha, j) || verifica_diagonais(velha))
                return 1;
            else
                return 0;
        }
    }
}
