/*
Questão 3) Defina estruturas para representar retângulos (dadas a base e a altura) e círculos (dado o raio), e
implemente as funções a seguir:

a) Dado um círculo, crie e retorne o maior retângulo circunscrito de altura h. Considere que h é menor do
que o diâmetro do círculo.

Protótipo: Ret* ret_circunscrito(Circ* c, float h);

b) Dado um retângulo, crie e retorne o maior círculo interno ao retângulo.
Protótipo: Circ* circ_interno(Ret* r)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float base;
    float altura;
} Retangulo;

typedef struct {
    float raio;
} Circulo;

typedef struct {
    float base;
    float altura;
} RetanguloCircunscrito;

typedef struct {
    float raio;
} CirculoInterno;

RetanguloCircunscrito* ret_circunscrito(Circulo* c, float h) {
    RetanguloCircunscrito* ret = (RetanguloCircunscrito*)malloc(sizeof(RetanguloCircunscrito));

    if (ret != NULL) {
        ret->base = 2 * c->raio;
        ret->altura = h;
    }

    return ret;
}

CirculoInterno* circ_interno(Retangulo* r) {
    CirculoInterno* circ = (CirculoInterno*)malloc(sizeof(CirculoInterno));

    if (circ != NULL) {
        float menor_dimensao = r->base < r->altura ? r->base : r->altura;
        circ->raio = menor_dimensao / 2;
    }

    return circ;
}

int main() {
    Circulo c = {5.0};
    RetanguloCircunscrito* ret_c = ret_circunscrito(&c, 3.0);

    printf("Retângulo circunscrito:\n");
    printf("Base: %.2f\n", ret_c->base);
    printf("Altura: %.2f\n", ret_c->altura);

    free(ret_c);

    printf("\n");

    Retangulo r = {10.0, 6.0};
    CirculoInterno* circ_i = circ_interno(&r);

    printf("Círculo interno:\n");
    printf("Raio: %.2f\n", circ_i->raio);

    free(circ_i);

    return 0;
}


