/*Questão 3) Qual será a saída exibida pelo programa a seguir:
#include <stdio.h>
int main(void) {
 int a, b, c, d;
 int *p1;
 int *p2 = &a;
 int *p3 = &c;
 p1 = p2;
 *p2 = 10;
 b = 20;
 int **pp;
 pp = &p1;
 *p3 = **pp;
 int *p4 = &d;
 *p4 = b + (*p1)++;
 printf("%d\t%d\t%d\t%d\n", a, b, c, d);
 return 0;
}

Observe que, se int *p é uma variável do tipo ponteiro para inteiro, então int **pp é uma 
variável do tipo ponteiro para ponteiro de inteiro, isto é, uma varável que poderá armazenar o 
endereço de um ponteiro do tipo int.

Saída: 
a: 11, pois foi definido como 10 através de '*p2 = 10' e incrementado mais 1 em '(*p1)++'.
b: 20, pois foi definido como 20 diretamente.
c: 10, pois recebeu o valor de 'a' através de '*p3 = **pp;'.
d: 30, pois é o resultado da expressão 'b + (*p1)++;'. */