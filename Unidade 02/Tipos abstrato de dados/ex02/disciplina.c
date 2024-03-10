#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

typedef struct Disciplina Disciplina;

Disciplina* cria_disciplina(char nome[], int codigo) {
  Disciplina* disciplina = (Disciplina*) malloc(sizeof(Disciplina));
  strncpy(disciplina->nome, nome, sizeof(disciplina->nome));
  disciplina->nome[sizeof(disciplina->nome) - 1] = '\0';
  disciplina->codigo = codigo;
  return disciplina;
}

void exclui_disciplina(Disciplina* disciplina) {
  free(disciplina);
}