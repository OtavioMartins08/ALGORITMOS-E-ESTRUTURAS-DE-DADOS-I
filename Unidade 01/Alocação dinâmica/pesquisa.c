/*
Questão 2) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um novo produto. Um número N de pessoas de
ambos os sexos foi entrevistado, e o questionário consistia em apenas duas perguntas: (i) o sexo do entrevistado
(M/F) e (ii) sua opinião sobre o produto (gostou/não gostou). Escreva um programa em C que:

a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados, um deles contendo a resposta para
a primeira pergunta e o outro contendo a resposta para a segunda pergunta.

b) determine a porcentagem de pessoas do sexo feminino que responderam que gostaram do produto.

c) determine a porcentagem de pessoas do sexo masculino que responderam que não gostaram do produto.
*/

#include <stdio.h>

int main() {
    int N;

    printf("Digite o numero de pessoas entrevistadas: ");
    scanf("%d", &N);

    char sexo[N];
    char opiniao[N];

    for (int i = 0; i < N; i++) {
        printf("Resposta da pessoa %d (Sexo [M/F]): ", i + 1);
        scanf(" %c", &sexo[i]); 
        printf("Resposta da pessoa %d (Opiniao [G/N]): ", i + 1);
        scanf(" %c", &opiniao[i]); 
    }

    int contFemininoGostou = 0;
    for (int i = 0; i < N; i++) {
        if (sexo[i] == 'F' && opiniao[i] == 'G') {
            contFemininoGostou++;
        }
    }
    float porcentagemFemininoGostou = (float)contFemininoGostou / N * 100;

    int contMasculinoNaoGostou = 0;
    for (int i = 0; i < N; i++) {
        if (sexo[i] == 'M' && opiniao[i] == 'N') {
            contMasculinoNaoGostou++;
        }
    }
    float porcentagemMasculinoNaoGostou = (float)contMasculinoNaoGostou / N * 100;

    printf("\nPorcentagem de pessoas do sexo feminino que gostaram do produto: %.2f%%\n", porcentagemFemininoGostou);
    printf("Porcentagem de pessoas do sexo masculino que nao gostaram do produto: %.2f%%\n", porcentagemMasculinoNaoGostou);

    return 0;
}

