//03. Identifique os erros de compilaçao que seriam detectados no seguinte programa se eles existirem:

#include <stdio.h>

int main() {
    int N_ant, N_prox, N, N_atual //Falta ponto e vírgula no final da linha
    N_ant = N_atual = 1;

    //Falta declaração do tipo de i (int i)
    for (i = 1, i <= N, i++) { //Falta ponto e vírgula no final da linha
        N_prox = N_ant + N_atual;
        N_ant = N_atual;
        N_atual = N_prox;
    }

    printf("Fim do laco!\n");
    return;  //Falta valor de retorno (deve ser return 0;)
}
