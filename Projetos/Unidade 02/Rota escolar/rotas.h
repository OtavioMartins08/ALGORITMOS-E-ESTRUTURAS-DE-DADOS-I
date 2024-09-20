#ifndef ROTAS_H
#define ROTAS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROTAS 100
#define MAX_ROTA 100
#define MAX_HORARIO 10

typedef struct
{
    char rota[MAX_ROTA];
    char horarioPartida[MAX_HORARIO];
    char horarioChegada[MAX_HORARIO];
} Rota;

extern Rota rotas[MAX_ROTAS];
extern int qtdRotas;

void adicionarRota();
void listarRotas();
void excluirRota();
int horarioValido(const char *horario);
void adicionarRotaMotorista();
void excluirRotaMotorista();

#endif
