#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"

int main() {
    // Criação de disciplinas
    Disciplina* d1 = cria_disciplina("Geometria Analítica", 1);
    Disciplina* d2 = cria_disciplina("Algoritmos e Estruturas de Dados I", 2);
    Disciplina* d3 = cria_disciplina("Cálculo II", 3);

    // Criação dos alunos
    Aluno* a1 = cria_aluno("Luis", 101);
    Aluno* a2 = cria_aluno("Otavio", 102);

    // Matrícula de alunos em disciplinas
    matricula_disciplina(a1, d1);
    matricula_disciplina(a1, d2);
    matricula_disciplina(a2, d1);
    matricula_disciplina(a2, d3);

    // Exibição de informações
    printf("Informações do aluno 101:\n");
    printf("Nome: %s\n", a1->nome);
    printf("Matrícula: %d\n", a1->matricula);
    printf("Disciplinas:\n");
    for (int i = 0; i < a1->num_disciplinas; i++) {
        printf("%d - %s\n", a1->disciplinas[i]->codigo, a1->disciplinas[i]->nome);
    }

    printf("\nInformações do aluno 102:\n");
    printf("Nome: %s\n", a2->nome);
    printf("Matrícula: %d\n", a2->matricula);
    printf("Disciplinas:\n");
    for (int i = 0; i < a2->num_disciplinas; i++) {
        printf("%d - %s\n", a2->disciplinas[i]->codigo, a2->disciplinas[i]->nome);
    }

    // Liberação
    exclui_aluno(a1);
    exclui_aluno(a2);
    exclui_disciplina(d1);
    exclui_disciplina(d2);
    exclui_disciplina(d3);

    return 0;
}
