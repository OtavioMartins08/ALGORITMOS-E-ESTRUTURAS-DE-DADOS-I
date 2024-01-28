//04. Escreva uma funcao que receba dois numeros positivos por parametro e retorne a soma dos N numeros
//inteiros existentes entre eles.

#include <stdio.h>

int somaEntreNumeros(int inicio, int fim) {
    int soma = 0;

    if (inicio > fim) {
        int temp = inicio;
        inicio = fim;
        fim = temp;
    }

    for (int i = inicio; i <= fim; i++) {
        soma += i;
    }

    return soma;
}

int main() {
    int num1 = 1;
    int num2 = 10;

    int resultado = somaEntreNumeros(num1, num2);

    printf("%d",resultado);

    return 0;
}
