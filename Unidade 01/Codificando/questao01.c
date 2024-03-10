#include <stdio.h>

void mostrar(int v[], int n);
void inverter(int v[], int n);
void trocar(int v[], int i, int f);

int main(){
    int v[5] = {1,2,3,4,5};
    mostrar(v, 5);
    inverter(v, 5);
    mostrar(v, 5);
    return 0;
}

void mostrar(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void inverter(int v[], int n){
    int i = 0;
    int f = n-1;
    while (i < f){
        trocar(v, i, f);
        i++;
        f--;
    }
}

void trocar(int v[], int i, int f){
    int aux = v[i];
    v[i] = v[f];
    v[f] = aux; 
}
