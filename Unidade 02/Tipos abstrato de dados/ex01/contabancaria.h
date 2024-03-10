typedef struct ContaBancaria ContaBancaria;

ContaBancaria *criaContaBancaria(char *titular, int numero, float saldo);
void deposita(ContaBancaria *conta, float valor);
int saca(ContaBancaria *conta, float valor);
int transfere(ContaBancaria *contaOrigem, ContaBancaria *contaDestino, float valor);
float saldo(ContaBancaria *conta);
void excluiContaBancaria(ContaBancaria *conta);
