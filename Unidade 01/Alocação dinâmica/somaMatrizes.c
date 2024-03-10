/*
Questão 1) Escreva um programa que calcula a soma de duas matrizes MxN, considerando matrizes quadradas. As dimensões deve ser
fornecidas pelo o usuário. Use alocação dinâmica e escreva uma função que somará as matrizes;
*/

#include <stdio.h>
#include <stdlib.h>

void somaMatrizes(int **matriz1, int **matriz2, int **resultado, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void imprimeMatriz(int **matriz, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int M, N;

    printf("Digite o numero de linhas (M) e colunas (N) das matrizes quadradas: ");
    scanf("%d %d", &M, &N);

    int **matriz1 = (int **)malloc(M * sizeof(int *));
    int **matriz2 = (int **)malloc(M * sizeof(int *));
    int **resultado = (int **)malloc(M * sizeof(int *));

    for (int i = 0; i < M; i++) {
        matriz1[i] = (int *)malloc(N * sizeof(int));
        matriz2[i] = (int *)malloc(N * sizeof(int));
        resultado[i] = (int *)malloc(N * sizeof(int));
    }

    // Leitura das matrizes
    printf("Digite os numeros da primeira matriz:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os numeros da segunda matriz:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    somaMatrizes(matriz1, matriz2, resultado, M, N);

    printf("\nMatriz 1:\n");
    imprimeMatriz(matriz1, M, N);

    printf("\nMatriz 2:\n");
    imprimeMatriz(matriz2, M, N);

    printf("\nResultado da soma:\n");
    imprimeMatriz(resultado, M, N);

    for (int i = 0; i < M; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(resultado[i]);
    }

    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0;
}
