/*
Crie um tipo estruturado para representar uma conta bancária, cujos campos são: o nome do cliente, o número 
da conta e um saldo. Crie uma variável do tipo estrutura e escreva instruções para inicializar seus campos. Em seguida,
implementeuma função para realizar um depósito em uma estrutura do tipo struct contaBancaria. Sua função deve obedecer ao
seguinte protótipo: void deposita(float valor, struct contaBancaria* conta);
*/

#include <stdio.h>

struct ContaBancaria {
    char nomeCliente[50];
    int numeroConta;
    float saldo;
};

void deposita(float valor, struct ContaBancaria *conta) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Deposito de %.2f realizado com sucesso. Novo saldo: %.2f\n", valor, conta->saldo);
    } else {
        printf("Valor invalido para deposito.\n");
    }
}

int main() {
    struct ContaBancaria minhaConta;
    printf("Informe o nome do cliente: ");
    scanf("%s", minhaConta.nomeCliente);

    printf("Informe o numero da conta: ");
    scanf("%d", &minhaConta.numeroConta);

    printf("Informe o saldo inicial: ");
    scanf("%f", &minhaConta.saldo);

    float valorDeposito;
    printf("Digite o valor do deposito: ");
    scanf("%f", &valorDeposito);

    deposita(valorDeposito, &minhaConta);

    return 0;
}
