#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno* cria_aluno(char nome[], int matricula) {
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
    if (aluno == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o aluno\n");
        exit(1);
    }

    int i = 0;
    while (nome[i] != '\0' && i < sizeof(aluno->nome) - 1) {
        aluno->nome[i] = nome[i];
        i++;
    }
    aluno->nome[i] = '\0'; 
    aluno->matricula = matricula;
    aluno->num_disciplinas = 0;
    return aluno;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina) {
    if (aluno->num_disciplinas < 7) {
        aluno->disciplinas[aluno->num_disciplinas] = disciplina;
        aluno->num_disciplinas++;
    }
}

void exclui_aluno(Aluno* aluno) {
    for (int i = 0; i < aluno->num_disciplinas; i++) {
        exclui_disciplina(aluno->disciplinas[i]);
    }
    free(aluno);
}
