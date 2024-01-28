/*
Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
produto (gostou/não gostou). Escreva um programa em C que:

a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
para a segunda pergunta.

b) determine a porcentagem de pessoas do sexo feminino que responderam que
gostaram do produto.

c) determine a porcentagem de pessoas do sexo masculino que responderam que não
gostaram do produto. 
*/

#include <stdio.h>

int main() {
    int N;
    printf("Informe o numero de pessoas a serem entrevistadas: ");
    scanf("%d", &N);
    if (N <= 0) {
        printf("O numero de pessoas deve ser maior que zero.\n");
        return 1;  
    }
    char sexo[N];
    char opiniao[N];
    for (int i = 0; i < N; i++) {
        printf("Informe o sexo da pessoa %d (M/F): ", i + 1);
        scanf(" %c", &sexo[i]);
        printf("Informe a opiniao da pessoa %d sobre o produto (gostou/nao gostou): ", i + 1);
        if ((sexo[i] != 'M' && sexo[i] != 'F') || (opiniao[i] != 'g' && opiniao[i] != 'n')) {
            printf("Respostas invalidas. Por favor, informe M ou F para o sexo e gostou/nao gostou para a opiniao.\n");
            return 1;  
        }
    }
    int mulheresGostaram = 0;
    for (int i = 0; i < N; i++) {
        if (sexo[i] == 'F' && opiniao[i] == 'g') {
            mulheresGostaram++;
        }
    }
    float porcentagemMulheresGostaram = (float)mulheresGostaram / N * 100;

    printf("Porcentagem de mulheres que gostaram do produto: %.2f%%\n", porcentagemMulheresGostaram);
    int homensNaoGostaram = 0;
    for (int i = 0; i < N; i++) {
        if (sexo[i] == 'M' && opiniao[i] == 'n') {
            homensNaoGostaram++;
        }
    }
    float porcentagemHomensNaoGostaram = (float)homensNaoGostaram / N * 100;
    printf("Porcentagem de homens que nao gostaram do produto: %.2f%%\n", porcentagemHomensNaoGostaram);

    return 0;  
}
