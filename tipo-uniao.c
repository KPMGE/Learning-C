//importação de bibliotecas
#include <stdio.h>

//definindo um tipo união aleatorio
union exemplo
{
    char nome[31];
    int idade;
};

//definindo um pseudônimo para o tipo união
typedef union exemplo Guy;

//função principal
int main(void)
{
    //definindo variável do tipo união
    Guy k;

    //lendo dados
    printf("Digite um nome e uma idade: ");
    scanf(" %30[^\n] %d", k.nome, &k.idade);

    //OBS: O nome não será mostrado, pois em um tipo união, toda vez q acessamos um campo
    //o valora anterior deixa de existir
    //mostrando dados
    printf("Nome: %s\nidade: %d", k.nome, k.idade);
    return 0;
}
