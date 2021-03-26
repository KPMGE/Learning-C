#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

struct usuario {
  char *nome;
  int cpf;
};

Usuario_t* criaUsuario(char *nome, int cpf) {
  Usuario_t *usuarioAlocado = (Usuario_t *) malloc(sizeof(Usuario_t));

  if (usuarioAlocado == NULL) {
    printf("Espaco insuficiente");
    exit(1);
  }

  usuarioAlocado->nome = strdup(nome);

  return usuarioAlocado;
}

char* nomeUsuario(Usuario_t *usuario) {
  return usuario->nome;
}

int cpfUsuario(Usuario_t *usuario) {
  return usuario->cpf;
}

void destroiUsuario(Usuario_t *usuario) {
  free(usuario->nome);
  free(usuario);
}