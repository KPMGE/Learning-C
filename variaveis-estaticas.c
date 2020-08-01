//programa que mostra os numeros de 0 à 100 em linhas de 5, usando variaveis estáticas
//para capturar a quantidade de vezes que a função de impressão é chamada

//importação de bibliotecas
#include <stdio.h> 

//função que imprime os numeros em linhas de 5
void mostraNumeros(int n);

//função principal
int main()
{
    int i;

    //repetindo 100 vezes
    for(i = 0 ; i <= 100; i++)
        //chamando a função para mostrar o numero correspondente a cada loop
        mostraNumeros(i);

    return 0;
}

void mostraNumeros(int numero)
{
    //definindo a variável estática n
    static int n = 1;

    //mostrando o numero atual
    printf("%d ", numero);

    //caso o número de execuções seja 6, pulamos uma linha e resetamos a variável n
    if(n == 5)
    {
        printf("\n");
        n = 0;
    }

    //incrementando n após uma execução da função
    n++;
}
