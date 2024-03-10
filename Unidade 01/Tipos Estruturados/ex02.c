/*
2. Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os
seguintes campos: nome da pessoa, numero do documento e idade.

a) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Pessoa e
preencha seus campos com valores fornecidos pelo usu´ario via teclado.

b) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Pessoa e
imprima os valores dos seus campos.

c) Implemente uma fun¸c˜ao para realizar uma atualiza¸c˜ao da idade de uma estrutura do tipo Pessoa.

d) Escreva uma fun¸c˜ao que receba como parˆametro um vetor de estruturas do tipo Pessoa e imprima
o nome da Pessoa mais velha e mais nova. */

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    MASCULINO,
    FEMININO
} Genero;

struct Pessoa {
    char nome[40];
    double numeroDocumento;
    int idade;
    Genero genero;
};

void receberDados(struct Pessoa *pessoa) {
    printf("Nome: ");
    scanf(" %[^\n]", pessoa->nome);

    printf("Número do documento: ");
    scanf("%lf", &pessoa->numeroDocumento);

    printf("Idade: ");
    scanf("%d", &pessoa->idade);

    printf("Gênero (0 para Masculino, 1 para Feminino): ");
    scanf("%d", (int *)&pessoa->genero);
}

void imprimirDados(struct Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Número do documento: %.0lf\n", pessoa->numeroDocumento);
    printf("Idade: %d\n", pessoa->idade);

    printf("Gênero: %s\n", pessoa->genero == MASCULINO ? "Masculino" : "Feminino");
}

int main() {
    int numPessoas;
    printf("Quantidade de pessoas: ");
    scanf("%d", &numPessoas);

    struct Pessoa *pessoa = (struct Pessoa *)malloc(numPessoas * sizeof(struct Pessoa));
    if (pessoa == NULL) {
        printf("Erro na alocação de memória");
        exit(1);
    }

    for (int i = 0; i < numPessoas; i++) {
        printf("Dados da pessoa %d\n", i + 1);
        receberDados(&pessoa[i]);
    }

    for (int i = 0; i < numPessoas; i++) {
        printf("Dados da pessoa %d\n", i + 1);
        imprimirDados(&pessoa[i]);
    }

    free(pessoa);

    return 0;
}
