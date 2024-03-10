/*
Questão 1) Escreva um programa em C que leia de um arquivo as notas dos alunos de uma
turma e escreva em outro arquivo o nome e a média de cada aluno, bem como a sua situação
(aprovado (média >= 7.0) ou reprovado). Tanto no arquivo de entrada quanto no de saída,
considere que os dados em cada linha estão separados por um caractere de tabulação ‘\t’. Para a
execução do programa com o arquivo de entrada “entrada_q3.txt”, deverá ser criado o arquivo
de saída “saída_q3.txt”.
*/

#include <stdio.h>

int main() {
  FILE *entrada = fopen("entrada_q3.txt", "r");
  FILE *saida = fopen("saida_q3.txt", "w");

  if (entrada == NULL || saida == NULL) {
    printf("Erro ao abrir os arquivos!");
    return 1;
  }

  char nome[50];
  float nota1, nota2, nota3;
  while (fscanf(entrada, "%s\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3) != EOF) {
    fprintf(saida, "%s\t%.2f\t%s\n", nome, (nota1 + nota2 + nota3) / 3,
            ((nota1 + nota2 + nota3) / 3 >= 7.0) ? "Aprovado" : "Reprovado");
  }

  fclose(entrada);
  fclose(saida);

  return 0;
}