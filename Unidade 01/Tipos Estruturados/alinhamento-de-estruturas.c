#include <stdio.h>
#include <stdlib.h>

    typedef struct disciplina{
        char nome[20];
        float nota;
        int codigo;
    }Disciplina;
    typedef struct aluno{
        char nome[20];
        int idade;
        int matricula;
        Disciplina materias[7]; 
    }Aluno;

    int main(void) {

        Aluno aluno; 
        aluno.idade = 19; 
        aluno.matricula = 20233;
        aluno.materias[0].codigo= 98070;
        printf("%d, %d, %d \n", aluno.idade, aluno.matricula, aluno.materias->codigo);

    return 0;
}