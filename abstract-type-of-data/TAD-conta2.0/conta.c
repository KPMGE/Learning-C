#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"

struct conta {
  Usuario_t *usuario;
  int conta;
  float saldo;
};


Conta_t* criaConta(char *nome, int cpf, int conta, float saldo) {
  Conta_t *contaAlocada = (Conta_t *) malloc(sizeof(Conta_t));

  if (contaAlocada == NULL) {
    printf("Espaco insuficiente");
    exit(1);
  }

  contaAlocada->usuario = criaUsuario(nome, cpf);
  contaAlocada->conta = conta;
  contaAlocada->saldo = saldo;
}

int contaUsuario(Conta_t *conta) {
  return conta->conta;
}

float saldo(Conta_t *conta) {
  return conta->saldo;
}

int sacar(Conta_t* conta, float valor) {
  
  if (valor > saldo(conta)) {
    return 0;
  }

  conta->saldo = saldo(conta) - valor;
  return 1;
}

void depositar(Conta_t *conta, float valor) {
  conta->saldo = saldo(conta) + valor;
}

void exibeDados(Conta_t **listaContas, int qtd) {
  for (int i = 0; i < qtd; i++) {
    printf("Conta %d:\n", i + 1);
    printf("Usario: %s\n", nomeUsuario(listaContas[i]->usuario));
    printf("Numero Conta: %d\n", contaUsuario(listaContas[i]));
    printf("Saldo: %.3f\n", saldo(listaContas[i]));
    printf("\n");
  }
}

int transferir(Conta_t* conta1, Conta_t* conta2, float valor) {
  if (!sacar(conta1, valor)) {
    return 0;
  }

  depositar(conta2, valor);
}

Conta_t* pesquisaConta(Conta_t** listaContas, int qtd, int Nconta) {
  for (int i = 0; i < qtd; i++) {
    if (contaUsuario(listaContas[i]) == Nconta) {
      return listaContas[i];
    }
  }
  return 0;
}


void destroiListaContas(Conta_t **listaContas) {
  free(listaContas);
}

