#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 50
#define MAX_EMAIL 80
#define MAX_SENHA 20

typedef struct Usuario
{
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char senha[MAX_SENHA];
    struct Usuario *prox;
} Usuario;

extern Usuario *motoristas;
extern Usuario *alunos;
extern int qtdMotoristas;
extern int qtdAlunos;

void cadastrarUsuario(Usuario **usuarios, const char *tipoUsuario);
void listarUsuarios(Usuario *usuarios, const char *tipoUsuario);
Usuario *loginUsuario(Usuario *usuarios, const char *tipoUsuario);
void editarUsuario(Usuario *usuario);
void excluirUsuario(Usuario **usuarios, int indice);
int emailValido(const char *email);
void acoesMotorista(Usuario *motorista);
void acoesAluno(Usuario *aluno);
void limparTela();

#endif
