#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

int main(void) {
  char nome[100];
  int cpf, escolha = 1;
  float valor;

  scanf("%s", nome);
  scanf("%d", &cpf);

  Conta_t *contaUsuario = criaConta(nome, cpf, 0, 0, 0.0);

  while (escolha != 0) {
    scanf("%d", &escolha);

    if (escolha == 1) {
      scanf("%f", &valor);
      sacar(contaUsuario, valor);
    }

    if (escolha == 2) {
      scanf("%f", &valor);
      depositar(contaUsuario, valor);
    }
  }

  exibeDados(contaUsuario);
  destroiConta(contaUsuario);

  return 0;
}