#include "arquivos.h"
#include "usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Usuario *motoristas;
extern int qtdMotoristas;

extern Usuario *alunos;
extern int qtdAlunos;

extern Rota *rotas;
extern int qtdRotas;

void salvarRotasNoArquivo()
{
    FILE *arquivo = fopen(ARQUIVO_ROTAS, "w");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo %s para escrita!\n", ARQUIVO_ROTAS);
        return;
    }

    Rota *aux = rotas;
    while (aux != NULL)
    {
        fprintf(arquivo, "%s;%s;%s\n", aux->rota, aux->horarioPartida, aux->horarioChegada);
        aux = aux->prox;
    }
    fclose(arquivo);
}

void carregarRotasDoArquivo()
{
    FILE *arquivo = fopen(ARQUIVO_ROTAS, "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo %s para leitura!\n", ARQUIVO_ROTAS);
        return;
    }

    qtdRotas = 0;
    rotas = NULL;
    Rota *atual = NULL;

    while (1)
    {
        Rota *novaRota = (Rota *)malloc(sizeof(Rota));
        if (!novaRota)
        {
            printf("Erro ao alocar memória para rota!\n");
            break;
        }
        if (fscanf(arquivo, "%[^;];%[^;];%[^\n]\n", novaRota->rota, novaRota->horarioPartida, novaRota->horarioChegada) == 3)
        {
            novaRota->prox = NULL;
            if (rotas == NULL)
            {
                rotas = novaRota;
            }
            else
            {
                atual->prox = novaRota;
            }
            atual = novaRota;
            qtdRotas++;
        }
        else
        {
            free(novaRota);
            break;
        }
    }
    fclose(arquivo);
}

void salvarMotoristas()
{
    FILE *file = fopen("motoristas.txt", "w");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para salvar motoristas!\n");
        return;
    }

    Usuario *aux = motoristas;
    while (aux != NULL)
    {
        fprintf(file, "%s,%s,%s\n", aux->nome, aux->email, aux->senha);
        aux = aux->prox;
    }
    fclose(file);
    printf("Motoristas salvos com sucesso!\n");
}

void salvarAlunos()
{
    FILE *file = fopen("alunos.txt", "w");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para salvar alunos!\n");
        return;
    }

    Usuario *aux = alunos;
    while (aux != NULL)
    {
        fprintf(file, "%s,%s,%s\n", aux->nome, aux->email, aux->senha);
        aux = aux->prox;
    }
    fclose(file);
    printf("Alunos salvos com sucesso!\n");
}

void salvarUsuariosNoArquivo(Usuario *usuarios, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo %s para escrita!\n", nomeArquivo);
        return;
    }

    Usuario *aux = usuarios;
    while (aux != NULL)
    {
        fprintf(arquivo, "%s;%s;%s\n", aux->nome, aux->email, aux->senha);
        aux = aux->prox;
    }
    fclose(arquivo);
}

void carregarUsuariosDoArquivo(Usuario **usuarios, int *qtdUsuarios, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo %s para leitura!\n", nomeArquivo);
        return;
    }

    *qtdUsuarios = 0;
    *usuarios = NULL;
    Usuario *atual = NULL;

    while (1)
    {
        Usuario *novoUsuario = (Usuario *)malloc(sizeof(Usuario));
        if (!novoUsuario)
        {
            printf("Erro ao alocar memória para usuário!\n");
            break;
        }
        if (fscanf(arquivo, "%[^;];%[^;];%[^\n]\n", novoUsuario->nome, novoUsuario->email, novoUsuario->senha) == 3)
        {
            novoUsuario->prox = NULL;
            if (*usuarios == NULL)
            {
                *usuarios = novoUsuario;
            }
            else
            {
                atual->prox = novoUsuario;
            }
            atual = novoUsuario;
            (*qtdUsuarios)++;
        }
        else
        {
            free(novoUsuario);
            break;
        }
    }
    fclose(arquivo);
}
