#include "rotas.h"
#include "arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Rota rotas[MAX_ROTAS];
int qtdRotas = 0;

int horarioValido(const char *horario)
{
    if (strlen(horario) != 5)
        return 0;
    for (int i = 0; i < 5; i++)
    {
        if (i == 2 && horario[i] != ':')
            return 0;
        if (i != 2 && !isdigit(horario[i]))
            return 0;
    }
    return 1;
}

void adicionarRota()
{
    if (qtdRotas >= MAX_ROTAS)
    {
        printf("Limite de rotas atingido!\n");
        return;
    }

    Rota novaRota;
    printf("Digite a rota: ");
    scanf(" %[^\n]s", novaRota.rota);
    do
    {
        printf("Digite o horario de partida (HH:MM): ");
        scanf("%s", novaRota.horarioPartida);
    } while (!horarioValido(novaRota.horarioPartida));

    do
    {
        printf("Digite o horario de chegada (HH:MM): ");
        scanf("%s", novaRota.horarioChegada);
    } while (!horarioValido(novaRota.horarioChegada));

    rotas[qtdRotas++] = novaRota;
    printf("Rota adicionada com sucesso!\n");
}

void listarRotas()
{
    printf("Lista de rotas:\n");
    for (int i = 0; i < qtdRotas; i++)
    {
        printf("%d. Rota: %s | Partida: %s | Chegada: %s\n", i + 1, rotas[i].rota, rotas[i].horarioPartida, rotas[i].horarioChegada);
    }
}

void excluirRota()
{
    int indice;
    listarRotas();
    printf("Digite o numero da rota que deseja excluir: ");
    scanf("%d", &indice);
    if (indice < 1 || indice > qtdRotas)
    {
        printf("Indice invalido!\n");
        return;
    }

    for (int i = indice - 1; i < qtdRotas - 1; i++)
    {
        rotas[i] = rotas[i + 1];
    }
    qtdRotas--;
    printf("Rota excluida com sucesso!\n");
}

void adicionarRotaMotorista()
{
    if (qtdRotas >= MAX_ROTAS)
    {
        printf("Limite de rotas atingido!\n");
        return;
    }

    Rota novaRota;
    printf("Digite a rota: ");
    scanf(" %[^\n]s", novaRota.rota);
    do
    {
        printf("Digite o horario de partida (HH:MM): ");
        scanf("%s", novaRota.horarioPartida);
    } while (!horarioValido(novaRota.horarioPartida));

    do
    {
        printf("Digite o horario de chegada (HH:MM): ");
        scanf("%s", novaRota.horarioChegada);
    } while (!horarioValido(novaRota.horarioChegada));

    rotas[qtdRotas++] = novaRota;
    printf("Rota adicionada com sucesso!\n");
    salvarRotasNoArquivo();
}

void excluirRotaMotorista()
{
    int indice;
    listarRotas();
    printf("Digite o numero da rota que deseja excluir: ");
    scanf("%d", &indice);

    if (indice < 1 || indice > qtdRotas)
    {
        printf("Indice invalido!\n");
        return;
    }

    for (int i = indice - 1; i < qtdRotas - 1; i++)
    {
        rotas[i] = rotas[i + 1];
    }
    qtdRotas--;
    printf("Rota excluida com sucesso!\n");
    salvarRotasNoArquivo();
}