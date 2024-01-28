/*Considere o trecho de código abaixo:
int main(void) {
int x, *p;
x = 100;
p = x;
printf(“Valor de p = %p\tValor de *p = %d”, p, *p);
}

Se tentarmos compilar o programa (não o compile ainda), você acha que o compilador nos
fornece alguma mensagem? Se sim, responda:
a) Esta mensagem é de erro ou advertência?
R: Sim, o compiladora retornará uma mensagem de erro.
b) Por que o compilador emite tal mensagem?
R: Porque no ponteiro 'p' está sendo atribuído o valor da variável 'x' invés do endereço da mesma.
c) Compile e execute o programa. A execução foi bem sucedida?
R: Não foi bem sucessida, o copilador emetiu uma mensagem de erro.
d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida pelo compilador.
R: int main(void) {
    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p = %p\tValor de *p = %d", (void*)p, *p);
}

e) Compile e execute novamente o programa. A execução foi bem sucedida?
Sim, a compilação e a execução foi bem sucedida. */