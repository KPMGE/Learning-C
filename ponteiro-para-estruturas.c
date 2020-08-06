//Programa que le um ponto qualquer e mostra-o, usando uma estrutura
//OBS: Sempre que passamos uma estrutura para uma função, é conveniente usar um ponteiro para estrutura, pois caso contratrio,
//toda  a estrutura será copiada
//
//OBS: Para acessar o valor de um campo em um ponteiro para estrutura, usamos '(variavel->campo)'
//OBS: Para acessar o endereço de memória de um campo com um ponteiro para estrutura, usamos '(&variavel->campo)'
//
//
//importação de bibliotecas
#include <stdio.h>

//definindo estrutura para um ponto
struct ponto
{
    float x;
    float y;
};

//função que imprime o ponto dado
void imprime_ponto(struct ponto *p);

//função principal
int main(void)
{
    //definindo variável p, do tipo ponto
    struct ponto p;

    //definindo ponteiro para armazenar o endereço de uma estrutura
    struct ponto *ponteiro_para_ponto;

    //atribuindo o endereço da variavel
    ponteiro_para_ponto = &p;

    //lendo ponto
    printf("digite um ponto qualquer: ");
    scanf("%f %f", &p.x, &p.y);

    //imprimindo ponto digitado
    imprime_ponto(ponteiro_para_ponto);
    return 0;
}

void imprime_ponto(struct ponto *pp)
{
    //mostrando o ponto
    printf("O ponto e:  (%.2f, %.2f)", pp->x, pp->y);
}
