//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função principal
int main(void)
{
    //declaração de variáveis
    char busca[4], palavra[4];
    int i, j, k, cont = 0;

    //capturando palavra a ser encontrada
    printf("Digite uma palavra de 3 letras: ");
    scanf(" %3[^\n]", busca);

    //loops para fazer todas as combinações possiveis
    for(i = 'a'; i <= 'z'; i++)
    {
        for(j = 'a'; j <= 'z'; j++)
        {
            for(k = 'a'; k <= 'z'; k++)
            {
                //mostrando anagrama formado pela união das letras
                printf("%c%c%c", i, j, k);
                printf("\n");

                //criando uma anagrama de 3 letras na variável palavra
                palavra[0] = i;
                palavra[1] = j;
                palavra[2] = k;
                palavra[3] = '\0';

                //incrementando contador
                cont++;

                //caso as o anagrama ea palavra digitada sejam iguais
                if(!strcmp(palavra, busca))
                {
                    //mostrando mensagem e terminando o programa
                    printf("Palavra encontrada!!\n%d combinacoes feitas!!", cont);
                    exit(1);
                }
            }
        }
    }

    return 0;
}
