/*Questão 2) Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
10 alunos matriculados. Calcule e mostre:

a) a nota obtida para cada aluno;

b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6. */

#include <stdio.h>

int main() {
    int num_questoes;
    char gabarito[100];
    float notas[10];
    float nota_minima = 6.0;
    int alunos_aprovados = 0;
    printf("Informe o numero de questoes: ");
    scanf("%d", &num_questoes);
    printf("Informe o gabarito da prova (sem espacos): ");
    scanf("%s", gabarito);
    for (int i = 0; i < 10; i++) {
        char respostas_aluno[100];
        printf("Informe as respostas do aluno %d (sem espacos): ", i + 1);
        scanf("%s", respostas_aluno);
        float nota = 0.0;
        for (int i_questao = 0; i_questao < num_questoes; i_questao++) {
            if (respostas_aluno[i_questao] == gabarito[i_questao]) {
                nota += 10.0 / num_questoes;
            }
        }
        notas[i] = nota;
        if (nota >= nota_minima) {
            alunos_aprovados++;
        }
    }
    printf("\nResultados:\n");
    for (int i = 0; i < 10; i++) {
        printf("Aluno %d: Nota %.2f\n", i + 1, notas[i]);
    }
    float porcentagem_aprovacao = (float)alunos_aprovados / 10 * 100;
    printf("\nPorcentagem de aprovacao: %.2f%%\n", porcentagem_aprovacao);

    return 0;
}
