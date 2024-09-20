#include "arquivos.h"
#include "usuarios.h"
#include <stdio.h>

extern Usuario motoristas[MAX_USUARIOS];
extern int qtdMotoristas;

extern Usuario alunos[MAX_USUARIOS];
extern int qtdAlunos;

extern Rota rotas[MAX_ROTAS];
extern int qtdRotas;

void salvarRotasNoArquivo()
{
    FILE *arquivo = fopen(ARQUIVO_ROTAS, "w");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo %s para escrita!\n", ARQUIVO_ROTAS);
        return;
    }

    for (int i = 0; i < qtdRotas; i++)
    {
        fprintf(arquivo, "%s;%s;%s\n", rotas[i].rota, rotas[i].horarioPartida, rotas[i].horarioChegada);
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
    while (fscanf(arquivo, "%[^;];%[^;];%[^\n]\n", rotas[qtdRotas].rota, rotas[qtdRotas].horarioPartida, rotas[qtdRotas].horarioChegada) == 3)
    {
        qtdRotas++;
    }
    fclose(arquivo);
}

void salvarMotoristas()
{
    FILE *file = fopen("motoristas.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar motoristas!\n");
        return;
    }

    for (int i = 0; i < qtdMotoristas; i++)
    {
        fprintf(file, "%s,%s,%s\n", motoristas[i].nome, motoristas[i].email, motoristas[i].senha);
    }
    fclose(file);
    printf("Motoristas salvos com sucesso!\n");
}

void salvarAlunos()
{
    FILE *file = fopen("alunos.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar alunos!\n");
        return;
    }

    for (int i = 0; i < qtdAlunos; i++)
    {
        fprintf(file, "%s,%s,%s\n", alunos[i].nome, alunos[i].email, alunos[i].senha);
    }
    fclose(file);
    printf("Alunos salvos com sucesso!\n");
}

void salvarUsuariosNoArquivo(Usuario usuarios[], int qtdUsuarios, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo %s para escrita!\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < qtdUsuarios; i++)
    {
        fprintf(arquivo, "%s;%s;%s\n", usuarios[i].nome, usuarios[i].email, usuarios[i].senha);
    }
    fclose(arquivo);
}

void carregarUsuariosDoArquivo(Usuario usuarios[], int *qtdUsuarios, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo %s para leitura!\n", nomeArquivo);
        return;
    }

    *qtdUsuarios = 0;
    while (fscanf(arquivo, "%[^;];%[^;];%[^\n]\n", usuarios[*qtdUsuarios].nome, usuarios[*qtdUsuarios].email, usuarios[*qtdUsuarios].senha) == 3)
    {
        (*qtdUsuarios)++;
    }
    fclose(arquivo);
}
