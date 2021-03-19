#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "conta.h"

struct conta {
  Usuario_t *usuario;
  int conta;
  int agencia;
  float saldo;
};


Conta_t* criaConta(char *nome, int cpf, int agencia, int conta, float saldo) {
  Conta_t *contaAlocada = (Conta_t *) malloc(sizeof(Conta_t));

  if (contaAlocada == NULL) {
    printf("Espaco insuficiente");
    exit(1);
  }

  contaAlocada->usuario = criaUsuario(nome, cpf);
  contaAlocada->agencia = agencia;
  contaAlocada->conta = conta;
  contaAlocada->saldo = saldo;
}

int agencia(Conta_t *conta) {
  return conta->agencia;
}

int contaUsuario(Conta_t *conta) {
  return conta->conta;
}

float saldo(Conta_t *conta) {
  return conta->saldo;
}

void sacar(Conta_t *conta, float valor) {
  if (valor > saldo(conta)) {
    printf("Voce nao pode sacar!");
    exit(1);
  }

  conta->saldo = saldo(conta) - valor;
}

void depositar(Conta_t *conta, float valor) {
  conta->saldo = saldo(conta) + valor;
}

void exibeDados(Conta_t *conta) {
  printf("Usario: %s\n", nomeUsuario(conta->usuario));
  printf("Conta: %d\n", contaUsuario(conta));
  printf("Agencia: %d\n", agencia(conta));
  printf("Saldo: %.3f\n", saldo(conta));
}

void destroiConta(Conta_t *conta) {
  free(conta);
}
