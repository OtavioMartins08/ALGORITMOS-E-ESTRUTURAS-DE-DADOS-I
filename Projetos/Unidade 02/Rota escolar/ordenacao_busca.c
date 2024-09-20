#include "ordenacao_busca.h"

void merge(Usuario usuarios[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Usuario L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = usuarios[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = usuarios[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i].nome, R[j].nome) <= 0)
        {
            usuarios[k] = L[i];
            i++;
        }
        else
        {
            usuarios[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        usuarios[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        usuarios[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Usuario usuarios[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(usuarios, inicio, meio);
        mergeSort(usuarios, meio + 1, fim);
        merge(usuarios, inicio, meio, fim);
    }
}

void ordenarUsuariosPorNome(Usuario usuarios[], int qtdUsuarios)
{
    mergeSort(usuarios, 0, qtdUsuarios - 1);
}

int buscarUsuarioPorNome(Usuario usuarios[], int qtdUsuarios, const char *nome)
{
    int inicio = 0, fim = qtdUsuarios - 1;
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        int comparacao = strcmp(usuarios[meio].nome, nome);

        if (comparacao == 0)
        {
            return meio;
        }
        else if (comparacao < 0)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}
