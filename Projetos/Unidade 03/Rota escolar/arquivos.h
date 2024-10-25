#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "usuarios.h"
#include "rotas.h"

#define ARQUIVO_MOTORISTAS "motoristas.txt"
#define ARQUIVO_ALUNOS "alunos.txt"
#define ARQUIVO_ROTAS "rotas.txt"

extern Usuario *motoristas;
extern int qtdMotoristas;
extern Usuario *alunos;
extern int qtdAlunos;
extern Rota *rotas;
extern int qtdRotas;

void salvarUsuariosNoArquivo(Usuario *usuarios, const char *nomeArquivo);
void carregarUsuariosDoArquivo(Usuario **usuarios, int *qtdUsuarios, const char *nomeArquivo);
void salvarMotoristas();
void salvarAlunos();
void salvarRotasNoArquivo();
void carregarRotasDoArquivo();

#endif
