/*
Questão 1) Crie um tipo estruturado para armazenar dados de um ingresso. Uma estrutura deste tipo possui os
seguintes campos: preço, local e atração.

a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e
preencha seus campos com valores fornecidos pelo usuário via teclado. Protótipo: void
preenche(Ingresso* i);

b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e imprima
os valores dos seus campos. Protótipo: void imprime(Ingresso* i); 

c) Escreva uma função que receba, como parâmetros, o endereço de uma estrutura do tipo Ingresso e um
novo valor de preço e atualize o preço do ingresso para o novo valor. Protótipo: void
altera_preco(Ingresso* i, float valor);

d) Escreva uma função que receba, como parâmetros, um vetor de ingressos e o tamanho do vetor e
imprima os eventos de ingresso mais barato e mais caro. Protótipo: void imprime_menor_maior_preco(int
n, Ingresso* vet);

e) Escreva uma função main para testar as funções anteriores
*/

#include <stdio.h>

typedef struct Ingresso {
    float preco;
    char local[50];
    char atracao[50];
} Ingresso;

void preenche(Ingresso* i) {
    printf("Digite o preço do ingresso: ");
    scanf("%f", &i->preco);

    printf("Digite o local do evento: ");
    scanf(" %[^\n]", i->local);

    printf("Digite a atracao do evento: ");
    scanf(" %[^\n]", i->atracao);
}

void imprime(Ingresso* i) {
    printf("Preço: %.2f\n", i->preco);
    printf("Local: %s\n", i->local);
    printf("Atração: %s\n", i->atracao);
}

void altera_preco(Ingresso* i, float valor) {
    i->preco = valor;
}

void imprime_menor_maior_preco(int n, Ingresso* vet) {
    if (n <= 0) {
        printf("Vetor invalido.\n");
        return;
    }

    Ingresso menor = vet[0];
    Ingresso maior = vet[0];

    for (int i = 1; i < n; i++) {
        if (vet[i].preco < menor.preco) {
            menor = vet[i];
        }
        if (vet[i].preco > maior.preco) {
            maior = vet[i];
        }
    }

    printf("Evento mais barato:\n");
    imprime(&menor);

    printf("\nEvento mais caro:\n");
    imprime(&maior);
}

int main() {
    int tamanho;

    printf("Digite o tamanho do vetor de ingressos: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    Ingresso* vetor = (Ingresso*)malloc(tamanho * sizeof(Ingresso));
    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("\nIngresso %d:\n", i + 1);
        preenche(&vetor[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        printf("\nIngresso %d:\n", i + 1);
        imprime(&vetor[i]);
    }

    float novo_preco;
    printf("\nDigite o novo preco para o primeiro ingresso: ");
    scanf("%f", &novo_preco);

    altera_preco(&vetor[0], novo_preco);

    printf("\nIngresso 1 apos alteracao de preco:\n");
    imprime(&vetor[0]);

    imprime_menor_maior_preco(tamanho, vetor);

    free(vetor);

    return 0;
}
