/*
Questão 2) Escreva um programa que aloque dinamicamente uma matriz de inteiros definida pelo o usuário. Em seguida, implemente uma
função que receba um valor, retorne 1, caso esteja na matriz ou retorne 0 caso não esteja. Dica: implemente uma função que faz essa
verificaçã.
*/

#include <stdio.h>
#include <stdlib.h>

int valorEstaNaMatriz(int **matriz, int linhas, int colunas, int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                return 1; 
            }
        }
    }
    return 0; 
}

int **alocaMatriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void liberaMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int linhas, colunas, valorBusca;

    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);

    int **matriz = alocaMatriz(linhas, colunas);

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite o valor a ser buscado na matriz: ");
    scanf("%d", &valorBusca);

    if (valorEstaNaMatriz(matriz, linhas, colunas, valorBusca)) {
        printf("O valor %d está na matriz.\n", valorBusca);
    } else {
        printf("O valor %d não está na matriz.\n", valorBusca);
    }

    liberaMatriz(matriz, linhas);

    return 0;
}
