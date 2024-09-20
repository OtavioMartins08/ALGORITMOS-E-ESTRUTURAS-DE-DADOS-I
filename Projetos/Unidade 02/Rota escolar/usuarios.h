#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIOS 100
#define MAX_NOME 50
#define MAX_EMAIL 80
#define MAX_SENHA 20

typedef struct
{
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char senha[MAX_SENHA];
} Usuario;

extern Usuario motoristas[MAX_USUARIOS];
extern Usuario alunos[MAX_USUARIOS];

extern int qtdMotoristas;
extern int qtdAlunos;

void cadastrarUsuario(Usuario usuarios[], int *qtdUsuarios, const char *tipoUsuario);
void listarUsuarios(Usuario usuarios[], int qtdUsuarios, const char *tipoUsuario);
int loginUsuario(Usuario usuarios[], int qtdUsuarios, const char *tipoUsuario);
void editarUsuario(Usuario *usuario);
void excluirUsuario(Usuario usuarios[], int *qtdUsuarios, int indice);
int emailValido(const char *email);
void acoesMotorista(int indiceMotorista);
void acoesAluno(int indiceAluno);
void limparTela();

#endif
