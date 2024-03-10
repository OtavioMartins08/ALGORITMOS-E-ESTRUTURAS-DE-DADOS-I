#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

int main() {
  ContaBancaria *conta1 = criaContaBancaria("João da Silva", 123456, 1000.0);
  ContaBancaria *conta2 = criaContaBancaria("Maria Souza", 654321, 500.0);

  deposita(conta1, 200.0);
  saca(conta1, 300.0);
  transfere(conta1, conta2, 150.0);

  printf("Saldo de conta 1: %.2f\n", saldo(conta1));
  printf("Saldo de conta 2: %.2f\n", saldo(conta2));

  excluiContaBancaria(conta1);
  excluiContaBancaria(conta2);

  return 0;
}