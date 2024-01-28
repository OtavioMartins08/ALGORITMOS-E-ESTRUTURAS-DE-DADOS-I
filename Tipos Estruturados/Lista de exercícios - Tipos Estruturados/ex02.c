/*
Questão 2) Escreva um programa em C que manipula dados de um conjunto de alunos da disciplina de Estrutura de
Dados e Programação da UFERSA Pau dos Ferros. Para representar um aluno são necessárias as seguintes
informações: matrícula (inteiro), nome (80 caracteres), turma (caractere), três notas (reais em um vetor) e uma
média (real). Seu programa deve levar em consideração que é ofertado um número máximo de vagas para a
disciplina. Sabendo dessas informações, faça o que se pede nos itens a seguir:

a) Implemente uma função que recebe os dados de um aluno e o matricula na disciplina, caso haja vaga
disponível. Protótipo: void matricula(int n,Aluno** alunos);

b) Implemente uma função que lança as notas e calcula a média dos alunos da disciplina. Protótipo: void
lanca_notas(int n, Aluno** alunos);

c) Implemente uma função que imprime os dados de todos os alunos da disciplina. Protótipo: void
imprime_tudo(int n, Aluno** alunos);

d) Implemente uma função que imprime os dados de todos os alunos de uma turma. Protótipo: void
imprime_turma(int n, Aluno** alunos, char turma);

e) Implemente uma função que imprime os alunos aprovados de uma determinada turma. Para ser
aprovado, o aluno deve ter média maior que ou igual a 7,0. Protótipo: void imprime_turma_aprovados(int n,
Aluno**alunos, char turma);

Sugestões: i) Use um vetor de ponteiros para estrutura; ii) Use uma constante simbólica para representar o número 
máximo de alunos. Iii) Antes de manipular o vetor de ponteiros, inicialize cada um de seus elementos com NULL 
(você pode escrever uma função para isso).

OBS.: Os exercícios apresentados sugerem a implementação de diferentes funções. Sendo assim, o programador
deve escrever um programa (função main) para testar sua implementação.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 50
#define MAX_NOME 80

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char turma;
    float notas[3];
    float media;
} Aluno;

void inicializa_alunos(Aluno **alunos) {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        alunos[i] = NULL;
    }
}

void matricula(int n, Aluno **alunos) {
    if (n < MAX_ALUNOS) {
        alunos[n] = (Aluno *)malloc(sizeof(Aluno));

        if (alunos[n] != NULL) {
            printf("Digite a matrícula do aluno: ");
            scanf("%d", &alunos[n]->matricula);

            printf("Digite o nome do aluno: ");
            scanf(" %[^\n]s", alunos[n]->nome);

            printf("Digite a turma do aluno: ");
            scanf(" %c", &alunos[n]->turma);

            for (int i = 0; i < 3; i++) {
                printf("Digite a nota %d do aluno: ", i + 1);
                scanf("%f", &alunos[n]->notas[i]);
            }

            alunos[n]->media = 0.0;
        } else {
            printf("Erro ao alocar memória para o aluno.\n");
        }
    } else {
        printf("Número máximo de alunos atingido.\n");
    }
}

void lanca_notas(int n, Aluno **alunos) {
    for (int i = 0; i < n; i++) {
        float soma = 0.0;

        for (int j = 0; j < 3; j++) {
            soma += alunos[i]->notas[j];
        }

        alunos[i]->media = soma / 3;
    }
}

void imprime_tudo(int n, Aluno **alunos) {
    for (int i = 0; i < n; i++) {
        printf("Matrícula: %d\n", alunos[i]->matricula);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Turma: %c\n", alunos[i]->turma);
        printf("Notas: %.2f, %.2f, %.2f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
        printf("Média: %.2f\n", alunos[i]->media);
        printf("\n");
    }
}

void imprime_turma(int n, Aluno **alunos, char turma) {
    for (int i = 0; i < n; i++) {
        if (alunos[i]->turma == turma) {
            printf("Matrícula: %d\n", alunos[i]->matricula);
            printf("Nome: %s\n", alunos[i]->nome);
            printf("Turma: %c\n", alunos[i]->turma);
            printf("Notas: %.2f, %.2f, %.2f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
            printf("Média: %.2f\n", alunos[i]->media);
            printf("\n");
        }
    }
}

void imprime_turma_aprovados(int n, Aluno **alunos, char turma) {
    printf("Alunos aprovados na turma %c:\n", turma);

    for (int i = 0; i < n; i++) {
        if (alunos[i]->turma == turma && alunos[i]->media >= 7.0) {
            printf("%s\n", alunos[i]->nome);
        }
    }
}

int main(void) {
    Aluno *alunos[MAX_ALUNOS];

    inicializa_alunos(alunos);

    int opcao, num_alunos = 0;
    char turma;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Matricular aluno\n");
        printf("2. Lancar notas e calcular medias\n");
        printf("3. Imprimir dados de todos os alunos\n");
        printf("4. Imprimir dados de uma turma\n");
        printf("5. Imprimir alunos aprovados de uma turma\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                matricula(num_alunos, alunos);
                num_alunos++;
                break;
            case 2:
                lanca_notas(num_alunos, alunos);
                printf("Notas lançadas e médias calculadas.\n");
                break
;
            case 3:
                imprime_tudo(num_alunos, alunos);
                break;
            case 4:
                printf("Digite a turma: ");
                scanf(" %c", &turma);
                imprime_turma(num_alunos, alunos, turma);
                break;
            case 5:
                printf("Digite a turma: ");
                scanf(" %c", &turma);
                imprime_turma_aprovados(num_alunos, alunos, turma);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    for (int i = 0; i < num_alunos; i++) {
        free(alunos[i]);
    }

    return 0;
}
