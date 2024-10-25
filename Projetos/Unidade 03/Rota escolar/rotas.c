#include "rotas.h"
#include "arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Rota *rotas = NULL;
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
    Rota *novaRota = (Rota *)malloc(sizeof(Rota));
    if (!novaRota)
    {
        printf("Erro ao alocar memória para nova rota!\n");
        return;
    }

    printf("Digite a rota: ");
    scanf(" %[^\n]s", novaRota->rota);
    if (strlen(novaRota->rota) == 0)
    {
        printf("A rota não pode estar vazia!\n");
        free(novaRota);
        return;
    }

    do
    {
        printf("Digite o horário de partida (HH:MM): ");
        scanf("%s", novaRota->horarioPartida);
    } while (!horarioValido(novaRota->horarioPartida));

    do
    {
        printf("Digite o horário de chegada (HH:MM): ");
        scanf("%s", novaRota->horarioChegada);
    } while (!horarioValido(novaRota->horarioChegada));

    novaRota->prox = rotas;
    rotas = novaRota;
    qtdRotas++;

    printf("Rota '%s' adicionada com sucesso! Partida: %s, Chegada: %s\n",
           novaRota->rota, novaRota->horarioPartida, novaRota->horarioChegada);
}

void listarRotas()
{
    Rota *atual = rotas;
    int indice = 1;

    printf("Lista de rotas:\n");
    while (atual != NULL)
    {
        printf("%d. Rota: %s | Partida: %s | Chegada: %s\n",
               indice++, atual->rota, atual->horarioPartida, atual->horarioChegada);
        atual = atual->prox;
    }
}

void excluirRota()
{
    int indice, i = 1;
    listarRotas();
    printf("Digite o número da rota que deseja excluir: ");
    scanf("%d", &indice);

    if (indice < 1)
    {
        printf("Índice inválido!\n");
        return;
    }

    Rota *atual = rotas, *anterior = NULL;
    while (atual && i < indice)
    {
        anterior = atual;
        atual = atual->prox;
        i++;
    }

    if (!atual)
    {
        printf("Rota não encontrada!\n");
        return;
    }

    if (anterior == NULL)
    {
        rotas = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
    qtdRotas--;
    printf("Rota excluída com sucesso!\n");
}

void adicionarRotaMotorista()
{
    adicionarRota();
    salvarRotasNoArquivo();
}

void excluirRotaMotorista()
{
    listarRotas();
    excluirRota();
    salvarRotasNoArquivo();
}
