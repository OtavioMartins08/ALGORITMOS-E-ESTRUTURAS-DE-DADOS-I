#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar um documento por vez
typedef union documentos{
    char rg[15];
    char cpf[15];
}Documentos;

typedef struct pessoa{
    char nome[20];
    int idade;
    Documentos doc; //Variável para armazenar o CPF ou RG
}Pessoa;

void dados_pessoa (Pessoa * p){
    /*Função que preenche os dados de uma variável
    do tipo Pessoa (struct) */
    int opcao;
    printf("Informe o nome: \t");
    scanf("%[^\n], p->nome");
    printf("\nInforme a idade: \t");
    scanf("%d", &p->idade);
    printf("Digite 1 para CPF ou 2 para RG");
    scanf("%d",&opcao);
    if(opcao){
        scanf("%[^\n]", p->doc.cpf);
    }
    else{
        scanf("%[^\n]", p->doc.rg);
    }
}

int main(void){
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    dados_pessoa(pessoa); //a função recebe o endereço da variável
    printf("CPF = %s \n RG+%s", pessoa->doc.cpf, pessoa->doc.rg);
    free(pessoa);
    
    return 0;
}