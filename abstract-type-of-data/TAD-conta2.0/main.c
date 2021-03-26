#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

int main(void) {
  char nome[100];
  int cpf, escolha = 1, qtd = 0, nConta, nConta2;
  float valor;

  Conta_t **listaContas, *contaEscolhida, *contaEscolhida2;

  while (escolha != 0) {
    printf("\n\n------------ TELA INICIAL ---------\n\n");
    printf("0 - sair\n1 - saque\n2 - deposito\n3 - transferencia\n4 - cadastro de conta\n5 - relatiorio\n> ");
    scanf("%d", &escolha);

    switch(escolha) {
      // sacar
      case 1: 
        printf("\n\n------------ SAQUE ---------\n\n");
        // exibindo lista de contas
        exibeDados(listaContas, qtd);

        printf("\ndigite o numero da conta que quer sacar: ");
        scanf("%d",&nConta);

        // pesquisando conta
        contaEscolhida = pesquisaConta(listaContas, qtd, nConta);

        // caso a conta não exista
        if (contaEscolhida == 0) {
          printf("\n\nsua conta nao existe\n\n");
          continue;
        } 
        
        printf("\ndigite o valor que quer sacar: ");
        scanf("%f", &valor);
        if(!sacar(contaEscolhida, valor)) {
          printf("Voce nao pode sacar esse valor!");
        }
      break;

      // depositar
      case 2: 
        printf("\n\n------------ DEPOSITO ---------\n\n");

        // exibindo lista de contas
        exibeDados(listaContas, qtd);

        printf("\ndigite o numero da conta que quer depositar: ");
        scanf("%d", &nConta);

        // obtendo conta
        contaEscolhida = pesquisaConta(listaContas, qtd, nConta);

        // caso a conta não exista
        if (contaEscolhida == 0) {
          printf("\n\nsua conta nao existe\n\n");
          continue;
        } 
        
        printf("\ndigite o valor que quer depositar: ");
        scanf("%f", &valor);

        // depositarndo
        depositar(contaEscolhida, valor);
      break;

      // transferir
      case 3: 
        printf("\n\n------------ TRANSFERENCIA ---------\n\n");

        exibeDados(listaContas, qtd);

        // requisitando os dados
        printf("transferir de: ");
        scanf("%d", &nConta);
        printf("transferir para: ");
        scanf("%d", &nConta2);
        printf("digite o valor a ser transferido: ");
        scanf("%f", &valor);

        if (valor <= 0) {
          printf("\n\nValor invalido!!\n\n");
          continue;
        }

        // obtendo as contas
        contaEscolhida = pesquisaConta(listaContas, qtd, nConta);
        contaEscolhida2 = pesquisaConta(listaContas, qtd, nConta2);

        // transferindo
        transferir(contaEscolhida, contaEscolhida2, valor);
      break;

      // cadastro de conta
      case 4: 
        printf("\n\n------------ CADASTRO DE CONTA ---------\n\n");
        
        // alocando espaço adicional
        listaContas = realloc(listaContas, (qtd + 1)*sizeof(listaContas));

        // requisitando dados do usuario
        printf("digite o nome: ");
        scanf("%s", nome);
        printf("digite o cpf: ");
        scanf("%d", &cpf);
        printf("digite o numero da conta: ");
        scanf("%d", &nConta);
        printf("digite o saldo: ");
        scanf("%f", &valor);

        // criando conta e atualizando valor da quantidade
        listaContas[qtd] = criaConta(nome, cpf, nConta, valor);
        qtd++;
      break;

      // relatorio
      case 5: 
        printf("\n\n--------------- CONTAS CADASTRADAS --------------\n\n");

        exibeDados(listaContas, qtd);

        scanf("%d", &escolha);

        // caso seja digitado 0, voltamos a tela inicial
        if (escolha == 0) {
          escolha++;
          continue;
        }
      break;
    
      default: 
        if (escolha != 0) {
          printf("Escolha invalida!!\n");
        }
      break;
    }
  }

  // liberando memoria alocada
  destroiListaContas(listaContas);

  return 0;
}