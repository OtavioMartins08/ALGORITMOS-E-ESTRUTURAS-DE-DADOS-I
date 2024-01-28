/*
1. Crie um tipo estruturado para armazenar dados de um funcionario. Uma estrutura deste tipo possui
os seguintes campos: nome, salario, identificador e cargo.

a) Escreva uma funcao que receba como parˆametro o endere¸co de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usu´ario via teclado.

b) Escreva uma funcao que receba como parametro o endereco de uma estrutura do tipo Funcionario
e imprima os valores dos seus campos.

c) Implemente uma funcao para realizar uma alteracao no salario de uma estrutura do tipo Funcionario.

d) Escreva uma funcao que receba como parametro um vetor de estruturas do tipo Funcionario e
imprima o cargo e salario do Funcionario com maior salario e o cargo e salario do funcionario
com o menor salario. 
*/

#include <stdio.h>
#include <stdlib.h>

struct Funcionario {
    char nome[40];
    float salario;
    int identificador;
    char cargo[25];
};
void receberDados(struct Funcionario *funcionario) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", funcionario->nome);
    printf("Digite o salario: ");
    scanf("%f", &funcionario->salario);
    printf("Digite o identificador: ");
    scanf("%d", &funcionario->identificador);
    printf("Digite o cargo: ");
    scanf(" %[^\n]", funcionario->cargo);
}
void imprimirDados(struct Funcionario *funcionario) {
    printf("Nome: %s\n", funcionario->nome);
    printf("Salario: %.2f\n", funcionario->salario);
    printf("Identificador: %d\n", funcionario->identificador);
    printf("Cargo: %s\n", funcionario->cargo);
}
void alterarSalario(struct Funcionario *funcionario, float novoSalario) {
    funcionario->salario = novoSalario;
}
void imprimirMaiorMenorSalario(struct Funcionario *funcionarios, int numFuncionarios) {
    if (numFuncionarios <= 0) {
        printf("Sem funcionario para avaliar.\n");
        return;
    }

    int indiceMaiorSalario = 0;
    int indiceMenorSalario = 0;

    for (int i = 1; i < numFuncionarios; i++) {
        if (funcionarios[i].salario > funcionarios[indiceMaiorSalario].salario) {
            indiceMaiorSalario = i;
        }

        if (funcionarios[i].salario < funcionarios[indiceMenorSalario].salario) {
            indiceMenorSalario = i;
        }
    }

    printf("Funcionario com maior salario:\n");
    printf("Cargo: %s\n", funcionarios[indiceMaiorSalario].cargo);
    printf("Salario: %.2f\n", funcionarios[indiceMaiorSalario].salario);

    printf("\nFuncionario com menor salario:\n");
    printf("Cargo: %s\n", funcionarios[indiceMenorSalario].cargo);
    printf("Salario: %.2f\n", funcionarios[indiceMenorSalario].salario);
}
int main() {
    int numFuncionarios;

    printf("Digite o numero de funcionarios: ");
    scanf("%d", &numFuncionarios);
    struct Funcionario *funcionarios = (struct Funcionario *)malloc(numFuncionarios * sizeof(struct Funcionario));
    if (funcionarios == NULL) {
        printf("Erro ao alocar memória");
        return 1;
    }
    for (int i = 0; i < numFuncionarios; i++) {
        printf("\nDados do Funcionario %d:\n", i + 1);
        receberDados(&funcionarios[i]);
    }
    printf("\nImprimindo dados dos funcionarios:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("\nDados do Funcionario %d:\n", i + 1);
        imprimirDados(&funcionarios[i]);
    }
    printf("\nDados do primeiro funcionario apos alteracao de salario:\n");
    imprimirDados(&funcionarios[0]);
    imprimirMaiorMenorSalario(funcionarios, numFuncionarios);

    free(funcionarios);

    return 0;
}
