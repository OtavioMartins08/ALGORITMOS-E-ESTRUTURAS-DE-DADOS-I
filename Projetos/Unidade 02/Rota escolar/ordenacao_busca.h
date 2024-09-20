#ifndef ORDENACAO_BUSCA_H
#define ORDENACAO_BUSCA_H

#include "usuarios.h"
#include "rotas.h"

void ordenarUsuariosPorNome(Usuario usuarios[], int qtdUsuarios);
int buscarUsuarioPorNome(Usuario usuarios[], int qtdUsuarios, const char *nome);

#endif
