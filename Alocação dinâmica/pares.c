/*
Questão 1) Implemente uma função que receba como parâmetro um vetor de números
inteiros (vet) de tamanho n e retorne quantos números pares estão armazenados
nesse vetor. Essa função deve obedecer ao protótipo: int pares(int n, int* vet);
*/

#include <stdio.h>

int pares(int n, int *vet) {
    int countPares = 0;

    for (int i = 0; i < n; i++) {
        if (vet[i] % 2 == 0) {
            countPares++;
        }
    }

    return countPares;
}

int main() {
    int tamanho = 6;
    int vetor[] = {1, 2, 3, 4, 5, 6};

    int quantidadePares = pares(tamanho, vetor);

    printf("Quantidade de numeros pares: %d\n", quantidadePares);

    return 0;
}
