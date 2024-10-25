#ifndef ROTAS_H
#define ROTAS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROTA 100
#define MAX_HORARIO 10

typedef struct Rota
{
    char rota[MAX_ROTA];
    char horarioPartida[MAX_HORARIO];
    char horarioChegada[MAX_HORARIO];
    struct Rota *prox;
} Rota;

extern int qtdRotas;

void adicionarRota();
void listarRotas();
void excluirRota();
int horarioValido(const char *horario);
void adicionarRotaMotorista();
void excluirRotaMotorista();

#endif
