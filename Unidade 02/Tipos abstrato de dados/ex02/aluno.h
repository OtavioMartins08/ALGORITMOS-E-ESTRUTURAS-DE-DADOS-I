#include "disciplina.h"

// Definição da estrutura Aluno
typedef struct Aluno {
    char nome[100];
    int matricula;
    Disciplina* disciplinas[7];
    int num_disciplinas;
} Aluno;

// Declarações das funções relacionadas a Aluno
Aluno* cria_aluno(char nome[], int matricula);
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);
void exclui_aluno(Aluno* aluno);