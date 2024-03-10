/*
2. Implemente um programa em C para ler o nome e as notas de um número N de alunos e armazená-los
em um arquivo.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
FILE *arquivo = fopen("notas.txt", "w");

if (arquivo == NULL) {
  printf("Erro ao abrir o arquivo!\n");
  return 1;
}

int N;
printf("Digite o número de alunos: ");
scanf("%d", &N);

char nome[50];
float nota1, nota2, nota3;

for (int i = 0; i < N; i++) {
  printf("\nNome do aluno %d: ", i + 1);
  scanf("%s", nome);
  printf("Primeira nota do aluno %dº: ", i + 1);
  scanf("%f", &nota1);
  printf("Segunda nota do aluno %dº: ", i + 1);
  scanf("%f", &nota2);
  printf("Terceira nota do aluno %dº: ", i + 1);
  scanf("%f", &nota3);

  fprintf(arquivo, "%s %.2f %.2f %.2f\n", nome, nota1, nota2, nota3);
}

fclose(arquivo);

printf("\nNotas dos alunos gravadas com sucesso no arquivo 'notas.txt'!\n");

return 0;
}