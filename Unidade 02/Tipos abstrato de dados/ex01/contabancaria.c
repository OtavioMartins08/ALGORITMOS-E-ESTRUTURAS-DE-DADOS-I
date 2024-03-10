#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

struct ContaBancaria {
char titular[50];
int numero;
float saldo;
};

ContaBancaria *criaContaBancaria(char *titular, int numero, float saldo) {
ContaBancaria *conta = (ContaBancaria *) malloc(sizeof(ContaBancaria));
for (int i = 0; i < sizeof(conta->titular) && titular[i] != '\0'; i++) {
 conta->titular[i] = titular[i];
}
conta->titular[sizeof(conta->titular) - 1] = '\0';
conta->numero = numero;
conta->saldo = saldo;
return conta;
}

void deposita(ContaBancaria *conta, float valor) {
conta->saldo += valor;
}

int saca(ContaBancaria *conta, float valor) {
if (conta->saldo >= valor) {
 conta->saldo -= valor;
 return 1;
}
return 0;
}

int transfere(ContaBancaria *contaOrigem, ContaBancaria *contaDestino, float valor) {
if (saca(contaOrigem, valor)) {
 deposita(contaDestino, valor);
 return 1;
}
return 0;
}

float saldo(ContaBancaria *conta) {
return conta->saldo;
}

void excluiContaBancaria(ContaBancaria *conta) {
free(conta);
}