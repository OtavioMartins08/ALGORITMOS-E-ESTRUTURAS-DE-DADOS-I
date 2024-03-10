//Exemplo feito em aula.

#include <stdio.h>
#include <stdlib.h>

int main (void){
    int*vetor = malloc(3*sizeof(int));
    if (vetor == NULL){
        printf("Erro na alocação de memoria");
        exit(1);
    }
    free (vetor);
    return 0;
}