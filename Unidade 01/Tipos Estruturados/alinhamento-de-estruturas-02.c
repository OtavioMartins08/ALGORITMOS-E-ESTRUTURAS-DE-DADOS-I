#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina {
    char nome[20];
    float nota;
    int codigo;
} Disciplina;

typedef struct aluno {
    char nome[20];
    int idade;
    int matricula;
    Disciplina *materias; 
} Aluno;

int main(void) {
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno == NULL) {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    aluno->materias = (Disciplina *)malloc(2 * sizeof(Disciplina));
    if (aluno->materias == NULL) {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    printf("Informe os dados do aluno: nome, idade e matricula\n");
    scanf(" %[^\n]", aluno->nome);
    scanf("%d %d", &aluno->idade, &aluno->matricula);

    for (int index = 0; index < 2; index++) {
        printf("Cadastro da Disciplina %dº: nome, codigo e nota\n", index + 1);
        scanf(" %[^\n]", aluno->materias[index].nome);
        scanf("%d", &aluno->materias[index].codigo);
        scanf("%f", &aluno->materias[index].nota);
    }

    free(aluno->materias);
    free(aluno);

    return 0;
}
