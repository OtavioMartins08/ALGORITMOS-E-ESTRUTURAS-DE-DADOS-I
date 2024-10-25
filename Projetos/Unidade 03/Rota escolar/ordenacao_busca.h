#ifndef ORDENACAO_BUSCA_H
#define ORDENACAO_BUSCA_H

#include "usuarios.h"

void ordenarUsuariosPorNome(Usuario **usuarios);
Usuario *buscarUsuarioPorNome(Usuario *usuarios, const char *nome);

#endif
