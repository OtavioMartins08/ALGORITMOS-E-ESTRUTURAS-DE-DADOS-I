/*
Questão 3) Implemente uma função que preencha um vetor de N elementos com valores inteiros fornecidos via teclado, de modo que,
à medida que um novo elemento é inserido, o vetor já permaneça organizado de maneira ordenada crescente. Escreva um programa
que utiliza esta função, que deve obedecer ao seguinte protótipo: void preenche_ordenado(int n, int* vet);
*/

#include <stdio.h>

void preenche_ordenado(int n, int *vet) {
    int valor;
    printf("Digite os elementos do vetor de forma ordenada crescente:\n");

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);

        int j = i;
        while (j > 0 && vet[j - 1] > valor) {
            vet[j] = vet[j - 1];
            j--;
        }

        vet[j] = valor;
    }
}

int main() {
    int N;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int *vetor = (int *)malloc(N * sizeof(int));

    if (vetor == NULL) {
        printf("Erro na alocação de memoria.\n");
        return 1;
    }

    preenche_ordenado(N, vetor);

    printf("\nVetor preenchido de forma ordenada crescente:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}
