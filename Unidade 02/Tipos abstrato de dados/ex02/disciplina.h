#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct Disciplina {
    int codigo;
    char nome[100];
} Disciplina;

Disciplina* cria_disciplina(char nome[], int codigo);
void exclui_disciplina(Disciplina* disciplina);

#endif
