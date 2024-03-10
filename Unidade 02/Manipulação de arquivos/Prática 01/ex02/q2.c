/*
Questão 2) Escreva um programa em C que preencha um vetor de 10 inteiros com informações
vindas de um arquivo e escreva em outro arquivo o menor elemento, o maior elemento, bem
como a média dos elementos do vetor.
*/

#include <stdio.h>
#include <limits.h>

int main() {
  FILE *entrada = fopen("entrada_q2.txt", "r");
  FILE *saida = fopen("saida_q2.txt", "w");

  if (entrada == NULL || saida == NULL) {
    printf("Erro ao abrir os arquivos!");
    return 1;
  }

  int vetor[10];
  int i = 0;
  int menor, maior, soma;

  while (fscanf(entrada, "%d", &vetor[i]) != EOF && i < 10) {
    i++;
  }

  if (i == 0) {
    printf("Erro: o arquivo de entrada não contém dados válidos!\n");
    return 1;
  }

  menor = vetor[0];
  maior = vetor[0];
  soma = 0;

  for (int j = 0; j < 10; j++) {
    if (vetor[j] < menor) {
      menor = vetor[j];
    }
    if (vetor[j] > maior) {
      maior = vetor[j];
    }
    soma += vetor[j];
  }

  float media = soma / 10.0;

  fprintf(saida, "menor elemento: %d\nmaior elemento: %d\nmedia doslementos: %.2f\n", menor, maior, media);

fclose(entrada); 
fclose(saida);

return 0; }

