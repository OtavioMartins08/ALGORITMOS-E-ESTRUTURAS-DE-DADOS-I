#include <stdlib.h>
#include <stdio.h>

int main(){
        int *ponteiroVetor= malloc(3*sizeof(int)); 
        int *ponteiro2Vetor= (int *) malloc(3*sizeof(int)); 
        if(ponteiroVetor==NULL){
            printf("ERRO na alocacao de memoria");
            exit(1);
        }
        scanf("%d",&ponteiroVetor+2); 
        scanf("%d",&ponteiroVetor[2]);
        printf("%d\n\n",ponteiroVetor[2]); 
        printf("%d\n\n",*(ponteiroVetor+2));
        ponteiroVetor=(int *) realloc(ponteiroVetor, 5 *sizeof(int));
        scanf("%d",ponteiroVetor+4);
        printf("%d \n", *(ponteiroVetor+4));
        int linhas=5,coluna=3,i;
        int *matriz= (int *) malloc(linhas*sizeof(int *));
        for(i=0;i<linhas;i++){
            matriz[i]=(int *)malloc(coluna*sizeof(int));
        }
        for(i=0;i<linhas;i++){
            free(matriz[i]);
        }
        free(matriz);
        free(ponteiroVetor);

    return 0;
}