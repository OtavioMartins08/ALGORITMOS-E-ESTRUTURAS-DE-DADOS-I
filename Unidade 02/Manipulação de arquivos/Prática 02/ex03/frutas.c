#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
 char nome[50];
 float preco;
} Fruta;

int main() {
 FILE *arquivo = fopen("frutas.txt", "w");

 if (arquivo == NULL) {
   printf("Erro ao abrir o arquivo!\n");
   return 1;
 }

 Fruta fruta;
 char resposta;

 do {
   printf("\nNome da fruta: ");
   scanf("%s", fruta.nome);

   printf("Preço da fruta: ");
   scanf("%f", &fruta.preco);

   fprintf(arquivo, "%s,%.2f\n", fruta.nome, fruta.preco);

   printf("\nDeseja cadastrar outra fruta? (s/n): ");
   scanf(" %c", &resposta);
 } while (resposta == 's' || resposta == 'S');

 fclose(arquivo);

 printf("\nCadastro de frutas encerrado. Informações gravadas com sucesso no arquivo 'frutas.txt'!\n");

 return 0;
}