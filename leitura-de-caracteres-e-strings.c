//exemplos de leitura de caracteres e cadeias de caracteres
//OBS: Adicionando um espaço antes dos especificadores, ignoramos eventuais brancos antes do texto

//importação de bibliotecas
#include <stdio.h>

int main(void)
{
    //declaração de varáveis
    char caractere, nome[15], frase[80], frase2[11];

    //lendo um caractere
    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    //lendo um único nome não-composto
    printf("Digite um nome: ");
    scanf(" %s", nome);

    //lendo uma frase até que o usuário use o caractere de mudança de linha ('\n'), ou seja, tecle ENTER
    printf("Digite uma frase e tecle ENTER para finalizar: ");
    scanf(" %80[^\n]", frase);

    //lendo uma frase de, no máximo, 20 caracteres
    printf("Digite uma frase de no maximo 20 caracteres ou tecle ENTER para finalizar: ");
    scanf(" %10[^\n]", frase2);

    //mostrando os resultados
    printf("\n\nO nome caractere foi: %c\n", caractere);
    printf("O nome digitado foi: %s\n", nome);
    printf("A frase digitada foi: %s\n", frase);
    printf("os 10 caracteres capturados foram: %s", frase2);

    return 0;
}
