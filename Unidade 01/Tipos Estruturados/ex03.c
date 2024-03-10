/*
3. Escreva um programa que implementa uma struct Data com os campos dia, mˆes e ano. O mˆes deve
ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARC¸ O, ABRIL, MAIO,
JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
deve ler a data e imprimir a data no formato dd/mm/aaaa.
*/

#include <stdio.h>

typedef enum meses {
    JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO
} Mes;

typedef struct data {
    int dia;
    Mes mes;
    int ano;
} Data;

void imprimirData(Data *data) {
    printf("%02d/%02d/%04d\n", data->dia, data->mes, data->ano);
}

int main() {
    Data data;

    printf("Digite o dia: ");
    scanf("%d", &data.dia);

    printf("Digite o mes (1-12): ");
    scanf("%d", &data.mes);

    printf("Digite o ano: ");
    scanf("%d", &data.ano);

    if (data.mes < JANEIRO || data.mes > DEZEMBRO) {
        printf("Mes invalido.\n");
        return 1;
    }

    printf("\nData informada: ");
    imprimirData(&data);

    return 0;
}
