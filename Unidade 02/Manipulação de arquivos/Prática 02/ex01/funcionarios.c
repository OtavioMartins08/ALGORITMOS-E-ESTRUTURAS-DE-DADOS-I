/*
1. Faça um programa em C que solicita ao usu´ario informações de funcionários via teclado. As informações digitadas pelo o usuário são: id, nome e salário do funcionários. Armazene as informações
digitadas pelo usuário em um arquivo texto.
*/

#include <stdio.h>

int main() {
 FILE *arquivo = fopen("funcionarios.txt", "w");

 if (arquivo == NULL) {
   printf("Erro ao abrir o arquivo!\n");
   return 1;
 }

 int id;
 char nome[50];
 float salario;
 int qnt;
printf("Digite a quantidade de funcionários que deseja cadastrar: ");
scanf(" %d", &qnt);

printf("Digite as informações dos funcionários:\n");

 for (int i = 0; i < qnt; i++) {
   printf("\nId do funcionário %dº: ", i + 1);
   scanf("%d", &id);
   printf("Nome do funcionário %dº: ", i + 1);
   scanf("%s", nome);
   printf("Salário do funcionário %dº: ", i + 1);
   scanf("%f", &salario);

   fprintf(arquivo, "%d %s %.2f\n", id, nome, salario);
 }

 fclose(arquivo);

 printf("\nInformações dos funcionários gravadas com sucesso no arquivo 'funcionarios.txt'!\n");

 return 0;
}